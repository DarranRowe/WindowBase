//#include "pch.h"
#include <map>

#include "windowbase/window_base.hpp"
#include "window_base_private.hpp"
#include "application_impl.hpp"

#include <propsys.h>
#include <propkey.h>
#include <propvarutil.h>
#include <shellapi.h>
#include <wrl.h>
#include <wil/resource.h>
#include <objidl.h>
#include <ShObjIdl.h>
#include <appmodel.h>

namespace window_base::windowing
{
	using details::close_callback_container;
	using details::prop_name_from_type_a;
	using details::prop_name_from_type_w;
	using details::get_register_callback_container_a;
	using details::get_register_callback_container_w;

	using utility::conversion::pointer_convert;
	using utility::conversion::value_convert;

	namespace details
	{
		close_callback_container *get_register_callback_container_a(HWND wnd) noexcept
		{
			close_callback_container *ccc{ pointer_convert<close_callback_container>(get_property_a(wnd, prop_type::register_callback)) };
			_ASSERTE(ccc != nullptr);
			return ccc;
		}
		close_callback_container *get_register_callback_container_w(HWND wnd) noexcept
		{
			close_callback_container *ccc{ pointer_convert<close_callback_container>(get_property_w(wnd, prop_type::register_callback)) };
			_ASSERTE(ccc != nullptr);
			return ccc;
		}

		template <size_t N>
		bool export_exists(HMODULE mod, const char(&export_name)[N])
		{
			static bool use_cache{ false };
			static bool feature_checked{ false };

			if (!feature_checked)
			{
				_ASSERTE(mod != nullptr);
				FARPROC fp{ GetProcAddress(mod, export_name) };
				if (fp != nullptr)
				{
					use_cache = true;
				}
				feature_checked = true;
			}
			return use_cache;
		}

		bool can_use_win11_features() noexcept
		{
			HMODULE mod{ GetModuleHandleW(L"kernelbase.dll") };
			auto &export_name{ "GetMachineTypeAttributes" };

			return export_exists(mod, export_name);
		}
		bool can_use_win11_22h2_features() noexcept
		{
			HMODULE mod{ GetModuleHandleW(L"kernelbase.dll") };
			auto &export_name{ "GetPackageGraphRevisionId" };

			return export_exists(mod, export_name);
		}
		bool can_use_win11_24h2_features() noexcept
		{
			HMODULE mod{ GetModuleHandleW(L"kernelbase.dll") };
			auto &export_name{ "TryCreatePackageDependency2" };

			return export_exists(mod, export_name);
		}

		bool set_property_a(HWND wnd, prop_type prop, void *data) noexcept
		{
			_ASSERTE(wnd != nullptr);
			_ASSERTE(data != nullptr);
			bool result{ SetPropA(wnd, prop_name_from_type_a(prop).data(), data) == FALSE ? false : true };

			return result;
		}
		void *get_property_a(HWND wnd, prop_type prop) noexcept
		{
			_ASSERTE(wnd != nullptr);
			void *data{ GetPropA(wnd, prop_name_from_type_a(prop).data()) };

			return data;
		}
		void *remove_property_a(HWND wnd, prop_type prop) noexcept
		{
			_ASSERTE(wnd != nullptr);
			void *data{ RemovePropA(wnd, prop_name_from_type_a(prop).data()) };

			return data;
		}

		bool set_property_w(HWND wnd, prop_type prop, void *data) noexcept
		{
			_ASSERTE(wnd != nullptr);
			_ASSERTE(data != nullptr);
			bool result{ SetPropW(wnd, prop_name_from_type_w(prop).data(), data) == FALSE ? false : true };

			return result;
		}
		void *get_property_w(HWND wnd, prop_type prop) noexcept
		{
			_ASSERTE(wnd != nullptr);
			void *data{ GetPropW(wnd, prop_name_from_type_w(prop).data()) };

			return data;
		}
		void *remove_property_w(HWND wnd, prop_type prop) noexcept
		{
			_ASSERTE(wnd != nullptr);
			void *data{ RemovePropW(wnd, prop_name_from_type_w(prop).data()) };

			return data;
		}
	}

	namespace window_implementation
	{
		static bool s_has_arranged{ false };
		static bool s_has_arranged_init{ false };

		static wil::unique_hmodule s_user32_handle{};
		static std::function<BOOL(HWND)> s_IsWindowArranged_ptr{};

		static void init_arranged() noexcept
		{
			using utility::conversion::function_pointer_convert;

			s_user32_handle.reset(LoadLibraryExW(L"User32.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32));

			auto is_window_arranged_ptr{ GetProcAddress(s_user32_handle.get(), "IsWindowArranged") };
			if (is_window_arranged_ptr == nullptr)
			{
				s_has_arranged_init = true;
			}
			else
			{
				s_has_arranged_init = true;
				s_IsWindowArranged_ptr = function_pointer_convert<BOOL(WINAPI)(HWND)>(is_window_arranged_ptr);
				s_has_arranged = true;
			}
		}

		static BOOL IsWindowArrangedWrapper(HWND window) noexcept
		{
			_ASSERTE(window != nullptr);
			FAIL_FAST_IF_NULL(window);
			if (!s_has_arranged_init)
			{
				init_arranged();
			}

			if (!s_has_arranged)
			{
				return FALSE;
			}

			return s_IsWindowArranged_ptr(window);
		}
		static bool show_window_helper(HWND window, int show_cmd) noexcept
		{
			_ASSERTE(window != nullptr);
			FAIL_FAST_IF_NULL(window);
			return ShowWindow(window, show_cmd) == FALSE ? false : true;
		}

		static HRESULT prop_var_set_aumid(HWND wnd, std::wstring &aumid) noexcept
		{
			FAIL_FAST_IF_NULL(wnd);
			Microsoft::WRL::ComPtr<IPropertyStore> win_prop_store;
			HRESULT hr{ SHGetPropertyStoreForWindow(wnd, IID_PPV_ARGS(win_prop_store.ReleaseAndGetAddressOf())) };

			if (SUCCEEDED(hr))
			{
				PROPVARIANT pv{};
				PropVariantInit(&pv);

				pv.vt = VT_LPWSTR;
				pv.pwszVal = aumid.data();

				hr = win_prop_store->SetValue(PKEY_AppUserModel_ID, pv);
			}

			return hr;
		}

		static HRESULT prop_var_set_aumid(HWND wnd, std::string &aumid) noexcept
		{
			FAIL_FAST_IF_NULL(wnd);
			Microsoft::WRL::ComPtr<IPropertyStore> win_prop_store;
			HRESULT hr{ SHGetPropertyStoreForWindow(wnd, IID_PPV_ARGS(win_prop_store.ReleaseAndGetAddressOf())) };

			if (SUCCEEDED(hr))
			{
				PROPVARIANT pv{};
				PropVariantInit(&pv);

				pv.vt = VT_LPSTR;
				pv.pszVal = aumid.data();

				hr = win_prop_store->SetValue(PKEY_AppUserModel_ID, pv);
			}

			return hr;
		}

		static std::pair<HRESULT, std::wstring> prop_var_get_aumid(HWND wnd) noexcept
		{
			FAIL_FAST_IF_NULL(wnd);
			std::wstring aumid{};
			Microsoft::WRL::ComPtr<IPropertyStore> win_prop_store;
			HRESULT hr{ SHGetPropertyStoreForWindow(wnd, IID_PPV_ARGS(win_prop_store.ReleaseAndGetAddressOf())) };

			if (SUCCEEDED(hr))
			{
				PROPVARIANT pv{};
				PropVariantInit(&pv);

				hr = win_prop_store->GetValue(PKEY_AppUserModel_ID, &pv);

				if (SUCCEEDED(hr))
				{
					if (pv.vt == VT_LPWSTR)
					{
						aumid = pv.pwszVal;
					}

					if (pv.vt == VT_BSTR)
					{
						aumid = pv.bstrVal;
						PropVariantClear(&pv);
					}
				}
			}

			return std::make_pair(hr, aumid);
		}

		static HRESULT set_window_aumid(HWND wnd, std::wstring &aumid) noexcept
		{
			return prop_var_set_aumid(wnd, aumid);
		}

		static HRESULT set_window_aumid(HWND wnd, std::string &aumid) noexcept
		{
			return prop_var_set_aumid(wnd, aumid);
		}

		static std::pair<HRESULT, std::string> get_window_aumid_a(HWND wnd) noexcept
		{
			using utility::conversion::value_convert;
			auto [hr, waumid] { prop_var_get_aumid(wnd)};

			if (FAILED(hr) || waumid.empty())
			{
				return std::make_pair(hr, std::string{});
			}

			auto buffer_size{ WideCharToMultiByte(CP_ACP, 0, waumid.c_str(), -1, nullptr, 0, nullptr, nullptr) };

			if (buffer_size == 0)
			{
				return std::make_pair(HRESULT_FROM_WIN32(GetLastError()), std::string{});
			}

			//The size returned from WideCharToMultiByte includes the null terminator, since the size
			//of the std::string doesn't include a null terminator then just using buffer_size as is
			//will result in aumid being one character longer than what it should be.
			//We remove the extra character when initialising the string, but then add it back on
			//when writing to it.
			std::string aumid(buffer_size - 1, '\0');

			_ASSERTE(aumid.size() < (INT32_MAX - 1));

			buffer_size = WideCharToMultiByte(CP_ACP, 0, waumid.c_str(), -1, aumid.data(), value_convert<int>(aumid.size() + 1), nullptr, nullptr);

			if (buffer_size == 0)
			{
				return std::make_pair(HRESULT_FROM_WIN32(GetLastError()), std::string{});
			}

			return { S_OK, aumid };
		}

		static std::pair<HRESULT, std::wstring> get_window_aumid_w(HWND wnd) noexcept
		{
			return prop_var_get_aumid(wnd);
		}

		static DWORD get_window_style_a(HWND wnd)
		{
			DWORD result{ value_convert<DWORD>(window_traits_a::WndGetWindowLongPtr(wnd, GWL_STYLE)) };
			return result;
		}

		static DWORD get_window_style_w(HWND wnd)
		{
			DWORD result{ value_convert<DWORD>(window_traits_w::WndGetWindowLongPtr(wnd, GWL_STYLE)) };
			return result;
		}

		static DWORD get_window_ex_style_a(HWND wnd)
		{
			DWORD result{ value_convert<DWORD>(window_traits_a::WndGetWindowLongPtr(wnd, GWL_EXSTYLE)) };
			return result;
		}

		static DWORD get_window_ex_style_w(HWND wnd)
		{
			DWORD result{ value_convert<DWORD>(window_traits_w::WndGetWindowLongPtr(wnd, GWL_EXSTYLE)) };
			return result;
		}
	}

	namespace common_impl
	{
		static RECT get_window_rect(HWND wnd) noexcept
		{
			RECT rc_wnd{};
			GetWindowRect(wnd, &rc_wnd);

			return rc_wnd;
		}

		static RECT get_client_rect(HWND wnd) noexcept
		{
			RECT rc_wnd{};
			GetClientRect(wnd, &rc_wnd);

			return rc_wnd;
		}

		static bool is_windowbase_window(HWND wnd) noexcept
		{
			using utility::conversion::pointer_convert;
			using details::prop_type;
			using details::get_property_a;
			using details::get_property_w;

			bool window_unicode{ IsWindowUnicode(wnd) != FALSE };

			//Explicitly indicate that this value is, and can only ever be const.
			//windowbase_identity is initialised taking the address of a constexpr value. Be sure to only ever attempt a read to this pointer.
			const int32_t *windowbase_identity{ window_unicode ? pointer_convert<const int32_t>(get_property_w(wnd, prop_type::identity)) : pointer_convert<const int32_t>(get_property_a(wnd, prop_type::identity)) };
			if (windowbase_identity != nullptr)
			{
				_ASSERTE(*windowbase_identity == 1);
				return true;
			}

			return false;
		}

		static dpi_awareness get_dpi_awareness(HWND wnd) noexcept
		{
			auto context{ GetWindowDpiAwarenessContext(wnd) };
			return application::details::awareness_ctx_to_awareness(context);
		}

		static dpi_hosting_behaviour get_dpi_hosting_behaviour(HWND wnd) noexcept
		{
			auto hosting_behaviour{ GetWindowDpiHostingBehavior(wnd) };
			return application::details::convert_behaviour_from_api(hosting_behaviour);
		}

		static bool is_window_rtl(HWND wnd, bool unicode_window) noexcept
		{
			DWORD ex_styles{ unicode_window ? window_implementation::get_window_ex_style_w(wnd) : window_implementation::get_window_ex_style_a(wnd) };
			return (ex_styles & WS_EX_LAYOUTRTL) == WS_EX_LAYOUTRTL;
		}

		static bool is_active(HWND wnd) noexcept
		{
			WINDOWINFO wi{ sizeof(WINDOWINFO) };

			GetWindowInfo(wnd, &wi);

			return (wi.dwWindowStatus == WS_ACTIVECAPTION);
		}

		static bool is_visible(HWND wnd) noexcept
		{
			return IsWindowVisible(wnd) == FALSE ? false : true;
		}

		static bool is_enabled(HWND wnd) noexcept
		{
			return IsWindowEnabled(wnd) == FALSE ? false : true;
		}

		static bool is_minimised(HWND wnd) noexcept
		{
			return IsIconic(wnd) == FALSE ? false : true;
		}

		static bool is_maximised(HWND wnd) noexcept
		{
			return IsZoomed(wnd) == FALSE ? false : true;
		}

		static bool is_arranged(HWND wnd) noexcept
		{
			return window_implementation::IsWindowArrangedWrapper(wnd) == FALSE ? false : true;
		}

		static bool show_window_cmd(HWND wnd, int show_cmd) noexcept
		{
			return window_implementation::show_window_helper(wnd, show_cmd);
		}

		static bool show_window_default(HWND wnd) noexcept
		{
			return window_implementation::show_window_helper(wnd, SW_SHOWDEFAULT);
		}

		static bool show_window(HWND wnd, bool activate) noexcept
		{
			//There are three things that we need to check for here.
			//Is the window visible.
			//Is the window maximised or minimised.
			//Dubiously, has the window been shown once.
			//The documentation is tricky here, since it states "displaying the
			//window for the first time" in the SW_NORMAL description.

			if (is_visible(wnd))
			{
				//If the window is already visible, we just pass this through to
				//restore.
				return restore_window(wnd);
			}

			return window_implementation::show_window_helper(wnd, activate == true ? SW_NORMAL : SW_SHOWNOACTIVATE);
		}

		static bool show_window_minimised(HWND wnd, bool activate) noexcept
		{
			if (is_visible(wnd))
			{
				//If the window is already visible, we pass this to minimise.
				return minimise_window(wnd);
			}
			return window_implementation::show_window_helper(wnd, activate == true ? SW_SHOWMINIMIZED : SW_SHOWMINNOACTIVE);
		}

		static bool show_window_maximised(HWND wnd) noexcept
		{
			if (is_visible(wnd))
			{
				return maximise_window(wnd);
			}
			return window_implementation::show_window_helper(wnd, SW_SHOWMAXIMIZED);
		}

		static bool minimise_window(HWND wnd) noexcept
		{
			if (!is_visible(wnd))
			{
				return show_window_minimised(wnd, false);
			}
			if (!is_minimised(wnd))
			{
				return window_implementation::show_window_helper(wnd, SW_MINIMIZE);
			}

			return true;
		}

		static bool maximise_window(HWND wnd) noexcept
		{
			if (!is_visible(wnd))
			{
				return show_window_maximised(wnd);
			}
			if (!is_maximised(wnd))
			{
				return window_implementation::show_window_helper(wnd, SW_MAXIMIZE);
			}

			return true;
		}

		static bool restore_window(HWND) noexcept
		{
			return false;
		}

		static bool hide_window(HWND wnd) noexcept
		{
			return window_implementation::show_window_helper(wnd, SW_HIDE);
		}

		static bool enable_window(HWND wnd) noexcept
		{
			return EnableWindow(wnd, TRUE) == FALSE ? false : true;
		}

		static bool disable_window(HWND wnd) noexcept
		{
			return EnableWindow(wnd, FALSE) == FALSE ? false : true;
		}

		static bool destroy_window(HWND wnd) noexcept
		{
			return DestroyWindow(wnd) == FALSE ? false : true;
		}

		static void update_window(HWND wnd) noexcept
		{
			UpdateWindow(wnd);
		}

		static void redraw_window(HWND wnd, std::optional<RECT> rect, HRGN rgn, redraw_window_flags flags) noexcept
		{
			using utility::conversion::value_convert;
			//Prioritise region over rect.
			HRGN rg_rgn{ rgn };
			RECT *rc_rect{ rgn != nullptr ? rect.has_value() == true ? &rect.value() : nullptr : nullptr };

			RedrawWindow(wnd, rc_rect, rg_rgn, value_convert<UINT>(flags));
		}

		static HWND get_parent(HWND wnd) noexcept
		{
			return GetParent(wnd);
		}

		static SIZE get_size(HWND wnd) noexcept
		{
			SIZE s{};
			RECT rc_wnd{ get_window_rect(wnd) };

			s.cx = rc_wnd.right - rc_wnd.left;
			s.cy = rc_wnd.bottom - rc_wnd.top;

			return s;
		}

		static SIZE get_client_size(HWND wnd) noexcept
		{
			SIZE s{};
			RECT rc_wnd{ get_client_rect(wnd) };

			s.cx = rc_wnd.right - rc_wnd.left;
			s.cy = rc_wnd.bottom - rc_wnd.top;

			return s;
		}

		static POINT get_position(HWND wnd) noexcept
		{
			POINT p{};
			RECT rc_wnd{ get_window_rect(wnd) };

			p.x = rc_wnd.left;
			p.y = rc_wnd.top;

			return p;
		}

		static void set_size(HWND wnd, const SIZE &new_size) noexcept
		{
			SetWindowPos(wnd, nullptr, 0, 0, new_size.cx, new_size.cy, SWP_NOMOVE | SWP_NOZORDER);
		}

		static void set_client_size(HWND wnd, uint32_t dpi, bool unicode_window, const SIZE &client_size) noexcept
		{
			RECT rc_original{ get_window_rect(wnd) };
			RECT rc_adjustrect{};
			RECT rc_targetrect{};
			//AdjustWindowRect only takes into account a single menu line.
			//If we have a menu, then we may need to pad the window size if the menu is more than a single line.
			auto menu_line_size{ GetSystemMetrics(SM_CYMENU) };

			//Keep the original window rectangle so we can revert.
			DWORD style{ unicode_window ? window_implementation::get_window_style_w(wnd) : window_implementation::get_window_style_a(wnd) };
			DWORD ex_style{ unicode_window ? window_implementation::get_window_ex_style_w(wnd) : window_implementation::get_window_ex_style_a(wnd) };
			HMENU main_menu{ GetMenu(wnd) };
			rc_adjustrect.right = client_size.cx;
			rc_adjustrect.bottom = client_size.cy;
			AdjustWindowRectExForDpi(&rc_adjustrect, style, main_menu != nullptr, ex_style, dpi);
			uint32_t menu_adjustment{ 0 };

			while (true)
			{
				rc_targetrect = rc_original;
				rc_targetrect.right = rc_targetrect.left + (rc_adjustrect.right - rc_adjustrect.left);
				rc_targetrect.bottom = rc_targetrect.top + (rc_adjustrect.bottom - rc_adjustrect.top) + menu_adjustment;

				SIZE new_size{ rc_targetrect.right - rc_targetrect.left, rc_targetrect.bottom - rc_targetrect.top };
				set_size(wnd, new_size);

				auto new_client_size{ get_client_size(wnd) };
				if ((new_client_size.cx >= client_size.cx) && (new_client_size.cy == client_size.cy))
				{
					break;
				}

				menu_adjustment += menu_line_size;
			}
			RedrawWindow(wnd, nullptr, nullptr, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
		}

		static void set_position(HWND wnd, const POINT &position) noexcept
		{
			SetWindowPos(wnd, nullptr, position.x, position.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		}

		static void set_size_position(HWND wnd, const POINT &position, const SIZE &size) noexcept
		{
			SetWindowPos(wnd, nullptr, position.x, position.y, size.cx, size.cy, SWP_NOZORDER);
		}

		static void set_z_order_top(HWND wnd) noexcept
		{
			SetWindowPos(wnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		static void set_z_order_bottom(HWND wnd) noexcept
		{
			SetWindowPos(wnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		static void set_z_order_after(HWND wnd, HWND after_wnd) noexcept
		{
			SetWindowPos(wnd, after_wnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
	}

	LRESULT window_traits_a::WndDefWindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		return DefWindowProcA(wnd, msg, wparam, lparam);
	}

	HHOOK window_traits_a::WndSetWindowsHookEx(int id, HOOKPROC proc, HINSTANCE modinst, DWORD tid)
	{
		return SetWindowsHookExA(id, proc, modinst, tid);
	}

	LONG_PTR window_traits_a::WndGetWindowLongPtr(HWND wnd, int index)
	{
#ifdef _WIN64
		return GetWindowLongPtrA(wnd, index);
#else
		return GetWindowLongA(wnd, index);
#endif
	}

	LONG_PTR window_traits_a::WndSetWindowLongPtr(HWND wnd, int index, LONG_PTR new_value)
	{
#ifdef _WIN64
		return SetWindowLongPtrA(wnd, index, new_value);
#else
		return SetWindowLongA(wnd, index, new_value);
#endif
	}

	LRESULT window_traits_w::WndDefWindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		return DefWindowProcW(wnd, msg, wparam, lparam);
	}

	HHOOK window_traits_w::WndSetWindowsHookEx(int id, HOOKPROC proc, HINSTANCE modinst, DWORD tid)
	{
		return SetWindowsHookExW(id, proc, modinst, tid);
	}

	LONG_PTR window_traits_w::WndGetWindowLongPtr(HWND wnd, int index)
	{
#ifdef _WIN64
		return GetWindowLongPtrW(wnd, index);
#else
		return GetWindowLongW(wnd, index);
#endif
	}

	LONG_PTR window_traits_w::WndSetWindowLongPtr(HWND wnd, int index, LONG_PTR new_value)
	{
#ifdef _WIN64
		return SetWindowLongPtrW(wnd, index, new_value);
#else
		return SetWindowLongW(wnd, index, new_value);
#endif
	}

	uint32_t close_callback_container::register_close_callback(std::function<close_callback_type> &f) noexcept
	{
		//yes, we mean v++, not ++v since we want to increment but keep the old value
		uint32_t cookie{ m_cookie++ };

		m_callbacks.insert(std::make_pair(cookie, f));
		return cookie;
	}

	void close_callback_container::unregister_close_callback(uint32_t cookie) noexcept
	{
		m_callbacks.erase(cookie);
	}

	void close_callback_container::notify_close(HWND handle) noexcept
	{
		for (auto &callback : m_callbacks)
		{
			callback.second(handle, callback.first);
		}
	}

	//A lot of the implementation either works based upon the window handle,
	//or a common subsection of the data. To reduce how much is implemented,
	//this functionality is placed in a common base class.
	bool window_base_common::is_windowbase_window(HWND wnd) noexcept
	{
		return common_impl::is_windowbase_window(wnd);
	}

	void window_base_common::set_data(details::window_data *data) noexcept
	{
		_ASSERTE(m_window_data == nullptr);
		m_window_data = data;
	}

	HWND window_base_common::get_handle() const noexcept
	{
		//make sure that the handle has been initialised
		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->window_handle != nullptr);
		return m_window_data->window_handle;
	}
	HINSTANCE window_base_common::get_instance() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->module_instance;
	}
	uint32_t window_base_common::get_thread_id() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->thread_id;
	}
	uint32_t window_base_common::get_dpi() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->window_dpi;
	}
	float window_base_common::get_scale() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->window_scale;
	}
	dpi_awareness window_base_common::get_dpi_awareness() const noexcept
	{
		return common_impl::get_dpi_awareness(get_handle());
	}
	dpi_hosting_behaviour window_base_common::get_dpi_hosting_behaviour() const noexcept
	{
		return common_impl::get_dpi_hosting_behaviour(get_handle());
	}
	bool window_base_common::is_window_rtl() const noexcept
	{
		return common_impl::is_window_rtl(get_handle(), is_window_unicode());
	}
	bool window_base_common::is_window_unicode() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->data_type != details::window_data_type::unspecified);
		return m_window_data->data_type == details::window_data_type::ansi ? false : true;
	}

	bool window_base_common::is_active() const noexcept
	{
		return common_impl::is_active(get_handle());
	}
	bool window_base_common::is_visible() const noexcept
	{
		return common_impl::is_visible(get_handle());
	}
	bool window_base_common::is_enabled() const noexcept
	{
		return common_impl::is_enabled(get_handle());
	}
	bool window_base_common::is_minimised() const noexcept
	{
		return common_impl::is_minimised(get_handle());
	}
	bool window_base_common::is_maximised() const noexcept
	{
		return common_impl::is_maximised(get_handle());
	}
	bool window_base_common::is_arranged() const noexcept
	{
		return common_impl::is_arranged(get_handle());
	}

	bool window_base_common::show_window_cmd(int show_cmd) noexcept
	{
		return common_impl::show_window_cmd(get_handle(), show_cmd);
	}
	bool window_base_common::show_window_default() noexcept
	{
		return common_impl::show_window_default(get_handle());
	}
	bool window_base_common::show_window(bool activate) noexcept
	{
		return common_impl::show_window(get_handle(), activate);
	}
	bool window_base_common::show_window_minimised(bool activate) noexcept
	{
		return common_impl::show_window_minimised(get_handle(), activate);
	}
	bool window_base_common::show_window_maximised() noexcept
	{
		return common_impl::show_window_maximised(get_handle());
	}
	bool window_base_common::minimise_window() noexcept
	{
		return common_impl::minimise_window(get_handle());
	}
	bool window_base_common::maximise_window() noexcept
	{
		return common_impl::maximise_window(get_handle());
	}
	bool window_base_common::restore_window() noexcept
	{
		return common_impl::restore_window(get_handle());
	}
	bool window_base_common::hide_window() noexcept
	{
		return common_impl::hide_window(get_handle());
	}
	bool window_base_common::enable_window() noexcept
	{
		return common_impl::enable_window(get_handle());
	}
	bool window_base_common::disable_window() noexcept
	{
		return common_impl::disable_window(get_handle());
	}
	bool window_base_common::destroy_window() noexcept
	{
		return common_impl::destroy_window(get_handle());
	}

	void window_base_common::update_window() noexcept
	{
		common_impl::update_window(get_handle());
	}
	void window_base_common::redraw_window(std::optional<RECT> rect, HRGN rgn, redraw_window_flags flags) noexcept
	{
		common_impl::redraw_window(get_handle(), rect, rgn, flags);
	}

	HWND window_base_common::get_parent() const noexcept
	{
		return common_impl::get_parent(get_handle());
	}
	SIZE window_base_common::get_size() const noexcept
	{
		return common_impl::get_size(get_handle());
	}
	SIZE window_base_common::get_client_size() const noexcept
	{
		return common_impl::get_client_size(get_handle());
	}
	POINT window_base_common::get_position() const noexcept
	{
		return common_impl::get_position(get_handle());
	}

	void window_base_common::set_size(const SIZE &new_size) noexcept
	{
		common_impl::set_size(get_handle(), new_size);
	}
	void window_base_common::set_client_size(const SIZE &client_size) noexcept
	{
		common_impl::set_client_size(get_handle(), get_dpi(), is_window_unicode(), client_size);
	}
	void window_base_common::set_position(const POINT &position) noexcept
	{
		common_impl::set_position(get_handle(), position);
	}
	void window_base_common::set_size_position(const POINT &position, const SIZE &size) noexcept
	{
		common_impl::set_size_position(get_handle(), position, size);
	}
	void window_base_common::set_z_order_top() noexcept
	{
		common_impl::set_z_order_top(get_handle());
	}
	void window_base_common::set_z_order_bottom() noexcept
	{
		common_impl::set_z_order_bottom(get_handle());
	}
	void window_base_common::set_z_order_after(HWND wnd) noexcept
	{
		common_impl::set_z_order_after(get_handle(), wnd);
	}

	void window_base_common::register_power_notification(power_notify_type type) noexcept
	{
		using utility::conversion::handle_cast;

		_ASSERTE(m_window_data != nullptr);
		HPOWERNOTIFY result{};

		if (m_window_data->power_notify_handles.find(type) != std::end(m_window_data->power_notify_handles))
		{
			return;
		}

		if (type == power_notify_type::suspend_resume)
		{
			result = RegisterSuspendResumeNotification(handle_cast<HANDLE>(get_handle()), DEVICE_NOTIFY_WINDOW_HANDLE);
		}
		else
		{
			GUID power_guid{};

			switch (type)
			{
			case power_notify_type::acdc_powersource:
				power_guid = GUID_ACDC_POWER_SOURCE;
				break;
			case power_notify_type::battery_percentage_remaining:
				power_guid = GUID_BATTERY_PERCENTAGE_REMAINING;
				break;
			case power_notify_type::idle_background_task:
				power_guid = GUID_IDLE_BACKGROUND_TASK;
				break;
			case power_notify_type::monitor_power_on:
				power_guid = GUID_MONITOR_POWER_ON;
				break;
			case power_notify_type::power_saving_status:
				power_guid = GUID_POWER_SAVING_STATUS;
				break;
			case power_notify_type::powerscheme_personality:
				power_guid = GUID_POWERSCHEME_PERSONALITY;
				break;
			case power_notify_type::lidswitch_state_change:
				power_guid = GUID_LIDSWITCH_STATE_CHANGE;
				break;
			case power_notify_type::system_awaymode:
				power_guid = GUID_SYSTEM_AWAYMODE;
				break;
			case power_notify_type::console_display_state:
				power_guid = GUID_CONSOLE_DISPLAY_STATE;
				break;
			case power_notify_type::global_user_presence:
				power_guid = GUID_GLOBAL_USER_PRESENCE;
				break;
			case power_notify_type::session_display_status:
				power_guid = GUID_SESSION_DISPLAY_STATUS;
				break;
			case power_notify_type::session_user_presence:
				power_guid = GUID_SESSION_USER_PRESENCE;
				break;
			}

			result = RegisterPowerSettingNotification(handle_cast<HANDLE>(get_handle()), &power_guid, DEVICE_NOTIFY_WINDOW_HANDLE);
		}

		if (result != nullptr)
		{
			m_window_data->power_notify_handles.emplace(std::make_pair(type, result));
		}
	}
	void window_base_common::unregister_power_notification(power_notify_type type) noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		auto it{ m_window_data->power_notify_handles.find(type) };
		if (it != std::end(m_window_data->power_notify_handles))
		{
			auto cache{ (*it).second };
			m_window_data->power_notify_handles.erase(it);

			if (type == power_notify_type::suspend_resume)
			{
				UnregisterSuspendResumeNotification(cache);
			}
			else
			{
				UnregisterPowerSettingNotification(cache);
			}
		}
	}

	register_callback &window_base_common::get_register_interface() const noexcept
	{
		close_callback_container *rcc{ is_window_unicode() == false ? get_register_callback_container_a(get_handle()) : get_register_callback_container_w(get_handle()) };
		_ASSERTE(rcc != nullptr);
		return *rcc;
	}

	void window_base_common::notify_window_close() noexcept
	{
		close_callback_container *rcc{ is_window_unicode() == false ? get_register_callback_container_a(get_handle()) : get_register_callback_container_w(get_handle()) };
		if (rcc != nullptr)
		{
			rcc->notify_close(get_handle());
		}
	}

	void window_base_common::set_dpi(uint32_t dpi) noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		m_window_data->window_dpi = dpi;
		m_window_data->window_scale = dpi / 96.f;
	}
	bool window_base_common::has_associated_window() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return (m_window_data->window_handle != nullptr);
	}

	bool window_base_common::is_window_destroying() const noexcept
	{
		_ASSERTE(m_window_data->data_type != details::window_data_type::unspecified);

		bool unicode = m_window_data->data_type == details::window_data_type::ansi ? false : true;
		//The properties indicate that a null return from GetProp indicates that the property is not found.
		//This is why we always set a value. So we detect if the property has been set by get_prop returning
		//a valid value rather than null.

		auto result = !unicode ? details::get_property_a(get_handle(), details::prop_type::destroying_win) : details::get_property_w(get_handle(), details::prop_type::destroying_win);

		if (result != nullptr)
		{
			return true;
		}

		result = !unicode ? details::get_property_a(get_handle(), details::prop_type::destroying_class) : details::get_property_w(get_handle(), details::prop_type::destroying_class);

		return result != nullptr;
	}

	bool window_base_common::set_destroying_window() const noexcept
	{
		_ASSERTE(m_window_data->data_type != details::window_data_type::unspecified);

		bool unicode = m_window_data->data_type == details::window_data_type::ansi ? false : true;

		_ASSERTE(is_window_destroying() == false);

		//The data being set doesn't matter.
		//All that matters is that it is a non null value.
		auto result = !unicode ? details::set_property_a(get_handle(), details::prop_type::destroying_win, const_cast<int32_t *>(&identity_version)) : details::set_property_a(get_handle(), details::prop_type::destroying_win, const_cast<int32_t *>(&identity_version));

		return result;
	}

	bool window_base_common::set_destroying_class() const noexcept
	{
		_ASSERTE(m_window_data->data_type != details::window_data_type::unspecified);

		bool unicode = m_window_data->data_type == details::window_data_type::ansi ? false : true;

		_ASSERTE(is_window_destroying() == false);

		//The data being set doesn't matter.
		//All that matters is that it is a non null value.
		auto result = !unicode ? details::set_property_a(get_handle(), details::prop_type::destroying_class, const_cast<int32_t *>(&identity_version)) : details::set_property_a(get_handle(), details::prop_type::destroying_class, const_cast<int32_t *>(&identity_version));

		return result;
	}

	void *window_base_common::raw_inst_from_handle(HWND handle)
	{
		using details::prop_type;
		using details::get_property_a;
		using details::get_property_w;

		auto window_unicode{ IsWindowUnicode(handle) != FALSE };
		auto value{ !window_unicode ? get_property_a(handle, prop_type::instance) : get_property_w(handle, prop_type::instance) };
		return value;
	}
	
	void window_base_a::set_window_aumid_from_process_aumid() noexcept
	{
		/*
		if (application::application::process_has_explicit_app_user_model_id())
		{
			auto eaumid{ application::application::get_explicit_app_user_model_id() };
			window_implementation::set_window_aumid(get_handle(), eaumid);
		}
		*/
	}
	void window_base_a::set_window_aumid(const std::string_view &aumid) noexcept
	{
		std::string aumid_cache{ aumid };
		window_implementation::set_window_aumid(get_handle(), aumid_cache);
	}
	std::string window_base_a::get_window_aumid() const noexcept
	{
		return window_implementation::get_window_aumid_a(get_handle()).second;
	}
	bool window_base_a::window_has_aumid() const noexcept
	{
		auto [hr, aumid] { window_implementation::get_window_aumid_w(get_handle()) };

		//Obtaining the aumid from the property store returns S_OK even if
		//the window has no aumid. We base the result of this function on
		//whether the string is empty or not.

		return !aumid.empty() ? true : false;
	}

	window_base_a::window_base_a(HINSTANCE inst) noexcept : m_window_data(details::make_window_data_a(inst))
	{
		set_data(m_window_data.get());
	}

	window_base_a::~window_base_a() noexcept
	{
		//If the window hasn't been marked as destroying, this means that
		//this is happening as a direct call to delete on the pointer.
		//This means that we mark the window as being deleted, and then
		//destroy the window.
		if (!is_window_destroying())
		{
			details::set_property_a(get_handle(), details::prop_type::destroying_class, const_cast<int32_t *>(&identity_version));
			destroy_window();
		}
	}

	void window_base_a::set_window_info(HWND handle, uint32_t thread_id, void *instance) noexcept
	{
		using utility::conversion::pointer_convert;
		using details::prop_type;
		using details::set_property_a;

		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->window_initial_construction_complete == false);

		m_window_data->window_handle = handle;
		m_window_data->thread_id = thread_id;

		//IMPORTANT:
		//This is removing the constness purely because this must cast to void*.
		//NEVER ATTEMPT TO WRITE TO prop_type::identity.
		set_property_a(handle, prop_type::identity, const_cast<int32_t *>(&windowing::identity_version));
		set_property_a(handle, prop_type::instance, instance);

		std::unique_ptr<close_callback_container> register_container{ std::make_unique<close_callback_container>() };

		//This uses pointer_convert (static_cast) to convert the pointer to void *.
		//This doesn't need to be done, since C++ will convert to void * without issue, but this helps identify that we are converting a pointer.
		set_property_a(handle, prop_type::register_callback, pointer_convert<void>(register_container.get()));
		register_container.release();

		m_window_data->window_initial_construction_complete = true;
	}
	void window_base_a::cleanup_window_info() noexcept
	{
		using utility::conversion::pointer_convert;

		using details::prop_type;
		using details::get_property_a;
		using details::remove_property_a;

		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->window_initial_construction_complete == true);
		auto handle = m_window_data->window_handle;

		std::unique_ptr<close_callback_container> register_container{ pointer_convert<close_callback_container>(get_property_a(handle, prop_type::register_callback)) };
		remove_property_a(handle, prop_type::register_callback);
		remove_property_a(handle, prop_type::instance);
		remove_property_a(handle, prop_type::identity);
	}

	HWND window_base_a::create_window(uint32_t ex_style, uint32_t style, const std::string_view &class_name, const std::string_view &title, const POINT &top_left, const SIZE &size, HWND parent, HMENU menu, window_base_a *data) noexcept
	{
		using utility::conversion::pointer_convert;

		_ASSERTE(data->has_associated_window() == false);
		auto result{ CreateWindowExA(ex_style, class_name.data(), title.data(), style, top_left.x, top_left.y, size.cx, size.cy, parent, menu, data->get_instance(), pointer_convert<void>(data)) };
		return result;
	}

	void window_base_w::set_window_aumid_from_process_aumid() noexcept
	{
		/*
		if (application::application::process_has_explicit_app_user_model_id())
		{
			auto eaumid{ application::application::get_explicit_app_user_model_id() };
			window_implementation::set_window_aumid(get_handle(), eaumid);
		}
		*/
	}
	void window_base_w::set_window_aumid(const std::wstring_view &aumid) noexcept
	{
		std::wstring aumid_cache{ aumid };
		window_implementation::set_window_aumid(get_handle(), aumid_cache);
	}
	std::wstring window_base_w::get_window_aumid() const noexcept
	{
		return window_implementation::get_window_aumid_w(get_handle()).second;
	}
	bool window_base_w::window_has_aumid() const noexcept
	{
		auto [hr, aumid] { window_implementation::get_window_aumid_w(get_handle()) };

		//Obtaining the aumid from the property store returns S_OK even if
		//the window has no aumid. We base the result of this function on
		//whether the string is empty or not.

		return !aumid.empty() ? true : false;
	}

	window_base_w::window_base_w(HINSTANCE inst) noexcept : m_window_data(details::make_window_data_w(inst))
	{
		set_data(m_window_data.get());
	}

	window_base_w::~window_base_w() noexcept
	{
		//If the window hasn't been marked as destroying, this means that
		//this is happening as a direct call to delete on the pointer.
		//This means that we mark the window as being deleted, and then
		//destroy the window.
		if (!is_window_destroying())
		{
			details::set_property_w(get_handle(), details::prop_type::destroying_class, const_cast<int32_t *>(&identity_version));
			destroy_window();
		}
	}

	void window_base_w::set_window_info(HWND handle, uint32_t thread_id, void *instance) noexcept
	{
		using utility::conversion::pointer_convert;
		using details::prop_type;
		using details::set_property_w;

		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->window_initial_construction_complete == false);

		m_window_data->window_handle = handle;
		m_window_data->thread_id = thread_id;

		//IMPORTANT:
		//This is removing the constness purely because this must cast to void*.
		//NEVER ATTEMPT TO WRITE TO prop_type::identity.
		set_property_w(handle, prop_type::identity, const_cast<int32_t *>(&windowing::identity_version));
		set_property_w(handle, prop_type::instance, instance);

		std::unique_ptr<close_callback_container> register_container{ std::make_unique<close_callback_container>() };

		//This uses pointer_convert (static_cast) to convert the pointer to void *.
		//This doesn't need to be done, since C++ will convert to void * without issue, but this helps identify that we are converting a pointer.
		set_property_w(handle, prop_type::register_callback, pointer_convert<void>(register_container.get()));
		register_container.release();

		m_window_data->window_initial_construction_complete = true;
	}
	void window_base_w::cleanup_window_info() noexcept
	{
		using utility::conversion::pointer_convert;

		using details::prop_type;
		using details::get_property_w;
		using details::remove_property_w;

		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->window_initial_construction_complete == true);
		auto handle = m_window_data->window_handle;

		std::unique_ptr<close_callback_container> register_container{ pointer_convert<close_callback_container>(get_property_w(handle, prop_type::register_callback)) };
		remove_property_w(handle, prop_type::register_callback);
		remove_property_w(handle, prop_type::instance);
		remove_property_w(handle, prop_type::identity);
	}

	HWND window_base_w::create_window(uint32_t ex_style, uint32_t style, const std::wstring_view &class_name, const std::wstring_view &title, const POINT &top_left, const SIZE &size, HWND parent, HMENU menu, window_base_w *data) noexcept
	{
		using utility::conversion::pointer_convert;

		_ASSERTE(data->has_associated_window() == false);
		auto result{ CreateWindowExW(ex_style, class_name.data(), title.data(), style, top_left.x, top_left.y, size.cx, size.cy, parent, menu, data->get_instance(), pointer_convert<void>(data)) };
		return result;
	}
}
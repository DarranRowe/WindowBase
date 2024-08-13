//#include "pch.h"
#include <string_view>

#include "window_base.hpp"
#include "window_base_private.hpp"

#include "application.hpp"

#include <propsys.h>
#include <propkey.h>
#include <propvarutil.h>
#include <wrl.h>
#include <wil/resource.h>
#include <objidl.h>
#include <ShObjIdl.h>

namespace windowing
{
	using details::message_callback_container;
	using details::close_callback_container;
	using details::prop_name_from_type_a;
	using details::prop_name_from_type_w;
	using details::get_register_callback_container_a;
	using details::get_register_callback_container_w;
	
	namespace details
	{
		close_callback_container *get_register_callback_container_a(HWND wnd) noexcept
		{
			close_callback_container *ccc = static_cast<close_callback_container *>(get_property_a(wnd, prop_type::register_callback));
			_ASSERTE(ccc != nullptr);
			return ccc;
		}
		close_callback_container *get_register_callback_container_w(HWND wnd) noexcept
		{
			close_callback_container *ccc = static_cast<close_callback_container *>(get_property_w(wnd, prop_type::register_callback));
			_ASSERTE(ccc != nullptr);
			return ccc;
		}

		template <size_t N>
		bool export_exists(HMODULE mod, const char(&export_name)[N])
		{
			static bool use_cache = false;
			static bool feature_checked = false;

			if (!feature_checked)
			{
				_ASSERTE(mod != nullptr);
				FARPROC fp = GetProcAddress(mod, export_name);
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
			HMODULE mod = GetModuleHandleW(L"kernelbase.dll");
			auto &export_name = "GetMachineTypeAttributes";

			return export_exists(mod, export_name);
		}
		bool can_use_win11_22h2_features() noexcept
		{
			HMODULE mod = GetModuleHandleW(L"kernelbase.dll");
			auto &export_name = "GetPackageGraphRevisionId";

			return export_exists(mod, export_name);
		}

		bool set_property_a(HWND wnd, prop_type prop, void *data) noexcept
		{
			_ASSERTE(wnd != nullptr);
			bool result = false;
			_ASSERTE(data != nullptr);
			result = SetPropA(wnd, prop_name_from_type_a(prop).data(), data);

			return result;
		}
		void *get_property_a(HWND wnd, prop_type prop) noexcept
		{
			_ASSERTE(wnd != nullptr);
			void *data = nullptr;
			data = GetPropA(wnd, prop_name_from_type_a(prop).data());

			return data;
		}
		void *remove_property_a(HWND wnd, prop_type prop) noexcept
		{
			_ASSERTE(wnd != nullptr);
			void *data = nullptr;
			data = RemovePropA(wnd, prop_name_from_type_a(prop).data());

			return data;
		}

		bool set_property_w(HWND wnd, prop_type prop, void *data) noexcept
		{
			_ASSERTE(wnd != nullptr);
			bool result = false;
			_ASSERTE(data != nullptr);
			result = SetPropW(wnd, prop_name_from_type_w(prop).data(), data);

			return result;
		}
		void *get_property_w(HWND wnd, prop_type prop) noexcept
		{
			_ASSERTE(wnd != nullptr);
			void *data = nullptr;
			data = GetPropW(wnd, prop_name_from_type_w(prop).data());

			return data;
		}
		void *remove_property_w(HWND wnd, prop_type prop) noexcept
		{
			_ASSERTE(wnd != nullptr);
			void *data = nullptr;
			data = RemovePropW(wnd, prop_name_from_type_w(prop).data());

			return data;
		}
	}

	namespace window_implementation
	{
		static bool s_has_arranged = false;
		static bool s_has_arranged_init = false;

		static wil::unique_hmodule s_user32_handle{};
		static std::function<BOOL(HWND)> s_IsWindowArranged_ptr{};

		static void init_arranged() noexcept
		{
			s_user32_handle.reset(LoadLibraryExW(L"User32.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32));

			auto is_window_arranged_ptr = GetProcAddress(s_user32_handle.get(), "IsWindowArranged");
			if (is_window_arranged_ptr == nullptr)
			{
				s_has_arranged_init = true;
			}
			else
			{
				s_has_arranged_init = true;
				s_IsWindowArranged_ptr = reinterpret_cast<BOOL(WINAPI *)(HWND)>(is_window_arranged_ptr);
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
		static DWORD get_window_style(HWND window, bool unicode) noexcept
		{
			_ASSERTE(window != nullptr);
			FAIL_FAST_IF_NULL(window);
			return static_cast<DWORD>(TWndGetWindowLongPtr(window, GWL_STYLE, unicode));
		}
		static DWORD get_window_ex_style(HWND window, bool unicode) noexcept
		{
			_ASSERTE(window != nullptr);
			FAIL_FAST_IF_NULL(window);
			return static_cast<DWORD>(TWndGetWindowLongPtr(window, GWL_EXSTYLE, unicode));
		}

		static HRESULT prop_var_set_aumid(HWND wnd, std::wstring &aumid) noexcept
		{
			FAIL_FAST_IF_NULL(wnd);
			HRESULT hr = S_OK;
			Microsoft::WRL::ComPtr<IPropertyStore> win_prop_store;

			hr = SHGetPropertyStoreForWindow(wnd, IID_PPV_ARGS(win_prop_store.ReleaseAndGetAddressOf()));

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
			HRESULT hr = S_OK;
			Microsoft::WRL::ComPtr<IPropertyStore> win_prop_store;

			hr = SHGetPropertyStoreForWindow(wnd, IID_PPV_ARGS(win_prop_store.ReleaseAndGetAddressOf()));

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
			HRESULT hr = S_OK;
			std::wstring aumid{};
			Microsoft::WRL::ComPtr<IPropertyStore> win_prop_store;

			hr = SHGetPropertyStoreForWindow(wnd, IID_PPV_ARGS(win_prop_store.ReleaseAndGetAddressOf()));

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
			auto [hr, waumid] = prop_var_get_aumid(wnd);

			if (FAILED(hr) || waumid.empty())
			{
				return std::make_pair(hr, std::string{});
			}

			auto buffer_size = WideCharToMultiByte(CP_ACP, 0, waumid.c_str(), -1, nullptr, 0, nullptr, nullptr);

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

			buffer_size = WideCharToMultiByte(CP_ACP, 0, waumid.c_str(), -1, aumid.data(), static_cast<int>(aumid.size() + 1), nullptr, nullptr);

			if (buffer_size == 0)
			{
				return std::make_pair(HRESULT_FROM_WIN32(GetLastError()), std::string{});
			}


			return {S_OK, aumid};
		}

		static std::pair<HRESULT, std::wstring> get_window_aumid_w(HWND wnd) noexcept
		{
			return prop_var_get_aumid(wnd);
		}
	}

	uint32_t close_callback_container::register_close_callback(std::function<close_callback_type> &f) noexcept
	{
		//yes, we mean v++, not ++v since we want to increment but keep the old value
		uint32_t cookie = m_cookie++;

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

	bool message_callback_container::add_callback(const std::shared_ptr<message_callback> &callback, uint32_t index) noexcept
	{
		if (!has_callback(index))
		{
			m_map.emplace(std::make_pair(index, callback));
			return true;
		}

		return false;
	}
	void message_callback_container::remove_callback(uint32_t index) noexcept
	{
		if (has_callback(index))
		{
			m_map.erase(index);
		}
	}
	void message_callback_container::clear_callbacks() noexcept
	{
		m_map.clear();
	}
	message_callback *message_callback_container::get_callback(uint32_t index) const noexcept
	{
		const auto &callback = m_map.find(index);
		if (callback != m_map.end())
		{
			return callback->second.get();
		}

		return nullptr;
	}
	bool message_callback_container::has_callback(uint32_t index) const noexcept
	{
		const auto &callback = m_map.find(index);

		return callback != m_map.end();
	}

	HWND window_base::get_handle() const noexcept
	{
		//make sure that the handle has been initialised
		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->m_handle != nullptr);
		return m_window_data->m_handle;
	}
	HINSTANCE window_base::get_instance() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->m_instance;
	}
	uint32_t window_base::get_thread_id() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->m_thread_id;
	}
	uint32_t window_base::get_dpi() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->m_dpi;
	}
	float window_base::get_scale() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->m_scale;
	}
	bool window_base::is_window_dpi_aware() const noexcept
	{
		auto context = GetWindowDpiAwarenessContext(get_handle());

		if ((context == DPI_AWARENESS_CONTEXT_UNAWARE) || (context == DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED))
		{
			return false;
		}
		return true;
	}
	bool window_base::is_window_rtl() const noexcept
	{
		LONG_PTR ex_styles{};
		ex_styles = window_implementation::get_window_ex_style(get_handle(), is_window_unicode());
		return (ex_styles & WS_EX_LAYOUTRTL) == WS_EX_LAYOUTRTL;
	}
	bool window_base::is_window_unicode() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return m_window_data->window_unicode;
	}

	bool window_base::is_active() const noexcept
	{
		WINDOWINFO wi{sizeof(WINDOWINFO)};

		GetWindowInfo(get_handle(), &wi);

		return (wi.dwWindowStatus == WS_ACTIVECAPTION);
	}
	bool window_base::is_visible() const noexcept
	{
		return IsWindowVisible(get_handle()) == FALSE ? false : true;
	}
	bool window_base::is_enabled() const noexcept
	{
		return IsWindowEnabled(get_handle()) == FALSE ? false : true;
	}
	bool window_base::is_minimised() const noexcept
	{
		return IsIconic(get_handle()) == FALSE ? false : true;
	}
	bool window_base::is_maximised() const noexcept
	{
		return IsZoomed(get_handle()) == FALSE ? false : true;
	}
	bool window_base::is_arranged() const noexcept
	{
		return window_implementation::IsWindowArrangedWrapper(get_handle()) == FALSE ? false : true;
	}

	bool window_base::show_window_cmd(int show_cmd) noexcept
	{
		return window_implementation::show_window_helper(get_handle(), show_cmd);
	}
	bool window_base::show_window_default() noexcept
	{
		return window_implementation::show_window_helper(get_handle(), SW_SHOWDEFAULT);
	}
	bool window_base::show_window(bool activate) noexcept
	{
		//There are three things that we need to check for here.
		//Is the window visible.
		//Is the window maximised or minimised.
		//Dubiously, has the window been shown once.
		//The documentation is tricky here, since it states "displaying the
		//window for the first time" in the SW_NORMAL description.

		if (is_visible())
		{
			//If the window is already visible, we just pass this through to
			//restore.
			return restore_window();
		}

		return window_implementation::show_window_helper(get_handle(), activate == true ? SW_NORMAL : SW_SHOWNOACTIVATE);
	}
	bool window_base::show_window_minimised(bool activate) noexcept
	{
		if (is_visible())
		{
			//If the window is already visible, we pass this to minimise.
			return minimise_window();
		}
		return window_implementation::show_window_helper(get_handle(), activate == true ? SW_SHOWMINIMIZED : SW_SHOWMINNOACTIVE);
	}
	bool window_base::show_window_maximised() noexcept
	{
		if (is_visible())
		{
			return maximise_window();
		}
		return window_implementation::show_window_helper(get_handle(), SW_SHOWMAXIMIZED);
	}
	bool window_base::minimise_window() noexcept
	{
		if (!is_visible())
		{
			return show_window_minimised(false);
		}
		if (!is_minimised())
		{
			return window_implementation::show_window_helper(get_handle(), SW_MINIMIZE);
		}

		return true;
	}
	bool window_base::maximise_window() noexcept
	{
		if (!is_visible())
		{
			return show_window_maximised();
		}
		if(!is_maximised())
		{
			return window_implementation::show_window_helper(get_handle(), SW_MAXIMIZE);
		}

		return true;
	}
	bool window_base::restore_window() noexcept
	{
		return false;
	}
	bool window_base::hide_window() noexcept
	{
		return window_implementation::show_window_helper(get_handle(), SW_HIDE);
	}
	bool window_base::enable_window() noexcept
	{
		return EnableWindow(get_handle(), TRUE) == FALSE ? false : true;
	}
	bool window_base::disable_window() noexcept
	{
		return EnableWindow(get_handle(), FALSE) == FALSE ? false : true;
	}

	void window_base::update_window() noexcept
	{
		UpdateWindow(get_handle());
	}
	void window_base::redraw_window(std::optional<RECT> rect, HRGN rgn, redraw_window_flags flags) noexcept
	{
		//Prioritise region over rect.
		HRGN rg_rgn = rgn;
		RECT *rc_rect = rgn != nullptr ? rect.has_value() == true ? &rect.value() : nullptr : nullptr;

		RedrawWindow(get_handle(), rc_rect, rg_rgn, static_cast<UINT>(flags));
	}

	HWND window_base::get_parent() const noexcept
	{
		return GetParent(get_handle());
	}
	SIZE window_base::get_size() const noexcept
	{
		SIZE s{};
		RECT rc_wnd{};

		GetWindowRect(get_handle(), &rc_wnd);

		s.cx = rc_wnd.right - rc_wnd.left;
		s.cy = rc_wnd.bottom - rc_wnd.top;

		return s;
	}
	SIZE window_base::get_client_size() const noexcept
	{
		SIZE s{};
		RECT rc_wnd{};

		GetClientRect(get_handle(), &rc_wnd);

		s.cx = rc_wnd.right - rc_wnd.left;
		s.cy = rc_wnd.bottom - rc_wnd.top;

		return s;
	}
	POINT window_base::get_position() const noexcept
	{
		POINT p{};
		RECT rc_wnd{};

		GetWindowRect(get_handle(), &rc_wnd);

		p.x = rc_wnd.left;
		p.y = rc_wnd.top;

		return p;
	}

	void window_base::set_size(const SIZE &new_size) noexcept
	{
		SetWindowPos(get_handle(), nullptr, 0, 0, new_size.cx, new_size.cy, SWP_NOMOVE | SWP_NOZORDER);
	}
	void window_base::set_client_size(const SIZE &client_size) noexcept
	{
		RECT rc_original{};
		RECT rc_adjustrect{};
		RECT rc_targetrect{};
		//AdjustWindowRect only takes into account a single menu line.
		//If we have a menu, then we may need to pad the window size if the menu is more than a single line.
		auto menu_line_size = GetSystemMetrics(SM_CYMENU);

		//Keep the original window rectangle so we can revert.
		GetWindowRect(get_handle(), &rc_original);
		DWORD style = window_implementation::get_window_style(get_handle(), is_window_unicode());
		DWORD ex_style = window_implementation::get_window_ex_style(get_handle(), is_window_unicode());
		HMENU main_menu = GetMenu(get_handle());
		rc_adjustrect.right = client_size.cx;
		rc_adjustrect.bottom = client_size.cy;
		AdjustWindowRectExForDpi(&rc_adjustrect, style, main_menu != nullptr, ex_style, get_dpi());
		uint32_t menu_adjustment = 0;

		while (true)
		{
			rc_targetrect = rc_original;
			rc_targetrect.right = rc_targetrect.left + (rc_adjustrect.right - rc_adjustrect.left);
			rc_targetrect.bottom = rc_targetrect.top + (rc_adjustrect.bottom - rc_adjustrect.top) + menu_adjustment;

			SIZE new_size = { rc_targetrect.right - rc_targetrect.left, rc_targetrect.bottom - rc_targetrect.top };
			set_size(new_size);

			auto new_client_size = get_client_size();
			if ((new_client_size.cx >= client_size.cx) && (new_client_size.cy == client_size.cy))
			{
				break;
			}

			menu_adjustment += menu_line_size;
		}
		RedrawWindow(get_handle(), nullptr, nullptr, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
	}
	void window_base::set_position(const POINT &position) noexcept
	{
		SetWindowPos(get_handle(), nullptr, position.x, position.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}
	void window_base::set_size_position(const POINT &position, const SIZE &size) noexcept
	{
		SetWindowPos(get_handle(), nullptr, position.x, position.y, size.cx, size.cy, SWP_NOZORDER);
	}
	void window_base::set_z_order_top() noexcept
	{
		SetWindowPos(get_handle(), HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
	void window_base::set_z_order_bottom() noexcept
	{
		SetWindowPos(get_handle(), HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
	void window_base::set_z_order_after(HWND wnd) noexcept
	{
		SetWindowPos(get_handle(), wnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}

	void window_base::set_window_aumid_from_process_aumid() noexcept
	{
		if (application::application::process_has_explicit_app_user_model_id())
		{
			auto eaumid = application::application::get_explicit_app_user_model_id();
			window_implementation::set_window_aumid(get_handle(), eaumid);
		}
	}
	void window_base::set_window_aumid(const std::string_view &aumid) noexcept
	{
		std::string aumid_cache = std::string(aumid);
		window_implementation::set_window_aumid(get_handle(), aumid_cache);
	}
	void window_base::set_window_aumid(const std::wstring_view &aumid) noexcept
	{
		std::wstring aumid_cache = std::wstring(aumid);
		window_implementation::set_window_aumid(get_handle(), aumid_cache);
	}
	aumid_type window_base::get_window_aumid() const noexcept
	{
		auto win_unicode = is_window_unicode();

		return win_unicode == true ? aumid_type{ window_implementation::get_window_aumid_w(get_handle()).second } : aumid_type{ window_implementation::get_window_aumid_a(get_handle()).second };
	}
	bool window_base::window_has_aumid() const noexcept
	{
		auto [hr, aumid] = window_implementation::get_window_aumid_w(get_handle());

		//Obtaining the aumid from the property store returns S_OK even if
		//the window has no aumid. We base the result of this function on
		//whether the string is empty or not.

		return !aumid.empty() ? true : false;
	}

	void window_base::register_power_notification(power_notify_type type) noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		HPOWERNOTIFY result{};

		if (m_window_data->m_power_notify_handles.find(type) != std::end(m_window_data->m_power_notify_handles))
		{
			return;
		}

		if (type == power_notify_type::suspend_resume)
		{
			result = RegisterSuspendResumeNotification(reinterpret_cast<HANDLE>(get_handle()), DEVICE_NOTIFY_WINDOW_HANDLE);
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

			result = RegisterPowerSettingNotification(reinterpret_cast<HANDLE>(get_handle()), &power_guid, DEVICE_NOTIFY_WINDOW_HANDLE);
		}

		if (result != nullptr)
		{
			m_window_data->m_power_notify_handles.emplace(std::make_pair(type, result));
		}
	}
	void window_base::unregister_power_notification(power_notify_type type) noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		auto it = m_window_data->m_power_notify_handles.find(type);
		if (it != std::end(m_window_data->m_power_notify_handles))
		{
			auto cache = (*it).second;
			m_window_data->m_power_notify_handles.erase(it);

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

	register_callback &window_base::get_register_interface() const noexcept
	{
		close_callback_container *rcc = is_window_unicode() == true ? get_register_callback_container_w(get_handle()) : get_register_callback_container_a(get_handle());
		_ASSERTE(rcc != nullptr);
		return *rcc;
	}
	message_callback &window_base::get_window_message_callback(HWND wnd, uint32_t index) noexcept
	{
		using details::prop_type;
		using details::set_property_a;
		using details::set_property_w;
		auto message_container = IsWindowUnicode(wnd) != FALSE ? static_cast<message_callback_container *>(get_property_w(wnd, prop_type::message_callback)) : static_cast<message_callback_container *>(get_property_a(wnd, prop_type::message_callback));
		_ASSERTE(message_container != nullptr);

		auto has_callback = message_container->has_callback(index);
		_ASSERTE(has_callback == true);
		FAIL_FAST_IF_WIN32_BOOL_FALSE(has_callback == false ? FALSE : TRUE);
		return *message_container->get_callback(index);
	}
	bool window_base::has_window_message_callback(HWND wnd, uint32_t index) noexcept
	{
		using details::prop_type;
		using details::get_property_a;
		using details::get_property_w;
		auto message_container = IsWindowUnicode(wnd) != FALSE ? static_cast<message_callback_container *>(get_property_w(wnd, prop_type::message_callback)) : static_cast<message_callback_container *>(get_property_a(wnd, prop_type::message_callback));
		return message_container == nullptr ? false : message_container->has_callback(index);
	}

	window_base::window_base(HINSTANCE inst) noexcept : m_window_data(details::make_window_data(inst))
	{
	}

	window_base::~window_base() noexcept
	{
	}

	void window_base::notify_window_close() noexcept
	{
		close_callback_container *rcc = is_window_unicode() == true ? get_register_callback_container_w(get_handle()) : get_register_callback_container_a(get_handle());
		if (rcc != nullptr)
		{
			rcc->notify_close(get_handle());
		}
	}
	void window_base::set_window_info(HWND handle, uint32_t thread_id, bool unicode, void *instance) noexcept
	{
		using details::prop_type;
		using details::set_property_a;
		using details::set_property_w;

		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->window_initial_construction_complete == false);

		m_window_data->m_handle = handle;
		m_window_data->m_thread_id = thread_id;
		m_window_data->window_unicode = unicode;

		unicode == true ? set_property_w(handle, prop_type::instance, instance) : set_property_a(handle, prop_type::instance, instance);

		std::unique_ptr<close_callback_container> register_container = std::make_unique<close_callback_container>();

		unicode == true ? set_property_w(handle, prop_type::register_callback, static_cast<void *>(register_container.get())) : set_property_a(handle, prop_type::register_callback, static_cast<void *>(register_container.get()));
		register_container.release();

		std::unique_ptr<message_callback_container> message_callback = std::make_unique<message_callback_container>();
		unicode == true ? set_property_w(handle, prop_type::message_callback, static_cast<void *>(message_callback.get())) : set_property_a(handle, prop_type::message_callback, static_cast<void *>(message_callback.get()));
		message_callback.release();

		m_window_data->window_initial_construction_complete = true;
	}
	void window_base::cleanup_window_info() noexcept
	{
		using details::prop_type;
		using details::get_property_a;
		using details::get_property_w;
		using details::remove_property_a;
		using details::remove_property_w;

		_ASSERTE(m_window_data != nullptr);
		_ASSERTE(m_window_data->window_initial_construction_complete == true);
		auto unicode = m_window_data->window_unicode;
		auto handle = m_window_data->m_handle;

		std::unique_ptr<close_callback_container> register_container;
		register_container.reset(static_cast<close_callback_container *>(unicode == true ? get_property_w(handle, prop_type::register_callback) : get_property_a(handle, prop_type::register_callback)));
		unicode == true ? remove_property_w(handle, prop_type::register_callback) : remove_property_a(handle, prop_type::register_callback);
		std::unique_ptr<message_callback_container> message_container;
		message_container.reset(static_cast<message_callback_container *>(unicode == true  ? get_property_w(handle, prop_type::message_callback) : get_property_a(handle, prop_type::message_callback)));
		unicode == true ? remove_property_w(handle, prop_type::message_callback) : remove_property_a(handle, prop_type::message_callback);
		unicode == true ? remove_property_w(handle, prop_type::instance) : remove_property_a(handle, prop_type::instance);
	}
	void window_base::set_dpi(uint32_t dpi) noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		m_window_data->m_dpi = dpi;
		m_window_data->m_scale = dpi / 96.f;
	}
	bool window_base::has_associated_window() const noexcept
	{
		_ASSERTE(m_window_data != nullptr);
		return (m_window_data->m_handle != nullptr);
	}

	bool window_base::add_message_callback(const std::shared_ptr<message_callback> &callback, uint32_t index) noexcept
	{
		using details::prop_type;
		using details::get_property_a;
		using details::get_property_w;

		auto unicode = is_window_unicode();
		auto handle = get_handle();
		auto message_container = static_cast<message_callback_container *>(unicode == true ? get_property_w(handle, prop_type::message_callback) : get_property_a(handle, prop_type::message_callback));
		_ASSERTE(message_container != nullptr);

		if (!message_container->has_callback(index))
		{
			message_container->add_callback(callback, index);
			return true;
		}

		return false;
	}
	void window_base::remove_message_callback(uint32_t index) noexcept
	{
		using details::prop_type;
		using details::get_property_a;
		using details::get_property_w;

		auto unicode = is_window_unicode();
		auto handle = get_handle();
		auto message_container = static_cast<message_callback_container *>(unicode == true ? get_property_w(handle, prop_type::message_callback) : get_property_a(handle, prop_type::message_callback));
		_ASSERTE(message_container != nullptr);

		message_container->remove_callback(index);
	}
	void window_base::clear_message_callbacks() noexcept
	{
		using details::prop_type;
		using details::get_property_a;
		using details::get_property_w;

		auto unicode = is_window_unicode();
		auto handle = get_handle();
		auto message_container = static_cast<message_callback_container *>(unicode == true ? get_property_w(handle, prop_type::message_callback) : get_property_a(handle, prop_type::message_callback));
		_ASSERTE(message_container != nullptr);

		message_container->clear_callbacks();
	}

	void *window_base::raw_inst_from_handle(HWND handle)
	{
		using details::prop_type;
		using details::get_property_a;
		using details::get_property_w;

		bool window_unicode = IsWindowUnicode(handle) != FALSE;

		auto value = window_unicode == true ? get_property_w(handle, prop_type::instance) : get_property_a(handle, prop_type::instance);
		return value;
	}

	bool window_base::is_class_registered(HINSTANCE inst, const std::string_view &class_name) noexcept
	{
		WNDCLASSEXA wcx{ sizeof(WNDCLASSEXA) };

		if (GetClassInfoExA(inst, class_name.data(), &wcx))
		{
			return true;
		}

		auto last_error = GetLastError();
		_ASSERTE(last_error == ERROR_CLASS_DOES_NOT_EXIST);
		FAIL_FAST_IF_WIN32_ERROR(last_error);
		return false;
	}
	bool window_base::is_class_registered(HINSTANCE inst, const std::wstring_view &class_name) noexcept
	{
		WNDCLASSEXW wcx{ sizeof(WNDCLASSEXW) };

		if (GetClassInfoExW(inst, class_name.data(), &wcx))
		{
			return true;
		}

		auto last_error = GetLastError();
		_ASSERTE(last_error == ERROR_CLASS_DOES_NOT_EXIST);
		if (last_error != ERROR_CLASS_DOES_NOT_EXIST)
		{
			FAIL_FAST_IF_WIN32_ERROR(last_error);
		}
		return false;
	}
	bool window_base::register_class(uint32_t style, const std::string_view &class_name, const std::string_view &menu_name, int32_t class_extra, int32_t wnd_extra, WNDPROC wndproc, HINSTANCE inst, HBRUSH background, HCURSOR cursor, HICON icon, HICON sm_icon) noexcept
	{
		if (is_class_registered(inst, class_name))
		{
			return true;
		}

		WNDCLASSEXA wcx{ sizeof(WNDCLASSEXA) };
		wcx.style = style;
		wcx.hInstance = inst;
		wcx.cbClsExtra = class_extra;
		wcx.cbWndExtra = wnd_extra;
		wcx.lpszClassName = class_name.data();
		wcx.lpszMenuName = menu_name.data();
		wcx.lpfnWndProc = wndproc;
		wcx.hbrBackground = background;
		wcx.hCursor = cursor;
		wcx.hIcon = icon;
		wcx.hIconSm = sm_icon;

		return RegisterClassExA(&wcx) != 0;
	}
	bool window_base::register_class(uint32_t style, const std::wstring_view &class_name, const std::wstring_view &menu_name, int32_t class_extra, int32_t wnd_extra, WNDPROC wndproc, HINSTANCE inst, HBRUSH background, HCURSOR cursor, HICON icon, HICON sm_icon) noexcept
	{
		if (is_class_registered(inst, class_name))
		{
			return true;
		}

		WNDCLASSEXW wcx{ sizeof(WNDCLASSEXW) };
		wcx.style = style;
		wcx.hInstance = inst;
		wcx.cbClsExtra = class_extra;
		wcx.cbWndExtra = wnd_extra;
		wcx.lpszClassName = class_name.data();
		wcx.lpszMenuName = menu_name.data();
		wcx.lpfnWndProc = wndproc;
		wcx.hbrBackground = background;
		wcx.hCursor = cursor;
		wcx.hIcon = icon;
		wcx.hIconSm = sm_icon;

		return RegisterClassExW(&wcx) != 0;
	}
	//This is used for window_t building the information from the definitions.
	bool window_base::register_class(const WNDCLASSEXA &wcx) noexcept
	{
		if (is_class_registered(wcx.hInstance, wcx.lpszClassName))
		{
			return true;
		}

		return RegisterClassExA(&wcx) != 0;
	}
	bool window_base::register_class(const WNDCLASSEXW &wcx) noexcept
	{
		if (is_class_registered(wcx.hInstance, wcx.lpszClassName))
		{
			return true;
		}

		return RegisterClassExW(&wcx) != 0;
	}
	HWND window_base::create_window(uint32_t ex_style, uint32_t style, const std::string_view &class_name, const std::string_view &title, const POINT &top_left, const SIZE &size, HWND parent, HMENU menu, void *data) noexcept
	{
		window_base *that = static_cast<window_base *>(data);
		_ASSERTE(that->has_associated_window() == false);
		auto result = CreateWindowExA(ex_style, class_name.data(), title.data(), style, top_left.x, top_left.y, size.cx, size.cy, parent, menu, that->get_instance(), data);
		return result;
	}
	HWND window_base::create_window(uint32_t ex_style, uint32_t style, const std::wstring_view &class_name, const std::wstring_view &title, const POINT &top_left, const SIZE &size, HWND parent, HMENU menu, void *data) noexcept
	{
		window_base *that = static_cast<window_base *>(data);
		_ASSERTE(that->has_associated_window() == false);
		auto result = CreateWindowExW(ex_style, class_name.data(), title.data(), style, top_left.x, top_left.y, size.cx, size.cy, parent, menu, that->get_instance(), data);
		return result;
	}
}
#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

namespace windowing
{
	enum class prop_type
	{
		instance,
		mouse_track,
		mouse_track_hook,
		register_callback,
		message_callback
	};

	struct window_traits_a
	{
		using char_t = char;
		using create_struct_t = CREATESTRUCTA;
		using cbt_createwnd_t = CBT_CREATEWNDA;
		using wndclassex_t = WNDCLASSEXA;

		inline static constexpr const bool window_unicode = false;

		static LRESULT WndDefWindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			return DefWindowProcA(wnd, msg, wparam, lparam);
		}
		static HHOOK WndSetWindowsHookEx(int hook_id, HOOKPROC hook_proc, HINSTANCE mod, DWORD thread_id)
		{
			return SetWindowsHookExA(hook_id, hook_proc, mod, thread_id);
		}
		static LONG_PTR WndSetWindowLongPtr(HWND wnd, int index, LONG_PTR new_long)
		{
#ifdef _WIN64
			return SetWindowLongPtrA(wnd, index, new_long);
#else
			return SetWindowLongA(wnd, index, new_long);
#endif
		}
		static LONG WndSetWindowLong([[maybe_unused]] HWND wnd, [[maybe_unused]] int index, [[maybe_unused]] LONG new_long)
		{
#ifdef _WIN64
			const bool set_window_long_called_on_64 = true;
			_ASSERTE(set_window_long_called_on_64 == false);
			__fastfail(FAST_FAIL_FATAL_APP_EXIT);
			return 0;
#else
			return SetWindowLongA(wnd, index, new_long);
#endif
		}
		static LONG_PTR WndGetWindowLongPtr(HWND wnd, int index)
		{
#ifdef _WIN64
			return GetWindowLongPtrA(wnd, index);
#else
			return GetWindowLongA(wnd, index);
#endif
		}
		static LONG WndGetWindowLong([[maybe_unused]] HWND wnd, [[maybe_unused]] int index)
		{
#ifdef _WIN64
			const bool set_window_long_called_on_64 = true;
			_ASSERTE(set_window_long_called_on_64 == false);
			__fastfail(FAST_FAIL_FATAL_APP_EXIT);
			return 0;
#else
			return GetWindowLongA(wnd, index);
#endif
		}

		static bool WndSetProp(HWND wnd, LPCSTR prop, void *value)
		{
			return SetPropA(wnd, prop, value) != FALSE;
		}
		static void *WndGetProp(HWND wnd, LPCSTR prop)
		{
			return GetPropA(wnd, prop);
		}
		static void *WndRemoveProp(HWND wnd, LPCSTR prop)
		{
			return RemovePropA(wnd, prop);
		}
	};
	struct window_traits_w
	{
		using char_t = wchar_t;
		using create_struct_t = CREATESTRUCTW;
		using cbt_createwnd_t = CBT_CREATEWNDW;
		using wndclassex_t = WNDCLASSEXW;

		inline static constexpr const bool window_unicode = true;

		static LRESULT WndDefWindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			return DefWindowProcW(wnd, msg, wparam, lparam);
		}
		static HHOOK WndSetWindowsHookEx(int hook_id, HOOKPROC hook_proc, HINSTANCE mod, DWORD thread_id)
		{
			return SetWindowsHookExW(hook_id, hook_proc, mod, thread_id);
		}
		static LONG_PTR WndSetWindowLongPtr(HWND wnd, int index, LONG_PTR new_long)
		{
#ifdef _WIN64
			return SetWindowLongPtrW(wnd, index, new_long);
#else
			return SetWindowLongW(wnd, index, new_long);
#endif
		}
		static LONG WndSetWindowLong([[maybe_unused]] HWND wnd, [[maybe_unused]] int index, [[maybe_unused]] LONG new_long)
		{
#ifdef _WIN64
			const bool set_window_long_called_on_64 = true;
			_ASSERTE(set_window_long_called_on_64 == false);
			__fastfail(FAST_FAIL_FATAL_APP_EXIT);
			return 0;
#else
			return SetWindowLongW(wnd, index, new_long);
#endif
		}
		static LONG_PTR WndGetWindowLongPtr(HWND wnd, int index)
		{
#ifdef _WIN64
			return GetWindowLongPtrW(wnd, index);
#else
			return GetWindowLongW(wnd, index);
#endif
		}
		static LONG WndGetWindowLong([[maybe_unused]] HWND wnd, [[maybe_unused]] int index)
		{
#ifdef _WIN64
			const bool set_window_long_called_on_64 = true;
			_ASSERTE(set_window_long_called_on_64 == false);
			__fastfail(FAST_FAIL_FATAL_APP_EXIT);
			return 0;
#else
			return GetWindowLongW(wnd, index);
#endif
		}

		static bool WndSetProp(HWND wnd, LPCWSTR prop, void *value)
		{
			return SetPropW(wnd, prop, value) != FALSE;
		}
		static void *WndGetProp(HWND wnd, LPCWSTR prop)
		{
			return GetPropW(wnd, prop);
		}
		static void *WndRemoveProp(HWND wnd, LPCWSTR prop)
		{
			return RemovePropW(wnd, prop);
		}
	};

	bool set_property_a(HWND, prop_type, void *);
	void *get_property_a(HWND, prop_type);
	void *remove_property_a(HWND, prop_type);
	bool set_property_w(HWND, prop_type, void *);
	void *get_property_w(HWND, prop_type);
	void *remove_property_w(HWND, prop_type);

	struct prop_traits_a
	{
		static bool set_property(HWND wnd, prop_type prop, void *data)
		{
			return windowing::set_property_a(wnd, prop, data);
		}
		static void *get_property(HWND wnd, prop_type prop)
		{
			return windowing::get_property_a(wnd, prop);
		}
		static void *remove_property(HWND wnd, prop_type prop)
		{
			return windowing::remove_property_a(wnd, prop);
		}
	};
	struct prop_traits_w
	{
		static bool set_property(HWND wnd, prop_type prop, void *data)
		{
			return windowing::set_property_w(wnd, prop, data);
		}
		static void *get_property(HWND wnd, prop_type prop)
		{
			return windowing::get_property_w(wnd, prop);
		}
		static void *remove_property(HWND wnd, prop_type prop)
		{
			return windowing::remove_property_w(wnd, prop);
		}
	};
}
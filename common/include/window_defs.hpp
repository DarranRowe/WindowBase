#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

namespace windowing
{
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
#ifdef _DEBUG
			const bool set_window_long_called_on_64{ true };
			_ASSERTE(set_window_long_called_on_64 == false);
#endif
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
#ifdef _DEBUG
			const bool get_window_long_called_on_64{ true };
			_ASSERTE(get_window_long_called_on_64 == false);
#endif
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
#ifdef _DEBUG
			const bool set_window_long_called_on_64{ true };
			_ASSERTE(set_window_long_called_on_64 == false);
#endif
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
#ifdef _DEBUG
			const bool get_window_long_called_on_64{ true };
			_ASSERTE(get_window_long_called_on_64 == false);
#endif
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

	inline LONG_PTR TWndGetWindowLongPtr(HWND wnd, int index, bool unicode)
	{
		using ta = window_traits_a;
		using tw = window_traits_w;
		return unicode == true ? tw::WndGetWindowLongPtr(wnd, index) : ta::WndGetWindowLongPtr(wnd, index);
	}
}
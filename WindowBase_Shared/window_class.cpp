#include "windowbase/window_class.hpp"

#include <wil/result.h>

namespace window_base::windowing
{
	//As per the Old New Thing article on the 29th April 2015, GetClassInfo actually returns the atom that
	//we care about. This is undocumented, but ATL relies on it.
	uint16_t is_class_registered(HINSTANCE instance, const std::string_view &class_name) noexcept
	{
		WNDCLASSEXA wcx{ sizeof(WNDCLASSEXA) };

		auto result = GetClassInfoExA(instance, class_name.data(), &wcx);

		if (!result)
		{
			auto last_error{ GetLastError() };
			_ASSERTE(last_error == ERROR_CLASS_DOES_NOT_EXIST);
			if (last_error != ERROR_CLASS_DOES_NOT_EXIST)
			{
				FAIL_FAST_IF_WIN32_ERROR(last_error);
			}
		}

		return static_cast<uint16_t>(result);
	}

	uint16_t is_class_registered(HINSTANCE instance, const std::wstring_view &class_name) noexcept
	{
		WNDCLASSEXW wcx{ sizeof(WNDCLASSEXW) };

		auto result = GetClassInfoExW(instance, class_name.data(), &wcx);

		if (!result)
		{
			auto last_error{ GetLastError() };
			_ASSERTE(last_error == ERROR_CLASS_DOES_NOT_EXIST);
			if (last_error != ERROR_CLASS_DOES_NOT_EXIST)
			{
				FAIL_FAST_IF_WIN32_ERROR(last_error);
			}
		}

		return static_cast<uint16_t>(result);
	}

	uint16_t register_class(uint32_t style, const std::string_view &class_name, const std::string_view &menu_name, int32_t class_extra, int32_t wnd_extra, WNDPROC wndproc, HINSTANCE inst, HBRUSH background, HCURSOR cursor, HICON icon, HICON iconsm) noexcept
	{
		auto is_registered_result = is_class_registered(inst, class_name);
		if (is_registered_result)
		{
			return is_registered_result;
		}

#if (__cpp_designated_initializers >= 201707L)
		WNDCLASSEXA wcx{ .cbSize = sizeof(WNDCLASSEXA),
			.style = style,
			.lpfnWndProc = wndproc,
			.cbClsExtra = class_extra,
			.cbWndExtra = wnd_extra,
			.hInstance = inst,
			.hIcon = icon,
			.hCursor = cursor,
			.hbrBackground = background,
			.lpszMenuName = menu_name.data(),
			.lpszClassName = class_name.data(),
			.hIconSm = iconsm
		};
#else
		WNDCLASSEXA wcx{ sizeof(WNDCLASSEXA),
			style,
			wndproc,
			class_extra,
			wnd_extra,
			inst,
			icon,
			cursor,
			background,
			menu_name.data(),
			class_name.data(),
			iconsm
		};
#endif

		return RegisterClassExA(&wcx);
	}

	uint16_t register_class(uint32_t style, const std::wstring_view &class_name, const std::wstring_view &menu_name, int32_t class_extra, int32_t wnd_extra, WNDPROC wndproc, HINSTANCE inst, HBRUSH background, HCURSOR cursor, HICON icon, HICON iconsm) noexcept
	{
		auto is_registered_result = is_class_registered(inst, class_name);
		if (is_registered_result)
		{
			return is_registered_result;
		}

#if (__cpp_designated_initializers >= 201707L)
		WNDCLASSEXW wcx{ .cbSize = sizeof(WNDCLASSEXW),
			.style = style,
			.lpfnWndProc = wndproc,
			.cbClsExtra = class_extra,
			.cbWndExtra = wnd_extra,
			.hInstance = inst,
			.hIcon = icon,
			.hCursor = cursor,
			.hbrBackground = background,
			.lpszMenuName = menu_name.data(),
			.lpszClassName = class_name.data(),
			.hIconSm = iconsm
		};
#else
		WNDCLASSEXW wcx{ sizeof(WNDCLASSEXW),
			style,
			wndproc,
			class_extra,
			wnd_extra,
			inst,
			icon,
			cursor,
			background,
			menu_name.data(),
			class_name.data(),
			iconsm
		};
#endif

		return RegisterClassExW(&wcx);
	}

	uint16_t register_class(const WNDCLASSEXA &wcx) noexcept
	{
		auto is_registered_result = is_class_registered(wcx.hInstance, wcx.lpszClassName);
		if (is_registered_result)
		{
			return is_registered_result;
		}

		return RegisterClassExA(&wcx);
	}

	uint16_t register_class(const WNDCLASSEXW &wcx) noexcept
	{
		auto is_registered_result = is_class_registered(wcx.hInstance, wcx.lpszClassName);
		if (is_registered_result)
		{
			return is_registered_result;
		}

		return RegisterClassExW(&wcx);
	}
}
#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <string_view>

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>

namespace window_base::windowing
{
	uint16_t is_class_registered(HINSTANCE, const std::string_view &) noexcept;
	uint16_t is_class_registered(HINSTANCE, const std::wstring_view &) noexcept;
	uint16_t register_class(uint32_t, const std::string_view &, const std::string_view &, int32_t, int32_t, WNDPROC, HINSTANCE, HBRUSH, HCURSOR, HICON, HICON) noexcept;
	uint16_t register_class(uint32_t, const std::wstring_view &, const std::wstring_view &, int32_t, int32_t, WNDPROC, HINSTANCE, HBRUSH, HCURSOR, HICON, HICON) noexcept;
	uint16_t register_class(const WNDCLASSEXA &) noexcept;
	uint16_t register_class(const WNDCLASSEXW &) noexcept;
}
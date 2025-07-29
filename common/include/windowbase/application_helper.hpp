#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <cstdint>

namespace window_base::application::helper
{
	bool is_windows_10_or_greater();
	bool is_windows_11_or_greater();
	uint32_t get_windows_10_build();

	bool is_at_least_windows_10_build(uint32_t build);
	bool is_windows_10_build(uint32_t build);
	bool is_build_win10_range(uint32_t build);
	bool is_build_known_win11_range(uint32_t build);
}
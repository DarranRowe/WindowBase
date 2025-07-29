#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <cstdint>

#define NOVTABLE __declspec(novtable)
#define EMPTYBASES __declspec(empty_bases)

namespace window_base
{
#ifdef _WIN64
	using uintptr_t = uint64_t;
	using intptr_t = int64_t;
#else
	using uintptr_t = uint32_t;
	using intptr_t = int32_t;
#endif

	constexpr const uint32_t cursor_creation_scaling_default = 2;
	constexpr const uint32_t cursor_creation_scaling_none = 1;
	enum class dpi_awareness
	{
		unknown,
		unaware,
		system,
		per_monitor,
		per_monitor_v2,
		unaware_scaled
	};

	enum class dpi_hosting_behaviour
	{
		hosting_invalid = -1,
		hosting_default,
		hosting_mixed
	};
}
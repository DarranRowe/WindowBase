#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <string>
#include <cstdint>
#include <cinttypes>

namespace application
{
	struct init_failure_information
	{
		int32_t error_code;
		std::string file;
		std::string function;
		uint32_t line_number;
	};
}
#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <string>
#include <format>

namespace application::debug
{
	struct log_instance
	{
	};

	void write_to_debugger(const std::wstring &);

	void write_to_log(const log_instance &, const std::wstring &);

	void write_to_stderr(const std::wstring &);

	template <typename... Args>
	void format_write_to_debugger(std::wformat_string<Args...> fmt, Args &&... args)
	{
		auto format_string = std::format(fmt, std::forward<Args>(args)...);
		write_to_debugger(format_string);
	}

	template <typename... Args>
	void format_write_to_log(const log_instance &log, std::wformat_string<Args...> fmt, Args &&... args)
	{
		auto format_string = std::format(fmt, std::forward<Args>(args)...);
		write_to_log(log, format_string);
	}

	template <typename... Args>
	void format_write_to_stderr(std::wformat_string<Args...> fmt, Args &&... args)
	{
		auto format_string = std::format(fmt, std::forward<Args>(args)...);
		write_to_stderr(format_string);
	}
}
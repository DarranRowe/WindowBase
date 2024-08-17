#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <string>
#include <string_view>
#if (__cplusplus >= 202002L || (defined _MSVC_LANG && _MSVC_LANG >= 202002L))
#include <format>
#endif

namespace application::helper
{
	bool is_windows_10_or_greater();
	bool is_windows_11_or_greater();
	uint32_t get_windows_10_build();

	bool is_at_least_windows_10_build(uint32_t build);
	bool is_windows_10_build(uint32_t build);
	bool is_build_win10_range(uint32_t build);
	bool is_build_known_win11_range(uint32_t build);

	void allocate_console_for_ui_process();
	bool api_is_debugger_present();
	bool is_file_translated(FILE *);
	bool is_stdout_translated();
	bool is_stderr_translated();
	bool no_cache_is_file_translated(FILE *);
	bool no_cache_is_stdout_translated();
	bool no_cache_is_stderr_translated();
	void write_string_to_debugger(const std::string &);
	void write_string_to_debugger(const std::string_view &);
	void write_string_to_debugger(const std::wstring &);
	void write_string_to_debugger(const std::wstring_view &);
	int write_string_to_stream(FILE *, const std::string &);
	int write_string_to_stream(FILE *, const std::string_view &);
	int write_string_to_stream(FILE *, const std::wstring &);
	int write_string_to_stream(FILE *, const std::wstring_view &);
	int write_string_to_stdout(const std::string &);
	int write_string_to_stdout(const std::string_view &);
	int write_string_to_stdout(const std::wstring &);
	int write_string_to_stdout(const std::wstring_view &);
	int write_string_to_stderr(const std::string &);
	int write_string_to_stderr(const std::string_view &);
	int write_string_to_stderr(const std::wstring &);
	int write_string_to_stderr(const std::wstring_view &);

#if (__cplusplus >= 202002L || (defined _MSVC_LANG && _MSVC_LANG >= 202002L))
	template <typename... _Types>
	void write_debugger(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void write_debugger(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void writeln_debugger(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
			fmt_string += "\r\n";
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void writeln_debugger(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
			fmt_string += "\r\n";
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void write_debugger(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void write_debugger(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void writeln_debugger(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
			fmt_string += L"\r\n";
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void writeln_debugger(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
			fmt_string += L"\r\n";
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	int write_stream(FILE *stream, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int write_stream(FILE *stream, const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int writeln_stream(FILE *stream, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_file_translated(stream))
		{
			fmt_string += "\n";
		}
		else
		{
			fmt_string += "\r\n";
		}
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int writeln_stream(FILE *stream, const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_file_translated(stream))
		{
			fmt_string += "\n";
		}
		else
		{
			fmt_string += "\r\n";
		}
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int write_stream(FILE *stream, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int write_stream(FILE *stream, const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int writeln_stream(FILE *stream, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_file_translated(stream))
		{
			fmt_string += L"\n";
		}
		else
		{
			fmt_string += L"\r\n";
		}
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int writeln_stream(FILE *stream, const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_file_translated(stream))
		{
			fmt_string += L"\n";
		}
		else
		{
			fmt_string += L"\r\n";
		}
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int write_stdout(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int write_stdout(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int writeln_stdout(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_stdout_translated())
		{
			fmt_string += "\n";
		}
		else
		{
			fmt_string += "\r\n";
		}
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int writeln_stdout(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_stdout_translated())
		{
			fmt_string += "\n";
		}
		else
		{
			fmt_string += "\r\n";
		}
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int write_stdout(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int write_stdout(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int writeln_stdout(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_stdout_translated())
		{
			fmt_string += L"\n";
		}
		else
		{
			fmt_string += L"\r\n";
		}
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int writeln_stdout(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_stdout_translated())
		{
			fmt_string += L"\n";
		}
		else
		{
			fmt_string += L"\r\n";
		}
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int write_stderr(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int write_stderr(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int writeln_stderr(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_stderr_translated())
		{
			fmt_string += "\n";
		}
		else
		{
			fmt_string += "\r\n";
		}
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int writeln_stderr(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_stderr_translated())
		{
			fmt_string += "\n";
		}
		else
		{
			fmt_string += "\r\n";
		}
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int write_stderr(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int write_stderr(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int writeln_stderr(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_stderr_translated())
		{
			fmt_string += L"\n";
		}
		else
		{
			fmt_string += L"\r\n";
		}
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int writeln_stderr(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		if (is_stderr_translated())
		{
			fmt_string += L"\n";
		}
		else
		{
			fmt_string += L"\r\n";
		}
		return write_string_to_stderr(fmt_string);
	}
#endif
}
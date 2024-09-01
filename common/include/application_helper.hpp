#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <cstdarg>
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

	inline std::string format_to_string_s(const char *format, va_list va)
	{
		//snprintf returns the how many characters it would write.
		va_list args = va;

		//As long as this is > than the sso size
		//then it is ok.
		size_t string_buffer_size = 128;
		std::string s(string_buffer_size, '\0');

		//The extra +1 because snprintf also writes a null.
		//The standard does allow writing to the terminator as long
		//as it is with a default initialised character (CharT()).
		auto result = vsnprintf(s.data(), s.size() + 1, format, args);
		if (result > string_buffer_size)
		{
			s.resize(string_buffer_size);
			result = vsnprintf(s.data(), s.size() + 1, format, args);
		}
		else
		{
			//Shrink the string down to just the result.
			s.resize(result);
		}

		return s;
	}

	inline std::wstring format_to_string_s(const wchar_t *format, va_list va)
	{
		//swprintf returns -1 if the buffer isn't large enough.
		//We call it in a loop and double the buffer each time
		va_list args = va;

		size_t string_buffer = 128;
		std::wstring s(string_buffer, '\0');
		bool do_format = true;

		while (do_format)
		{
			//The extra +1 because it also writes a null.
			auto result = vswprintf(s.data(), s.size() + 1, format, args);
			if (result != -1)
			{
				s.resize(result);
				do_format = false;
			}
			else
			{
				string_buffer *= 2;
				s.resize(string_buffer);
			}
		}

		return s;
	}

	inline void append_new_line(std::string &string, bool cr)
	{
		if (cr)
		{
			string += '\r';
		}
		string += '\n';
	}

	inline void append_new_line(std::wstring &string, bool cr)
	{
		if (cr)
		{
			string += L'\r';
		}
		string += L'\n';
	}

	template <typename CharT>
	inline void write_debugger_s(const CharT *format, ...)
	{
		if (api_is_debugger_present())
		{
			va_list args{};
			va_start(args, format);
			std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
			write_string_to_debugger(fmt_string);
			va_end(args);
		}
	}

	template <typename CharT>
	inline void writeln_debugger_s(const CharT *format, ...)
	{
		if (api_is_debugger_present())
		{
			va_list args{};
			va_start(args, format);
			std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
			append_new_line(fmt_string, true);
			write_string_to_debugger(fmt_string);
			va_end(args);
		}
	}

	template <typename CharT>
	inline int write_stream_s(FILE *stream, const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		write_string_to_stream(stream, fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int writeln_stream_s(FILE *stream, const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		append_new_line(fmt_string, !is_file_translated(stream));
		write_string_to_stream(stream, fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int write_stdout_s(const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		write_string_to_stdout(fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int writeln_stdout_s(FILE *stream, const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		append_new_line(fmt_string, !is_stdout_translated());
		write_string_to_stdout(fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int write_stderr_s(const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		write_string_to_stderr(fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int writeln_stderr_s(FILE *stream, const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		append_new_line(fmt_string, !is_stderr_translated());
		write_string_to_stderr(fmt_string);
		va_end(args);
	}
	

#if (__cplusplus >= 202002L || (defined _MSVC_LANG && _MSVC_LANG >= 202002L))
	template <typename... _Types>
	std::string format_to_string_f(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		return std::format(_Fmt, std::forward<_Types>(_Args)...);
	}

	template <typename... _Types>
	std::string format_to_string_f(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		return std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
	}

	template <typename... _Types>
	std::wstring format_to_string_f(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		return std::format(_Fmt, std::forward<_Types>(_Args)...);
	}

	template <typename... _Types>
	std::wstring format_to_string_f(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		return std::format(_Loc, _Fmt, std::forward<_Types>(_Args)...);
	}

	template <typename... _Types>
	void write_debugger(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void write_debugger(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void writeln_debugger(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
			append_new_line(fmt_string, true);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void writeln_debugger(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
			append_new_line(fmt_string, true);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void write_debugger(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void write_debugger(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void writeln_debugger(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
			append_new_line(fmt_string, true);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	void writeln_debugger(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		if (api_is_debugger_present())
		{
			auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
			append_new_line(fmt_string, true);
			write_string_to_debugger(fmt_string);
		}
	}

	template <typename... _Types>
	int write_stream(FILE *stream, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int write_stream(FILE *stream, const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int writeln_stream(FILE *stream, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_file_translated(stream));
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int writeln_stream(FILE *stream, const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_file_translated(stream));
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int write_stream(FILE *stream, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int write_stream(FILE *stream, const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int writeln_stream(FILE *stream, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_file_translated(stream));
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int writeln_stream(FILE *stream, const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_file_translated(stream));
		return write_string_to_stream(stream, fmt_string);
	}

	template <typename... _Types>
	int write_stdout(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int write_stdout(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int writeln_stdout(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_stdout_translated());
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int writeln_stdout(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_stdout_translated());
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int write_stdout(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int write_stdout(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int writeln_stdout(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_stdout_translated());
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int writeln_stdout(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_stdout_translated());
		return write_string_to_stdout(fmt_string);
	}

	template <typename... _Types>
	int write_stderr(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int write_stderr(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int writeln_stderr(std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_stderr_translated());
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int writeln_stderr(const std::locale &_Loc, std::format_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_stderr_translated());
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int write_stderr(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int write_stderr(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int writeln_stderr(std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_stderr_translated());
		return write_string_to_stderr(fmt_string);
	}

	template <typename... _Types>
	int writeln_stderr(const std::locale &_Loc, std::wformat_string<_Types...> _Fmt, _Types &&... _Args)
	{
		auto fmt_string = format_to_string_f(_Loc, _Fmt, std::forward<_Types>(_Args)...);
		//If the output stream is in translated mode then the underlying
		//functions will translate \n to \r\n, so we only want to append \n.
		append_new_line(fmt_string, !is_stderr_translated());
		return write_string_to_stderr(fmt_string);
	}
#else
	template <typename CharT>
	inline void write_debugger(const CharT *format, ...)
	{
		if (api_is_debugger_present())
		{
			va_list args{};
			va_start(args, format);
			std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
			write_string_to_debugger(fmt_string);
			va_end(args);
		}
	}

	template <typename CharT>
	inline void writeln_debugger(const CharT *format, ...)
	{
		if (api_is_debugger_present())
		{
			va_list args{};
			va_start(args, format);
			std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
			append_new_line(fmt_string, true);
			write_string_to_debugger(fmt_string);
			va_end(args);
		}
	}

	template <typename CharT>
	inline int write_stream(FILE *stream, const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		write_string_to_stream(stream, fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int writeln_stream(FILE *stream, const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		append_new_line(fmt_string, !is_file_translated(stream));
		write_string_to_stream(stream, fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int write_stdout(const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		write_string_to_stdout(fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int writeln_stdout(FILE *stream, const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		append_new_line(fmt_string, !is_stdout_translated());
		write_string_to_stdout(fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int write_stderr(const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		write_string_to_stderr(fmt_string);
		va_end(args);
	}

	template <typename CharT>
	inline int writeln_stderr(FILE *stream, const CharT *format, ...)
	{
		va_list args{};
		va_start(args, format);
		std::basic_string<CharT> fmt_string = format_to_string_s(format, args);
		append_new_line(fmt_string, !is_stderr_translated());
		write_string_to_stderr(fmt_string);
		va_end(args);
	}
#endif
}
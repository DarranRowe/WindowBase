#include <Windows.h>

#include "debug_helper.hpp"

namespace application::debug
{
	void write_to_debugger(const std::wstring &fs)
	{
		if (IsDebuggerPresent())
		{
			OutputDebugStringW(fs.c_str());
		}
	}

	void write_to_log(const log_instance &, const std::wstring &)
	{
	}

	void write_to_stderr(const std::wstring &fs)
	{
		fwrite(fs.c_str(), 2, fs.size(), stderr);
	}
}
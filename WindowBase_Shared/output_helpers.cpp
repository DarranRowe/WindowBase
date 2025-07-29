#include "windowbase/output_helpers.hpp"

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>

#include <io.h>
#include <fcntl.h>

namespace window_base::output_helpers
{
	namespace debug
	{
		bool is_debugger_present()
		{
			return IsDebuggerPresent() != FALSE;
		}

		void output_debug_string(const char *out_str)
		{
			OutputDebugStringA(out_str);
		}

		void output_debug_string(const wchar_t *out_str)
		{
			OutputDebugStringW(out_str);
		}
	}
}
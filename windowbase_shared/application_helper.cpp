#include "application_helper.hpp"

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <memory>
#include <appmodel.h>
#include <io.h>
#include <fcntl.h>
#include <vector>

namespace application::helper
{
	namespace details
	{
		bool has_win10_actctx()
		{
			auto exe_handle = GetModuleHandleW(nullptr);
			SIZE_T buffer_required = 0;
			QueryActCtxW(QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE, exe_handle, nullptr, CompatibilityInformationInActivationContext, nullptr, 0, &buffer_required);

			std::unique_ptr<std::byte[]> act_ctx_buffer = std::make_unique<std::byte[]>(buffer_required);

			QueryActCtxW(QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE, exe_handle, nullptr, CompatibilityInformationInActivationContext, act_ctx_buffer.get(), buffer_required, &buffer_required);

			{
				ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION &actctx_ci = *reinterpret_cast<ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION *>(act_ctx_buffer.get());

				COMPATIBILITY_CONTEXT_ELEMENT target_id{};

				//<supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}" />
				GUID os_id = GUID{ 0x8e0f7a12, 0xbfb3, 0x4fe8, {0xb9, 0xa5, 0x48, 0xfd, 0x50, 0xa1, 0x5a, 0x9a} };

				auto elements = actctx_ci.ElementCount;
				for (DWORD it = 0; it < elements; ++it)
				{
					if (actctx_ci.Elements[it].Type == ACTCTX_COMPATIBILITY_ELEMENT_TYPE_OS && actctx_ci.Elements[it].Id == os_id)
					{
						return true;
					}
				}
			}

			return false;
		}

		uint32_t get_build_from_version();
		uint32_t estimate_build_from_exports()
		{
			//Look for kernelbase exports.
			//GetPackageGraphRevisionId for Windows 11 22H2
			//GetMachineTypeAttributes for Windows 11 21H2
			//GetPackageInfo3 for Windows 10 20H1
			//GetPackageInfo2 for Windows 10 19H1
			//InitializeContext2 for Windows 10 Redstone 5
			//RaiseCustomSystemEventTrigger for Windows 10 Redstone 4
			//OpenCommPort for Windows 10 Restone 3
			//MapViewOfFileNuma2 for Windows 10 Redstone 2

			//RS1 and TH2 are awkward
			//Try this function in Ole32.dll for RS1.
			//OleGetClipboardWithEnterpriseInfo for Windows 10 Redstone 1

			//There is nothing clear for TH2, try looking for efswrt.dll
			//ProtectFileToEnterpriseIdentity for Windows 10 Threshold 2

			//SetProcessValidCallTargets for Windows 10

			return 0;
		}

		bool look_for_win10_base_function()
		{
			//If we only want to be sure that we are on Windows 10, just look for a function in one of the libraries.
			//We use SetProcessValidCallTargets from CFG to do this.

			HMODULE kernel_base = GetModuleHandleW(L"kernelbase.dll");
			if (kernel_base == nullptr)
			{
				return false;
			}

			auto fp = GetProcAddress(kernel_base, "SetProcessValidCallTargets");

			return fp != nullptr;
		}

		bool look_for_win11_base_function()
		{
			//If we only want to be sure that we are on Windows 11, just look for a function in one of the libraries.
			//We use GetMachineTypeAttributes to do this.

			HMODULE kernel_base = GetModuleHandleW(L"kernelbase.dll");
			if (kernel_base == nullptr)
			{
				return false;
			}

			auto fp = GetProcAddress(kernel_base, "GetMachineTypeAttributes");

			return fp != nullptr;
		}
	}

	bool is_windows_10_or_greater()
	{
		return details::look_for_win10_base_function();
	}

	bool is_windows_11_or_greater()
	{
		return details::look_for_win11_base_function();
	}

	uint32_t get_windows_10_build()
	{
		return 0;
	}

	bool is_at_least_windows_10_build(uint32_t build)
	{
		if (build < 10240)
		{
			return false;
		}
		OSVERSIONINFOEXW osv{};
		osv.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);
		osv.dwMajorVersion = 10;
		osv.dwMinorVersion = 0;
		osv.dwBuildNumber = build;

		auto cm = VerSetConditionMask(VerSetConditionMask(VerSetConditionMask(0, VER_BUILDNUMBER, VER_GREATER_EQUAL), VER_MINORVERSION, VER_EQUAL), VER_MAJORVERSION, VER_EQUAL);

		return VerifyVersionInfoW(&osv, VER_MAJORVERSION | VER_MINORVERSION | VER_BUILDNUMBER, cm);
	}

	bool is_windows_10_build(uint32_t build)
	{
		if (build < 10240)
		{
			return false;
		}
		OSVERSIONINFOEXW osv{};
		osv.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);
		osv.dwMajorVersion = 10;
		osv.dwMinorVersion = 0;
		osv.dwBuildNumber = build;

		auto cm = VerSetConditionMask(VerSetConditionMask(VerSetConditionMask(0, VER_BUILDNUMBER, VER_EQUAL), VER_MINORVERSION, VER_EQUAL), VER_MAJORVERSION, VER_EQUAL);

		return VerifyVersionInfoW(&osv, VER_MAJORVERSION | VER_MINORVERSION | VER_BUILDNUMBER, cm);
	}

	bool is_build_win10_range(uint32_t build)
	{
		//Builds below 10240 were 8.1,
		//the latest 10 build is 19041/19045
		if (build < 10240 || build >= 20000)
		{
			return false;
		}
		return true;
	}

	bool is_build_known_win11_range(uint32_t build)
	{
		//Builds 22000 and above are currently Windows 11
		if (build >= 22000)
		{
			return true;
		}
		return false;
	}

	//Has the stdout and stderr files
	//been set for unicode output.
	//Assume false because this is how the files are initialised.
	static bool s_stdout_unicode = false;
	static bool s_stderr_unicode = false;
	
	enum class translated_state
	{
		unknown,
		no,
		yes
	};

	static std::vector<translated_state> s_mode{};

	void allocate_console_for_ui_process()
	{
		auto d_in_handle = GetStdHandle(STD_INPUT_HANDLE);
		auto d_out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		auto d_err_handle = GetStdHandle(STD_ERROR_HANDLE);

		if (!AllocConsole())
		{
			DWORD last_error = GetLastError();
			write_debugger(L"AllocConsole failed. Last error: {}. Process is likely attached to a console.", last_error);
			return;
		}

		//Only reopen the file handles if there is not an existing console.
		//Also, only reopen the files if the standard handle wasn't null before
		//we allocated the console. This indicates that the handles were redirected.
		//Opening them will direct them back to the console.
		FILE *dummy = nullptr;
		if (d_in_handle == nullptr)
		{
			freopen_s(&dummy, "CONIN$", "r", stdin);
		}
		if (d_out_handle == nullptr)
		{
			freopen_s(&dummy, "CONOUT$", "w", stdout);
		}
		if (d_err_handle == nullptr)
		{
			freopen_s(&dummy, "CONOUT$", "w", stderr);
		}
	}

	//This is to remove the need for Windows.h in our headers.
	bool api_is_debugger_present()
	{
		return IsDebuggerPresent() != FALSE;
	}

	bool is_file_translated(FILE *stream)
	{
		auto fd = _fileno(stream);

		if (fd == -1)
		{
			writeln_debugger(L"File given is invalid.");
			_ASSERTE(false);
			__fastfail(static_cast<unsigned int>(-1));
		}

		if (fd == -2)
		{
			_ASSERTE(stream == stdout || stream == stderr);
			writeln_debugger(L"Standard out or standard error not associated with a console.");
			_ASSERTE(false);
			__fastfail(static_cast<unsigned int>(-2));
		}

		//This should shortcircuit.
		//The only known cases where fd is negative have been dealt with.
		if (s_mode.size() < static_cast<size_t>(fd) || s_mode[fd] == translated_state::unknown)
		{
			return no_cache_is_file_translated(stream);
		}

		return s_mode[fd] == translated_state::yes;
	}

	bool is_stdout_translated()
	{
		return is_file_translated(stdout);
	}

	bool is_stderr_translated()
	{
		return is_file_translated(stderr);
	}

	bool no_cache_is_file_translated(FILE *stream)
	{
		auto fd = _fileno(stream);

		if (fd == -1)
		{
			writeln_debugger(L"File given is invalid.");
			_ASSERTE(false);
		}

		if (fd == -2)
		{
			_ASSERTE(stream == stdout || stream == stderr);
			writeln_debugger(L"Standard out or standard error not associated with a console.");
			_ASSERTE(false);
		}

		if (s_mode.size() < static_cast<size_t>(fd))
		{
			//Add an extra 1 to the descriptor so that
			//the vector operators are guaranteed to work.
			s_mode.resize(fd + 1, translated_state::unknown);
		}

		auto old_mode = _setmode(fd, _O_TEXT);
		auto ignore_old_mode = _setmode(fd, old_mode);
		ignore_old_mode;

		bool translated = old_mode & _O_TEXT;
		if (translated)
		{
			s_mode[fd] = translated_state::yes;
		}
		else
		{
			s_mode[fd] = translated_state::no;
		}

		return translated;
	}

	bool no_cache_is_stdout_translated()
	{
		return no_cache_is_file_translated(stdout);
	}

	bool no_cache_is_stderr_translated()
	{
		return no_cache_is_file_translated(stderr);
	}

	void write_string_to_debugger(const std::string &fmt_string)
	{
		OutputDebugStringA(fmt_string.c_str());
	}

	void write_string_to_debugger(const std::string_view &fmt_string)
	{
		OutputDebugStringA(fmt_string.data());
	}

	void write_string_to_debugger(const std::wstring &fmt_string)
	{
		OutputDebugStringW(fmt_string.c_str());
	}

	void write_string_to_debugger(const std::wstring_view &fmt_string)
	{
		OutputDebugStringW(fmt_string.data());
	}

	int write_string_to_stream(FILE *stream, const std::string &fmt_string)
	{
		return fputs(fmt_string.c_str(), stream);
	}

	int write_string_to_stream(FILE *stream, const std::string_view &fmt_string)
	{
		return fputs(fmt_string.data(), stream);
	}

	int write_string_to_stream(FILE *stream, const std::wstring &fmt_string)
	{
		return fputws(fmt_string.c_str(), stream);
	}

	int write_string_to_stream(FILE *stream, const std::wstring_view &fmt_string)
	{
		return fputws(fmt_string.data(), stream);
	}

	int write_string_to_stdout(const std::string &fmt_string)
	{
		return write_string_to_stream(stdout, fmt_string);
	}

	int write_string_to_stdout(const std::string_view &fmt_string)
	{
		return write_string_to_stream(stdout, fmt_string);
	}

	int write_string_to_stdout(const std::wstring &fmt_string)
	{
		return write_string_to_stream(stdout, fmt_string);
	}

	int write_string_to_stdout(const std::wstring_view &fmt_string)
	{
		return write_string_to_stream(stdout, fmt_string);
	}

	int write_string_to_stderr(const std::string &fmt_string)
	{
		return write_string_to_stream(stderr, fmt_string);
	}

	int write_string_to_stderr(const std::string_view &fmt_string)
	{
		return write_string_to_stream(stderr, fmt_string);
	}

	int write_string_to_stderr(const std::wstring &fmt_string)
	{
		return write_string_to_stream(stderr, fmt_string);
	}

	int write_string_to_stderr(const std::wstring_view &fmt_string)
	{
		return write_string_to_stream(stderr, fmt_string);
	}
}
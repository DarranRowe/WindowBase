//We are forcing the usage of deprecated functions
//only in this file.
#define FKG_FORCED_USAGE

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <memory>
#include <appmodel.h>
#include <vector>
#include "windowbase/application_helper.hpp"
#include "windowbase/utility.hpp"

namespace window_base::application::helper
{
	namespace details
	{
		std::pair<bool, bool> has_actctx()
		{
			using utility::conversion::type_convert;
			using utility::conversion::pointer_deref;

			bool has_81_actctx{};
			bool has_10_actctx{};
			auto exe_handle{ GetModuleHandleW(nullptr) };
			SIZE_T buffer_required{ 0 };
			QueryActCtxW(QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE, exe_handle, nullptr, CompatibilityInformationInActivationContext, nullptr, 0, &buffer_required);

			std::unique_ptr<std::byte[]> act_ctx_buffer{ std::make_unique<std::byte[]>(buffer_required) };

			QueryActCtxW(QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE, exe_handle, nullptr, CompatibilityInformationInActivationContext, act_ctx_buffer.get(), buffer_required, &buffer_required);

			{
				ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION &actctx_ci{ pointer_deref(type_convert<ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION>(act_ctx_buffer.get())) };

				COMPATIBILITY_CONTEXT_ELEMENT target_id{};

				//<supportedOS Id="{1f676c76-80e1-4239-95bb-83d0f6d0da78}" />
				GUID win81_os_id = GUID{ 0x1f676c76, 0x80e1, 0x4239, {0x95, 0xbb, 0x83, 0xd0, 0xf6, 0xd0, 0xda, 0x78} };
				//<supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}" />
				GUID win10_os_id = GUID{ 0x8e0f7a12, 0xbfb3, 0x4fe8, {0xb9, 0xa5, 0x48, 0xfd, 0x50, 0xa1, 0x5a, 0x9a} };

				auto elements = actctx_ci.ElementCount;
				for (DWORD it = 0; it < elements; ++it)
				{
					if (actctx_ci.Elements[it].Type == ACTCTX_COMPATIBILITY_ELEMENT_TYPE_OS && actctx_ci.Elements[it].Id == win81_os_id)
					{
						has_81_actctx = true;
					}
					if (actctx_ci.Elements[it].Type == ACTCTX_COMPATIBILITY_ELEMENT_TYPE_OS && actctx_ci.Elements[it].Id == win10_os_id)
					{
						has_10_actctx = true;
					}
				}
			}

			return {has_81_actctx, has_10_actctx};
		}

		uint32_t get_build_from_version()
		{
			using utility::conversion::type_convert;
			using utility::conversion::value_convert;

			OSVERSIONINFOEXW vi{ sizeof(OSVERSIONINFOEXW) };

			GetVersionExW(type_convert<OSVERSIONINFOW>(&vi));

			return value_convert<uint32_t>(vi.dwBuildNumber);
		}

		uint32_t estimate_build_from_exports()
		{
			//Look for kernelbase exports.
			//AddPackageDependency2 for Windows 11 24H2
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

		bool look_for_win81_base_function()
		{
			//If we only want to be sure that we are on Windows 8.1, just look for a function in one of the libraries.
			//We use IsProcessCritical from the process/threads API.
			HMODULE kernel_base{ GetModuleHandleW(L"kernelbase.dll") };
			if (kernel_base == nullptr)
			{
				return false;
			}

			auto fp{ GetProcAddress(kernel_base, "IsProcessCritical") };

			return fp != nullptr;
		}

		bool look_for_win10_base_function()
		{
			//If we only want to be sure that we are on Windows 10, just look for a function in one of the libraries.
			//We use SetProcessValidCallTargets from CFG to do this.

			HMODULE kernel_base{ GetModuleHandleW(L"kernelbase.dll") };
			if (kernel_base == nullptr)
			{
				return false;
			}

			auto fp{ GetProcAddress(kernel_base, "SetProcessValidCallTargets") };

			return fp != nullptr;
		}

		bool look_for_win11_base_function()
		{
			//If we only want to be sure that we are on Windows 11, just look for a function in one of the libraries.
			//We use GetMachineTypeAttributes to do this.

			HMODULE kernel_base{ GetModuleHandleW(L"kernelbase.dll") };
			if (kernel_base == nullptr)
			{
				return false;
			}

			auto fp{ GetProcAddress(kernel_base, "GetMachineTypeAttributes") };

			return fp != nullptr;
		}

		bool can_get_full_version()
		{
			auto [ac_81, ac_10] { has_actctx()};

			//We can get the Windows 10 and 11 version
			//numbers in this case.
			if (ac_10 && look_for_win10_base_function())
			{
				return true;
			}

			//This means that we have the Windows 8.1 compatibility
			//setting. We still need to know if this is Windows 8.1, but
			//at the same time, not actually Windows 10.
			if (ac_81 && look_for_win81_base_function() && !look_for_win10_base_function())
			{
				return true;
			}

			//Windows 8 didn't have the restriction that version
			//information was restricted. If we are on an older version
			//of Windows, then this will work.
			if (!look_for_win81_base_function())
			{
				return true;
			}

			return false;
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
		if (details::can_get_full_version())
		{
			return details::get_build_from_version();
		}

		return details::estimate_build_from_exports();
	}

	bool is_at_least_windows_10_build(uint32_t build)
	{
		if (build < 10240)
		{
			return false;
		}

#ifdef __cpp_designated_initializers
		OSVERSIONINFOEXW osv{
			.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW),
			.dwMajorVersion = 10,
			.dwMinorVersion = 0,
			.dwBuildNumber = build
		};
#else
		OSVERSIONINFOEXW osv{
			sizeof(OSVERSIONINFOEXW),
			10,
			0,
			build
		};
#endif

		auto cm{ VerSetConditionMask(VerSetConditionMask(VerSetConditionMask(0, VER_BUILDNUMBER, VER_GREATER_EQUAL), VER_MINORVERSION, VER_EQUAL), VER_MAJORVERSION, VER_EQUAL) };

		return VerifyVersionInfoW(&osv, VER_MAJORVERSION | VER_MINORVERSION | VER_BUILDNUMBER, cm);
	}

	bool is_windows_10_build(uint32_t build)
	{
		if (build < 10240)
		{
			return false;
		}
#ifdef __cpp_designated_initializers
		OSVERSIONINFOEXW osv{
			.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW),
			.dwMajorVersion = 10,
			.dwMinorVersion = 0,
			.dwBuildNumber = build
		};
#else
		OSVERSIONINFOEXW osv{
			sizeof(OSVERSIONINFOEXW),
			10,
			0,
			build
		};
#endif

		auto cm{ VerSetConditionMask(VerSetConditionMask(VerSetConditionMask(0, VER_BUILDNUMBER, VER_EQUAL), VER_MINORVERSION, VER_EQUAL), VER_MAJORVERSION, VER_EQUAL) };

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
}
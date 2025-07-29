#include "windowbase/application_info.hpp"
#include "windowbase/application_helper.hpp"
#include "windowbase/utility.hpp"

#include <functional>
#include <string>

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <appmodel.h>
#include <wil/result.h>
#include <wil/token_helpers.h>

#include <windows.foundation.h>
#include <windows.foundation.collections.h>
#include <windows.applicationmodel.h>
#include <windows.applicationmodel.core.h>

#include "interface_traits.h"
#include "wrl_helpers.h"

namespace window_base::application
{
#if NTDDI_VERSION < NTDDI_WIN10_19H1
	//This function doesn't exist before 19H1 so older Windows 10 SDKs don't have it.
	//We use a dummy function definition so things will compile, but the application,
	//still uses GetProcAddress and will not do anything if the function pointer is null.
	using GetCurrentPackagePath2_t = LONG(int, UINT32 *, PWSTR);
	using GetCurrentPackageInfo2_t = LONG(const UINT32, int, UINT32 *, BYTE *, UINT32 *);
#else
	using GetCurrentPackagePath2_t = decltype(GetCurrentPackagePath2);
	using GetCurrentPackageInfo2_t = decltype(GetCurrentPackageInfo2);
#endif

	std::function<GetCurrentPackagePath2_t> get_gcpp2_ptr()
	{
		using utility::conversion::function_pointer_convert;
#if NTDDI_VERSION < NTDDI_WIN10_19H1
		//This function doesn't exist before 19H1 so older Windows 10 SDKs don't have it.
		//If we build with an older SDK, this function and anything trying to get external
		//content path will just return empty values.
		return {};
#else
		//Current implementations of Windows export this function from KernelBase.dll.
		//Since Kernel32.dll depends on KernelBase.dll, so it should always be loaded.
		//If this somehow fails, then we are in a special place. So we just return nothing.

		HMODULE kb_mod{ GetModuleHandleW(L"KernelBase.dll") };
		if (kb_mod == nullptr)
		{
			return {};
		}

		auto gcpp2_fun_ptr{ function_pointer_convert<GetCurrentPackagePath2_t>(GetProcAddress(kb_mod, "GetCurrentPackagePath2")) };
		if (gcpp2_fun_ptr == nullptr)
		{
			return {};
		}

		std::function<GetCurrentPackagePath2_t> result{ [gcpp2_fun_ptr](auto p1, auto p2, auto p3) { return gcpp2_fun_ptr(p1, p2, p3); } };

		return result;
#endif
	}

	std::function<GetCurrentPackageInfo2_t> get_gcpi2_ptr()
	{
		using utility::conversion::function_pointer_convert;

#if NTDDI_VERSION < NTDDI_WIN10_19H1
		//This function doesn't exist before 19H1 so older Windows 10 SDKs don't have it.
		//If we build with an older SDK, this function and anything trying to get external
		//content path will just return empty values.
		return {};
#else
		//Current implementations of Windows export this function from KernelBase.dll.
		//Since Kernel32.dll depends on KernelBase.dll, so it should always be loaded.
		//If this somehow fails, then we are in a special place. So we just return nothing.

		HMODULE kb_mod{ GetModuleHandleW(L"KernelBase.dll") };
		if (kb_mod == nullptr)
		{
			return {};
		}

		auto gcpi2_fun_ptr{ function_pointer_convert<GetCurrentPackageInfo2_t>(GetProcAddress(kb_mod, "GetCurrentPackageInfo2")) };
		if (gcpi2_fun_ptr == nullptr)
		{
			return {};
		}

		std::function<GetCurrentPackageInfo2_t> result{ [gcpi2_fun_ptr](auto p1, auto p2, auto p3, auto p4, auto p5) {return gcpi2_fun_ptr(p1, p2, p3, p4, p5); } };

		return result;
#endif
	}

	std::unique_ptr<BYTE[]> get_package_id()
	{
		UINT32 buffer_size{};
		std::unique_ptr<BYTE[]> package_id_result;
		auto gcpi_result{ GetCurrentPackageId(&buffer_size, nullptr) };

		if (gcpi_result != APPMODEL_ERROR_NO_PACKAGE)
		{
			if (gcpi_result == ERROR_INSUFFICIENT_BUFFER)
			{
				package_id_result = std::make_unique<BYTE[]>(buffer_size);

				gcpi_result = GetCurrentPackageId(&buffer_size, package_id_result.get());
				FAIL_FAST_IF_WIN32_ERROR(gcpi_result);
			}
			else
			{
				FAIL_FAST_IF_WIN32_ERROR(gcpi_result);
			}
		}

		return package_id_result;
	}

	bool is_application_packaged()
	{
		auto package_id_buffer{ get_package_id() };

		if (package_id_buffer)
		{
			return true;
		}
		return false;
	}

	bool application_has_external_location()
	{
		return false;
	}

	std::filesystem::path application_path()
	{
		std::filesystem::path app_path_result;

		//Using wstring and GetModuleFileNameW internally is fine.
		//m_application_path has the type of std::filesystem::path.
		//VC uses wide characters because the filesystem is UTF-16. This means assigning to it would convert
		//if we used GetModuleFileNameA. Using the UTF-16 version also reduces the chance of mangling things
		//if the locale isn't set properly.
		bool full_path_copied{ false };
		std::wstring app_path = std::wstring(MAX_PATH, L'\0');
		uint32_t path_size{ MAX_PATH };

		while (!full_path_copied)
		{
			auto module_length{ GetModuleFileNameW(nullptr, app_path.data(), path_size) };
			if (module_length == 0)
			{
				FAIL_FAST_WIN32(GetLastError());
			}
			if (module_length < path_size)
			{
				full_path_copied = true;
				app_path.resize(module_length);
			}
			else
			{
				path_size *= 5;
				app_path.resize(path_size);
			}
		}

		app_path_result = app_path;
		app_path_result.remove_filename();

		return app_path_result;
	}

	std::filesystem::path application_package_path()
	{
		if (is_application_packaged())
		{
			UINT32 package_path_length{ 0 };
			auto gcpp_result{ GetCurrentPackagePath(&package_path_length, nullptr) };
			std::filesystem::path package_path;

			if (gcpp_result == ERROR_INSUFFICIENT_BUFFER)
			{
				std::wstring pp(package_path_length, L'\0');

				gcpp_result = GetCurrentPackagePath(&package_path_length, pp.data());

				FAIL_FAST_IF_WIN32_ERROR(gcpp_result);

				package_path = pp;
			}
			else
			{
				FAIL_FAST_IF_WIN32_ERROR(gcpp_result);
			}

			return package_path;
		}

		//Empty path used to indicate that the application has no package path.
		return std::filesystem::path{};
	}

	std::filesystem::path application_external_content_path()
	{
		//Initialize result to an empty value.
		//This is detected as an empty path, which we use
		//to indicate that the external content path isn't
		//set for the package.
		auto result = std::filesystem::path{};
#if NTDDI_VERSION < NTDDI_WIN10_VB
		//Compiling this with a Windows SDK older than 2004
		//should outright default to returning an empty path.
#else
		auto gcpp2_ptr{ get_gcpp2_ptr() };

		if (is_application_packaged())
		{
			if (gcpp2_ptr != nullptr)
			{
				//Since this could run on a version of Windows older than 2004, we need
				//to be sure that attempted package external path detection will only
				//occur on 2004 or newer.
				//We need to do this extra version check because GetCurrentPackagePath2
				//exists in 19H1 too. It was extended for 2004 for the packages with
				//external content.
				if (helper::is_at_least_windows_10_build(19041))
				{
					//PackagePathType_xxxExternal only exists in the 2004
					//and newers SDKs.
					auto package_path_type{ PackagePathType_EffectiveExternal };
					UINT32 package_path_length{ 0 };
					auto gcpp_result{ gcpp2_ptr(package_path_type, &package_path_length, nullptr) };

					if (gcpp_result == ERROR_INSUFFICIENT_BUFFER)
					{
						std::wstring pp(package_path_length, L'\0');

						gcpp_result = gcpp2_ptr(package_path_type, &package_path_length, pp.data());

						FAIL_FAST_IF_WIN32_ERROR(gcpp_result);

						result = std::filesystem::path(pp) / L"";
					}
					else
					{
						if (gcpp_result != ERROR_PATH_NOT_FOUND)
						{
							FAIL_FAST_IF_WIN32_ERROR(gcpp_result);
						}
					}
				}
			}
		}
#endif
		return result;
	}

	std::wstring application_package_full_name()
	{
		std::wstring result{};
		UINT32 full_name_length{};
		auto gcpfn_result{ GetCurrentPackageFullName(&full_name_length, nullptr) };

		if (gcpfn_result == ERROR_INSUFFICIENT_BUFFER)
		{
			result.resize(full_name_length);
			gcpfn_result = GetCurrentPackageFullName(&full_name_length, result.data());

			FAIL_FAST_IF_WIN32_ERROR(gcpfn_result);
		}
		if (gcpfn_result != APPMODEL_ERROR_NO_PACKAGE)
		{
			FAIL_FAST_IF_WIN32_ERROR(gcpfn_result);
		}

		return result;
	}
	
	std::wstring application_package_family_name()
	{
		std::wstring result{};
		UINT32 full_name_length{};
		auto gcpfn_result{ GetCurrentPackageFamilyName(&full_name_length, nullptr) };

		if (gcpfn_result == ERROR_INSUFFICIENT_BUFFER)
		{
			result.resize(full_name_length);
			gcpfn_result = GetCurrentPackageFamilyName(&full_name_length, result.data());

			FAIL_FAST_IF_WIN32_ERROR(gcpfn_result);
		}
		if (gcpfn_result != APPMODEL_ERROR_NO_PACKAGE)
		{
			FAIL_FAST_IF_WIN32_ERROR(gcpfn_result);
		}

		return result;
	}

	bool application_app_container()
	{
		return wil::get_token_is_app_container_failfast();
	}

	std::wstring application_package_app_aumid()
	{
		if (!is_application_packaged())
		{
			return {};
		}

		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::IPackage> current_package;
		auto s{ wrl_helpers::get_activation_factory<ABI::Windows::ApplicationModel::IPackageStatics, ABI::Windows::ApplicationModel::Package>() };
		FAIL_FAST_IF_FAILED(s->get_Current(current_package.ReleaseAndGetAddressOf()));

		auto ip8result{ wrl_helpers::try_as<ABI::Windows::ApplicationModel::IPackage8>(current_package) };
		FAIL_FAST_IF_FAILED(ip8result.second);
		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::IPackage8> current_package8{ ip8result.first };

		Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry *>> applistentries;

		FAIL_FAST_IF_FAILED(current_package8->GetAppListEntries(applistentries.ReleaseAndGetAddressOf()));
		unsigned int applistentries_size{};
		FAIL_FAST_IF_FAILED(applistentries->get_Size(&applistentries_size));
		if (applistentries_size < 1)
		{
			FAIL_FAST();
		}

		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::Core::IAppListEntry> applistentry;
		FAIL_FAST_IF_FAILED(applistentries->GetAt(0, applistentry.ReleaseAndGetAddressOf()));
		auto iale2result{ wrl_helpers::try_as<ABI::Windows::ApplicationModel::Core::IAppListEntry2>(applistentry) };
		FAIL_FAST_IF_FAILED(iale2result.second);
		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::Core::IAppListEntry2> applistentry2{ iale2result.first };

		Microsoft::WRL::Wrappers::HString aumid;
		FAIL_FAST_IF_FAILED(applistentry2->get_AppUserModelId(aumid.ReleaseAndGetAddressOf()));

		unsigned int raw_buffer_length{};
		auto raw_buffer{ aumid.GetRawBuffer(&raw_buffer_length) };

		std::wstring aumid_result{ raw_buffer };

		return aumid_result;
	}

	std::wstring application_package_app_aumid(uint32_t app)
	{
		if (!is_application_packaged())
		{
			return {};
		}

		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::IPackage> current_package;
		auto s = wrl_helpers::get_activation_factory<ABI::Windows::ApplicationModel::IPackageStatics, ABI::Windows::ApplicationModel::Package>();
		FAIL_FAST_IF_FAILED(s->get_Current(current_package.ReleaseAndGetAddressOf()));

		auto ip8result = wrl_helpers::try_as<ABI::Windows::ApplicationModel::IPackage8>(current_package);
		FAIL_FAST_IF_FAILED(ip8result.second);
		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::IPackage8> current_package8{ ip8result.first };

		Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry *>> applistentries;

		FAIL_FAST_IF_FAILED(current_package8->GetAppListEntries(applistentries.ReleaseAndGetAddressOf()));
		unsigned int applistentries_size{};
		FAIL_FAST_IF_FAILED(applistentries->get_Size(&applistentries_size));
		if (applistentries_size < app)
		{
			FAIL_FAST();
		}

		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::Core::IAppListEntry> applistentry;
		FAIL_FAST_IF_FAILED(applistentries->GetAt(app, applistentry.ReleaseAndGetAddressOf()));
		auto iale2result = wrl_helpers::try_as<ABI::Windows::ApplicationModel::Core::IAppListEntry2>(applistentry);
		FAIL_FAST_IF_FAILED(iale2result.second);
		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::Core::IAppListEntry2> applistentry2{ iale2result.first };

		Microsoft::WRL::Wrappers::HString aumid;
		FAIL_FAST_IF_FAILED(applistentry2->get_AppUserModelId(aumid.ReleaseAndGetAddressOf()));

		unsigned int raw_buffer_length{};
		auto raw_buffer{ aumid.GetRawBuffer(&raw_buffer_length) };

		std::wstring aumid_result{ raw_buffer };

		return aumid_result;
	}

	uint32_t application_package_get_applist_count()
	{
		if (!is_application_packaged())
		{
			return 0;
		}

		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::IPackage> current_package;
		auto s = wrl_helpers::get_activation_factory<ABI::Windows::ApplicationModel::IPackageStatics, ABI::Windows::ApplicationModel::Package>();
		FAIL_FAST_IF_FAILED(s->get_Current(current_package.ReleaseAndGetAddressOf()));

		auto ip8result = wrl_helpers::try_as<ABI::Windows::ApplicationModel::IPackage8>(current_package);
		FAIL_FAST_IF_FAILED(ip8result.second);
		Microsoft::WRL::ComPtr<ABI::Windows::ApplicationModel::IPackage8> current_package8{ ip8result.first };

		Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry *>> applistentries;

		FAIL_FAST_IF_FAILED(current_package8->GetAppListEntries(applistentries.ReleaseAndGetAddressOf()));
		unsigned int applistentries_size{};
		FAIL_FAST_IF_FAILED(applistentries->get_Size(&applistentries_size));

		return applistentries_size;
	}
}
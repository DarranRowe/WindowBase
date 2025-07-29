#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <filesystem>
#include <string>
#include <cstdint>

namespace window_base::application
{
	bool is_application_packaged();
	bool application_has_external_location();

	std::filesystem::path application_path();
	std::filesystem::path application_package_path();
	std::filesystem::path application_external_content_path();

	std::wstring application_package_full_name();
	std::wstring application_package_family_name();
	bool application_app_container();

	std::wstring application_package_app_aumid();
	std::wstring application_package_app_aumid(uint32_t);
	uint32_t application_package_get_applist_count();
}
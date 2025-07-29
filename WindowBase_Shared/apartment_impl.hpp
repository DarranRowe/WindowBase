#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <combaseapi.h>
#include <roapi.h>

#include <vector>
#include <mutex>

namespace window_base::application::details
{
	enum class com_type
	{
		uninit,
		com,
		winrt,
		ole
	};

	struct apartment_impl
	{
		void init_com(COINIT init_type);
		void init_winrt(RO_INIT_TYPE init_type);
		void init_ole();

		void uninit_apartment();

		void increment_mta_count();
		void decrement_mta_count();
		uint32_t get_mta_cookie_count() const;
		HRESULT failure_code() const;
		bool is_winrt_apartment() const;
		bool is_ole_apartment() const;

		//Don't store the apartment threading type,
		//it isn't really needed for uninitialisation
		com_type m_com_type{};
		
		std::mutex m_mta_cookies_lock{};
		std::vector<CO_MTA_USAGE_COOKIE> m_mta_cookies;
		HRESULT m_failure_code{ S_OK };
	};
}
#include "apartment_impl.hpp"
#include "windowbase/utility.hpp"
#include "windowbase/output_helpers.hpp"

#pragma comment (lib, "WindowsApp.lib")

namespace window_base::application::details
{
	using utility::conversion::value_convert;
	void apartment_impl::init_com(COINIT init_type)
	{
		HRESULT hr{ CoInitializeEx(nullptr, init_type) };
		if (SUCCEEDED(hr))
		{
			m_com_type = com_type::com;
		}
		else
		{
			output_helpers::debug::format_debugwriteln(L"CoInitializeEx failed: {}.", hr);
			m_failure_code = hr;
		}
	}

	void apartment_impl::init_winrt(RO_INIT_TYPE init_type)
	{
		HRESULT hr{ RoInitialize(init_type) };
		if (SUCCEEDED(hr))
		{
			m_com_type = com_type::winrt;
		}
		else
		{
			output_helpers::debug::format_debugwriteln(L"RoInitialize failed: {}.", hr);
			m_failure_code = hr;
		}
	}

	void apartment_impl::init_ole()
	{
		//OLE only has sta.
		HRESULT hr{ OleInitialize(nullptr) };
		if (SUCCEEDED(hr))
		{
			m_com_type = com_type::ole;
		}
		else
		{
			output_helpers::debug::format_debugwriteln(L"OleInitialize failed: {}.", hr);
			m_failure_code = hr;
		}
	}

	void apartment_impl::uninit_apartment()
	{
		switch (m_com_type)
		{
		case com_type::com:
		{
			CoUninitialize();
			m_com_type = com_type::uninit;
			break;
		}
		case com_type::winrt:
		{
			RoUninitialize();
			m_com_type = com_type::uninit;
			break;
		}
		case com_type::ole:
		{
			OleUninitialize();
			m_com_type = com_type::uninit;
			break;
		}
		}
	}

	void apartment_impl::increment_mta_count()
	{
		CO_MTA_USAGE_COOKIE usage_cookie{};

		HRESULT hr{ CoIncrementMTAUsage(&usage_cookie) };

		if(SUCCEEDED(hr))
		{
			std::scoped_lock lock(m_mta_cookies_lock);
			m_mta_cookies.emplace_back(usage_cookie);
		}
		else
		{
			output_helpers::debug::format_debugwriteln(L"CoIncrementMTAUsage failed: {}.", hr);
		}
	}

	void apartment_impl::decrement_mta_count()
	{
		CO_MTA_USAGE_COOKIE usage_cookie{};

		{
			std::scoped_lock lock(m_mta_cookies_lock);
			auto vsize{ m_mta_cookies.size() };
			usage_cookie = m_mta_cookies.at(vsize - 1);
			m_mta_cookies.resize(vsize - 1);
		}

		CoDecrementMTAUsage(usage_cookie);
	}

	uint32_t apartment_impl::get_mta_cookie_count() const
	{
		return value_convert<uint32_t>(m_mta_cookies.size());
	}

	HRESULT apartment_impl::failure_code() const
	{
		return m_failure_code;
	}

	bool apartment_impl::is_winrt_apartment() const
	{
		return m_com_type == com_type::winrt;
	}

	bool apartment_impl::is_ole_apartment() const
	{
		return m_com_type == com_type::ole;
	}
}
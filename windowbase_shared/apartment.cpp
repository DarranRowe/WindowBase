#include "apartment_impl.hpp"
#include "apartment.hpp"
#include "application_helper.hpp"

namespace application
{
	std::pair<APTTYPE, APTTYPEQUALIFIER> query_apt_type()
	{
		APTTYPE apt_type{};
		APTTYPEQUALIFIER apt_type_qual{};
		HRESULT hr = S_OK;

		hr = CoGetApartmentType(&apt_type, &apt_type_qual);

		if (hr == CO_E_NOTINITIALIZED)
		{
			return std::make_pair(APTTYPE_CURRENT, APTTYPEQUALIFIER_NONE);
		}

		if (FAILED(hr))
		{
			helper::writeln_debugger(L"CoGetApartmentType failed: {}.", hr);
		}
		_ASSERTE(SUCCEEDED(hr));

		return std::make_pair(apt_type, apt_type_qual);
	}

	apartment::apartment(com_t) noexcept
	{
		try
		{
			m_impl = std::make_unique<details::apartment_impl>();

			m_impl->init_com(COINIT_APARTMENTTHREADED);
		}
		catch (...)
		{
			//We don't do anything more than have a path for an exception to be eaten here.
			//Since the only real exception we can get here is a failed memory allocation,
			//we can detect this by having the smart pointer stay null.
		}
	}

	apartment::apartment(com_t, mta_t) noexcept
	{
		try
		{
			m_impl = std::make_unique<details::apartment_impl>();

			m_impl->init_com(COINIT_MULTITHREADED);
		}
		catch (...)
		{
			//We don't do anything more than have a path for an exception to be eaten here.
			//Since the only real exception we can get here is a failed memory allocation,
			//we can detect this by having the smart pointer stay null.
		}
	}

	apartment::apartment(winrt_t) noexcept
	{
		try
		{
			m_impl = std::make_unique<details::apartment_impl>();

			m_impl->init_winrt(RO_INIT_SINGLETHREADED);
		}
		catch (...)
		{
			//We don't do anything more than have a path for an exception to be eaten here.
			//Since the only real exception we can get here is a failed memory allocation,
			//we can detect this by having the smart pointer stay null.
		}
	}

	apartment::apartment(winrt_t, mta_t) noexcept
	{
		try
		{
			m_impl = std::make_unique<details::apartment_impl>();

			m_impl->init_winrt(RO_INIT_MULTITHREADED);
		}
		catch (...)
		{
			//We don't do anything more than have a path for an exception to be eaten here.
			//Since the only real exception we can get here is a failed memory allocation,
			//we can detect this by having the smart pointer stay null.
		}
	}

	apartment::apartment(ole_t) noexcept
	{
		try
		{
			m_impl = std::make_unique<details::apartment_impl>();

			m_impl->init_ole();
		}
		catch (...)
		{
			//We don't do anything more than have a path for an exception to be eaten here.
			//Since the only real exception we can get here is a failed memory allocation,
			//we can detect this by having the smart pointer stay null.
		}
	}

	apartment::~apartment() noexcept
	{
		if (m_impl)
		{
			m_impl->uninit_apartment();
		}
	}

	void apartment::increment_implicit_mta()
	{
		m_impl->increment_mta_count();
	}

	void apartment::decrement_implicit_mta()
	{
		m_impl->decrement_mta_count();
	}

	uint32_t apartment::outstanding_mta_count() const
	{
		return m_impl->get_mta_cookie_count();
	}

	uint32_t apartment::init_failure_code() const
	{
		if (!m_impl)
		{
			return static_cast<uint32_t>(E_FAIL);
		}
		return m_impl->failure_code();
	}

	bool apartment::is_aparmtent_init()
	{
		auto result = query_apt_type();

		if (result.first == APTTYPE_CURRENT || result.second == APTTYPEQUALIFIER_IMPLICIT_MTA || result.second == APTTYPEQUALIFIER_NA_ON_IMPLICIT_MTA)
		{
			return false;
		}

		return true;
	}

	bool apartment::is_sta_apartment()
	{
		auto result = query_apt_type();

		if (result.first == APTTYPE_STA || result.first == APTTYPE_MAINSTA)
		{
			return true;
		}

		return false;
	}

	bool apartment::is_nta_apartment()
	{
		auto result = query_apt_type();

		if (result.first == APTTYPE_NA)
		{
			return true;
		}

		return false;
	}

	bool apartment::is_implicit_mta()
	{
		auto result = query_apt_type();

		if (result.second == APTTYPEQUALIFIER_IMPLICIT_MTA || result.second == APTTYPEQUALIFIER_NA_ON_IMPLICIT_MTA)
		{
			return true;
		}

		return false;
	}

	bool apartment::is_winrt_apartment() const
	{
		return m_impl->is_winrt_apartment();
	}

	bool apartment::is_ole_apartment() const
	{
		return m_impl->is_ole_apartment();
	}
}
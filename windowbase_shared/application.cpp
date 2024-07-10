#include "application.hpp"
#include "application_thread.hpp"
#include "application_impl.hpp"
#include "debug_helper.hpp"

namespace application
{
	application::application() noexcept
	{
#ifdef _DEBUG
		auto impl =
#endif
		details::application_impl::make_new_instance();

#ifdef _DEBUG
		_ASSERTE(impl != nullptr);
#endif
	}

	application::~application() noexcept
	{
		details::application_impl::release_impl();
	}

	application::application(current_inst_t) noexcept
	{
		//This is to construct for try_get_current_instance.
		//This really does nothing, because if the implementation
		//exists, unsafe_get_current_instance increments the reference
		//count.
	}

	application::application(const application &) noexcept
	{
#ifdef _DEBUG
		auto impl = details::application_impl::get_current_instance();
		_ASSERTE(impl != nullptr);
#endif

		details::application_impl::add_ref_impl();
	}

	application::application(application &&) noexcept
	{
	}

	application &application::operator=(const application &right) noexcept
	{
		if (&right == this)
		{
			return *this;
		}

#ifdef _DEBUG
		auto impl = details::application_impl::get_current_instance();
		_ASSERTE(impl != nullptr);
#endif

		details::application_impl::add_ref_impl();

		return *this;
	}

	application &application::operator=(application &&) noexcept
	{
		return *this;
	}

	std::optional<application> application::try_get_current_instance()
	{
		auto current_impl = details::application_impl::unsafe_get_current_instance();

		if (current_impl == nullptr)
		{
			return std::nullopt;
		}

		return application::application(current_inst_t{});
	}

	void application::make_thread_gui()
	{
		details::application_impl::convert_thread_to_ui_thread();
	}

	void application::set_explicit_app_user_model_id(const std::wstring_view &aumid)
	{
		details::application_impl::set_aumid(aumid);
	}

	std::wstring application::get_explicit_app_user_model_id()
	{
		auto aumid = details::application_impl::get_aumid();
		_ASSERTE(aumid != std::nullopt);
		if (!aumid.has_value())
		{
			debug::format_write_to_debugger(L"No explicit AUMID set for the current process.\r\n");
		}

		return aumid.value_or(L"###Invalid AUMID###");
	}

	bool application::process_has_explicit_app_user_model_id()
	{
		auto aumid = details::application_impl::get_aumid();
		return aumid.has_value();
	}

	uint32_t application::get_application_thread_id() const
	{
		auto impl = details::application_impl::get_current_instance();

		return impl->get_main_thread_id();
	}

	application_thread application::get_for_thread() const
	{
		return application_thread{};
	}

	bool application::is_main_thread() const
	{
		auto impl = details::application_impl::get_current_instance();

		return impl->is_current_thread_main_thread();
	}

	bool application::is_ui_thread(uint32_t tid) const
	{
		return details::application_impl::is_thread_ui_thread(tid);
	}

	bool application::did_initialisation_fail() const
	{
		auto impl = details::application_impl::get_current_instance();

		if (impl == nullptr)
		{
			return true;
		}

		return impl->did_initialisation_fail();
	}

	init_failure_information application::get_failure_information() const
	{
		auto impl = details::application_impl::get_current_instance();

		if (impl == nullptr)
		{
			return init_failure_information{-1, "application_impl.cpp", "make_new_instance", 43};
		}

		return impl->get_failure_information();
	}
}
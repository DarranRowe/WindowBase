#include "windowbase/application_singleton.hpp"
#include "windowbase/application_thread.hpp"
#include "application_impl.hpp"
#include "windowbase/output_helpers.hpp"

namespace window_base::application
{
	application_singleton::application_singleton() noexcept
	{
		MAKEINST_ASSERT;
	}

	application_singleton::~application_singleton() noexcept
	{
		details::application_impl::release_impl();
	}

	application_singleton::application_singleton(current_inst_t) noexcept
	{
		//This is to construct for try_get_current_instance.
		//This really does nothing, because if the implementation
		//exists, unsafe_get_current_instance increments the reference
		//count.
	}

	application_singleton::application_singleton(const application_singleton &) noexcept
	{
		CHECKIMPL_ASSERT;
		details::application_impl::add_ref_impl();
	}

	application_singleton::application_singleton(application_singleton &&) noexcept
	{

		CHECKIMPL_ASSERT;
		details::application_impl::add_ref_impl();
	}

	application_singleton &application_singleton::operator=(const application_singleton &) noexcept
	{
		return *this;
	}

	application_singleton &application_singleton::operator=(application_singleton &&) noexcept
	{
		return *this;
	}

	std::optional<application_singleton> application_singleton::try_get_current_instance()
	{
		auto current_impl{ details::application_impl::unsafe_get_current_instance() };

		if (current_impl == nullptr)
		{
			return std::nullopt;
		}

		return application_singleton::application_singleton(current_inst_t{});
	}

	void application_singleton::make_thread_gui() noexcept
	{
		details::application_impl::convert_thread_to_ui_thread();
	}

	void application_singleton::set_explicit_app_user_model_id(const std::wstring_view &aumid) noexcept
	{
		details::application_impl::set_aumid(aumid);
	}

	std::wstring application_singleton::get_explicit_app_user_model_id() noexcept
	{
		auto aumid{ details::application_impl::get_aumid() };
		_ASSERTE(aumid != std::nullopt);
		if (!aumid.has_value())
		{
			output_helpers::debug::format_debugwriteln(L"No explicit AUMID set for the current process.");
		}

		return aumid.value_or(L"###Invalid AUMID###");
	}

	bool application_singleton::process_has_explicit_app_user_model_id() noexcept
	{
		auto aumid{ details::application_impl::get_aumid() };
		return aumid.has_value();
	}

	void application_singleton::enable_mouse_in_pointer() noexcept
	{
		details::application_impl::enable_mouse_in_pointer();
	}

	bool application_singleton::is_mouse_in_pointer_enabled() noexcept
	{
		return details::application_impl::is_mouse_in_pointer_enabled();
	}

	dpi_awareness application_singleton::get_dpi_awareness() noexcept
	{
		return details::application_impl::get_process_dpi_awareness();
	}

	void application_singleton::post_exit_message_to_thread(uint32_t tid, int32_t exit_code)
	{
		using utility::conversion::value_convert;
		PostThreadMessageW(tid, WM_QUIT, value_convert<WPARAM>(exit_code), 0);
	}

	uint32_t application_singleton::get_application_thread_id() const
	{
		auto impl{ details::application_impl::get_current_instance() };

		return impl->get_main_thread_id();
	}

	application_thread application_singleton::get_for_thread() const
	{
		return application_thread{};
	}

	bool application_singleton::is_main_thread() const
	{
		auto impl{ details::application_impl::get_current_instance() };

		return impl->is_current_thread_main_thread();
	}

	bool application_singleton::is_ui_thread(uint32_t tid) const
	{
		return details::application_impl::is_thread_ui_thread(tid);
	}

	bool application_singleton::did_initialisation_fail() const
	{
		auto impl{ details::application_impl::get_current_instance() };

		if (impl == nullptr)
		{
			return true;
		}

		return impl->did_initialisation_fail();
	}

	init_failure_information application_singleton::get_failure_information() const
	{
		auto impl{ details::application_impl::get_current_instance() };

		if (impl == nullptr)
		{
			return init_failure_information{-1, "application_impl.cpp", "make_new_instance", 43};
		}

		return impl->get_failure_information();
	}
}
#include "windowbase/application_thread.hpp"
#include "application_impl.hpp"

namespace window_base::application
{
	application_thread::application_thread() noexcept : m_tid(details::application_impl::get_current_thread_id())
	{
		using details::application_impl;
		auto impl{ application_impl::get_current_instance() };
		_ASSERTE(impl != nullptr);

		//While we do check and assert, this should only ever be constructed
		//from a valid application. This is why we can blindly add_ref here.
		application_impl::add_ref_impl();

		impl->init_data_for_thread(m_tid);

		application_impl::convert_thread_to_ui_thread();
	}

	application_thread::~application_thread() noexcept
	{
		using details::application_impl;
		auto impl{ application_impl::get_current_instance() };

		impl->remove_data_for_thread(m_tid);

		application_impl::release_impl();
	}

	application_thread::application_thread(const application_thread &) noexcept
	{
		using details::application_impl;
		CHECKIMPL_ASSERT;

		application_impl::add_ref_impl();
	}

	application_thread::application_thread(application_thread &&) noexcept
	{
		using details::application_impl;
		//This is needed in the move constructor since we are working on our own data.
		//This constructor is paired with a destructor, so we must increase our ref count.
		CHECKIMPL_ASSERT;

		application_impl::add_ref_impl();
	}

	application_thread &application_thread::operator=(const application_thread &) noexcept
	{
		return *this;
	}

	application_thread &application_thread::operator=(application_thread &&) noexcept
	{
		return *this;
	}

	uint32_t application_thread::get_thread_id() const
	{
		return m_tid;
	}

	bool application_thread::is_current_thread() const
	{
		auto current_tid{GetCurrentThreadId()};

		return (current_tid == m_tid);
	}

	dpi_awareness application_thread::set_dpi_awareness(dpi_awareness awareness) noexcept
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };
		return inst->set_thread_dpi_awareness(awareness);
	}

	dpi_awareness application_thread::get_dpi_awareness() noexcept
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };
		return inst->get_thread_dpi_awareness();
	}

	dpi_hosting_behaviour application_thread::set_dpi_hosting_behaviour(dpi_hosting_behaviour hosting) noexcept
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };
		return inst->set_thread_dpi_hosting_behaviour(hosting);
	}

	dpi_hosting_behaviour application_thread::get_dpi_hosting_behaviour() noexcept
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };
		return inst->get_thread_dpi_hosting_behaviour();
	}

	uint32_t application_thread::set_cursor_creation_scaling(uint32_t dpi) noexcept
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };
		return inst->set_thread_cursor_creation_scaling(dpi);
	}

	void application_thread::set_message_pump_to_ansi()
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		inst->set_message_pump_to_ansi(true, m_tid);
	}

	void application_thread::set_message_pump_to_unicode()
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		inst->set_message_pump_to_ansi(false, m_tid);
	}

	bool application_thread::is_message_pump_ansi() const
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		return inst->is_message_pump_ansi(m_tid);
	}

	bool application_thread::is_message_pump_unicode() const
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		return (!inst->is_message_pump_ansi(m_tid));
	}

	int application_thread::run_message_pump() const
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		return inst->is_message_pump_ansi(m_tid) ? inst->run_ansi_message_pump(m_tid) : inst->run_unicode_message_pump(m_tid);
	}

	int application_thread::run_game_message_pump() const
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		return inst->is_message_pump_ansi(m_tid) ? inst->run_ansi_game_message_pump(m_tid) : inst->run_unicode_game_message_pump(m_tid);
	}

	void application_thread::exit_message_pump(int exit_code) const
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		inst->send_pump_exit_for_thread(m_tid, exit_code);
	}

	void application_thread::clear_message_queue() const
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		inst->is_message_pump_ansi(m_tid) ? inst->clear_ansi_message_queue(m_tid) : inst->clear_unicode_message_queue(m_tid);
	}

	uint32_t application_thread::add_pump_callback(pump_callback_wrapper callback)
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		return inst->add_callback(callback, 0, m_tid);
	}

	void application_thread::clear_pump_callbacks()
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		inst->clear_callbacks(m_tid);
	}

	void application_thread::remove_pump_callback(uint32_t cookie)
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		inst->remove_callback(cookie, m_tid);
	}

	void application_thread::add_pump_work_callback(work_callback_wrapper callback)
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		inst->add_work_callback(callback, m_tid);
	}

	void application_thread::remove_pump_work_callback()
	{
		using details::application_impl;
		auto inst{ application_impl::get_current_instance() };

		inst->remove_work_callback(m_tid);
	}
}
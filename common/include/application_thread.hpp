#pragma once

#include "application_defs.hpp"

namespace application
{
	class application;
	//Public API
	//Modification of this class requires adding the functions to the export list.
	class application_thread
	{
	public:
		~application_thread() noexcept;
		application_thread(const application_thread &) noexcept;
		application_thread(application_thread &&) noexcept;
		application_thread &operator=(const application_thread &) noexcept;
		application_thread &operator=(application_thread &&) noexcept;

		void set_message_pump_to_ansi();
		void set_message_pump_to_unicode();
		bool is_message_pump_ansi() const;
		bool is_message_pump_unicode() const;
		int run_message_pump() const;
		int run_game_message_pump() const;
		void clear_message_queue() const;
		void exit_message_pump(int) const;

		uint32_t add_pump_simple_callback(pump_callback_wrapper);
		uint32_t add_pump_window_callback(HWND, uint32_t);
		void clear_pump_callbacks();
		void remove_pump_callback(uint32_t);
		void add_pump_work_callback(work_callback_wrapper);
		void remove_pump_work_callback();
		
	private:
		//Not directly constructable, can only be obtained through application::get_for_thread.
		friend class application;
		application_thread() noexcept;
		uint32_t m_tid{};
	};
}
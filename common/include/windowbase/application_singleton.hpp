#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <optional>
#include <cstdint>
#include <string>

#include "application_thread.hpp"

namespace window_base::application
{
	struct current_inst_t {};

	struct init_failure_information
	{
		int32_t error_code;
		std::string file;
		std::string function;
		uint32_t line_number;
	};

	//Public API
	//Modification of this class requires adding the functions to the export list.
	class application_singleton
	{
	public:
		application_singleton() noexcept;
		~application_singleton() noexcept;

		application_singleton(const application_singleton &) noexcept;
		application_singleton(application_singleton &&) noexcept;
		application_singleton &operator=(const application_singleton &) noexcept;
		application_singleton &operator=(application_singleton &&) noexcept;

		static void post_exit_message_to_thread(uint32_t, int32_t);

		static std::optional<application_singleton> try_get_current_instance();
		static void make_thread_gui() noexcept;

		static void set_explicit_app_user_model_id(const std::wstring_view &) noexcept;
		static std::wstring get_explicit_app_user_model_id() noexcept;
		static bool process_has_explicit_app_user_model_id() noexcept;

		//This has no disable. The documentation states that this
		//can only be called once in a process.
		static void enable_mouse_in_pointer() noexcept;
		static bool is_mouse_in_pointer_enabled() noexcept;

		//There is no set equivalent.
		//This really should be set in the manifest.
		dpi_awareness get_dpi_awareness() noexcept;

		uint32_t get_application_thread_id() const;

		application_thread get_for_thread() const;

		bool is_main_thread() const;
		bool is_ui_thread(uint32_t) const;

		bool did_initialisation_fail() const;
		init_failure_information get_failure_information() const;

	private:
		application_singleton(current_inst_t) noexcept;
	};
}
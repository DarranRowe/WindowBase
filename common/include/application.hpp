#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <optional>

#include "application_error.hpp"
#include "application_thread.hpp"

namespace application
{
	struct current_inst_t {};

	//Public API
	//Modification of this class requires adding the functions to the export list.
	class application
	{
	public:
		application() noexcept;
		~application() noexcept;

		application(const application &) noexcept;
		application(application &&) noexcept;
		application &operator=(const application &) noexcept;
		application &operator=(application &&) noexcept;

		static std::optional<application> try_get_current_instance();
		static void make_thread_gui();

		static void set_explicit_app_user_model_id(const std::wstring_view &);
		static std::wstring get_explicit_app_user_model_id();
		static bool process_has_explicit_app_user_model_id();

		uint32_t get_application_thread_id() const;

		application_thread get_for_thread() const;

		bool is_main_thread() const;
		bool is_ui_thread(uint32_t) const;

		bool did_initialisation_fail() const;
		init_failure_information get_failure_information() const;

	private:
		application(current_inst_t) noexcept;
	};
}
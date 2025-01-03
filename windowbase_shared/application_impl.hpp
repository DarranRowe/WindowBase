#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <cinttypes>
#include <cstdint>
#include <filesystem>
#include <functional>
#include <map>
#include <mutex>
#include <shared_mutex>

#include "application.hpp"
#include "application_error.hpp"

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <appmodel.h>
#include <combaseapi.h>
#include <wrl.h>

#include <wil/result_originate.h>

#include "window_base.hpp"

namespace application
{
	class application;
}

namespace application::details
{
	using message_process_callback_ptr = message_process_callback *;
	using work_process_callback_ptr = work_process_callback *;

	struct callback_information
	{
		pump_callback_wrapper callback_wrapper;
		HWND window_handle{};
		uint32_t callback_identifier{};
	};

	struct thread_pump_information
	{
		bool in_message_pump{ false };
		bool is_pump_ansi{ false };
		std::atomic_uint32_t thread_refs{ 1 };

		std::shared_mutex callback_mutex{};
		uint32_t callback_cookie{};
		std::map<uint32_t, std::unique_ptr<callback_information>> callback_info{};
		std::unique_ptr<work_callback_wrapper> callback_work_information{};
	};

	struct thread_data_map
	{
		std::shared_mutex lookup_mutex{};
		std::map<uint32_t, std::unique_ptr<thread_pump_information>> lookup_map{};
	};

	struct application_impl
	{
		//Must be created on the heap using new.
		//release will call delete this.
		application_impl() noexcept;
		~application_impl() noexcept;

		application_impl(const application_impl &) = delete;
		application_impl(application_impl &&) = delete;
		application_impl &operator=(const application_impl &) = delete;
		application_impl &operator=(application_impl &&) = delete;

		//Impl is self reference counted.
		//This has a couple of implications.
		void add_ref() noexcept;
		bool release() noexcept;

		//Most of these don't need to be instance members.
		static bool is_thread_ui_thread(uint32_t) noexcept;
		static bool is_thread_in_message_pump(uint32_t) noexcept;

		static void set_aumid(const std::wstring_view &) noexcept;
		static std::optional<std::wstring> get_aumid() noexcept;

		void send_pump_exit_for_thread(uint32_t, int) noexcept;

		uint32_t get_main_thread_id() const noexcept;
		bool is_current_thread_main_thread() const noexcept;
		uint32_t add_callback(pump_callback_wrapper, HWND, uint32_t, uint32_t);
		void clear_callbacks(uint32_t);
		void remove_callback(uint32_t, uint32_t);
		void add_work_callback(work_callback_wrapper, uint32_t);
		void remove_work_callback(uint32_t);

		void set_message_pump_to_ansi(bool, uint32_t);
		bool is_message_pump_ansi(uint32_t);
		int run_ansi_message_pump(uint32_t);
		int run_unicode_message_pump(uint32_t);
		int run_ansi_game_message_pump(uint32_t);
		int run_unicode_game_message_pump(uint32_t);
		void clear_ansi_message_queue(uint32_t);
		void clear_unicode_message_queue(uint32_t);

		bool did_initialisation_fail() const;
		init_failure_information get_failure_information() const;

		static application_impl *get_current_instance() noexcept;
		static application_impl *unsafe_get_current_instance() noexcept;
		static application_impl *make_new_instance() noexcept;
		static void add_ref_impl() noexcept;
		static void release_impl() noexcept;

		init_failure_information m_failure_info{};

		//This is the id of the thread that the application
		//instance was created on.
		inline static uint32_t m_application_thread_id{};

		static bool convert_thread_to_ui_thread();

		static thread_data_map &get_data_map();
		static void init_data_for_thread(uint32_t);
		static void remove_data_for_thread(uint32_t);
		static thread_pump_information &get_pump_info_for_thread(uint32_t);

		static uint32_t get_current_thread_id() noexcept;
		static bool post_quit_message_for_thread(uint32_t, int) noexcept;

		std::atomic_uint32_t m_refs{1};
	};
}
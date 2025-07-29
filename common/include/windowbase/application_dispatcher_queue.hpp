#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <cinttypes>
#include <cstdint>

namespace window_base::application
{
	class application_system_dispatcher_queue
	{
	public:
		application_system_dispatcher_queue() noexcept;
		application_system_dispatcher_queue(const application_system_dispatcher_queue &) noexcept;
		application_system_dispatcher_queue(application_system_dispatcher_queue &&) noexcept;
		~application_system_dispatcher_queue() noexcept;

		application_system_dispatcher_queue &operator=(const application_system_dispatcher_queue &) = delete;
		application_system_dispatcher_queue &operator=(application_system_dispatcher_queue &&) = delete;

		bool thread_has_dispatcher_queue() const noexcept;
		bool thread_has_uncontrolled_dispatcher_queue() const noexcept;

		bool create_dispatcher_queue_on_thread() noexcept;
		int32_t create_background_dispatcher_queue() noexcept;
		void destroy_thread_dispatcher_queue() noexcept;
		void destroy_background_dispatcher_queue(int32_t) noexcept;
	};

	class application_winappsdk_dispatcher_queue
	{
	public:
		application_winappsdk_dispatcher_queue() noexcept;
		application_winappsdk_dispatcher_queue(const application_winappsdk_dispatcher_queue &) noexcept;
		application_winappsdk_dispatcher_queue(application_winappsdk_dispatcher_queue &&) noexcept;
		~application_winappsdk_dispatcher_queue() noexcept;

		application_winappsdk_dispatcher_queue &operator=(const application_winappsdk_dispatcher_queue &) = delete;
		application_winappsdk_dispatcher_queue &operator=(application_winappsdk_dispatcher_queue &&) = delete;

		static bool dispatcher_queue_available() noexcept;

		bool thread_has_dispatcher_queue() const noexcept;
		bool thread_has_uncontrolled_dispatcher_queue() const noexcept;

		bool create_dispatcher_queue_on_thread() noexcept;
		int32_t create_background_dispatcher_queue() noexcept;
		void destroy_thread_dispatcher_queue() noexcept;
		void destroy_background_dispatcher_queue(int32_t) noexcept;
	};
}
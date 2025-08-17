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

#include "windowbase/application_singleton.hpp"

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <appmodel.h>
#include <combaseapi.h>
#include <wrl.h>

#include <wil/result_originate.h>

#include "windowbase/window_base.hpp"

#ifdef _DEBUG
#define MAKEINST_ASSERT auto impl{details::application_impl::make_new_instance()};\
_ASSERTE(impl!=nullptr)
#define CHECKIMPL_ASSERT auto impl{ details::application_impl::get_current_instance() };\
_ASSERTE(impl != nullptr)
#else
#define MAKEINST_ASSERT details::application_impl::make_new_instance()
#define CHECKIMPL_ASSERT
#endif

namespace window_base
{
	namespace application
	{
		class application_singleton;
	}

	namespace application::details
	{
		using message_process_callback_ptr = message_process_callback *;
		using work_process_callback_ptr = work_process_callback *;

		struct callback_information
		{
			pump_callback_wrapper callback_wrapper;
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

		template <bool Unicode = false>
		struct run_pump_traits
		{
			static BOOL WndGetMessage(MSG *msg, HWND wnd, UINT filter_min, UINT filter_max)
			{
				return GetMessageA(msg, wnd, filter_min, filter_max);
			}

			static LRESULT WndDispatchMessage(MSG *msg)
			{
				return DispatchMessageA(msg);
			}

			static BOOL WndPeekMessage(MSG *msg, HWND wnd, UINT filter_min, UINT filter_max, UINT remove)
			{
				return PeekMessageA(msg, wnd, filter_min, filter_max, remove);
			}
		};

		template <>
		struct run_pump_traits<true>
		{
			static BOOL WndGetMessage(MSG *msg, HWND wnd, UINT filter_min, UINT filter_max)
			{
				return GetMessageW(msg, wnd, filter_min, filter_max);
			}

			static LRESULT WndDispatchMessage(MSG *msg)
			{
				return DispatchMessageW(msg);
			}

			static BOOL WndPeekMessage(MSG *msg, HWND wnd, UINT filter_min, UINT filter_max, UINT remove)
			{
				return PeekMessageW(msg, wnd, filter_min, filter_max, remove);
			}
		};

		inline dpi_awareness awareness_ctx_to_awareness(DPI_AWARENESS_CONTEXT ctx)
		{
			dpi_awareness result{};

			if (AreDpiAwarenessContextsEqual(ctx, DPI_AWARENESS_CONTEXT_UNAWARE) != FALSE)
			{
				result = dpi_awareness::unaware;
			}
			if (AreDpiAwarenessContextsEqual(ctx, DPI_AWARENESS_CONTEXT_SYSTEM_AWARE) != FALSE)
			{
				result = dpi_awareness::system;
			}
			if (AreDpiAwarenessContextsEqual(ctx, DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE) != FALSE)
			{
				result = dpi_awareness::per_monitor;
			}
			if (AreDpiAwarenessContextsEqual(ctx, DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2) != FALSE)
			{
				result = dpi_awareness::per_monitor_v2;
			}
			if (AreDpiAwarenessContextsEqual(ctx, DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED) != FALSE)
			{
				result = dpi_awareness::unaware_scaled;
			}
			_ASSERTE(result != dpi_awareness::unknown);
			return result;
		}

		inline DPI_AWARENESS_CONTEXT awareness_to_awareness_ctx(dpi_awareness awareness)
		{
			DPI_AWARENESS_CONTEXT ctx{};
			_ASSERTE(awareness != dpi_awareness::unknown);
			switch (awareness)
			{
			case dpi_awareness::unaware:
				ctx = DPI_AWARENESS_CONTEXT_UNAWARE;
				break;
			case dpi_awareness::system:
				ctx = DPI_AWARENESS_CONTEXT_SYSTEM_AWARE;
				break;
			case dpi_awareness::per_monitor:
				ctx = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE;
				break;
			case dpi_awareness::per_monitor_v2:
				ctx = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;
				break;
			case dpi_awareness::unaware_scaled:
				ctx = DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED;
				break;
			}

			return ctx;
		}

		inline dpi_hosting_behaviour convert_behaviour_from_api(DPI_HOSTING_BEHAVIOR b)
		{
			return static_cast<dpi_hosting_behaviour>(b);
		}
		inline DPI_HOSTING_BEHAVIOR convert_behaviour_to_api(dpi_hosting_behaviour b)
		{
			return static_cast<DPI_HOSTING_BEHAVIOR>(b);
		}

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

			static void enable_mouse_in_pointer() noexcept;
			static bool is_mouse_in_pointer_enabled() noexcept;

			static dpi_awareness get_process_dpi_awareness() noexcept;

			dpi_awareness get_thread_dpi_awareness() noexcept;
			dpi_awareness set_thread_dpi_awareness(dpi_awareness) noexcept;
			dpi_hosting_behaviour get_thread_dpi_hosting_behaviour() noexcept;
			dpi_hosting_behaviour set_thread_dpi_hosting_behaviour(dpi_hosting_behaviour) noexcept;
			uint32_t set_thread_cursor_creation_scaling(uint32_t);

			void send_pump_exit_for_thread(uint32_t, int) noexcept;

			uint32_t get_main_thread_id() const noexcept;
			bool is_current_thread_main_thread() const noexcept;
			uint32_t add_callback(pump_callback_wrapper, uint32_t, uint32_t);
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

			template <bool Unicode>
			int run_message_pump(uint32_t tid)
			{
				using utility::conversion::value_convert;
				using traits_t = run_pump_traits<Unicode>;

				auto &tpi{ get_pump_info_for_thread(tid) };

				tpi.in_message_pump = true;

				MSG msg{};

				while (traits_t::WndGetMessage(&msg, nullptr, 0, 0))
				{
					bool dispatch_message{ true };
					{
						std::shared_lock sl{ tpi.callback_mutex };

						for (auto &pci : tpi.callback_info)
						{
							callback_information &ci{ *pci.second.get() };
							auto sc_result{ ci.callback_wrapper(msg) };
							dispatch_message = sc_result == true ? dispatch_message : sc_result;
						}
					}

					if (dispatch_message)
					{
						traits_t::WndDispatchMessage(&msg);
					}
				}

				int result{ value_convert<int>(msg.wParam) };

				tpi.in_message_pump = false;

				return result;
			}

			template <bool Unicode>
			int run_game_message_pump(uint32_t tid)
			{
				using utility::conversion::value_convert;
				using traits_t = run_pump_traits<Unicode>;

				auto &tpi{ get_pump_info_for_thread(tid) };
				bool continue_loop{ true };

				tpi.in_message_pump = true;
				MSG msg{};

				while (continue_loop)
				{
					if (traits_t::WndPeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) != 0)
					{
						if (msg.message != WM_QUIT)
						{
							bool dispatch_message{ true };

							{
								std::shared_lock sl{ tpi.callback_mutex };

								for (auto &pci : tpi.callback_info)
								{
									callback_information &ci{ *pci.second.get() };
									auto sc_result{ ci.callback_wrapper(msg) };
									dispatch_message = sc_result == true ? dispatch_message : sc_result;
								}
							}

							if (dispatch_message)
							{
								traits_t::WndDispatchMessage(&msg);
							}
						}
						else
						{
							continue_loop = false;
						}
					}
					else
					{
						std::shared_lock sl{ tpi.callback_mutex };

						_ASSERTE(tpi.callback_work_information);

						work_callback_wrapper &ci{ *tpi.callback_work_information.get() };

						auto result{ ci() };
						continue_loop = result;
					}
				}

				int result{ value_convert<int>(msg.wParam) };

				tpi.in_message_pump = false;

				return result;
			}

			template <bool Unicode>
			void clear_message_queue(uint32_t tid)
			{
				using traits_t = run_pump_traits<Unicode>;
				auto &tpi{ get_pump_info_for_thread(tid) };

				tpi.in_message_pump = true;

				MSG msg{};

				while (traits_t::WndPeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) != 0)
				{
					traits_t::WndDispatchMessage(&msg);
				}

				tpi.in_message_pump = false;
			}

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

			static bool convert_thread_to_ui_thread() noexcept;

			static thread_data_map &get_data_map();
			static void init_data_for_thread(uint32_t);
			static void remove_data_for_thread(uint32_t);
			static thread_pump_information &get_pump_info_for_thread(uint32_t);

			static uint32_t get_current_thread_id() noexcept;
			static bool post_quit_message_for_thread(uint32_t, int) noexcept;

			std::atomic_uint32_t m_refs{ 1 };
		};
	}
}
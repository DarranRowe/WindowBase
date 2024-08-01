#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <wrl.h>

#include "application_dispatcher_queue.hpp"
#include "application_dispatcher_queue_private.hpp"

#include <mutex>
#include "application.hpp"
#include "application_helper.hpp"
#include <DispatcherQueue.h>

#include "wrl_helpers.h"

#if !defined WINAPPSDK_AVAILABLE
namespace ABI
{
	namespace Microsoft
	{
		namespace UI
		{
			namespace Dispatching
			{
				//The structure needs to be defined for ComPtr.
				struct IDispatcherQueue : public IInspectable
				{
				};
			}
		}
	}
}
#endif

namespace application
{
	namespace details
	{
		static std::atomic_uint32_t system_queue_refs{ 0 };
		static std::atomic_uint32_t was_queue_refs{ 0 };
		static std::mutex dispatcher_queue_info_mutex_thread_lock;
		static std::mutex dispatcher_queue_info_mutex_b_lock;
		static dispatcher_queue_info s_dispatcher_queue_info{};

		void shutdown_all_sys_queues()
		{
			{
				std::scoped_lock sl(dispatcher_queue_info_mutex_thread_lock);
				s_dispatcher_queue_info.thread_sys_dispatcher_queue.clear();
			}

			{
				std::scoped_lock sl(dispatcher_queue_info_mutex_b_lock);
				s_dispatcher_queue_info.background_information.background_sys_thread.clear();
			}
		}
		void shutdown_all_app_queues()
		{
#if defined WINAPPSDK_AVAILABLE
			{
				std::scoped_lock sl(dispatcher_queue_info_mutex_thread_lock);
				s_dispatcher_queue_info.thread_app_dispatcher_queue.clear();
			}

			{
				std::scoped_lock sl(dispatcher_queue_info_mutex_b_lock);
				s_dispatcher_queue_info.background_information.background_app_thread.clear();
			}
#endif
		}

		bool runtime_loadable()
		{
			if constexpr (winappsdk_available)
			{
				wil::unique_hmodule win_app_runtime_handle;

				win_app_runtime_handle.reset(LoadLibraryW(L"Microsoft.WindowsAppRuntime.dll"));

				return win_app_runtime_handle != nullptr;
			}
			else
			{
				return false;
			}
		}
		bool wappsdk_dq_activatable()
		{
#if defined WINAPPSDK_AVAILABLE
			bool result = true;
			try
			{
				auto rf = wrl_helpers::get_activation_factory<ABI::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics>();
			}
			catch (wil::ResultException &)
			{
				result = false;
			}

			return result;
#else
			return false;
#endif
		}

		void incref_sys_queue()
		{
			++system_queue_refs;
		}

		bool decref_sys_queue()
		{
			auto refs = --system_queue_refs;
			return refs == 0 ? false : true;
		}

		void incref_was_queue()
		{
			++was_queue_refs;
		}

		bool decref_was_queue()
		{
			auto refs = --was_queue_refs;
			return refs == 0 ? false : true;
		}
	}

	bool is_current_thread_ui()
	{
		return IsGUIThread(FALSE) == FALSE ? false : true;
	}
	void clear_message_queue()
	{
		MSG msg{};

		while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			DispatchMessageW(&msg);
		}
	}

	application_system_dispatcher_queue::application_system_dispatcher_queue() noexcept
	{
		details::incref_sys_queue();
	}

	application_system_dispatcher_queue::application_system_dispatcher_queue(const application_system_dispatcher_queue &) noexcept
	{
		details::incref_sys_queue();
	}

	application_system_dispatcher_queue::application_system_dispatcher_queue(application_system_dispatcher_queue &&) noexcept
	{
		details::incref_sys_queue();
	}

	application_system_dispatcher_queue::~application_system_dispatcher_queue() noexcept
	{
		auto still_alive = details::decref_sys_queue();
		if(!still_alive)
		{
			details::shutdown_all_sys_queues();
			clear_message_queue();
		}
	}

	bool application_system_dispatcher_queue::thread_has_dispatcher_queue() const noexcept
	{
		auto thread_id = GetCurrentThreadId();

		{
			std::scoped_lock sl = std::scoped_lock(details::dispatcher_queue_info_mutex_thread_lock);
			auto tit = details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.find(thread_id);

			if (tit != details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.end())
			{
				return true;
			}
		}

		return false;
	}

	bool application_system_dispatcher_queue::thread_has_uncontrolled_dispatcher_queue() const noexcept
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;
		bool return_result = false;

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				auto dq_statics = wrl_helpers::get_activation_factory<IDispatcherQueueStatics>();
				ComPtr<IDispatcherQueue> tdq;
				THROW_IF_FAILED(dq_statics->GetForCurrentThread(tdq.ReleaseAndGetAddressOf()));

				if (tdq != nullptr)
				{
					return_result = true;
				}
			});

		return return_result;
	}

	bool application_system_dispatcher_queue::create_dispatcher_queue_on_thread() noexcept
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;

		using namespace std;

		bool return_result = false;

		auto thread_id = GetCurrentThreadId();

		if (!is_current_thread_ui())
		{
			return false;
		}

		if (thread_has_dispatcher_queue())
		{
			return true;
		}

		if (thread_has_uncontrolled_dispatcher_queue())
		{
			return true;
		}

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				ComPtr<IDispatcherQueueController> disp_queue_ctrl;
				THROW_IF_FAILED(CreateDispatcherQueueController(DispatcherQueueOptions{ sizeof(DispatcherQueueOptions), DQTYPE_THREAD_CURRENT, DQTAT_COM_NONE }, disp_queue_ctrl.ReleaseAndGetAddressOf()));

				{
					scoped_lock sl{ details::dispatcher_queue_info_mutex_thread_lock };
					details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.emplace(make_pair(thread_id, move(disp_queue_ctrl)));
				}

				return_result = true;
			});

		return return_result;
	}

	int32_t application_system_dispatcher_queue::create_background_dispatcher_queue() noexcept
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;

		using namespace std;
		int32_t disp_queue_id = -1;

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				DispatcherQueueOptions dqo{sizeof(DispatcherQueueOptions), DQTYPE_THREAD_DEDICATED, DQTAT_COM_STA};
				THROW_IF_FAILED(CreateDispatcherQueueController(DispatcherQueueOptions{ sizeof(DispatcherQueueOptions), DQTYPE_THREAD_DEDICATED, DQTAT_COM_STA }, dqc.ReleaseAndGetAddressOf()));

				{
					scoped_lock sl{ details::dispatcher_queue_info_mutex_b_lock };
					auto &bi = details::s_dispatcher_queue_info.background_information;

					_ASSERTE(bi.background_id >= -1);
					auto id_cache = bi.background_id++;
					bi.background_sys_thread.emplace(id_cache, move(dqc));
					disp_queue_id = id_cache;
				}
			});

		return disp_queue_id;
	}

	void application_system_dispatcher_queue::destroy_thread_dispatcher_queue() noexcept
	{
		using namespace ABI::Windows::Foundation;
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;

		auto id = GetCurrentThreadId();
		if (!is_current_thread_ui())
		{
			return;
		}

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					std::scoped_lock sl{ details::dispatcher_queue_info_mutex_thread_lock };
					auto it = details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.find(id);
					if (it != details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.end())
					{
						dqc = (*it).second;
						details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.erase(id);
					}
				}

				if (dqc)
				{
					ComPtr<IAsyncAction> async_return;
					THROW_IF_FAILED(dqc->ShutdownQueueAsync(async_return.ReleaseAndGetAddressOf()));

					ComPtr<IAsyncInfo> async_return_info;
					THROW_IF_FAILED(async_return.As(&async_return_info));

					AsyncStatus as{};
					THROW_IF_FAILED(async_return_info->get_Status(&as));

					while (as == AsyncStatus::Started)
					{
						clear_message_queue();
						THROW_IF_FAILED(async_return_info->get_Status(&as));
					}
				}
			});
	}

	void application_system_dispatcher_queue::destroy_background_dispatcher_queue(int32_t id) noexcept
	{
		using namespace ABI::Windows::Foundation;
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					std::scoped_lock sl(details::dispatcher_queue_info_mutex_b_lock);

					auto it = details::s_dispatcher_queue_info.background_information.background_sys_thread.find(id);
					if (it != details::s_dispatcher_queue_info.background_information.background_sys_thread.end())
					{
						dqc = (*it).second;
						details::s_dispatcher_queue_info.background_information.background_sys_thread.erase(id);
					}
				}

				if (dqc)
				{
					ComPtr<IAsyncAction> async_return;
					THROW_IF_FAILED(dqc->ShutdownQueueAsync(async_return.ReleaseAndGetAddressOf()));

					ComPtr<IAsyncInfo> async_return_info;
					THROW_IF_FAILED(async_return.As(&async_return_info));

					AsyncStatus as{};
					THROW_IF_FAILED(async_return_info->get_Status(&as));

					while (as == AsyncStatus::Started)
					{
						clear_message_queue();
						THROW_IF_FAILED(async_return_info->get_Status(&as));
					}
				}
			});
	}

	void check_runtime_capability()
	{
		if constexpr (winappsdk_available == false)
		{
			helper::writeln_debugger(L"Library was built without Windows App SDK support.");
			helper::writeln_debugger(L"Make sure that the Windows App SDK ABI headers have been placed in the correct location.");
		}
		_ASSERTE(winappsdk_available == true);
		bool loadable_runtime = details::runtime_loadable();
		if (!loadable_runtime)
		{
			helper::writeln_debugger(L"Windows App SDK was not loadable.");
			helper::writeln_debugger(L"Please bootstrap the Windows App Runtime, reference with the Dynamic Dependencies API or build the application as self contained.");
		}
		_ASSERTE(loadable_runtime == true);
	}

	application_winappsdk_dispatcher_queue::application_winappsdk_dispatcher_queue() noexcept
	{
		check_runtime_capability();
		details::incref_was_queue();
	}
	application_winappsdk_dispatcher_queue::application_winappsdk_dispatcher_queue(const application_winappsdk_dispatcher_queue &) noexcept
	{
		//There is no check for the runtime capabilities here.
		//This copies from an existing instance, that is where the capabilities are checked.
		details::incref_was_queue();
	}
	application_winappsdk_dispatcher_queue::application_winappsdk_dispatcher_queue(application_winappsdk_dispatcher_queue &&) noexcept
	{
		//There is no check for the runtime capabilities here.
		//This copies from an existing instance, that is where the capabilities are checked.
		details::incref_was_queue();
	}
	application_winappsdk_dispatcher_queue::~application_winappsdk_dispatcher_queue() noexcept
	{
		auto still_alive = details::decref_was_queue();

		if constexpr (winappsdk_available)
		{
			if (!still_alive)
			{
				details::shutdown_all_app_queues();
				clear_message_queue();
			}
		}
	}

	bool application_winappsdk_dispatcher_queue::dispatcher_queue_available() noexcept
	{
		if (details::runtime_loadable() && details::wappsdk_dq_activatable())
		{
			return true;
		}

		return false;
	}

	bool application_winappsdk_dispatcher_queue::thread_has_dispatcher_queue() const noexcept
	{
#if defined WINAPPSDK_AVAILABLE
		auto thread_id = GetCurrentThreadId();

		{
			std::scoped_lock sl = std::scoped_lock(details::dispatcher_queue_info_mutex_thread_lock);
			auto tit = details::s_dispatcher_queue_info.thread_app_dispatcher_queue.find(thread_id);

			if (tit != details::s_dispatcher_queue_info.thread_app_dispatcher_queue.end())
			{
				return true;
			}
		}
#endif

		return false;
	}

	bool application_winappsdk_dispatcher_queue::thread_has_uncontrolled_dispatcher_queue() const noexcept
	{
		bool return_result = false;

#if defined WINAPPSDK_AVAILABLE
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;
		
		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				auto dq_statics = wrl_helpers::get_activation_factory<IDispatcherQueueStatics>();
				ComPtr<IDispatcherQueue> tdq;
				THROW_IF_FAILED(dq_statics->GetForCurrentThread(tdq.ReleaseAndGetAddressOf()));

				if (tdq != nullptr)
				{
					return_result = true;
				}
			});
#endif
		_ASSERTE(winappsdk_available == true);

		return return_result;
	}

	bool application_winappsdk_dispatcher_queue::create_dispatcher_queue_on_thread() noexcept
	{
		bool return_result = false;

#if defined WINAPPSDK_AVAILABLE
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;

		using namespace std;

		auto thread_id = GetCurrentThreadId();

		if (!is_current_thread_ui())
		{
			return false;
		}

		if (thread_has_dispatcher_queue())
		{
			return true;
		}

		if (thread_has_uncontrolled_dispatcher_queue())
		{
			return true;
		}

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				ComPtr<IDispatcherQueueController> disp_queue_ctrl;
				auto dqcs = wrl_helpers::get_activation_factory<IDispatcherQueueControllerStatics>();

				THROW_IF_FAILED(dqcs->CreateOnCurrentThread(disp_queue_ctrl.ReleaseAndGetAddressOf()));

				{
					scoped_lock sl{ details::dispatcher_queue_info_mutex_thread_lock };
					details::s_dispatcher_queue_info.thread_app_dispatcher_queue.emplace(make_pair(thread_id, move(disp_queue_ctrl)));
				}

				return_result = true;
			});
#endif

		return return_result;
	}

	int32_t application_winappsdk_dispatcher_queue::create_background_dispatcher_queue() noexcept
	{
		int32_t disp_queue_id = -1;

#if defined WINAPPSDK_AVAILABLE
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;

		using namespace std;

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				auto dqcs = wrl_helpers::get_activation_factory<IDispatcherQueueControllerStatics>();

				THROW_IF_FAILED(dqcs->CreateOnCurrentThread(dqc.ReleaseAndGetAddressOf()));

				{
					scoped_lock sl{ details::dispatcher_queue_info_mutex_b_lock };
					auto &bi = details::s_dispatcher_queue_info.background_information;

					_ASSERTE(bi.background_id >= -1);
					auto id_cache = bi.background_id++;
					bi.background_app_thread.emplace(id_cache, move(dqc));
					disp_queue_id = id_cache;
				}
			});
#endif

		return disp_queue_id;
	}

	void application_winappsdk_dispatcher_queue::destroy_thread_dispatcher_queue() noexcept
	{
#if defined WINAPPSDK_AVAILABLE
		using namespace ABI::Windows::Foundation;
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;

		auto id = GetCurrentThreadId();
		if (!is_current_thread_ui())
		{
			return;
		}

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					std::scoped_lock sl{ details::dispatcher_queue_info_mutex_thread_lock };
					auto it = details::s_dispatcher_queue_info.thread_app_dispatcher_queue.find(id);
					if (it != details::s_dispatcher_queue_info.thread_app_dispatcher_queue.end())
					{
						dqc = (*it).second;
						details::s_dispatcher_queue_info.thread_app_dispatcher_queue.erase(id);
					}
				}

				if (dqc)
				{
					ComPtr<IAsyncAction> async_return;
					THROW_IF_FAILED(dqc->ShutdownQueueAsync(async_return.ReleaseAndGetAddressOf()));

					ComPtr<IAsyncInfo> async_return_info;
					THROW_IF_FAILED(async_return.As(&async_return_info));

					AsyncStatus as{};
					THROW_IF_FAILED(async_return_info->get_Status(&as));

					while (as == AsyncStatus::Started)
					{
						clear_message_queue();
						THROW_IF_FAILED(async_return_info->get_Status(&as));
					}
				}
			});
#endif
	}

	void application_winappsdk_dispatcher_queue::destroy_background_dispatcher_queue([[maybe_unused]] int32_t id) noexcept
	{
#if defined WINAPPSDK_AVAILABLE
		using namespace ABI::Windows::Foundation;
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&, this]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					std::scoped_lock sl(details::dispatcher_queue_info_mutex_b_lock);

					auto it = details::s_dispatcher_queue_info.background_information.background_app_thread.find(id);
					if (it != details::s_dispatcher_queue_info.background_information.background_app_thread.end())
					{
						dqc = (*it).second;
						details::s_dispatcher_queue_info.background_information.background_app_thread.erase(id);
					}
				}

				if (dqc)
				{
					ComPtr<IAsyncAction> async_return;
					THROW_IF_FAILED(dqc->ShutdownQueueAsync(async_return.ReleaseAndGetAddressOf()));

					ComPtr<IAsyncInfo> async_return_info;
					THROW_IF_FAILED(async_return.As(&async_return_info));

					AsyncStatus as{};
					THROW_IF_FAILED(async_return_info->get_Status(&as));

					while (as == AsyncStatus::Started)
					{
						clear_message_queue();
						THROW_IF_FAILED(async_return_info->get_Status(&as));
					}
				}
			});
#endif
	}
}
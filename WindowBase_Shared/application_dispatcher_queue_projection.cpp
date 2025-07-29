#include "windowbase/application_dispatcher_queue_projection.hpp"
#include "application_dispatcher_queue_private.hpp"

#include <wil/result_originate.h>

namespace window_base::application::projection
{
	void *application_system_dispatcher_queue_access::get_thread_dispatcher_queue_abi()
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;
		using namespace std;

		void *result{ nullptr };
		auto thread_id{ GetCurrentThreadId() };

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					scoped_lock sl{ details::obtain_dqinfo_mutex() };
					auto &info{ details::obtain_dqinfo() };

					auto it{ info.thread_sys_dispatcher_queue.find(thread_id) };
					if (it != info.thread_sys_dispatcher_queue.end())
					{
						dqc = (*it).second;
						ComPtr<IDispatcherQueue> dq;
						THROW_IF_FAILED(dqc->get_DispatcherQueue(dq.ReleaseAndGetAddressOf()));

						//This keeps the current reference count.
						//It will immediately be attached to a projection type.
						result = dq.Detach();
					}
				}
			});

		return result;
	}

	void *application_system_dispatcher_queue_access::get_background_dispatcher_queue_abi(int32_t id)
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;
		using namespace std;

		void *result{ nullptr };

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					scoped_lock sl{ details::obtain_dqinfo_background_mutex() };
					auto &bi{ details::obtain_dqinfo().background_information };

					auto it{ bi.background_sys_thread.find(id) };
					if (it != bi.background_sys_thread.end())
					{
						dqc = (*it).second;
						Microsoft::WRL::ComPtr<IDispatcherQueue> dq;
						THROW_IF_FAILED(dqc->get_DispatcherQueue(dq.ReleaseAndGetAddressOf()));

						//This keeps the current reference count.
						//It will immediately be attached to a projection type.
						result = dq.Detach();
					}
				}
			});

		return result;
	}

	void *application_winappsdk_dispatcher_queue_access::get_thread_dispatcher_queue_abi()
	{
#ifdef WINAPPSDK_AVAILABLE
		using namespace ABI::Microsoft::UI::Dispatching;
#endif
		using namespace Microsoft::WRL;
		using namespace std;

		void *result{ nullptr };

#ifdef WINAPPSDK_AVAILABLE
		auto thread_id{ GetCurrentThreadId() };
		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					scoped_lock sl{ details::obtain_dqinfo_mutex() };
					auto &info{ details::obtain_dqinfo() };

					auto it{ info.thread_app_dispatcher_queue.find(thread_id) };
					if (it != info.thread_app_dispatcher_queue.end())
					{
						dqc = (*it).second;
						ComPtr<IDispatcherQueue> dq;
						THROW_IF_FAILED(dqc->get_DispatcherQueue(dq.ReleaseAndGetAddressOf()));

						//This keeps the current reference count.
						//It will immediately be attached to a projection type.
						result = dq.Detach();
					}
				}
			});
#endif
		_ASSERTE(winappsdk_available == true);
		return result;

	}
	void *application_winappsdk_dispatcher_queue_access::get_background_dispatcher_queue_abi([[maybe_unused]] int32_t id)
	{
#ifdef WINAPPSDK_AVAILABLE
		using namespace ABI::Microsoft::UI::Dispatching;
#endif
		using namespace Microsoft::WRL;
		using namespace std;

		void *result{ nullptr };

#ifdef WINAPPSDK_AVAILABLE
		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					scoped_lock sl{ details::obtain_dqinfo_background_mutex() };
					auto &bi{ details::obtain_dqinfo().background_information };

					auto it{ bi.background_app_thread.find(id) };
					if (it != bi.background_app_thread.end())
					{
						dqc = (*it).second;
						Microsoft::WRL::ComPtr<IDispatcherQueue> dq;
						THROW_IF_FAILED(dqc->get_DispatcherQueue(dq.ReleaseAndGetAddressOf()));

						//This keeps the current reference count.
						//It will immediately be attached to a projection type.
						result = dq.Detach();
					}
				}
			});

#endif
		_ASSERTE(winappsdk_available == true);
		return result;
	}
}
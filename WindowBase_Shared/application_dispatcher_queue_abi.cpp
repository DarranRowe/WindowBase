#include "windowbase/application_dispatcher_queue_abi.hpp"
#include "application_dispatcher_queue_private.hpp"

#include <wil/result_originate.h>

#if !defined WINAPPSDK_AVAILABLE
namespace ABI::Microsoft::UI::Dispatching
{
	//The structure needs to be defined for ComPtr.
	struct IDispatcherQueue : public IInspectable
	{
	};
}
#endif

namespace window_base::application::abi
{
	Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> application_system_dispatcher_queue_access::get_thread_dispatcher_queue()
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;
		using namespace std;

		auto thread_id{ GetCurrentThreadId() };
		ComPtr<IDispatcherQueue> result;

		wil::FailFastException(WI_DIAGNOSTICS_INFO, [&]()
			{
				ComPtr<IDispatcherQueueController> dqc;
				{
					scoped_lock sl{ details::obtain_dqinfo_mutex()};
					auto &info{ details::obtain_dqinfo() };

					auto it{ info.thread_sys_dispatcher_queue.find(thread_id) };
					if (it != info.thread_sys_dispatcher_queue.end())
					{
						dqc = (*it).second;
						THROW_IF_FAILED(dqc->get_DispatcherQueue(result.ReleaseAndGetAddressOf()));
					}
				}
			});

		return result;
	}

	Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> application_system_dispatcher_queue_access::get_background_dispatcher_queue(int32_t id)
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;
		using namespace std;

		Microsoft::WRL::ComPtr<IDispatcherQueue> result;

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
						THROW_IF_FAILED(dqc->get_DispatcherQueue(result.ReleaseAndGetAddressOf()));
					}
				}
			});

		return result;
	}

	Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> application_winappsdk_dispatcher_queue_access::get_thread_dispatcher_queue()
	{
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;
		using namespace std;

		ComPtr<IDispatcherQueue> result;

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
						THROW_IF_FAILED(dqc->get_DispatcherQueue(result.ReleaseAndGetAddressOf()));
					}
				}
			});
#endif

		return result;
	}

	Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> application_winappsdk_dispatcher_queue_access::get_background_dispatcher_queue([[maybe_unused]] int32_t id)
	{
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;
		using namespace std;

		Microsoft::WRL::ComPtr<IDispatcherQueue> result;

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
						THROW_IF_FAILED(dqc->get_DispatcherQueue(result.ReleaseAndGetAddressOf()));
					}
				}
			});
#endif

		return result;
	}
}
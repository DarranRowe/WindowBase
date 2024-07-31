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
		std::mutex dispatcher_queue_info_mutex_thread_lock;
		std::mutex dispatcher_queue_info_mutex_b_lock;
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

	application_system_dispatcher_queue::application_system_dispatcher_queue()
	{
	}
	application_system_dispatcher_queue::~application_system_dispatcher_queue()
	{
		details::shutdown_all_sys_queues();
		clear_message_queue();
	}

	bool application_system_dispatcher_queue::thread_has_dispatcher_queue() const
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

	bool application_system_dispatcher_queue::thread_has_uncontrolled_dispatcher_queue() const
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;
		try
		{
			HRESULT hr = S_OK;

			auto dq_statics = wrl_helpers::get_activation_factory<IDispatcherQueueStatics>();
			ComPtr<IDispatcherQueue> tdq;
			hr = dq_statics->GetForCurrentThread(tdq.ReleaseAndGetAddressOf());

			if (tdq != nullptr)
			{
				return true;
			}
		}
		catch (wil::ResultException &)
		{
		}

		return false;
	}

	bool application_system_dispatcher_queue::create_dispatcher_queue_on_thread()
	{
		using namespace ABI::Windows::System;
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

		try
		{
			HRESULT hr = S_OK;
			ComPtr<IDispatcherQueueController> disp_queue_ctrl;

			hr = CreateDispatcherQueueController(DispatcherQueueOptions{ sizeof(DispatcherQueueOptions), DQTYPE_THREAD_CURRENT, DQTAT_COM_NONE }, disp_queue_ctrl.ReleaseAndGetAddressOf());
			THROW_IF_FAILED(hr);

			{
				scoped_lock sl(details::dispatcher_queue_info_mutex_thread_lock);
				details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.emplace(make_pair(thread_id, move(disp_queue_ctrl)));
			}

			return true;
		}
		catch (wil::ResultException &)
		{
		}

		return false;
	}

	int32_t application_system_dispatcher_queue::create_background_dispatcher_queue()
	{
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;

		int32_t disp_queue_id = -1;
		try
		{
			ComPtr<IDispatcherQueueController> dqc;

			//Desktop applications don't work with ASTA, so we just use STA.
			DispatcherQueueOptions dqo{ sizeof(DispatcherQueueOptions), DQTYPE_THREAD_DEDICATED, DQTAT_COM_STA};
			HRESULT hr = CreateDispatcherQueueController(dqo, dqc.ReleaseAndGetAddressOf());

			if (SUCCEEDED(hr))
			{
				std::scoped_lock sl(details::dispatcher_queue_info_mutex_b_lock);
				auto &bi = details::s_dispatcher_queue_info.background_information;

				_ASSERTE(bi.background_id >= -1);
				auto id_cache = bi.background_id++;
				bi.background_sys_thread.emplace(id_cache, std::move(dqc));
				disp_queue_id = id_cache;
			}
		}
		catch (wil::ResultException &)
		{
		}

		return disp_queue_id;
	}

	void application_system_dispatcher_queue::destroy_thread_dispatcher_queue()
	{
		using namespace ABI::Windows::Foundation;
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;

		auto id = GetCurrentThreadId();
		if (!is_current_thread_ui())
		{
			return;
		}

		ComPtr<IDispatcherQueueController> dqc;
		{
			std::scoped_lock sl(details::dispatcher_queue_info_mutex_thread_lock);

			auto it = details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.find(id);
			if (it != details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.end())
			{
				dqc = (*it).second;
				details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.erase(id);
			}
		}

		try
		{
			HRESULT hr = S_OK;
			ComPtr<IAsyncAction> async_return;
			hr = dqc->ShutdownQueueAsync(async_return.ReleaseAndGetAddressOf());
			THROW_IF_FAILED(hr);

			ComPtr<IAsyncInfo> async_return_info;
			hr = async_return.As(&async_return_info);
			THROW_IF_FAILED(hr);

			AsyncStatus as{};
			hr = async_return_info->get_Status(&as);
			THROW_IF_FAILED(hr);

			while (as == AsyncStatus::Started)
			{
				clear_message_queue();
				hr = async_return_info->get_Status(&as);
				THROW_IF_FAILED(hr);
			}
		}
		catch (wil::ResultException &)
		{

		}
	}

	void application_system_dispatcher_queue::destroy_background_dispatcher_queue(int32_t id)
	{
		using namespace ABI::Windows::Foundation;
		using namespace ABI::Windows::System;
		using namespace Microsoft::WRL;

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

		try
		{
			HRESULT hr = S_OK;
			ComPtr<IAsyncAction> async_return;
			hr = dqc->ShutdownQueueAsync(async_return.ReleaseAndGetAddressOf());
			THROW_IF_FAILED(hr);

			ComPtr<IAsyncInfo> async_return_info;
			hr = async_return.As(&async_return_info);
			THROW_IF_FAILED(hr);

			AsyncStatus as{};
			hr = async_return_info->get_Status(&as);
			THROW_IF_FAILED(hr);

			while (as == AsyncStatus::Started)
			{
				clear_message_queue();
				hr = async_return_info->get_Status(&as);
				THROW_IF_FAILED(hr);
			}
		}
		catch (wil::ResultException &)
		{

		}
	}

	Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> application_system_dispatcher_queue::get_thread_dispatcher_queue() const
	{
		auto thread_id = GetCurrentThreadId();
		Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> result;
		HRESULT hr = S_OK;

		{
			std::scoped_lock sl(details::dispatcher_queue_info_mutex_thread_lock);
			auto dq_it = details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.find(thread_id);
			if (dq_it == details::s_dispatcher_queue_info.thread_sys_dispatcher_queue.end())
			{
				return {};
			}

			hr = (*dq_it).second->get_DispatcherQueue(result.ReleaseAndGetAddressOf());
		}

		if (FAILED(hr))
		{
			return {};
		}
		return result;
	}

	Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> application_system_dispatcher_queue::get_background_dispatcher_queue(int32_t id) const
	{
		Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> result;
		HRESULT hr = S_OK;

		{
			std::scoped_lock sl(details::dispatcher_queue_info_mutex_b_lock);
			auto &bi = details::s_dispatcher_queue_info.background_information;
			auto it = bi.background_sys_thread.find(id);
			if (it != bi.background_sys_thread.end())
			{
				hr = (*it).second->get_DispatcherQueue(result.ReleaseAndGetAddressOf());
			}
		}

		if (FAILED(hr))
		{
			result.Reset();
		}

		return result;
	}

	application_winappsdk_dispatcher_queue::application_winappsdk_dispatcher_queue()
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
	application_winappsdk_dispatcher_queue::~application_winappsdk_dispatcher_queue()
	{
#if defined WINAPPSDK_AVAILABLE
		details::shutdown_all_app_queues();
		clear_message_queue();
#endif
	}

	bool application_winappsdk_dispatcher_queue::dispatcher_queue_available()
	{
		if (details::runtime_loadable() && details::wappsdk_dq_activatable())
		{
			return true;
		}

		return false;
	}

	bool application_winappsdk_dispatcher_queue::thread_has_dispatcher_queue() const
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

	bool application_winappsdk_dispatcher_queue::thread_has_uncontrolled_dispatcher_queue() const
	{
#if defined WINAPPSDK_AVAILABLE
		try
		{
			HRESULT hr = S_OK;

			auto dq_statics = wrl_helpers::get_activation_factory<ABI::Microsoft::UI::Dispatching::IDispatcherQueueStatics>();
			Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> tdq;
			hr = dq_statics->GetForCurrentThread(tdq.ReleaseAndGetAddressOf());

			if (tdq != nullptr)
			{
				return true;
			}
		}
		catch (wil::ResultException &)
		{
		}
#endif
		_ASSERTE(winappsdk_available == true);

		return false;
	}

	bool application_winappsdk_dispatcher_queue::create_dispatcher_queue_on_thread()
	{
#if defined WINAPPSDK_AVAILABLE
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;

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

		try
		{
			HRESULT hr = S_OK;
			ComPtr<IDispatcherQueueController> disp_queue_ctrl;
			auto dqcs = wrl_helpers::get_activation_factory<IDispatcherQueueControllerStatics>();

			hr = dqcs->CreateOnCurrentThread(disp_queue_ctrl.ReleaseAndGetAddressOf());

			{
				std::scoped_lock sl(details::dispatcher_queue_info_mutex_thread_lock);
				details::s_dispatcher_queue_info.thread_app_dispatcher_queue.emplace(std::make_pair(thread_id, std::move(disp_queue_ctrl)));
			}

			return true;
		}
		catch (wil::ResultException &)
		{
		}
#endif

		return false;
	}

	int32_t application_winappsdk_dispatcher_queue::create_background_dispatcher_queue()
	{
		int32_t disp_queue_id = -1;

#if defined WINAPPSDK_AVAILABLE
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;

		try
		{
			HRESULT hr = S_OK;
			ComPtr<IDispatcherQueueController> dqc;
			auto dqcs = wrl_helpers::get_activation_factory<IDispatcherQueueControllerStatics>();

			hr = dqcs->CreateOnDedicatedThread(dqc.ReleaseAndGetAddressOf());

			if (SUCCEEDED(hr))
			{
				std::scoped_lock sl(details::dispatcher_queue_info_mutex_b_lock);
				auto &bi = details::s_dispatcher_queue_info.background_information;

				_ASSERTE(bi.background_id >= -1);
				auto id_cache = bi.background_id++;
				bi.background_app_thread.emplace(id_cache, std::move(dqc));
				disp_queue_id = id_cache;
			}
		}
		catch (wil::ResultException &)
		{
		}
#endif

		return disp_queue_id;
	}

	void application_winappsdk_dispatcher_queue::destroy_thread_dispatcher_queue()
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

		ComPtr<IDispatcherQueueController> dqc;
		{
			std::scoped_lock sl(details::dispatcher_queue_info_mutex_thread_lock);

			auto it = details::s_dispatcher_queue_info.thread_app_dispatcher_queue.find(id);
			if (it != details::s_dispatcher_queue_info.thread_app_dispatcher_queue.end())
			{
				dqc = (*it).second;
				details::s_dispatcher_queue_info.thread_app_dispatcher_queue.erase(id);
			}
		}

		try
		{
			HRESULT hr = S_OK;
			ComPtr<IAsyncAction> async_return;
			hr = dqc->ShutdownQueueAsync(async_return.ReleaseAndGetAddressOf());
			THROW_IF_FAILED(hr);

			ComPtr<IAsyncInfo> async_return_info;
			hr = async_return.As(&async_return_info);
			THROW_IF_FAILED(hr);

			AsyncStatus as{};
			hr = async_return_info->get_Status(&as);
			THROW_IF_FAILED(hr);

			while (as == AsyncStatus::Started)
			{
				clear_message_queue();
				hr = async_return_info->get_Status(&as);
				THROW_IF_FAILED(hr);
			}
		}
		catch (wil::ResultException &)
		{

		}
#endif
	}

	void application_winappsdk_dispatcher_queue::destroy_background_dispatcher_queue(int32_t id)
	{
#if defined WINAPPSDK_AVAILABLE
		using namespace ABI::Windows::Foundation;
		using namespace ABI::Microsoft::UI::Dispatching;
		using namespace Microsoft::WRL;

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

		try
		{
			HRESULT hr = S_OK;
			ComPtr<IAsyncAction> async_return;
			hr = dqc->ShutdownQueueAsync(async_return.ReleaseAndGetAddressOf());
			THROW_IF_FAILED(hr);

			ComPtr<IAsyncInfo> async_return_info;
			hr = async_return.As(&async_return_info);
			THROW_IF_FAILED(hr);

			AsyncStatus as{};
			hr = async_return_info->get_Status(&as);
			THROW_IF_FAILED(hr);

			while (as == AsyncStatus::Started)
			{
				clear_message_queue();
				hr = async_return_info->get_Status(&as);
				THROW_IF_FAILED(hr);
			}
		}
		catch (wil::ResultException &)
		{

		}
#else
		id;
#endif
	}

	Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> application_winappsdk_dispatcher_queue::get_thread_dispatcher_queue() const
	{
		Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> result{};

#if defined WINAPPSDK_AVAILABLE
		auto thread_id = GetCurrentThreadId();
		HRESULT hr = S_OK;

		{
			std::scoped_lock sl(details::dispatcher_queue_info_mutex_thread_lock);
			auto dq_it = details::s_dispatcher_queue_info.thread_app_dispatcher_queue.find(thread_id);
			if (dq_it == details::s_dispatcher_queue_info.thread_app_dispatcher_queue.end())
			{
				return {};
			}

			hr = (*dq_it).second->get_DispatcherQueue(result.ReleaseAndGetAddressOf());
		}

		if (FAILED(hr))
		{
			return {};
		}
#endif
		return result;
	}

	Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> application_winappsdk_dispatcher_queue::get_background_dispatcher_queue(int32_t id) const
	{
		Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> result{};

#if defined WINAPPSDK_AVAILABLE
		HRESULT hr = S_OK;

		{
			std::scoped_lock sl(details::dispatcher_queue_info_mutex_b_lock);
			auto &bi = details::s_dispatcher_queue_info.background_information;
			auto it = bi.background_app_thread.find(id);
			if (it != bi.background_app_thread.end())
			{
				hr = (*it).second->get_DispatcherQueue(result.ReleaseAndGetAddressOf());
			}
		}

		if (FAILED(hr))
		{
			result.Reset();
		}
#else
		id;
#endif
		return result;
	}
}
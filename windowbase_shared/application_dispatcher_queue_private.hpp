#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <vector>
#include <map>

#include <wrl.h>
#include <windows.system.h>
#if (__has_include(<Microsoft.UI.Dispatching.h>))
#define WINAPPSDK_AVAILABLE 1
constexpr bool winappsdk_available = true;
#include <Microsoft.UI.Dispatching.h>
#else
constexpr bool winappsdk_available = false;
#endif

#include <atomic>

namespace application::details
{
	struct background_dispatcher_queue_information
	{
		std::map<int32_t, Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueueController>> background_sys_thread;
#if defined WINAPPSDK_AVAILABLE
		std::map <int32_t, Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueueController>> background_app_thread;
#endif
		std::atomic_int32_t background_id{};
	};

	struct dispatcher_queue_info
	{
		std::map<uint32_t, Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueueController>> thread_sys_dispatcher_queue;
#if defined WINAPPSDK_AVAILABLE
		std::map<uint32_t, Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueueController>> thread_app_dispatcher_queue;
#endif
		background_dispatcher_queue_information background_information;
	};

	void shutdown_all_sys_queues();
	void shutdown_all_app_queues();

	bool runtime_loadable();
	bool wappsdk_dq_activatable();
}
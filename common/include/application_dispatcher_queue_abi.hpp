#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <wrl.h>

#include <cinttypes>
#include <cstdint>

#include <windows.system.h>
#if __has_include(<microsoft.ui.dispatching.h>)
#define WINAPPSDK_ENABLE_ABI
#include <microsoft.ui.dispatching.h>
#endif

#if !defined WINAPPSDK_ENABLE_ABI
namespace ABI
{
	namespace Microsoft
	{
		namespace UI
		{
			namespace Dispatching
			{
				struct IDispatcherQueue;
			}
		}
	}
}
#endif

namespace application::abi
{
	struct application_system_dispatcher_queue_access
	{
		static Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> get_thread_dispatcher_queue();
		static Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> get_background_dispatcher_queue(int32_t);
	};

	struct application_winappsdk_dispatcher_queue_access
	{
		static Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> get_thread_dispatcher_queue();
		static Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> get_background_dispatcher_queue(int32_t);
	};
}
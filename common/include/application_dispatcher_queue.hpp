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
#if (__has_include(<Microsoft.UI.Dispatching.h>))
#include <microsoft.ui.dispatching.h>
#endif

namespace application
{
	class application_system_dispatcher_queue
	{
	public:
		application_system_dispatcher_queue();
		~application_system_dispatcher_queue();

		bool thread_has_dispatcher_queue() const;
		bool thread_has_uncontrolled_dispatcher_queue() const;

		bool create_dispatcher_queue_on_thread();
		int32_t create_background_dispatcher_queue();
		void destroy_thread_dispatcher_queue();
		void destroy_background_dispatcher_queue(int32_t);

		Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> get_thread_dispatcher_queue() const;
		Microsoft::WRL::ComPtr<ABI::Windows::System::IDispatcherQueue> get_background_dispatcher_queue(int32_t) const;

		template <typename WinRTDispQueue>
		auto get_thread_dispatcher_queue() -> WinRTDispQueue
		{
#ifdef WINRT_Windows_System_H
			auto dq = get_thread_dispatcher_queue();
			WinRTDispQueue result_dq = nullptr;

			HRESULT hr = dq.CopyTo(reinterpret_cast<ABI::Windows::System::IDispatcherQueue **>(winrt::put_abi(result_dq)));
			winrt::check_hresult(hr);

			return result_dq;
#else
			return WinRTDispQueue{};
#endif
		}
		template <typename WinRTDispQueue>
		auto get_background_dispatcher_queue(int32_t id) -> WinRTDispQueue
		{
#ifdef WINRT_Windows_System_H
			auto dq = get_background_dispatcher_queue(id);
			WinRTDispQueue result_dq = nullptr;

			HRESULT hr = dq.CopyTo(reinterpret_cast<ABI::Windows::System::IDispatcherQueue **>(winrt::put_abi(result_dq)));
			winrt::check_hresult(hr);

			return result_dq;
#else
			return WinRTDispQueue{};
#endif
		}
	};
}
//ABI::Microsoft::UI::Dispatching::IDispatcherQueue
#if !(__has_include(<Microsoft.UI.Dispatching.h>))
//Forwared declare IDispatcherQueue if we can't find the Windows App SDK ABI headers.
//This is to make sure that the class compiles.
#ifndef ____x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue_FWD_DEFINED__
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
#endif
namespace application
{
	class application_winappsdk_dispatcher_queue
	{
	public:
		application_winappsdk_dispatcher_queue();
		~application_winappsdk_dispatcher_queue();

		static bool dispatcher_queue_available();

		bool thread_has_dispatcher_queue() const;
		bool thread_has_uncontrolled_dispatcher_queue() const;

		bool create_dispatcher_queue_on_thread();
		int32_t create_background_dispatcher_queue();
		void destroy_thread_dispatcher_queue();
		void destroy_background_dispatcher_queue(int32_t);

		Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> get_thread_dispatcher_queue() const;
		Microsoft::WRL::ComPtr<ABI::Microsoft::UI::Dispatching::IDispatcherQueue> get_background_dispatcher_queue(int32_t) const;

		template <typename WinRTDispQueue>
		auto get_thread_dispatcher_queue() -> WinRTDispQueue
		{
#ifdef WINRT_Microsoft_UI_Dispatching_H
			auto dq = get_thread_dispatcher_queue();
			WinRTDispQueue result_dq = nullptr;

			HRESULT hr = dq.CopyTo(reinterpret_cast<ABI::Microsoft::UI::Dispatching::IDispatcherQueue **>(winrt::put_abi(result_dq)));
			winrt::check_hresult(hr);

			return result_dq;
#else
			return WinRTDispQueue{};
#endif
		}
		template <typename WinRTDispQueue>
		auto get_background_dispatcher_queue(int32_t id) -> WinRTDispQueue
		{
#ifdef WINRT_Microsoft_UI_Dispatching_H
			auto dq = get_background_dispatcher_queue(id);
			WinRTDispQueue result_dq = nullptr;

			HRESULT hr = dq.CopyTo(reinterpret_cast<ABI::Microsoft::UI::Dispatching::IDispatcherQueue **>(winrt::put_abi(result_dq)));
			winrt::check_hresult(hr);

			return result_dq;
#else
			return WinRTDispQueue{};
#endif
		}
	};
}
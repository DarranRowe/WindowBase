#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <cinttypes>
#include <cstdint>
#include "output_helpers.hpp"

namespace window_base::application::projection
{
	//One big problem with C++/WinRT is that this is a C++ library that isn't fully controlled by this library.
	//There is a certain amount of stability guaranteed with the ABI here, but if this library is built against
	//one version of C++/WinRT and the application is built against another, then this tecnically means that the
	//ABI could be incompatible.
	//We get around this by using void * and the C++/WinRT ABI types to transfer the runtime class to an inline
	//function, and then use an inline function to return the projected type. This roundabout method is also
	//used so we will not need the ABI headers.

	struct dispatcher_queue_dummy_return {};

	struct application_system_dispatcher_queue_access
	{
		static auto get_thread_dispatcher_queue()
		{
			//We check for the include guard rather than the header.
			//The Windows SDK comes with a version of this file.
#ifdef WINRT_Windows_System_H
			auto abi_dq = get_thread_dispatcher_queue_abi();
			winrt::Windows::System::DispatcherQueue dq{ nullptr };

			//For safety purposes, the dispatcher queue has a reference added.
			//We will just attach it to the projection type.
			winrt::attach_abi(dq, abi_dq);
			return dq;
#else
			output_helpers::debug::format_debugwriteln(L"An attempt to obtain the dispatcher queue when a projection header was not included.");
			output_helpers::debug::format_debugwriteln(L"Make sure that winrt/Windows.System.h is included first.");
			_ASSERTE(false);
			return dispatcher_queue_dummy_return{};
#endif
		}

		static auto get_background_dispatcher_queue([[maybe_unused]] int32_t id)
		{
			//We check for the include guard rather than the header.
			//The Windows SDK comes with a version of this file.
#ifdef WINRT_Windows_System_H
			auto abi_dq = get_background_dispatcher_queue_abi(id);
			winrt::Windows::System::DispatcherQueue dq{ nullptr };

			//For safety purposes, the dispatcher queue has a reference added.
			//We will just attach it to the projection type.
			winrt::attach_abi(dq, abi_dq);
			return dq;
#else
			output_helpers::debug::format_debugwriteln(L"An attempt to obtain the dispatcher queue when a projection header was not included.");
			output_helpers::debug::format_debugwriteln(L"Make sure that winrt/Windows.System.h is included first.");
			_ASSERTE(false);
			return dispatcher_queue_dummy_return{};
#endif
		}
	private:
		static void *get_thread_dispatcher_queue_abi();
		static void *get_background_dispatcher_queue_abi(int32_t);
	};

	struct application_winappsdk_dispatcher_queue_access
	{
		static auto get_thread_dispatcher_queue()
		{
			//We check for the include guard rather than the header.
			//The Windows SDK comes with a version of this file.
#ifdef WINRT_Microsoft_UI_Dispatching_H
			auto abi_dq = get_thread_dispatcher_queue_abi();
			winrt::Microsoft::UI::Dispatching::DispatcherQueue dq{ nullptr };

			//For safety purposes, the dispatcher queue has a reference added.
			//We will just attach it to the projection type.
			winrt::attach_abi(dq, abi_dq);
			return dq;
#else
			output_helpers::debug::format_debugwriteln(L"An attempt to obtain the dispatcher queue when a projection header was not included.");
			output_helpers::debug::format_debugwriteln(L"Make sure that winrt/Microsoft.UI.Dispatching.h is included first.");
			_ASSERTE(false);
			return dispatcher_queue_dummy_return{};
#endif
		}

		static auto get_background_dispatcher_queue([[maybe_unused]] int32_t id)
		{
			//We check for the include guard rather than the header.
			//The Windows SDK comes with a version of this file.
#ifdef WINRT_Microsoft_UI_Dispatching_H
			auto abi_dq = get_background_dispatcher_queue_abi(id);
			winrt::Microsoft::UI::Dispatching::DispatcherQueue dq{ nullptr };

			//For safety purposes, the dispatcher queue has a reference added.
			//We will just attach it to the projection type.
			winrt::attach_abi(dq, abi_dq);
			return dq;
#else
			output_helpers::debug::format_debugwriteln(L"An attempt to obtain the dispatcher queue when a projection header was not included.");
			output_helpers::debug::format_debugwriteln(L"Make sure that winrt/Microsoft.UI.Dispatching.h is included first.");
			_ASSERTE(false);
			return dispatcher_queue_dummy_return{};
#endif
		}
	private:
		static void *get_thread_dispatcher_queue_abi();
		static void *get_background_dispatcher_queue_abi(int32_t);
	};
}
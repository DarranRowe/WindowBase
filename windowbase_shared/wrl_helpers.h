#pragma once

#if (__cplusplus >= 202002L || (defined _MSVC_LANG && _MSVC_LANG >= 202002L))
#include <format>
#endif
#include <ctxtcall.h>
#include <wil/wrl.h>
#include <wil/result_originate.h>
#include "application_helper.hpp"
#include "interface_traits.h"

namespace wrl_helpers
{
	inline Microsoft::WRL::Wrappers::HString initialise_hstring(const std::wstring_view &runtime_class)
	{
		Microsoft::WRL::Wrappers::HString hs;
		HRESULT hr{ hs.Set(runtime_class.data()) };

		RoOriginateErrorW(hr, 0, L"Failed to set the runtime class name");
		THROW_IF_FAILED(hr);

		return hs;
	}

	template <typename Interface, typename RuntimeClass>
	inline auto activate_instance()
	{
		static_assert(interface_traits<Interface, RuntimeClass>::activatable);
		auto runtime_class{ initialise_hstring(interface_traits<Interface, RuntimeClass>::class_name) };
		Microsoft::WRL::ComPtr<Interface> ret;
		HRESULT hr{ Windows::Foundation::ActivateInstance(runtime_class, ret.ReleaseAndGetAddressOf()) };
		if (FAILED(hr))
		{
#if (__cplusplus >= 202002L || (defined _MSVC_LANG && _MSVC_LANG >= 202002L))
			auto l_fmtstr{ application::helper::format_to_string(L"Failed to activate instance. Interface name {}, RuntimeClass name {}", interface_traits<Interface, RuntimeClass>::interface_name, interface_traits<Interface, RuntimeClass>::class_name) };
#else
			auto l_fmtstr{ application::helper::format_to_string(L"Failed to activate instance. Interface name %s, RuntimeClass name %s", interface_traits<Interface, RuntimeClass>::interface_name.data(), interface_traits<Interface, RuntimeClass>::class_name.data()) };
#endif
			RoOriginateErrorW(hr, l_fmtstr.length(), l_fmtstr.c_str());
			THROW_IF_FAILED(hr);
		}

		return ret;
	}

	template <typename Interface, typename RuntimeClass>
	inline auto get_activation_factory()
	{
		using application::helper::value_convert;

		Microsoft::WRL::ComPtr<Interface> ret;
		auto runtime_class = initialise_hstring(factory_interface_traits<Interface, RuntimeClass>::class_name);
		HRESULT hr{ Windows::Foundation::GetActivationFactory(runtime_class, ret.ReleaseAndGetAddressOf()) };
		if (FAILED(hr))
		{
#if (__cplusplus >= 202002L || (defined _MSVC_LANG && _MSVC_LANG >= 202002L))
			auto l_fmtstr{ application::helper::format_to_string(L"Failed to get activation factory. Interface name: {}, RuntimeClass name: {}", factory_interface_traits<Interface, RuntimeClass>::interface_name, factory_interface_traits<Interface, RuntimeClass>::class_name) };
#else
			auto l_fmtstr{ application::helper::format_to_string(L"Failed to get activation factory. Interface name: %s, RuntimeClass name: %s", factory_interface_traits<Interface, RuntimeClass>::interface_name.data(), factory_interface_traits<Interface, RuntimeClass>::class_name.data()) };
#endif
			RoOriginateErrorW(hr, value_convert<UINT>(l_fmtstr.length()), l_fmtstr.c_str());
			THROW_IF_FAILED(hr);
		}

		return ret;
	}

	inline auto get_activation_factory(const std::wstring_view &class_name)
	{
		using application::helper::value_convert;

		Microsoft::WRL::ComPtr<IActivationFactory> ret;
		auto runtime_class{ initialise_hstring(class_name) };
		HRESULT hr{ Windows::Foundation::GetActivationFactory(runtime_class, ret.ReleaseAndGetAddressOf()) };
		if (FAILED(hr))
		{
#if (__cplusplus >= 202002L || (defined _MSVC_LANG && _MSVC_LANG >= 202002L))
			auto l_fmtstr{ application::helper::format_to_string(L"Failed to get activation factory. Interface name: IActivationFactory, RuntimeClass name: {}", class_name) };
#else
			auto l_fmtstr{ application::helper::format_to_string(L"Failed to get activation factory. Interface name: IActivationFactory, RuntimeClass name: %s", class_name.data()) };
#endif
			RoOriginateErrorW(hr, value_convert<UINT>(l_fmtstr.length()), l_fmtstr.c_str());
			THROW_IF_FAILED(hr);
		}

		return ret;
	}

	template <typename OutInterface, typename InInterface>
	std::pair<Microsoft::WRL::ComPtr<OutInterface>, HRESULT> try_as(const Microsoft::WRL::ComPtr<InInterface> &ptr)
	{
		Microsoft::WRL::ComPtr<OutInterface> out_ptr;
		HRESULT hr{ ptr.As(&out_ptr) };

		return std::make_pair(std::move(out_ptr), hr);
	}
}
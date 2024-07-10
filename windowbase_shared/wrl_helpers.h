#pragma once

#include <format>
#include <ctxtcall.h>
#include <wil/wrl.h>
#include <wil/result_originate.h>
#include "interface_traits.h"

namespace wrl_helpers
{
	inline Microsoft::WRL::Wrappers::HString initialise_hstring(const std::wstring_view &runtime_class)
	{
		HRESULT hr = S_OK;
		Microsoft::WRL::Wrappers::HString hs;
		hr = hs.Set(runtime_class.data());

		RoOriginateErrorW(hr, 0, L"Failed to set the runtime class name");
		THROW_IF_FAILED(hr);

		return hs;
	}

	template <typename Interface>
	inline auto activate_instance()
	{
		static_assert(interface_traits<Interface>::activatable);
		HRESULT hr = S_OK;
		auto runtime_class = initialise_hstring(interface_traits<Interface>::class_name);
		Microsoft::WRL::ComPtr<Interface> ret;
		hr = Windows::Foundation::ActivateInstance(runtime_class, ret.ReleaseAndGetAddressOf());
		if (FAILED(hr))
		{
			auto l_fmtstr = std::format(L"Failed to activate instance. Interface name {}, RuntimeClass name {}", interface_traits<Interface>::interface_name, interface_traits<Interface>::class_name);
			RoOriginateErrorW(hr, l_fmtstr.length(), l_fmtstr.c_str());
			THROW_IF_FAILED(hr);
		}

		return ret;
	}

	template <typename Interface>
	inline auto get_activation_factory()
	{
		HRESULT hr = S_OK;
		Microsoft::WRL::ComPtr<Interface> ret;
		auto runtime_class = initialise_hstring(factory_interface_traits<Interface>::class_name);
		hr = Windows::Foundation::GetActivationFactory(runtime_class, ret.ReleaseAndGetAddressOf());
		if (FAILED(hr))
		{
			auto l_fmtstr = std::format(L"Failed to get activation factory. Interface name: {}, RuntimeClass name: {}", factory_interface_traits<Interface>::interface_name, factory_interface_traits<Interface>::class_name);
			RoOriginateErrorW(hr, static_cast<UINT>(l_fmtstr.length()), l_fmtstr.c_str());
			THROW_IF_FAILED(hr);
		}

		return ret;
	}

	inline auto get_activation_factory(const std::wstring_view &class_name)
	{
		HRESULT hr = S_OK;
		Microsoft::WRL::ComPtr<IActivationFactory> ret;
		auto runtime_class = initialise_hstring(class_name);
		hr = Windows::Foundation::GetActivationFactory(runtime_class, ret.ReleaseAndGetAddressOf());
		if (FAILED(hr))
		{
			auto l_fmtstr = std::format(L"Failed to get activation factory. Interface name: IActivationFactory, RuntimeClass name: {}", class_name);
			RoOriginateErrorW(hr, static_cast<UINT>(l_fmtstr.length()), l_fmtstr.c_str());
			THROW_IF_FAILED(hr);
		}

		return ret;
	}

	template <typename OutInterface, typename InInterface>
	std::pair<Microsoft::WRL::ComPtr<OutInterface>, HRESULT> try_as(const Microsoft::WRL::ComPtr<InInterface> &ptr)
	{
		HRESULT hr = S_OK;
		Microsoft::WRL::ComPtr<OutInterface> out_ptr;
		hr = ptr.As(&out_ptr);

		return std::make_pair(std::move(out_ptr), hr);
	}
}
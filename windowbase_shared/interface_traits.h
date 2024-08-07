#pragma once

//It is fine if this only depends upon one parameter.
//The static assert being in the template is there
//to make the static assert depend upon a template
//parameter, so it only asserts after the template
//expansion.
template <typename Interface>
struct static_assert_helper
{
	static constexpr bool value = false;
};
//There are some interfaces that are not exclusive
//to a runtime class that may be used. Using the
//runtime class type as a template parameter allows
//for correct information.
template <typename Interface, typename RuntimeClass>
struct interface_traits
{
	static_assert(static_assert_helper<Interface>::value, "interface_traits is not specialised for this interface");
	//The layout for this is as follows.
	//Typename type, this must be the same as the Interface template parameter.
	//Typename base_type, this must be the default interface for the runtime class.
	//Typename class_type, this must be the same as the RuntimeClass template parameter.
	//Member class_name, this is the fully qualified name for the runtime class. Type is wstring_view.
	//Member interface_name, this is the fully qualified name for the interface. Type is wstring_view.
	//Member activatable, this indicates whether or not the runtime class can be activated. Type is bool.
};
//This is for the factory interfaces and the static
//interfaces.
//One important point to note, there is not always
//a listing for IActivationFactory when a runtime
//class is activatable. To give an example using
//Windows.Foundation.Uri, this runtime class has
//two constructors, but none of them are default.
//IActivationFactory::ActivateInstance corresponds
//to the default constructor.
//It is possible to query for IActivationFactory
//but ActivateInstance will return E_NOTIMPLEMENTED.
//IActivateInstance will only be available if the
//documentation states that a runtime class has
//a default constructor.
template <typename Interface, typename RuntimeClass>
struct factory_interface_traits
{
	static_assert(static_assert_helper<Interface>::value, "factory_interface_traits is not specialised for this interface");
	//The layout for this is as follows.
	//Typename type, this must be the same as the Interface template parameter.
	//Typename class_type, this must be the same as the RuntimeClass template parameter.
	//Member class_name, this is the fully qualified name for the runtime class. Type is wstring_view.
	//Member interface_name, this is the fully qualified name for the interface. Type is wstring_view.
};

template <size_t N>
inline constexpr std::wstring_view init_stringview(const wchar_t(&string_name)[N])
{
	return std::wstring_view{ string_name, ARRAYSIZE(string_name) };
}

#ifdef __windows2Efoundation_h__
template <>
struct interface_traits<ABI::Windows::Foundation::IUriRuntimeClass, ABI::Windows::Foundation::Uri>
{
	using type = ABI::Windows::Foundation::IUriRuntimeClass;
	using base_type = ABI::Windows::Foundation::IUriRuntimeClass;
	using class_type = ABI::Windows::Foundation::Uri;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Foundation_Uri) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Foundation_IUriRuntimeClass) };
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri, ABI::Windows::Foundation::Uri>
{
	using type = ABI::Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri;
	using base_type = ABI::Windows::Foundation::IUriRuntimeClass;
	using class_type = ABI::Windows::Foundation::Uri;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Foundation_Uri) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Foundation_IUriRuntimeClassWithAbsoluteCanonicalUri) };
	inline static constexpr bool activatable = false;
};

template <>
struct factory_interface_traits<ABI::Windows::Foundation::IUriRuntimeClassFactory, ABI::Windows::Foundation::Uri>
{
	using type = ABI::Windows::Foundation::IUriRuntimeClassFactory;
	using class_type = ABI::Windows::Foundation::Uri;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Foundation_Uri) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Foundation_IUriRuntimeClassFactory) };
};

template <>
struct factory_interface_traits<ABI::Windows::Foundation::IUriEscapeStatics, ABI::Windows::Foundation::Uri>
{
	using type = ABI::Windows::Foundation::IUriEscapeStatics;
	using class_type = ABI::Windows::Foundation::Uri;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Foundation_Uri) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Foundation_IUriEscapeStatics) };
};
#endif

#ifdef __windows2Esystem_h__
template <>
struct interface_traits<ABI::Windows::System::IDispatcherQueueController, ABI::Windows::System::DispatcherQueueController>
{
	using type = ABI::Windows::System::IDispatcherQueueController;
	using base_type = ABI::Windows::System::IDispatcherQueueController;
	using class_type = ABI::Windows::System::DispatcherQueueController;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_System_DispatcherQueueController) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_System_IDispatcherQueueController) };
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Windows::System::IDispatcherQueue, ABI::Windows::System::DispatcherQueue>
{
	using type = ABI::Windows::System::IDispatcherQueue;
	using base_type = ABI::Windows::System::IDispatcherQueue;
	using class_type = ABI::Windows::System::DispatcherQueue;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_System_DispatcherQueue) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_System_IDispatcherQueue) };
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Windows::System::IDispatcherQueue2, ABI::Windows::System::DispatcherQueue>
{
	using type = ABI::Windows::System::IDispatcherQueue2;
	using base_type = ABI::Windows::System::IDispatcherQueue;
	using class_type = ABI::Windows::System::DispatcherQueue;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_System_DispatcherQueue) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_System_IDispatcherQueue2) };
	inline static constexpr bool activatable = false;
};

template <>
struct factory_interface_traits<ABI::Windows::System::IDispatcherQueueControllerStatics, ABI::Windows::System::DispatcherQueueController>
{
	using type = ABI::Windows::System::IDispatcherQueueControllerStatics;
	using class_type = ABI::Windows::System::DispatcherQueueController;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_System_DispatcherQueueController) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_System_IDispatcherQueueControllerStatics) };
};

template <>
struct factory_interface_traits<ABI::Windows::System::IDispatcherQueueStatics, ABI::Windows::System::DispatcherQueue>
{
	using type = ABI::Windows::System::IDispatcherQueueStatics;
	using class_type = ABI::Windows::System::DispatcherQueue;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_System_DispatcherQueue) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_System_IDispatcherQueueStatics) };
};
#endif

#ifdef __windows2Eapplicationmodel_h__
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage2, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage2;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage2) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage3, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage3;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage3) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage4, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage4;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage4) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage5, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage5;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage5) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage6, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage6;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage6) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage7, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage7;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage7) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage8, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage8;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage8) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage9, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackage;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackage9) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackageWithMetadata, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackageWithMetadata;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackageWithMetadata) };
	inline static constexpr bool activatable = false;
};

template<>
struct factory_interface_traits<ABI::Windows::ApplicationModel::IPackageStatics, ABI::Windows::ApplicationModel::Package>
{
	using type = ABI::Windows::ApplicationModel::IPackageStatics;
	using class_type = ABI::Windows::ApplicationModel::Package;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Package) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackageStatics) };
};

template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackageId, ABI::Windows::ApplicationModel::PackageId>
{
	using type = ABI::Windows::ApplicationModel::IPackageId;
	using base_type = ABI::Windows::ApplicationModel::IPackageId;
	using class_type = ABI::Windows::ApplicationModel::PackageId;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_PackageId) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackageId) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackageIdWithMetadata, ABI::Windows::ApplicationModel::PackageId>
{
	using type = ABI::Windows::ApplicationModel::IPackageIdWithMetadata;
	using base_type = ABI::Windows::ApplicationModel::IPackageId;
	using class_type = ABI::Windows::ApplicationModel::PackageId;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_PackageId) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_IPackageIdWithMetadata) };
	inline static constexpr bool activatable = false;
};
#endif

#ifdef __windows2Eapplicationmodel2Ecore_h__
template<>
struct interface_traits<ABI::Windows::ApplicationModel::Core::IAppListEntry, ABI::Windows::ApplicationModel::Core::AppListEntry>
{
	using type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	using base_type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	using class_type = ABI::Windows::ApplicationModel::Core::AppListEntry;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::Core::IAppListEntry2, ABI::Windows::ApplicationModel::Core::AppListEntry>
{
	using type = ABI::Windows::ApplicationModel::Core::IAppListEntry2;
	using base_type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	using class_type = ABI::Windows::ApplicationModel::Core::AppListEntry;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry2) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::Core::IAppListEntry3, ABI::Windows::ApplicationModel::Core::AppListEntry>
{
	using type = ABI::Windows::ApplicationModel::Core::IAppListEntry3;
	using base_type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	using class_type = ABI::Windows::ApplicationModel::Core::AppListEntry;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry3) };
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::Core::IAppListEntry4, ABI::Windows::ApplicationModel::Core::AppListEntry>
{
	using type = ABI::Windows::ApplicationModel::Core::IAppListEntry4;
	using base_type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	using class_type = ABI::Windows::ApplicationModel::Core::AppListEntry;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry4) };
	inline static constexpr bool activatable = false;
};
#endif

#ifdef __windows2Emanagement2Edeployment_h__
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager2, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager2;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager2) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager3, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager3;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager3) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager4, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager4;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager4) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager5, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager5;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager5) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager6, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager6;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager6) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager7, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager7;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager7) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager8, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager8;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager8) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager9, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager9;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager9) };
	inline static constexpr bool activatable = true;
};
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager10, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager10;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Windows_Management_Deployment_IPackageManager10) };
	inline static constexpr bool activatable = true;
};
template <>
struct factory_interface_traits<IActivationFactory, ABI::Windows::Management::Deployment::PackageManager>
{
	using type = IActivationFactory;
	using class_type = ABI::Windows::Management::Deployment::PackageManager;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Windows_Management_Deployment_PackageManager) };
	inline static constexpr std::wstring_view interface_name = std::wstring_view(L"IActivationFactory", ARRAYSIZE(L"IActivationFactory"));
};
#endif

#ifdef __microsoft2Eui2Ewindowing_h__
template <>
struct interface_traits<ABI::Microsoft::UI::Windowing::IAppWindow, ABI::Microsoft::UI::Windowing::AppWindow>
{
	using type = ABI::Microsoft::UI::Windowing::IAppWindow;
	using base_type = ABI::Microsoft::UI::Windowing::IAppWindow;
	using class_type = ABI::Microsoft::UI::Windowing::AppWindow;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Windowing_AppWindow) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Windowing_IAppWindow) };
	inline static constexpr bool activatable = false;
};
template <>
struct interface_traits<ABI::Microsoft::UI::Windowing::IAppWindow2, ABI::Microsoft::UI::Windowing::AppWindow>
{
	using type = ABI::Microsoft::UI::Windowing::IAppWindow2;
	using base_type = ABI::Microsoft::UI::Windowing::IAppWindow;
	using class_type = ABI::Microsoft::UI::Windowing::AppWindow;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Windowing_AppWindow) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Windowing_IAppWindow2) };
	inline static constexpr bool activatable = false;
};

template <>
struct factory_interface_traits<ABI::Microsoft::UI::Windowing::IAppWindowStatics, ABI::Microsoft::UI::Windowing::AppWindow>
{
	using type = ABI::Microsoft::UI::Windowing::IAppWindowStatics;
	using class_type = ABI::Microsoft::UI::Windowing::AppWindow;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Windowing_AppWindow) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Windowing_IAppWindowStatics) };
};
#endif

#ifdef __microsoft2Eui2Edispatching_h__
template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueue, ABI::Microsoft::UI::Dispatching::DispatcherQueue>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueue;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueue;
	using class_type = ABI::Microsoft::UI::Dispatching::DispatcherQueue;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueue) };
	inline static constexpr bool activatable = false;
};
template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueue2, ABI::Microsoft::UI::Dispatching::DispatcherQueue>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueue2;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueue;
	using class_type = ABI::Microsoft::UI::Dispatching::DispatcherQueue;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueue2) };
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueController, ABI::Microsoft::UI::Dispatching::DispatcherQueueController>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueController;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueController;
	using class_type = ABI::Microsoft::UI::Dispatching::DispatcherQueueController;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueController) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueController) };
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs, ABI::Microsoft::UI::Dispatching::DispatcherQueueShutdownStartingEventArgs>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs;
	using class_type = ABI::Microsoft::UI::Dispatching::DispatcherQueueShutdownStartingEventArgs;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueShutdownStartingEventArgs) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueShutdownStartingEventArgs) };
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueTimer, ABI::Microsoft::UI::Dispatching::DispatcherQueueTimer>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueTimer;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueTimer;
	using class_type = ABI::Microsoft::UI::Dispatching::DispatcherQueueTimer;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueTimer) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueTimer) };
	inline static constexpr bool activatable = false;
};

template <>
struct factory_interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics, ABI::Microsoft::UI::Dispatching::DispatcherQueueController>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics;
	using class_type = ABI::Microsoft::UI::Dispatching::DispatcherQueueController;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueController) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueControllerStatics) };
};

template <>
struct factory_interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueStatics, ABI::Microsoft::UI::Dispatching::DispatcherQueue>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueStatics;
	using class_type = ABI::Microsoft::UI::Dispatching::DispatcherQueue;
	inline static constexpr std::wstring_view class_name{ init_stringview(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue) };
	inline static constexpr std::wstring_view interface_name{ init_stringview(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueStatics) };
};
#endif
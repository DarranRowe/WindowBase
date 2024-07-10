#pragma once

template <typename Interface>
struct static_assert_helper
{
	static constexpr bool value = false;
};

template <typename Interface>
struct interface_traits
{
	static_assert(static_assert_helper<Interface>::value, "interface_traits is not specialised for this interface");
};

template <typename Interface>
struct factory_interface_traits
{
	static_assert(static_assert_helper<Interface>::value, "factory_interface_traits is not specialised for this interface");
};

#ifdef __windows2Efoundation_h__
template <>
struct interface_traits<ABI::Windows::Foundation::IUriRuntimeClass>
{
	using type = ABI::Windows::Foundation::IUriRuntimeClass;
	using base_type = ABI::Windows::Foundation::IUriRuntimeClass;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Foundation_Uri, ARRAYSIZE(RuntimeClass_Windows_Foundation_Uri));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Foundation_IUriRuntimeClass, ARRAYSIZE(InterfaceName_Windows_Foundation_IUriRuntimeClass));
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>
{
	using type = ABI::Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri;
	using base_type = ABI::Windows::Foundation::IUriRuntimeClass;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Foundation_Uri, ARRAYSIZE(RuntimeClass_Windows_Foundation_Uri));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Foundation_IUriRuntimeClassWithAbsoluteCanonicalUri, ARRAYSIZE(InterfaceName_Windows_Foundation_IUriRuntimeClassWithAbsoluteCanonicalUri));
	inline static constexpr bool activatable = false;
};

template <>
struct factory_interface_traits<ABI::Windows::Foundation::IUriRuntimeClassFactory>
{
	using type = ABI::Windows::Foundation::IUriRuntimeClassFactory;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Foundation_Uri, ARRAYSIZE(RuntimeClass_Windows_Foundation_Uri));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Foundation_IUriRuntimeClassFactory, ARRAYSIZE(InterfaceName_Windows_Foundation_IUriRuntimeClassFactory));
};

template <>
struct factory_interface_traits<ABI::Windows::Foundation::IUriEscapeStatics>
{
	using type = ABI::Windows::Foundation::IUriEscapeStatics;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Foundation_Uri, ARRAYSIZE(RuntimeClass_Windows_Foundation_Uri));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Foundation_IUriEscapeStatics, ARRAYSIZE(InterfaceName_Windows_Foundation_IUriEscapeStatics));
};
#endif

#ifdef __windows2Esystem_h__
template <>
struct interface_traits<ABI::Windows::System::IDispatcherQueueController>
{
	using type = ABI::Windows::System::IDispatcherQueueController;
	using base_type = ABI::Windows::System::IDispatcherQueueController;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_System_DispatcherQueueController, ARRAYSIZE(RuntimeClass_Windows_System_DispatcherQueueController));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_System_IDispatcherQueueController, ARRAYSIZE(InterfaceName_Windows_System_IDispatcherQueueController));
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Windows::System::IDispatcherQueue>
{
	using type = ABI::Windows::System::IDispatcherQueue;
	using base_type = ABI::Windows::System::IDispatcherQueue;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_System_DispatcherQueue, ARRAYSIZE(RuntimeClass_Windows_System_DispatcherQueue));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_System_IDispatcherQueue, ARRAYSIZE(InterfaceName_Windows_System_IDispatcherQueue));
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Windows::System::IDispatcherQueue2>
{
	using type = ABI::Windows::System::IDispatcherQueue2;
	using base_type = ABI::Windows::System::IDispatcherQueue;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_System_DispatcherQueue, ARRAYSIZE(RuntimeClass_Windows_System_DispatcherQueue));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_System_IDispatcherQueue2, ARRAYSIZE(InterfaceName_Windows_System_IDispatcherQueue2));
	inline static constexpr bool activatable = false;
};

template <>
struct factory_interface_traits<ABI::Windows::System::IDispatcherQueueControllerStatics>
{
	using type = ABI::Windows::System::IDispatcherQueueControllerStatics;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_System_DispatcherQueueController, ARRAYSIZE(RuntimeClass_Windows_System_DispatcherQueueController));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_System_IDispatcherQueueControllerStatics, ARRAYSIZE(InterfaceName_Windows_System_IDispatcherQueueControllerStatics));
};

template <>
struct factory_interface_traits<ABI::Windows::System::IDispatcherQueueStatics>
{
	using type = ABI::Windows::System::IDispatcherQueueStatics;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_System_DispatcherQueue, ARRAYSIZE(RuntimeClass_Windows_System_DispatcherQueue));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_System_IDispatcherQueueStatics, ARRAYSIZE(InterfaceName_Windows_System_IDispatcherQueueStatics));
};
#endif

#ifdef __windows2Eapplicationmodel_h__
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage>
{
	using type = ABI::Windows::ApplicationModel::IPackage;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage2>
{
	using type = ABI::Windows::ApplicationModel::IPackage2;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage2, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage2));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage3>
{
	using type = ABI::Windows::ApplicationModel::IPackage3;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage3, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage3));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage4>
{
	using type = ABI::Windows::ApplicationModel::IPackage4;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage4, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage4));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage5>
{
	using type = ABI::Windows::ApplicationModel::IPackage5;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage5, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage5));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage6>
{
	using type = ABI::Windows::ApplicationModel::IPackage6;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage6, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage6));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage7>
{
	using type = ABI::Windows::ApplicationModel::IPackage7;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage7, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage7));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage8>
{
	using type = ABI::Windows::ApplicationModel::IPackage8;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage8, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage8));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackage9>
{
	using type = ABI::Windows::ApplicationModel::IPackage;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackage9, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackage9));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackageWithMetadata>
{
	using type = ABI::Windows::ApplicationModel::IPackageWithMetadata;
	using base_type = ABI::Windows::ApplicationModel::IPackage;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackageWithMetadata, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackageWithMetadata));
	inline static constexpr bool activatable = false;
};

template<>
struct factory_interface_traits<ABI::Windows::ApplicationModel::IPackageStatics>
{
	using type = ABI::Windows::ApplicationModel::IPackageStatics;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Package, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Package));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackageStatics, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackageStatics));
};

template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackageId>
{
	using type = ABI::Windows::ApplicationModel::IPackageId;
	using base_type = ABI::Windows::ApplicationModel::IPackageId;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_PackageId, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_PackageId));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackageId, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackageId));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::IPackageIdWithMetadata>
{
	using type = ABI::Windows::ApplicationModel::IPackageIdWithMetadata;
	using base_type = ABI::Windows::ApplicationModel::IPackageId;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_PackageId, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_PackageId));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_IPackageIdWithMetadata, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_IPackageIdWithMetadata));
	inline static constexpr bool activatable = false;
};
#endif

#ifdef __windows2Eapplicationmodel2Ecore_h__
template<>
struct interface_traits<ABI::Windows::ApplicationModel::Core::IAppListEntry>
{
	using type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	using base_type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::Core::IAppListEntry2>
{
	using type = ABI::Windows::ApplicationModel::Core::IAppListEntry2;
	using base_type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry2, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry2));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::Core::IAppListEntry3>
{
	using type = ABI::Windows::ApplicationModel::Core::IAppListEntry3;
	using base_type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry3, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry3));
	inline static constexpr bool activatable = false;
};
template<>
struct interface_traits<ABI::Windows::ApplicationModel::Core::IAppListEntry4>
{
	using type = ABI::Windows::ApplicationModel::Core::IAppListEntry4;
	using base_type = ABI::Windows::ApplicationModel::Core::IAppListEntry;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry, ARRAYSIZE(RuntimeClass_Windows_ApplicationModel_Core_AppListEntry));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry4, ARRAYSIZE(InterfaceName_Windows_ApplicationModel_Core_IAppListEntry4));
	inline static constexpr bool activatable = false;
};
#endif

#ifdef __windows2Emanagement2Edeployment_h__
template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager2>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager2;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager2, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager2));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager3>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager3;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager3, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager3));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager4>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager4;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager4, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager4));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager5>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager5;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager5, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager5));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager6>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager6;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager6, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager6));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager7>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager7;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager7, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager7));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager8>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager8;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager8, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager8));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager9>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager9;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager9, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager9));
	inline static constexpr bool activatable = true;
};

template <>
struct interface_traits<ABI::Windows::Management::Deployment::IPackageManager10>
{
	using type = ABI::Windows::Management::Deployment::IPackageManager10;
	using base_type = ABI::Windows::Management::Deployment::IPackageManager;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Windows_Management_Deployment_PackageManager, ARRAYSIZE(RuntimeClass_Windows_Management_Deployment_PackageManager));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Windows_Management_Deployment_IPackageManager10, ARRAYSIZE(InterfaceName_Windows_Management_Deployment_IPackageManager10));
	inline static constexpr bool activatable = true;
};
#endif

#ifdef __microsoft2Eui2Ewindowing_h__
template <>
struct interface_traits<ABI::Microsoft::UI::Windowing::IAppWindow>
{
	using type = ABI::Microsoft::UI::Windowing::IAppWindow;
	using base_type = ABI::Microsoft::UI::Windowing::IAppWindow;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Windowing_AppWindow, ARRAYSIZE(RuntimeClass_Microsoft_UI_Windowing_AppWindow));
	inline static constexpr bool activatable = false;
};
template <>
struct interface_traits<ABI::Microsoft::UI::Windowing::IAppWindow2>
{
	using type = ABI::Microsoft::UI::Windowing::IAppWindow2;
	using base_type = ABI::Microsoft::UI::Windowing::IAppWindow;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Windowing_AppWindow, ARRAYSIZE(RuntimeClass_Microsoft_UI_Windowing_AppWindow));
	inline static constexpr bool activatable = false;
};

template <>
struct factory_interface_traits<ABI::Microsoft::UI::Windowing::IAppWindowStatics>
{
	using type = ABI::Microsoft::UI::Windowing::IAppWindowStatics;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Windowing_AppWindow, ARRAYSIZE(RuntimeClass_Microsoft_UI_Windowing_AppWindow));
};
#endif

#ifdef __microsoft2Eui2Edispatching_h__
template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueue>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueue;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueue;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue, ARRAYSIZE(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueue, ARRAYSIZE(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueue));
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueue2>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueue2;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueue;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue, ARRAYSIZE(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueue2, ARRAYSIZE(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueue2));
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueController>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueController;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueController;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueController, ARRAYSIZE(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueController));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueController, ARRAYSIZE(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueController));
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueShutdownStartingEventArgs, ARRAYSIZE(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueShutdownStartingEventArgs));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueShutdownStartingEventArgs, ARRAYSIZE(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueShutdownStartingEventArgs));
	inline static constexpr bool activatable = false;
};

template <>
struct interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueTimer>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueTimer;
	using base_type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueTimer;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueTimer, ARRAYSIZE(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueTimer));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueTimer, ARRAYSIZE(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueTimer));
	inline static constexpr bool activatable = false;
};

template <>
struct factory_interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueController, ARRAYSIZE(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueueController));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueControllerStatics, ARRAYSIZE(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueControllerStatics));
};

template <>
struct factory_interface_traits<ABI::Microsoft::UI::Dispatching::IDispatcherQueueStatics>
{
	using type = ABI::Microsoft::UI::Dispatching::IDispatcherQueueStatics;
	inline static constexpr std::wstring_view class_name = std::wstring_view(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue, ARRAYSIZE(RuntimeClass_Microsoft_UI_Dispatching_DispatcherQueue));
	inline static constexpr std::wstring_view interface_name = std::wstring_view(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueStatics, ARRAYSIZE(InterfaceName_Microsoft_UI_Dispatching_IDispatcherQueueStatics));
};
#endif
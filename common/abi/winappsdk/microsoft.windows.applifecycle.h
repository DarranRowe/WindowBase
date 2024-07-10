
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif /*COM_NO_WINDOWS_H*/
#ifndef __microsoft2Ewindows2Eapplifecycle_h__
#define __microsoft2Ewindows2Eapplifecycle_h__
#ifndef __microsoft2Ewindows2Eapplifecycle_p_h__
#define __microsoft2Ewindows2Eapplifecycle_p_h__


#pragma once

//
// Deprecated attribute support
//

#pragma push_macro("DEPRECATED")
#undef DEPRECATED

#if !defined(DISABLE_WINRT_DEPRECATION)
#if defined(__cplusplus)
#if __cplusplus >= 201402
#define DEPRECATED(x) [[deprecated(x)]]
#define DEPRECATEDENUMERATOR(x) [[deprecated(x)]]
#elif defined(_MSC_VER)
#if _MSC_VER >= 1900
#define DEPRECATED(x) [[deprecated(x)]]
#define DEPRECATEDENUMERATOR(x) [[deprecated(x)]]
#else
#define DEPRECATED(x) __declspec(deprecated(x))
#define DEPRECATEDENUMERATOR(x)
#endif // _MSC_VER >= 1900
#else // Not Standard C++ or MSVC, ignore the construct.
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif  // C++ deprecation
#else // C - disable deprecation
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif
#else // Deprecation is disabled
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif  /* DEPRECATED */

// Disable Deprecation for this header, MIDL verifies that cross-type access is acceptable
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#pragma warning(push)
#pragma warning(disable: 4996)
#endif

// Ensure that the setting of the /ns_prefix command line switch is consistent for all headers.
// If you get an error from the compiler indicating "warning C4005: 'CHECK_NS_PREFIX_STATE': macro redefinition", this
// indicates that you have included two different headers with different settings for the /ns_prefix MIDL command line switch
#if !defined(DISABLE_NS_PREFIX_CHECKS)
#define CHECK_NS_PREFIX_STATE "always"
#endif // !defined(DISABLE_NS_PREFIX_CHECKS)


#pragma push_macro("MIDL_CONST_ID")
#undef MIDL_CONST_ID
#define MIDL_CONST_ID const __declspec(selectany)


//  API Contract Inclusion Definitions
#if !defined(SPECIFIC_API_CONTRACT_DEFINITIONS)
#if !defined(MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION)
#define MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION 0x20000
#endif // defined(MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATEDEVENTSCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATEDEVENTSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATEDEVENTSCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATIONCAMERASETTINGSCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATIONCAMERASETTINGSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATIONCAMERASETTINGSCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_CONTACTACTIVATEDEVENTSCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_ACTIVATION_CONTACTACTIVATEDEVENTSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_CONTACTACTIVATEDEVENTSCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_WEBUISEARCHACTIVATEDEVENTSCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_ACTIVATION_WEBUISEARCHACTIVATEDEVENTSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_WEBUISEARCHACTIVATEDEVENTSCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_BACKGROUND_BACKGROUNDALARMAPPLICATIONCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_BACKGROUND_BACKGROUNDALARMAPPLICATIONCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_BACKGROUND_BACKGROUNDALARMAPPLICATIONCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_CALLSBACKGROUNDCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_CALLSBACKGROUNDCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_CALLSBACKGROUNDCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION 0x70000
#endif // defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSVOIPCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_CALLS_CALLSVOIPCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSVOIPCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_CALLS_LOCKSCREENCALLCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_CALLS_LOCKSCREENCALLCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_CALLS_LOCKSCREENCALLCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_COMMUNICATIONBLOCKING_COMMUNICATIONBLOCKINGCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_COMMUNICATIONBLOCKING_COMMUNICATIONBLOCKINGCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_APPLICATIONMODEL_COMMUNICATIONBLOCKING_COMMUNICATIONBLOCKINGCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_SEARCH_SEARCHCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_SEARCH_SEARCHCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_SEARCH_SEARCHCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION 0x30000
#endif // defined(WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_WALLET_WALLETCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_WALLET_WALLETCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_APPLICATIONMODEL_WALLET_WALLETCONTRACT_VERSION)

#if !defined(WINDOWS_DEVICES_PRINTERS_EXTENSIONS_EXTENSIONSCONTRACT_VERSION)
#define WINDOWS_DEVICES_PRINTERS_EXTENSIONS_EXTENSIONSCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_DEVICES_PRINTERS_EXTENSIONS_EXTENSIONSCONTRACT_VERSION)

#if !defined(WINDOWS_DEVICES_SMARTCARDS_SMARTCARDBACKGROUNDTRIGGERCONTRACT_VERSION)
#define WINDOWS_DEVICES_SMARTCARDS_SMARTCARDBACKGROUNDTRIGGERCONTRACT_VERSION 0x30000
#endif // defined(WINDOWS_DEVICES_SMARTCARDS_SMARTCARDBACKGROUNDTRIGGERCONTRACT_VERSION)

#if !defined(WINDOWS_DEVICES_SMARTCARDS_SMARTCARDEMULATORCONTRACT_VERSION)
#define WINDOWS_DEVICES_SMARTCARDS_SMARTCARDEMULATORCONTRACT_VERSION 0x60000
#endif // defined(WINDOWS_DEVICES_SMARTCARDS_SMARTCARDEMULATORCONTRACT_VERSION)

#if !defined(WINDOWS_DEVICES_SMS_LEGACYSMSAPICONTRACT_VERSION)
#define WINDOWS_DEVICES_SMS_LEGACYSMSAPICONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_DEVICES_SMS_LEGACYSMSAPICONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xf0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#if !defined(WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION)
#define WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION)

#if !defined(WINDOWS_GLOBALIZATION_GLOBALIZATIONJAPANESEPHONETICANALYZERCONTRACT_VERSION)
#define WINDOWS_GLOBALIZATION_GLOBALIZATIONJAPANESEPHONETICANALYZERCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_GLOBALIZATION_GLOBALIZATIONJAPANESEPHONETICANALYZERCONTRACT_VERSION)

#if !defined(WINDOWS_MEDIA_CAPTURE_APPBROADCASTCONTRACT_VERSION)
#define WINDOWS_MEDIA_CAPTURE_APPBROADCASTCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_MEDIA_CAPTURE_APPBROADCASTCONTRACT_VERSION)

#if !defined(WINDOWS_MEDIA_CAPTURE_APPCAPTURECONTRACT_VERSION)
#define WINDOWS_MEDIA_CAPTURE_APPCAPTURECONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_MEDIA_CAPTURE_APPCAPTURECONTRACT_VERSION)

#if !defined(WINDOWS_MEDIA_CAPTURE_APPCAPTUREMETADATACONTRACT_VERSION)
#define WINDOWS_MEDIA_CAPTURE_APPCAPTUREMETADATACONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_MEDIA_CAPTURE_APPCAPTUREMETADATACONTRACT_VERSION)

#if !defined(WINDOWS_MEDIA_CAPTURE_CAMERACAPTUREUICONTRACT_VERSION)
#define WINDOWS_MEDIA_CAPTURE_CAMERACAPTUREUICONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_MEDIA_CAPTURE_CAMERACAPTUREUICONTRACT_VERSION)

#if !defined(WINDOWS_MEDIA_CAPTURE_GAMEBARCONTRACT_VERSION)
#define WINDOWS_MEDIA_CAPTURE_GAMEBARCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_MEDIA_CAPTURE_GAMEBARCONTRACT_VERSION)

#if !defined(WINDOWS_MEDIA_DEVICES_CALLCONTROLCONTRACT_VERSION)
#define WINDOWS_MEDIA_DEVICES_CALLCONTROLCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_MEDIA_DEVICES_CALLCONTROLCONTRACT_VERSION)

#if !defined(WINDOWS_MEDIA_MEDIACONTROLCONTRACT_VERSION)
#define WINDOWS_MEDIA_MEDIACONTROLCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_MEDIA_MEDIACONTROLCONTRACT_VERSION)

#if !defined(WINDOWS_MEDIA_PROTECTION_PROTECTIONRENEWALCONTRACT_VERSION)
#define WINDOWS_MEDIA_PROTECTION_PROTECTIONRENEWALCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_MEDIA_PROTECTION_PROTECTIONRENEWALCONTRACT_VERSION)

#if !defined(WINDOWS_NETWORKING_CONNECTIVITY_WWANCONTRACT_VERSION)
#define WINDOWS_NETWORKING_CONNECTIVITY_WWANCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_NETWORKING_CONNECTIVITY_WWANCONTRACT_VERSION)

#if !defined(WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION)
#define WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION 0x30000
#endif // defined(WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION)

#if !defined(WINDOWS_PHONE_PHONECONTRACT_VERSION)
#define WINDOWS_PHONE_PHONECONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_PHONE_PHONECONTRACT_VERSION)

#if !defined(WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION)
#define WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION)

#if !defined(WINDOWS_SECURITY_ENTERPRISEDATA_ENTERPRISEDATACONTRACT_VERSION)
#define WINDOWS_SECURITY_ENTERPRISEDATA_ENTERPRISEDATACONTRACT_VERSION 0x50000
#endif // defined(WINDOWS_SECURITY_ENTERPRISEDATA_ENTERPRISEDATACONTRACT_VERSION)

#if !defined(WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION)
#define WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION 0x70000
#endif // defined(WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION)

#if !defined(WINDOWS_SYSTEM_SYSTEMMANAGEMENTCONTRACT_VERSION)
#define WINDOWS_SYSTEM_SYSTEMMANAGEMENTCONTRACT_VERSION 0x70000
#endif // defined(WINDOWS_SYSTEM_SYSTEMMANAGEMENTCONTRACT_VERSION)

#if !defined(WINDOWS_UI_CORE_COREWINDOWDIALOGSCONTRACT_VERSION)
#define WINDOWS_UI_CORE_COREWINDOWDIALOGSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_UI_CORE_COREWINDOWDIALOGSCONTRACT_VERSION)

#if !defined(WINDOWS_UI_VIEWMANAGEMENT_VIEWMANAGEMENTVIEWSCALINGCONTRACT_VERSION)
#define WINDOWS_UI_VIEWMANAGEMENT_VIEWMANAGEMENTVIEWSCALINGCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_UI_VIEWMANAGEMENT_VIEWMANAGEMENTVIEWSCALINGCONTRACT_VERSION)

#if !defined(WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION)
#define WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.ApplicationModel.Core.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                interface IActivationRegistrationManagerStatics;
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics ABI::Microsoft::Windows::AppLifecycle::IActivationRegistrationManagerStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                interface IAppActivationArguments;
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments ABI::Microsoft::Windows::AppLifecycle::IAppActivationArguments

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                interface IAppInstance;
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance ABI::Microsoft::Windows::AppLifecycle::IAppInstance

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                interface IAppInstanceStatics;
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics ABI::Microsoft::Windows::AppLifecycle::IAppInstanceStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                interface IAppInstanceStatics2;
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 ABI::Microsoft::Windows::AppLifecycle::IAppInstanceStatics2

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                class AppInstance;
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE
#define DEF___FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("58c4b850-cfd3-54c7-9568-cf76a017afae"))
IIterator<ABI::Microsoft::Windows::AppLifecycle::AppInstance*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::AppLifecycle::AppInstance*, ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<Microsoft.Windows.AppLifecycle.AppInstance>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Microsoft::Windows::AppLifecycle::AppInstance*> __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t;
#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance ABI::Windows::Foundation::Collections::__FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance ABI::Windows::Foundation::Collections::IIterator<ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>
//#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t ABI::Windows::Foundation::Collections::IIterator<ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE */


#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE
#define DEF___FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("46dd4ef2-c3a5-5a9f-b72d-8f0836be424a"))
IIterable<ABI::Microsoft::Windows::AppLifecycle::AppInstance*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::AppLifecycle::AppInstance*, ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<Microsoft.Windows.AppLifecycle.AppInstance>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Microsoft::Windows::AppLifecycle::AppInstance*> __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t;
#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance ABI::Windows::Foundation::Collections::__FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance ABI::Windows::Foundation::Collections::IIterable<ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>
//#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t ABI::Windows::Foundation::Collections::IIterable<ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE */


#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE
#define DEF___FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("1520072b-d6f2-5a95-988d-e6c4a6eb66a4"))
IVectorView<ABI::Microsoft::Windows::AppLifecycle::AppInstance*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::AppLifecycle::AppInstance*, ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Microsoft.Windows.AppLifecycle.AppInstance>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Microsoft::Windows::AppLifecycle::AppInstance*> __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t;
#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance ABI::Windows::Foundation::Collections::__FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance ABI::Windows::Foundation::Collections::IVectorView<ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>
//#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t ABI::Windows::Foundation::Collections::IVectorView<ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE */


#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE
#define DEF___FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f37e92bb-b953-5d1e-ae0b-15e49c194c98"))
IVector<ABI::Microsoft::Windows::AppLifecycle::AppInstance*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::AppLifecycle::AppInstance*, ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVector`1<Microsoft.Windows.AppLifecycle.AppInstance>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Microsoft::Windows::AppLifecycle::AppInstance*> __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t;
#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance ABI::Windows::Foundation::Collections::__FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance ABI::Windows::Foundation::Collections::IVector<ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>
//#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_t ABI::Windows::Foundation::Collections::IVector<ABI::Microsoft::Windows::AppLifecycle::IAppInstance*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_USE */


#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                class AppActivationArguments;
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_USE
#define DEF___FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("37d74b33-9510-5748-b33d-4676ee2b48a7"))
IEventHandler<ABI::Microsoft::Windows::AppLifecycle::AppActivationArguments*> : IEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::AppLifecycle::AppActivationArguments*, ABI::Microsoft::Windows::AppLifecycle::IAppActivationArguments*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.EventHandler`1<Microsoft.Windows.AppLifecycle.AppActivationArguments>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IEventHandler<ABI::Microsoft::Windows::AppLifecycle::AppActivationArguments*> __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_t;
#define __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments ABI::Windows::Foundation::__FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments ABI::Windows::Foundation::IEventHandler<ABI::Microsoft::Windows::AppLifecycle::IAppActivationArguments*>
//#define __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_t ABI::Windows::Foundation::IEventHandler<ABI::Microsoft::Windows::AppLifecycle::IAppActivationArguments*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_USE */


#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000



namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Core {
                
                typedef enum AppRestartFailureReason : int AppRestartFailureReason;
                
            } /* Core */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */




#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IAsyncAction;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIAsyncAction ABI::Windows::Foundation::IAsyncAction

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__





namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                
                typedef enum ExtendedActivationKind : int ExtendedActivationKind;
                
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


















/*
 *
 * Struct Microsoft.Windows.AppLifecycle.ExtendedActivationKind
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                /* [v1_enum, contract] */
                enum ExtendedActivationKind : int
                {
                    ExtendedActivationKind_Launch = 0,
                    ExtendedActivationKind_Search = 1,
                    ExtendedActivationKind_ShareTarget = 2,
                    ExtendedActivationKind_File = 3,
                    ExtendedActivationKind_Protocol = 4,
                    ExtendedActivationKind_FileOpenPicker = 5,
                    ExtendedActivationKind_FileSavePicker = 6,
                    ExtendedActivationKind_CachedFileUpdater = 7,
                    ExtendedActivationKind_ContactPicker = 8,
                    ExtendedActivationKind_Device = 9,
                    ExtendedActivationKind_PrintTaskSettings = 10,
                    ExtendedActivationKind_CameraSettings = 11,
                    ExtendedActivationKind_RestrictedLaunch = 12,
                    ExtendedActivationKind_AppointmentsProvider = 13,
                    ExtendedActivationKind_Contact = 14,
                    ExtendedActivationKind_LockScreenCall = 15,
                    ExtendedActivationKind_VoiceCommand = 16,
                    ExtendedActivationKind_LockScreen = 17,
                    ExtendedActivationKind_PickerReturned = 1000,
                    ExtendedActivationKind_WalletAction = 1001,
                    ExtendedActivationKind_PickFileContinuation = 1002,
                    ExtendedActivationKind_PickSaveFileContinuation = 1003,
                    ExtendedActivationKind_PickFolderContinuation = 1004,
                    ExtendedActivationKind_WebAuthenticationBrokerContinuation = 1005,
                    ExtendedActivationKind_WebAccountProvider = 1006,
                    ExtendedActivationKind_ComponentUI = 1007,
                    ExtendedActivationKind_ProtocolForResults = 1009,
                    ExtendedActivationKind_ToastNotification = 1010,
                    ExtendedActivationKind_Print3DWorkflow = 1011,
                    ExtendedActivationKind_DialReceiver = 1012,
                    ExtendedActivationKind_DevicePairing = 1013,
                    ExtendedActivationKind_UserDataAccountsProvider = 1014,
                    ExtendedActivationKind_FilePickerExperience = 1015,
                    ExtendedActivationKind_LockScreenComponent = 1016,
                    ExtendedActivationKind_ContactPanel = 1017,
                    ExtendedActivationKind_PrintWorkflowForegroundTask = 1018,
                    ExtendedActivationKind_GameUIProvider = 1019,
                    ExtendedActivationKind_StartupTask = 1020,
                    ExtendedActivationKind_CommandLineLaunch = 1021,
                    ExtendedActivationKind_BarcodeScannerProvider = 1022,
                    ExtendedActivationKind_PrintSupportJobUI = 1023,
                    ExtendedActivationKind_PrintSupportSettingsUI = 1024,
                    ExtendedActivationKind_PhoneCallActivation = 1025,
                    ExtendedActivationKind_VpnForeground = 1026,
                    ExtendedActivationKind_Push = 5000,
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x20000
                    
                    ExtendedActivationKind_AppNotification = 5001,
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x20000
                    
                };
                
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IActivationRegistrationManagerStatics
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.ActivationRegistrationManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IActivationRegistrationManagerStatics[] = L"Microsoft.Windows.AppLifecycle.IActivationRegistrationManagerStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                /* [object, uuid("5AC4E92E-017B-5D68-8198-F68636AB99D3"), exclusiveto, contract] */
                MIDL_INTERFACE("5AC4E92E-017B-5D68-8198-F68636AB99D3")
                IActivationRegistrationManagerStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE RegisterForFileTypeActivation(
                        /* [in] */UINT32 __supportedFileTypesSize,
                        /* [size_is(__supportedFileTypesSize), in] */HSTRING * supportedFileTypes,
                        /* [in] */HSTRING logo,
                        /* [in] */HSTRING displayName,
                        /* [in] */UINT32 __supportedVerbsSize,
                        /* [size_is(__supportedVerbsSize), in] */HSTRING * supportedVerbs,
                        /* [in] */HSTRING exePath
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterForProtocolActivation(
                        /* [in] */HSTRING scheme,
                        /* [in] */HSTRING logo,
                        /* [in] */HSTRING displayName,
                        /* [in] */HSTRING exePath
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterForStartupActivation(
                        /* [in] */HSTRING taskId,
                        /* [in] */HSTRING exePath
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE UnregisterForFileTypeActivation(
                        /* [in] */UINT32 __fileTypesSize,
                        /* [size_is(__fileTypesSize), in] */HSTRING * fileTypes,
                        /* [in] */HSTRING exePath
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE UnregisterForProtocolActivation(
                        /* [in] */HSTRING scheme,
                        /* [in] */HSTRING exePath
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE UnregisterForStartupActivation(
                        /* [in] */HSTRING taskId
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IActivationRegistrationManagerStatics=_uuidof(IActivationRegistrationManagerStatics);
                
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IAppActivationArguments
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.AppActivationArguments
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IAppActivationArguments[] = L"Microsoft.Windows.AppLifecycle.IAppActivationArguments";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                /* [object, uuid("14F99EAF-1580-5062-BDC8-D5D1C31138FB"), exclusiveto, contract] */
                MIDL_INTERFACE("14F99EAF-1580-5062-BDC8-D5D1C31138FB")
                IAppActivationArguments : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Kind(
                        /* [retval, out] */ABI::Microsoft::Windows::AppLifecycle::ExtendedActivationKind * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Data(
                        /* [retval, out] */IInspectable * * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IAppActivationArguments=_uuidof(IAppActivationArguments);
                
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IAppInstance
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.AppInstance
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IAppInstance[] = L"Microsoft.Windows.AppLifecycle.IAppInstance";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                /* [object, uuid("75766AE4-0239-5A26-B9DA-D5BFC75A4866"), exclusiveto, contract] */
                MIDL_INTERFACE("75766AE4-0239-5A26-B9DA-D5BFC75A4866")
                IAppInstance : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE UnregisterKey(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RedirectActivationToAsync(
                        /* [in] */ABI::Microsoft::Windows::AppLifecycle::IAppActivationArguments * args,
                        /* [retval, out] */ABI::Windows::Foundation::IAsyncAction * * operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetActivatedEventArgs(
                        /* [retval, out] */ABI::Microsoft::Windows::AppLifecycle::IAppActivationArguments * * result
                        ) = 0;
                    /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_Activated(
                        /* [in] */__FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments * handler,
                        /* [retval, out] */EventRegistrationToken * token
                        ) = 0;
                    /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_Activated(
                        /* [in] */EventRegistrationToken token
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Key(
                        /* [retval, out] */HSTRING * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsCurrent(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ProcessId(
                        /* [retval, out] */UINT32 * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IAppInstance=_uuidof(IAppInstance);
                
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IAppInstanceStatics
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.AppInstance
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IAppInstanceStatics[] = L"Microsoft.Windows.AppLifecycle.IAppInstanceStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                /* [object, uuid("4F414B25-8330-5A9B-BBC1-8229D479649D"), exclusiveto, contract] */
                MIDL_INTERFACE("4F414B25-8330-5A9B-BBC1-8229D479649D")
                IAppInstanceStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetCurrent(
                        /* [retval, out] */ABI::Microsoft::Windows::AppLifecycle::IAppInstance * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetInstances(
                        /* [retval, out] */__FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindOrRegisterForKey(
                        /* [in] */HSTRING key,
                        /* [retval, out] */ABI::Microsoft::Windows::AppLifecycle::IAppInstance * * result
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IAppInstanceStatics=_uuidof(IAppInstanceStatics);
                
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IAppInstanceStatics2
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.AppInstance
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IAppInstanceStatics2[] = L"Microsoft.Windows.AppLifecycle.IAppInstanceStatics2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppLifecycle {
                /* [object, uuid("FE9F1885-7160-5397-BA9B-5890B24FDC04"), exclusiveto, contract] */
                MIDL_INTERFACE("FE9F1885-7160-5397-BA9B-5890B24FDC04")
                IAppInstanceStatics2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Restart(
                        /* [in] */HSTRING arguments,
                        /* [retval, out] */ABI::Windows::ApplicationModel::Core::AppRestartFailureReason * result
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IAppInstanceStatics2=_uuidof(IAppInstanceStatics2);
                
            } /* AppLifecycle */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.AppLifecycle.ActivationRegistrationManager
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.AppLifecycle.IActivationRegistrationManagerStatics interface starting with version 1.0 of the Microsoft.Windows.AppLifecycle.AppLifecycleContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_AppLifecycle_ActivationRegistrationManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppLifecycle_ActivationRegistrationManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppLifecycle_ActivationRegistrationManager[] = L"Microsoft.Windows.AppLifecycle.ActivationRegistrationManager";
#endif
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppLifecycle.AppActivationArguments
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppLifecycle.IAppActivationArguments ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppLifecycle_AppActivationArguments_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppLifecycle_AppActivationArguments_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppLifecycle_AppActivationArguments[] = L"Microsoft.Windows.AppLifecycle.AppActivationArguments";
#endif
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppLifecycle.AppInstance
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.AppLifecycle.IAppInstanceStatics2 interface starting with version 2.0 of the Microsoft.Windows.AppLifecycle.AppLifecycleContract API contract
 *   Static Methods exist on the Microsoft.Windows.AppLifecycle.IAppInstanceStatics interface starting with version 1.0 of the Microsoft.Windows.AppLifecycle.AppLifecycleContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppLifecycle.IAppInstance ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppLifecycle_AppInstance_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppLifecycle_AppInstance_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppLifecycle_AppInstance[] = L"Microsoft.Windows.AppLifecycle.AppInstance";
#endif
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000




#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__)
#define ____FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance;

typedef struct __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [retval][out] */ __RPC__out __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl;

interface __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance
{
    CONST_VTBL struct __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__)
#define ____FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance;

typedef  struct __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_Microsoft__CWindows__CAppLifecycle__CAppInstance **first);

    END_INTERFACE
} __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl;

interface __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance
{
    CONST_VTBL struct __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance;

typedef struct __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);

    ULONG ( STDMETHODCALLTYPE *Release )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
                                            /* [out] */ __RPC__out ULONG *iidCount,
                                            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )( 
                                         __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
                                         /* [in] */ unsigned int index,
                                         /* [retval][out] */ __RPC__out __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * *item);

        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
            /* [retval][out] */ __RPC__out unsigned int *size);

        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
                                               __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
            /* [in] */ __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * item,
            /* [out] */ __RPC__out unsigned int *index,
            /* [retval][out] */ __RPC__out boolean *found);

        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
                                               __RPC__in __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * *items,
            /* [retval][out] */ __RPC__out unsigned int *actual);

        END_INTERFACE
} __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl;

interface __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance
{
    CONST_VTBL struct __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#endif /* COBJMACROS */



#endif // ____FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__)
#define ____FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__

typedef interface __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance;

typedef struct __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ unsigned int index,
        /* [retval][out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * *item);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
        __RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [retval][out] */ __RPC__out unsigned int *size);

    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [retval][out] */ __RPC__deref_out_opt __FIVectorView_1_Microsoft__CWindows__CAppLifecycle__CAppInstance **view);

    HRESULT ( STDMETHODCALLTYPE *IndexOf )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * item,
        /* [out] */ __RPC__out unsigned int *index,
        /* [retval][out] */ __RPC__out boolean *found);

    HRESULT ( STDMETHODCALLTYPE *SetAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * item);

    HRESULT ( STDMETHODCALLTYPE *InsertAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * item);

    HRESULT ( STDMETHODCALLTYPE *RemoveAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [in] */ unsigned int index);
    HRESULT ( STDMETHODCALLTYPE *Append )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This, /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * item);
    HRESULT ( STDMETHODCALLTYPE *RemoveAtEnd )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ unsigned int startIndex,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    HRESULT ( STDMETHODCALLTYPE *ReplaceAll )(__RPC__in __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * This,
        /* [in] */ unsigned int count,
        /* [size_is][in] */ __RPC__in_ecount_full(count) __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * *value);

    END_INTERFACE
} __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl;

interface __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance
{
    CONST_VTBL struct __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstanceVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_SetAt(This,index,item)	\
    ( (This)->lpVtbl -> SetAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_InsertAt(This,index,item)	\
    ( (This)->lpVtbl -> InsertAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_RemoveAt(This,index)	\
    ( (This)->lpVtbl -> RemoveAt(This,index) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_Append(This,item)	\
    ( (This)->lpVtbl -> Append(This,item) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_RemoveAtEnd(This)	\
    ( (This)->lpVtbl -> RemoveAtEnd(This) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#define __FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_ReplaceAll(This,count,value)	\
    ( (This)->lpVtbl -> ReplaceAll(This,count,value) ) 

#endif /* COBJMACROS */



#endif // ____FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_INTERFACE_DEFINED__)
#define ____FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_INTERFACE_DEFINED__

typedef interface __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments;

typedef struct __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArgumentsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments * This,/* [in] */ __RPC__in_opt IInspectable *sender,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * *e);
    END_INTERFACE
} __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArgumentsVtbl;

interface __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments
{
    CONST_VTBL struct __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArgumentsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_QueryInterface(This,riid,ppvObject)	\
        ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_AddRef(This)	\
        ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_Release(This)	\
        ( (This)->lpVtbl -> Release(This) ) 

#define __FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_Invoke(This,sender,e)	\
        ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */


#endif // ____FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000



typedef enum __x_ABI_CWindows_CApplicationModel_CCore_CAppRestartFailureReason __x_ABI_CWindows_CApplicationModel_CCore_CAppRestartFailureReason;




#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIAsyncAction __x_ABI_CWindows_CFoundation_CIAsyncAction;

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__






typedef enum __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CExtendedActivationKind __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CExtendedActivationKind;


















/*
 *
 * Struct Microsoft.Windows.AppLifecycle.ExtendedActivationKind
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CExtendedActivationKind
{
    ExtendedActivationKind_Launch = 0,
    ExtendedActivationKind_Search = 1,
    ExtendedActivationKind_ShareTarget = 2,
    ExtendedActivationKind_File = 3,
    ExtendedActivationKind_Protocol = 4,
    ExtendedActivationKind_FileOpenPicker = 5,
    ExtendedActivationKind_FileSavePicker = 6,
    ExtendedActivationKind_CachedFileUpdater = 7,
    ExtendedActivationKind_ContactPicker = 8,
    ExtendedActivationKind_Device = 9,
    ExtendedActivationKind_PrintTaskSettings = 10,
    ExtendedActivationKind_CameraSettings = 11,
    ExtendedActivationKind_RestrictedLaunch = 12,
    ExtendedActivationKind_AppointmentsProvider = 13,
    ExtendedActivationKind_Contact = 14,
    ExtendedActivationKind_LockScreenCall = 15,
    ExtendedActivationKind_VoiceCommand = 16,
    ExtendedActivationKind_LockScreen = 17,
    ExtendedActivationKind_PickerReturned = 1000,
    ExtendedActivationKind_WalletAction = 1001,
    ExtendedActivationKind_PickFileContinuation = 1002,
    ExtendedActivationKind_PickSaveFileContinuation = 1003,
    ExtendedActivationKind_PickFolderContinuation = 1004,
    ExtendedActivationKind_WebAuthenticationBrokerContinuation = 1005,
    ExtendedActivationKind_WebAccountProvider = 1006,
    ExtendedActivationKind_ComponentUI = 1007,
    ExtendedActivationKind_ProtocolForResults = 1009,
    ExtendedActivationKind_ToastNotification = 1010,
    ExtendedActivationKind_Print3DWorkflow = 1011,
    ExtendedActivationKind_DialReceiver = 1012,
    ExtendedActivationKind_DevicePairing = 1013,
    ExtendedActivationKind_UserDataAccountsProvider = 1014,
    ExtendedActivationKind_FilePickerExperience = 1015,
    ExtendedActivationKind_LockScreenComponent = 1016,
    ExtendedActivationKind_ContactPanel = 1017,
    ExtendedActivationKind_PrintWorkflowForegroundTask = 1018,
    ExtendedActivationKind_GameUIProvider = 1019,
    ExtendedActivationKind_StartupTask = 1020,
    ExtendedActivationKind_CommandLineLaunch = 1021,
    ExtendedActivationKind_BarcodeScannerProvider = 1022,
    ExtendedActivationKind_PrintSupportJobUI = 1023,
    ExtendedActivationKind_PrintSupportSettingsUI = 1024,
    ExtendedActivationKind_PhoneCallActivation = 1025,
    ExtendedActivationKind_VpnForeground = 1026,
    ExtendedActivationKind_Push = 5000,
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x20000
    
    ExtendedActivationKind_AppNotification = 5001,
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x20000
    
};
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IActivationRegistrationManagerStatics
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.ActivationRegistrationManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IActivationRegistrationManagerStatics[] = L"Microsoft.Windows.AppLifecycle.IActivationRegistrationManagerStatics";
/* [object, uuid("5AC4E92E-017B-5D68-8198-F68636AB99D3"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *RegisterForFileTypeActivation )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
        /* [in] */UINT32 __supportedFileTypesSize,
        /* [size_is(__supportedFileTypesSize), in] */HSTRING * supportedFileTypes,
        /* [in] */HSTRING logo,
        /* [in] */HSTRING displayName,
        /* [in] */UINT32 __supportedVerbsSize,
        /* [size_is(__supportedVerbsSize), in] */HSTRING * supportedVerbs,
        /* [in] */HSTRING exePath
        );
    HRESULT ( STDMETHODCALLTYPE *RegisterForProtocolActivation )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
        /* [in] */HSTRING scheme,
        /* [in] */HSTRING logo,
        /* [in] */HSTRING displayName,
        /* [in] */HSTRING exePath
        );
    HRESULT ( STDMETHODCALLTYPE *RegisterForStartupActivation )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
        /* [in] */HSTRING taskId,
        /* [in] */HSTRING exePath
        );
    HRESULT ( STDMETHODCALLTYPE *UnregisterForFileTypeActivation )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
        /* [in] */UINT32 __fileTypesSize,
        /* [size_is(__fileTypesSize), in] */HSTRING * fileTypes,
        /* [in] */HSTRING exePath
        );
    HRESULT ( STDMETHODCALLTYPE *UnregisterForProtocolActivation )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
        /* [in] */HSTRING scheme,
        /* [in] */HSTRING exePath
        );
    HRESULT ( STDMETHODCALLTYPE *UnregisterForStartupActivation )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics * This,
        /* [in] */HSTRING taskId
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_RegisterForFileTypeActivation(This,__supportedFileTypesSize,supportedFileTypes,logo,displayName,__supportedVerbsSize,supportedVerbs,exePath) \
    ( (This)->lpVtbl->RegisterForFileTypeActivation(This,__supportedFileTypesSize,supportedFileTypes,logo,displayName,__supportedVerbsSize,supportedVerbs,exePath) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_RegisterForProtocolActivation(This,scheme,logo,displayName,exePath) \
    ( (This)->lpVtbl->RegisterForProtocolActivation(This,scheme,logo,displayName,exePath) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_RegisterForStartupActivation(This,taskId,exePath) \
    ( (This)->lpVtbl->RegisterForStartupActivation(This,taskId,exePath) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_UnregisterForFileTypeActivation(This,__fileTypesSize,fileTypes,exePath) \
    ( (This)->lpVtbl->UnregisterForFileTypeActivation(This,__fileTypesSize,fileTypes,exePath) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_UnregisterForProtocolActivation(This,scheme,exePath) \
    ( (This)->lpVtbl->UnregisterForProtocolActivation(This,scheme,exePath) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_UnregisterForStartupActivation(This,taskId) \
    ( (This)->lpVtbl->UnregisterForStartupActivation(This,taskId) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIActivationRegistrationManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IAppActivationArguments
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.AppActivationArguments
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IAppActivationArguments[] = L"Microsoft.Windows.AppLifecycle.IAppActivationArguments";
/* [object, uuid("14F99EAF-1580-5062-BDC8-D5D1C31138FB"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArgumentsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Kind )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppLifecycle_CExtendedActivationKind * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Data )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * This,
        /* [retval, out] */IInspectable * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArgumentsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArgumentsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_get_Kind(This,value) \
    ( (This)->lpVtbl->get_Kind(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_get_Data(This,value) \
    ( (This)->lpVtbl->get_Data(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IAppInstance
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.AppInstance
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IAppInstance[] = L"Microsoft.Windows.AppLifecycle.IAppInstance";
/* [object, uuid("75766AE4-0239-5A26-B9DA-D5BFC75A4866"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *UnregisterKey )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This
        );
    HRESULT ( STDMETHODCALLTYPE *RedirectActivationToAsync )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * args,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIAsyncAction * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *GetActivatedEventArgs )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppActivationArguments * * result
        );
    /* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_Activated )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
        /* [in] */__FIEventHandler_1_Microsoft__CWindows__CAppLifecycle__CAppActivationArguments * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_Activated )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
        /* [in] */EventRegistrationToken token
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Key )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsCurrent )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ProcessId )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * This,
        /* [retval, out] */UINT32 * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_UnregisterKey(This) \
    ( (This)->lpVtbl->UnregisterKey(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_RedirectActivationToAsync(This,args,operation) \
    ( (This)->lpVtbl->RedirectActivationToAsync(This,args,operation) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_GetActivatedEventArgs(This,result) \
    ( (This)->lpVtbl->GetActivatedEventArgs(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_add_Activated(This,handler,token) \
    ( (This)->lpVtbl->add_Activated(This,handler,token) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_remove_Activated(This,token) \
    ( (This)->lpVtbl->remove_Activated(This,token) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_get_Key(This,value) \
    ( (This)->lpVtbl->get_Key(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_get_IsCurrent(This,value) \
    ( (This)->lpVtbl->get_IsCurrent(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_get_ProcessId(This,value) \
    ( (This)->lpVtbl->get_ProcessId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IAppInstanceStatics
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.AppInstance
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IAppInstanceStatics[] = L"Microsoft.Windows.AppLifecycle.IAppInstanceStatics";
/* [object, uuid("4F414B25-8330-5A9B-BBC1-8229D479649D"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetCurrent )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetInstances )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This,
        /* [retval, out] */__FIVector_1_Microsoft__CWindows__CAppLifecycle__CAppInstance * * result
        );
    HRESULT ( STDMETHODCALLTYPE *FindOrRegisterForKey )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics * This,
        /* [in] */HSTRING key,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstance * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_GetCurrent(This,result) \
    ( (This)->lpVtbl->GetCurrent(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_GetInstances(This,result) \
    ( (This)->lpVtbl->GetInstances(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_FindOrRegisterForKey(This,key,result) \
    ( (This)->lpVtbl->FindOrRegisterForKey(This,key,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppLifecycle.IAppInstanceStatics2
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppLifecycle.AppInstance
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppLifecycle_IAppInstanceStatics2[] = L"Microsoft.Windows.AppLifecycle.IAppInstanceStatics2";
/* [object, uuid("FE9F1885-7160-5397-BA9B-5890B24FDC04"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *Restart )(
        __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2 * This,
        /* [in] */HSTRING arguments,
        /* [retval, out] */__x_ABI_CWindows_CApplicationModel_CCore_CAppRestartFailureReason * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_Restart(This,arguments,result) \
    ( (This)->lpVtbl->Restart(This,arguments,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppLifecycle_CIAppInstanceStatics2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.AppLifecycle.ActivationRegistrationManager
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.AppLifecycle.IActivationRegistrationManagerStatics interface starting with version 1.0 of the Microsoft.Windows.AppLifecycle.AppLifecycleContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_AppLifecycle_ActivationRegistrationManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppLifecycle_ActivationRegistrationManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppLifecycle_ActivationRegistrationManager[] = L"Microsoft.Windows.AppLifecycle.ActivationRegistrationManager";
#endif
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppLifecycle.AppActivationArguments
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppLifecycle.IAppActivationArguments ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppLifecycle_AppActivationArguments_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppLifecycle_AppActivationArguments_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppLifecycle_AppActivationArguments[] = L"Microsoft.Windows.AppLifecycle.AppActivationArguments";
#endif
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppLifecycle.AppInstance
 *
 * Introduced to Microsoft.Windows.AppLifecycle.AppLifecycleContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.AppLifecycle.IAppInstanceStatics2 interface starting with version 2.0 of the Microsoft.Windows.AppLifecycle.AppLifecycleContract API contract
 *   Static Methods exist on the Microsoft.Windows.AppLifecycle.IAppInstanceStatics interface starting with version 1.0 of the Microsoft.Windows.AppLifecycle.AppLifecycleContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppLifecycle.IAppInstance ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppLifecycle_AppInstance_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppLifecycle_AppInstance_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppLifecycle_AppInstance[] = L"Microsoft.Windows.AppLifecycle.AppInstance";
#endif
#endif // MICROSOFT_WINDOWS_APPLIFECYCLE_APPLIFECYCLECONTRACT_VERSION >= 0x10000




#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Eapplifecycle_p_h__

#endif // __microsoft2Ewindows2Eapplifecycle_h__

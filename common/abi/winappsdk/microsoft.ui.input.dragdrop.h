
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
#ifndef __microsoft2Eui2Einput2Edragdrop_h__
#define __microsoft2Eui2Einput2Edragdrop_h__
#ifndef __microsoft2Eui2Einput2Edragdrop_p_h__
#define __microsoft2Eui2Einput2Edragdrop_p_h__


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
#if !defined(MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION)
#define MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION 0x10005
#endif // defined(MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION)

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
#include "Microsoft.Foundation.h"
#include "Microsoft.UI.Content.h"
#include "Microsoft.UI.Input.h"
#include "Windows.ApplicationModel.DataTransfer.h"
#include "Windows.Graphics.Imaging.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    interface IDragDropManager;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager ABI::Microsoft::UI::Input::DragDrop::IDragDropManager

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    interface IDragDropManagerStatics;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics ABI::Microsoft::UI::Input::DragDrop::IDragDropManagerStatics

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    interface IDragInfo;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo ABI::Microsoft::UI::Input::DragDrop::IDragInfo

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    interface IDragOperation;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation ABI::Microsoft::UI::Input::DragDrop::IDragOperation

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    interface IDragUIOverride;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride ABI::Microsoft::UI::Input::DragDrop::IDragUIOverride

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    interface IDropOperationTarget;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget ABI::Microsoft::UI::Input::DragDrop::IDropOperationTarget

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    interface IDropOperationTargetRequestedEventArgs;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs ABI::Microsoft::UI::Input::DragDrop::IDropOperationTargetRequestedEventArgs

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    class DragDropManager;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    class DropOperationTargetRequestedEventArgs;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef DEF___FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("0c4ab140-bf34-57d9-8136-169a83c0dcdb"))
ITypedEventHandler<ABI::Microsoft::UI::Input::DragDrop::DragDropManager*,ABI::Microsoft::UI::Input::DragDrop::DropOperationTargetRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Input::DragDrop::DragDropManager*, ABI::Microsoft::UI::Input::DragDrop::IDragDropManager*>,ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Input::DragDrop::DropOperationTargetRequestedEventArgs*, ABI::Microsoft::UI::Input::DragDrop::IDropOperationTargetRequestedEventArgs*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.TypedEventHandler`2<Microsoft.UI.Input.DragDrop.DragDropManager, Microsoft.UI.Input.DragDrop.DropOperationTargetRequestedEventArgs>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Microsoft::UI::Input::DragDrop::DragDropManager*,ABI::Microsoft::UI::Input::DragDrop::DropOperationTargetRequestedEventArgs*> __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_t;
#define __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Input::DragDrop::IDragDropManager*,ABI::Microsoft::UI::Input::DragDrop::IDropOperationTargetRequestedEventArgs*>
//#define __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_t ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Input::DragDrop::IDragDropManager*,ABI::Microsoft::UI::Input::DragDrop::IDropOperationTargetRequestedEventArgs*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_USE */


#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace DataTransfer {
                enum DataPackageOperation : unsigned int;
            } /* DataTransfer */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */


#ifndef DEF___FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_USE
#define DEF___FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("add21d46-17df-5a43-a685-3262fce84643"))
IAsyncOperationCompletedHandler<enum ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation> : IAsyncOperationCompletedHandler_impl<enum ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.ApplicationModel.DataTransfer.DataPackageOperation>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<enum ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation> __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_t;
#define __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>
//#define __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_t ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_USE */





#ifndef DEF___FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_USE
#define DEF___FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("8b98aea9-64f0-5672-b30e-dfd9c2e4f6fe"))
IAsyncOperation<enum ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation> : IAsyncOperation_impl<enum ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.ApplicationModel.DataTransfer.DataPackageOperation>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<enum ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation> __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_t;
#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation ABI::Windows::Foundation::__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>
//#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_t ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_USE */








namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentIsland;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentIsland;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland ABI::Microsoft::UI::Content::IContentIsland

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__





namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                class PointerPoint;
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                interface IPointerPoint;
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint ABI::Microsoft::UI::Input::IPointerPoint

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint_FWD_DEFINED__





namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace DataTransfer {
                class DataPackage;
            } /* DataTransfer */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace DataTransfer {
                interface IDataPackage;
            } /* DataTransfer */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage ABI::Windows::ApplicationModel::DataTransfer::IDataPackage

#endif // ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage_FWD_DEFINED__


namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace DataTransfer {
                
                typedef enum DataPackageOperation : unsigned int DataPackageOperation;
                
            } /* DataTransfer */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace DataTransfer {
                class DataPackageView;
            } /* DataTransfer */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace DataTransfer {
                interface IDataPackageView;
            } /* DataTransfer */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView

#endif // ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView_FWD_DEFINED__





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


#ifndef ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IClosable;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIClosable ABI::Windows::Foundation::IClosable

#endif // ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__


namespace ABI {
    namespace Windows {
        namespace Foundation {
            
            typedef struct Point Point;
            
        } /* Foundation */
    } /* Windows */
} /* ABI */



namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Imaging {
                class SoftwareBitmap;
            } /* Imaging */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Imaging {
                interface ISoftwareBitmap;
            } /* Imaging */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap ABI::Windows::Graphics::Imaging::ISoftwareBitmap

#endif // ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__





namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    
                    typedef enum DragDropModifiers : unsigned int DragDropModifiers;
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    
                    typedef enum DragUIContentMode : int DragUIContentMode;
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */









namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    class DragInfo;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    class DragOperation;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    class DragUIOverride;
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */













/*
 *
 * Struct Microsoft.UI.Input.DragDrop.DragDropModifiers
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [v1_enum, flags, contract] */
                    enum DragDropModifiers : unsigned int
                    {
                        DragDropModifiers_None = 0,
                        DragDropModifiers_Shift = 0x1,
                        DragDropModifiers_Control = 0x2,
                        DragDropModifiers_Alt = 0x4,
                        DragDropModifiers_LeftButton = 0x8,
                        DragDropModifiers_MiddleButton = 0x10,
                        DragDropModifiers_RightButton = 0x20,
                    };
                    
                    DEFINE_ENUM_FLAG_OPERATORS(DragDropModifiers)
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Struct Microsoft.UI.Input.DragDrop.DragUIContentMode
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [v1_enum, contract] */
                    enum DragUIContentMode : int
                    {
                        DragUIContentMode_Auto = 0,
                        DragUIContentMode_Deferred = 1,
                    };
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragDropManager
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragDropManager
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragDropManager[] = L"Microsoft.UI.Input.DragDrop.IDragDropManager";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [object, uuid("4FEA9EFC-B073-5FBE-9C95-A4113EF6393F"), exclusiveto, contract] */
                    MIDL_INTERFACE("4FEA9EFC-B073-5FBE-9C95-A4113EF6393F")
                    IDragDropManager : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AreConcurrentOperationsEnabled(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AreConcurrentOperationsEnabled(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_TargetRequested(
                            /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs * handler,
                            /* [retval, out] */EventRegistrationToken * token
                            ) = 0;
                        /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_TargetRequested(
                            /* [in] */EventRegistrationToken token
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDragDropManager=_uuidof(IDragDropManager);
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragDropManagerStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragDropManager
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragDropManagerStatics[] = L"Microsoft.UI.Input.DragDrop.IDragDropManagerStatics";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [object, uuid("5587C863-57D7-5D0F-8EA9-E5DCF06A0F83"), exclusiveto, contract] */
                    MIDL_INTERFACE("5587C863-57D7-5D0F-8EA9-E5DCF06A0F83")
                    IDragDropManagerStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetForIsland(
                            /* [in] */ABI::Microsoft::UI::Content::IContentIsland * content,
                            /* [retval, out] */ABI::Microsoft::UI::Input::DragDrop::IDragDropManager * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDragDropManagerStatics=_uuidof(IDragDropManagerStatics);
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragInfo
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragInfo
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragInfo[] = L"Microsoft.UI.Input.DragDrop.IDragInfo";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [object, uuid("7507D891-62A8-5A79-A880-AC7353D001EC"), exclusiveto, contract] */
                    MIDL_INTERFACE("7507D891-62A8-5A79-A880-AC7353D001EC")
                    IDragInfo : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AllowedOperations(
                            /* [retval, out] */ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Data(
                            /* [retval, out] */ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Modifiers(
                            /* [retval, out] */ABI::Microsoft::UI::Input::DragDrop::DragDropModifiers * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Position(
                            /* [retval, out] */ABI::Windows::Foundation::Point * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDragInfo=_uuidof(IDragInfo);
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragOperation
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragOperation
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragOperation[] = L"Microsoft.UI.Input.DragDrop.IDragOperation";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [object, uuid("EF122288-7984-53D3-8488-133DCD3DE793"), exclusiveto, contract] */
                    MIDL_INTERFACE("EF122288-7984-53D3-8488-133DCD3DE793")
                    IDragOperation : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AllowedOperations(
                            /* [retval, out] */ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AllowedOperations(
                            /* [in] */ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Data(
                            /* [retval, out] */ABI::Windows::ApplicationModel::DataTransfer::IDataPackage * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DragUIContentMode(
                            /* [retval, out] */ABI::Microsoft::UI::Input::DragDrop::DragUIContentMode * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_DragUIContentMode(
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::DragUIContentMode value
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetDragUIContentFromSoftwareBitmap(
                            /* [in] */ABI::Windows::Graphics::Imaging::ISoftwareBitmap * bitmap
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetDragUIContentFromSoftwareBitmap2(
                            /* [in] */ABI::Windows::Graphics::Imaging::ISoftwareBitmap * bitmap,
                            /* [in] */ABI::Windows::Foundation::Point anchorPoint
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartAsync(
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::IDragDropManager * initialTarget,
                            /* [in] */ABI::Microsoft::UI::Input::IPointerPoint * initialPointerPoint,
                            /* [retval, out] */__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * * operation
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDragOperation=_uuidof(IDragOperation);
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragUIOverride
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragUIOverride
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragUIOverride[] = L"Microsoft.UI.Input.DragDrop.IDragUIOverride";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [object, uuid("8432FBAC-A17F-5A95-8F56-FB432280B54D"), exclusiveto, contract] */
                    MIDL_INTERFACE("8432FBAC-A17F-5A95-8F56-FB432280B54D")
                    IDragUIOverride : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Caption(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Caption(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsCaptionVisible(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsCaptionVisible(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsContentVisible(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsContentVisible(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsGlyphVisible(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsGlyphVisible(
                            /* [in] */::boolean value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Clear(void) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetContentFromSoftwareBitmap(
                            /* [in] */ABI::Windows::Graphics::Imaging::ISoftwareBitmap * bitmap
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetContentFromSoftwareBitmap2(
                            /* [in] */ABI::Windows::Graphics::Imaging::ISoftwareBitmap * bitmap,
                            /* [in] */ABI::Windows::Foundation::Point anchorPoint
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDragUIOverride=_uuidof(IDragUIOverride);
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDropOperationTarget
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDropOperationTarget[] = L"Microsoft.UI.Input.DragDrop.IDropOperationTarget";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [object, uuid("1C2707D9-0065-53C7-BBFB-50850378CAF3"), contract] */
                    MIDL_INTERFACE("1C2707D9-0065-53C7-BBFB-50850378CAF3")
                    IDropOperationTarget : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE DropAsync(
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::IDragInfo * dragInfo,
                            /* [retval, out] */__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE EnterAsync(
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::IDragInfo * dragInfo,
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::IDragUIOverride * dragUIOverride,
                            /* [retval, out] */__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE LeaveAsync(
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::IDragInfo * dragInfo,
                            /* [retval, out] */ABI::Windows::Foundation::IAsyncAction * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE OverAsync(
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::IDragInfo * dragInfo,
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::IDragUIOverride * dragUIOverride,
                            /* [retval, out] */__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * * operation
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDropOperationTarget=_uuidof(IDropOperationTarget);
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDropOperationTargetRequestedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DropOperationTargetRequestedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDropOperationTargetRequestedEventArgs[] = L"Microsoft.UI.Input.DragDrop.IDropOperationTargetRequestedEventArgs";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Input {
                namespace DragDrop {
                    /* [object, uuid("F61C5B62-720E-59FF-AD0B-E77FC5B8A4A3"), exclusiveto, contract] */
                    MIDL_INTERFACE("F61C5B62-720E-59FF-AD0B-E77FC5B8A4A3")
                    IDropOperationTargetRequestedEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE SetTarget(
                            /* [in] */ABI::Microsoft::UI::Input::DragDrop::IDropOperationTarget * target
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDropOperationTargetRequestedEventArgs=_uuidof(IDropOperationTargetRequestedEventArgs);
                    
                } /* DragDrop */
            } /* Input */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DragDropManager
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Input.DragDrop.IDragDropManagerStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDragDropManager ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragDropManager_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragDropManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DragDropManager[] = L"Microsoft.UI.Input.DragDrop.DragDropManager";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DragInfo
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDragInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragInfo_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DragInfo[] = L"Microsoft.UI.Input.DragDrop.DragInfo";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DragOperation
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDragOperation ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragOperation_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragOperation_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DragOperation[] = L"Microsoft.UI.Input.DragDrop.DragOperation";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DragUIOverride
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDragUIOverride ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragUIOverride_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragUIOverride_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DragUIOverride[] = L"Microsoft.UI.Input.DragDrop.DragUIOverride";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DropOperationTargetRequestedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDropOperationTargetRequestedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DropOperationTargetRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DropOperationTargetRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DropOperationTargetRequestedEventArgs[] = L"Microsoft.UI.Input.DragDrop.DropOperationTargetRequestedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager;

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics;

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo;

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation;

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride;

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget;

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs;

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions


#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs * This,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * sender,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs * e);
    END_INTERFACE
} __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */



#endif // ____FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__

#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

enum __x_ABI_CWindows_CApplicationModel_CDataTransfer_CDataPackageOperation;
#if !defined(____FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation;

// Forward declare the async operation.
typedef interface __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation;

typedef struct __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperationVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This,/* [in] */ __RPC__in_opt __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation *asyncInfo, /* [in] */ AsyncStatus status);
    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperationVtbl;

interface __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperationVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_Invoke(This,asyncInfo,status)	\
    ( (This)->lpVtbl -> Invoke(This,asyncInfo,status) ) 
#endif /* COBJMACROS */


#endif // ____FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_INTERFACE_DEFINED__



#if !defined(____FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation;

typedef struct __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperationVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Completed )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This, /* [in] */ __RPC__in_opt __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation *handler);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Completed )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This, /* [retval][out] */ __RPC__deref_out_opt __FIAsyncOperationCompletedHandler_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation **handler);
    HRESULT ( STDMETHODCALLTYPE *GetResults )(__RPC__in __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * This, /* [retval][out] */ __RPC__out enum __x_ABI_CWindows_CApplicationModel_CDataTransfer_CDataPackageOperation *results);
    END_INTERFACE
} __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperationVtbl;

interface __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation
{
    CONST_VTBL struct __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperationVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 
#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 
#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 

#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_put_Completed(This,handler)	\
    ( (This)->lpVtbl -> put_Completed(This,handler) ) 
#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_get_Completed(This,handler)	\
    ( (This)->lpVtbl -> get_Completed(This,handler) ) 
#define __FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_GetResults(This,results)	\
    ( (This)->lpVtbl -> GetResults(This,results) ) 
#endif /* COBJMACROS */


#endif // ____FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation_INTERFACE_DEFINED__






#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__





#ifndef ____x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint __x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint;

#endif // ____x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint_FWD_DEFINED__





#ifndef ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage __x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage;

#endif // ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage_FWD_DEFINED__



typedef enum __x_ABI_CWindows_CApplicationModel_CDataTransfer_CDataPackageOperation __x_ABI_CWindows_CApplicationModel_CDataTransfer_CDataPackageOperation;

#ifndef ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView __x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView;

#endif // ____x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView_FWD_DEFINED__





#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIAsyncAction __x_ABI_CWindows_CFoundation_CIAsyncAction;

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__


#ifndef ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIClosable __x_ABI_CWindows_CFoundation_CIClosable;

#endif // ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__



typedef struct __x_ABI_CWindows_CFoundation_CPoint __x_ABI_CWindows_CFoundation_CPoint;



#ifndef ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap __x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap;

#endif // ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__






typedef enum __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragDropModifiers __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragDropModifiers;


typedef enum __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragUIContentMode __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragUIContentMode;























/*
 *
 * Struct Microsoft.UI.Input.DragDrop.DragDropModifiers
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
/* [v1_enum, flags, contract] */
enum __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragDropModifiers
{
    DragDropModifiers_None = 0,
    DragDropModifiers_Shift = 0x1,
    DragDropModifiers_Control = 0x2,
    DragDropModifiers_Alt = 0x4,
    DragDropModifiers_LeftButton = 0x8,
    DragDropModifiers_MiddleButton = 0x10,
    DragDropModifiers_RightButton = 0x20,
};
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Struct Microsoft.UI.Input.DragDrop.DragUIContentMode
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragUIContentMode
{
    DragUIContentMode_Auto = 0,
    DragUIContentMode_Deferred = 1,
};
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragDropManager
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragDropManager
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragDropManager[] = L"Microsoft.UI.Input.DragDrop.IDragDropManager";
/* [object, uuid("4FEA9EFC-B073-5FBE-9C95-A4113EF6393F"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AreConcurrentOperationsEnabled )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AreConcurrentOperationsEnabled )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This,
        /* [in] */boolean value
        );
    /* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_TargetRequested )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This,
        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CInput__CDragDrop__CDragDropManager_Microsoft__CUI__CInput__CDragDrop__CDropOperationTargetRequestedEventArgs * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_TargetRequested )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * This,
        /* [in] */EventRegistrationToken token
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerVtbl;

interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_get_AreConcurrentOperationsEnabled(This,value) \
    ( (This)->lpVtbl->get_AreConcurrentOperationsEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_put_AreConcurrentOperationsEnabled(This,value) \
    ( (This)->lpVtbl->put_AreConcurrentOperationsEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_add_TargetRequested(This,handler,token) \
    ( (This)->lpVtbl->add_TargetRequested(This,handler,token) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_remove_TargetRequested(This,token) \
    ( (This)->lpVtbl->remove_TargetRequested(This,token) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragDropManagerStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragDropManager
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragDropManagerStatics[] = L"Microsoft.UI.Input.DragDrop.IDragDropManagerStatics";
/* [object, uuid("5587C863-57D7-5D0F-8EA9-E5DCF06A0F83"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetForIsland )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * content,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStaticsVtbl;

interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_GetForIsland(This,content,result) \
    ( (This)->lpVtbl->GetForIsland(This,content,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragInfo
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragInfo
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragInfo[] = L"Microsoft.UI.Input.DragDrop.IDragInfo";
/* [object, uuid("7507D891-62A8-5A79-A880-AC7353D001EC"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfoVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AllowedOperations )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This,
        /* [retval, out] */__x_ABI_CWindows_CApplicationModel_CDataTransfer_CDataPackageOperation * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Data )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This,
        /* [retval, out] */__x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackageView * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Modifiers )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragDropModifiers * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Position )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CPoint * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfoVtbl;

interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfoVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_get_AllowedOperations(This,value) \
    ( (This)->lpVtbl->get_AllowedOperations(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_get_Data(This,value) \
    ( (This)->lpVtbl->get_Data(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_get_Modifiers(This,value) \
    ( (This)->lpVtbl->get_Modifiers(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_get_Position(This,value) \
    ( (This)->lpVtbl->get_Position(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragOperation
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragOperation
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragOperation[] = L"Microsoft.UI.Input.DragDrop.IDragOperation";
/* [object, uuid("EF122288-7984-53D3-8488-133DCD3DE793"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperationVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AllowedOperations )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
        /* [retval, out] */__x_ABI_CWindows_CApplicationModel_CDataTransfer_CDataPackageOperation * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AllowedOperations )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
        /* [in] */__x_ABI_CWindows_CApplicationModel_CDataTransfer_CDataPackageOperation value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Data )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
        /* [retval, out] */__x_ABI_CWindows_CApplicationModel_CDataTransfer_CIDataPackage * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DragUIContentMode )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragUIContentMode * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_DragUIContentMode )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CDragUIContentMode value
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetDragUIContentFromSoftwareBitmap )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
        /* [in] */__x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap * bitmap
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetDragUIContentFromSoftwareBitmap2 )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
        /* [in] */__x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap * bitmap,
        /* [in] */__x_ABI_CWindows_CFoundation_CPoint anchorPoint
        );
    HRESULT ( STDMETHODCALLTYPE *StartAsync )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragDropManager * initialTarget,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CIPointerPoint * initialPointerPoint,
        /* [retval, out] */__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * * operation
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperationVtbl;

interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperationVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_get_AllowedOperations(This,value) \
    ( (This)->lpVtbl->get_AllowedOperations(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_put_AllowedOperations(This,value) \
    ( (This)->lpVtbl->put_AllowedOperations(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_get_Data(This,value) \
    ( (This)->lpVtbl->get_Data(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_get_DragUIContentMode(This,value) \
    ( (This)->lpVtbl->get_DragUIContentMode(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_put_DragUIContentMode(This,value) \
    ( (This)->lpVtbl->put_DragUIContentMode(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_SetDragUIContentFromSoftwareBitmap(This,bitmap) \
    ( (This)->lpVtbl->SetDragUIContentFromSoftwareBitmap(This,bitmap) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_SetDragUIContentFromSoftwareBitmap2(This,bitmap,anchorPoint) \
    ( (This)->lpVtbl->SetDragUIContentFromSoftwareBitmap2(This,bitmap,anchorPoint) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_StartAsync(This,initialTarget,initialPointerPoint,operation) \
    ( (This)->lpVtbl->StartAsync(This,initialTarget,initialPointerPoint,operation) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragOperation_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDragUIOverride
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DragUIOverride
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDragUIOverride[] = L"Microsoft.UI.Input.DragDrop.IDragUIOverride";
/* [object, uuid("8432FBAC-A17F-5A95-8F56-FB432280B54D"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverrideVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Caption )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Caption )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsCaptionVisible )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsCaptionVisible )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsContentVisible )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsContentVisible )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsGlyphVisible )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsGlyphVisible )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [in] */boolean value
        );
    HRESULT ( STDMETHODCALLTYPE *Clear )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetContentFromSoftwareBitmap )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [in] */__x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap * bitmap
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetContentFromSoftwareBitmap2 )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * This,
        /* [in] */__x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap * bitmap,
        /* [in] */__x_ABI_CWindows_CFoundation_CPoint anchorPoint
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverrideVtbl;

interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverrideVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_get_Caption(This,value) \
    ( (This)->lpVtbl->get_Caption(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_put_Caption(This,value) \
    ( (This)->lpVtbl->put_Caption(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_get_IsCaptionVisible(This,value) \
    ( (This)->lpVtbl->get_IsCaptionVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_put_IsCaptionVisible(This,value) \
    ( (This)->lpVtbl->put_IsCaptionVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_get_IsContentVisible(This,value) \
    ( (This)->lpVtbl->get_IsContentVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_put_IsContentVisible(This,value) \
    ( (This)->lpVtbl->put_IsContentVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_get_IsGlyphVisible(This,value) \
    ( (This)->lpVtbl->get_IsGlyphVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_put_IsGlyphVisible(This,value) \
    ( (This)->lpVtbl->put_IsGlyphVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_Clear(This) \
    ( (This)->lpVtbl->Clear(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_SetContentFromSoftwareBitmap(This,bitmap) \
    ( (This)->lpVtbl->SetContentFromSoftwareBitmap(This,bitmap) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_SetContentFromSoftwareBitmap2(This,bitmap,anchorPoint) \
    ( (This)->lpVtbl->SetContentFromSoftwareBitmap2(This,bitmap,anchorPoint) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDropOperationTarget
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDropOperationTarget[] = L"Microsoft.UI.Input.DragDrop.IDropOperationTarget";
/* [object, uuid("1C2707D9-0065-53C7-BBFB-50850378CAF3"), contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *DropAsync )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * dragInfo,
        /* [retval, out] */__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *EnterAsync )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * dragInfo,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * dragUIOverride,
        /* [retval, out] */__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *LeaveAsync )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * dragInfo,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIAsyncAction * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *OverAsync )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragInfo * dragInfo,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDragUIOverride * dragUIOverride,
        /* [retval, out] */__FIAsyncOperation_1_Windows__CApplicationModel__CDataTransfer__CDataPackageOperation * * operation
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetVtbl;

interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_DropAsync(This,dragInfo,operation) \
    ( (This)->lpVtbl->DropAsync(This,dragInfo,operation) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_EnterAsync(This,dragInfo,dragUIOverride,operation) \
    ( (This)->lpVtbl->EnterAsync(This,dragInfo,dragUIOverride,operation) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_LeaveAsync(This,dragInfo,operation) \
    ( (This)->lpVtbl->LeaveAsync(This,dragInfo,operation) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_OverAsync(This,dragInfo,dragUIOverride,operation) \
    ( (This)->lpVtbl->OverAsync(This,dragInfo,dragUIOverride,operation) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Input.DragDrop.IDropOperationTargetRequestedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Input.DragDrop.DropOperationTargetRequestedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Input_DragDrop_IDropOperationTargetRequestedEventArgs[] = L"Microsoft.UI.Input.DragDrop.IDropOperationTargetRequestedEventArgs";
/* [object, uuid("F61C5B62-720E-59FF-AD0B-E77FC5B8A4A3"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *SetTarget )(
        __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTarget * target
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgsVtbl;

interface __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_SetTarget(This,target) \
    ( (This)->lpVtbl->SetTarget(This,target) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CInput_CDragDrop_CIDropOperationTargetRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DragDropManager
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Input.DragDrop.IDragDropManagerStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDragDropManager ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragDropManager_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragDropManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DragDropManager[] = L"Microsoft.UI.Input.DragDrop.DragDropManager";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DragInfo
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDragInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragInfo_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DragInfo[] = L"Microsoft.UI.Input.DragDrop.DragInfo";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DragOperation
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDragOperation ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragOperation_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragOperation_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DragOperation[] = L"Microsoft.UI.Input.DragDrop.DragOperation";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DragUIOverride
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDragUIOverride ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragUIOverride_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DragUIOverride_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DragUIOverride[] = L"Microsoft.UI.Input.DragDrop.DragUIOverride";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Input.DragDrop.DropOperationTargetRequestedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Input.DragDrop.IDropOperationTargetRequestedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DropOperationTargetRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Input_DragDrop_DropOperationTargetRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Input_DragDrop_DropOperationTargetRequestedEventArgs[] = L"Microsoft.UI.Input.DragDrop.DropOperationTargetRequestedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004





#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Eui2Einput2Edragdrop_p_h__

#endif // __microsoft2Eui2Einput2Edragdrop_h__

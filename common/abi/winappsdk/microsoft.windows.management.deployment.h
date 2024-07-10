
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
#ifndef __microsoft2Ewindows2Emanagement2Edeployment_h__
#define __microsoft2Ewindows2Emanagement2Edeployment_h__
#ifndef __microsoft2Ewindows2Emanagement2Edeployment_p_h__
#define __microsoft2Ewindows2Emanagement2Edeployment_p_h__


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
#if !defined(MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION)
#define MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION 0x20000
#endif // defined(MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION)

#if !defined(MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION)
#define MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION 0x10000
#endif // defined(MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION)

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
#include "Microsoft.Windows.ApplicationModel.DynamicDependency.h"
#include "Windows.ApplicationModel.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IAddPackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions ABI::Microsoft::Windows::Management::Deployment::IAddPackageOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IEnsureReadyOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions ABI::Microsoft::Windows::Management::Deployment::IEnsureReadyOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageDeploymentManager;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentManager

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageDeploymentManagerStatics;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentManagerStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageDeploymentResult;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageRuntimeManager;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager ABI::Microsoft::Windows::Management::Deployment::IPackageRuntimeManager

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageRuntimeManagerStatics;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics ABI::Microsoft::Windows::Management::Deployment::IPackageRuntimeManagerStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageSet;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet ABI::Microsoft::Windows::Management::Deployment::IPackageSet

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageSetItem;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageSetItemRuntimeDisposition;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageSetRuntimeDisposition;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition ABI::Microsoft::Windows::Management::Deployment::IPackageSetRuntimeDisposition

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageVolume;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume ABI::Microsoft::Windows::Management::Deployment::IPackageVolume

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IPackageVolumeStatics;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics ABI::Microsoft::Windows::Management::Deployment::IPackageVolumeStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IProvisionPackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions ABI::Microsoft::Windows::Management::Deployment::IProvisionPackageOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IRegisterPackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions ABI::Microsoft::Windows::Management::Deployment::IRegisterPackageOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IRemovePackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions ABI::Microsoft::Windows::Management::Deployment::IRemovePackageOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    interface IStagePackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions ABI::Microsoft::Windows::Management::Deployment::IStagePackageOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class PackageSetItem;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE
#define DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("74086841-814d-5f81-8ea4-0fac86b9ae28"))
IIterator<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*, ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<Microsoft.Windows.Management.Deployment.PackageSetItem>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*> __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t;
#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem ABI::Windows::Foundation::Collections::__FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem ABI::Windows::Foundation::Collections::IIterator<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>
//#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t ABI::Windows::Foundation::Collections::IIterator<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE
#define DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("45be2e06-b238-53c6-ad96-32558da5e19e"))
IIterable<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*, ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<Microsoft.Windows.Management.Deployment.PackageSetItem>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*> __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t;
#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem ABI::Windows::Foundation::Collections::__FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem ABI::Windows::Foundation::Collections::IIterable<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>
//#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t ABI::Windows::Foundation::Collections::IIterable<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class PackageSetItemRuntimeDisposition;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE
#define DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("2d49cffd-4c79-5c38-99a0-0336074e91d6"))
IIterator<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*, ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*> __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t;
#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition ABI::Windows::Foundation::Collections::__FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition ABI::Windows::Foundation::Collections::IIterator<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>
//#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t ABI::Windows::Foundation::Collections::IIterator<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE
#define DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("9f0e9c51-ad26-5814-a133-3c2fbd16f391"))
IIterable<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*, ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*> __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t;
#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition ABI::Windows::Foundation::Collections::__FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition ABI::Windows::Foundation::Collections::IIterable<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>
//#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t ABI::Windows::Foundation::Collections::IIterable<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class PackageVolume;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("9d883a1c-5ffa-5699-8327-ef5cd96c0291"))
IIterator<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*, ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<Microsoft.Windows.Management.Deployment.PackageVolume>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*> __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t;
#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::__FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::IIterator<ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>
//#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t ABI::Windows::Foundation::Collections::IIterator<ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("4b7be9cc-af65-50c9-9679-6dedd2ae9e4d"))
IIterable<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*, ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<Microsoft.Windows.Management.Deployment.PackageVolume>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*> __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t;
#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::__FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::IIterable<ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>
//#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t ABI::Windows::Foundation::Collections::IIterable<ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE
#define DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("8a350fa7-ca4b-57dc-9772-e824e3156aa7"))
IVectorView<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*, ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Microsoft.Windows.Management.Deployment.PackageSetItem>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*> __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t;
#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem ABI::Windows::Foundation::Collections::__FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem ABI::Windows::Foundation::Collections::IVectorView<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>
//#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t ABI::Windows::Foundation::Collections::IVectorView<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE
#define DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("c9fc469d-dd12-593c-b554-8aad5d1c6c45"))
IVectorView<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*, ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*> __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t;
#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition ABI::Windows::Foundation::Collections::__FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition ABI::Windows::Foundation::Collections::IVectorView<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>
//#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t ABI::Windows::Foundation::Collections::IVectorView<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("5368a870-6748-50bd-b2bd-e401ebb50bd8"))
IVectorView<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*, ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Microsoft.Windows.Management.Deployment.PackageVolume>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*> __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t;
#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::__FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::IVectorView<ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>
//#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t ABI::Windows::Foundation::Collections::IVectorView<ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE
#define DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("1a149ede-06c9-5179-aebc-42f8aefcd854"))
IVector<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*, ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVector`1<Microsoft.Windows.Management.Deployment.PackageSetItem>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Microsoft::Windows::Management::Deployment::PackageSetItem*> __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t;
#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem ABI::Windows::Foundation::Collections::__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem ABI::Windows::Foundation::Collections::IVector<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>
//#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_t ABI::Windows::Foundation::Collections::IVector<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItem*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE
#define DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("27772c5b-2d44-5594-acd9-818907ab582c"))
IVector<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*, ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVector`1<Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Microsoft::Windows::Management::Deployment::PackageSetItemRuntimeDisposition*> __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t;
#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition ABI::Windows::Foundation::Collections::__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition ABI::Windows::Foundation::Collections::IVector<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>
//#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_t ABI::Windows::Foundation::Collections::IVector<ABI::Microsoft::Windows::Management::Deployment::IPackageSetItemRuntimeDisposition*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("2662562c-57ff-5dc0-af01-0e484793c9cc"))
IVector<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*, ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVector`1<Microsoft.Windows.Management.Deployment.PackageVolume>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Microsoft::Windows::Management::Deployment::PackageVolume*> __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t;
#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::IVector<ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>
//#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_t ABI::Windows::Foundation::Collections::IVector<ABI::Microsoft::Windows::Management::Deployment::IPackageVolume*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class PackageDeploymentResult;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    struct PackageDeploymentProgress;
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE
#define DEF___FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("a365d7cc-d85a-507b-aa4a-8cfc2b58cb95"))
IAsyncOperationProgressHandler<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> : IAsyncOperationProgressHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*, ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*>,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.AsyncOperationProgressHandler`2<Microsoft.Windows.Management.Deployment.PackageDeploymentResult, Microsoft.Windows.Management.Deployment.PackageDeploymentProgress>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationProgressHandler<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t;
#define __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress ABI::Windows::Foundation::__FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*,ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress>
//#define __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*,ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000



#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE
#define DEF___FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("dba3c316-3afa-51e6-a85f-d1af460495e3"))
IAsyncOperationWithProgressCompletedHandler<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> : IAsyncOperationWithProgressCompletedHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*, ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*>,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2<Microsoft.Windows.Management.Deployment.PackageDeploymentResult, Microsoft.Windows.Management.Deployment.PackageDeploymentProgress>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationWithProgressCompletedHandler<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t;
#define __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress ABI::Windows::Foundation::__FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*,ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress>
//#define __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*,ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000



#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE
#define DEF___FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("446a127a-02de-5b73-ae01-993d4e6ef729"))
IAsyncOperationWithProgress<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> : IAsyncOperationWithProgress_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*, ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*>,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.IAsyncOperationWithProgress`2<Microsoft.Windows.Management.Deployment.PackageDeploymentResult, Microsoft.Windows.Management.Deployment.PackageDeploymentProgress>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationWithProgress<ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentResult*,struct ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress> __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t;
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress ABI::Windows::Foundation::__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*,ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress>
//#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_t ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentResult*,ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgress>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_USE */


#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Foundation {
            class Uri;
        } /* Foundation */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IUriRuntimeClass;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIUriRuntimeClass ABI::Windows::Foundation::IUriRuntimeClass

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CFoundation__CUri_USE
#define DEF___FIIterator_1_Windows__CFoundation__CUri_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("1c157d0f-5efe-5cec-bbd6-0c6ce9af07a5"))
IIterator<ABI::Windows::Foundation::Uri*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Uri>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Foundation::Uri*> __FIIterator_1_Windows__CFoundation__CUri_t;
#define __FIIterator_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CFoundation__CUri_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::IIterator<ABI::Windows::Foundation::IUriRuntimeClass*>
//#define __FIIterator_1_Windows__CFoundation__CUri_t ABI::Windows::Foundation::Collections::IIterator<ABI::Windows::Foundation::IUriRuntimeClass*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CFoundation__CUri_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CFoundation__CUri_USE
#define DEF___FIIterable_1_Windows__CFoundation__CUri_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("b0d63b78-78ad-5e31-b6d8-e32a0e16c447"))
IIterable<ABI::Windows::Foundation::Uri*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Uri>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Foundation::Uri*> __FIIterable_1_Windows__CFoundation__CUri_t;
#define __FIIterable_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CFoundation__CUri_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::IUriRuntimeClass*>
//#define __FIIterable_1_Windows__CFoundation__CUri_t ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::IUriRuntimeClass*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CFoundation__CUri_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CFoundation__CUri_USE
#define DEF___FIVectorView_1_Windows__CFoundation__CUri_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("4b8385bd-a2cd-5ff1-bf74-7ea580423e50"))
IVectorView<ABI::Windows::Foundation::Uri*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Foundation.Uri>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Foundation::Uri*> __FIVectorView_1_Windows__CFoundation__CUri_t;
#define __FIVectorView_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CFoundation__CUri_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVectorView_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::IVectorView<ABI::Windows::Foundation::IUriRuntimeClass*>
//#define __FIVectorView_1_Windows__CFoundation__CUri_t ABI::Windows::Foundation::Collections::IVectorView<ABI::Windows::Foundation::IUriRuntimeClass*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CFoundation__CUri_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Windows__CFoundation__CUri_USE
#define DEF___FIVector_1_Windows__CFoundation__CUri_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("0d82bd8d-fe62-5d67-a7b9-7886dd75bc4e"))
IVector<ABI::Windows::Foundation::Uri*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Foundation.Uri>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::Foundation::Uri*> __FIVector_1_Windows__CFoundation__CUri_t;
#define __FIVector_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CFoundation__CUri_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVector_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::IVector<ABI::Windows::Foundation::IUriRuntimeClass*>
//#define __FIVector_1_Windows__CFoundation__CUri_t ABI::Windows::Foundation::Collections::IVector<ABI::Windows::Foundation::IUriRuntimeClass*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CFoundation__CUri_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#ifndef DEF___FIIterator_1_HSTRING_USE
#define DEF___FIIterator_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236"))
IIterator<HSTRING> : IIterator_impl<HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<HSTRING> __FIIterator_1_HSTRING_t;
#define __FIIterator_1_HSTRING ABI::Windows::Foundation::Collections::__FIIterator_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_HSTRING ABI::Windows::Foundation::Collections::IIterator<HSTRING>
//#define __FIIterator_1_HSTRING_t ABI::Windows::Foundation::Collections::IIterator<HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_HSTRING_USE */




#ifndef DEF___FIIterable_1_HSTRING_USE
#define DEF___FIIterable_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e"))
IIterable<HSTRING> : IIterable_impl<HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<HSTRING> __FIIterable_1_HSTRING_t;
#define __FIIterable_1_HSTRING ABI::Windows::Foundation::Collections::__FIIterable_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_HSTRING ABI::Windows::Foundation::Collections::IIterable<HSTRING>
//#define __FIIterable_1_HSTRING_t ABI::Windows::Foundation::Collections::IIterable<HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_HSTRING_USE */




#ifndef DEF___FIVectorView_1_HSTRING_USE
#define DEF___FIVectorView_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e"))
IVectorView<HSTRING> : IVectorView_impl<HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVectorView`1<String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<HSTRING> __FIVectorView_1_HSTRING_t;
#define __FIVectorView_1_HSTRING ABI::Windows::Foundation::Collections::__FIVectorView_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVectorView_1_HSTRING ABI::Windows::Foundation::Collections::IVectorView<HSTRING>
//#define __FIVectorView_1_HSTRING_t ABI::Windows::Foundation::Collections::IVectorView<HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_HSTRING_USE */




#ifndef DEF___FIVector_1_HSTRING_USE
#define DEF___FIVector_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90"))
IVector<HSTRING> : IVector_impl<HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVector`1<String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<HSTRING> __FIVector_1_HSTRING_t;
#define __FIVector_1_HSTRING ABI::Windows::Foundation::Collections::__FIVector_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVector_1_HSTRING ABI::Windows::Foundation::Collections::IVector<HSTRING>
//#define __FIVector_1_HSTRING_t ABI::Windows::Foundation::Collections::IVector<HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_HSTRING_USE */




#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE
#define DEF___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f1fe0d5e-8449-5479-875f-17daeb0027f0"))
IKeyValuePair<ABI::Windows::Foundation::Uri*,HSTRING> : IKeyValuePair_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>,HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IKeyValuePair`2<Windows.Foundation.Uri, String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IKeyValuePair<ABI::Windows::Foundation::Uri*,HSTRING> __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t;
#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::__FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::IKeyValuePair<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>
//#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t ABI::Windows::Foundation::Collections::IKeyValuePair<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE
#define DEF___FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("0c11a982-9f05-557f-b3e8-3737b26830d1"))
IIterator<__FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING*> : IIterator_impl<__FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING*> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<Windows.Foundation.Uri, String>>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<__FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING*> __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t;
#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::__FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::IIterator<ABI::Windows::Foundation::Collections::IKeyValuePair<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>*>
//#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t ABI::Windows::Foundation::Collections::IIterator<ABI::Windows::Foundation::Collections::IKeyValuePair<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE
#define DEF___FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("52129c53-b03d-59b3-a27e-b0385643e9fe"))
IIterable<__FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING*> : IIterable_impl<__FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING*> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IKeyValuePair`2<Windows.Foundation.Uri, String>>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<__FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING*> __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t;
#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::__FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IKeyValuePair<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>*>
//#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_t ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IKeyValuePair<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIMapView_2_Windows__CFoundation__CUri_HSTRING_USE
#define DEF___FIMapView_2_Windows__CFoundation__CUri_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("87530605-8bd4-5f0a-85f1-751e8bd20446"))
IMapView<ABI::Windows::Foundation::Uri*,HSTRING> : IMapView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>,HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IMapView`2<Windows.Foundation.Uri, String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMapView<ABI::Windows::Foundation::Uri*,HSTRING> __FIMapView_2_Windows__CFoundation__CUri_HSTRING_t;
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::__FIMapView_2_Windows__CFoundation__CUri_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::IMapView<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>
//#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_t ABI::Windows::Foundation::Collections::IMapView<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMapView_2_Windows__CFoundation__CUri_HSTRING_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIMap_2_Windows__CFoundation__CUri_HSTRING_USE
#define DEF___FIMap_2_Windows__CFoundation__CUri_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("4c522071-01da-5f85-9d52-29952578a301"))
IMap<ABI::Windows::Foundation::Uri*,HSTRING> : IMap_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>,HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IMap`2<Windows.Foundation.Uri, String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMap<ABI::Windows::Foundation::Uri*,HSTRING> __FIMap_2_Windows__CFoundation__CUri_HSTRING_t;
#define __FIMap_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::__FIMap_2_Windows__CFoundation__CUri_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIMap_2_Windows__CFoundation__CUri_HSTRING ABI::Windows::Foundation::Collections::IMap<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>
//#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_t ABI::Windows::Foundation::Collections::IMap<ABI::Windows::Foundation::IUriRuntimeClass*,HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMap_2_Windows__CFoundation__CUri_HSTRING_USE */


#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000



namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    class AddPackageDependencyOptions;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    interface IAddPackageDependencyOptions;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IAddPackageDependencyOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    class CreatePackageDependencyOptions;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    interface ICreatePackageDependencyOptions;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::ICreatePackageDependencyOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    
                    typedef struct PackageDependencyContextId PackageDependencyContextId;
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    
                    typedef enum PackageDependencyProcessorArchitectures : unsigned int PackageDependencyProcessorArchitectures;
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */





namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            
            typedef struct PackageVersion PackageVersion;
            
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */







namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    
                    typedef enum PackageDeploymentProgressStatus : int PackageDeploymentProgressStatus;
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    
                    typedef enum PackageDeploymentStatus : int PackageDeploymentStatus;
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    
                    typedef enum StubPackageOption : int StubPackageOption;
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    
                    typedef struct PackageDeploymentProgress PackageDeploymentProgress;
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


















namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class AddPackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class EnsureReadyOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class PackageDeploymentManager;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */



namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class PackageRuntimeManager;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class PackageSet;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */




namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class PackageSetRuntimeDisposition;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */



namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class ProvisionPackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class RegisterPackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class RemovePackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    class StagePackageOptions;
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */













/*
 *
 * Struct Microsoft.Windows.Management.Deployment.PackageDeploymentProgressStatus
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [v1_enum, contract] */
                    enum PackageDeploymentProgressStatus : int
                    {
                        PackageDeploymentProgressStatus_Queued = 0,
                        PackageDeploymentProgressStatus_InProgress = 1,
                        PackageDeploymentProgressStatus_CompletedSuccess = 2,
                        PackageDeploymentProgressStatus_CompletedFailure = 3,
                    };
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.Management.Deployment.PackageDeploymentStatus
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [v1_enum, contract] */
                    enum PackageDeploymentStatus : int
                    {
                        PackageDeploymentStatus_InProgress = 0,
                        PackageDeploymentStatus_CompletedSuccess = 1,
                        PackageDeploymentStatus_CompletedFailure = 2,
                    };
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.Management.Deployment.StubPackageOption
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [v1_enum, contract] */
                    enum StubPackageOption : int
                    {
                        StubPackageOption_Default = 0,
                        StubPackageOption_InstallFull = 1,
                        StubPackageOption_InstallStub = 2,
                        StubPackageOption_UsePreference = 3,
                    };
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.Management.Deployment.PackageDeploymentProgress
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [contract] */
                    struct PackageDeploymentProgress
                    {
                        ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentProgressStatus Status;
                        DOUBLE Progress;
                    };
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IAddPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.AddPackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IAddPackageOptions[] = L"Microsoft.Windows.Management.Deployment.IAddPackageOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("E3DB7F39-F9D0-5884-BDEF-6153B54574A3"), exclusiveto, contract] */
                    MIDL_INTERFACE("E3DB7F39-F9D0-5884-BDEF-6153B54574A3")
                    IAddPackageOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_TargetVolume(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageVolume * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_TargetVolume(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageVolume * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DependencyPackageUris(
                            /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageFamilyNames(
                            /* [retval, out] */__FIVector_1_HSTRING * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageUris(
                            /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RelatedPackageUris(
                            /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExternalLocationUri(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ExternalLocationUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_StubPackageOption(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::StubPackageOption * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_StubPackageOption(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::StubPackageOption value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AllowUnsigned(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AllowUnsigned(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DeveloperMode(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_DeveloperMode(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ForceAppShutdown(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ForceAppShutdown(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ForceTargetAppShutdown(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ForceTargetAppShutdown(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ForceUpdateFromAnyVersion(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ForceUpdateFromAnyVersion(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InstallAllResources(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_InstallAllResources(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RequiredContentGroupOnly(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_RequiredContentGroupOnly(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RetainFilesOnFailure(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_RetainFilesOnFailure(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_StageInPlace(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_StageInPlace(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DeferRegistrationWhenPackagesAreInUse(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_DeferRegistrationWhenPackagesAreInUse(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsExpectedDigestsSupported(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExpectedDigests(
                            /* [retval, out] */__FIMap_2_Windows__CFoundation__CUri_HSTRING * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsLimitToExistingPackagesSupported(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LimitToExistingPackages(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_LimitToExistingPackages(
                            /* [in] */::boolean value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAddPackageOptions=_uuidof(IAddPackageOptions);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IEnsureReadyOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.EnsureReadyOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IEnsureReadyOptions[] = L"Microsoft.Windows.Management.Deployment.IEnsureReadyOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("20102D03-EC44-5C2B-8FD6-1104DC99755D"), exclusiveto, contract] */
                    MIDL_INTERFACE("20102D03-EC44-5C2B-8FD6-1104DC99755D")
                    IEnsureReadyOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AddPackageOptions(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IAddPackageOptions * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IEnsureReadyOptions=_uuidof(IEnsureReadyOptions);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageDeploymentManager
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageDeploymentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageDeploymentManager[] = L"Microsoft.Windows.Management.Deployment.IPackageDeploymentManager";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("F41717D8-5AB2-57AC-83CD-D0C48CC784CD"), exclusiveto, contract] */
                    MIDL_INTERFACE("F41717D8-5AB2-57AC-83CD-D0C48CC784CD")
                    IPackageDeploymentManager : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE IsPackageReady(
                            /* [in] */HSTRING package,
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPackageReadyByUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPackageSetReady(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE EnsurePackageReadyAsync(
                            /* [in] */HSTRING package,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IEnsureReadyOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE EnsurePackageReadyByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IEnsureReadyOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE EnsurePackageSetReadyAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IEnsureReadyOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AddPackageAsync(
                            /* [in] */HSTRING package,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IAddPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AddPackageByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IAddPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AddPackageSetAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IAddPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StagePackageAsync(
                            /* [in] */HSTRING package,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IStagePackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StagePackageByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IStagePackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StagePackageSetAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IStagePackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RegisterPackageAsync(
                            /* [in] */HSTRING package,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IRegisterPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RegisterPackageByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IRegisterPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RegisterPackageSetAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IRegisterPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RemovePackageAsync(
                            /* [in] */HSTRING package,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IRemovePackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RemovePackageByFullNameAsync(
                            /* [in] */HSTRING packageFullName,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IRemovePackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RemovePackageByFamilyNameAsync(
                            /* [in] */HSTRING packageFamilyName,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IRemovePackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RemovePackageByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IRemovePackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RemovePackageSetAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IRemovePackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ResetPackageAsync(
                            /* [in] */HSTRING package,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ResetPackageByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ResetPackageSetAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RepairPackageAsync(
                            /* [in] */HSTRING package,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RepairPackageByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RepairPackageSetAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ProvisionPackageAsync(
                            /* [in] */HSTRING package,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IProvisionPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ProvisionPackageByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IProvisionPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ProvisionPackageSetAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IProvisionPackageOptions * options,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE DeprovisionPackageAsync(
                            /* [in] */HSTRING package,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE DeprovisionPackageByUriAsync(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * packageUri,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE DeprovisionPackageSetAsync(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPackageRegistrationPending(
                            /* [in] */HSTRING packageFamilyName,
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPackageRegistrationPendingForUser(
                            /* [in] */HSTRING userSecurityId,
                            /* [in] */HSTRING packageFamilyName,
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDeploymentManager=_uuidof(IPackageDeploymentManager);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageDeploymentManagerStatics
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageDeploymentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageDeploymentManagerStatics[] = L"Microsoft.Windows.Management.Deployment.IPackageDeploymentManagerStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("DBDA4AC6-CA28-59B8-9FC6-DBFB5765F1C2"), exclusiveto, contract] */
                    MIDL_INTERFACE("DBDA4AC6-CA28-59B8-9FC6-DBFB5765F1C2")
                    IPackageDeploymentManagerStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetDefault(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageDeploymentManager * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDeploymentManagerStatics=_uuidof(IPackageDeploymentManagerStatics);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageDeploymentResult
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageDeploymentResult
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageDeploymentResult[] = L"Microsoft.Windows.Management.Deployment.IPackageDeploymentResult";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("D6B99601-18C2-599E-8BD1-40A9310AD263"), exclusiveto, contract] */
                    MIDL_INTERFACE("D6B99601-18C2-599E-8BD1-40A9310AD263")
                    IPackageDeploymentResult : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Status(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::PackageDeploymentStatus * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Error(
                            /* [retval, out] */HRESULT * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExtendedError(
                            /* [retval, out] */HRESULT * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ErrorText(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ActivityId(
                            /* [retval, out] */GUID * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDeploymentResult=_uuidof(IPackageDeploymentResult);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageRuntimeManager
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageRuntimeManager
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageRuntimeManager[] = L"Microsoft.Windows.Management.Deployment.IPackageRuntimeManager";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("6BF0FD29-6C2A-58D1-AF0C-ABD2EAC45E29"), exclusiveto, contract] */
                    MIDL_INTERFACE("6BF0FD29-6C2A-58D1-AF0C-ABD2EAC45E29")
                    IPackageRuntimeManager : public IInspectable
                    {
                    public:
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE AddPackageSet(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageSetRuntimeDisposition * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE AddPackageSetWithOptions(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSet * packageSet,
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::ICreatePackageDependencyOptions * createOptions,
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IAddPackageDependencyOptions * addOptions,
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageSetRuntimeDisposition * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RemovePackageSet(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageSetRuntimeDisposition * packageSetRuntimeDisposition
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageRuntimeManager=_uuidof(IPackageRuntimeManager);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageRuntimeManagerStatics
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageRuntimeManager
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageRuntimeManagerStatics[] = L"Microsoft.Windows.Management.Deployment.IPackageRuntimeManagerStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("790947DE-01D4-5858-AA69-9C9390FB7D3E"), exclusiveto, contract] */
                    MIDL_INTERFACE("790947DE-01D4-5858-AA69-9C9390FB7D3E")
                    IPackageRuntimeManagerStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetDefault(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageRuntimeManager * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageRuntimeManagerStatics=_uuidof(IPackageRuntimeManagerStatics);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageSet
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageSet
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageSet[] = L"Microsoft.Windows.Management.Deployment.IPackageSet";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("229FDF93-8529-5F8D-988C-AF8A39AD46F7"), exclusiveto, contract] */
                    MIDL_INTERFACE("229FDF93-8529-5F8D-988C-AF8A39AD46F7")
                    IPackageSet : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Id(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Id(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageUri(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PackageUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Items(
                            /* [retval, out] */__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageSet=_uuidof(IPackageSet);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageSetItem
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageSetItem
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageSetItem[] = L"Microsoft.Windows.Management.Deployment.IPackageSetItem";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("8F254E15-C371-550F-B4E8-3F0BB1AE375F"), exclusiveto, contract] */
                    MIDL_INTERFACE("8F254E15-C371-550F-B4E8-3F0BB1AE375F")
                    IPackageSetItem : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Id(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Id(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageFamilyName(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PackageFamilyName(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_MinVersion(
                            /* [retval, out] */ABI::Windows::ApplicationModel::PackageVersion * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_MinVersion(
                            /* [in] */ABI::Windows::ApplicationModel::PackageVersion value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ProcessorArchitectureFilter(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyProcessorArchitectures * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ProcessorArchitectureFilter(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyProcessorArchitectures value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageUri(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PackageUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageSetItem=_uuidof(IPackageSetItem);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageSetItemRuntimeDisposition
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageSetItemRuntimeDisposition[] = L"Microsoft.Windows.Management.Deployment.IPackageSetItemRuntimeDisposition";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("7A7F9F70-D416-5F83-A3CD-027BF3D2ABFD"), exclusiveto, contract] */
                    MIDL_INTERFACE("7A7F9F70-D416-5F83-A3CD-027BF3D2ABFD")
                    IPackageSetItemRuntimeDisposition : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageSetItemId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageFullName(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageDependencyId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageDependencyContextId(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyContextId * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageSetItemRuntimeDisposition=_uuidof(IPackageSetItemRuntimeDisposition);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageSetRuntimeDisposition
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageSetRuntimeDisposition
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageSetRuntimeDisposition[] = L"Microsoft.Windows.Management.Deployment.IPackageSetRuntimeDisposition";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("C13F1088-EA36-5DB3-BCDD-E6D59E6C9B71"), exclusiveto, contract] */
                    MIDL_INTERFACE("C13F1088-EA36-5DB3-BCDD-E6D59E6C9B71")
                    IPackageSetRuntimeDisposition : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageSetId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PackageSetId(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageSetItemRuntimeDispositions(
                            /* [retval, out] */__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageSetRuntimeDisposition=_uuidof(IPackageSetRuntimeDisposition);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageVolume
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageVolume
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageVolume[] = L"Microsoft.Windows.Management.Deployment.IPackageVolume";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("9C9710F4-795A-58B3-93F4-C991C4329C49"), exclusiveto, contract] */
                    MIDL_INTERFACE("9C9710F4-795A-58B3-93F4-C991C4329C49")
                    IPackageVolume : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSystemVolume(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_MountPoint(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Name(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageStorePath(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SupportsHardLinks(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsFullTrustPackageSupported(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsAppxInstallSupported(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsRepairNeeded(
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Repair(void) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageVolume=_uuidof(IPackageVolume);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageVolumeStatics
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageVolume
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageVolumeStatics[] = L"Microsoft.Windows.Management.Deployment.IPackageVolumeStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("4C731835-8BC0-5313-9B56-8A4100EAEA01"), exclusiveto, contract] */
                    MIDL_INTERFACE("4C731835-8BC0-5313-9B56-8A4100EAEA01")
                    IPackageVolumeStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE FindPackageVolumes(
                            /* [retval, out] */__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE FindPackageVolumeByPath(
                            /* [in] */HSTRING packageStorePath,
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageVolume * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE FindPackageVolumeByName(
                            /* [in] */HSTRING name,
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageVolume * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageVolumeStatics=_uuidof(IPackageVolumeStatics);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IProvisionPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.ProvisionPackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IProvisionPackageOptions[] = L"Microsoft.Windows.Management.Deployment.IProvisionPackageOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("415E300F-D1E3-581E-A114-76D277B06136"), exclusiveto, contract] */
                    MIDL_INTERFACE("415E300F-D1E3-581E-A114-76D277B06136")
                    IProvisionPackageOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsOptionalPackageFamilyNamesSupported(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageFamilyNames(
                            /* [retval, out] */__FIVector_1_HSTRING * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsProjectionOrderPackageFamilyNamesSupported(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ProjectionOrderPackageFamilyNames(
                            /* [retval, out] */__FIVector_1_HSTRING * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IProvisionPackageOptions=_uuidof(IProvisionPackageOptions);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IRegisterPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.RegisterPackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IRegisterPackageOptions[] = L"Microsoft.Windows.Management.Deployment.IRegisterPackageOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("83068623-2046-505F-8425-55226C0F84CC"), exclusiveto, contract] */
                    MIDL_INTERFACE("83068623-2046-505F-8425-55226C0F84CC")
                    IRegisterPackageOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AppDataVolume(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageVolume * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AppDataVolume(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageVolume * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DependencyPackageFamilyNames(
                            /* [retval, out] */__FIVector_1_HSTRING * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DependencyPackageUris(
                            /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageFamilyNames(
                            /* [retval, out] */__FIVector_1_HSTRING * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExternalLocationUri(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ExternalLocationUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AllowUnsigned(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AllowUnsigned(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DeveloperMode(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_DeveloperMode(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ForceAppShutdown(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ForceAppShutdown(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ForceTargetAppShutdown(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ForceTargetAppShutdown(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ForceUpdateFromAnyVersion(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ForceUpdateFromAnyVersion(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InstallAllResources(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_InstallAllResources(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_StageInPlace(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_StageInPlace(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DeferRegistrationWhenPackagesAreInUse(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_DeferRegistrationWhenPackagesAreInUse(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsExpectedDigestsSupported(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExpectedDigests(
                            /* [retval, out] */__FIMap_2_Windows__CFoundation__CUri_HSTRING * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IRegisterPackageOptions=_uuidof(IRegisterPackageOptions);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IRemovePackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.RemovePackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IRemovePackageOptions[] = L"Microsoft.Windows.Management.Deployment.IRemovePackageOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("E7C90595-9A44-5046-8EBF-41ED326B200E"), exclusiveto, contract] */
                    MIDL_INTERFACE("E7C90595-9A44-5046-8EBF-41ED326B200E")
                    IRemovePackageOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FailIfNotFound(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_FailIfNotFound(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PreserveApplicationData(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PreserveApplicationData(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PreserveRoamableApplicationData(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PreserveRoamableApplicationData(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RemoveForAllUsers(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_RemoveForAllUsers(
                            /* [in] */::boolean value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IRemovePackageOptions=_uuidof(IRemovePackageOptions);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IStagePackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.StagePackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IStagePackageOptions[] = L"Microsoft.Windows.Management.Deployment.IStagePackageOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Management {
                namespace Deployment {
                    /* [object, uuid("9B6B3203-FD7C-5EAD-A9D6-AB2E8566BE5E"), exclusiveto, contract] */
                    MIDL_INTERFACE("9B6B3203-FD7C-5EAD-A9D6-AB2E8566BE5E")
                    IStagePackageOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_TargetVolume(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::IPackageVolume * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_TargetVolume(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::IPackageVolume * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DependencyPackageUris(
                            /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageFamilyNames(
                            /* [retval, out] */__FIVector_1_HSTRING * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageUris(
                            /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RelatedPackageUris(
                            /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExternalLocationUri(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ExternalLocationUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_StubPackageOption(
                            /* [retval, out] */ABI::Microsoft::Windows::Management::Deployment::StubPackageOption * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_StubPackageOption(
                            /* [in] */ABI::Microsoft::Windows::Management::Deployment::StubPackageOption value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DeveloperMode(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_DeveloperMode(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ForceUpdateFromAnyVersion(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ForceUpdateFromAnyVersion(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InstallAllResources(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_InstallAllResources(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RequiredContentGroupOnly(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_RequiredContentGroupOnly(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_StageInPlace(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_StageInPlace(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AllowUnsigned(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AllowUnsigned(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsExpectedDigestsSupported(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExpectedDigests(
                            /* [retval, out] */__FIMap_2_Windows__CFoundation__CUri_HSTRING * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IStagePackageOptions=_uuidof(IStagePackageOptions);
                    
                } /* Deployment */
            } /* Management */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.AddPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IAddPackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_AddPackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_AddPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_AddPackageOptions[] = L"Microsoft.Windows.Management.Deployment.AddPackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.EnsureReadyOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IEnsureReadyOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_EnsureReadyOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_EnsureReadyOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_EnsureReadyOptions[] = L"Microsoft.Windows.Management.Deployment.EnsureReadyOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageDeploymentManager
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Management.Deployment.IPackageDeploymentManagerStatics interface starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageDeploymentManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageDeploymentManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageDeploymentManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageDeploymentManager[] = L"Microsoft.Windows.Management.Deployment.PackageDeploymentManager";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageDeploymentResult
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageDeploymentResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageDeploymentResult_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageDeploymentResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageDeploymentResult[] = L"Microsoft.Windows.Management.Deployment.PackageDeploymentResult";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageRuntimeManager
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Management.Deployment.IPackageRuntimeManagerStatics interface starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageRuntimeManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageRuntimeManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageRuntimeManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageRuntimeManager[] = L"Microsoft.Windows.Management.Deployment.PackageRuntimeManager";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageSet
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageSet ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSet_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSet_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageSet[] = L"Microsoft.Windows.Management.Deployment.PackageSet";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageSetItem
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageSetItem ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetItem_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetItem_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageSetItem[] = L"Microsoft.Windows.Management.Deployment.PackageSetItem";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageSetItemRuntimeDisposition ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetItemRuntimeDisposition_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetItemRuntimeDisposition_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageSetItemRuntimeDisposition[] = L"Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageSetRuntimeDisposition
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageSetRuntimeDisposition ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetRuntimeDisposition_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetRuntimeDisposition_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageSetRuntimeDisposition[] = L"Microsoft.Windows.Management.Deployment.PackageSetRuntimeDisposition";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageVolume
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Management.Deployment.IPackageVolumeStatics interface starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageVolume ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageVolume_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageVolume_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageVolume[] = L"Microsoft.Windows.Management.Deployment.PackageVolume";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.ProvisionPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IProvisionPackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_ProvisionPackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_ProvisionPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_ProvisionPackageOptions[] = L"Microsoft.Windows.Management.Deployment.ProvisionPackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.RegisterPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IRegisterPackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_RegisterPackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_RegisterPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_RegisterPackageOptions[] = L"Microsoft.Windows.Management.Deployment.RegisterPackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.RemovePackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IRemovePackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_RemovePackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_RemovePackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_RemovePackageOptions[] = L"Microsoft.Windows.Management.Deployment.RemovePackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.StagePackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IStagePackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_StagePackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_StagePackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_StagePackageOptions[] = L"Microsoft.Windows.Management.Deployment.StagePackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__)
#define ____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem;

typedef struct __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [retval][out] */ __RPC__out __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl;

interface __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem
{
    CONST_VTBL struct __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__)
#define ____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem;

typedef  struct __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem **first);

    END_INTERFACE
} __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl;

interface __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem
{
    CONST_VTBL struct __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__)
#define ____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition;

typedef struct __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [retval][out] */ __RPC__out __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl;

interface __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition
{
    CONST_VTBL struct __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__)
#define ____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition;

typedef  struct __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition **first);

    END_INTERFACE
} __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl;

interface __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition
{
    CONST_VTBL struct __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [retval][out] */ __RPC__out __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume;

typedef  struct __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume **first);

    END_INTERFACE
} __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem;

typedef struct __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);

    ULONG ( STDMETHODCALLTYPE *Release )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
                                            /* [out] */ __RPC__out ULONG *iidCount,
                                            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )( 
                                         __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
                                         /* [in] */ unsigned int index,
                                         /* [retval][out] */ __RPC__out __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * *item);

        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
            /* [retval][out] */ __RPC__out unsigned int *size);

        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
                                               __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
            /* [in] */ __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * item,
            /* [out] */ __RPC__out unsigned int *index,
            /* [retval][out] */ __RPC__out boolean *found);

        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
                                               __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * *items,
            /* [retval][out] */ __RPC__out unsigned int *actual);

        END_INTERFACE
} __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl;

interface __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem
{
    CONST_VTBL struct __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#endif /* COBJMACROS */



#endif // ____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition;

typedef struct __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);

    ULONG ( STDMETHODCALLTYPE *Release )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
                                            /* [out] */ __RPC__out ULONG *iidCount,
                                            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )( 
                                         __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
                                         /* [in] */ unsigned int index,
                                         /* [retval][out] */ __RPC__out __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * *item);

        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
            /* [retval][out] */ __RPC__out unsigned int *size);

        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
                                               __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
            /* [in] */ __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * item,
            /* [out] */ __RPC__out unsigned int *index,
            /* [retval][out] */ __RPC__out boolean *found);

        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
                                               __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * *items,
            /* [retval][out] */ __RPC__out unsigned int *actual);

        END_INTERFACE
} __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl;

interface __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition
{
    CONST_VTBL struct __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#endif /* COBJMACROS */



#endif // ____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);

    ULONG ( STDMETHODCALLTYPE *Release )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )( __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
                                            /* [out] */ __RPC__out ULONG *iidCount,
                                            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
        __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )( 
                                         __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
                                         /* [in] */ unsigned int index,
                                         /* [retval][out] */ __RPC__out __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * *item);

        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
            /* [retval][out] */ __RPC__out unsigned int *size);

        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
                                               __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
            /* [in] */ __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * item,
            /* [out] */ __RPC__out unsigned int *index,
            /* [retval][out] */ __RPC__out boolean *found);

        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
                                               __RPC__in __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * *items,
            /* [retval][out] */ __RPC__out unsigned int *actual);

        END_INTERFACE
} __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#endif /* COBJMACROS */



#endif // ____FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__)
#define ____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__

typedef interface __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem;

typedef struct __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ unsigned int index,
        /* [retval][out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * *item);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
        __RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [retval][out] */ __RPC__out unsigned int *size);

    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [retval][out] */ __RPC__deref_out_opt __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem **view);

    HRESULT ( STDMETHODCALLTYPE *IndexOf )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * item,
        /* [out] */ __RPC__out unsigned int *index,
        /* [retval][out] */ __RPC__out boolean *found);

    HRESULT ( STDMETHODCALLTYPE *SetAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * item);

    HRESULT ( STDMETHODCALLTYPE *InsertAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * item);

    HRESULT ( STDMETHODCALLTYPE *RemoveAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [in] */ unsigned int index);
    HRESULT ( STDMETHODCALLTYPE *Append )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This, /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * item);
    HRESULT ( STDMETHODCALLTYPE *RemoveAtEnd )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ unsigned int startIndex,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    HRESULT ( STDMETHODCALLTYPE *ReplaceAll )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * This,
        /* [in] */ unsigned int count,
        /* [size_is][in] */ __RPC__in_ecount_full(count) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * *value);

    END_INTERFACE
} __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl;

interface __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem
{
    CONST_VTBL struct __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_SetAt(This,index,item)	\
    ( (This)->lpVtbl -> SetAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_InsertAt(This,index,item)	\
    ( (This)->lpVtbl -> InsertAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_RemoveAt(This,index)	\
    ( (This)->lpVtbl -> RemoveAt(This,index) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_Append(This,item)	\
    ( (This)->lpVtbl -> Append(This,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_RemoveAtEnd(This)	\
    ( (This)->lpVtbl -> RemoveAtEnd(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_ReplaceAll(This,count,value)	\
    ( (This)->lpVtbl -> ReplaceAll(This,count,value) ) 

#endif /* COBJMACROS */



#endif // ____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__)
#define ____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__

typedef interface __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition;

typedef struct __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ unsigned int index,
        /* [retval][out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * *item);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
        __RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [retval][out] */ __RPC__out unsigned int *size);

    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [retval][out] */ __RPC__deref_out_opt __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition **view);

    HRESULT ( STDMETHODCALLTYPE *IndexOf )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * item,
        /* [out] */ __RPC__out unsigned int *index,
        /* [retval][out] */ __RPC__out boolean *found);

    HRESULT ( STDMETHODCALLTYPE *SetAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * item);

    HRESULT ( STDMETHODCALLTYPE *InsertAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * item);

    HRESULT ( STDMETHODCALLTYPE *RemoveAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [in] */ unsigned int index);
    HRESULT ( STDMETHODCALLTYPE *Append )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This, /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * item);
    HRESULT ( STDMETHODCALLTYPE *RemoveAtEnd )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ unsigned int startIndex,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    HRESULT ( STDMETHODCALLTYPE *ReplaceAll )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * This,
        /* [in] */ unsigned int count,
        /* [size_is][in] */ __RPC__in_ecount_full(count) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * *value);

    END_INTERFACE
} __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl;

interface __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition
{
    CONST_VTBL struct __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDispositionVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_SetAt(This,index,item)	\
    ( (This)->lpVtbl -> SetAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_InsertAt(This,index,item)	\
    ( (This)->lpVtbl -> InsertAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_RemoveAt(This,index)	\
    ( (This)->lpVtbl -> RemoveAt(This,index) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_Append(This,item)	\
    ( (This)->lpVtbl -> Append(This,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_RemoveAtEnd(This)	\
    ( (This)->lpVtbl -> RemoveAtEnd(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_ReplaceAll(This,count,value)	\
    ( (This)->lpVtbl -> ReplaceAll(This,count,value) ) 

#endif /* COBJMACROS */



#endif // ____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ unsigned int index,
        /* [retval][out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * *item);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
        __RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [retval][out] */ __RPC__out unsigned int *size);

    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [retval][out] */ __RPC__deref_out_opt __FIVectorView_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume **view);

    HRESULT ( STDMETHODCALLTYPE *IndexOf )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * item,
        /* [out] */ __RPC__out unsigned int *index,
        /* [retval][out] */ __RPC__out boolean *found);

    HRESULT ( STDMETHODCALLTYPE *SetAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * item);

    HRESULT ( STDMETHODCALLTYPE *InsertAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * item);

    HRESULT ( STDMETHODCALLTYPE *RemoveAt )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [in] */ unsigned int index);
    HRESULT ( STDMETHODCALLTYPE *Append )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This, /* [in] */ __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * item);
    HRESULT ( STDMETHODCALLTYPE *RemoveAtEnd )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ unsigned int startIndex,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    HRESULT ( STDMETHODCALLTYPE *ReplaceAll )(__RPC__in __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * This,
        /* [in] */ unsigned int count,
        /* [size_is][in] */ __RPC__in_ecount_full(count) __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * *value);

    END_INTERFACE
} __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolumeVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_SetAt(This,index,item)	\
    ( (This)->lpVtbl -> SetAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_InsertAt(This,index,item)	\
    ( (This)->lpVtbl -> InsertAt(This,index,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_RemoveAt(This,index)	\
    ( (This)->lpVtbl -> RemoveAt(This,index) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_Append(This,item)	\
    ( (This)->lpVtbl -> Append(This,item) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_RemoveAtEnd(This)	\
    ( (This)->lpVtbl -> RemoveAtEnd(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#define __FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_ReplaceAll(This,count,value)	\
    ( (This)->lpVtbl -> ReplaceAll(This,count,value) ) 

#endif /* COBJMACROS */



#endif // ____FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgress;

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__)
#define ____FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress;

typedef interface __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress;

typedef struct __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [in] */ __RPC__in_opt __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress *asyncInfo, /* [in] */ struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgress progressInfo);
    END_INTERFACE
} __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl;

interface __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress
{
    CONST_VTBL struct __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_Invoke(This,asyncInfo,progressInfo)	\
    ( (This)->lpVtbl -> Invoke(This,asyncInfo,progressInfo) ) 
#endif /* COBJMACROS */


#endif // ____FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000



#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__)
#define ____FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress;

//  Forward declare the async operation.
typedef interface __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress;

typedef struct __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [in] */ __RPC__in_opt __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress *asyncInfo, /* [in] */ AsyncStatus status);
    END_INTERFACE
} __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl;

interface __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress
{
    CONST_VTBL struct __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl *lpVtbl;
};



#ifdef COBJMACROS
#define __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_Invoke(This,asyncInfo,status)	\
    ( (This)->lpVtbl -> Invoke(This,asyncInfo,status) ) 
#endif /* COBJMACROS */



#endif // ____FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000



#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__)
#define ____FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress;

typedef struct __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Progress )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [in] */ __RPC__in_opt __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress *handler);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Progress )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [retval][out] */ __RPC__deref_out_opt __FIAsyncOperationProgressHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress **handler);
    /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Completed )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [in] */ __RPC__in_opt __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress *handler);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Completed )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [retval][out] */ __RPC__deref_out_opt __FIAsyncOperationWithProgressCompletedHandler_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress **handler);
    HRESULT ( STDMETHODCALLTYPE *GetResults )(__RPC__in __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * This, /* [retval][out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * *results);
    END_INTERFACE
} __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl;

interface __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress
{
    CONST_VTBL struct __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgressVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 

#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_put_Progress(This,handler)	\
    ( (This)->lpVtbl -> put_Progress(This,handler) ) 
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_get_Progress(This,handler)	\
    ( (This)->lpVtbl -> get_Progress(This,handler) ) 
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_put_Completed(This,handler)	\
    ( (This)->lpVtbl -> put_Completed(This,handler) ) 
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_get_Completed(This,handler)	\
    ( (This)->lpVtbl -> get_Completed(This,handler) ) 
#define __FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_GetResults(This,results)	\
    ( (This)->lpVtbl -> GetResults(This,results) ) 
#endif /* COBJMACROS */



#endif // ____FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CFoundation__CUri __FIIterator_1_Windows__CFoundation__CUri;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CFoundation__CUri;

typedef struct __FIIterator_1_Windows__CFoundation__CUriVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_Windows__CFoundation__CUri * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This, /* [retval][out] */ __RPC__out __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_Windows__CFoundation__CUri * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1_Windows__CFoundation__CUriVtbl;

interface __FIIterator_1_Windows__CFoundation__CUri
{
    CONST_VTBL struct __FIIterator_1_Windows__CFoundation__CUriVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1_Windows__CFoundation__CUri_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_Windows__CFoundation__CUri_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_Windows__CFoundation__CUri_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_Windows__CFoundation__CUri_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_Windows__CFoundation__CUri_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_Windows__CFoundation__CUri_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_Windows__CFoundation__CUri_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_Windows__CFoundation__CUri_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_Windows__CFoundation__CUri_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_Windows__CFoundation__CUri_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CFoundation__CUri __FIIterable_1_Windows__CFoundation__CUri;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CFoundation__CUri;

typedef  struct __FIIterable_1_Windows__CFoundation__CUriVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_Windows__CFoundation__CUri * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_Windows__CFoundation__CUri * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_Windows__CFoundation__CUri * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_Windows__CFoundation__CUri * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_Windows__CFoundation__CUri * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_Windows__CFoundation__CUri * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_Windows__CFoundation__CUri * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_Windows__CFoundation__CUri **first);

    END_INTERFACE
} __FIIterable_1_Windows__CFoundation__CUriVtbl;

interface __FIIterable_1_Windows__CFoundation__CUri
{
    CONST_VTBL struct __FIIterable_1_Windows__CFoundation__CUriVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CFoundation__CUri_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_Windows__CFoundation__CUri_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_Windows__CFoundation__CUri_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_Windows__CFoundation__CUri_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_Windows__CFoundation__CUri_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_Windows__CFoundation__CUri_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_Windows__CFoundation__CUri_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CFoundation__CUri __FIVectorView_1_Windows__CFoundation__CUri;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CFoundation__CUri;

typedef struct __FIVectorView_1_Windows__CFoundation__CUriVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )( __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This);

    ULONG ( STDMETHODCALLTYPE *Release )( __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )( __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This,
                                            /* [out] */ __RPC__out ULONG *iidCount,
                                            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
        __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
        __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )( 
                                         __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This,
                                         /* [in] */ unsigned int index,
                                         /* [retval][out] */ __RPC__out __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *item);

        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This,
            /* [retval][out] */ __RPC__out unsigned int *size);

        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
                                               __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This,
            /* [in] */ __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * item,
            /* [out] */ __RPC__out unsigned int *index,
            /* [retval][out] */ __RPC__out boolean *found);

        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
                                               __RPC__in __FIVectorView_1_Windows__CFoundation__CUri * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *items,
            /* [retval][out] */ __RPC__out unsigned int *actual);

        END_INTERFACE
} __FIVectorView_1_Windows__CFoundation__CUriVtbl;

interface __FIVectorView_1_Windows__CFoundation__CUri
{
    CONST_VTBL struct __FIVectorView_1_Windows__CFoundation__CUriVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVectorView_1_Windows__CFoundation__CUri_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVectorView_1_Windows__CFoundation__CUri_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVectorView_1_Windows__CFoundation__CUri_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVectorView_1_Windows__CFoundation__CUri_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVectorView_1_Windows__CFoundation__CUri_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVectorView_1_Windows__CFoundation__CUri_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVectorView_1_Windows__CFoundation__CUri_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVectorView_1_Windows__CFoundation__CUri_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVectorView_1_Windows__CFoundation__CUri_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVectorView_1_Windows__CFoundation__CUri_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#endif /* COBJMACROS */



#endif // ____FIVectorView_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CFoundation__CUri __FIVector_1_Windows__CFoundation__CUri;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CFoundation__CUri;

typedef struct __FIVector_1_Windows__CFoundation__CUriVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This, /* [out] */ __RPC__deref_out_opt __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
        /* [in] */ unsigned int index,
        /* [retval][out] */ __RPC__deref_out_opt __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *item);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
        __RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
        /* [retval][out] */ __RPC__out unsigned int *size);

    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This, /* [retval][out] */ __RPC__deref_out_opt __FIVectorView_1_Windows__CFoundation__CUri **view);

    HRESULT ( STDMETHODCALLTYPE *IndexOf )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
        /* [in] */ __RPC__in __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * item,
        /* [out] */ __RPC__out unsigned int *index,
        /* [retval][out] */ __RPC__out boolean *found);

    HRESULT ( STDMETHODCALLTYPE *SetAt )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * item);

    HRESULT ( STDMETHODCALLTYPE *InsertAt )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * item);

    HRESULT ( STDMETHODCALLTYPE *RemoveAt )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This, /* [in] */ unsigned int index);
    HRESULT ( STDMETHODCALLTYPE *Append )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This, /* [in] */ __RPC__in __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * item);
    HRESULT ( STDMETHODCALLTYPE *RemoveAtEnd )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
        /* [in] */ unsigned int startIndex,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    HRESULT ( STDMETHODCALLTYPE *ReplaceAll )(__RPC__in __FIVector_1_Windows__CFoundation__CUri * This,
        /* [in] */ unsigned int count,
        /* [size_is][in] */ __RPC__in_ecount_full(count) __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *value);

    END_INTERFACE
} __FIVector_1_Windows__CFoundation__CUriVtbl;

interface __FIVector_1_Windows__CFoundation__CUri
{
    CONST_VTBL struct __FIVector_1_Windows__CFoundation__CUriVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVector_1_Windows__CFoundation__CUri_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVector_1_Windows__CFoundation__CUri_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVector_1_Windows__CFoundation__CUri_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVector_1_Windows__CFoundation__CUri_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVector_1_Windows__CFoundation__CUri_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVector_1_Windows__CFoundation__CUri_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVector_1_Windows__CFoundation__CUri_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVector_1_Windows__CFoundation__CUri_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVector_1_Windows__CFoundation__CUri_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIVector_1_Windows__CFoundation__CUri_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVector_1_Windows__CFoundation__CUri_SetAt(This,index,item)	\
    ( (This)->lpVtbl -> SetAt(This,index,item) ) 

#define __FIVector_1_Windows__CFoundation__CUri_InsertAt(This,index,item)	\
    ( (This)->lpVtbl -> InsertAt(This,index,item) ) 

#define __FIVector_1_Windows__CFoundation__CUri_RemoveAt(This,index)	\
    ( (This)->lpVtbl -> RemoveAt(This,index) ) 

#define __FIVector_1_Windows__CFoundation__CUri_Append(This,item)	\
    ( (This)->lpVtbl -> Append(This,item) ) 

#define __FIVector_1_Windows__CFoundation__CUri_RemoveAtEnd(This)	\
    ( (This)->lpVtbl -> RemoveAtEnd(This) ) 

#define __FIVector_1_Windows__CFoundation__CUri_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define __FIVector_1_Windows__CFoundation__CUri_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#define __FIVector_1_Windows__CFoundation__CUri_ReplaceAll(This,count,value)	\
    ( (This)->lpVtbl -> ReplaceAll(This,count,value) ) 

#endif /* COBJMACROS */



#endif // ____FIVector_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if !defined(____FIIterator_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterator_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterator_1_HSTRING __FIIterator_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_HSTRING;

typedef struct __FIIterator_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_HSTRING * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_HSTRING * This, /* [retval][out] */ __RPC__out HSTRING *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_HSTRING * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_HSTRING * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_HSTRING * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) HSTRING *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1_HSTRINGVtbl;

interface __FIIterator_1_HSTRING
{
    CONST_VTBL struct __FIIterator_1_HSTRINGVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_HSTRING_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_HSTRING_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_HSTRING_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_HSTRING_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1_HSTRING_INTERFACE_DEFINED__


#if !defined(____FIIterable_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterable_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterable_1_HSTRING __FIIterable_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_HSTRING;

typedef  struct __FIIterable_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_HSTRING * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_HSTRING * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_HSTRING * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_HSTRING **first);

    END_INTERFACE
} __FIIterable_1_HSTRINGVtbl;

interface __FIIterable_1_HSTRING
{
    CONST_VTBL struct __FIIterable_1_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_HSTRING_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1_HSTRING_INTERFACE_DEFINED__


#if !defined(____FIVectorView_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIVectorView_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_HSTRING __FIVectorView_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_HSTRING;

typedef struct __FIVectorView_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVectorView_1_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )( __RPC__in __FIVectorView_1_HSTRING * This);

    ULONG ( STDMETHODCALLTYPE *Release )( __RPC__in __FIVectorView_1_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )( __RPC__in __FIVectorView_1_HSTRING * This,
                                            /* [out] */ __RPC__out ULONG *iidCount,
                                            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
        __RPC__in __FIVectorView_1_HSTRING * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
        __RPC__in __FIVectorView_1_HSTRING * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )( 
                                         __RPC__in __FIVectorView_1_HSTRING * This,
                                         /* [in] */ unsigned int index,
                                         /* [retval][out] */ __RPC__out HSTRING *item);

        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in __FIVectorView_1_HSTRING * This,
            /* [retval][out] */ __RPC__out unsigned int *size);

        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
                                               __RPC__in __FIVectorView_1_HSTRING * This,
            /* [in] */ HSTRING item,
            /* [out] */ __RPC__out unsigned int *index,
            /* [retval][out] */ __RPC__out boolean *found);

        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
                                               __RPC__in __FIVectorView_1_HSTRING * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) HSTRING *items,
            /* [retval][out] */ __RPC__out unsigned int *actual);

        END_INTERFACE
} __FIVectorView_1_HSTRINGVtbl;

interface __FIVectorView_1_HSTRING
{
    CONST_VTBL struct __FIVectorView_1_HSTRINGVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVectorView_1_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVectorView_1_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVectorView_1_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVectorView_1_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVectorView_1_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVectorView_1_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVectorView_1_HSTRING_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVectorView_1_HSTRING_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVectorView_1_HSTRING_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVectorView_1_HSTRING_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#endif /* COBJMACROS */



#endif // ____FIVectorView_1_HSTRING_INTERFACE_DEFINED__


#if !defined(____FIVector_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIVector_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIVector_1_HSTRING __FIVector_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_HSTRING;

typedef struct __FIVector_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVector_1_HSTRING * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIVector_1_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIVector_1_HSTRING * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIVector_1_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIVector_1_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIVector_1_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )(__RPC__in __FIVector_1_HSTRING * This,
        /* [in] */ unsigned int index,
        /* [retval][out] */ __RPC__deref_out_opt HSTRING *item);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
        __RPC__in __FIVector_1_HSTRING * This,
        /* [retval][out] */ __RPC__out unsigned int *size);

    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIVector_1_HSTRING * This, /* [retval][out] */ __RPC__deref_out_opt __FIVectorView_1_HSTRING **view);

    HRESULT ( STDMETHODCALLTYPE *IndexOf )(__RPC__in __FIVector_1_HSTRING * This,
        /* [in] */ __RPC__in HSTRING item,
        /* [out] */ __RPC__out unsigned int *index,
        /* [retval][out] */ __RPC__out boolean *found);

    HRESULT ( STDMETHODCALLTYPE *SetAt )(__RPC__in __FIVector_1_HSTRING * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in HSTRING item);

    HRESULT ( STDMETHODCALLTYPE *InsertAt )(__RPC__in __FIVector_1_HSTRING * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in HSTRING item);

    HRESULT ( STDMETHODCALLTYPE *RemoveAt )(__RPC__in __FIVector_1_HSTRING * This, /* [in] */ unsigned int index);
    HRESULT ( STDMETHODCALLTYPE *Append )(__RPC__in __FIVector_1_HSTRING * This, /* [in] */ __RPC__in HSTRING item);
    HRESULT ( STDMETHODCALLTYPE *RemoveAtEnd )(__RPC__in __FIVector_1_HSTRING * This);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIVector_1_HSTRING * This);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIVector_1_HSTRING * This,
        /* [in] */ unsigned int startIndex,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) HSTRING *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    HRESULT ( STDMETHODCALLTYPE *ReplaceAll )(__RPC__in __FIVector_1_HSTRING * This,
        /* [in] */ unsigned int count,
        /* [size_is][in] */ __RPC__in_ecount_full(count) HSTRING *value);

    END_INTERFACE
} __FIVector_1_HSTRINGVtbl;

interface __FIVector_1_HSTRING
{
    CONST_VTBL struct __FIVector_1_HSTRINGVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIVector_1_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVector_1_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVector_1_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVector_1_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVector_1_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVector_1_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVector_1_HSTRING_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVector_1_HSTRING_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVector_1_HSTRING_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIVector_1_HSTRING_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVector_1_HSTRING_SetAt(This,index,item)	\
    ( (This)->lpVtbl -> SetAt(This,index,item) ) 

#define __FIVector_1_HSTRING_InsertAt(This,index,item)	\
    ( (This)->lpVtbl -> InsertAt(This,index,item) ) 

#define __FIVector_1_HSTRING_RemoveAt(This,index)	\
    ( (This)->lpVtbl -> RemoveAt(This,index) ) 

#define __FIVector_1_HSTRING_Append(This,item)	\
    ( (This)->lpVtbl -> Append(This,item) ) 

#define __FIVector_1_HSTRING_RemoveAtEnd(This)	\
    ( (This)->lpVtbl -> RemoveAtEnd(This) ) 

#define __FIVector_1_HSTRING_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define __FIVector_1_HSTRING_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#define __FIVector_1_HSTRING_ReplaceAll(This,count,value)	\
    ( (This)->lpVtbl -> ReplaceAll(This,count,value) ) 

#endif /* COBJMACROS */



#endif // ____FIVector_1_HSTRING_INTERFACE_DEFINED__



#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__)
#define ____FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

typedef interface __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING;

typedef struct __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This,
            /* [out] */ __RPC__out ULONG *iidCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )(__RPC__in __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__out __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * *key);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )(__RPC__in __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__deref_out_opt HSTRING *value);
    END_INTERFACE
} __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl;

interface __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING
{
    CONST_VTBL struct __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_get_Key(This,key)	\
    ( (This)->lpVtbl -> get_Key(This,key) ) 

#define __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_get_Value(This,value)	\
    ( (This)->lpVtbl -> get_Value(This,value) ) 
#endif /* COBJMACROS */


#endif // ____FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING;

typedef struct __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__out __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl;

interface __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING
{
    CONST_VTBL struct __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING;

typedef  struct __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING **first);

    END_INTERFACE
} __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl;

interface __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING
{
    CONST_VTBL struct __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1___FIKeyValuePair_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIMapView_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__)
#define ____FIMapView_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

typedef interface __FIMapView_2_Windows__CFoundation__CUri_HSTRING __FIMapView_2_Windows__CFoundation__CUri_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMapView_2_Windows__CFoundation__CUri_HSTRING;

typedef struct __FIMapView_2_Windows__CFoundation__CUri_HSTRINGVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This,/* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *Lookup )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ __RPC__in __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * key,
        /* [retval][out] */ __RPC__deref_out_opt HSTRING *value);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__out unsigned int *size);
    HRESULT ( STDMETHODCALLTYPE *HasKey )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This, /* [in] */ __RPC__in __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * key, /* [retval][out] */ __RPC__out boolean *found);
    HRESULT ( STDMETHODCALLTYPE *Split )(__RPC__in __FIMapView_2_Windows__CFoundation__CUri_HSTRING * This,/* [out] */ __RPC__deref_out_opt __FIMapView_2_Windows__CFoundation__CUri_HSTRING **firstPartition,
        /* [out] */ __RPC__deref_out_opt __FIMapView_2_Windows__CFoundation__CUri_HSTRING **secondPartition);
    END_INTERFACE
} __FIMapView_2_Windows__CFoundation__CUri_HSTRINGVtbl;

interface __FIMapView_2_Windows__CFoundation__CUri_HSTRING
{
    CONST_VTBL struct __FIMapView_2_Windows__CFoundation__CUri_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 

#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_Lookup(This,key,value)	\
    ( (This)->lpVtbl -> Lookup(This,key,value) ) 
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_HasKey(This,key,found)	\
    ( (This)->lpVtbl -> HasKey(This,key,found) ) 
#define __FIMapView_2_Windows__CFoundation__CUri_HSTRING_Split(This,firstPartition,secondPartition)	\
    ( (This)->lpVtbl -> Split(This,firstPartition,secondPartition) ) 
#endif /* COBJMACROS */


#endif // ____FIMapView_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIMap_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__)
#define ____FIMap_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

typedef interface __FIMap_2_Windows__CFoundation__CUri_HSTRING __FIMap_2_Windows__CFoundation__CUri_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMap_2_Windows__CFoundation__CUri_HSTRING;

typedef struct __FIMap_2_Windows__CFoundation__CUri_HSTRINGVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *Lookup )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * key,
        /* [retval][out] */ __RPC__deref_out_opt HSTRING **value);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__out unsigned int *size);
    HRESULT ( STDMETHODCALLTYPE *HasKey )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This, /* [in] */ __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * key, /* [retval][out] */ __RPC__out boolean *found);
    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This, /* [retval][out] */ __RPC__deref_out_opt __FIMapView_2_Windows__CFoundation__CUri_HSTRING **view);
    HRESULT ( STDMETHODCALLTYPE *Insert )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This,
        /* [in] */ __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * key,
        /* [in] */ __RPC__in_opt HSTRING *value,
        /* [retval][out] */ __RPC__out boolean *replaced);
    HRESULT ( STDMETHODCALLTYPE *Remove )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This,/* [in] */ __x_ABI_CWindows_CFoundation_CIUriRuntimeClass * key);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIMap_2_Windows__CFoundation__CUri_HSTRING * This);
    END_INTERFACE
} __FIMap_2_Windows__CFoundation__CUri_HSTRINGVtbl;

interface __FIMap_2_Windows__CFoundation__CUri_HSTRING
{
    CONST_VTBL struct __FIMap_2_Windows__CFoundation__CUri_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_Lookup(This,key,value)	\
    ( (This)->lpVtbl -> Lookup(This,key,value) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_HasKey(This,key,found)	\
    ( (This)->lpVtbl -> HasKey(This,key,found) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_Insert(This,key,value,replaced)	\
    ( (This)->lpVtbl -> Insert(This,key,value,replaced) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_Remove(This,key)	\
    ( (This)->lpVtbl -> Remove(This,key) ) 

#define __FIMap_2_Windows__CFoundation__CUri_HSTRING_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 
#endif /* COBJMACROS */



#endif // ____FIMap_2_Windows__CFoundation__CUri_HSTRING_INTERFACE_DEFINED__

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__


#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__



typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyContextId __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyContextId;


typedef enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures;






typedef struct __x_ABI_CWindows_CApplicationModel_CPackageVersion __x_ABI_CWindows_CApplicationModel_CPackageVersion;








typedef enum __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgressStatus __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgressStatus;


typedef enum __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentStatus __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentStatus;


typedef enum __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CStubPackageOption __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CStubPackageOption;


typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgress __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgress;











































/*
 *
 * Struct Microsoft.Windows.Management.Deployment.PackageDeploymentProgressStatus
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgressStatus
{
    PackageDeploymentProgressStatus_Queued = 0,
    PackageDeploymentProgressStatus_InProgress = 1,
    PackageDeploymentProgressStatus_CompletedSuccess = 2,
    PackageDeploymentProgressStatus_CompletedFailure = 3,
};
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.Management.Deployment.PackageDeploymentStatus
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentStatus
{
    PackageDeploymentStatus_InProgress = 0,
    PackageDeploymentStatus_CompletedSuccess = 1,
    PackageDeploymentStatus_CompletedFailure = 2,
};
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.Management.Deployment.StubPackageOption
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CStubPackageOption
{
    StubPackageOption_Default = 0,
    StubPackageOption_InstallFull = 1,
    StubPackageOption_InstallStub = 2,
    StubPackageOption_UsePreference = 3,
};
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.Management.Deployment.PackageDeploymentProgress
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

/* [contract] */
struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgress
{
    __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentProgressStatus Status;
    DOUBLE Progress;
};
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IAddPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.AddPackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IAddPackageOptions[] = L"Microsoft.Windows.Management.Deployment.IAddPackageOptions";
/* [object, uuid("E3DB7F39-F9D0-5884-BDEF-6153B54574A3"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_TargetVolume )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_TargetVolume )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DependencyPackageUris )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OptionalPackageFamilyNames )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */__FIVector_1_HSTRING * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OptionalPackageUris )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RelatedPackageUris )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExternalLocationUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ExternalLocationUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_StubPackageOption )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CStubPackageOption * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_StubPackageOption )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CStubPackageOption value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AllowUnsigned )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AllowUnsigned )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DeveloperMode )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_DeveloperMode )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ForceAppShutdown )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ForceAppShutdown )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ForceTargetAppShutdown )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ForceTargetAppShutdown )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ForceUpdateFromAnyVersion )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ForceUpdateFromAnyVersion )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InstallAllResources )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_InstallAllResources )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RequiredContentGroupOnly )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_RequiredContentGroupOnly )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RetainFilesOnFailure )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_RetainFilesOnFailure )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_StageInPlace )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_StageInPlace )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DeferRegistrationWhenPackagesAreInUse )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_DeferRegistrationWhenPackagesAreInUse )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsExpectedDigestsSupported )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExpectedDigests )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */__FIMap_2_Windows__CFoundation__CUri_HSTRING * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsLimitToExistingPackagesSupported )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LimitToExistingPackages )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_LimitToExistingPackages )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * This,
        /* [in] */boolean value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_TargetVolume(This,value) \
    ( (This)->lpVtbl->get_TargetVolume(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_TargetVolume(This,value) \
    ( (This)->lpVtbl->put_TargetVolume(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_DependencyPackageUris(This,value) \
    ( (This)->lpVtbl->get_DependencyPackageUris(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_OptionalPackageFamilyNames(This,value) \
    ( (This)->lpVtbl->get_OptionalPackageFamilyNames(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_OptionalPackageUris(This,value) \
    ( (This)->lpVtbl->get_OptionalPackageUris(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_RelatedPackageUris(This,value) \
    ( (This)->lpVtbl->get_RelatedPackageUris(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ExternalLocationUri(This,value) \
    ( (This)->lpVtbl->get_ExternalLocationUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_ExternalLocationUri(This,value) \
    ( (This)->lpVtbl->put_ExternalLocationUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_StubPackageOption(This,value) \
    ( (This)->lpVtbl->get_StubPackageOption(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_StubPackageOption(This,value) \
    ( (This)->lpVtbl->put_StubPackageOption(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_AllowUnsigned(This,value) \
    ( (This)->lpVtbl->get_AllowUnsigned(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_AllowUnsigned(This,value) \
    ( (This)->lpVtbl->put_AllowUnsigned(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_DeveloperMode(This,value) \
    ( (This)->lpVtbl->get_DeveloperMode(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_DeveloperMode(This,value) \
    ( (This)->lpVtbl->put_DeveloperMode(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ForceAppShutdown(This,value) \
    ( (This)->lpVtbl->get_ForceAppShutdown(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_ForceAppShutdown(This,value) \
    ( (This)->lpVtbl->put_ForceAppShutdown(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ForceTargetAppShutdown(This,value) \
    ( (This)->lpVtbl->get_ForceTargetAppShutdown(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_ForceTargetAppShutdown(This,value) \
    ( (This)->lpVtbl->put_ForceTargetAppShutdown(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ForceUpdateFromAnyVersion(This,value) \
    ( (This)->lpVtbl->get_ForceUpdateFromAnyVersion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_ForceUpdateFromAnyVersion(This,value) \
    ( (This)->lpVtbl->put_ForceUpdateFromAnyVersion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_InstallAllResources(This,value) \
    ( (This)->lpVtbl->get_InstallAllResources(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_InstallAllResources(This,value) \
    ( (This)->lpVtbl->put_InstallAllResources(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_RequiredContentGroupOnly(This,value) \
    ( (This)->lpVtbl->get_RequiredContentGroupOnly(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_RequiredContentGroupOnly(This,value) \
    ( (This)->lpVtbl->put_RequiredContentGroupOnly(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_RetainFilesOnFailure(This,value) \
    ( (This)->lpVtbl->get_RetainFilesOnFailure(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_RetainFilesOnFailure(This,value) \
    ( (This)->lpVtbl->put_RetainFilesOnFailure(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_StageInPlace(This,value) \
    ( (This)->lpVtbl->get_StageInPlace(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_StageInPlace(This,value) \
    ( (This)->lpVtbl->put_StageInPlace(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_DeferRegistrationWhenPackagesAreInUse(This,value) \
    ( (This)->lpVtbl->get_DeferRegistrationWhenPackagesAreInUse(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_DeferRegistrationWhenPackagesAreInUse(This,value) \
    ( (This)->lpVtbl->put_DeferRegistrationWhenPackagesAreInUse(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_IsExpectedDigestsSupported(This,value) \
    ( (This)->lpVtbl->get_IsExpectedDigestsSupported(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ExpectedDigests(This,value) \
    ( (This)->lpVtbl->get_ExpectedDigests(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_IsLimitToExistingPackagesSupported(This,value) \
    ( (This)->lpVtbl->get_IsLimitToExistingPackagesSupported(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_LimitToExistingPackages(This,value) \
    ( (This)->lpVtbl->get_LimitToExistingPackages(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_LimitToExistingPackages(This,value) \
    ( (This)->lpVtbl->put_LimitToExistingPackages(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IEnsureReadyOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.EnsureReadyOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IEnsureReadyOptions[] = L"Microsoft.Windows.Management.Deployment.IEnsureReadyOptions";
/* [object, uuid("20102D03-EC44-5C2B-8FD6-1104DC99755D"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AddPackageOptions )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_get_AddPackageOptions(This,value) \
    ( (This)->lpVtbl->get_AddPackageOptions(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageDeploymentManager
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageDeploymentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageDeploymentManager[] = L"Microsoft.Windows.Management.Deployment.IPackageDeploymentManager";
/* [object, uuid("F41717D8-5AB2-57AC-83CD-D0C48CC784CD"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *IsPackageReady )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [retval, out] */boolean * result
        );
    HRESULT ( STDMETHODCALLTYPE *IsPackageReadyByUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [retval, out] */boolean * result
        );
    HRESULT ( STDMETHODCALLTYPE *IsPackageSetReady )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [retval, out] */boolean * result
        );
    HRESULT ( STDMETHODCALLTYPE *EnsurePackageReadyAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *EnsurePackageReadyByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *EnsurePackageSetReadyAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIEnsureReadyOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *AddPackageAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *AddPackageByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *AddPackageSetAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIAddPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *StagePackageAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *StagePackageByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *StagePackageSetAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RegisterPackageAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RegisterPackageByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RegisterPackageSetAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RemovePackageAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RemovePackageByFullNameAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING packageFullName,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RemovePackageByFamilyNameAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING packageFamilyName,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RemovePackageByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RemovePackageSetAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *ResetPackageAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *ResetPackageByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *ResetPackageSetAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RepairPackageAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RepairPackageByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *RepairPackageSetAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *ProvisionPackageAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *ProvisionPackageByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *ProvisionPackageSetAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * options,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *DeprovisionPackageAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING package,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *DeprovisionPackageByUriAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * packageUri,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *DeprovisionPackageSetAsync )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [retval, out] */__FIAsyncOperationWithProgress_2_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentResult_Microsoft__CWindows__CManagement__CDeployment__CPackageDeploymentProgress * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *IsPackageRegistrationPending )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING packageFamilyName,
        /* [retval, out] */boolean * result
        );
    HRESULT ( STDMETHODCALLTYPE *IsPackageRegistrationPendingForUser )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * This,
        /* [in] */HSTRING userSecurityId,
        /* [in] */HSTRING packageFamilyName,
        /* [retval, out] */boolean * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_IsPackageReady(This,package,result) \
    ( (This)->lpVtbl->IsPackageReady(This,package,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_IsPackageReadyByUri(This,packageUri,result) \
    ( (This)->lpVtbl->IsPackageReadyByUri(This,packageUri,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_IsPackageSetReady(This,packageSet,result) \
    ( (This)->lpVtbl->IsPackageSetReady(This,packageSet,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_EnsurePackageReadyAsync(This,package,options,operation) \
    ( (This)->lpVtbl->EnsurePackageReadyAsync(This,package,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_EnsurePackageReadyByUriAsync(This,packageUri,options,operation) \
    ( (This)->lpVtbl->EnsurePackageReadyByUriAsync(This,packageUri,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_EnsurePackageSetReadyAsync(This,packageSet,options,operation) \
    ( (This)->lpVtbl->EnsurePackageSetReadyAsync(This,packageSet,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_AddPackageAsync(This,package,options,operation) \
    ( (This)->lpVtbl->AddPackageAsync(This,package,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_AddPackageByUriAsync(This,packageUri,options,operation) \
    ( (This)->lpVtbl->AddPackageByUriAsync(This,packageUri,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_AddPackageSetAsync(This,packageSet,options,operation) \
    ( (This)->lpVtbl->AddPackageSetAsync(This,packageSet,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_StagePackageAsync(This,package,options,operation) \
    ( (This)->lpVtbl->StagePackageAsync(This,package,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_StagePackageByUriAsync(This,packageUri,options,operation) \
    ( (This)->lpVtbl->StagePackageByUriAsync(This,packageUri,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_StagePackageSetAsync(This,packageSet,options,operation) \
    ( (This)->lpVtbl->StagePackageSetAsync(This,packageSet,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RegisterPackageAsync(This,package,options,operation) \
    ( (This)->lpVtbl->RegisterPackageAsync(This,package,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RegisterPackageByUriAsync(This,packageUri,options,operation) \
    ( (This)->lpVtbl->RegisterPackageByUriAsync(This,packageUri,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RegisterPackageSetAsync(This,packageSet,options,operation) \
    ( (This)->lpVtbl->RegisterPackageSetAsync(This,packageSet,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RemovePackageAsync(This,package,options,operation) \
    ( (This)->lpVtbl->RemovePackageAsync(This,package,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RemovePackageByFullNameAsync(This,packageFullName,options,operation) \
    ( (This)->lpVtbl->RemovePackageByFullNameAsync(This,packageFullName,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RemovePackageByFamilyNameAsync(This,packageFamilyName,options,operation) \
    ( (This)->lpVtbl->RemovePackageByFamilyNameAsync(This,packageFamilyName,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RemovePackageByUriAsync(This,packageUri,options,operation) \
    ( (This)->lpVtbl->RemovePackageByUriAsync(This,packageUri,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RemovePackageSetAsync(This,packageSet,options,operation) \
    ( (This)->lpVtbl->RemovePackageSetAsync(This,packageSet,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_ResetPackageAsync(This,package,operation) \
    ( (This)->lpVtbl->ResetPackageAsync(This,package,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_ResetPackageByUriAsync(This,packageUri,operation) \
    ( (This)->lpVtbl->ResetPackageByUriAsync(This,packageUri,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_ResetPackageSetAsync(This,packageSet,operation) \
    ( (This)->lpVtbl->ResetPackageSetAsync(This,packageSet,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RepairPackageAsync(This,package,operation) \
    ( (This)->lpVtbl->RepairPackageAsync(This,package,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RepairPackageByUriAsync(This,packageUri,operation) \
    ( (This)->lpVtbl->RepairPackageByUriAsync(This,packageUri,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_RepairPackageSetAsync(This,packageSet,operation) \
    ( (This)->lpVtbl->RepairPackageSetAsync(This,packageSet,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_ProvisionPackageAsync(This,package,options,operation) \
    ( (This)->lpVtbl->ProvisionPackageAsync(This,package,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_ProvisionPackageByUriAsync(This,packageUri,options,operation) \
    ( (This)->lpVtbl->ProvisionPackageByUriAsync(This,packageUri,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_ProvisionPackageSetAsync(This,packageSet,options,operation) \
    ( (This)->lpVtbl->ProvisionPackageSetAsync(This,packageSet,options,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_DeprovisionPackageAsync(This,package,operation) \
    ( (This)->lpVtbl->DeprovisionPackageAsync(This,package,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_DeprovisionPackageByUriAsync(This,packageUri,operation) \
    ( (This)->lpVtbl->DeprovisionPackageByUriAsync(This,packageUri,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_DeprovisionPackageSetAsync(This,packageSet,operation) \
    ( (This)->lpVtbl->DeprovisionPackageSetAsync(This,packageSet,operation) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_IsPackageRegistrationPending(This,packageFamilyName,result) \
    ( (This)->lpVtbl->IsPackageRegistrationPending(This,packageFamilyName,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_IsPackageRegistrationPendingForUser(This,userSecurityId,packageFamilyName,result) \
    ( (This)->lpVtbl->IsPackageRegistrationPendingForUser(This,userSecurityId,packageFamilyName,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageDeploymentManagerStatics
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageDeploymentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageDeploymentManagerStatics[] = L"Microsoft.Windows.Management.Deployment.IPackageDeploymentManagerStatics";
/* [object, uuid("DBDA4AC6-CA28-59B8-9FC6-DBFB5765F1C2"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetDefault )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManager * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_GetDefault(This,result) \
    ( (This)->lpVtbl->GetDefault(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageDeploymentResult
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageDeploymentResult
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageDeploymentResult[] = L"Microsoft.Windows.Management.Deployment.IPackageDeploymentResult";
/* [object, uuid("D6B99601-18C2-599E-8BD1-40A9310AD263"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResultVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Status )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CPackageDeploymentStatus * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Error )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
        /* [retval, out] */HRESULT * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExtendedError )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
        /* [retval, out] */HRESULT * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ErrorText )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ActivityId )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult * This,
        /* [retval, out] */GUID * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResultVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResultVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_get_Status(This,value) \
    ( (This)->lpVtbl->get_Status(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_get_Error(This,value) \
    ( (This)->lpVtbl->get_Error(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_get_ExtendedError(This,value) \
    ( (This)->lpVtbl->get_ExtendedError(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_get_ErrorText(This,value) \
    ( (This)->lpVtbl->get_ErrorText(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_get_ActivityId(This,value) \
    ( (This)->lpVtbl->get_ActivityId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageDeploymentResult_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageRuntimeManager
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageRuntimeManager
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageRuntimeManager[] = L"Microsoft.Windows.Management.Deployment.IPackageRuntimeManager";
/* [object, uuid("6BF0FD29-6C2A-58D1-AF0C-ABD2EAC45E29"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [overload] */HRESULT ( STDMETHODCALLTYPE *AddPackageSet )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *AddPackageSetWithOptions )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * packageSet,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * createOptions,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * addOptions,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * * result
        );
    HRESULT ( STDMETHODCALLTYPE *RemovePackageSet )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * packageSetRuntimeDisposition
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_AddPackageSet(This,packageSet,result) \
    ( (This)->lpVtbl->AddPackageSet(This,packageSet,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_AddPackageSetWithOptions(This,packageSet,createOptions,addOptions,result) \
    ( (This)->lpVtbl->AddPackageSetWithOptions(This,packageSet,createOptions,addOptions,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_RemovePackageSet(This,packageSetRuntimeDisposition) \
    ( (This)->lpVtbl->RemovePackageSet(This,packageSetRuntimeDisposition) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageRuntimeManagerStatics
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageRuntimeManager
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageRuntimeManagerStatics[] = L"Microsoft.Windows.Management.Deployment.IPackageRuntimeManagerStatics";
/* [object, uuid("790947DE-01D4-5858-AA69-9C9390FB7D3E"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetDefault )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManager * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_GetDefault(This,result) \
    ( (This)->lpVtbl->GetDefault(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageRuntimeManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageSet
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageSet
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageSet[] = L"Microsoft.Windows.Management.Deployment.IPackageSet";
/* [object, uuid("229FDF93-8529-5F8D-988C-AF8A39AD46F7"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Id )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Id )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PackageUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Items )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet * This,
        /* [retval, out] */__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItem * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_get_Id(This,value) \
    ( (This)->lpVtbl->get_Id(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_put_Id(This,value) \
    ( (This)->lpVtbl->put_Id(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_get_PackageUri(This,value) \
    ( (This)->lpVtbl->get_PackageUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_put_PackageUri(This,value) \
    ( (This)->lpVtbl->put_PackageUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_get_Items(This,value) \
    ( (This)->lpVtbl->get_Items(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSet_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageSetItem
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageSetItem
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageSetItem[] = L"Microsoft.Windows.Management.Deployment.IPackageSetItem";
/* [object, uuid("8F254E15-C371-550F-B4E8-3F0BB1AE375F"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Id )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Id )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageFamilyName )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PackageFamilyName )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_MinVersion )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [retval, out] */__x_ABI_CWindows_CApplicationModel_CPackageVersion * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_MinVersion )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [in] */__x_ABI_CWindows_CApplicationModel_CPackageVersion value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ProcessorArchitectureFilter )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ProcessorArchitectureFilter )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PackageUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_get_Id(This,value) \
    ( (This)->lpVtbl->get_Id(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_put_Id(This,value) \
    ( (This)->lpVtbl->put_Id(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_get_PackageFamilyName(This,value) \
    ( (This)->lpVtbl->get_PackageFamilyName(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_put_PackageFamilyName(This,value) \
    ( (This)->lpVtbl->put_PackageFamilyName(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_get_MinVersion(This,value) \
    ( (This)->lpVtbl->get_MinVersion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_put_MinVersion(This,value) \
    ( (This)->lpVtbl->put_MinVersion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_get_ProcessorArchitectureFilter(This,value) \
    ( (This)->lpVtbl->get_ProcessorArchitectureFilter(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_put_ProcessorArchitectureFilter(This,value) \
    ( (This)->lpVtbl->put_ProcessorArchitectureFilter(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_get_PackageUri(This,value) \
    ( (This)->lpVtbl->get_PackageUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_put_PackageUri(This,value) \
    ( (This)->lpVtbl->put_PackageUri(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItem_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageSetItemRuntimeDisposition
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageSetItemRuntimeDisposition[] = L"Microsoft.Windows.Management.Deployment.IPackageSetItemRuntimeDisposition";
/* [object, uuid("7A7F9F70-D416-5F83-A3CD-027BF3D2ABFD"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDispositionVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageSetItemId )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageFullName )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageDependencyId )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageDependencyContextId )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyContextId * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDispositionVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDispositionVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_get_PackageSetItemId(This,value) \
    ( (This)->lpVtbl->get_PackageSetItemId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_get_PackageFullName(This,value) \
    ( (This)->lpVtbl->get_PackageFullName(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_get_PackageDependencyId(This,value) \
    ( (This)->lpVtbl->get_PackageDependencyId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_get_PackageDependencyContextId(This,value) \
    ( (This)->lpVtbl->get_PackageDependencyContextId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetItemRuntimeDisposition_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageSetRuntimeDisposition
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageSetRuntimeDisposition
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageSetRuntimeDisposition[] = L"Microsoft.Windows.Management.Deployment.IPackageSetRuntimeDisposition";
/* [object, uuid("C13F1088-EA36-5DB3-BCDD-E6D59E6C9B71"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDispositionVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageSetId )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PackageSetId )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageSetItemRuntimeDispositions )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition * This,
        /* [retval, out] */__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageSetItemRuntimeDisposition * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDispositionVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDispositionVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_get_PackageSetId(This,value) \
    ( (This)->lpVtbl->get_PackageSetId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_put_PackageSetId(This,value) \
    ( (This)->lpVtbl->put_PackageSetId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_get_PackageSetItemRuntimeDispositions(This,value) \
    ( (This)->lpVtbl->get_PackageSetItemRuntimeDispositions(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageSetRuntimeDisposition_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageVolume
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageVolume
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageVolume[] = L"Microsoft.Windows.Management.Deployment.IPackageVolume";
/* [object, uuid("9C9710F4-795A-58B3-93F4-C991C4329C49"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSystemVolume )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_MountPoint )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Name )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageStorePath )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SupportsHardLinks )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsFullTrustPackageSupported )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsAppxInstallSupported )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
        /* [retval, out] */boolean * value
        );
    HRESULT ( STDMETHODCALLTYPE *IsRepairNeeded )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This,
        /* [retval, out] */boolean * result
        );
    HRESULT ( STDMETHODCALLTYPE *Repair )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * This
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_get_IsSystemVolume(This,value) \
    ( (This)->lpVtbl->get_IsSystemVolume(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_get_MountPoint(This,value) \
    ( (This)->lpVtbl->get_MountPoint(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_get_Name(This,value) \
    ( (This)->lpVtbl->get_Name(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_get_PackageStorePath(This,value) \
    ( (This)->lpVtbl->get_PackageStorePath(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_get_SupportsHardLinks(This,value) \
    ( (This)->lpVtbl->get_SupportsHardLinks(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_get_IsFullTrustPackageSupported(This,value) \
    ( (This)->lpVtbl->get_IsFullTrustPackageSupported(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_get_IsAppxInstallSupported(This,value) \
    ( (This)->lpVtbl->get_IsAppxInstallSupported(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_IsRepairNeeded(This,result) \
    ( (This)->lpVtbl->IsRepairNeeded(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_Repair(This) \
    ( (This)->lpVtbl->Repair(This) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IPackageVolumeStatics
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.PackageVolume
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IPackageVolumeStatics[] = L"Microsoft.Windows.Management.Deployment.IPackageVolumeStatics";
/* [object, uuid("4C731835-8BC0-5313-9B56-8A4100EAEA01"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *FindPackageVolumes )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This,
        /* [retval, out] */__FIVector_1_Microsoft__CWindows__CManagement__CDeployment__CPackageVolume * * result
        );
    HRESULT ( STDMETHODCALLTYPE *FindPackageVolumeByPath )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This,
        /* [in] */HSTRING packageStorePath,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * * result
        );
    HRESULT ( STDMETHODCALLTYPE *FindPackageVolumeByName )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics * This,
        /* [in] */HSTRING name,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FindPackageVolumes(This,result) \
    ( (This)->lpVtbl->FindPackageVolumes(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FindPackageVolumeByPath(This,packageStorePath,result) \
    ( (This)->lpVtbl->FindPackageVolumeByPath(This,packageStorePath,result) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_FindPackageVolumeByName(This,name,result) \
    ( (This)->lpVtbl->FindPackageVolumeByName(This,name,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolumeStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IProvisionPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.ProvisionPackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IProvisionPackageOptions[] = L"Microsoft.Windows.Management.Deployment.IProvisionPackageOptions";
/* [object, uuid("415E300F-D1E3-581E-A114-76D277B06136"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsOptionalPackageFamilyNamesSupported )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OptionalPackageFamilyNames )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This,
        /* [retval, out] */__FIVector_1_HSTRING * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsProjectionOrderPackageFamilyNamesSupported )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ProjectionOrderPackageFamilyNames )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions * This,
        /* [retval, out] */__FIVector_1_HSTRING * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_get_IsOptionalPackageFamilyNamesSupported(This,value) \
    ( (This)->lpVtbl->get_IsOptionalPackageFamilyNamesSupported(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_get_OptionalPackageFamilyNames(This,value) \
    ( (This)->lpVtbl->get_OptionalPackageFamilyNames(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_get_IsProjectionOrderPackageFamilyNamesSupported(This,value) \
    ( (This)->lpVtbl->get_IsProjectionOrderPackageFamilyNamesSupported(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_get_ProjectionOrderPackageFamilyNames(This,value) \
    ( (This)->lpVtbl->get_ProjectionOrderPackageFamilyNames(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIProvisionPackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IRegisterPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.RegisterPackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IRegisterPackageOptions[] = L"Microsoft.Windows.Management.Deployment.IRegisterPackageOptions";
/* [object, uuid("83068623-2046-505F-8425-55226C0F84CC"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AppDataVolume )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AppDataVolume )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DependencyPackageFamilyNames )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */__FIVector_1_HSTRING * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DependencyPackageUris )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OptionalPackageFamilyNames )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */__FIVector_1_HSTRING * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExternalLocationUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ExternalLocationUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AllowUnsigned )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AllowUnsigned )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DeveloperMode )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_DeveloperMode )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ForceAppShutdown )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ForceAppShutdown )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ForceTargetAppShutdown )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ForceTargetAppShutdown )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ForceUpdateFromAnyVersion )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ForceUpdateFromAnyVersion )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InstallAllResources )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_InstallAllResources )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_StageInPlace )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_StageInPlace )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DeferRegistrationWhenPackagesAreInUse )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_DeferRegistrationWhenPackagesAreInUse )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsExpectedDigestsSupported )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExpectedDigests )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions * This,
        /* [retval, out] */__FIMap_2_Windows__CFoundation__CUri_HSTRING * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_AppDataVolume(This,value) \
    ( (This)->lpVtbl->get_AppDataVolume(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_AppDataVolume(This,value) \
    ( (This)->lpVtbl->put_AppDataVolume(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_DependencyPackageFamilyNames(This,value) \
    ( (This)->lpVtbl->get_DependencyPackageFamilyNames(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_DependencyPackageUris(This,value) \
    ( (This)->lpVtbl->get_DependencyPackageUris(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_OptionalPackageFamilyNames(This,value) \
    ( (This)->lpVtbl->get_OptionalPackageFamilyNames(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ExternalLocationUri(This,value) \
    ( (This)->lpVtbl->get_ExternalLocationUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_ExternalLocationUri(This,value) \
    ( (This)->lpVtbl->put_ExternalLocationUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_AllowUnsigned(This,value) \
    ( (This)->lpVtbl->get_AllowUnsigned(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_AllowUnsigned(This,value) \
    ( (This)->lpVtbl->put_AllowUnsigned(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_DeveloperMode(This,value) \
    ( (This)->lpVtbl->get_DeveloperMode(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_DeveloperMode(This,value) \
    ( (This)->lpVtbl->put_DeveloperMode(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ForceAppShutdown(This,value) \
    ( (This)->lpVtbl->get_ForceAppShutdown(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_ForceAppShutdown(This,value) \
    ( (This)->lpVtbl->put_ForceAppShutdown(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ForceTargetAppShutdown(This,value) \
    ( (This)->lpVtbl->get_ForceTargetAppShutdown(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_ForceTargetAppShutdown(This,value) \
    ( (This)->lpVtbl->put_ForceTargetAppShutdown(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ForceUpdateFromAnyVersion(This,value) \
    ( (This)->lpVtbl->get_ForceUpdateFromAnyVersion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_ForceUpdateFromAnyVersion(This,value) \
    ( (This)->lpVtbl->put_ForceUpdateFromAnyVersion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_InstallAllResources(This,value) \
    ( (This)->lpVtbl->get_InstallAllResources(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_InstallAllResources(This,value) \
    ( (This)->lpVtbl->put_InstallAllResources(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_StageInPlace(This,value) \
    ( (This)->lpVtbl->get_StageInPlace(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_StageInPlace(This,value) \
    ( (This)->lpVtbl->put_StageInPlace(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_DeferRegistrationWhenPackagesAreInUse(This,value) \
    ( (This)->lpVtbl->get_DeferRegistrationWhenPackagesAreInUse(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_DeferRegistrationWhenPackagesAreInUse(This,value) \
    ( (This)->lpVtbl->put_DeferRegistrationWhenPackagesAreInUse(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_IsExpectedDigestsSupported(This,value) \
    ( (This)->lpVtbl->get_IsExpectedDigestsSupported(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ExpectedDigests(This,value) \
    ( (This)->lpVtbl->get_ExpectedDigests(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IRemovePackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.RemovePackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IRemovePackageOptions[] = L"Microsoft.Windows.Management.Deployment.IRemovePackageOptions";
/* [object, uuid("E7C90595-9A44-5046-8EBF-41ED326B200E"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FailIfNotFound )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_FailIfNotFound )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PreserveApplicationData )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PreserveApplicationData )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PreserveRoamableApplicationData )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PreserveRoamableApplicationData )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RemoveForAllUsers )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_RemoveForAllUsers )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions * This,
        /* [in] */boolean value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_get_FailIfNotFound(This,value) \
    ( (This)->lpVtbl->get_FailIfNotFound(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_put_FailIfNotFound(This,value) \
    ( (This)->lpVtbl->put_FailIfNotFound(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_get_PreserveApplicationData(This,value) \
    ( (This)->lpVtbl->get_PreserveApplicationData(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_put_PreserveApplicationData(This,value) \
    ( (This)->lpVtbl->put_PreserveApplicationData(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_get_PreserveRoamableApplicationData(This,value) \
    ( (This)->lpVtbl->get_PreserveRoamableApplicationData(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_put_PreserveRoamableApplicationData(This,value) \
    ( (This)->lpVtbl->put_PreserveRoamableApplicationData(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_get_RemoveForAllUsers(This,value) \
    ( (This)->lpVtbl->get_RemoveForAllUsers(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_put_RemoveForAllUsers(This,value) \
    ( (This)->lpVtbl->put_RemoveForAllUsers(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIRemovePackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Management.Deployment.IStagePackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Management.Deployment.StagePackageOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Management_Deployment_IStagePackageOptions[] = L"Microsoft.Windows.Management.Deployment.IStagePackageOptions";
/* [object, uuid("9B6B3203-FD7C-5EAD-A9D6-AB2E8566BE5E"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_TargetVolume )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_TargetVolume )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIPackageVolume * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DependencyPackageUris )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OptionalPackageFamilyNames )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */__FIVector_1_HSTRING * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OptionalPackageUris )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RelatedPackageUris )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */__FIVector_1_Windows__CFoundation__CUri * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExternalLocationUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ExternalLocationUri )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_StubPackageOption )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CStubPackageOption * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_StubPackageOption )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CStubPackageOption value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DeveloperMode )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_DeveloperMode )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ForceUpdateFromAnyVersion )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ForceUpdateFromAnyVersion )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InstallAllResources )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_InstallAllResources )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RequiredContentGroupOnly )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_RequiredContentGroupOnly )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_StageInPlace )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_StageInPlace )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AllowUnsigned )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AllowUnsigned )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsExpectedDigestsSupported )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExpectedDigests )(
        __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions * This,
        /* [retval, out] */__FIMap_2_Windows__CFoundation__CUri_HSTRING * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_TargetVolume(This,value) \
    ( (This)->lpVtbl->get_TargetVolume(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_TargetVolume(This,value) \
    ( (This)->lpVtbl->put_TargetVolume(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_DependencyPackageUris(This,value) \
    ( (This)->lpVtbl->get_DependencyPackageUris(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_OptionalPackageFamilyNames(This,value) \
    ( (This)->lpVtbl->get_OptionalPackageFamilyNames(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_OptionalPackageUris(This,value) \
    ( (This)->lpVtbl->get_OptionalPackageUris(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_RelatedPackageUris(This,value) \
    ( (This)->lpVtbl->get_RelatedPackageUris(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_ExternalLocationUri(This,value) \
    ( (This)->lpVtbl->get_ExternalLocationUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_ExternalLocationUri(This,value) \
    ( (This)->lpVtbl->put_ExternalLocationUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_StubPackageOption(This,value) \
    ( (This)->lpVtbl->get_StubPackageOption(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_StubPackageOption(This,value) \
    ( (This)->lpVtbl->put_StubPackageOption(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_DeveloperMode(This,value) \
    ( (This)->lpVtbl->get_DeveloperMode(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_DeveloperMode(This,value) \
    ( (This)->lpVtbl->put_DeveloperMode(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_ForceUpdateFromAnyVersion(This,value) \
    ( (This)->lpVtbl->get_ForceUpdateFromAnyVersion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_ForceUpdateFromAnyVersion(This,value) \
    ( (This)->lpVtbl->put_ForceUpdateFromAnyVersion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_InstallAllResources(This,value) \
    ( (This)->lpVtbl->get_InstallAllResources(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_InstallAllResources(This,value) \
    ( (This)->lpVtbl->put_InstallAllResources(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_RequiredContentGroupOnly(This,value) \
    ( (This)->lpVtbl->get_RequiredContentGroupOnly(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_RequiredContentGroupOnly(This,value) \
    ( (This)->lpVtbl->put_RequiredContentGroupOnly(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_StageInPlace(This,value) \
    ( (This)->lpVtbl->get_StageInPlace(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_StageInPlace(This,value) \
    ( (This)->lpVtbl->put_StageInPlace(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_AllowUnsigned(This,value) \
    ( (This)->lpVtbl->get_AllowUnsigned(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_AllowUnsigned(This,value) \
    ( (This)->lpVtbl->put_AllowUnsigned(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_IsExpectedDigestsSupported(This,value) \
    ( (This)->lpVtbl->get_IsExpectedDigestsSupported(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_ExpectedDigests(This,value) \
    ( (This)->lpVtbl->get_ExpectedDigests(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.AddPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IAddPackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_AddPackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_AddPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_AddPackageOptions[] = L"Microsoft.Windows.Management.Deployment.AddPackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.EnsureReadyOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IEnsureReadyOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_EnsureReadyOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_EnsureReadyOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_EnsureReadyOptions[] = L"Microsoft.Windows.Management.Deployment.EnsureReadyOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageDeploymentManager
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Management.Deployment.IPackageDeploymentManagerStatics interface starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageDeploymentManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageDeploymentManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageDeploymentManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageDeploymentManager[] = L"Microsoft.Windows.Management.Deployment.PackageDeploymentManager";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageDeploymentResult
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageDeploymentResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageDeploymentResult_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageDeploymentResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageDeploymentResult[] = L"Microsoft.Windows.Management.Deployment.PackageDeploymentResult";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageRuntimeManager
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Management.Deployment.IPackageRuntimeManagerStatics interface starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageRuntimeManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageRuntimeManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageRuntimeManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageRuntimeManager[] = L"Microsoft.Windows.Management.Deployment.PackageRuntimeManager";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageSet
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageSet ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSet_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSet_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageSet[] = L"Microsoft.Windows.Management.Deployment.PackageSet";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageSetItem
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageSetItem ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetItem_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetItem_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageSetItem[] = L"Microsoft.Windows.Management.Deployment.PackageSetItem";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageSetItemRuntimeDisposition ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetItemRuntimeDisposition_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetItemRuntimeDisposition_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageSetItemRuntimeDisposition[] = L"Microsoft.Windows.Management.Deployment.PackageSetItemRuntimeDisposition";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageSetRuntimeDisposition
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageSetRuntimeDisposition ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetRuntimeDisposition_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageSetRuntimeDisposition_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageSetRuntimeDisposition[] = L"Microsoft.Windows.Management.Deployment.PackageSetRuntimeDisposition";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.PackageVolume
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Management.Deployment.IPackageVolumeStatics interface starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IPackageVolume ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageVolume_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_PackageVolume_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_PackageVolume[] = L"Microsoft.Windows.Management.Deployment.PackageVolume";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.ProvisionPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IProvisionPackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_ProvisionPackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_ProvisionPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_ProvisionPackageOptions[] = L"Microsoft.Windows.Management.Deployment.ProvisionPackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.RegisterPackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IRegisterPackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_RegisterPackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_RegisterPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_RegisterPackageOptions[] = L"Microsoft.Windows.Management.Deployment.RegisterPackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.RemovePackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IRemovePackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_RemovePackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_RemovePackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_RemovePackageOptions[] = L"Microsoft.Windows.Management.Deployment.RemovePackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Management.Deployment.StagePackageOptions
 *
 * Introduced to Microsoft.Windows.Management.Deployment.PackageDeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.Management.Deployment.PackageDeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Management.Deployment.IStagePackageOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Management_Deployment_StagePackageOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Management_Deployment_StagePackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Management_Deployment_StagePackageOptions[] = L"Microsoft.Windows.Management.Deployment.StagePackageOptions";
#endif
#endif // MICROSOFT_WINDOWS_MANAGEMENT_DEPLOYMENT_PACKAGEDEPLOYMENTCONTRACT_VERSION >= 0x10000





#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Emanagement2Edeployment_p_h__

#endif // __microsoft2Ewindows2Emanagement2Edeployment_h__

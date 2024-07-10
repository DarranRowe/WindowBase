
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
#ifndef __microsoft2Ewindows2Eapplicationmodel2Edynamicdependency_h__
#define __microsoft2Ewindows2Eapplicationmodel2Edynamicdependency_h__
#ifndef __microsoft2Ewindows2Eapplicationmodel2Edynamicdependency_p_h__
#define __microsoft2Ewindows2Eapplicationmodel2Edynamicdependency_p_h__


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
#include "Windows.ApplicationModel.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
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

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    interface IPackageDependency;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependency

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    interface IPackageDependencyContext;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependencyContext

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    interface IPackageDependencyContextFactory;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependencyContextFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    interface IPackageDependencyRankStatics;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependencyRankStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    interface IPackageDependencyStatics;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependencyStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    interface IPackageDependencyStatics2;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependencyStatics2

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_FWD_DEFINED__


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
            namespace ApplicationModel {
                namespace DynamicDependency {
                    
                    typedef enum PackageDependencyLifetimeArtifactKind : int PackageDependencyLifetimeArtifactKind;
                    
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
                    class AddPackageDependencyOptions;
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
                    class CreatePackageDependencyOptions;
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
                    class PackageDependency;
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
                    class PackageDependencyContext;
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */









/*
 *
 * Struct Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyLifetimeArtifactKind
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [v1_enum, contract] */
                    enum PackageDependencyLifetimeArtifactKind : int
                    {
                        PackageDependencyLifetimeArtifactKind_Process = 0,
                        PackageDependencyLifetimeArtifactKind_FilePath = 1,
                        PackageDependencyLifetimeArtifactKind_RegistryKey = 2,
                    };
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyProcessorArchitectures
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [v1_enum, flags, contract] */
                    enum PackageDependencyProcessorArchitectures : unsigned int
                    {
                        PackageDependencyProcessorArchitectures_None = 0,
                        PackageDependencyProcessorArchitectures_Neutral = 0x1,
                        PackageDependencyProcessorArchitectures_X86 = 0x2,
                        PackageDependencyProcessorArchitectures_X64 = 0x4,
                        PackageDependencyProcessorArchitectures_Arm = 0x8,
                        PackageDependencyProcessorArchitectures_Arm64 = 0x10,
                        PackageDependencyProcessorArchitectures_X86OnArm64 = 0x20,
                    };
                    
                    DEFINE_ENUM_FLAG_OPERATORS(PackageDependencyProcessorArchitectures)
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContextId
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [contract] */
                    struct PackageDependencyContextId
                    {
                        UINT64 Id;
                    };
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IAddPackageDependencyOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.AddPackageDependencyOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IAddPackageDependencyOptions[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IAddPackageDependencyOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [object, uuid("01B801FD-24E3-5E6B-9F1C-805AB410B604"), exclusiveto, contract] */
                    MIDL_INTERFACE("01B801FD-24E3-5E6B-9F1C-805AB410B604")
                    IAddPackageDependencyOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Rank(
                            /* [retval, out] */INT32 * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Rank(
                            /* [in] */INT32 value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PrependIfRankCollision(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PrependIfRankCollision(
                            /* [in] */::boolean value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAddPackageDependencyOptions=_uuidof(IAddPackageDependencyOptions);
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.ICreatePackageDependencyOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.CreatePackageDependencyOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_ICreatePackageDependencyOptions[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.ICreatePackageDependencyOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [object, uuid("CDBB820F-3C69-55DC-A017-B4132574C5D6"), exclusiveto, contract] */
                    MIDL_INTERFACE("CDBB820F-3C69-55DC-A017-B4132574C5D6")
                    ICreatePackageDependencyOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Architectures(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyProcessorArchitectures * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Architectures(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyProcessorArchitectures value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_VerifyDependencyResolution(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_VerifyDependencyResolution(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LifetimeArtifactKind(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyLifetimeArtifactKind * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_LifetimeArtifactKind(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyLifetimeArtifactKind value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LifetimeArtifact(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_LifetimeArtifact(
                            /* [in] */HSTRING value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_ICreatePackageDependencyOptions=_uuidof(ICreatePackageDependencyOptions);
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependency
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependency[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependency";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [object, uuid("32AE7B95-E358-5A48-9669-C97D85AD6556"), exclusiveto, contract] */
                    MIDL_INTERFACE("32AE7B95-E358-5A48-9669-C97D85AD6556")
                    IPackageDependency : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Id(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Delete(void) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE Add(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependencyContext * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE Add2(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IAddPackageDependencyOptions * options,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependencyContext * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDependency=_uuidof(IPackageDependency);
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContext
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContext
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyContext[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContext";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [object, uuid("9902C35A-A3F5-5645-AF0F-CDF9FCA00D5E"), exclusiveto, contract] */
                    MIDL_INTERFACE("9902C35A-A3F5-5645-AF0F-CDF9FCA00D5E")
                    IPackageDependencyContext : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ContextId(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyContextId * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageDependencyId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageFullName(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Remove(void) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDependencyContext=_uuidof(IPackageDependencyContext);
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContextFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContext
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyContextFactory[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContextFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [object, uuid("9914F24F-BEBF-516B-ADAB-5C3E8BF323F8"), exclusiveto, contract] */
                    MIDL_INTERFACE("9914F24F-BEBF-516B-ADAB-5C3E8BF323F8")
                    IPackageDependencyContextFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::PackageDependencyContextId contextId,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependencyContext * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDependencyContextFactory=_uuidof(IPackageDependencyContextFactory);
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyRankStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyRank
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyRankStatics[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyRankStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [object, uuid("260583BD-A4AB-53FD-A190-C446BFDB5384"), exclusiveto, contract] */
                    MIDL_INTERFACE("260583BD-A4AB-53FD-A190-C446BFDB5384")
                    IPackageDependencyRankStatics : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Default(
                            /* [retval, out] */INT32 * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDependencyRankStatics=_uuidof(IPackageDependencyRankStatics);
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyStatics[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [object, uuid("17B656E1-1A58-5F3C-84A8-4430F6E749C2"), exclusiveto, contract] */
                    MIDL_INTERFACE("17B656E1-1A58-5F3C-84A8-4430F6E749C2")
                    IPackageDependencyStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetFromId(
                            /* [in] */HSTRING id,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependency * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetFromIdForSystem(
                            /* [in] */HSTRING id,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependency * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE Create(
                            /* [in] */HSTRING packageFamilyName,
                            /* [in] */ABI::Windows::ApplicationModel::PackageVersion minVersion,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependency * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE Create2(
                            /* [in] */HSTRING packageFamilyName,
                            /* [in] */ABI::Windows::ApplicationModel::PackageVersion minVersion,
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::ICreatePackageDependencyOptions * options,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependency * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateForSystem(
                            /* [in] */HSTRING packageFamilyName,
                            /* [in] */ABI::Windows::ApplicationModel::PackageVersion minVersion,
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::ICreatePackageDependencyOptions * options,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::DynamicDependency::IPackageDependency * * result
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_GenerationId(
                            /* [retval, out] */UINT32 * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDependencyStatics=_uuidof(IPackageDependencyStatics);
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyStatics2[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace DynamicDependency {
                    /* [object, uuid("C7C6E4F3-C0CA-5FDB-BEF2-57E6020FFE4E"), exclusiveto, contract] */
                    MIDL_INTERFACE("C7C6E4F3-C0CA-5FDB-BEF2-57E6020FFE4E")
                    IPackageDependencyStatics2 : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PackageGraphRevisionId(
                            /* [retval, out] */UINT32 * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IPackageDependencyStatics2=_uuidof(IPackageDependencyStatics2);
                    
                } /* DynamicDependency */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.AddPackageDependencyOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.DynamicDependency.IAddPackageDependencyOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_AddPackageDependencyOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_AddPackageDependencyOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_AddPackageDependencyOptions[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.AddPackageDependencyOptions";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.CreatePackageDependencyOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.DynamicDependency.ICreatePackageDependencyOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_CreatePackageDependencyOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_CreatePackageDependencyOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_CreatePackageDependencyOptions[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.CreatePackageDependencyOptions";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics2 interface starting with version 2.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependency ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependency_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependency_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependency[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContext
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContextFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContext ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyContext_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyContext[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContext";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyRank
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyRankStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyRank_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyRank_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyRank[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyRank";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_FWD_DEFINED__


typedef struct __x_ABI_CWindows_CApplicationModel_CPackageVersion __x_ABI_CWindows_CApplicationModel_CPackageVersion;





typedef enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyLifetimeArtifactKind __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyLifetimeArtifactKind;


typedef enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures;


typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyContextId __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyContextId;




















/*
 *
 * Struct Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyLifetimeArtifactKind
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyLifetimeArtifactKind
{
    PackageDependencyLifetimeArtifactKind_Process = 0,
    PackageDependencyLifetimeArtifactKind_FilePath = 1,
    PackageDependencyLifetimeArtifactKind_RegistryKey = 2,
};
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyProcessorArchitectures
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
/* [v1_enum, flags, contract] */
enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures
{
    PackageDependencyProcessorArchitectures_None = 0,
    PackageDependencyProcessorArchitectures_Neutral = 0x1,
    PackageDependencyProcessorArchitectures_X86 = 0x2,
    PackageDependencyProcessorArchitectures_X64 = 0x4,
    PackageDependencyProcessorArchitectures_Arm = 0x8,
    PackageDependencyProcessorArchitectures_Arm64 = 0x10,
    PackageDependencyProcessorArchitectures_X86OnArm64 = 0x20,
};
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContextId
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

/* [contract] */
struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyContextId
{
    UINT64 Id;
};
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IAddPackageDependencyOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.AddPackageDependencyOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IAddPackageDependencyOptions[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IAddPackageDependencyOptions";
/* [object, uuid("01B801FD-24E3-5E6B-9F1C-805AB410B604"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Rank )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This,
        /* [retval, out] */INT32 * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Rank )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This,
        /* [in] */INT32 value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PrependIfRankCollision )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PrependIfRankCollision )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * This,
        /* [in] */boolean value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_get_Rank(This,value) \
    ( (This)->lpVtbl->get_Rank(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_put_Rank(This,value) \
    ( (This)->lpVtbl->put_Rank(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_get_PrependIfRankCollision(This,value) \
    ( (This)->lpVtbl->get_PrependIfRankCollision(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_put_PrependIfRankCollision(This,value) \
    ( (This)->lpVtbl->put_PrependIfRankCollision(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.ICreatePackageDependencyOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.CreatePackageDependencyOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_ICreatePackageDependencyOptions[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.ICreatePackageDependencyOptions";
/* [object, uuid("CDBB820F-3C69-55DC-A017-B4132574C5D6"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Architectures )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Architectures )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyProcessorArchitectures value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_VerifyDependencyResolution )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_VerifyDependencyResolution )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LifetimeArtifactKind )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyLifetimeArtifactKind * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_LifetimeArtifactKind )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyLifetimeArtifactKind value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LifetimeArtifact )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_LifetimeArtifact )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * This,
        /* [in] */HSTRING value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_get_Architectures(This,value) \
    ( (This)->lpVtbl->get_Architectures(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_put_Architectures(This,value) \
    ( (This)->lpVtbl->put_Architectures(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_get_VerifyDependencyResolution(This,value) \
    ( (This)->lpVtbl->get_VerifyDependencyResolution(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_put_VerifyDependencyResolution(This,value) \
    ( (This)->lpVtbl->put_VerifyDependencyResolution(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_get_LifetimeArtifactKind(This,value) \
    ( (This)->lpVtbl->get_LifetimeArtifactKind(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_put_LifetimeArtifactKind(This,value) \
    ( (This)->lpVtbl->put_LifetimeArtifactKind(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_get_LifetimeArtifact(This,value) \
    ( (This)->lpVtbl->get_LifetimeArtifact(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_put_LifetimeArtifact(This,value) \
    ( (This)->lpVtbl->put_LifetimeArtifact(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependency
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependency[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependency";
/* [object, uuid("32AE7B95-E358-5A48-9669-C97D85AD6556"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Id )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This,
        /* [retval, out] */HSTRING * value
        );
    HRESULT ( STDMETHODCALLTYPE *Delete )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *Add )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *Add2 )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIAddPackageDependencyOptions * options,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_get_Id(This,value) \
    ( (This)->lpVtbl->get_Id(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_Delete(This) \
    ( (This)->lpVtbl->Delete(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_Add(This,result) \
    ( (This)->lpVtbl->Add(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_Add2(This,options,result) \
    ( (This)->lpVtbl->Add2(This,options,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContext
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContext
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyContext[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContext";
/* [object, uuid("9902C35A-A3F5-5645-AF0F-CDF9FCA00D5E"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ContextId )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyContextId * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageDependencyId )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageFullName )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This,
        /* [retval, out] */HSTRING * value
        );
    HRESULT ( STDMETHODCALLTYPE *Remove )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * This
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_get_ContextId(This,value) \
    ( (This)->lpVtbl->get_ContextId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_get_PackageDependencyId(This,value) \
    ( (This)->lpVtbl->get_PackageDependencyId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_get_PackageFullName(This,value) \
    ( (This)->lpVtbl->get_PackageFullName(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_Remove(This) \
    ( (This)->lpVtbl->Remove(This) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContextFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContext
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyContextFactory[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContextFactory";
/* [object, uuid("9914F24F-BEBF-516B-ADAB-5C3E8BF323F8"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CPackageDependencyContextId contextId,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContext * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_CreateInstance(This,contextId,value) \
    ( (This)->lpVtbl->CreateInstance(This,contextId,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyContextFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyRankStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyRank
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyRankStatics[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyRankStatics";
/* [object, uuid("260583BD-A4AB-53FD-A190-C446BFDB5384"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Default )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics * This,
        /* [retval, out] */INT32 * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_get_Default(This,value) \
    ( (This)->lpVtbl->get_Default(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyRankStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyStatics[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics";
/* [object, uuid("17B656E1-1A58-5F3C-84A8-4430F6E749C2"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetFromId )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
        /* [in] */HSTRING id,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetFromIdForSystem )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
        /* [in] */HSTRING id,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *Create )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
        /* [in] */HSTRING packageFamilyName,
        /* [in] */__x_ABI_CWindows_CApplicationModel_CPackageVersion minVersion,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *Create2 )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
        /* [in] */HSTRING packageFamilyName,
        /* [in] */__x_ABI_CWindows_CApplicationModel_CPackageVersion minVersion,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * options,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * * result
        );
    HRESULT ( STDMETHODCALLTYPE *CreateForSystem )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
        /* [in] */HSTRING packageFamilyName,
        /* [in] */__x_ABI_CWindows_CApplicationModel_CPackageVersion minVersion,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CICreatePackageDependencyOptions * options,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependency * * result
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_GenerationId )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics * This,
        /* [retval, out] */UINT32 * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_GetFromId(This,id,result) \
    ( (This)->lpVtbl->GetFromId(This,id,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_GetFromIdForSystem(This,id,result) \
    ( (This)->lpVtbl->GetFromIdForSystem(This,id,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_Create(This,packageFamilyName,minVersion,result) \
    ( (This)->lpVtbl->Create(This,packageFamilyName,minVersion,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_Create2(This,packageFamilyName,minVersion,options,result) \
    ( (This)->lpVtbl->Create2(This,packageFamilyName,minVersion,options,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_CreateForSystem(This,packageFamilyName,minVersion,options,result) \
    ( (This)->lpVtbl->CreateForSystem(This,packageFamilyName,minVersion,options,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_get_GenerationId(This,value) \
    ( (This)->lpVtbl->get_GenerationId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_DynamicDependency_IPackageDependencyStatics2[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics2";
/* [object, uuid("C7C6E4F3-C0CA-5FDB-BEF2-57E6020FFE4E"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PackageGraphRevisionId )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2 * This,
        /* [retval, out] */UINT32 * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_get_PackageGraphRevisionId(This,value) \
    ( (This)->lpVtbl->get_PackageGraphRevisionId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CDynamicDependency_CIPackageDependencyStatics2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.AddPackageDependencyOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.DynamicDependency.IAddPackageDependencyOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_AddPackageDependencyOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_AddPackageDependencyOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_AddPackageDependencyOptions[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.AddPackageDependencyOptions";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.CreatePackageDependencyOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.DynamicDependency.ICreatePackageDependencyOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_CreatePackageDependencyOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_CreatePackageDependencyOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_CreatePackageDependencyOptions[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.CreatePackageDependencyOptions";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics2 interface starting with version 2.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependency ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependency_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependency_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependency[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependency";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContext
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContextFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyContext ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyContext_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyContext[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyContext";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyRank
 *
 * Introduced to Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.DynamicDependency.IPackageDependencyRankStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.DynamicDependency.DynamicDependencyContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyRank_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyRank_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_DynamicDependency_PackageDependencyRank[] = L"Microsoft.Windows.ApplicationModel.DynamicDependency.PackageDependencyRank";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_DYNAMICDEPENDENCY_DYNAMICDEPENDENCYCONTRACT_VERSION >= 0x10000





#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Eapplicationmodel2Edynamicdependency_p_h__

#endif // __microsoft2Ewindows2Eapplicationmodel2Edynamicdependency_h__

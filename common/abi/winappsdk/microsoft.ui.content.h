
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
#ifndef __microsoft2Eui2Econtent_h__
#define __microsoft2Eui2Econtent_h__
#ifndef __microsoft2Eui2Econtent_p_h__
#define __microsoft2Eui2Econtent_p_h__


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
#include "Microsoft.UI.h"
#include "Microsoft.UI.Composition.h"
#include "Microsoft.UI.Dispatching.h"
#include "Windows.Foundation.Numerics.h"
#include "Windows.Graphics.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentCoordinateConverter;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter ABI::Microsoft::UI::Content::IContentCoordinateConverter

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentCoordinateConverterFactory;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory ABI::Microsoft::UI::Content::IContentCoordinateConverterFactory

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentCoordinateConverterStatics;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics ABI::Microsoft::UI::Content::IContentCoordinateConverterStatics

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentDeferral;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral ABI::Microsoft::UI::Content::IContentDeferral

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentEnvironmentSettingChangedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs ABI::Microsoft::UI::Content::IContentEnvironmentSettingChangedEventArgs

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentEnvironmentStateChangedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs ABI::Microsoft::UI::Content::IContentEnvironmentStateChangedEventArgs

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_FWD_DEFINED__

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

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentIslandAutomationProviderRequestedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs ABI::Microsoft::UI::Content::IContentIslandAutomationProviderRequestedEventArgs

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentIslandEnvironment;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment ABI::Microsoft::UI::Content::IContentIslandEnvironment

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentIslandEnvironmentFactory;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory ABI::Microsoft::UI::Content::IContentIslandEnvironmentFactory

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentIslandFactory;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory ABI::Microsoft::UI::Content::IContentIslandFactory

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentIslandStateChangedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs ABI::Microsoft::UI::Content::IContentIslandStateChangedEventArgs

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentIslandStatics;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics ABI::Microsoft::UI::Content::IContentIslandStatics

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSite;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite ABI::Microsoft::UI::Content::IContentSite

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteBridge;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge ABI::Microsoft::UI::Content::IContentSiteBridge

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteEnvironment;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment ABI::Microsoft::UI::Content::IContentSiteEnvironment

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteEnvironmentFactory;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory ABI::Microsoft::UI::Content::IContentSiteEnvironmentFactory

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteEnvironmentView;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView ABI::Microsoft::UI::Content::IContentSiteEnvironmentView

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteEnvironmentViewFactory;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory ABI::Microsoft::UI::Content::IContentSiteEnvironmentViewFactory

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteFactory;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory ABI::Microsoft::UI::Content::IContentSiteFactory

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteRequestedStateChangedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs ABI::Microsoft::UI::Content::IContentSiteRequestedStateChangedEventArgs

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteView;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView ABI::Microsoft::UI::Content::IContentSiteView

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IContentSiteViewFactory;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory ABI::Microsoft::UI::Content::IContentSiteViewFactory

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IDesktopChildSiteBridge;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge ABI::Microsoft::UI::Content::IDesktopChildSiteBridge

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IDesktopChildSiteBridgeStatics;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics ABI::Microsoft::UI::Content::IDesktopChildSiteBridgeStatics

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IDesktopSiteBridge;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge ABI::Microsoft::UI::Content::IDesktopSiteBridge

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IDesktopSiteBridgeFactory;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory ABI::Microsoft::UI::Content::IDesktopSiteBridgeFactory

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                interface IDesktopSiteBridgeStatics;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics ABI::Microsoft::UI::Content::IDesktopSiteBridgeStatics

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                enum ContentLayoutDirection : int;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


#ifndef DEF___FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_USE
#define DEF___FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("76e53eed-3539-540b-8d51-4206bca63f5f"))
IReference<enum ABI::Microsoft::UI::Content::ContentLayoutDirection> : IReference_impl<enum ABI::Microsoft::UI::Content::ContentLayoutDirection> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.IReference`1<Microsoft.UI.Content.ContentLayoutDirection>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IReference<enum ABI::Microsoft::UI::Content::ContentLayoutDirection> __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_t;
#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection ABI::Windows::Foundation::__FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection ABI::Windows::Foundation::IReference<ABI::Microsoft::UI::Content::ContentLayoutDirection>
//#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_t ABI::Windows::Foundation::IReference<ABI::Microsoft::UI::Content::ContentLayoutDirection>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_USE */



namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentIsland;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentIslandAutomationProviderRequestedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("3b44f287-f0ef-5d10-ab5f-1b324f45f7da"))
ITypedEventHandler<ABI::Microsoft::UI::Content::ContentIsland*,ABI::Microsoft::UI::Content::ContentIslandAutomationProviderRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentIsland*, ABI::Microsoft::UI::Content::IContentIsland*>,ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentIslandAutomationProviderRequestedEventArgs*, ABI::Microsoft::UI::Content::IContentIslandAutomationProviderRequestedEventArgs*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.TypedEventHandler`2<Microsoft.UI.Content.ContentIsland, Microsoft.UI.Content.ContentIslandAutomationProviderRequestedEventArgs>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Microsoft::UI::Content::ContentIsland*,ABI::Microsoft::UI::Content::ContentIslandAutomationProviderRequestedEventArgs*> __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_t;
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentIsland*,ABI::Microsoft::UI::Content::IContentIslandAutomationProviderRequestedEventArgs*>
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_t ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentIsland*,ABI::Microsoft::UI::Content::IContentIslandAutomationProviderRequestedEventArgs*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_USE */


#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentIslandStateChangedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_USE
#define DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("ceb771a4-bf66-529d-883a-602d592f390c"))
ITypedEventHandler<ABI::Microsoft::UI::Content::ContentIsland*,ABI::Microsoft::UI::Content::ContentIslandStateChangedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentIsland*, ABI::Microsoft::UI::Content::IContentIsland*>,ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentIslandStateChangedEventArgs*, ABI::Microsoft::UI::Content::IContentIslandStateChangedEventArgs*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.TypedEventHandler`2<Microsoft.UI.Content.ContentIsland, Microsoft.UI.Content.ContentIslandStateChangedEventArgs>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Microsoft::UI::Content::ContentIsland*,ABI::Microsoft::UI::Content::ContentIslandStateChangedEventArgs*> __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_t;
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentIsland*,ABI::Microsoft::UI::Content::IContentIslandStateChangedEventArgs*>
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_t ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentIsland*,ABI::Microsoft::UI::Content::IContentIslandStateChangedEventArgs*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_USE */


#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentIslandEnvironment;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentEnvironmentSettingChangedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_USE
#define DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("1ad20c79-1495-5501-ac8a-a38845e8f218"))
ITypedEventHandler<ABI::Microsoft::UI::Content::ContentIslandEnvironment*,ABI::Microsoft::UI::Content::ContentEnvironmentSettingChangedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentIslandEnvironment*, ABI::Microsoft::UI::Content::IContentIslandEnvironment*>,ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentEnvironmentSettingChangedEventArgs*, ABI::Microsoft::UI::Content::IContentEnvironmentSettingChangedEventArgs*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.TypedEventHandler`2<Microsoft.UI.Content.ContentIslandEnvironment, Microsoft.UI.Content.ContentEnvironmentSettingChangedEventArgs>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Microsoft::UI::Content::ContentIslandEnvironment*,ABI::Microsoft::UI::Content::ContentEnvironmentSettingChangedEventArgs*> __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_t;
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentIslandEnvironment*,ABI::Microsoft::UI::Content::IContentEnvironmentSettingChangedEventArgs*>
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_t ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentIslandEnvironment*,ABI::Microsoft::UI::Content::IContentEnvironmentSettingChangedEventArgs*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_USE */


#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentEnvironmentStateChangedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_USE
#define DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("c7742341-cfd5-5ef6-ab2a-d38c65b780b5"))
ITypedEventHandler<ABI::Microsoft::UI::Content::ContentIslandEnvironment*,ABI::Microsoft::UI::Content::ContentEnvironmentStateChangedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentIslandEnvironment*, ABI::Microsoft::UI::Content::IContentIslandEnvironment*>,ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentEnvironmentStateChangedEventArgs*, ABI::Microsoft::UI::Content::IContentEnvironmentStateChangedEventArgs*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.TypedEventHandler`2<Microsoft.UI.Content.ContentIslandEnvironment, Microsoft.UI.Content.ContentEnvironmentStateChangedEventArgs>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Microsoft::UI::Content::ContentIslandEnvironment*,ABI::Microsoft::UI::Content::ContentEnvironmentStateChangedEventArgs*> __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_t;
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentIslandEnvironment*,ABI::Microsoft::UI::Content::IContentEnvironmentStateChangedEventArgs*>
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_t ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentIslandEnvironment*,ABI::Microsoft::UI::Content::IContentEnvironmentStateChangedEventArgs*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_USE */


#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentSite;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentSiteRequestedStateChangedEventArgs;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_USE
#define DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("b34e5337-73e6-5227-8921-6321eea32a9b"))
ITypedEventHandler<ABI::Microsoft::UI::Content::ContentSite*,ABI::Microsoft::UI::Content::ContentSiteRequestedStateChangedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentSite*, ABI::Microsoft::UI::Content::IContentSite*>,ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::Content::ContentSiteRequestedStateChangedEventArgs*, ABI::Microsoft::UI::Content::IContentSiteRequestedStateChangedEventArgs*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.TypedEventHandler`2<Microsoft.UI.Content.ContentSite, Microsoft.UI.Content.ContentSiteRequestedStateChangedEventArgs>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Microsoft::UI::Content::ContentSite*,ABI::Microsoft::UI::Content::ContentSiteRequestedStateChangedEventArgs*> __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_t;
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentSite*,ABI::Microsoft::UI::Content::IContentSiteRequestedStateChangedEventArgs*>
//#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_t ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::Content::IContentSite*,ABI::Microsoft::UI::Content::IContentSiteRequestedStateChangedEventArgs*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_USE */


#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004






namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Composition {
                class Compositor;
            } /* Composition */
        } /* UI */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CUI_CComposition_CICompositor_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CComposition_CICompositor_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Composition {
                interface ICompositor;
            } /* Composition */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CComposition_CICompositor ABI::Microsoft::UI::Composition::ICompositor

#endif // ____x_ABI_CMicrosoft_CUI_CComposition_CICompositor_FWD_DEFINED__


#ifndef ____x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Composition {
                interface ICompositionSupportsSystemBackdrop;
            } /* Composition */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop ABI::Microsoft::UI::Composition::ICompositionSupportsSystemBackdrop

#endif // ____x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop_FWD_DEFINED__


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Composition {
                class Visual;
            } /* Composition */
        } /* UI */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CUI_CComposition_CIVisual_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CComposition_CIVisual_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Composition {
                interface IVisual;
            } /* Composition */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CComposition_CIVisual ABI::Microsoft::UI::Composition::IVisual

#endif // ____x_ABI_CMicrosoft_CUI_CComposition_CIVisual_FWD_DEFINED__





namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Dispatching {
                class DispatcherQueue;
            } /* Dispatching */
        } /* UI */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Dispatching {
                interface IDispatcherQueue;
            } /* Dispatching */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue ABI::Microsoft::UI::Dispatching::IDispatcherQueue

#endif // ____x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue_FWD_DEFINED__





namespace ABI {
    namespace Microsoft {
        namespace UI {
            
            typedef struct DisplayId DisplayId;
            
        } /* UI */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CUI_CIClosableNotifier_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CIClosableNotifier_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            interface IClosableNotifier;
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CIClosableNotifier ABI::Microsoft::UI::IClosableNotifier

#endif // ____x_ABI_CMicrosoft_CUI_CIClosableNotifier_FWD_DEFINED__


namespace ABI {
    namespace Microsoft {
        namespace UI {
            
            typedef struct WindowId WindowId;
            
        } /* UI */
    } /* Microsoft */
} /* ABI */



#ifndef ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            namespace Collections {
                interface IPropertySet;
            } /* Collections */
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet ABI::Windows::Foundation::Collections::IPropertySet

#endif // ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__





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
            namespace Numerics {
                
                typedef struct Vector2 Vector2;
                
            } /* Numerics */
        } /* Foundation */
    } /* Windows */
} /* ABI */




namespace ABI {
    namespace Windows {
        namespace Foundation {
            
            typedef struct Point Point;
            
        } /* Foundation */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Foundation {
            
            typedef struct Rect Rect;
            
        } /* Foundation */
    } /* Windows */
} /* ABI */



namespace ABI {
    namespace Windows {
        namespace Graphics {
            
            typedef struct PointInt32 PointInt32;
            
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            
            typedef struct RectInt32 RectInt32;
            
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            
            typedef struct SizeInt32 SizeInt32;
            
        } /* Graphics */
    } /* Windows */
} /* ABI */



namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                
                typedef enum ContentCoordinateRoundingMode : int ContentCoordinateRoundingMode;
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                
                typedef enum ContentLayoutDirection : int ContentLayoutDirection;
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                
                typedef enum ContentSizePolicy : int ContentSizePolicy;
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */





























namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentCoordinateConverter;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentDeferral;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */









namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentSiteEnvironment;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentSiteEnvironmentView;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */



namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class ContentSiteView;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class DesktopChildSiteBridge;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                class DesktopSiteBridge;
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */










/*
 *
 * Struct Microsoft.UI.Content.ContentCoordinateRoundingMode
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [v1_enum, contract] */
                enum ContentCoordinateRoundingMode : int
                {
                    ContentCoordinateRoundingMode_Auto = 0,
                    ContentCoordinateRoundingMode_Floor = 1,
                    ContentCoordinateRoundingMode_Round = 2,
                    ContentCoordinateRoundingMode_Ceiling = 3,
                };
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Struct Microsoft.UI.Content.ContentLayoutDirection
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [v1_enum, contract] */
                enum ContentLayoutDirection : int
                {
                    ContentLayoutDirection_LeftToRight = 0,
                    ContentLayoutDirection_RightToLeft = 1,
                };
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Struct Microsoft.UI.Content.ContentSizePolicy
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [v1_enum, contract] */
                enum ContentSizePolicy : int
                {
                    ContentSizePolicy_None = 0,
                    ContentSizePolicy_ResizeContentToParentWindow = 1,
                    ContentSizePolicy_ResizeParentWindowToContent = 2,
                };
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentCoordinateConverter
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentCoordinateConverter
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentCoordinateConverter[] = L"Microsoft.UI.Content.IContentCoordinateConverter";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("10A11230-5EB4-5840-A346-570F4A49040F"), exclusiveto, contract] */
                MIDL_INTERFACE("10A11230-5EB4-5840-A346-570F4A49040F")
                IContentCoordinateConverter : public IInspectable
                {
                public:
                    /* [overload, default_overload] */virtual HRESULT STDMETHODCALLTYPE ConvertLocalToScreenWithPoint(
                        /* [in] */ABI::Windows::Foundation::Point localPoint,
                        /* [retval, out] */ABI::Windows::Graphics::PointInt32 * result
                        ) = 0;
                    /* [overload] */virtual HRESULT STDMETHODCALLTYPE ConvertLocalToScreenWithPoints(
                        /* [in] */UINT32 __localPointsSize,
                        /* [size_is(__localPointsSize), in] */ABI::Windows::Foundation::Point * localPoints,
                        /* [out] */UINT32 * __resultSize,
                        /* [size_is(, *(__resultSize)), retval, out] */ABI::Windows::Graphics::PointInt32 * * result
                        ) = 0;
                    /* [overload] */virtual HRESULT STDMETHODCALLTYPE ConvertLocalToScreenWithPointsAndRoundingMode(
                        /* [in] */UINT32 __localPointsSize,
                        /* [size_is(__localPointsSize), in] */ABI::Windows::Foundation::Point * localPoints,
                        /* [in] */ABI::Microsoft::UI::Content::ContentCoordinateRoundingMode roundingMode,
                        /* [out] */UINT32 * __resultSize,
                        /* [size_is(, *(__resultSize)), retval, out] */ABI::Windows::Graphics::PointInt32 * * result
                        ) = 0;
                    /* [overload] */virtual HRESULT STDMETHODCALLTYPE ConvertLocalToScreenWithRect(
                        /* [in] */ABI::Windows::Foundation::Rect localRect,
                        /* [retval, out] */ABI::Windows::Graphics::RectInt32 * result
                        ) = 0;
                    /* [overload, default_overload] */virtual HRESULT STDMETHODCALLTYPE ConvertScreenToLocalWithPoint(
                        /* [in] */ABI::Windows::Graphics::PointInt32 screenPoint,
                        /* [retval, out] */ABI::Windows::Foundation::Point * result
                        ) = 0;
                    /* [overload] */virtual HRESULT STDMETHODCALLTYPE ConvertScreenToLocalWithPoints(
                        /* [in] */UINT32 __screenPointsSize,
                        /* [size_is(__screenPointsSize), in] */ABI::Windows::Graphics::PointInt32 * screenPoints,
                        /* [out] */UINT32 * __resultSize,
                        /* [size_is(, *(__resultSize)), retval, out] */ABI::Windows::Foundation::Point * * result
                        ) = 0;
                    /* [overload] */virtual HRESULT STDMETHODCALLTYPE ConvertScreenToLocalWithRect(
                        /* [in] */ABI::Windows::Graphics::RectInt32 screenRect,
                        /* [retval, out] */ABI::Windows::Foundation::Rect * result
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentCoordinateConverter=_uuidof(IContentCoordinateConverter);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentCoordinateConverterFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentCoordinateConverter
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentCoordinateConverterFactory[] = L"Microsoft.UI.Content.IContentCoordinateConverterFactory";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("A4B216EE-0E26-56BD-9209-A75CF9D80F27"), exclusiveto, contract] */
                MIDL_INTERFACE("A4B216EE-0E26-56BD-9209-A75CF9D80F27")
                IContentCoordinateConverterFactory : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IContentCoordinateConverterFactory=_uuidof(IContentCoordinateConverterFactory);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentCoordinateConverterStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentCoordinateConverter
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentCoordinateConverterStatics[] = L"Microsoft.UI.Content.IContentCoordinateConverterStatics";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("F56374CE-B6DF-5B42-A58F-4E3BB039E3A9"), exclusiveto, contract] */
                MIDL_INTERFACE("F56374CE-B6DF-5B42-A58F-4E3BB039E3A9")
                IContentCoordinateConverterStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateForWindowId(
                        /* [in] */ABI::Microsoft::UI::WindowId windowId,
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentCoordinateConverter * * result
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentCoordinateConverterStatics=_uuidof(IContentCoordinateConverterStatics);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentDeferral
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentDeferral
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentDeferral[] = L"Microsoft.UI.Content.IContentDeferral";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("470529F5-CD93-599B-968E-F8A689BC3A07"), exclusiveto, contract] */
                MIDL_INTERFACE("470529F5-CD93-599B-968E-F8A689BC3A07")
                IContentDeferral : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Complete(void) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentDeferral=_uuidof(IContentDeferral);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentEnvironmentSettingChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentEnvironmentSettingChangedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentEnvironmentSettingChangedEventArgs[] = L"Microsoft.UI.Content.IContentEnvironmentSettingChangedEventArgs";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("76478051-FC80-5EEC-A3F3-62606ABE06B7"), exclusiveto, contract] */
                MIDL_INTERFACE("76478051-FC80-5EEC-A3F3-62606ABE06B7")
                IContentEnvironmentSettingChangedEventArgs : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SettingName(
                        /* [retval, out] */HSTRING * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentEnvironmentSettingChangedEventArgs=_uuidof(IContentEnvironmentSettingChangedEventArgs);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentEnvironmentStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentEnvironmentStateChangedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentEnvironmentStateChangedEventArgs[] = L"Microsoft.UI.Content.IContentEnvironmentStateChangedEventArgs";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("8970FA4F-10BA-5F67-970B-8C72BC009B67"), exclusiveto, contract] */
                MIDL_INTERFACE("8970FA4F-10BA-5F67-970B-8C72BC009B67")
                IContentEnvironmentStateChangedEventArgs : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DidAppWindowIdChange(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DidDisplayIdChange(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentEnvironmentStateChangedEventArgs=_uuidof(IContentEnvironmentStateChangedEventArgs);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIsland
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIsland
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIsland[] = L"Microsoft.UI.Content.IContentIsland";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("5B2504BA-361C-50AA-BD6E-4122C6D93889"), exclusiveto, contract] */
                MIDL_INTERFACE("5B2504BA-361C-50AA-BD6E-4122C6D93889")
                IContentIsland : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ActualSize(
                        /* [retval, out] */ABI::Windows::Foundation::Numerics::Vector2 * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AppData(
                        /* [retval, out] */IInspectable * * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AppData(
                        /* [in] */IInspectable * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CoordinateConverter(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentCoordinateConverter * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CustomProperties(
                        /* [retval, out] */ABI::Windows::Foundation::Collections::IPropertySet * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DispatcherQueue(
                        /* [retval, out] */ABI::Microsoft::UI::Dispatching::IDispatcherQueue * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Environment(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentIslandEnvironment * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Id(
                        /* [retval, out] */UINT64 * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsConnected(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsHitTestVisibleWhenTransparent(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsHitTestVisibleWhenTransparent(
                        /* [in] */::boolean value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsIslandEnabled(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsIslandEnabled(
                        /* [in] */::boolean value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsIslandVisible(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsIslandVisible(
                        /* [in] */::boolean value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSiteEnabled(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSiteVisible(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LayoutDirection(
                        /* [retval, out] */ABI::Microsoft::UI::Content::ContentLayoutDirection * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RasterizationScale(
                        /* [retval, out] */FLOAT * value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetAutomationHostProvider(
                        /* [retval, out] */IInspectable * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetStateChangeDeferral(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentDeferral * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RequestSize(
                        /* [in] */ABI::Windows::Foundation::Numerics::Vector2 size
                        ) = 0;
                    /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_AutomationProviderRequested(
                        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs * handler,
                        /* [retval, out] */EventRegistrationToken * token
                        ) = 0;
                    /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_AutomationProviderRequested(
                        /* [in] */EventRegistrationToken token
                        ) = 0;
                    /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_StateChanged(
                        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs * handler,
                        /* [retval, out] */EventRegistrationToken * token
                        ) = 0;
                    /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_StateChanged(
                        /* [in] */EventRegistrationToken token
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentIsland=_uuidof(IContentIsland);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIsland;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandAutomationProviderRequestedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIslandAutomationProviderRequestedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandAutomationProviderRequestedEventArgs[] = L"Microsoft.UI.Content.IContentIslandAutomationProviderRequestedEventArgs";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("9FE24BED-2B9C-5137-887F-403C94841824"), exclusiveto, contract] */
                MIDL_INTERFACE("9FE24BED-2B9C-5137-887F-403C94841824")
                IContentIslandAutomationProviderRequestedEventArgs : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AutomationProvider(
                        /* [retval, out] */IInspectable * * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AutomationProvider(
                        /* [in] */IInspectable * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Handled(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Handled(
                        /* [in] */::boolean value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentIslandAutomationProviderRequestedEventArgs=_uuidof(IContentIslandAutomationProviderRequestedEventArgs);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandEnvironment
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIslandEnvironment
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandEnvironment[] = L"Microsoft.UI.Content.IContentIslandEnvironment";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("C334236D-DA88-566D-811D-74AEF2EBA978"), exclusiveto, contract] */
                MIDL_INTERFACE("C334236D-DA88-566D-811D-74AEF2EBA978")
                IContentIslandEnvironment : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AppWindowId(
                        /* [retval, out] */ABI::Microsoft::UI::WindowId * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DisplayId(
                        /* [retval, out] */ABI::Microsoft::UI::DisplayId * value
                        ) = 0;
                    /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_SettingChanged(
                        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs * handler,
                        /* [retval, out] */EventRegistrationToken * token
                        ) = 0;
                    /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_SettingChanged(
                        /* [in] */EventRegistrationToken token
                        ) = 0;
                    /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_StateChanged(
                        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs * handler,
                        /* [retval, out] */EventRegistrationToken * token
                        ) = 0;
                    /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_StateChanged(
                        /* [in] */EventRegistrationToken token
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentIslandEnvironment=_uuidof(IContentIslandEnvironment);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandEnvironmentFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIslandEnvironment
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandEnvironmentFactory[] = L"Microsoft.UI.Content.IContentIslandEnvironmentFactory";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("47A782D6-B177-5C1E-BF87-90437DD809D0"), exclusiveto, contract] */
                MIDL_INTERFACE("47A782D6-B177-5C1E-BF87-90437DD809D0")
                IContentIslandEnvironmentFactory : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IContentIslandEnvironmentFactory=_uuidof(IContentIslandEnvironmentFactory);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIsland
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandFactory[] = L"Microsoft.UI.Content.IContentIslandFactory";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("82383F52-E81A-5EC9-A954-BAC8A931BA7D"), exclusiveto, contract] */
                MIDL_INTERFACE("82383F52-E81A-5EC9-A954-BAC8A931BA7D")
                IContentIslandFactory : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IContentIslandFactory=_uuidof(IContentIslandFactory);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIslandStateChangedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandStateChangedEventArgs[] = L"Microsoft.UI.Content.IContentIslandStateChangedEventArgs";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("C828EEB2-0C62-5B40-9D48-77C06083C278"), exclusiveto, contract] */
                MIDL_INTERFACE("C828EEB2-0C62-5B40-9D48-77C06083C278")
                IContentIslandStateChangedEventArgs : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DidActualSizeChange(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DidSiteEnabledChange(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DidSiteVisibleChange(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DidLayoutDirectionChange(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DidRasterizationScaleChange(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentIslandStateChangedEventArgs=_uuidof(IContentIslandStateChangedEventArgs);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIsland
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandStatics[] = L"Microsoft.UI.Content.IContentIslandStatics";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("7B9EB7CC-8C43-5E0A-AB23-AB48628FD223"), exclusiveto, contract] */
                MIDL_INTERFACE("7B9EB7CC-8C43-5E0A-AB23-AB48628FD223")
                IContentIslandStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Create(
                        /* [in] */ABI::Microsoft::UI::Composition::IVisual * Root,
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentIsland * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindAllForCompositor(
                        /* [in] */ABI::Microsoft::UI::Composition::ICompositor * compositor,
                        /* [out] */UINT32 * __resultSize,
                        /* [size_is(, *(__resultSize)), retval, out] */ABI::Microsoft::UI::Content::IContentIsland * * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindAllForCurrentThread(
                        /* [out] */UINT32 * __resultSize,
                        /* [size_is(, *(__resultSize)), retval, out] */ABI::Microsoft::UI::Content::IContentIsland * * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetByVisual(
                        /* [in] */ABI::Microsoft::UI::Composition::IVisual * child,
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentIsland * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetFromId(
                        /* [in] */UINT64 id,
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentIsland * * result
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentIslandStatics=_uuidof(IContentIslandStatics);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSite
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSite
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSite[] = L"Microsoft.UI.Content.IContentSite";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("996C60C4-02B2-5EEF-93B0-DD6B1EC2FD7B"), exclusiveto, contract] */
                MIDL_INTERFACE("996C60C4-02B2-5EEF-93B0-DD6B1EC2FD7B")
                IContentSite : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ActualSize(
                        /* [retval, out] */ABI::Windows::Foundation::Numerics::Vector2 * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ActualSize(
                        /* [in] */ABI::Windows::Foundation::Numerics::Vector2 value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ClientSize(
                        /* [retval, out] */ABI::Windows::Graphics::SizeInt32 * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ClientSize(
                        /* [in] */ABI::Windows::Graphics::SizeInt32 value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CoordinateConverter(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentCoordinateConverter * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DispatcherQueue(
                        /* [retval, out] */ABI::Microsoft::UI::Dispatching::IDispatcherQueue * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Environment(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentSiteEnvironment * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsConnected(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSiteEnabled(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsSiteEnabled(
                        /* [in] */::boolean value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSiteVisible(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsSiteVisible(
                        /* [in] */::boolean value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LayoutDirection(
                        /* [retval, out] */ABI::Microsoft::UI::Content::ContentLayoutDirection * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_LayoutDirection(
                        /* [in] */ABI::Microsoft::UI::Content::ContentLayoutDirection value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OverrideScale(
                        /* [retval, out] */FLOAT * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_OverrideScale(
                        /* [in] */FLOAT value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ParentScale(
                        /* [retval, out] */FLOAT * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ParentScale(
                        /* [in] */FLOAT value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RasterizationScale(
                        /* [retval, out] */FLOAT * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RequestedSize(
                        /* [retval, out] */ABI::Windows::Foundation::Numerics::Vector2 * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ShouldApplyRasterizationScale(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ShouldApplyRasterizationScale(
                        /* [in] */::boolean value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_View(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentSiteView * * value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetIslandStateChangeDeferral(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentDeferral * * result
                        ) = 0;
                    /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_RequestedStateChanged(
                        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs * handler,
                        /* [retval, out] */EventRegistrationToken * token
                        ) = 0;
                    /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_RequestedStateChanged(
                        /* [in] */EventRegistrationToken token
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentSite=_uuidof(IContentSite);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSite;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.Foundation.IClosable
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteBridge[] = L"Microsoft.UI.Content.IContentSiteBridge";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("FAAAB99E-A42B-549C-92DF-3B6D6E1E368B"), contract] */
                MIDL_INTERFACE("FAAAB99E-A42B-549C-92DF-3B6D6E1E368B")
                IContentSiteBridge : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DispatcherQueue(
                        /* [retval, out] */ABI::Microsoft::UI::Dispatching::IDispatcherQueue * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LayoutDirectionOverride(
                        /* [retval, out] */__FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_LayoutDirectionOverride(
                        /* [in] */__FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OverrideScale(
                        /* [retval, out] */FLOAT * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_OverrideScale(
                        /* [in] */FLOAT value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteBridge=_uuidof(IContentSiteBridge);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteEnvironment
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteEnvironment
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteEnvironment[] = L"Microsoft.UI.Content.IContentSiteEnvironment";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("685D085D-BE53-55D1-AEC4-BA2273D5468B"), exclusiveto, contract] */
                MIDL_INTERFACE("685D085D-BE53-55D1-AEC4-BA2273D5468B")
                IContentSiteEnvironment : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AppWindowId(
                        /* [retval, out] */ABI::Microsoft::UI::WindowId * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_AppWindowId(
                        /* [in] */ABI::Microsoft::UI::WindowId value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DisplayId(
                        /* [retval, out] */ABI::Microsoft::UI::DisplayId * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_DisplayId(
                        /* [in] */ABI::Microsoft::UI::DisplayId value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_View(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentSiteEnvironmentView * * value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE NotifySettingChanged(
                        /* [in] */HSTRING setting
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteEnvironment=_uuidof(IContentSiteEnvironment);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteEnvironmentFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteEnvironment
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteEnvironmentFactory[] = L"Microsoft.UI.Content.IContentSiteEnvironmentFactory";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("0BEFA998-CB15-5F16-A4A5-C0ED1674E186"), exclusiveto, contract] */
                MIDL_INTERFACE("0BEFA998-CB15-5F16-A4A5-C0ED1674E186")
                IContentSiteEnvironmentFactory : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteEnvironmentFactory=_uuidof(IContentSiteEnvironmentFactory);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteEnvironmentView
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteEnvironmentView
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteEnvironmentView[] = L"Microsoft.UI.Content.IContentSiteEnvironmentView";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("5B6FE420-0BB3-54DD-8589-786CF02E38F1"), exclusiveto, contract] */
                MIDL_INTERFACE("5B6FE420-0BB3-54DD-8589-786CF02E38F1")
                IContentSiteEnvironmentView : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AppWindowId(
                        /* [retval, out] */ABI::Microsoft::UI::WindowId * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DisplayId(
                        /* [retval, out] */ABI::Microsoft::UI::DisplayId * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteEnvironmentView=_uuidof(IContentSiteEnvironmentView);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteEnvironmentViewFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteEnvironmentView
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteEnvironmentViewFactory[] = L"Microsoft.UI.Content.IContentSiteEnvironmentViewFactory";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("C901EDF2-F184-5A64-8D58-8CF8EFA8B678"), exclusiveto, contract] */
                MIDL_INTERFACE("C901EDF2-F184-5A64-8D58-8CF8EFA8B678")
                IContentSiteEnvironmentViewFactory : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteEnvironmentViewFactory=_uuidof(IContentSiteEnvironmentViewFactory);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSite
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteFactory[] = L"Microsoft.UI.Content.IContentSiteFactory";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("72FB98D5-B28A-57F1-91FA-24C014A342C1"), exclusiveto, contract] */
                MIDL_INTERFACE("72FB98D5-B28A-57F1-91FA-24C014A342C1")
                IContentSiteFactory : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteFactory=_uuidof(IContentSiteFactory);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteRequestedStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteRequestedStateChangedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteRequestedStateChangedEventArgs[] = L"Microsoft.UI.Content.IContentSiteRequestedStateChangedEventArgs";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("1B55FD1D-7292-562B-B4A1-D4DE7972E684"), exclusiveto, contract] */
                MIDL_INTERFACE("1B55FD1D-7292-562B-B4A1-D4DE7972E684")
                IContentSiteRequestedStateChangedEventArgs : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DidRequestedSizeChange(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteRequestedStateChangedEventArgs=_uuidof(IContentSiteRequestedStateChangedEventArgs);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteView
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteView
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteView[] = L"Microsoft.UI.Content.IContentSiteView";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("2D5D8DD5-358E-5B05-993B-B2666D1786B3"), exclusiveto, contract] */
                MIDL_INTERFACE("2D5D8DD5-358E-5B05-993B-B2666D1786B3")
                IContentSiteView : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ActualSize(
                        /* [retval, out] */ABI::Windows::Foundation::Numerics::Vector2 * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ClientSize(
                        /* [retval, out] */ABI::Windows::Graphics::SizeInt32 * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CoordinateConverter(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentCoordinateConverter * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DispatcherQueue(
                        /* [retval, out] */ABI::Microsoft::UI::Dispatching::IDispatcherQueue * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_EnvironmentView(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentSiteEnvironmentView * * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsConnected(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSiteEnabled(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSiteVisible(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LayoutDirection(
                        /* [retval, out] */ABI::Microsoft::UI::Content::ContentLayoutDirection * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OverrideScale(
                        /* [retval, out] */FLOAT * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ParentScale(
                        /* [retval, out] */FLOAT * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RasterizationScale(
                        /* [retval, out] */FLOAT * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RequestedSize(
                        /* [retval, out] */ABI::Windows::Foundation::Numerics::Vector2 * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ShouldApplyRasterizationScale(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteView=_uuidof(IContentSiteView);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteViewFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteView
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteViewFactory[] = L"Microsoft.UI.Content.IContentSiteViewFactory";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("9EFD72F0-63EF-5B6A-A50C-5685BD8100F1"), exclusiveto, contract] */
                MIDL_INTERFACE("9EFD72F0-63EF-5B6A-A50C-5685BD8100F1")
                IContentSiteViewFactory : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IContentSiteViewFactory=_uuidof(IContentSiteViewFactory);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopChildSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopChildSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopChildSiteBridge[] = L"Microsoft.UI.Content.IDesktopChildSiteBridge";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("B2F2FF7B-1825-51B0-B80B-7599889C569F"), exclusiveto, contract] */
                MIDL_INTERFACE("B2F2FF7B-1825-51B0-B80B-7599889C569F")
                IDesktopChildSiteBridge : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ResizePolicy(
                        /* [retval, out] */ABI::Microsoft::UI::Content::ContentSizePolicy * value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ResizePolicy(
                        /* [in] */ABI::Microsoft::UI::Content::ContentSizePolicy value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SiteView(
                        /* [retval, out] */ABI::Microsoft::UI::Content::IContentSiteView * * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IDesktopChildSiteBridge=_uuidof(IDesktopChildSiteBridge);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopChildSiteBridgeStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopChildSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopChildSiteBridgeStatics[] = L"Microsoft.UI.Content.IDesktopChildSiteBridgeStatics";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("AB6B82DE-6A47-5DE3-A860-613C8DB679AB"), exclusiveto, contract] */
                MIDL_INTERFACE("AB6B82DE-6A47-5DE3-A860-613C8DB679AB")
                IDesktopChildSiteBridgeStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Create(
                        /* [in] */ABI::Microsoft::UI::Composition::ICompositor * compositor,
                        /* [in] */ABI::Microsoft::UI::WindowId parentWindowId,
                        /* [retval, out] */ABI::Microsoft::UI::Content::IDesktopChildSiteBridge * * result
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IDesktopChildSiteBridgeStatics=_uuidof(IDesktopChildSiteBridgeStatics);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopSiteBridge[] = L"Microsoft.UI.Content.IDesktopSiteBridge";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("F0AE8750-905C-50A2-8A12-4545C6245BB4"), exclusiveto, contract] */
                MIDL_INTERFACE("F0AE8750-905C-50A2-8A12-4545C6245BB4")
                IDesktopSiteBridge : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsEnabled(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsVisible(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_WindowId(
                        /* [retval, out] */ABI::Microsoft::UI::WindowId * value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE Connect(
                        /* [in] */ABI::Microsoft::UI::Content::IContentIsland * content
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE Disable(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE Enable(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE Hide(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE MoveAndResize(
                        /* [in] */ABI::Windows::Graphics::RectInt32 rect
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE MoveInZOrderAtBottom(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE MoveInZOrderAtTop(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE MoveInZOrderBelow(
                        /* [in] */ABI::Microsoft::UI::WindowId windowId
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE Show(void) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IDesktopSiteBridge=_uuidof(IDesktopSiteBridge);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopSiteBridgeFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopSiteBridgeFactory[] = L"Microsoft.UI.Content.IDesktopSiteBridgeFactory";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("D94EE1FF-3AF1-54D0-9311-652B29C57C5B"), exclusiveto, contract] */
                MIDL_INTERFACE("D94EE1FF-3AF1-54D0-9311-652B29C57C5B")
                IDesktopSiteBridgeFactory : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IDesktopSiteBridgeFactory=_uuidof(IDesktopSiteBridgeFactory);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopSiteBridgeStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopSiteBridgeStatics[] = L"Microsoft.UI.Content.IDesktopSiteBridgeStatics";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Content {
                /* [object, uuid("E0B38DAF-9CD4-50C5-83EE-C76E3CF34EBA"), exclusiveto, contract] */
                MIDL_INTERFACE("E0B38DAF-9CD4-50C5-83EE-C76E3CF34EBA")
                IDesktopSiteBridgeStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE IsSupported(
                        /* [retval, out] */::boolean * result
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IDesktopSiteBridgeStatics=_uuidof(IDesktopSiteBridgeStatics);
                
            } /* Content */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentCoordinateConverter
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Content.IContentCoordinateConverterStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentCoordinateConverter ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentCoordinateConverter_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentCoordinateConverter_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentCoordinateConverter[] = L"Microsoft.UI.Content.ContentCoordinateConverter";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentDeferral
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentDeferral ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentDeferral_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentDeferral_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentDeferral[] = L"Microsoft.UI.Content.ContentDeferral";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentEnvironmentSettingChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentEnvironmentSettingChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentEnvironmentSettingChangedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentEnvironmentSettingChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentEnvironmentSettingChangedEventArgs[] = L"Microsoft.UI.Content.ContentEnvironmentSettingChangedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentEnvironmentStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentEnvironmentStateChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentEnvironmentStateChangedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentEnvironmentStateChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentEnvironmentStateChangedEventArgs[] = L"Microsoft.UI.Content.ContentEnvironmentStateChangedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentIsland
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Content.IContentIslandStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentIsland ** Default Interface **
 *    Windows.Foundation.IClosable
 *    Microsoft.UI.IClosableNotifier
 *    Microsoft.UI.Composition.ICompositionSupportsSystemBackdrop
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentIsland_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentIsland_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentIsland[] = L"Microsoft.UI.Content.ContentIsland";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentIslandAutomationProviderRequestedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentIslandAutomationProviderRequestedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentIslandAutomationProviderRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentIslandAutomationProviderRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentIslandAutomationProviderRequestedEventArgs[] = L"Microsoft.UI.Content.ContentIslandAutomationProviderRequestedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentIslandEnvironment
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentIslandEnvironment ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentIslandEnvironment_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentIslandEnvironment_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentIslandEnvironment[] = L"Microsoft.UI.Content.ContentIslandEnvironment";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentIslandStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentIslandStateChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentIslandStateChangedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentIslandStateChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentIslandStateChangedEventArgs[] = L"Microsoft.UI.Content.ContentIslandStateChangedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSite
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSite ** Default Interface **
 *    Windows.Foundation.IClosable
 *    Microsoft.UI.IClosableNotifier
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSite_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSite_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSite[] = L"Microsoft.UI.Content.ContentSite";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSiteEnvironment
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSiteEnvironment ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSiteEnvironment_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSiteEnvironment_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSiteEnvironment[] = L"Microsoft.UI.Content.ContentSiteEnvironment";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSiteEnvironmentView
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSiteEnvironmentView ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSiteEnvironmentView_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSiteEnvironmentView_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSiteEnvironmentView[] = L"Microsoft.UI.Content.ContentSiteEnvironmentView";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSiteRequestedStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSiteRequestedStateChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSiteRequestedStateChangedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSiteRequestedStateChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSiteRequestedStateChangedEventArgs[] = L"Microsoft.UI.Content.ContentSiteRequestedStateChangedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSiteView
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSiteView ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSiteView_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSiteView_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSiteView[] = L"Microsoft.UI.Content.ContentSiteView";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.DesktopChildSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Content.IDesktopChildSiteBridgeStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IDesktopChildSiteBridge ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_DesktopChildSiteBridge_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_DesktopChildSiteBridge_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_DesktopChildSiteBridge[] = L"Microsoft.UI.Content.DesktopChildSiteBridge";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.DesktopSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Content.IDesktopSiteBridgeStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IDesktopSiteBridge ** Default Interface **
 *    Microsoft.UI.IClosableNotifier
 *    Microsoft.UI.Content.IContentSiteBridge
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_DesktopSiteBridge_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_DesktopSiteBridge_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_DesktopSiteBridge[] = L"Microsoft.UI.Content.DesktopSiteBridge";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004




#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSite __x_ABI_CMicrosoft_CUI_CContent_CIContentSite;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics;

#endif // ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions
enum __x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection;
#if !defined(____FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_INTERFACE_DEFINED__)
#define ____FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_INTERFACE_DEFINED__

typedef interface __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection;

typedef struct __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirectionVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )( __RPC__in __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * This );
    ULONG ( STDMETHODCALLTYPE *Release )( __RPC__in __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * This );

    HRESULT ( STDMETHODCALLTYPE *GetIids )( __RPC__in __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * This, 
                                            /* [out] */ __RPC__out ULONG *iidCount,
                                            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( __RPC__in __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( __RPC__in __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )(__RPC__in __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * This, /* [retval][out] */ __RPC__out enum __x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection *value);
    END_INTERFACE
} __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirectionVtbl;

interface __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection
{
    CONST_VTBL struct __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirectionVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 
#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 
#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 

#define __FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_get_Value(This,value)	\
    ( (This)->lpVtbl -> get_Value(This,value) ) 
#endif /* COBJMACROS */


#endif // ____FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection_INTERFACE_DEFINED__




#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs * This,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * sender,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * e);
    END_INTERFACE
} __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */



#endif // ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__

#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004



#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs;

typedef struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs * This,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * sender,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * e);
    END_INTERFACE
} __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgsVtbl;

interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */



#endif // ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs_INTERFACE_DEFINED__

#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004



#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs;

typedef struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs * This,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * sender,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs * e);
    END_INTERFACE
} __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgsVtbl;

interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */



#endif // ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__

#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004



#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs;

typedef struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs * This,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * sender,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * e);
    END_INTERFACE
} __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgsVtbl;

interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */



#endif // ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__

#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004



#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs;

typedef struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs * This,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * sender,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs * e);
    END_INTERFACE
} __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgsVtbl;

interface __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */



#endif // ____FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__

#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004





#ifndef ____x_ABI_CMicrosoft_CUI_CComposition_CICompositor_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CComposition_CICompositor_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CComposition_CICompositor __x_ABI_CMicrosoft_CUI_CComposition_CICompositor;

#endif // ____x_ABI_CMicrosoft_CUI_CComposition_CICompositor_FWD_DEFINED__


#ifndef ____x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop __x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop;

#endif // ____x_ABI_CMicrosoft_CUI_CComposition_CICompositionSupportsSystemBackdrop_FWD_DEFINED__


#ifndef ____x_ABI_CMicrosoft_CUI_CComposition_CIVisual_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CComposition_CIVisual_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CComposition_CIVisual __x_ABI_CMicrosoft_CUI_CComposition_CIVisual;

#endif // ____x_ABI_CMicrosoft_CUI_CComposition_CIVisual_FWD_DEFINED__





#ifndef ____x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue __x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue;

#endif // ____x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue_FWD_DEFINED__






typedef struct __x_ABI_CMicrosoft_CUI_CDisplayId __x_ABI_CMicrosoft_CUI_CDisplayId;

#ifndef ____x_ABI_CMicrosoft_CUI_CIClosableNotifier_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CIClosableNotifier_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CIClosableNotifier __x_ABI_CMicrosoft_CUI_CIClosableNotifier;

#endif // ____x_ABI_CMicrosoft_CUI_CIClosableNotifier_FWD_DEFINED__



typedef struct __x_ABI_CMicrosoft_CUI_CWindowId __x_ABI_CMicrosoft_CUI_CWindowId;



#ifndef ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet;

#endif // ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__





#ifndef ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIClosable __x_ABI_CWindows_CFoundation_CIClosable;

#endif // ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__





typedef struct __x_ABI_CWindows_CFoundation_CNumerics_CVector2 __x_ABI_CWindows_CFoundation_CNumerics_CVector2;





typedef struct __x_ABI_CWindows_CFoundation_CPoint __x_ABI_CWindows_CFoundation_CPoint;


typedef struct __x_ABI_CWindows_CFoundation_CRect __x_ABI_CWindows_CFoundation_CRect;




typedef struct __x_ABI_CWindows_CGraphics_CPointInt32 __x_ABI_CWindows_CGraphics_CPointInt32;


typedef struct __x_ABI_CWindows_CGraphics_CRectInt32 __x_ABI_CWindows_CGraphics_CRectInt32;


typedef struct __x_ABI_CWindows_CGraphics_CSizeInt32 __x_ABI_CWindows_CGraphics_CSizeInt32;




typedef enum __x_ABI_CMicrosoft_CUI_CContent_CContentCoordinateRoundingMode __x_ABI_CMicrosoft_CUI_CContent_CContentCoordinateRoundingMode;


typedef enum __x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection __x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection;


typedef enum __x_ABI_CMicrosoft_CUI_CContent_CContentSizePolicy __x_ABI_CMicrosoft_CUI_CContent_CContentSizePolicy;




















































/*
 *
 * Struct Microsoft.UI.Content.ContentCoordinateRoundingMode
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CUI_CContent_CContentCoordinateRoundingMode
{
    ContentCoordinateRoundingMode_Auto = 0,
    ContentCoordinateRoundingMode_Floor = 1,
    ContentCoordinateRoundingMode_Round = 2,
    ContentCoordinateRoundingMode_Ceiling = 3,
};
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Struct Microsoft.UI.Content.ContentLayoutDirection
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection
{
    ContentLayoutDirection_LeftToRight = 0,
    ContentLayoutDirection_RightToLeft = 1,
};
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Struct Microsoft.UI.Content.ContentSizePolicy
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 */

#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CUI_CContent_CContentSizePolicy
{
    ContentSizePolicy_None = 0,
    ContentSizePolicy_ResizeContentToParentWindow = 1,
    ContentSizePolicy_ResizeParentWindowToContent = 2,
};
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentCoordinateConverter
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentCoordinateConverter
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentCoordinateConverter[] = L"Microsoft.UI.Content.IContentCoordinateConverter";
/* [object, uuid("10A11230-5EB4-5840-A346-570F4A49040F"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [overload, default_overload] */HRESULT ( STDMETHODCALLTYPE *ConvertLocalToScreenWithPoint )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CPoint localPoint,
        /* [retval, out] */__x_ABI_CWindows_CGraphics_CPointInt32 * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *ConvertLocalToScreenWithPoints )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
        /* [in] */UINT32 __localPointsSize,
        /* [size_is(__localPointsSize), in] */__x_ABI_CWindows_CFoundation_CPoint * localPoints,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */__x_ABI_CWindows_CGraphics_CPointInt32 * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *ConvertLocalToScreenWithPointsAndRoundingMode )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
        /* [in] */UINT32 __localPointsSize,
        /* [size_is(__localPointsSize), in] */__x_ABI_CWindows_CFoundation_CPoint * localPoints,
        /* [in] */__x_ABI_CMicrosoft_CUI_CContent_CContentCoordinateRoundingMode roundingMode,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */__x_ABI_CWindows_CGraphics_CPointInt32 * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *ConvertLocalToScreenWithRect )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CRect localRect,
        /* [retval, out] */__x_ABI_CWindows_CGraphics_CRectInt32 * result
        );
    /* [overload, default_overload] */HRESULT ( STDMETHODCALLTYPE *ConvertScreenToLocalWithPoint )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
        /* [in] */__x_ABI_CWindows_CGraphics_CPointInt32 screenPoint,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CPoint * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *ConvertScreenToLocalWithPoints )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
        /* [in] */UINT32 __screenPointsSize,
        /* [size_is(__screenPointsSize), in] */__x_ABI_CWindows_CGraphics_CPointInt32 * screenPoints,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */__x_ABI_CWindows_CFoundation_CPoint * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *ConvertScreenToLocalWithRect )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * This,
        /* [in] */__x_ABI_CWindows_CGraphics_CRectInt32 screenRect,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CRect * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_ConvertLocalToScreenWithPoint(This,localPoint,result) \
    ( (This)->lpVtbl->ConvertLocalToScreenWithPoint(This,localPoint,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_ConvertLocalToScreenWithPoints(This,__localPointsSize,localPoints,__resultSize,result) \
    ( (This)->lpVtbl->ConvertLocalToScreenWithPoints(This,__localPointsSize,localPoints,__resultSize,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_ConvertLocalToScreenWithPointsAndRoundingMode(This,__localPointsSize,localPoints,roundingMode,__resultSize,result) \
    ( (This)->lpVtbl->ConvertLocalToScreenWithPointsAndRoundingMode(This,__localPointsSize,localPoints,roundingMode,__resultSize,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_ConvertLocalToScreenWithRect(This,localRect,result) \
    ( (This)->lpVtbl->ConvertLocalToScreenWithRect(This,localRect,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_ConvertScreenToLocalWithPoint(This,screenPoint,result) \
    ( (This)->lpVtbl->ConvertScreenToLocalWithPoint(This,screenPoint,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_ConvertScreenToLocalWithPoints(This,__screenPointsSize,screenPoints,__resultSize,result) \
    ( (This)->lpVtbl->ConvertScreenToLocalWithPoints(This,__screenPointsSize,screenPoints,__resultSize,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_ConvertScreenToLocalWithRect(This,screenRect,result) \
    ( (This)->lpVtbl->ConvertScreenToLocalWithRect(This,screenRect,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentCoordinateConverterFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentCoordinateConverter
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentCoordinateConverterFactory[] = L"Microsoft.UI.Content.IContentCoordinateConverterFactory";
/* [object, uuid("A4B216EE-0E26-56BD-9209-A75CF9D80F27"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactoryVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentCoordinateConverterStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentCoordinateConverter
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentCoordinateConverterStatics[] = L"Microsoft.UI.Content.IContentCoordinateConverterStatics";
/* [object, uuid("F56374CE-B6DF-5B42-A58F-4E3BB039E3A9"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateForWindowId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CWindowId windowId,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStaticsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_CreateForWindowId(This,windowId,result) \
    ( (This)->lpVtbl->CreateForWindowId(This,windowId,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverterStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentDeferral
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentDeferral
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentDeferral[] = L"Microsoft.UI.Content.IContentDeferral";
/* [object, uuid("470529F5-CD93-599B-968E-F8A689BC3A07"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferralVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *Complete )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * This
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferralVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferralVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_Complete(This) \
    ( (This)->lpVtbl->Complete(This) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentEnvironmentSettingChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentEnvironmentSettingChangedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentEnvironmentSettingChangedEventArgs[] = L"Microsoft.UI.Content.IContentEnvironmentSettingChangedEventArgs";
/* [object, uuid("76478051-FC80-5EEC-A3F3-62606ABE06B7"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SettingName )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_get_SettingName(This,value) \
    ( (This)->lpVtbl->get_SettingName(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentSettingChangedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentEnvironmentStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentEnvironmentStateChangedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentEnvironmentStateChangedEventArgs[] = L"Microsoft.UI.Content.IContentEnvironmentStateChangedEventArgs";
/* [object, uuid("8970FA4F-10BA-5F67-970B-8C72BC009B67"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DidAppWindowIdChange )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DidDisplayIdChange )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_get_DidAppWindowIdChange(This,value) \
    ( (This)->lpVtbl->get_DidAppWindowIdChange(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_get_DidDisplayIdChange(This,value) \
    ( (This)->lpVtbl->get_DidDisplayIdChange(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentEnvironmentStateChangedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIsland
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIsland
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIsland[] = L"Microsoft.UI.Content.IContentIsland";
/* [object, uuid("5B2504BA-361C-50AA-BD6E-4122C6D93889"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ActualSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CNumerics_CVector2 * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AppData )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */IInspectable * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AppData )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */IInspectable * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CoordinateConverter )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CustomProperties )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CCollections_CIPropertySet * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DispatcherQueue )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Environment )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Id )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */UINT64 * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsConnected )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsHitTestVisibleWhenTransparent )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsHitTestVisibleWhenTransparent )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsIslandEnabled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsIslandEnabled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsIslandVisible )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsIslandVisible )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSiteEnabled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSiteVisible )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LayoutDirection )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RasterizationScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */FLOAT * value
        );
    HRESULT ( STDMETHODCALLTYPE *GetAutomationHostProvider )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */IInspectable * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetStateChangeDeferral )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * * result
        );
    HRESULT ( STDMETHODCALLTYPE *RequestSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CNumerics_CVector2 size
        );
    /* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_AutomationProviderRequested )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandAutomationProviderRequestedEventArgs * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_AutomationProviderRequested )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */EventRegistrationToken token
        );
    /* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_StateChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIsland_Microsoft__CUI__CContent__CContentIslandStateChangedEventArgs * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_StateChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * This,
        /* [in] */EventRegistrationToken token
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_ActualSize(This,value) \
    ( (This)->lpVtbl->get_ActualSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_AppData(This,value) \
    ( (This)->lpVtbl->get_AppData(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_put_AppData(This,value) \
    ( (This)->lpVtbl->put_AppData(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_CoordinateConverter(This,value) \
    ( (This)->lpVtbl->get_CoordinateConverter(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_CustomProperties(This,value) \
    ( (This)->lpVtbl->get_CustomProperties(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_DispatcherQueue(This,value) \
    ( (This)->lpVtbl->get_DispatcherQueue(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_Environment(This,value) \
    ( (This)->lpVtbl->get_Environment(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_Id(This,value) \
    ( (This)->lpVtbl->get_Id(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_IsConnected(This,value) \
    ( (This)->lpVtbl->get_IsConnected(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_IsHitTestVisibleWhenTransparent(This,value) \
    ( (This)->lpVtbl->get_IsHitTestVisibleWhenTransparent(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_put_IsHitTestVisibleWhenTransparent(This,value) \
    ( (This)->lpVtbl->put_IsHitTestVisibleWhenTransparent(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_IsIslandEnabled(This,value) \
    ( (This)->lpVtbl->get_IsIslandEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_put_IsIslandEnabled(This,value) \
    ( (This)->lpVtbl->put_IsIslandEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_IsIslandVisible(This,value) \
    ( (This)->lpVtbl->get_IsIslandVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_put_IsIslandVisible(This,value) \
    ( (This)->lpVtbl->put_IsIslandVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_IsSiteEnabled(This,value) \
    ( (This)->lpVtbl->get_IsSiteEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_IsSiteVisible(This,value) \
    ( (This)->lpVtbl->get_IsSiteVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_LayoutDirection(This,value) \
    ( (This)->lpVtbl->get_LayoutDirection(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_get_RasterizationScale(This,value) \
    ( (This)->lpVtbl->get_RasterizationScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_GetAutomationHostProvider(This,result) \
    ( (This)->lpVtbl->GetAutomationHostProvider(This,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_GetStateChangeDeferral(This,result) \
    ( (This)->lpVtbl->GetStateChangeDeferral(This,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_RequestSize(This,size) \
    ( (This)->lpVtbl->RequestSize(This,size) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_add_AutomationProviderRequested(This,handler,token) \
    ( (This)->lpVtbl->add_AutomationProviderRequested(This,handler,token) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_remove_AutomationProviderRequested(This,token) \
    ( (This)->lpVtbl->remove_AutomationProviderRequested(This,token) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_add_StateChanged(This,handler,token) \
    ( (This)->lpVtbl->add_StateChanged(This,handler,token) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_remove_StateChanged(This,token) \
    ( (This)->lpVtbl->remove_StateChanged(This,token) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIsland;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIsland_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandAutomationProviderRequestedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIslandAutomationProviderRequestedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandAutomationProviderRequestedEventArgs[] = L"Microsoft.UI.Content.IContentIslandAutomationProviderRequestedEventArgs";
/* [object, uuid("9FE24BED-2B9C-5137-887F-403C94841824"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AutomationProvider )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This,
        /* [retval, out] */IInspectable * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AutomationProvider )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This,
        /* [in] */IInspectable * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Handled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Handled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs * This,
        /* [in] */boolean value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_get_AutomationProvider(This,value) \
    ( (This)->lpVtbl->get_AutomationProvider(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_put_AutomationProvider(This,value) \
    ( (This)->lpVtbl->put_AutomationProvider(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_get_Handled(This,value) \
    ( (This)->lpVtbl->get_Handled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_put_Handled(This,value) \
    ( (This)->lpVtbl->put_Handled(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandAutomationProviderRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandEnvironment
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIslandEnvironment
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandEnvironment[] = L"Microsoft.UI.Content.IContentIslandEnvironment";
/* [object, uuid("C334236D-DA88-566D-811D-74AEF2EBA978"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AppWindowId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CWindowId * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DisplayId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CDisplayId * value
        );
    /* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_SettingChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentSettingChangedEventArgs * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_SettingChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
        /* [in] */EventRegistrationToken token
        );
    /* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_StateChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentIslandEnvironment_Microsoft__CUI__CContent__CContentEnvironmentStateChangedEventArgs * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_StateChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment * This,
        /* [in] */EventRegistrationToken token
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_get_AppWindowId(This,value) \
    ( (This)->lpVtbl->get_AppWindowId(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_get_DisplayId(This,value) \
    ( (This)->lpVtbl->get_DisplayId(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_add_SettingChanged(This,handler,token) \
    ( (This)->lpVtbl->add_SettingChanged(This,handler,token) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_remove_SettingChanged(This,token) \
    ( (This)->lpVtbl->remove_SettingChanged(This,token) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_add_StateChanged(This,handler,token) \
    ( (This)->lpVtbl->add_StateChanged(This,handler,token) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_remove_StateChanged(This,token) \
    ( (This)->lpVtbl->remove_StateChanged(This,token) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironment_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandEnvironmentFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIslandEnvironment
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandEnvironmentFactory[] = L"Microsoft.UI.Content.IContentIslandEnvironmentFactory";
/* [object, uuid("47A782D6-B177-5C1E-BF87-90437DD809D0"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactoryVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandEnvironmentFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIsland
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandFactory[] = L"Microsoft.UI.Content.IContentIslandFactory";
/* [object, uuid("82383F52-E81A-5EC9-A954-BAC8A931BA7D"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactoryVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIslandStateChangedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandStateChangedEventArgs[] = L"Microsoft.UI.Content.IContentIslandStateChangedEventArgs";
/* [object, uuid("C828EEB2-0C62-5B40-9D48-77C06083C278"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DidActualSizeChange )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DidSiteEnabledChange )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DidSiteVisibleChange )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DidLayoutDirectionChange )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DidRasterizationScaleChange )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_get_DidActualSizeChange(This,value) \
    ( (This)->lpVtbl->get_DidActualSizeChange(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_get_DidSiteEnabledChange(This,value) \
    ( (This)->lpVtbl->get_DidSiteEnabledChange(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_get_DidSiteVisibleChange(This,value) \
    ( (This)->lpVtbl->get_DidSiteVisibleChange(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_get_DidLayoutDirectionChange(This,value) \
    ( (This)->lpVtbl->get_DidLayoutDirectionChange(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_get_DidRasterizationScaleChange(This,value) \
    ( (This)->lpVtbl->get_DidRasterizationScaleChange(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStateChangedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentIslandStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentIsland
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentIslandStatics[] = L"Microsoft.UI.Content.IContentIslandStatics";
/* [object, uuid("7B9EB7CC-8C43-5E0A-AB23-AB48628FD223"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *Create )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CComposition_CIVisual * Root,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * * result
        );
    HRESULT ( STDMETHODCALLTYPE *FindAllForCompositor )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CComposition_CICompositor * compositor,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * * * result
        );
    HRESULT ( STDMETHODCALLTYPE *FindAllForCurrentThread )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetByVisual )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CComposition_CIVisual * child,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetFromId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics * This,
        /* [in] */UINT64 id,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStaticsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_Create(This,Root,result) \
    ( (This)->lpVtbl->Create(This,Root,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_FindAllForCompositor(This,compositor,__resultSize,result) \
    ( (This)->lpVtbl->FindAllForCompositor(This,compositor,__resultSize,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_FindAllForCurrentThread(This,__resultSize,result) \
    ( (This)->lpVtbl->FindAllForCurrentThread(This,__resultSize,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_GetByVisual(This,child,result) \
    ( (This)->lpVtbl->GetByVisual(This,child,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_GetFromId(This,id,result) \
    ( (This)->lpVtbl->GetFromId(This,id,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentIslandStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSite
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSite
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSite[] = L"Microsoft.UI.Content.IContentSite";
/* [object, uuid("996C60C4-02B2-5EEF-93B0-DD6B1EC2FD7B"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ActualSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CNumerics_CVector2 * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ActualSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CNumerics_CVector2 value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ClientSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CWindows_CGraphics_CSizeInt32 * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ClientSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */__x_ABI_CWindows_CGraphics_CSizeInt32 value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CoordinateConverter )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DispatcherQueue )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Environment )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsConnected )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSiteEnabled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsSiteEnabled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSiteVisible )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsSiteVisible )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LayoutDirection )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_LayoutDirection )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OverrideScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */FLOAT * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_OverrideScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */FLOAT value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ParentScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */FLOAT * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ParentScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */FLOAT value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RasterizationScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */FLOAT * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RequestedSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CNumerics_CVector2 * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ShouldApplyRasterizationScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ShouldApplyRasterizationScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_View )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * * value
        );
    HRESULT ( STDMETHODCALLTYPE *GetIslandStateChangeDeferral )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentDeferral * * result
        );
    /* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_RequestedStateChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CContent__CContentSite_Microsoft__CUI__CContent__CContentSiteRequestedStateChangedEventArgs * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_RequestedStateChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSite * This,
        /* [in] */EventRegistrationToken token
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSite
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_ActualSize(This,value) \
    ( (This)->lpVtbl->get_ActualSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_put_ActualSize(This,value) \
    ( (This)->lpVtbl->put_ActualSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_ClientSize(This,value) \
    ( (This)->lpVtbl->get_ClientSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_put_ClientSize(This,value) \
    ( (This)->lpVtbl->put_ClientSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_CoordinateConverter(This,value) \
    ( (This)->lpVtbl->get_CoordinateConverter(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_DispatcherQueue(This,value) \
    ( (This)->lpVtbl->get_DispatcherQueue(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_Environment(This,value) \
    ( (This)->lpVtbl->get_Environment(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_IsConnected(This,value) \
    ( (This)->lpVtbl->get_IsConnected(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_IsSiteEnabled(This,value) \
    ( (This)->lpVtbl->get_IsSiteEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_put_IsSiteEnabled(This,value) \
    ( (This)->lpVtbl->put_IsSiteEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_IsSiteVisible(This,value) \
    ( (This)->lpVtbl->get_IsSiteVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_put_IsSiteVisible(This,value) \
    ( (This)->lpVtbl->put_IsSiteVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_LayoutDirection(This,value) \
    ( (This)->lpVtbl->get_LayoutDirection(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_put_LayoutDirection(This,value) \
    ( (This)->lpVtbl->put_LayoutDirection(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_OverrideScale(This,value) \
    ( (This)->lpVtbl->get_OverrideScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_put_OverrideScale(This,value) \
    ( (This)->lpVtbl->put_OverrideScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_ParentScale(This,value) \
    ( (This)->lpVtbl->get_ParentScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_put_ParentScale(This,value) \
    ( (This)->lpVtbl->put_ParentScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_RasterizationScale(This,value) \
    ( (This)->lpVtbl->get_RasterizationScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_RequestedSize(This,value) \
    ( (This)->lpVtbl->get_RequestedSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_ShouldApplyRasterizationScale(This,value) \
    ( (This)->lpVtbl->get_ShouldApplyRasterizationScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_put_ShouldApplyRasterizationScale(This,value) \
    ( (This)->lpVtbl->put_ShouldApplyRasterizationScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_get_View(This,value) \
    ( (This)->lpVtbl->get_View(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_GetIslandStateChangeDeferral(This,result) \
    ( (This)->lpVtbl->GetIslandStateChangeDeferral(This,result) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_add_RequestedStateChanged(This,handler,token) \
    ( (This)->lpVtbl->add_RequestedStateChanged(This,handler,token) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSite_remove_RequestedStateChanged(This,token) \
    ( (This)->lpVtbl->remove_RequestedStateChanged(This,token) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSite;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSite_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.Foundation.IClosable
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteBridge[] = L"Microsoft.UI.Content.IContentSiteBridge";
/* [object, uuid("FAAAB99E-A42B-549C-92DF-3B6D6E1E368B"), contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridgeVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DispatcherQueue )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LayoutDirectionOverride )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
        /* [retval, out] */__FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_LayoutDirectionOverride )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
        /* [in] */__FIReference_1_Microsoft__CUI__CContent__CContentLayoutDirection * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OverrideScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
        /* [retval, out] */FLOAT * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_OverrideScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge * This,
        /* [in] */FLOAT value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridgeVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridgeVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_get_DispatcherQueue(This,value) \
    ( (This)->lpVtbl->get_DispatcherQueue(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_get_LayoutDirectionOverride(This,value) \
    ( (This)->lpVtbl->get_LayoutDirectionOverride(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_put_LayoutDirectionOverride(This,value) \
    ( (This)->lpVtbl->put_LayoutDirectionOverride(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_get_OverrideScale(This,value) \
    ( (This)->lpVtbl->get_OverrideScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_put_OverrideScale(This,value) \
    ( (This)->lpVtbl->put_OverrideScale(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteBridge_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteEnvironment
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteEnvironment
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteEnvironment[] = L"Microsoft.UI.Content.IContentSiteEnvironment";
/* [object, uuid("685D085D-BE53-55D1-AEC4-BA2273D5468B"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AppWindowId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CWindowId * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_AppWindowId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CWindowId value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DisplayId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CDisplayId * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_DisplayId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CDisplayId value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_View )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * * value
        );
    HRESULT ( STDMETHODCALLTYPE *NotifySettingChanged )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment * This,
        /* [in] */HSTRING setting
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_get_AppWindowId(This,value) \
    ( (This)->lpVtbl->get_AppWindowId(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_put_AppWindowId(This,value) \
    ( (This)->lpVtbl->put_AppWindowId(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_get_DisplayId(This,value) \
    ( (This)->lpVtbl->get_DisplayId(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_put_DisplayId(This,value) \
    ( (This)->lpVtbl->put_DisplayId(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_get_View(This,value) \
    ( (This)->lpVtbl->get_View(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_NotifySettingChanged(This,setting) \
    ( (This)->lpVtbl->NotifySettingChanged(This,setting) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironment_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteEnvironmentFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteEnvironment
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteEnvironmentFactory[] = L"Microsoft.UI.Content.IContentSiteEnvironmentFactory";
/* [object, uuid("0BEFA998-CB15-5F16-A4A5-C0ED1674E186"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactoryVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteEnvironmentView
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteEnvironmentView
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteEnvironmentView[] = L"Microsoft.UI.Content.IContentSiteEnvironmentView";
/* [object, uuid("5B6FE420-0BB3-54DD-8589-786CF02E38F1"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AppWindowId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CWindowId * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DisplayId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CDisplayId * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_get_AppWindowId(This,value) \
    ( (This)->lpVtbl->get_AppWindowId(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_get_DisplayId(This,value) \
    ( (This)->lpVtbl->get_DisplayId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteEnvironmentViewFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteEnvironmentView
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteEnvironmentViewFactory[] = L"Microsoft.UI.Content.IContentSiteEnvironmentViewFactory";
/* [object, uuid("C901EDF2-F184-5A64-8D58-8CF8EFA8B678"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactoryVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentViewFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSite
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteFactory[] = L"Microsoft.UI.Content.IContentSiteFactory";
/* [object, uuid("72FB98D5-B28A-57F1-91FA-24C014A342C1"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactoryVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteRequestedStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteRequestedStateChangedEventArgs
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteRequestedStateChangedEventArgs[] = L"Microsoft.UI.Content.IContentSiteRequestedStateChangedEventArgs";
/* [object, uuid("1B55FD1D-7292-562B-B4A1-D4DE7972E684"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DidRequestedSizeChange )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs * This,
        /* [retval, out] */boolean * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_get_DidRequestedSizeChange(This,value) \
    ( (This)->lpVtbl->get_DidRequestedSizeChange(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteRequestedStateChangedEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteView
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteView
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteView[] = L"Microsoft.UI.Content.IContentSiteView";
/* [object, uuid("2D5D8DD5-358E-5B05-993B-B2666D1786B3"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ActualSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CNumerics_CVector2 * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ClientSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */__x_ABI_CWindows_CGraphics_CSizeInt32 * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CoordinateConverter )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentCoordinateConverter * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DispatcherQueue )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CDispatching_CIDispatcherQueue * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_EnvironmentView )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentSiteEnvironmentView * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsConnected )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSiteEnabled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSiteVisible )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LayoutDirection )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CContentLayoutDirection * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OverrideScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */FLOAT * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ParentScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */FLOAT * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RasterizationScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */FLOAT * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RequestedSize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CNumerics_CVector2 * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ShouldApplyRasterizationScale )(
        __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * This,
        /* [retval, out] */boolean * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_ActualSize(This,value) \
    ( (This)->lpVtbl->get_ActualSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_ClientSize(This,value) \
    ( (This)->lpVtbl->get_ClientSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_CoordinateConverter(This,value) \
    ( (This)->lpVtbl->get_CoordinateConverter(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_DispatcherQueue(This,value) \
    ( (This)->lpVtbl->get_DispatcherQueue(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_EnvironmentView(This,value) \
    ( (This)->lpVtbl->get_EnvironmentView(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_IsConnected(This,value) \
    ( (This)->lpVtbl->get_IsConnected(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_IsSiteEnabled(This,value) \
    ( (This)->lpVtbl->get_IsSiteEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_IsSiteVisible(This,value) \
    ( (This)->lpVtbl->get_IsSiteVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_LayoutDirection(This,value) \
    ( (This)->lpVtbl->get_LayoutDirection(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_OverrideScale(This,value) \
    ( (This)->lpVtbl->get_OverrideScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_ParentScale(This,value) \
    ( (This)->lpVtbl->get_ParentScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_RasterizationScale(This,value) \
    ( (This)->lpVtbl->get_RasterizationScale(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_RequestedSize(This,value) \
    ( (This)->lpVtbl->get_RequestedSize(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_get_ShouldApplyRasterizationScale(This,value) \
    ( (This)->lpVtbl->get_ShouldApplyRasterizationScale(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IContentSiteViewFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.ContentSiteView
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentSiteViewFactory[] = L"Microsoft.UI.Content.IContentSiteViewFactory";
/* [object, uuid("9EFD72F0-63EF-5B6A-A50C-5685BD8100F1"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactoryVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIContentSiteViewFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopChildSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopChildSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopChildSiteBridge[] = L"Microsoft.UI.Content.IDesktopChildSiteBridge";
/* [object, uuid("B2F2FF7B-1825-51B0-B80B-7599889C569F"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ResizePolicy )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CContentSizePolicy * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ResizePolicy )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CContent_CContentSizePolicy value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SiteView )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIContentSiteView * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_get_ResizePolicy(This,value) \
    ( (This)->lpVtbl->get_ResizePolicy(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_put_ResizePolicy(This,value) \
    ( (This)->lpVtbl->put_ResizePolicy(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_get_SiteView(This,value) \
    ( (This)->lpVtbl->get_SiteView(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopChildSiteBridgeStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopChildSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopChildSiteBridgeStatics[] = L"Microsoft.UI.Content.IDesktopChildSiteBridgeStatics";
/* [object, uuid("AB6B82DE-6A47-5DE3-A860-613C8DB679AB"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *Create )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CComposition_CICompositor * compositor,
        /* [in] */__x_ABI_CMicrosoft_CUI_CWindowId parentWindowId,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridge * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStaticsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_Create(This,compositor,parentWindowId,result) \
    ( (This)->lpVtbl->Create(This,compositor,parentWindowId,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopChildSiteBridgeStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopSiteBridge[] = L"Microsoft.UI.Content.IDesktopSiteBridge";
/* [object, uuid("F0AE8750-905C-50A2-8A12-4545C6245BB4"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsEnabled )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsVisible )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_WindowId )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CWindowId * value
        );
    HRESULT ( STDMETHODCALLTYPE *Connect )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CContent_CIContentIsland * content
        );
    HRESULT ( STDMETHODCALLTYPE *Disable )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This
        );
    HRESULT ( STDMETHODCALLTYPE *Enable )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This
        );
    HRESULT ( STDMETHODCALLTYPE *Hide )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This
        );
    HRESULT ( STDMETHODCALLTYPE *MoveAndResize )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
        /* [in] */__x_ABI_CWindows_CGraphics_CRectInt32 rect
        );
    HRESULT ( STDMETHODCALLTYPE *MoveInZOrderAtBottom )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This
        );
    HRESULT ( STDMETHODCALLTYPE *MoveInZOrderAtTop )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This
        );
    HRESULT ( STDMETHODCALLTYPE *MoveInZOrderBelow )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CWindowId windowId
        );
    HRESULT ( STDMETHODCALLTYPE *Show )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge * This
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_get_IsEnabled(This,value) \
    ( (This)->lpVtbl->get_IsEnabled(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_get_IsVisible(This,value) \
    ( (This)->lpVtbl->get_IsVisible(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_get_WindowId(This,value) \
    ( (This)->lpVtbl->get_WindowId(This,value) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_Connect(This,content) \
    ( (This)->lpVtbl->Connect(This,content) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_Disable(This) \
    ( (This)->lpVtbl->Disable(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_Enable(This) \
    ( (This)->lpVtbl->Enable(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_Hide(This) \
    ( (This)->lpVtbl->Hide(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_MoveAndResize(This,rect) \
    ( (This)->lpVtbl->MoveAndResize(This,rect) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_MoveInZOrderAtBottom(This) \
    ( (This)->lpVtbl->MoveInZOrderAtBottom(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_MoveInZOrderAtTop(This) \
    ( (This)->lpVtbl->MoveInZOrderAtTop(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_MoveInZOrderBelow(This,windowId) \
    ( (This)->lpVtbl->MoveInZOrderBelow(This,windowId) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_Show(This) \
    ( (This)->lpVtbl->Show(This) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridge_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopSiteBridgeFactory
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopSiteBridgeFactory[] = L"Microsoft.UI.Content.IDesktopSiteBridgeFactory";
/* [object, uuid("D94EE1FF-3AF1-54D0-9311-652B29C57C5B"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactoryVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.Content.IDesktopSiteBridgeStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.Content.DesktopSiteBridge
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IDesktopSiteBridgeStatics[] = L"Microsoft.UI.Content.IDesktopSiteBridgeStatics";
/* [object, uuid("E0B38DAF-9CD4-50C5-83EE-C76E3CF34EBA"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *IsSupported )(
        __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics * This,
        /* [retval, out] */boolean * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStaticsVtbl;

interface __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_IsSupported(This,result) \
    ( (This)->lpVtbl->IsSupported(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CContent_CIDesktopSiteBridgeStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentCoordinateConverter
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Content.IContentCoordinateConverterStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentCoordinateConverter ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentCoordinateConverter_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentCoordinateConverter_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentCoordinateConverter[] = L"Microsoft.UI.Content.ContentCoordinateConverter";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentDeferral
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentDeferral ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentDeferral_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentDeferral_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentDeferral[] = L"Microsoft.UI.Content.ContentDeferral";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentEnvironmentSettingChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentEnvironmentSettingChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentEnvironmentSettingChangedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentEnvironmentSettingChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentEnvironmentSettingChangedEventArgs[] = L"Microsoft.UI.Content.ContentEnvironmentSettingChangedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentEnvironmentStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentEnvironmentStateChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentEnvironmentStateChangedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentEnvironmentStateChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentEnvironmentStateChangedEventArgs[] = L"Microsoft.UI.Content.ContentEnvironmentStateChangedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentIsland
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Content.IContentIslandStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentIsland ** Default Interface **
 *    Windows.Foundation.IClosable
 *    Microsoft.UI.IClosableNotifier
 *    Microsoft.UI.Composition.ICompositionSupportsSystemBackdrop
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentIsland_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentIsland_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentIsland[] = L"Microsoft.UI.Content.ContentIsland";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentIslandAutomationProviderRequestedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentIslandAutomationProviderRequestedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentIslandAutomationProviderRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentIslandAutomationProviderRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentIslandAutomationProviderRequestedEventArgs[] = L"Microsoft.UI.Content.ContentIslandAutomationProviderRequestedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentIslandEnvironment
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentIslandEnvironment ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentIslandEnvironment_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentIslandEnvironment_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentIslandEnvironment[] = L"Microsoft.UI.Content.ContentIslandEnvironment";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentIslandStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentIslandStateChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentIslandStateChangedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentIslandStateChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentIslandStateChangedEventArgs[] = L"Microsoft.UI.Content.ContentIslandStateChangedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSite
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSite ** Default Interface **
 *    Windows.Foundation.IClosable
 *    Microsoft.UI.IClosableNotifier
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSite_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSite_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSite[] = L"Microsoft.UI.Content.ContentSite";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSiteEnvironment
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSiteEnvironment ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSiteEnvironment_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSiteEnvironment_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSiteEnvironment[] = L"Microsoft.UI.Content.ContentSiteEnvironment";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSiteEnvironmentView
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSiteEnvironmentView ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSiteEnvironmentView_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSiteEnvironmentView_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSiteEnvironmentView[] = L"Microsoft.UI.Content.ContentSiteEnvironmentView";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSiteRequestedStateChangedEventArgs
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSiteRequestedStateChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSiteRequestedStateChangedEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSiteRequestedStateChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSiteRequestedStateChangedEventArgs[] = L"Microsoft.UI.Content.ContentSiteRequestedStateChangedEventArgs";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.ContentSiteView
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IContentSiteView ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_ContentSiteView_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_ContentSiteView_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_ContentSiteView[] = L"Microsoft.UI.Content.ContentSiteView";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.DesktopChildSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Content.IDesktopChildSiteBridgeStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IDesktopChildSiteBridge ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_DesktopChildSiteBridge_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_DesktopChildSiteBridge_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_DesktopChildSiteBridge[] = L"Microsoft.UI.Content.DesktopChildSiteBridge";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.Content.DesktopSiteBridge
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.Content.IDesktopSiteBridgeStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.Content.IDesktopSiteBridge ** Default Interface **
 *    Microsoft.UI.IClosableNotifier
 *    Microsoft.UI.Content.IContentSiteBridge
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_Content_DesktopSiteBridge_DEFINED
#define RUNTIMECLASS_Microsoft_UI_Content_DesktopSiteBridge_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_Content_DesktopSiteBridge[] = L"Microsoft.UI.Content.DesktopSiteBridge";
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
#endif // __microsoft2Eui2Econtent_p_h__

#endif // __microsoft2Eui2Econtent_h__

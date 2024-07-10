
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
#ifndef __microsoft2Ewindows2Ewidgets2Efeeds2Eproviders_h__
#define __microsoft2Ewindows2Ewidgets2Efeeds2Eproviders_h__
#ifndef __microsoft2Ewindows2Ewidgets2Efeeds2Eproviders_p_h__
#define __microsoft2Ewindows2Ewidgets2Efeeds2Eproviders_p_h__


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
#if !defined(MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION)
#define MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION 0x50000
#endif // defined(MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION)

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
#include "Microsoft.Windows.Widgets.h"
#include "Microsoft.Windows.Widgets.Notifications.h"
#include "Windows.Storage.Streams.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface ICustomQueryParametersRequestedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::ICustomQueryParametersRequestedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface ICustomQueryParametersUpdateOptions;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions ABI::Microsoft::Windows::Widgets::Feeds::Providers::ICustomQueryParametersUpdateOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface ICustomQueryParametersUpdateOptionsFactory;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory ABI::Microsoft::Windows::Widgets::Feeds::Providers::ICustomQueryParametersUpdateOptionsFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedAnalyticsInfoReportedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedAnalyticsInfoReportedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedAnnouncementInvokedTarget;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedAnnouncementInvokedTarget

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedDisabledArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedDisabledArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedEnabledArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedEnabledArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedErrorInfoReportedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedErrorInfoReportedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedManager;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedManager

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedManager2;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedManager2

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedManagerStatics;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedManagerStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedMessageReceivedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedMessageReceivedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedProvider;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProvider

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedProviderAnalytics;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderAnalytics

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedProviderDisabledArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderDisabledArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedProviderEnabledArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderEnabledArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedProviderErrors;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderErrors

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedProviderInfo;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderInfo

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedProviderMessage;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderMessage

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedResourceProvider;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceProvider

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedResourceRequest;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceRequest

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedResourceRequestedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceRequestedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedResourceResponse;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceResponse

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        interface IFeedResourceResponseFactory;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceResponseFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions

#ifndef DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("60310303-49c5-52e6-abc6-a9b36eccc716"))
IKeyValuePair<HSTRING,HSTRING> : IKeyValuePair_impl<HSTRING,HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IKeyValuePair`2<String, String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IKeyValuePair<HSTRING,HSTRING> __FIKeyValuePair_2_HSTRING_HSTRING_t;
#define __FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIKeyValuePair_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING,HSTRING>
//#define __FIKeyValuePair_2_HSTRING_HSTRING_t ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING,HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE */





#ifndef DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("05eb86f1-7140-5517-b88d-cbaebe57e6b1"))
IIterator<__FIKeyValuePair_2_HSTRING_HSTRING*> : IIterator_impl<__FIKeyValuePair_2_HSTRING_HSTRING*> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String, String>>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<__FIKeyValuePair_2_HSTRING_HSTRING*> __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_t;
#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::IIterator<ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING,HSTRING>*>
//#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_t ABI::Windows::Foundation::Collections::IIterator<ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING,HSTRING>*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE */





#ifndef DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e9bdaaf0-cbf6-5c72-be90-29cbf3a1319b"))
IIterable<__FIKeyValuePair_2_HSTRING_HSTRING*> : IIterable_impl<__FIKeyValuePair_2_HSTRING_HSTRING*> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IKeyValuePair`2<String, String>>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<__FIKeyValuePair_2_HSTRING_HSTRING*> __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_t;
#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING,HSTRING>*>
//#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_t ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING,HSTRING>*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE */




#ifndef DEF___FIMapView_2_HSTRING_HSTRING_USE
#define DEF___FIMapView_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("ac7f26f2-feb7-5b2a-8ac4-345bc62caede"))
IMapView<HSTRING,HSTRING> : IMapView_impl<HSTRING,HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IMapView`2<String, String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMapView<HSTRING,HSTRING> __FIMapView_2_HSTRING_HSTRING_t;
#define __FIMapView_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIMapView_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIMapView_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::IMapView<HSTRING,HSTRING>
//#define __FIMapView_2_HSTRING_HSTRING_t ABI::Windows::Foundation::Collections::IMapView<HSTRING,HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMapView_2_HSTRING_HSTRING_USE */




#ifndef DEF___FIMap_2_HSTRING_HSTRING_USE
#define DEF___FIMap_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f6d1f700-49c2-52ae-8154-826f9908773c"))
IMap<HSTRING,HSTRING> : IMap_impl<HSTRING,HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IMap`2<String, String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMap<HSTRING,HSTRING> __FIMap_2_HSTRING_HSTRING_t;
#define __FIMap_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIMap_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIMap_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::IMap<HSTRING,HSTRING>
//#define __FIMap_2_HSTRING_HSTRING_t ABI::Windows::Foundation::Collections::IMap<HSTRING,HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMap_2_HSTRING_HSTRING_USE */




#ifndef DEF___FIMapChangedEventArgs_1_HSTRING_USE
#define DEF___FIMapChangedEventArgs_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("60141efb-f2f9-5377-96fd-f8c60d9558b5"))
IMapChangedEventArgs<HSTRING> : IMapChangedEventArgs_impl<HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IMapChangedEventArgs`1<String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMapChangedEventArgs<HSTRING> __FIMapChangedEventArgs_1_HSTRING_t;
#define __FIMapChangedEventArgs_1_HSTRING ABI::Windows::Foundation::Collections::__FIMapChangedEventArgs_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIMapChangedEventArgs_1_HSTRING ABI::Windows::Foundation::Collections::IMapChangedEventArgs<HSTRING>
//#define __FIMapChangedEventArgs_1_HSTRING_t ABI::Windows::Foundation::Collections::IMapChangedEventArgs<HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMapChangedEventArgs_1_HSTRING_USE */




#ifndef DEF___FMapChangedEventHandler_2_HSTRING_HSTRING_USE
#define DEF___FMapChangedEventHandler_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e2663f37-2e1b-500c-ad68-c3ed7a8f74c8"))
MapChangedEventHandler<HSTRING,HSTRING> : MapChangedEventHandler_impl<HSTRING,HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.MapChangedEventHandler`2<String, String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef MapChangedEventHandler<HSTRING,HSTRING> __FMapChangedEventHandler_2_HSTRING_HSTRING_t;
#define __FMapChangedEventHandler_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FMapChangedEventHandler_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FMapChangedEventHandler_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::MapChangedEventHandler<HSTRING,HSTRING>
//#define __FMapChangedEventHandler_2_HSTRING_HSTRING_t ABI::Windows::Foundation::Collections::MapChangedEventHandler<HSTRING,HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FMapChangedEventHandler_2_HSTRING_HSTRING_USE */




#ifndef DEF___FIObservableMap_2_HSTRING_HSTRING_USE
#define DEF___FIObservableMap_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("1e036276-2f60-55f6-b7f3-f86079e6900b"))
IObservableMap<HSTRING,HSTRING> : IObservableMap_impl<HSTRING,HSTRING> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IObservableMap`2<String, String>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IObservableMap<HSTRING,HSTRING> __FIObservableMap_2_HSTRING_HSTRING_t;
#define __FIObservableMap_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIObservableMap_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIObservableMap_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::IObservableMap<HSTRING,HSTRING>
//#define __FIObservableMap_2_HSTRING_HSTRING_t ABI::Windows::Foundation::Collections::IObservableMap<HSTRING,HSTRING>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIObservableMap_2_HSTRING_HSTRING_USE */





namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    class FeedAnnouncement;
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    interface IFeedAnnouncement;
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement ABI::Microsoft::Windows::Widgets::Notifications::IFeedAnnouncement

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    class FeedAnnouncementInvokedArgs;
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    interface IFeedAnnouncementInvokedArgs;
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs ABI::Microsoft::Windows::Widgets::Notifications::IFeedAnnouncementInvokedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__










namespace ABI {
    namespace Windows {
        namespace Foundation {
            namespace Collections {
                class StringMap;
            } /* Collections */
        } /* Foundation */
    } /* Windows */
} /* ABI */





namespace ABI {
    namespace Windows {
        namespace Foundation {
            class Deferral;
        } /* Foundation */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IDeferral;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIDeferral ABI::Windows::Foundation::IDeferral

#endif // ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__




#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Streams {
                interface IRandomAccessStreamReference;
            } /* Streams */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference ABI::Windows::Storage::Streams::IRandomAccessStreamReference

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference_FWD_DEFINED__





























namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class CustomQueryParametersRequestedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class CustomQueryParametersUpdateOptions;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedAnalyticsInfoReportedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedDisabledArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedEnabledArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedErrorInfoReportedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedManager;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedMessageReceivedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedProviderDisabledArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedProviderEnabledArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedProviderInfo;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedResourceRequest;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedResourceRequestedArgs;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        class FeedResourceResponse;
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */








/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersRequestedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_ICustomQueryParametersRequestedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersRequestedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("DC2B0CD8-7936-5346-9371-B21484C7D859"), exclusiveto, contract] */
                        MIDL_INTERFACE("DC2B0CD8-7936-5346-9371-B21484C7D859")
                        ICustomQueryParametersRequestedArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_ICustomQueryParametersRequestedArgs=_uuidof(ICustomQueryParametersRequestedArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptions
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersUpdateOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_ICustomQueryParametersUpdateOptions[] = L"Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("753F1177-4909-568A-B070-98A3139205EC"), exclusiveto, contract] */
                        MIDL_INTERFACE("753F1177-4909-568A-B070-98A3139205EC")
                        ICustomQueryParametersUpdateOptions : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CustomQueryParameters(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_ICustomQueryParametersUpdateOptions=_uuidof(ICustomQueryParametersUpdateOptions);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptionsFactory
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersUpdateOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_ICustomQueryParametersUpdateOptionsFactory[] = L"Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptionsFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("34E318CD-3884-53C0-911C-225F32228FAE"), exclusiveto, contract] */
                        MIDL_INTERFACE("34E318CD-3884-53C0-911C-225F32228FAE")
                        ICustomQueryParametersUpdateOptionsFactory : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                                /* [in] */HSTRING feedProviderDefinitionId,
                                /* [in] */HSTRING customQueryParameters,
                                /* [retval, out] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::ICustomQueryParametersUpdateOptions * * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_ICustomQueryParametersUpdateOptionsFactory=_uuidof(ICustomQueryParametersUpdateOptionsFactory);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnalyticsInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedAnalyticsInfoReportedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedAnalyticsInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnalyticsInfoReportedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("3C0E3D65-ED47-5B8A-B650-39A7EDF18942"), exclusiveto, contract] */
                        MIDL_INTERFACE("3C0E3D65-ED47-5B8A-B650-39A7EDF18942")
                        IFeedAnalyticsInfoReportedArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AnalyticsJson(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedAnalyticsInfoReportedArgs=_uuidof(IFeedAnalyticsInfoReportedArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnnouncementInvokedTarget
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedAnnouncementInvokedTarget[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnnouncementInvokedTarget";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("5D44AE2A-072C-4DF9-9FE5-34D5D2E9FF63"), contract] */
                        MIDL_INTERFACE("5D44AE2A-072C-4DF9-9FE5-34D5D2E9FF63")
                        IFeedAnnouncementInvokedTarget : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE OnAnnouncementInvoked(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Notifications::IFeedAnnouncementInvokedArgs * args
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedAnnouncementInvokedTarget=_uuidof(IFeedAnnouncementInvokedTarget);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedDisabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedDisabledArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedDisabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedDisabledArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("95300612-ACA7-53C0-9CF6-D803689132C1"), exclusiveto, contract] */
                        MIDL_INTERFACE("95300612-ACA7-53C0-9CF6-D803689132C1")
                        IFeedDisabledArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedDisabledArgs=_uuidof(IFeedDisabledArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedEnabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedEnabledArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedEnabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedEnabledArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("EFF4B2D7-7347-5969-A77D-CAC433F0FDAE"), exclusiveto, contract] */
                        MIDL_INTERFACE("EFF4B2D7-7347-5969-A77D-CAC433F0FDAE")
                        IFeedEnabledArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedEnabledArgs=_uuidof(IFeedEnabledArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedErrorInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedErrorInfoReportedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedErrorInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedErrorInfoReportedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("62DE018C-161E-52D0-9DBE-AEC106FB6600"), exclusiveto, contract] */
                        MIDL_INTERFACE("62DE018C-161E-52D0-9DBE-AEC106FB6600")
                        IFeedErrorInfoReportedArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ErrorJson(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedErrorInfoReportedArgs=_uuidof(IFeedErrorInfoReportedArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedManager[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("87DF6A84-15AA-45CB-8911-5CAFAB57F723"), contract] */
                        MIDL_INTERFACE("87DF6A84-15AA-45CB-8911-5CAFAB57F723")
                        IFeedManager : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE GetEnabledFeedProviders(
                                /* [out] */UINT32 * __resultSize,
                                /* [size_is(, *(__resultSize)), retval, out] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderInfo * * * result
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE SetCustomQueryParameters(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::ICustomQueryParametersUpdateOptions * options
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedManager=_uuidof(IFeedManager);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager2
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedManager2[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("5838300A-A069-455D-9943-BA078ADA00D8"), contract] */
                        MIDL_INTERFACE("5838300A-A069-455D-9943-BA078ADA00D8")
                        IFeedManager2 : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE SendMessageToContent(
                                /* [in] */HSTRING feedProviderDefinitionId,
                                /* [in] */HSTRING feedDefinitionId,
                                /* [in] */HSTRING message
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE TryShowAnnouncement(
                                /* [in] */HSTRING feedProviderDefinitionId,
                                /* [in] */HSTRING feedDefinitionId,
                                /* [in] */ABI::Microsoft::Windows::Widgets::Notifications::IFeedAnnouncement * announcement
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedManager2=_uuidof(IFeedManager2);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedManagerStatics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedManager
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedManagerStatics[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedManagerStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("4BAF5174-77D6-5E2A-94EA-4F14CCDB1F2C"), exclusiveto, contract] */
                        MIDL_INTERFACE("4BAF5174-77D6-5E2A-94EA-4F14CCDB1F2C")
                        IFeedManagerStatics : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE GetDefault(
                                /* [retval, out] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedManager * * result
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedManagerStatics=_uuidof(IFeedManagerStatics);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedMessageReceivedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedMessageReceivedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedMessageReceivedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedMessageReceivedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("4ED6ECF9-4C74-5A0B-AE04-BEF6DD776F8A"), exclusiveto, contract] */
                        MIDL_INTERFACE("4ED6ECF9-4C74-5A0B-AE04-BEF6DD776F8A")
                        IFeedMessageReceivedArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Message(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedMessageReceivedArgs=_uuidof(IFeedMessageReceivedArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProvider
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProvider[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProvider";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("7293A12B-0329-458D-AC25-5332BE478FDE"), contract] */
                        MIDL_INTERFACE("7293A12B-0329-458D-AC25-5332BE478FDE")
                        IFeedProvider : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE OnFeedProviderEnabled(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderEnabledArgs * args
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE OnFeedProviderDisabled(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedProviderDisabledArgs * args
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE OnFeedEnabled(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedEnabledArgs * args
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE OnFeedDisabled(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedDisabledArgs * args
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE OnCustomQueryParametersRequested(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::ICustomQueryParametersRequestedArgs * args
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedProvider=_uuidof(IFeedProvider);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderAnalytics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderAnalytics[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderAnalytics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("F6885791-3085-4BD7-9CB1-4F1354C3A687"), contract] */
                        MIDL_INTERFACE("F6885791-3085-4BD7-9CB1-4F1354C3A687")
                        IFeedProviderAnalytics : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE OnAnalyticsInfoReported(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedAnalyticsInfoReportedArgs * args
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedProviderAnalytics=_uuidof(IFeedProviderAnalytics);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderDisabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderDisabledArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderDisabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderDisabledArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("19B65AEC-E01D-5E8C-AB5F-324212E7CD30"), exclusiveto, contract] */
                        MIDL_INTERFACE("19B65AEC-E01D-5E8C-AB5F-324212E7CD30")
                        IFeedProviderDisabledArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedProviderDisabledArgs=_uuidof(IFeedProviderDisabledArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderEnabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderEnabledArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderEnabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderEnabledArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("821FC9AF-0DE6-5A9B-9AE6-E179117B40E4"), exclusiveto, contract] */
                        MIDL_INTERFACE("821FC9AF-0DE6-5A9B-9AE6-E179117B40E4")
                        IFeedProviderEnabledArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedProviderEnabledArgs=_uuidof(IFeedProviderEnabledArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderErrors
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderErrors[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderErrors";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("6611E00A-D86C-49A3-9381-B7DA67EE62DC"), contract] */
                        MIDL_INTERFACE("6611E00A-D86C-49A3-9381-B7DA67EE62DC")
                        IFeedProviderErrors : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE OnErrorInfoReported(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedErrorInfoReportedArgs * args
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedProviderErrors=_uuidof(IFeedProviderErrors);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderInfo
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderInfo
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderInfo[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderInfo";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("73C37049-3C03-5896-8532-F9DFDAEB723F"), exclusiveto, contract] */
                        MIDL_INTERFACE("73C37049-3C03-5896-8532-F9DFDAEB723F")
                        IFeedProviderInfo : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_EnabledFeedDefinitionIds(
                                /* [out] */UINT32 * __valueSize,
                                /* [size_is(, *(__valueSize)), retval, out] */HSTRING * * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedProviderInfo=_uuidof(IFeedProviderInfo);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderMessage
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderMessage[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderMessage";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("60C2442A-4C9D-4880-BA26-CACA9E567DD4"), contract] */
                        MIDL_INTERFACE("60C2442A-4C9D-4880-BA26-CACA9E567DD4")
                        IFeedProviderMessage : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE OnMessageReceived(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedMessageReceivedArgs * args
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedProviderMessage=_uuidof(IFeedProviderMessage);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceProvider
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceProvider[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceProvider";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("E1B6266D-88A0-416C-9440-E341CB047CD3"), contract] */
                        MIDL_INTERFACE("E1B6266D-88A0-416C-9440-E341CB047CD3")
                        IFeedResourceProvider : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE OnResourceRequested(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceRequestedArgs * args
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedResourceProvider=_uuidof(IFeedResourceProvider);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequest
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequest
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceRequest[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequest";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("E62E479C-E21F-5863-B4C9-DF1BE2227981"), exclusiveto, contract] */
                        MIDL_INTERFACE("E62E479C-E21F-5863-B4C9-DF1BE2227981")
                        IFeedResourceRequest : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Uri(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Method(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Method(
                                /* [in] */HSTRING value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Content(
                                /* [retval, out] */ABI::Windows::Storage::Streams::IRandomAccessStreamReference * * value
                                ) = 0;
                            /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Content(
                                /* [in] */ABI::Windows::Storage::Streams::IRandomAccessStreamReference * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Headers(
                                /* [retval, out] */__FIMap_2_HSTRING_HSTRING * * value
                                ) = 0;
                            /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Headers(
                                /* [in] */__FIMap_2_HSTRING_HSTRING * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedResourceRequest=_uuidof(IFeedResourceRequest);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequestedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceRequestedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequestedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("360EB709-0BC9-52C1-9C70-3C7D413173D8"), exclusiveto, contract] */
                        MIDL_INTERFACE("360EB709-0BC9-52C1-9C70-3C7D413173D8")
                        IFeedResourceRequestedArgs : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedDefinitionId(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Request(
                                /* [retval, out] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceRequest * * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Response(
                                /* [retval, out] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceResponse * * value
                                ) = 0;
                            /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Response(
                                /* [in] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceResponse * value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                                /* [retval, out] */ABI::Windows::Foundation::IDeferral * * result
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedResourceRequestedArgs=_uuidof(IFeedResourceRequestedArgs);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponse
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceResponse
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceResponse[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponse";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("F831824E-7AEF-53FC-B7EE-32ADE675A3AD"), exclusiveto, contract] */
                        MIDL_INTERFACE("F831824E-7AEF-53FC-B7EE-32ADE675A3AD")
                        IFeedResourceResponse : public IInspectable
                        {
                        public:
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Content(
                                /* [retval, out] */ABI::Windows::Storage::Streams::IRandomAccessStreamReference * * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Headers(
                                /* [retval, out] */__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * * value
                                ) = 0;
                            /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Headers(
                                /* [in] */__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ReasonPhrase(
                                /* [retval, out] */HSTRING * value
                                ) = 0;
                            /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_StatusCode(
                                /* [retval, out] */INT32 * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedResourceResponse=_uuidof(IFeedResourceResponse);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponseFactory
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceResponse
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceResponseFactory[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponseFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Feeds {
                    namespace Providers {
                        /* [object, uuid("DB01690D-2547-5D7A-B625-D1629F443C5C"), exclusiveto, contract] */
                        MIDL_INTERFACE("DB01690D-2547-5D7A-B625-D1629F443C5C")
                        IFeedResourceResponseFactory : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                                /* [in] */ABI::Windows::Storage::Streams::IRandomAccessStreamReference * content,
                                /* [in] */HSTRING reasonPhrase,
                                /* [in] */INT32 statusCode,
                                /* [retval, out] */ABI::Microsoft::Windows::Widgets::Feeds::Providers::IFeedResourceResponse * * value
                                ) = 0;
                            
                        };

                        MIDL_CONST_ID IID & IID_IFeedResourceResponseFactory=_uuidof(IFeedResourceResponseFactory);
                        
                    } /* Providers */
                } /* Feeds */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersRequestedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersRequestedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersRequestedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersRequestedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersRequestedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersUpdateOptions
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptionsFactory interface starting with version 4.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersUpdateOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersUpdateOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersUpdateOptions[] = L"Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersUpdateOptions";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedAnalyticsInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnalyticsInfoReportedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedAnalyticsInfoReportedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedAnalyticsInfoReportedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedAnalyticsInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedAnalyticsInfoReportedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedDisabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedDisabledArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedDisabledArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedDisabledArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedDisabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedDisabledArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedEnabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedEnabledArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedEnabledArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedEnabledArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedEnabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedEnabledArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedErrorInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedErrorInfoReportedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedErrorInfoReportedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedErrorInfoReportedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedErrorInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedErrorInfoReportedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedManager
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Widgets.Feeds.Providers.IFeedManagerStatics interface starting with version 4.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager ** Default Interface **
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedManager[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedManager";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedMessageReceivedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedMessageReceivedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedMessageReceivedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedMessageReceivedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedMessageReceivedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedMessageReceivedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderDisabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderDisabledArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderDisabledArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderDisabledArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderDisabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderDisabledArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderEnabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderEnabledArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderEnabledArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderEnabledArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderEnabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderEnabledArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderInfo
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderInfo_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderInfo[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderInfo";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequest
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequest ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequest_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequest_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequest[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequest";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequestedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequestedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequestedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequestedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequestedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceResponse
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponseFactory interface starting with version 5.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponse ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceResponse_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceResponse_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceResponse[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceResponse";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000






#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions
#if !defined(____FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIKeyValuePair_2_HSTRING_HSTRING __FIKeyValuePair_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIKeyValuePair_2_HSTRING_HSTRING;

typedef struct __FIKeyValuePair_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIKeyValuePair_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIKeyValuePair_2_HSTRING_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIKeyValuePair_2_HSTRING_HSTRING * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIKeyValuePair_2_HSTRING_HSTRING * This,
            /* [out] */ __RPC__out ULONG *iidCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIKeyValuePair_2_HSTRING_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIKeyValuePair_2_HSTRING_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )(__RPC__in __FIKeyValuePair_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__out HSTRING *key);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )(__RPC__in __FIKeyValuePair_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__deref_out_opt HSTRING *value);
    END_INTERFACE
} __FIKeyValuePair_2_HSTRING_HSTRINGVtbl;

interface __FIKeyValuePair_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIKeyValuePair_2_HSTRING_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIKeyValuePair_2_HSTRING_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIKeyValuePair_2_HSTRING_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIKeyValuePair_2_HSTRING_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIKeyValuePair_2_HSTRING_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIKeyValuePair_2_HSTRING_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIKeyValuePair_2_HSTRING_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIKeyValuePair_2_HSTRING_HSTRING_get_Key(This,key)	\
    ( (This)->lpVtbl -> get_Key(This,key) ) 

#define __FIKeyValuePair_2_HSTRING_HSTRING_get_Value(This,value)	\
    ( (This)->lpVtbl -> get_Value(This,value) ) 
#endif /* COBJMACROS */


#endif // ____FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__



#if !defined(____FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING;

typedef struct __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__out __FIKeyValuePair_2_HSTRING_HSTRING * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __FIKeyValuePair_2_HSTRING_HSTRING * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl;

interface __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__



#if !defined(____FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING;

typedef  struct __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING **first);

    END_INTERFACE
} __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl;

interface __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__


#if !defined(____FIMapView_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIMapView_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIMapView_2_HSTRING_HSTRING __FIMapView_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMapView_2_HSTRING_HSTRING;

typedef struct __FIMapView_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This,/* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *Lookup )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in HSTRING key,
        /* [retval][out] */ __RPC__deref_out_opt HSTRING *value);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__out unsigned int *size);
    HRESULT ( STDMETHODCALLTYPE *HasKey )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This, /* [in] */ __RPC__in HSTRING key, /* [retval][out] */ __RPC__out boolean *found);
    HRESULT ( STDMETHODCALLTYPE *Split )(__RPC__in __FIMapView_2_HSTRING_HSTRING * This,/* [out] */ __RPC__deref_out_opt __FIMapView_2_HSTRING_HSTRING **firstPartition,
        /* [out] */ __RPC__deref_out_opt __FIMapView_2_HSTRING_HSTRING **secondPartition);
    END_INTERFACE
} __FIMapView_2_HSTRING_HSTRINGVtbl;

interface __FIMapView_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIMapView_2_HSTRING_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIMapView_2_HSTRING_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIMapView_2_HSTRING_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIMapView_2_HSTRING_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIMapView_2_HSTRING_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 
#define __FIMapView_2_HSTRING_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 
#define __FIMapView_2_HSTRING_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 

#define __FIMapView_2_HSTRING_HSTRING_Lookup(This,key,value)	\
    ( (This)->lpVtbl -> Lookup(This,key,value) ) 
#define __FIMapView_2_HSTRING_HSTRING_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 
#define __FIMapView_2_HSTRING_HSTRING_HasKey(This,key,found)	\
    ( (This)->lpVtbl -> HasKey(This,key,found) ) 
#define __FIMapView_2_HSTRING_HSTRING_Split(This,firstPartition,secondPartition)	\
    ( (This)->lpVtbl -> Split(This,firstPartition,secondPartition) ) 
#endif /* COBJMACROS */


#endif // ____FIMapView_2_HSTRING_HSTRING_INTERFACE_DEFINED__


#if !defined(____FIMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIMap_2_HSTRING_HSTRING __FIMap_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMap_2_HSTRING_HSTRING;

typedef struct __FIMap_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIMap_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIMap_2_HSTRING_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIMap_2_HSTRING_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIMap_2_HSTRING_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIMap_2_HSTRING_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIMap_2_HSTRING_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *Lookup )(__RPC__in __FIMap_2_HSTRING_HSTRING * This,
        /* [in] */ HSTRING key,
        /* [retval][out] */ __RPC__deref_out_opt HSTRING **value);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )(__RPC__in __FIMap_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__out unsigned int *size);
    HRESULT ( STDMETHODCALLTYPE *HasKey )(__RPC__in __FIMap_2_HSTRING_HSTRING * This, /* [in] */ HSTRING key, /* [retval][out] */ __RPC__out boolean *found);
    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIMap_2_HSTRING_HSTRING * This, /* [retval][out] */ __RPC__deref_out_opt __FIMapView_2_HSTRING_HSTRING **view);
    HRESULT ( STDMETHODCALLTYPE *Insert )(__RPC__in __FIMap_2_HSTRING_HSTRING * This,
        /* [in] */ HSTRING key,
        /* [in] */ __RPC__in_opt HSTRING *value,
        /* [retval][out] */ __RPC__out boolean *replaced);
    HRESULT ( STDMETHODCALLTYPE *Remove )(__RPC__in __FIMap_2_HSTRING_HSTRING * This,/* [in] */ HSTRING key);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIMap_2_HSTRING_HSTRING * This);
    END_INTERFACE
} __FIMap_2_HSTRING_HSTRINGVtbl;

interface __FIMap_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIMap_2_HSTRING_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIMap_2_HSTRING_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIMap_2_HSTRING_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIMap_2_HSTRING_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIMap_2_HSTRING_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIMap_2_HSTRING_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIMap_2_HSTRING_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIMap_2_HSTRING_HSTRING_Lookup(This,key,value)	\
    ( (This)->lpVtbl -> Lookup(This,key,value) ) 

#define __FIMap_2_HSTRING_HSTRING_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIMap_2_HSTRING_HSTRING_HasKey(This,key,found)	\
    ( (This)->lpVtbl -> HasKey(This,key,found) ) 

#define __FIMap_2_HSTRING_HSTRING_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIMap_2_HSTRING_HSTRING_Insert(This,key,value,replaced)	\
    ( (This)->lpVtbl -> Insert(This,key,value,replaced) ) 

#define __FIMap_2_HSTRING_HSTRING_Remove(This,key)	\
    ( (This)->lpVtbl -> Remove(This,key) ) 

#define __FIMap_2_HSTRING_HSTRING_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 
#endif /* COBJMACROS */



#endif // ____FIMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__


#if !defined(____FIMapChangedEventArgs_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIMapChangedEventArgs_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIMapChangedEventArgs_1_HSTRING __FIMapChangedEventArgs_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMapChangedEventArgs_1_HSTRING;

typedef struct __FIMapChangedEventArgs_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIMapChangedEventArgs_1_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIMapChangedEventArgs_1_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIMapChangedEventArgs_1_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIMapChangedEventArgs_1_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIMapChangedEventArgs_1_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIMapChangedEventArgs_1_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CollectionChange )(__RPC__in __FIMapChangedEventArgs_1_HSTRING * This, /* [out] */ __RPC__out __x_ABI_CWindows_CFoundation_CCollections_CCollectionChange *value);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )(__RPC__in __FIMapChangedEventArgs_1_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *value);
    END_INTERFACE
} __FIMapChangedEventArgs_1_HSTRINGVtbl;

interface __FIMapChangedEventArgs_1_HSTRING
{
    CONST_VTBL struct __FIMapChangedEventArgs_1_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIMapChangedEventArgs_1_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIMapChangedEventArgs_1_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIMapChangedEventArgs_1_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIMapChangedEventArgs_1_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 
#define __FIMapChangedEventArgs_1_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 
#define __FIMapChangedEventArgs_1_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 

#define __FIMapChangedEventArgs_1_HSTRING_get_CollectionChange(This,value)	\
    ( (This)->lpVtbl -> get_CollectionChange(This,value) ) 
#define __FIMapChangedEventArgs_1_HSTRING_get_Key(This,value)	\
    ( (This)->lpVtbl -> get_Key(This,value) ) 
#endif /* COBJMACROS */


#endif // ____FIMapChangedEventArgs_1_HSTRING_INTERFACE_DEFINED__


#if !defined(____FMapChangedEventHandler_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FMapChangedEventHandler_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FMapChangedEventHandler_2_HSTRING_HSTRING __FMapChangedEventHandler_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FMapChangedEventHandler_2_HSTRING_HSTRING;

//Forward declare IObservableMap and IMapChangedEventArgs
typedef interface __FIObservableMap_2_HSTRING_HSTRING __FIObservableMap_2_HSTRING_HSTRING;
typedef interface __FIMapChangedEventArgs_1_HSTRING __FIMapChangedEventArgs_1_HSTRING;

typedef struct __FMapChangedEventHandler_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FMapChangedEventHandler_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FMapChangedEventHandler_2_HSTRING_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FMapChangedEventHandler_2_HSTRING_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FMapChangedEventHandler_2_HSTRING_HSTRING * This, 
        /* [in] */ __RPC__in_opt __FIObservableMap_2_HSTRING_HSTRING *sender, 
        /* [in] */ __RPC__in_opt __FIMapChangedEventArgs_1_HSTRING *e);
    END_INTERFACE
} __FMapChangedEventHandler_2_HSTRING_HSTRINGVtbl;

interface __FMapChangedEventHandler_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FMapChangedEventHandler_2_HSTRING_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FMapChangedEventHandler_2_HSTRING_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FMapChangedEventHandler_2_HSTRING_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FMapChangedEventHandler_2_HSTRING_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FMapChangedEventHandler_2_HSTRING_HSTRING_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */


#endif // ____FMapChangedEventHandler_2_HSTRING_HSTRING_INTERFACE_DEFINED__


#if !defined(____FIObservableMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIObservableMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIObservableMap_2_HSTRING_HSTRING __FIObservableMap_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIObservableMap_2_HSTRING_HSTRING;

typedef struct __FIObservableMap_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIObservableMap_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIObservableMap_2_HSTRING_HSTRING * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIObservableMap_2_HSTRING_HSTRING * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIObservableMap_2_HSTRING_HSTRING * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIObservableMap_2_HSTRING_HSTRING * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIObservableMap_2_HSTRING_HSTRING * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *add_MapChanged )(__RPC__in __FIObservableMap_2_HSTRING_HSTRING * This,
        /* [in] */ __RPC__in_opt __FMapChangedEventHandler_2_HSTRING_HSTRING *handler,
        /* [retval][out] */ __RPC__out EventRegistrationToken *token);
    HRESULT ( STDMETHODCALLTYPE *remove_MapChanged )(__RPC__in __FIObservableMap_2_HSTRING_HSTRING * This,
        /* [in] */ EventRegistrationToken token);
    END_INTERFACE
} __FIObservableMap_2_HSTRING_HSTRINGVtbl;

interface __FIObservableMap_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIObservableMap_2_HSTRING_HSTRINGVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIObservableMap_2_HSTRING_HSTRING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 
#define __FIObservableMap_2_HSTRING_HSTRING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 
#define __FIObservableMap_2_HSTRING_HSTRING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define __FIObservableMap_2_HSTRING_HSTRING_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 
#define __FIObservableMap_2_HSTRING_HSTRING_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 
#define __FIObservableMap_2_HSTRING_HSTRING_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 

#define __FIObservableMap_2_HSTRING_HSTRING_add_MapChanged(This,handler,token)	\
    ( (This)->lpVtbl -> add_MapChanged(This,handler,token) ) 
#define __FIObservableMap_2_HSTRING_HSTRING_remove_MapChanged(This,token)	\
    ( (This)->lpVtbl -> remove_MapChanged(This,token) ) 
#endif /* COBJMACROS */



#endif // ____FIObservableMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__



#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__


#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__














#ifndef ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIDeferral __x_ABI_CWindows_CFoundation_CIDeferral;

#endif // ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__




#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference_FWD_DEFINED__

















































/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersRequestedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_ICustomQueryParametersRequestedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersRequestedArgs";
/* [object, uuid("DC2B0CD8-7936-5346-9371-B21484C7D859"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptions
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersUpdateOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_ICustomQueryParametersUpdateOptions[] = L"Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptions";
/* [object, uuid("753F1177-4909-568A-B070-98A3139205EC"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CustomQueryParameters )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_get_CustomQueryParameters(This,value) \
    ( (This)->lpVtbl->get_CustomQueryParameters(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptionsFactory
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersUpdateOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_ICustomQueryParametersUpdateOptionsFactory[] = L"Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptionsFactory";
/* [object, uuid("34E318CD-3884-53C0-911C-225F32228FAE"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory * This,
        /* [in] */HSTRING feedProviderDefinitionId,
        /* [in] */HSTRING customQueryParameters,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_CreateInstance(This,feedProviderDefinitionId,customQueryParameters,value) \
    ( (This)->lpVtbl->CreateInstance(This,feedProviderDefinitionId,customQueryParameters,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptionsFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnalyticsInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedAnalyticsInfoReportedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedAnalyticsInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnalyticsInfoReportedArgs";
/* [object, uuid("3C0E3D65-ED47-5B8A-B650-39A7EDF18942"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AnalyticsJson )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_get_FeedDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_get_AnalyticsJson(This,value) \
    ( (This)->lpVtbl->get_AnalyticsJson(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnnouncementInvokedTarget
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedAnnouncementInvokedTarget[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnnouncementInvokedTarget";
/* [object, uuid("5D44AE2A-072C-4DF9-9FE5-34D5D2E9FF63"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTargetVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnAnnouncementInvoked )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * args
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTargetVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTargetVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_OnAnnouncementInvoked(This,args) \
    ( (This)->lpVtbl->OnAnnouncementInvoked(This,args) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnnouncementInvokedTarget_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedDisabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedDisabledArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedDisabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedDisabledArgs";
/* [object, uuid("95300612-ACA7-53C0-9CF6-D803689132C1"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_get_FeedDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedDefinitionId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedEnabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedEnabledArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedEnabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedEnabledArgs";
/* [object, uuid("EFF4B2D7-7347-5969-A77D-CAC433F0FDAE"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_get_FeedDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedDefinitionId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedErrorInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedErrorInfoReportedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedErrorInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedErrorInfoReportedArgs";
/* [object, uuid("62DE018C-161E-52D0-9DBE-AEC106FB6600"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ErrorJson )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_get_FeedDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_get_ErrorJson(This,value) \
    ( (This)->lpVtbl->get_ErrorJson(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedManager[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager";
/* [object, uuid("87DF6A84-15AA-45CB-8911-5CAFAB57F723"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetEnabledFeedProviders )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * This,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetCustomQueryParameters )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersUpdateOptions * options
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_GetEnabledFeedProviders(This,__resultSize,result) \
    ( (This)->lpVtbl->GetEnabledFeedProviders(This,__resultSize,result) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_SetCustomQueryParameters(This,options) \
    ( (This)->lpVtbl->SetCustomQueryParameters(This,options) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager2
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedManager2[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager2";
/* [object, uuid("5838300A-A069-455D-9943-BA078ADA00D8"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *SendMessageToContent )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 * This,
        /* [in] */HSTRING feedProviderDefinitionId,
        /* [in] */HSTRING feedDefinitionId,
        /* [in] */HSTRING message
        );
    HRESULT ( STDMETHODCALLTYPE *TryShowAnnouncement )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2 * This,
        /* [in] */HSTRING feedProviderDefinitionId,
        /* [in] */HSTRING feedDefinitionId,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * announcement
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_SendMessageToContent(This,feedProviderDefinitionId,feedDefinitionId,message) \
    ( (This)->lpVtbl->SendMessageToContent(This,feedProviderDefinitionId,feedDefinitionId,message) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_TryShowAnnouncement(This,feedProviderDefinitionId,feedDefinitionId,announcement) \
    ( (This)->lpVtbl->TryShowAnnouncement(This,feedProviderDefinitionId,feedDefinitionId,announcement) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedManagerStatics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedManager
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedManagerStatics[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedManagerStatics";
/* [object, uuid("4BAF5174-77D6-5E2A-94EA-4F14CCDB1F2C"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetDefault )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManager * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_GetDefault(This,result) \
    ( (This)->lpVtbl->GetDefault(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedMessageReceivedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedMessageReceivedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedMessageReceivedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedMessageReceivedArgs";
/* [object, uuid("4ED6ECF9-4C74-5A0B-AE04-BEF6DD776F8A"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Message )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_get_FeedDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_get_Message(This,value) \
    ( (This)->lpVtbl->get_Message(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProvider
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProvider[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProvider";
/* [object, uuid("7293A12B-0329-458D-AC25-5332BE478FDE"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnFeedProviderEnabled )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs * args
        );
    HRESULT ( STDMETHODCALLTYPE *OnFeedProviderDisabled )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs * args
        );
    HRESULT ( STDMETHODCALLTYPE *OnFeedEnabled )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedEnabledArgs * args
        );
    HRESULT ( STDMETHODCALLTYPE *OnFeedDisabled )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedDisabledArgs * args
        );
    HRESULT ( STDMETHODCALLTYPE *OnCustomQueryParametersRequested )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CICustomQueryParametersRequestedArgs * args
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_OnFeedProviderEnabled(This,args) \
    ( (This)->lpVtbl->OnFeedProviderEnabled(This,args) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_OnFeedProviderDisabled(This,args) \
    ( (This)->lpVtbl->OnFeedProviderDisabled(This,args) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_OnFeedEnabled(This,args) \
    ( (This)->lpVtbl->OnFeedEnabled(This,args) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_OnFeedDisabled(This,args) \
    ( (This)->lpVtbl->OnFeedDisabled(This,args) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_OnCustomQueryParametersRequested(This,args) \
    ( (This)->lpVtbl->OnCustomQueryParametersRequested(This,args) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProvider_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderAnalytics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderAnalytics[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderAnalytics";
/* [object, uuid("F6885791-3085-4BD7-9CB1-4F1354C3A687"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalyticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnAnalyticsInfoReported )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedAnalyticsInfoReportedArgs * args
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalyticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalyticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_OnAnalyticsInfoReported(This,args) \
    ( (This)->lpVtbl->OnAnalyticsInfoReported(This,args) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderAnalytics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderDisabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderDisabledArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderDisabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderDisabledArgs";
/* [object, uuid("19B65AEC-E01D-5E8C-AB5F-324212E7CD30"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderDisabledArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderEnabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderEnabledArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderEnabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderEnabledArgs";
/* [object, uuid("821FC9AF-0DE6-5A9B-9AE6-E179117B40E4"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderEnabledArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderErrors
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderErrors[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderErrors";
/* [object, uuid("6611E00A-D86C-49A3-9381-B7DA67EE62DC"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrorsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnErrorInfoReported )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedErrorInfoReportedArgs * args
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrorsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrorsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_OnErrorInfoReported(This,args) \
    ( (This)->lpVtbl->OnErrorInfoReported(This,args) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderErrors_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderInfo
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderInfo
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderInfo[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderInfo";
/* [object, uuid("73C37049-3C03-5896-8532-F9DFDAEB723F"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfoVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_EnabledFeedDefinitionIds )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo * This,
        /* [out] */UINT32 * __valueSize,
        /* [size_is(, *(__valueSize)), retval, out] */HSTRING * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfoVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfoVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_get_EnabledFeedDefinitionIds(This,__valueSize,value) \
    ( (This)->lpVtbl->get_EnabledFeedDefinitionIds(This,__valueSize,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderInfo_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderMessage
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedProviderMessage[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderMessage";
/* [object, uuid("60C2442A-4C9D-4880-BA26-CACA9E567DD4"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessageVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnMessageReceived )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedMessageReceivedArgs * args
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessageVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessageVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_OnMessageReceived(This,args) \
    ( (This)->lpVtbl->OnMessageReceived(This,args) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedProviderMessage_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceProvider
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceProvider[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceProvider";
/* [object, uuid("E1B6266D-88A0-416C-9440-E341CB047CD3"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProviderVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnResourceRequested )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * args
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProviderVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProviderVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_OnResourceRequested(This,args) \
    ( (This)->lpVtbl->OnResourceRequested(This,args) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceProvider_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequest
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequest
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceRequest[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequest";
/* [object, uuid("E62E479C-E21F-5863-B4C9-DF1BE2227981"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Uri )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Method )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Method )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Content )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
        /* [retval, out] */__x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Content )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
        /* [in] */__x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Headers )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
        /* [retval, out] */__FIMap_2_HSTRING_HSTRING * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Headers )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * This,
        /* [in] */__FIMap_2_HSTRING_HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_get_Uri(This,value) \
    ( (This)->lpVtbl->get_Uri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_get_Method(This,value) \
    ( (This)->lpVtbl->get_Method(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_put_Method(This,value) \
    ( (This)->lpVtbl->put_Method(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_get_Content(This,value) \
    ( (This)->lpVtbl->get_Content(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_put_Content(This,value) \
    ( (This)->lpVtbl->put_Content(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_get_Headers(This,value) \
    ( (This)->lpVtbl->get_Headers(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_put_Headers(This,value) \
    ( (This)->lpVtbl->put_Headers(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequestedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceRequestedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequestedArgs";
/* [object, uuid("360EB709-0BC9-52C1-9C70-3C7D413173D8"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Request )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequest * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Response )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Response )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * value
        );
    HRESULT ( STDMETHODCALLTYPE *GetDeferral )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIDeferral * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_get_FeedDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_get_Request(This,value) \
    ( (This)->lpVtbl->get_Request(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_get_Response(This,value) \
    ( (This)->lpVtbl->get_Response(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_put_Response(This,value) \
    ( (This)->lpVtbl->put_Response(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_GetDeferral(This,result) \
    ( (This)->lpVtbl->GetDeferral(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceRequestedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponse
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceResponse
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceResponse[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponse";
/* [object, uuid("F831824E-7AEF-53FC-B7EE-32ADE675A3AD"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Content )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
        /* [retval, out] */__x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Headers )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
        /* [retval, out] */__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Headers )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
        /* [in] */__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ReasonPhrase )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_StatusCode )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * This,
        /* [retval, out] */INT32 * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_get_Content(This,value) \
    ( (This)->lpVtbl->get_Content(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_get_Headers(This,value) \
    ( (This)->lpVtbl->get_Headers(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_put_Headers(This,value) \
    ( (This)->lpVtbl->put_Headers(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_get_ReasonPhrase(This,value) \
    ( (This)->lpVtbl->get_ReasonPhrase(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_get_StatusCode(This,value) \
    ( (This)->lpVtbl->get_StatusCode(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponseFactory
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceResponse
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Feeds_Providers_IFeedResourceResponseFactory[] = L"Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponseFactory";
/* [object, uuid("DB01690D-2547-5D7A-B625-D1629F443C5C"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory * This,
        /* [in] */__x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamReference * content,
        /* [in] */HSTRING reasonPhrase,
        /* [in] */INT32 statusCode,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponse * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_CreateInstance(This,content,reasonPhrase,statusCode,value) \
    ( (This)->lpVtbl->CreateInstance(This,content,reasonPhrase,statusCode,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CFeeds_CProviders_CIFeedResourceResponseFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersRequestedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersRequestedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersRequestedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersRequestedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersRequestedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersUpdateOptions
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptionsFactory interface starting with version 4.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.ICustomQueryParametersUpdateOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersUpdateOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersUpdateOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_CustomQueryParametersUpdateOptions[] = L"Microsoft.Windows.Widgets.Feeds.Providers.CustomQueryParametersUpdateOptions";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedAnalyticsInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedAnalyticsInfoReportedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedAnalyticsInfoReportedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedAnalyticsInfoReportedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedAnalyticsInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedAnalyticsInfoReportedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedDisabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedDisabledArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedDisabledArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedDisabledArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedDisabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedDisabledArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedEnabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedEnabledArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedEnabledArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedEnabledArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedEnabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedEnabledArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedErrorInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedErrorInfoReportedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedErrorInfoReportedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedErrorInfoReportedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedErrorInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedErrorInfoReportedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedManager
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Widgets.Feeds.Providers.IFeedManagerStatics interface starting with version 4.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager ** Default Interface **
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedManager2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedManager[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedManager";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedMessageReceivedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedMessageReceivedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedMessageReceivedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedMessageReceivedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedMessageReceivedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedMessageReceivedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderDisabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderDisabledArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderDisabledArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderDisabledArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderDisabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderDisabledArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderEnabledArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderEnabledArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderEnabledArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderEnabledArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderEnabledArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderEnabledArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderInfo
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 4.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedProviderInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderInfo_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedProviderInfo[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedProviderInfo";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x40000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequest
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequest ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequest_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequest_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequest[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequest";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceRequestedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequestedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequestedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceRequestedArgs[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceRequestedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceResponse
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponseFactory interface starting with version 5.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Feeds.Providers.IFeedResourceResponse ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceResponse_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceResponse_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Feeds_Providers_FeedResourceResponse[] = L"Microsoft.Windows.Widgets.Feeds.Providers.FeedResourceResponse";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000






#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Ewidgets2Efeeds2Eproviders_p_h__

#endif // __microsoft2Ewindows2Ewidgets2Efeeds2Eproviders_h__

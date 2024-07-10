
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
#ifndef __microsoft2Ewindows2Ewidgets2Eproviders_h__
#define __microsoft2Ewindows2Ewidgets2Eproviders_h__
#ifndef __microsoft2Ewindows2Ewidgets2Eproviders_p_h__
#define __microsoft2Ewindows2Ewidgets2Eproviders_p_h__


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

#if !defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION 0x70000
#endif // defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xf0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#if !defined(WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION)
#define WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION 0x30000
#endif // defined(WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION)

#if !defined(WINDOWS_PHONE_PHONECONTRACT_VERSION)
#define WINDOWS_PHONE_PHONECONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_PHONE_PHONECONTRACT_VERSION)

#if !defined(WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION)
#define WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION)

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

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetActionInvokedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs ABI::Microsoft::Windows::Widgets::Providers::IWidgetActionInvokedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetAnalyticsInfoReportedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs ABI::Microsoft::Windows::Widgets::Providers::IWidgetAnalyticsInfoReportedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetContext;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetContextChangedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs ABI::Microsoft::Windows::Widgets::Providers::IWidgetContextChangedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetCustomizationRequestedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs ABI::Microsoft::Windows::Widgets::Providers::IWidgetCustomizationRequestedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetErrorInfoReportedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs ABI::Microsoft::Windows::Widgets::Providers::IWidgetErrorInfoReportedArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetInfo;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo ABI::Microsoft::Windows::Widgets::Providers::IWidgetInfo

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetManager;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager ABI::Microsoft::Windows::Widgets::Providers::IWidgetManager

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetManagerStatics;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics ABI::Microsoft::Windows::Widgets::Providers::IWidgetManagerStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetProvider;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider ABI::Microsoft::Windows::Widgets::Providers::IWidgetProvider

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetProvider2;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 ABI::Microsoft::Windows::Widgets::Providers::IWidgetProvider2

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetProviderAnalytics;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics ABI::Microsoft::Windows::Widgets::Providers::IWidgetProviderAnalytics

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetProviderErrors;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors ABI::Microsoft::Windows::Widgets::Providers::IWidgetProviderErrors

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetUpdateRequestOptions;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions ABI::Microsoft::Windows::Widgets::Providers::IWidgetUpdateRequestOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetUpdateRequestOptionsFactory;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory ABI::Microsoft::Windows::Widgets::Providers::IWidgetUpdateRequestOptionsFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    interface IWidgetUpdateRequestOptionsStatics;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics ABI::Microsoft::Windows::Widgets::Providers::IWidgetUpdateRequestOptionsStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_FWD_DEFINED__



namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                
                typedef enum WidgetSize : int WidgetSize;
                
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */




namespace ABI {
    namespace Windows {
        namespace Foundation {
            
            typedef struct DateTime DateTime;
            
        } /* Foundation */
    } /* Windows */
} /* ABI */



















namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetActionInvokedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetAnalyticsInfoReportedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetContext;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetContextChangedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetCustomizationRequestedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetErrorInfoReportedArgs;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetInfo;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetManager;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    class WidgetUpdateRequestOptions;
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */







/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetActionInvokedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetActionInvokedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetActionInvokedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetActionInvokedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("C593CC57-04B9-52CA-88AD-46FEA21EA340"), exclusiveto, contract] */
                    MIDL_INTERFACE("C593CC57-04B9-52CA-88AD-46FEA21EA340")
                    IWidgetActionInvokedArgs : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_WidgetContext(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Verb(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Data(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CustomState(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetActionInvokedArgs=_uuidof(IWidgetActionInvokedArgs);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetAnalyticsInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetAnalyticsInfoReportedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetAnalyticsInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetAnalyticsInfoReportedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("1D9E5FB5-2BCE-5350-87B1-D63199526639"), exclusiveto, contract] */
                    MIDL_INTERFACE("1D9E5FB5-2BCE-5350-87B1-D63199526639")
                    IWidgetAnalyticsInfoReportedArgs : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_WidgetContext(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AnalyticsJson(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetAnalyticsInfoReportedArgs=_uuidof(IWidgetAnalyticsInfoReportedArgs);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetContext
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetContext
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetContext[] = L"Microsoft.Windows.Widgets.Providers.IWidgetContext";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("903C518B-40BC-5BC6-88F7-AF9D81C0CDC1"), exclusiveto, contract] */
                    MIDL_INTERFACE("903C518B-40BC-5BC6-88F7-AF9D81C0CDC1")
                    IWidgetContext : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Id(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DefinitionId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Size(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::WidgetSize * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsActive(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetContext=_uuidof(IWidgetContext);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetContextChangedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetContextChangedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetContextChangedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetContextChangedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("2C226D54-2252-576B-A197-370B28D25C2F"), exclusiveto, contract] */
                    MIDL_INTERFACE("2C226D54-2252-576B-A197-370B28D25C2F")
                    IWidgetContextChangedArgs : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_WidgetContext(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetContextChangedArgs=_uuidof(IWidgetContextChangedArgs);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetCustomizationRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetCustomizationRequestedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetCustomizationRequestedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetCustomizationRequestedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("41DEA311-DD9B-5B8B-B493-3A30552116B8"), exclusiveto, contract] */
                    MIDL_INTERFACE("41DEA311-DD9B-5B8B-B493-3A30552116B8")
                    IWidgetCustomizationRequestedArgs : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_WidgetContext(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CustomState(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetCustomizationRequestedArgs=_uuidof(IWidgetCustomizationRequestedArgs);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetErrorInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetErrorInfoReportedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetErrorInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetErrorInfoReportedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("30EFA627-B21F-55D5-B91A-B23B4AA13645"), exclusiveto, contract] */
                    MIDL_INTERFACE("30EFA627-B21F-55D5-B91A-B23B4AA13645")
                    IWidgetErrorInfoReportedArgs : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_WidgetContext(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ErrorJson(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetErrorInfoReportedArgs=_uuidof(IWidgetErrorInfoReportedArgs);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetInfo
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetInfo
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetInfo[] = L"Microsoft.Windows.Widgets.Providers.IWidgetInfo";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("CEA11F42-A020-5DB5-89E2-B7DECE4AE5CB"), exclusiveto, contract] */
                    MIDL_INTERFACE("CEA11F42-A020-5DB5-89E2-B7DECE4AE5CB")
                    IWidgetInfo : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_WidgetContext(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Template(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Data(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CustomState(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LastUpdateTime(
                            /* [retval, out] */ABI::Windows::Foundation::DateTime * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetInfo=_uuidof(IWidgetInfo);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetManager
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetManager[] = L"Microsoft.Windows.Widgets.Providers.IWidgetManager";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("71CB10C0-671E-48E3-B995-207940397123"), contract] */
                    MIDL_INTERFACE("71CB10C0-671E-48E3-B995-207940397123")
                    IWidgetManager : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE UpdateWidget(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetUpdateRequestOptions * widgetUpdateRequestOptions
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetWidgetIds(
                            /* [out] */UINT32 * __resultSize,
                            /* [size_is(, *(__resultSize)), retval, out] */HSTRING * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetWidgetInfo(
                            /* [in] */HSTRING widgetId,
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetInfo * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetWidgetInfos(
                            /* [out] */UINT32 * __resultSize,
                            /* [size_is(, *(__resultSize)), retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetInfo * * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE DeleteWidget(
                            /* [in] */HSTRING widgetId
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetManager=_uuidof(IWidgetManager);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetManagerStatics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetManager
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetManagerStatics[] = L"Microsoft.Windows.Widgets.Providers.IWidgetManagerStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("7F233B06-28E5-5E2B-8C04-A4FA747C28C7"), exclusiveto, contract] */
                    MIDL_INTERFACE("7F233B06-28E5-5E2B-8C04-A4FA747C28C7")
                    IWidgetManagerStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetDefault(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetManager * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetManagerStatics=_uuidof(IWidgetManagerStatics);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetProvider
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetProvider[] = L"Microsoft.Windows.Widgets.Providers.IWidgetProvider";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("5C5774CC-72A0-452D-B9ED-075C0DD25EED"), contract] */
                    MIDL_INTERFACE("5C5774CC-72A0-452D-B9ED-075C0DD25EED")
                    IWidgetProvider : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateWidget(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext * widgetContext
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE DeleteWidget(
                            /* [in] */HSTRING widgetId,
                            /* [in] */HSTRING customState
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE OnActionInvoked(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetActionInvokedArgs * actionInvokedArgs
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE OnWidgetContextChanged(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContextChangedArgs * contextChangedArgs
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Activate(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetContext * widgetContext
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Deactivate(
                            /* [in] */HSTRING widgetId
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetProvider=_uuidof(IWidgetProvider);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetProvider2
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetProvider2[] = L"Microsoft.Windows.Widgets.Providers.IWidgetProvider2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("38C3A963-DD93-479D-9276-04BF84EE1816"), contract] */
                    MIDL_INTERFACE("38C3A963-DD93-479D-9276-04BF84EE1816")
                    IWidgetProvider2 : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE OnCustomizationRequested(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetCustomizationRequestedArgs * customizationRequestedArgs
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetProvider2=_uuidof(IWidgetProvider2);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetProviderAnalytics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetProviderAnalytics[] = L"Microsoft.Windows.Widgets.Providers.IWidgetProviderAnalytics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("661985A5-D187-482D-9EEF-6FDA05D21845"), contract] */
                    MIDL_INTERFACE("661985A5-D187-482D-9EEF-6FDA05D21845")
                    IWidgetProviderAnalytics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE OnAnalyticsInfoReported(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetAnalyticsInfoReportedArgs * args
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetProviderAnalytics=_uuidof(IWidgetProviderAnalytics);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetProviderErrors
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetProviderErrors[] = L"Microsoft.Windows.Widgets.Providers.IWidgetProviderErrors";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("90C1B5F0-0D3A-4AC6-ABB7-C97B367B8FCC"), contract] */
                    MIDL_INTERFACE("90C1B5F0-0D3A-4AC6-ABB7-C97B367B8FCC")
                    IWidgetProviderErrors : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE OnErrorInfoReported(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetErrorInfoReportedArgs * args
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetProviderErrors=_uuidof(IWidgetProviderErrors);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptions
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetUpdateRequestOptions[] = L"Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("B09CA8F7-7424-5687-BAAF-7DD6FA639672"), exclusiveto, contract] */
                    MIDL_INTERFACE("B09CA8F7-7424-5687-BAAF-7DD6FA639672")
                    IWidgetUpdateRequestOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_WidgetId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Template(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Template(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Data(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Data(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CustomState(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_CustomState(
                            /* [in] */HSTRING value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetUpdateRequestOptions=_uuidof(IWidgetUpdateRequestOptions);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsFactory
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetUpdateRequestOptionsFactory[] = L"Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("E0E00AF8-1D10-57A8-9419-3F568E854DAA"), exclusiveto, contract] */
                    MIDL_INTERFACE("E0E00AF8-1D10-57A8-9419-3F568E854DAA")
                    IWidgetUpdateRequestOptionsFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */HSTRING widgetId,
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Providers::IWidgetUpdateRequestOptions * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetUpdateRequestOptionsFactory=_uuidof(IWidgetUpdateRequestOptionsFactory);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsStatics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetUpdateRequestOptionsStatics[] = L"Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Providers {
                    /* [object, uuid("4645B5E3-D332-5D11-82F0-3607E5DF6018"), exclusiveto, contract] */
                    MIDL_INTERFACE("4645B5E3-D332-5D11-82F0-3607E5DF6018")
                    IWidgetUpdateRequestOptionsStatics : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_UnsetValue(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IWidgetUpdateRequestOptionsStatics=_uuidof(IWidgetUpdateRequestOptionsStatics);
                    
                } /* Providers */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetActionInvokedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetActionInvokedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetActionInvokedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetActionInvokedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetActionInvokedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetActionInvokedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetAnalyticsInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetAnalyticsInfoReportedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetAnalyticsInfoReportedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetAnalyticsInfoReportedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetAnalyticsInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetAnalyticsInfoReportedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetContext
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetContext ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetContext_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetContext[] = L"Microsoft.Windows.Widgets.Providers.WidgetContext";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetContextChangedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetContextChangedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetContextChangedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetContextChangedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetContextChangedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetContextChangedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetCustomizationRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetCustomizationRequestedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetCustomizationRequestedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetCustomizationRequestedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetCustomizationRequestedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetCustomizationRequestedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetErrorInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetErrorInfoReportedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetErrorInfoReportedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetErrorInfoReportedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetErrorInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetErrorInfoReportedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetInfo
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetInfo_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetInfo[] = L"Microsoft.Windows.Widgets.Providers.WidgetInfo";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetManager
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Widgets.Providers.IWidgetManagerStatics interface starting with version 1.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetManager[] = L"Microsoft.Windows.Widgets.Providers.WidgetManager";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsFactory interface starting with version 1.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsStatics interface starting with version 1.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetUpdateRequestOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetUpdateRequestOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetUpdateRequestOptions[] = L"Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_FWD_DEFINED__



typedef enum __x_ABI_CMicrosoft_CWindows_CWidgets_CWidgetSize __x_ABI_CMicrosoft_CWindows_CWidgets_CWidgetSize;





typedef struct __x_ABI_CWindows_CFoundation_CDateTime __x_ABI_CWindows_CFoundation_CDateTime;

































/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetActionInvokedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetActionInvokedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetActionInvokedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetActionInvokedArgs";
/* [object, uuid("C593CC57-04B9-52CA-88AD-46FEA21EA340"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_WidgetContext )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Verb )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Data )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CustomState )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_get_WidgetContext(This,value) \
    ( (This)->lpVtbl->get_WidgetContext(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_get_Verb(This,value) \
    ( (This)->lpVtbl->get_Verb(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_get_Data(This,value) \
    ( (This)->lpVtbl->get_Data(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_get_CustomState(This,value) \
    ( (This)->lpVtbl->get_CustomState(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetAnalyticsInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetAnalyticsInfoReportedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetAnalyticsInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetAnalyticsInfoReportedArgs";
/* [object, uuid("1D9E5FB5-2BCE-5350-87B1-D63199526639"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_WidgetContext )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AnalyticsJson )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_get_WidgetContext(This,value) \
    ( (This)->lpVtbl->get_WidgetContext(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_get_AnalyticsJson(This,value) \
    ( (This)->lpVtbl->get_AnalyticsJson(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetContext
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetContext
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetContext[] = L"Microsoft.Windows.Widgets.Providers.IWidgetContext";
/* [object, uuid("903C518B-40BC-5BC6-88F7-AF9D81C0CDC1"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Id )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Size )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CWidgetSize * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsActive )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * This,
        /* [retval, out] */boolean * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_get_Id(This,value) \
    ( (This)->lpVtbl->get_Id(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_get_DefinitionId(This,value) \
    ( (This)->lpVtbl->get_DefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_get_Size(This,value) \
    ( (This)->lpVtbl->get_Size(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_get_IsActive(This,value) \
    ( (This)->lpVtbl->get_IsActive(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetContextChangedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetContextChangedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetContextChangedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetContextChangedArgs";
/* [object, uuid("2C226D54-2252-576B-A197-370B28D25C2F"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_WidgetContext )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_get_WidgetContext(This,value) \
    ( (This)->lpVtbl->get_WidgetContext(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetCustomizationRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetCustomizationRequestedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetCustomizationRequestedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetCustomizationRequestedArgs";
/* [object, uuid("41DEA311-DD9B-5B8B-B493-3A30552116B8"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_WidgetContext )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CustomState )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_get_WidgetContext(This,value) \
    ( (This)->lpVtbl->get_WidgetContext(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_get_CustomState(This,value) \
    ( (This)->lpVtbl->get_CustomState(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetErrorInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetErrorInfoReportedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetErrorInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Providers.IWidgetErrorInfoReportedArgs";
/* [object, uuid("30EFA627-B21F-55D5-B91A-B23B4AA13645"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_WidgetContext )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ErrorJson )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_get_WidgetContext(This,value) \
    ( (This)->lpVtbl->get_WidgetContext(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_get_ErrorJson(This,value) \
    ( (This)->lpVtbl->get_ErrorJson(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetInfo
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetInfo
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetInfo[] = L"Microsoft.Windows.Widgets.Providers.IWidgetInfo";
/* [object, uuid("CEA11F42-A020-5DB5-89E2-B7DECE4AE5CB"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfoVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_WidgetContext )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Template )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Data )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CustomState )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LastUpdateTime )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CDateTime * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfoVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfoVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_get_WidgetContext(This,value) \
    ( (This)->lpVtbl->get_WidgetContext(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_get_Template(This,value) \
    ( (This)->lpVtbl->get_Template(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_get_Data(This,value) \
    ( (This)->lpVtbl->get_Data(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_get_CustomState(This,value) \
    ( (This)->lpVtbl->get_CustomState(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_get_LastUpdateTime(This,value) \
    ( (This)->lpVtbl->get_LastUpdateTime(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetManager
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetManager[] = L"Microsoft.Windows.Widgets.Providers.IWidgetManager";
/* [object, uuid("71CB10C0-671E-48E3-B995-207940397123"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *UpdateWidget )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * widgetUpdateRequestOptions
        );
    HRESULT ( STDMETHODCALLTYPE *GetWidgetIds )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */HSTRING * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetWidgetInfo )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
        /* [in] */HSTRING widgetId,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetWidgetInfos )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetInfo * * * result
        );
    HRESULT ( STDMETHODCALLTYPE *DeleteWidget )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * This,
        /* [in] */HSTRING widgetId
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_UpdateWidget(This,widgetUpdateRequestOptions) \
    ( (This)->lpVtbl->UpdateWidget(This,widgetUpdateRequestOptions) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_GetWidgetIds(This,__resultSize,result) \
    ( (This)->lpVtbl->GetWidgetIds(This,__resultSize,result) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_GetWidgetInfo(This,widgetId,result) \
    ( (This)->lpVtbl->GetWidgetInfo(This,widgetId,result) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_GetWidgetInfos(This,__resultSize,result) \
    ( (This)->lpVtbl->GetWidgetInfos(This,__resultSize,result) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_DeleteWidget(This,widgetId) \
    ( (This)->lpVtbl->DeleteWidget(This,widgetId) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetManagerStatics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetManager
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetManagerStatics[] = L"Microsoft.Windows.Widgets.Providers.IWidgetManagerStatics";
/* [object, uuid("7F233B06-28E5-5E2B-8C04-A4FA747C28C7"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetDefault )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManager * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_GetDefault(This,result) \
    ( (This)->lpVtbl->GetDefault(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetProvider
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetProvider[] = L"Microsoft.Windows.Widgets.Providers.IWidgetProvider";
/* [object, uuid("5C5774CC-72A0-452D-B9ED-075C0DD25EED"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateWidget )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * widgetContext
        );
    HRESULT ( STDMETHODCALLTYPE *DeleteWidget )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
        /* [in] */HSTRING widgetId,
        /* [in] */HSTRING customState
        );
    HRESULT ( STDMETHODCALLTYPE *OnActionInvoked )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetActionInvokedArgs * actionInvokedArgs
        );
    HRESULT ( STDMETHODCALLTYPE *OnWidgetContextChanged )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContextChangedArgs * contextChangedArgs
        );
    HRESULT ( STDMETHODCALLTYPE *Activate )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetContext * widgetContext
        );
    HRESULT ( STDMETHODCALLTYPE *Deactivate )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider * This,
        /* [in] */HSTRING widgetId
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_CreateWidget(This,widgetContext) \
    ( (This)->lpVtbl->CreateWidget(This,widgetContext) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_DeleteWidget(This,widgetId,customState) \
    ( (This)->lpVtbl->DeleteWidget(This,widgetId,customState) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_OnActionInvoked(This,actionInvokedArgs) \
    ( (This)->lpVtbl->OnActionInvoked(This,actionInvokedArgs) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_OnWidgetContextChanged(This,contextChangedArgs) \
    ( (This)->lpVtbl->OnWidgetContextChanged(This,contextChangedArgs) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_Activate(This,widgetContext) \
    ( (This)->lpVtbl->Activate(This,widgetContext) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_Deactivate(This,widgetId) \
    ( (This)->lpVtbl->Deactivate(This,widgetId) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetProvider2
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetProvider2[] = L"Microsoft.Windows.Widgets.Providers.IWidgetProvider2";
/* [object, uuid("38C3A963-DD93-479D-9276-04BF84EE1816"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnCustomizationRequested )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2 * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetCustomizationRequestedArgs * customizationRequestedArgs
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_OnCustomizationRequested(This,customizationRequestedArgs) \
    ( (This)->lpVtbl->OnCustomizationRequested(This,customizationRequestedArgs) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProvider2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetProviderAnalytics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetProviderAnalytics[] = L"Microsoft.Windows.Widgets.Providers.IWidgetProviderAnalytics";
/* [object, uuid("661985A5-D187-482D-9EEF-6FDA05D21845"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalyticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnAnalyticsInfoReported )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetAnalyticsInfoReportedArgs * args
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalyticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalyticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_OnAnalyticsInfoReported(This,args) \
    ( (This)->lpVtbl->OnAnalyticsInfoReported(This,args) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderAnalytics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetProviderErrors
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetProviderErrors[] = L"Microsoft.Windows.Widgets.Providers.IWidgetProviderErrors";
/* [object, uuid("90C1B5F0-0D3A-4AC6-ABB7-C97B367B8FCC"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrorsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnErrorInfoReported )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetErrorInfoReportedArgs * args
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrorsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrorsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_OnErrorInfoReported(This,args) \
    ( (This)->lpVtbl->OnErrorInfoReported(This,args) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetProviderErrors_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptions
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetUpdateRequestOptions[] = L"Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptions";
/* [object, uuid("B09CA8F7-7424-5687-BAAF-7DD6FA639672"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_WidgetId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Template )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Template )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Data )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Data )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CustomState )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_CustomState )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * This,
        /* [in] */HSTRING value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_get_WidgetId(This,value) \
    ( (This)->lpVtbl->get_WidgetId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_get_Template(This,value) \
    ( (This)->lpVtbl->get_Template(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_put_Template(This,value) \
    ( (This)->lpVtbl->put_Template(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_get_Data(This,value) \
    ( (This)->lpVtbl->get_Data(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_put_Data(This,value) \
    ( (This)->lpVtbl->put_Data(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_get_CustomState(This,value) \
    ( (This)->lpVtbl->get_CustomState(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_put_CustomState(This,value) \
    ( (This)->lpVtbl->put_CustomState(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsFactory
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetUpdateRequestOptionsFactory[] = L"Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsFactory";
/* [object, uuid("E0E00AF8-1D10-57A8-9419-3F568E854DAA"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory * This,
        /* [in] */HSTRING widgetId,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptions * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_CreateInstance(This,widgetId,value) \
    ( (This)->lpVtbl->CreateInstance(This,widgetId,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsStatics
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Providers_IWidgetUpdateRequestOptionsStatics[] = L"Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsStatics";
/* [object, uuid("4645B5E3-D332-5D11-82F0-3607E5DF6018"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_UnsetValue )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_get_UnsetValue(This,value) \
    ( (This)->lpVtbl->get_UnsetValue(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CProviders_CIWidgetUpdateRequestOptionsStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetActionInvokedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetActionInvokedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetActionInvokedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetActionInvokedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetActionInvokedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetActionInvokedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetAnalyticsInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetAnalyticsInfoReportedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetAnalyticsInfoReportedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetAnalyticsInfoReportedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetAnalyticsInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetAnalyticsInfoReportedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetContext
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetContext ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetContext_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetContext[] = L"Microsoft.Windows.Widgets.Providers.WidgetContext";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetContextChangedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetContextChangedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetContextChangedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetContextChangedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetContextChangedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetContextChangedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetCustomizationRequestedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetCustomizationRequestedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetCustomizationRequestedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetCustomizationRequestedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetCustomizationRequestedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetCustomizationRequestedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetErrorInfoReportedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 2.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetErrorInfoReportedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetErrorInfoReportedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetErrorInfoReportedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetErrorInfoReportedArgs[] = L"Microsoft.Windows.Widgets.Providers.WidgetErrorInfoReportedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetInfo
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetInfo_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetInfo[] = L"Microsoft.Windows.Widgets.Providers.WidgetInfo";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetManager
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Widgets.Providers.IWidgetManagerStatics interface starting with version 1.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetManager[] = L"Microsoft.Windows.Widgets.Providers.WidgetManager";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsFactory interface starting with version 1.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptionsStatics interface starting with version 1.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Providers.IWidgetUpdateRequestOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetUpdateRequestOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Providers_WidgetUpdateRequestOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Providers_WidgetUpdateRequestOptions[] = L"Microsoft.Windows.Widgets.Providers.WidgetUpdateRequestOptions";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x10000





#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Ewidgets2Eproviders_p_h__

#endif // __microsoft2Ewindows2Ewidgets2Eproviders_h__

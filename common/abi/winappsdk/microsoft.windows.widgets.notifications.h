
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
#ifndef __microsoft2Ewindows2Ewidgets2Enotifications_h__
#define __microsoft2Ewindows2Ewidgets2Enotifications_h__
#ifndef __microsoft2Ewindows2Ewidgets2Enotifications_p_h__
#define __microsoft2Ewindows2Ewidgets2Enotifications_p_h__


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

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    interface IFeedAnnouncementFactory;
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory ABI::Microsoft::Windows::Widgets::Notifications::IFeedAnnouncementFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_FWD_DEFINED__

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
            
            typedef struct DateTime DateTime;
            
        } /* Foundation */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Foundation {
            
            typedef struct TimeSpan TimeSpan;
            
        } /* Foundation */
    } /* Windows */
} /* ABI */

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




namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    
                    typedef enum AnnouncementActionKind : int AnnouncementActionKind;
                    
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    
                    typedef enum AnnouncementTextColor : int AnnouncementTextColor;
                    
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */




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







/*
 *
 * Struct Microsoft.Windows.Widgets.Notifications.AnnouncementActionKind
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */

#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    /* [v1_enum, contract] */
                    enum AnnouncementActionKind : int
                    {
                        AnnouncementActionKind_Shown = 0,
                        AnnouncementActionKind_Engaged = 1,
                    };
                    
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Struct Microsoft.Windows.Widgets.Notifications.AnnouncementTextColor
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */

#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    /* [v1_enum, contract] */
                    enum AnnouncementTextColor : int
                    {
                        AnnouncementTextColor_Default = 0,
                        AnnouncementTextColor_Dark = 1,
                        AnnouncementTextColor_Light = 2,
                        AnnouncementTextColor_Accent = 3,
                        AnnouncementTextColor_Good = 4,
                        AnnouncementTextColor_Warning = 5,
                        AnnouncementTextColor_Attention = 6,
                    };
                    
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Notifications.IFeedAnnouncement
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Notifications.FeedAnnouncement
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Notifications_IFeedAnnouncement[] = L"Microsoft.Windows.Widgets.Notifications.IFeedAnnouncement";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    /* [object, uuid("B88E8C2C-D251-5344-ACC2-8CF9BA07EC15"), exclusiveto, contract] */
                    MIDL_INTERFACE("B88E8C2C-D251-5344-ACC2-8CF9BA07EC15")
                    IFeedAnnouncement : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Id(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Id(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PrimaryText(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PrimaryText(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SecondaryText(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_SecondaryText(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LightModeIconUri(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_LightModeIconUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DarkModeIconUri(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_DarkModeIconUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PrimaryTextColor(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Notifications::AnnouncementTextColor * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_PrimaryTextColor(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Notifications::AnnouncementTextColor value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SecondaryTextColor(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Notifications::AnnouncementTextColor * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_SecondaryTextColor(
                            /* [in] */ABI::Microsoft::Windows::Widgets::Notifications::AnnouncementTextColor value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CustomAccessibilityText(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_CustomAccessibilityText(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSecondaryTextSubtle(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IsSecondaryTextSubtle(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ShowBadgeIfUserNotEngaged(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ShowBadgeIfUserNotEngaged(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExpirationTime(
                            /* [retval, out] */ABI::Windows::Foundation::DateTime * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ExpirationTime(
                            /* [in] */ABI::Windows::Foundation::DateTime value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Duration(
                            /* [retval, out] */ABI::Windows::Foundation::TimeSpan * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Duration(
                            /* [in] */ABI::Windows::Foundation::TimeSpan value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IFeedAnnouncement=_uuidof(IFeedAnnouncement);
                    
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementFactory
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Notifications.FeedAnnouncement
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Notifications_IFeedAnnouncementFactory[] = L"Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    /* [object, uuid("22074243-46D8-5AF2-8715-1C76D1CB774C"), exclusiveto, contract] */
                    MIDL_INTERFACE("22074243-46D8-5AF2-8715-1C76D1CB774C")
                    IFeedAnnouncementFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */HSTRING id,
                            /* [in] */HSTRING primaryText,
                            /* [in] */HSTRING secondaryText,
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * lightModeIcon,
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * darkModeIcon,
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Notifications::IFeedAnnouncement * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IFeedAnnouncementFactory=_uuidof(IFeedAnnouncementFactory);
                    
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementInvokedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Notifications.FeedAnnouncementInvokedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Notifications_IFeedAnnouncementInvokedArgs[] = L"Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementInvokedArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Widgets {
                namespace Notifications {
                    /* [object, uuid("70A48D98-323D-5F19-A1E1-B63FE36EDBF2"), exclusiveto, contract] */
                    MIDL_INTERFACE("70A48D98-323D-5F19-A1E1-B63FE36EDBF2")
                    IFeedAnnouncementInvokedArgs : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedProviderDefinitionId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FeedDefinitionId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AnnouncementId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ActionKind(
                            /* [retval, out] */ABI::Microsoft::Windows::Widgets::Notifications::AnnouncementActionKind * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IFeedAnnouncementInvokedArgs=_uuidof(IFeedAnnouncementInvokedArgs);
                    
                } /* Notifications */
            } /* Widgets */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Notifications.FeedAnnouncement
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementFactory interface starting with version 5.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Notifications.IFeedAnnouncement ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Notifications_FeedAnnouncement_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Notifications_FeedAnnouncement_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Notifications_FeedAnnouncement[] = L"Microsoft.Windows.Widgets.Notifications.FeedAnnouncement";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Notifications.FeedAnnouncementInvokedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementInvokedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Notifications_FeedAnnouncementInvokedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Notifications_FeedAnnouncementInvokedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Notifications_FeedAnnouncementInvokedArgs[] = L"Microsoft.Windows.Widgets.Notifications.FeedAnnouncementInvokedArgs";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_FWD_DEFINED__






typedef struct __x_ABI_CWindows_CFoundation_CDateTime __x_ABI_CWindows_CFoundation_CDateTime;


typedef struct __x_ABI_CWindows_CFoundation_CTimeSpan __x_ABI_CWindows_CFoundation_CTimeSpan;

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__





typedef enum __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementActionKind __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementActionKind;


typedef enum __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementTextColor __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementTextColor;











/*
 *
 * Struct Microsoft.Windows.Widgets.Notifications.AnnouncementActionKind
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */

#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementActionKind
{
    AnnouncementActionKind_Shown = 0,
    AnnouncementActionKind_Engaged = 1,
};
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Struct Microsoft.Windows.Widgets.Notifications.AnnouncementTextColor
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 */

#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementTextColor
{
    AnnouncementTextColor_Default = 0,
    AnnouncementTextColor_Dark = 1,
    AnnouncementTextColor_Light = 2,
    AnnouncementTextColor_Accent = 3,
    AnnouncementTextColor_Good = 4,
    AnnouncementTextColor_Warning = 5,
    AnnouncementTextColor_Attention = 6,
};
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Notifications.IFeedAnnouncement
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Notifications.FeedAnnouncement
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Notifications_IFeedAnnouncement[] = L"Microsoft.Windows.Widgets.Notifications.IFeedAnnouncement";
/* [object, uuid("B88E8C2C-D251-5344-ACC2-8CF9BA07EC15"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Id )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Id )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PrimaryText )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PrimaryText )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SecondaryText )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_SecondaryText )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LightModeIconUri )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_LightModeIconUri )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DarkModeIconUri )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_DarkModeIconUri )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PrimaryTextColor )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementTextColor * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_PrimaryTextColor )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementTextColor value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SecondaryTextColor )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementTextColor * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_SecondaryTextColor )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementTextColor value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CustomAccessibilityText )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_CustomAccessibilityText )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSecondaryTextSubtle )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IsSecondaryTextSubtle )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ShowBadgeIfUserNotEngaged )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ShowBadgeIfUserNotEngaged )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExpirationTime )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CDateTime * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ExpirationTime )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CDateTime value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Duration )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CTimeSpan * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Duration )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CTimeSpan value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_Id(This,value) \
    ( (This)->lpVtbl->get_Id(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_Id(This,value) \
    ( (This)->lpVtbl->put_Id(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_PrimaryText(This,value) \
    ( (This)->lpVtbl->get_PrimaryText(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_PrimaryText(This,value) \
    ( (This)->lpVtbl->put_PrimaryText(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_SecondaryText(This,value) \
    ( (This)->lpVtbl->get_SecondaryText(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_SecondaryText(This,value) \
    ( (This)->lpVtbl->put_SecondaryText(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_LightModeIconUri(This,value) \
    ( (This)->lpVtbl->get_LightModeIconUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_LightModeIconUri(This,value) \
    ( (This)->lpVtbl->put_LightModeIconUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_DarkModeIconUri(This,value) \
    ( (This)->lpVtbl->get_DarkModeIconUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_DarkModeIconUri(This,value) \
    ( (This)->lpVtbl->put_DarkModeIconUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_PrimaryTextColor(This,value) \
    ( (This)->lpVtbl->get_PrimaryTextColor(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_PrimaryTextColor(This,value) \
    ( (This)->lpVtbl->put_PrimaryTextColor(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_SecondaryTextColor(This,value) \
    ( (This)->lpVtbl->get_SecondaryTextColor(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_SecondaryTextColor(This,value) \
    ( (This)->lpVtbl->put_SecondaryTextColor(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_CustomAccessibilityText(This,value) \
    ( (This)->lpVtbl->get_CustomAccessibilityText(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_CustomAccessibilityText(This,value) \
    ( (This)->lpVtbl->put_CustomAccessibilityText(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_IsSecondaryTextSubtle(This,value) \
    ( (This)->lpVtbl->get_IsSecondaryTextSubtle(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_IsSecondaryTextSubtle(This,value) \
    ( (This)->lpVtbl->put_IsSecondaryTextSubtle(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_ShowBadgeIfUserNotEngaged(This,value) \
    ( (This)->lpVtbl->get_ShowBadgeIfUserNotEngaged(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_ShowBadgeIfUserNotEngaged(This,value) \
    ( (This)->lpVtbl->put_ShowBadgeIfUserNotEngaged(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_ExpirationTime(This,value) \
    ( (This)->lpVtbl->get_ExpirationTime(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_ExpirationTime(This,value) \
    ( (This)->lpVtbl->put_ExpirationTime(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_get_Duration(This,value) \
    ( (This)->lpVtbl->get_Duration(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_put_Duration(This,value) \
    ( (This)->lpVtbl->put_Duration(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementFactory
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Notifications.FeedAnnouncement
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Notifications_IFeedAnnouncementFactory[] = L"Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementFactory";
/* [object, uuid("22074243-46D8-5AF2-8715-1C76D1CB774C"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory * This,
        /* [in] */HSTRING id,
        /* [in] */HSTRING primaryText,
        /* [in] */HSTRING secondaryText,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * lightModeIcon,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * darkModeIcon,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncement * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_CreateInstance(This,id,primaryText,secondaryText,lightModeIcon,darkModeIcon,value) \
    ( (This)->lpVtbl->CreateInstance(This,id,primaryText,secondaryText,lightModeIcon,darkModeIcon,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Interface Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementInvokedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Widgets.Notifications.FeedAnnouncementInvokedArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Widgets_Notifications_IFeedAnnouncementInvokedArgs[] = L"Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementInvokedArgs";
/* [object, uuid("70A48D98-323D-5F19-A1E1-B63FE36EDBF2"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedProviderDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FeedDefinitionId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AnnouncementId )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ActionKind )(
        __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CAnnouncementActionKind * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_get_FeedProviderDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedProviderDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_get_FeedDefinitionId(This,value) \
    ( (This)->lpVtbl->get_FeedDefinitionId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_get_AnnouncementId(This,value) \
    ( (This)->lpVtbl->get_AnnouncementId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_get_ActionKind(This,value) \
    ( (This)->lpVtbl->get_ActionKind(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CWidgets_CNotifications_CIFeedAnnouncementInvokedArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Notifications.FeedAnnouncement
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementFactory interface starting with version 5.0 of the Microsoft.Windows.Widgets.WidgetContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Notifications.IFeedAnnouncement ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Notifications_FeedAnnouncement_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Notifications_FeedAnnouncement_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Notifications_FeedAnnouncement[] = L"Microsoft.Windows.Widgets.Notifications.FeedAnnouncement";
#endif
#endif // MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000


/*
 *
 * Class Microsoft.Windows.Widgets.Notifications.FeedAnnouncementInvokedArgs
 *
 * Introduced to Microsoft.Windows.Widgets.WidgetContract in version 5.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.Widgets.Notifications.IFeedAnnouncementInvokedArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_WIDGETS_WIDGETCONTRACT_VERSION >= 0x50000

#ifndef RUNTIMECLASS_Microsoft_Windows_Widgets_Notifications_FeedAnnouncementInvokedArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Widgets_Notifications_FeedAnnouncementInvokedArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Widgets_Notifications_FeedAnnouncementInvokedArgs[] = L"Microsoft.Windows.Widgets.Notifications.FeedAnnouncementInvokedArgs";
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
#endif // __microsoft2Ewindows2Ewidgets2Enotifications_p_h__

#endif // __microsoft2Ewindows2Ewidgets2Enotifications_h__

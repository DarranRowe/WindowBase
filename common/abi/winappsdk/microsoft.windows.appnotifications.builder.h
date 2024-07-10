
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
#ifndef __microsoft2Ewindows2Eappnotifications2Ebuilder_h__
#define __microsoft2Ewindows2Eappnotifications2Ebuilder_h__
#ifndef __microsoft2Ewindows2Eappnotifications2Ebuilder_p_h__
#define __microsoft2Ewindows2Eappnotifications2Ebuilder_p_h__


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
#if !defined(MICROSOFT_WINDOWS_APPNOTIFICATIONS_APPNOTIFICATIONSCONTRACT_VERSION)
#define MICROSOFT_WINDOWS_APPNOTIFICATIONS_APPNOTIFICATIONSCONTRACT_VERSION 0x30000
#endif // defined(MICROSOFT_WINDOWS_APPNOTIFICATIONS_APPNOTIFICATIONSCONTRACT_VERSION)

#if !defined(MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION)
#define MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION 0x10000
#endif // defined(MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION)

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
#include "Microsoft.Windows.AppNotifications.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationBuilder;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationBuilderStatics;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilderStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationButton;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationButtonFactory;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButtonFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationButtonStatics;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButtonStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationComboBox;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationComboBox

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationComboBoxFactory;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationComboBoxFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationProgressBar;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    interface IAppNotificationTextProperties;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationTextProperties

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_FWD_DEFINED__

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





namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                class AppNotification;
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                interface IAppNotification;
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification ABI::Microsoft::Windows::AppNotifications::IAppNotification

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification_FWD_DEFINED__





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
            namespace AppNotifications {
                namespace Builder {
                    
                    typedef enum AppNotificationAudioLooping : int AppNotificationAudioLooping;
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    
                    typedef enum AppNotificationButtonStyle : int AppNotificationButtonStyle;
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    
                    typedef enum AppNotificationDuration : int AppNotificationDuration;
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    
                    typedef enum AppNotificationImageCrop : int AppNotificationImageCrop;
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    
                    typedef enum AppNotificationScenario : int AppNotificationScenario;
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    
                    typedef enum AppNotificationSoundEvent : int AppNotificationSoundEvent;
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */










namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    class AppNotificationBuilder;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    class AppNotificationButton;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    class AppNotificationComboBox;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    class AppNotificationProgressBar;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    class AppNotificationTextProperties;
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */








/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationAudioLooping
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [v1_enum, contract] */
                    enum AppNotificationAudioLooping : int
                    {
                        AppNotificationAudioLooping_None = 0,
                        AppNotificationAudioLooping_Loop = 1,
                    };
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationButtonStyle
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [v1_enum, contract] */
                    enum AppNotificationButtonStyle : int
                    {
                        AppNotificationButtonStyle_Default = 0,
                        AppNotificationButtonStyle_Success = 1,
                        AppNotificationButtonStyle_Critical = 2,
                    };
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationDuration
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [v1_enum, contract] */
                    enum AppNotificationDuration : int
                    {
                        AppNotificationDuration_Default = 0,
                        AppNotificationDuration_Long = 1,
                    };
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationImageCrop
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [v1_enum, contract] */
                    enum AppNotificationImageCrop : int
                    {
                        AppNotificationImageCrop_Default = 0,
                        AppNotificationImageCrop_Circle = 1,
                    };
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationScenario
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [v1_enum, contract] */
                    enum AppNotificationScenario : int
                    {
                        AppNotificationScenario_Default = 0,
                        AppNotificationScenario_Reminder = 1,
                        AppNotificationScenario_Alarm = 2,
                        AppNotificationScenario_IncomingCall = 3,
                        AppNotificationScenario_Urgent = 4,
                    };
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationSoundEvent
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [v1_enum, contract] */
                    enum AppNotificationSoundEvent : int
                    {
                        AppNotificationSoundEvent_Default = 0,
                        AppNotificationSoundEvent_IM = 1,
                        AppNotificationSoundEvent_Mail = 2,
                        AppNotificationSoundEvent_Reminder = 3,
                        AppNotificationSoundEvent_SMS = 4,
                        AppNotificationSoundEvent_Alarm = 5,
                        AppNotificationSoundEvent_Alarm2 = 6,
                        AppNotificationSoundEvent_Alarm3 = 7,
                        AppNotificationSoundEvent_Alarm4 = 8,
                        AppNotificationSoundEvent_Alarm5 = 9,
                        AppNotificationSoundEvent_Alarm6 = 10,
                        AppNotificationSoundEvent_Alarm7 = 11,
                        AppNotificationSoundEvent_Alarm8 = 12,
                        AppNotificationSoundEvent_Alarm9 = 13,
                        AppNotificationSoundEvent_Alarm10 = 14,
                        AppNotificationSoundEvent_Call = 15,
                        AppNotificationSoundEvent_Call2 = 16,
                        AppNotificationSoundEvent_Call3 = 17,
                        AppNotificationSoundEvent_Call4 = 18,
                        AppNotificationSoundEvent_Call5 = 19,
                        AppNotificationSoundEvent_Call6 = 20,
                        AppNotificationSoundEvent_Call7 = 21,
                        AppNotificationSoundEvent_Call8 = 22,
                        AppNotificationSoundEvent_Call9 = 23,
                        AppNotificationSoundEvent_Call10 = 24,
                    };
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilder
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilder
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationBuilder[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilder";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("E801D31F-CE03-505C-ADEC-8A02724EC9DE"), exclusiveto, contract] */
                    MIDL_INTERFACE("E801D31F-CE03-505C-ADEC-8A02724EC9DE")
                    IAppNotificationBuilder : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE AddArgument(
                            /* [in] */HSTRING key,
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetTimeStamp(
                            /* [in] */ABI::Windows::Foundation::DateTime value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetDuration(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationDuration duration,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetScenario(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationScenario value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE AddText(
                            /* [in] */HSTRING text,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE AddText2(
                            /* [in] */HSTRING text,
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationTextProperties * properties,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAttributionText(
                            /* [in] */HSTRING text,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAttributionText2(
                            /* [in] */HSTRING text,
                            /* [in] */HSTRING language,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetInlineImage(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * imageUri,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetInlineImage2(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * imageUri,
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationImageCrop imageCrop,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetInlineImage3(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * imageUri,
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationImageCrop imagecrop,
                            /* [in] */HSTRING alternateText,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAppLogoOverride(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * imageUri,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAppLogoOverride2(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * imageUri,
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationImageCrop imageCrop,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAppLogoOverride3(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * imageUri,
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationImageCrop imageCrop,
                            /* [in] */HSTRING alternateText,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetHeroImage(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * imageUri,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetHeroImage2(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * imageUri,
                            /* [in] */HSTRING alternateText,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAudioUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * audioUri,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAudioUri2(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * audioUri,
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationAudioLooping loop,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAudioEvent(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationSoundEvent appNotificationSoundEvent,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetAudioEvent2(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationSoundEvent appNotificationSoundEvent,
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationAudioLooping loop,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE MuteAudio(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE AddTextBox(
                            /* [in] */HSTRING id,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE AddTextBox2(
                            /* [in] */HSTRING id,
                            /* [in] */HSTRING placeHolderText,
                            /* [in] */HSTRING title,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AddButton(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AddComboBox(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationComboBox * value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AddProgressBar(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE BuildNotification(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::IAppNotification * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetTag(
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetGroup(
                            /* [in] */HSTRING group,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationBuilder * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationBuilder=_uuidof(IAppNotificationBuilder);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilderStatics
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilder
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationBuilderStatics[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilderStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("C7042D2A-D319-520E-A314-50081C8888CC"), exclusiveto, contract] */
                    MIDL_INTERFACE("C7042D2A-D319-520E-A314-50081C8888CC")
                    IAppNotificationBuilderStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE IsUrgentScenarioSupported(
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationBuilderStatics=_uuidof(IAppNotificationBuilderStatics);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationButton
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationButton
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationButton[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationButton";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("A7C03031-5634-5098-AEC9-47ECB60C3499"), exclusiveto, contract] */
                    MIDL_INTERFACE("A7C03031-5634-5098-AEC9-47ECB60C3499")
                    IAppNotificationButton : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Content(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Content(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Arguments(
                            /* [retval, out] */__FIMap_2_HSTRING_HSTRING * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Arguments(
                            /* [in] */__FIMap_2_HSTRING_HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Icon(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Icon(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ToolTip(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ToolTip(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ContextMenuPlacement(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ContextMenuPlacement(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ButtonStyle(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationButtonStyle * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ButtonStyle(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationButtonStyle value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InputId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_InputId(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InvokeUri(
                            /* [retval, out] */ABI::Windows::Foundation::IUriRuntimeClass * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_InvokeUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_TargetAppId(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_TargetAppId(
                            /* [in] */HSTRING value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AddArgument(
                            /* [in] */HSTRING key,
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetIcon(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetToolTip(
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetContextMenuPlacement(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetButtonStyle(
                            /* [in] */ABI::Microsoft::Windows::AppNotifications::Builder::AppNotificationButtonStyle value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetInputId(
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetInvokeUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * protocolUri,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE SetInvokeUri2(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * protocolUri,
                            /* [in] */HSTRING targetAppId,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationButton=_uuidof(IAppNotificationButton);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonFactory
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationButton
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationButtonFactory[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("4F109286-0A6D-5A5E-9E8F-9FE31669FBB8"), exclusiveto, contract] */
                    MIDL_INTERFACE("4F109286-0A6D-5A5E-9E8F-9FE31669FBB8")
                    IAppNotificationButtonFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */HSTRING content,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationButton * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationButtonFactory=_uuidof(IAppNotificationButtonFactory);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonStatics
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationButton
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationButtonStatics[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("FEAD7C18-4144-59A4-9611-86B7E8191853"), exclusiveto, contract] */
                    MIDL_INTERFACE("FEAD7C18-4144-59A4-9611-86B7E8191853")
                    IAppNotificationButtonStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE IsToolTipSupported(
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsButtonStyleSupported(
                            /* [retval, out] */::boolean * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationButtonStatics=_uuidof(IAppNotificationButtonStatics);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBox
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationComboBox
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationComboBox[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBox";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("4547C9E2-4815-538C-BE26-040CE17F8B62"), exclusiveto, contract] */
                    MIDL_INTERFACE("4547C9E2-4815-538C-BE26-040CE17F8B62")
                    IAppNotificationComboBox : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Items(
                            /* [retval, out] */__FIMap_2_HSTRING_HSTRING * * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Items(
                            /* [in] */__FIMap_2_HSTRING_HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Title(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Title(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SelectedItem(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_SelectedItem(
                            /* [in] */HSTRING value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AddItem(
                            /* [in] */HSTRING id,
                            /* [in] */HSTRING content,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationComboBox * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetTitle(
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationComboBox * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetSelectedItem(
                            /* [in] */HSTRING id,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationComboBox * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationComboBox=_uuidof(IAppNotificationComboBox);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBoxFactory
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationComboBox
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationComboBoxFactory[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBoxFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("1B31B5B0-9D86-59ED-8629-A79498AB5D4B"), exclusiveto, contract] */
                    MIDL_INTERFACE("1B31B5B0-9D86-59ED-8629-A79498AB5D4B")
                    IAppNotificationComboBoxFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */HSTRING id,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationComboBox * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationComboBoxFactory=_uuidof(IAppNotificationComboBoxFactory);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationProgressBar
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationProgressBar
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationProgressBar[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationProgressBar";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("FCED62F2-2074-5641-8630-87A14315AC86"), exclusiveto, contract] */
                    MIDL_INTERFACE("FCED62F2-2074-5641-8630-87A14315AC86")
                    IAppNotificationProgressBar : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Title(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Title(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Status(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Status(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Value(
                            /* [retval, out] */DOUBLE * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Value(
                            /* [in] */DOUBLE value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ValueStringOverride(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ValueStringOverride(
                            /* [in] */HSTRING value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetTitle(
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE BindTitle(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetStatus(
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE BindStatus(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetValue(
                            /* [in] */DOUBLE value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE BindValue(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetValueStringOverride(
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE BindValueStringOverride(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationProgressBar * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationProgressBar=_uuidof(IAppNotificationProgressBar);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationTextProperties
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationTextProperties
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationTextProperties[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationTextProperties";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace AppNotifications {
                namespace Builder {
                    /* [object, uuid("23A30D0B-5258-5853-932E-9521A3642AFB"), exclusiveto, contract] */
                    MIDL_INTERFACE("23A30D0B-5258-5853-932E-9521A3642AFB")
                    IAppNotificationTextProperties : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Language(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_Language(
                            /* [in] */HSTRING value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IncomingCallAlignment(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_IncomingCallAlignment(
                            /* [in] */::boolean value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_MaxLines(
                            /* [retval, out] */INT32 * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_MaxLines(
                            /* [in] */INT32 value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetLanguage(
                            /* [in] */HSTRING value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationTextProperties * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetIncomingCallAlignment(
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationTextProperties * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetMaxLines(
                            /* [in] */INT32 value,
                            /* [retval, out] */ABI::Microsoft::Windows::AppNotifications::Builder::IAppNotificationTextProperties * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IAppNotificationTextProperties=_uuidof(IAppNotificationTextProperties);
                    
                } /* Builder */
            } /* AppNotifications */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilder
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilderStatics interface starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilder ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationBuilder_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationBuilder_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationBuilder[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilder";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationButton
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonFactory interface starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonStatics interface starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationButton ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationButton_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationButton_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationButton[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationButton";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationComboBox
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBoxFactory interface starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBox ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationComboBox_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationComboBox_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationComboBox[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationComboBox";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationProgressBar
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationProgressBar ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationProgressBar_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationProgressBar_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationProgressBar[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationProgressBar";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationTextProperties
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationTextProperties ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationTextProperties_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationTextProperties_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationTextProperties[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationTextProperties";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_FWD_DEFINED__

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



#ifndef ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification __x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification;

#endif // ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification_FWD_DEFINED__






typedef struct __x_ABI_CWindows_CFoundation_CDateTime __x_ABI_CWindows_CFoundation_CDateTime;

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__






typedef enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationAudioLooping __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationAudioLooping;


typedef enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationButtonStyle __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationButtonStyle;


typedef enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationDuration __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationDuration;


typedef enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationImageCrop __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationImageCrop;


typedef enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationScenario __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationScenario;


typedef enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationSoundEvent __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationSoundEvent;





















/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationAudioLooping
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationAudioLooping
{
    AppNotificationAudioLooping_None = 0,
    AppNotificationAudioLooping_Loop = 1,
};
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationButtonStyle
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationButtonStyle
{
    AppNotificationButtonStyle_Default = 0,
    AppNotificationButtonStyle_Success = 1,
    AppNotificationButtonStyle_Critical = 2,
};
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationDuration
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationDuration
{
    AppNotificationDuration_Default = 0,
    AppNotificationDuration_Long = 1,
};
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationImageCrop
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationImageCrop
{
    AppNotificationImageCrop_Default = 0,
    AppNotificationImageCrop_Circle = 1,
};
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationScenario
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationScenario
{
    AppNotificationScenario_Default = 0,
    AppNotificationScenario_Reminder = 1,
    AppNotificationScenario_Alarm = 2,
    AppNotificationScenario_IncomingCall = 3,
    AppNotificationScenario_Urgent = 4,
};
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Struct Microsoft.Windows.AppNotifications.Builder.AppNotificationSoundEvent
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationSoundEvent
{
    AppNotificationSoundEvent_Default = 0,
    AppNotificationSoundEvent_IM = 1,
    AppNotificationSoundEvent_Mail = 2,
    AppNotificationSoundEvent_Reminder = 3,
    AppNotificationSoundEvent_SMS = 4,
    AppNotificationSoundEvent_Alarm = 5,
    AppNotificationSoundEvent_Alarm2 = 6,
    AppNotificationSoundEvent_Alarm3 = 7,
    AppNotificationSoundEvent_Alarm4 = 8,
    AppNotificationSoundEvent_Alarm5 = 9,
    AppNotificationSoundEvent_Alarm6 = 10,
    AppNotificationSoundEvent_Alarm7 = 11,
    AppNotificationSoundEvent_Alarm8 = 12,
    AppNotificationSoundEvent_Alarm9 = 13,
    AppNotificationSoundEvent_Alarm10 = 14,
    AppNotificationSoundEvent_Call = 15,
    AppNotificationSoundEvent_Call2 = 16,
    AppNotificationSoundEvent_Call3 = 17,
    AppNotificationSoundEvent_Call4 = 18,
    AppNotificationSoundEvent_Call5 = 19,
    AppNotificationSoundEvent_Call6 = 20,
    AppNotificationSoundEvent_Call7 = 21,
    AppNotificationSoundEvent_Call8 = 22,
    AppNotificationSoundEvent_Call9 = 23,
    AppNotificationSoundEvent_Call10 = 24,
};
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilder
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilder
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationBuilder[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilder";
/* [object, uuid("E801D31F-CE03-505C-ADEC-8A02724EC9DE"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *AddArgument )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING key,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetTimeStamp )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CDateTime value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetDuration )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationDuration duration,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetScenario )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationScenario value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *AddText )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING text,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *AddText2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING text,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * properties,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAttributionText )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING text,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAttributionText2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING text,
        /* [in] */HSTRING language,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetInlineImage )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * imageUri,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetInlineImage2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * imageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationImageCrop imageCrop,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetInlineImage3 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * imageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationImageCrop imagecrop,
        /* [in] */HSTRING alternateText,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAppLogoOverride )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * imageUri,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAppLogoOverride2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * imageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationImageCrop imageCrop,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAppLogoOverride3 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * imageUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationImageCrop imageCrop,
        /* [in] */HSTRING alternateText,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetHeroImage )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * imageUri,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetHeroImage2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * imageUri,
        /* [in] */HSTRING alternateText,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAudioUri )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * audioUri,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAudioUri2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * audioUri,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationAudioLooping loop,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAudioEvent )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationSoundEvent appNotificationSoundEvent,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetAudioEvent2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationSoundEvent appNotificationSoundEvent,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationAudioLooping loop,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *MuteAudio )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *AddTextBox )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING id,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *AddTextBox2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING id,
        /* [in] */HSTRING placeHolderText,
        /* [in] */HSTRING title,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *AddButton )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *AddComboBox )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *AddProgressBar )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *BuildNotification )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CIAppNotification * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetTag )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetGroup )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * This,
        /* [in] */HSTRING group,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddArgument(This,key,value,result) \
    ( (This)->lpVtbl->AddArgument(This,key,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetTimeStamp(This,value,result) \
    ( (This)->lpVtbl->SetTimeStamp(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetDuration(This,duration,result) \
    ( (This)->lpVtbl->SetDuration(This,duration,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetScenario(This,value,result) \
    ( (This)->lpVtbl->SetScenario(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddText(This,text,result) \
    ( (This)->lpVtbl->AddText(This,text,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddText2(This,text,properties,result) \
    ( (This)->lpVtbl->AddText2(This,text,properties,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAttributionText(This,text,result) \
    ( (This)->lpVtbl->SetAttributionText(This,text,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAttributionText2(This,text,language,result) \
    ( (This)->lpVtbl->SetAttributionText2(This,text,language,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetInlineImage(This,imageUri,result) \
    ( (This)->lpVtbl->SetInlineImage(This,imageUri,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetInlineImage2(This,imageUri,imageCrop,result) \
    ( (This)->lpVtbl->SetInlineImage2(This,imageUri,imageCrop,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetInlineImage3(This,imageUri,imagecrop,alternateText,result) \
    ( (This)->lpVtbl->SetInlineImage3(This,imageUri,imagecrop,alternateText,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAppLogoOverride(This,imageUri,result) \
    ( (This)->lpVtbl->SetAppLogoOverride(This,imageUri,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAppLogoOverride2(This,imageUri,imageCrop,result) \
    ( (This)->lpVtbl->SetAppLogoOverride2(This,imageUri,imageCrop,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAppLogoOverride3(This,imageUri,imageCrop,alternateText,result) \
    ( (This)->lpVtbl->SetAppLogoOverride3(This,imageUri,imageCrop,alternateText,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetHeroImage(This,imageUri,result) \
    ( (This)->lpVtbl->SetHeroImage(This,imageUri,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetHeroImage2(This,imageUri,alternateText,result) \
    ( (This)->lpVtbl->SetHeroImage2(This,imageUri,alternateText,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAudioUri(This,audioUri,result) \
    ( (This)->lpVtbl->SetAudioUri(This,audioUri,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAudioUri2(This,audioUri,loop,result) \
    ( (This)->lpVtbl->SetAudioUri2(This,audioUri,loop,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAudioEvent(This,appNotificationSoundEvent,result) \
    ( (This)->lpVtbl->SetAudioEvent(This,appNotificationSoundEvent,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetAudioEvent2(This,appNotificationSoundEvent,loop,result) \
    ( (This)->lpVtbl->SetAudioEvent2(This,appNotificationSoundEvent,loop,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_MuteAudio(This,result) \
    ( (This)->lpVtbl->MuteAudio(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddTextBox(This,id,result) \
    ( (This)->lpVtbl->AddTextBox(This,id,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddTextBox2(This,id,placeHolderText,title,result) \
    ( (This)->lpVtbl->AddTextBox2(This,id,placeHolderText,title,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddButton(This,value,result) \
    ( (This)->lpVtbl->AddButton(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddComboBox(This,value,result) \
    ( (This)->lpVtbl->AddComboBox(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_AddProgressBar(This,value,result) \
    ( (This)->lpVtbl->AddProgressBar(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_BuildNotification(This,result) \
    ( (This)->lpVtbl->BuildNotification(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetTag(This,value,result) \
    ( (This)->lpVtbl->SetTag(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_SetGroup(This,group,result) \
    ( (This)->lpVtbl->SetGroup(This,group,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilder_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilderStatics
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilder
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationBuilderStatics[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilderStatics";
/* [object, uuid("C7042D2A-D319-520E-A314-50081C8888CC"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *IsUrgentScenarioSupported )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics * This,
        /* [retval, out] */boolean * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_IsUrgentScenarioSupported(This,result) \
    ( (This)->lpVtbl->IsUrgentScenarioSupported(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationBuilderStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationButton
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationButton
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationButton[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationButton";
/* [object, uuid("A7C03031-5634-5098-AEC9-47ECB60C3499"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Content )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Content )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Arguments )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */__FIMap_2_HSTRING_HSTRING * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Arguments )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */__FIMap_2_HSTRING_HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Icon )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Icon )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ToolTip )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ToolTip )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ContextMenuPlacement )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ContextMenuPlacement )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ButtonStyle )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationButtonStyle * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ButtonStyle )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationButtonStyle value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InputId )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_InputId )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InvokeUri )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_InvokeUri )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_TargetAppId )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_TargetAppId )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */HSTRING value
        );
    HRESULT ( STDMETHODCALLTYPE *AddArgument )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */HSTRING key,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetIcon )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetToolTip )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetContextMenuPlacement )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetButtonStyle )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CAppNotificationButtonStyle value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetInputId )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetInvokeUri )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * protocolUri,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *SetInvokeUri2 )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * protocolUri,
        /* [in] */HSTRING targetAppId,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_Content(This,value) \
    ( (This)->lpVtbl->get_Content(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_Content(This,value) \
    ( (This)->lpVtbl->put_Content(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_Arguments(This,value) \
    ( (This)->lpVtbl->get_Arguments(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_Arguments(This,value) \
    ( (This)->lpVtbl->put_Arguments(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_Icon(This,value) \
    ( (This)->lpVtbl->get_Icon(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_Icon(This,value) \
    ( (This)->lpVtbl->put_Icon(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_ToolTip(This,value) \
    ( (This)->lpVtbl->get_ToolTip(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_ToolTip(This,value) \
    ( (This)->lpVtbl->put_ToolTip(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_ContextMenuPlacement(This,value) \
    ( (This)->lpVtbl->get_ContextMenuPlacement(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_ContextMenuPlacement(This,value) \
    ( (This)->lpVtbl->put_ContextMenuPlacement(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_ButtonStyle(This,value) \
    ( (This)->lpVtbl->get_ButtonStyle(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_ButtonStyle(This,value) \
    ( (This)->lpVtbl->put_ButtonStyle(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_InputId(This,value) \
    ( (This)->lpVtbl->get_InputId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_InputId(This,value) \
    ( (This)->lpVtbl->put_InputId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_InvokeUri(This,value) \
    ( (This)->lpVtbl->get_InvokeUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_InvokeUri(This,value) \
    ( (This)->lpVtbl->put_InvokeUri(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_get_TargetAppId(This,value) \
    ( (This)->lpVtbl->get_TargetAppId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_put_TargetAppId(This,value) \
    ( (This)->lpVtbl->put_TargetAppId(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_AddArgument(This,key,value,result) \
    ( (This)->lpVtbl->AddArgument(This,key,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_SetIcon(This,value,result) \
    ( (This)->lpVtbl->SetIcon(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_SetToolTip(This,value,result) \
    ( (This)->lpVtbl->SetToolTip(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_SetContextMenuPlacement(This,result) \
    ( (This)->lpVtbl->SetContextMenuPlacement(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_SetButtonStyle(This,value,result) \
    ( (This)->lpVtbl->SetButtonStyle(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_SetInputId(This,value,result) \
    ( (This)->lpVtbl->SetInputId(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_SetInvokeUri(This,protocolUri,result) \
    ( (This)->lpVtbl->SetInvokeUri(This,protocolUri,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_SetInvokeUri2(This,protocolUri,targetAppId,result) \
    ( (This)->lpVtbl->SetInvokeUri2(This,protocolUri,targetAppId,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonFactory
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationButton
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationButtonFactory[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonFactory";
/* [object, uuid("4F109286-0A6D-5A5E-9E8F-9FE31669FBB8"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory * This,
        /* [in] */HSTRING content,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButton * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_CreateInstance(This,content,value) \
    ( (This)->lpVtbl->CreateInstance(This,content,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonStatics
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationButton
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationButtonStatics[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonStatics";
/* [object, uuid("FEAD7C18-4144-59A4-9611-86B7E8191853"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *IsToolTipSupported )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics * This,
        /* [retval, out] */boolean * result
        );
    HRESULT ( STDMETHODCALLTYPE *IsButtonStyleSupported )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics * This,
        /* [retval, out] */boolean * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_IsToolTipSupported(This,result) \
    ( (This)->lpVtbl->IsToolTipSupported(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_IsButtonStyleSupported(This,result) \
    ( (This)->lpVtbl->IsButtonStyleSupported(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationButtonStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBox
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationComboBox
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationComboBox[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBox";
/* [object, uuid("4547C9E2-4815-538C-BE26-040CE17F8B62"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Items )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [retval, out] */__FIMap_2_HSTRING_HSTRING * * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Items )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [in] */__FIMap_2_HSTRING_HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Title )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Title )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SelectedItem )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_SelectedItem )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [in] */HSTRING value
        );
    HRESULT ( STDMETHODCALLTYPE *AddItem )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [in] */HSTRING id,
        /* [in] */HSTRING content,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetTitle )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetSelectedItem )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * This,
        /* [in] */HSTRING id,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_get_Items(This,value) \
    ( (This)->lpVtbl->get_Items(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_put_Items(This,value) \
    ( (This)->lpVtbl->put_Items(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_get_Title(This,value) \
    ( (This)->lpVtbl->get_Title(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_put_Title(This,value) \
    ( (This)->lpVtbl->put_Title(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_get_SelectedItem(This,value) \
    ( (This)->lpVtbl->get_SelectedItem(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_put_SelectedItem(This,value) \
    ( (This)->lpVtbl->put_SelectedItem(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_AddItem(This,id,content,result) \
    ( (This)->lpVtbl->AddItem(This,id,content,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_SetTitle(This,value,result) \
    ( (This)->lpVtbl->SetTitle(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_SetSelectedItem(This,id,result) \
    ( (This)->lpVtbl->SetSelectedItem(This,id,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBoxFactory
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationComboBox
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationComboBoxFactory[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBoxFactory";
/* [object, uuid("1B31B5B0-9D86-59ED-8629-A79498AB5D4B"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory * This,
        /* [in] */HSTRING id,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBox * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_CreateInstance(This,id,value) \
    ( (This)->lpVtbl->CreateInstance(This,id,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationComboBoxFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationProgressBar
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationProgressBar
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationProgressBar[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationProgressBar";
/* [object, uuid("FCED62F2-2074-5641-8630-87A14315AC86"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBarVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Title )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Title )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Status )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Status )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Value )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [retval, out] */DOUBLE * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Value )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [in] */DOUBLE value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ValueStringOverride )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ValueStringOverride )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [in] */HSTRING value
        );
    HRESULT ( STDMETHODCALLTYPE *SetTitle )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * * result
        );
    HRESULT ( STDMETHODCALLTYPE *BindTitle )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetStatus )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * * result
        );
    HRESULT ( STDMETHODCALLTYPE *BindStatus )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetValue )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [in] */DOUBLE value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * * result
        );
    HRESULT ( STDMETHODCALLTYPE *BindValue )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetValueStringOverride )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * * result
        );
    HRESULT ( STDMETHODCALLTYPE *BindValueStringOverride )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBarVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBarVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_get_Title(This,value) \
    ( (This)->lpVtbl->get_Title(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_put_Title(This,value) \
    ( (This)->lpVtbl->put_Title(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_get_Status(This,value) \
    ( (This)->lpVtbl->get_Status(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_put_Status(This,value) \
    ( (This)->lpVtbl->put_Status(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_get_Value(This,value) \
    ( (This)->lpVtbl->get_Value(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_put_Value(This,value) \
    ( (This)->lpVtbl->put_Value(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_get_ValueStringOverride(This,value) \
    ( (This)->lpVtbl->get_ValueStringOverride(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_put_ValueStringOverride(This,value) \
    ( (This)->lpVtbl->put_ValueStringOverride(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_SetTitle(This,value,result) \
    ( (This)->lpVtbl->SetTitle(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_BindTitle(This,result) \
    ( (This)->lpVtbl->BindTitle(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_SetStatus(This,value,result) \
    ( (This)->lpVtbl->SetStatus(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_BindStatus(This,result) \
    ( (This)->lpVtbl->BindStatus(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_SetValue(This,value,result) \
    ( (This)->lpVtbl->SetValue(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_BindValue(This,result) \
    ( (This)->lpVtbl->BindValue(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_SetValueStringOverride(This,value,result) \
    ( (This)->lpVtbl->SetValueStringOverride(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_BindValueStringOverride(This,result) \
    ( (This)->lpVtbl->BindValueStringOverride(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationProgressBar_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.AppNotifications.Builder.IAppNotificationTextProperties
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.AppNotifications.Builder.AppNotificationTextProperties
 *
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_AppNotifications_Builder_IAppNotificationTextProperties[] = L"Microsoft.Windows.AppNotifications.Builder.IAppNotificationTextProperties";
/* [object, uuid("23A30D0B-5258-5853-932E-9521A3642AFB"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextPropertiesVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Language )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_Language )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [in] */HSTRING value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IncomingCallAlignment )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_IncomingCallAlignment )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [in] */boolean value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_MaxLines )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [retval, out] */INT32 * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_MaxLines )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [in] */INT32 value
        );
    HRESULT ( STDMETHODCALLTYPE *SetLanguage )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [in] */HSTRING value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetIncomingCallAlignment )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetMaxLines )(
        __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * This,
        /* [in] */INT32 value,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextPropertiesVtbl;

interface __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextPropertiesVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_get_Language(This,value) \
    ( (This)->lpVtbl->get_Language(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_put_Language(This,value) \
    ( (This)->lpVtbl->put_Language(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_get_IncomingCallAlignment(This,value) \
    ( (This)->lpVtbl->get_IncomingCallAlignment(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_put_IncomingCallAlignment(This,value) \
    ( (This)->lpVtbl->put_IncomingCallAlignment(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_get_MaxLines(This,value) \
    ( (This)->lpVtbl->get_MaxLines(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_put_MaxLines(This,value) \
    ( (This)->lpVtbl->put_MaxLines(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_SetLanguage(This,value,result) \
    ( (This)->lpVtbl->SetLanguage(This,value,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_SetIncomingCallAlignment(This,result) \
    ( (This)->lpVtbl->SetIncomingCallAlignment(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_SetMaxLines(This,value,result) \
    ( (This)->lpVtbl->SetMaxLines(This,value,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CAppNotifications_CBuilder_CIAppNotificationTextProperties_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilder
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilderStatics interface starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationBuilder ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationBuilder_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationBuilder_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationBuilder[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilder";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationButton
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonFactory interface starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.AppNotifications.Builder.IAppNotificationButtonStatics interface starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationButton ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationButton_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationButton_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationButton[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationButton";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationComboBox
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBoxFactory interface starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationComboBox ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationComboBox_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationComboBox_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationComboBox[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationComboBox";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationProgressBar
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationProgressBar ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationProgressBar_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationProgressBar_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationProgressBar[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationProgressBar";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.AppNotifications.Builder.AppNotificationTextProperties
 *
 * Introduced to Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.AppNotifications.Builder.AppNotificationBuilderContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.AppNotifications.Builder.IAppNotificationTextProperties ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationTextProperties_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_AppNotifications_Builder_AppNotificationTextProperties_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_AppNotifications_Builder_AppNotificationTextProperties[] = L"Microsoft.Windows.AppNotifications.Builder.AppNotificationTextProperties";
#endif
#endif // MICROSOFT_WINDOWS_APPNOTIFICATIONS_BUILDER_APPNOTIFICATIONBUILDERCONTRACT_VERSION >= 0x10000





#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Eappnotifications2Ebuilder_p_h__

#endif // __microsoft2Ewindows2Eappnotifications2Ebuilder_h__

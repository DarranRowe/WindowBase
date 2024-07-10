
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
#ifndef __microsoft2Ewindows2Eapplicationmodel2Eresources_h__
#define __microsoft2Ewindows2Eapplicationmodel2Eresources_h__
#ifndef __microsoft2Ewindows2Eapplicationmodel2Eresources_p_h__
#define __microsoft2Ewindows2Eapplicationmodel2Eresources_p_h__


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
#if !defined(MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION)
#define MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION 0x10000
#endif // defined(MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION)

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
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IKnownResourceQualifierNameStatics;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics ABI::Microsoft::Windows::ApplicationModel::Resources::IKnownResourceQualifierNameStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceCandidate;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceCandidateFactory;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidateFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceContext;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceContext

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceContext2;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2 ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceContext2

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceLoader;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceLoader

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceLoaderFactory;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceLoaderFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceLoaderStatics;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceLoaderStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceManager;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceManager

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceManager2;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2 ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceManager2

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceManagerFactory;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceManagerFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceMap;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceMap

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    interface IResourceNotFoundEventArgs;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceNotFoundEventArgs

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    class ResourceCandidate;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_USE
#define DEF___FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("6a46de21-86a6-536a-937b-1edfa3e16474"))
IKeyValuePair<HSTRING,ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceCandidate*> : IKeyValuePair_impl<HSTRING,ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceCandidate*, ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IKeyValuePair`2<String, Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IKeyValuePair<HSTRING,ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceCandidate*> __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_t;
#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate ABI::Windows::Foundation::Collections::__FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING,ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate*>
//#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_t ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING,ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_USE */


#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    class ResourceManager;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    class ResourceNotFoundEventArgs;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_USE
#define DEF___FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("30bb9803-2b8a-58e0-8812-93967822d6d0"))
ITypedEventHandler<ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceManager*,ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceNotFoundEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceManager*, ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceManager*>,ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceNotFoundEventArgs*, ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceNotFoundEventArgs*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.TypedEventHandler`2<Microsoft.Windows.ApplicationModel.Resources.ResourceManager, Microsoft.Windows.ApplicationModel.Resources.ResourceNotFoundEventArgs>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceManager*,ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceNotFoundEventArgs*> __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_t;
#define __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceManager*,ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceNotFoundEventArgs*>
//#define __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_t ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceManager*,ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceNotFoundEventArgs*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_USE */


#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


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
            namespace ApplicationModel {
                namespace Resources {
                    
                    typedef enum ResourceCandidateKind : int ResourceCandidateKind;
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
















namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    class ResourceContext;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */


namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    class ResourceLoader;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */



namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    class ResourceMap;
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */














/*
 *
 * Struct Microsoft.Windows.ApplicationModel.Resources.ResourceCandidateKind
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [v1_enum, contract] */
                    enum ResourceCandidateKind : int
                    {
                        ResourceCandidateKind_Unknown = 0,
                        ResourceCandidateKind_String = 1,
                        ResourceCandidateKind_FilePath = 2,
                        ResourceCandidateKind_EmbeddedData = 3,
                    };
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IKnownResourceQualifierNameStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.KnownResourceQualifierName
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IKnownResourceQualifierNameStatics[] = L"Microsoft.Windows.ApplicationModel.Resources.IKnownResourceQualifierNameStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("DD6CDEDC-559B-50C8-AC53-82FE21F915F3"), exclusiveto, contract] */
                    MIDL_INTERFACE("DD6CDEDC-559B-50C8-AC53-82FE21F915F3")
                    IKnownResourceQualifierNameStatics : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Contrast(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Custom(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DeviceFamily(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_HomeRegion(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Language(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LayoutDirection(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Scale(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_TargetSize(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Theme(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IKnownResourceQualifierNameStatics=_uuidof(IKnownResourceQualifierNameStatics);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceCandidate
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceCandidate[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceCandidate";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("6C54BC0C-EF1E-57B8-B478-34FECE737356"), exclusiveto, contract] */
                    MIDL_INTERFACE("6C54BC0C-EF1E-57B8-B478-34FECE737356")
                    IResourceCandidate : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ValueAsString(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ValueAsBytes(
                            /* [out] */UINT32 * __valueSize,
                            /* [size_is(, *(__valueSize)), retval, out] */BYTE * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Kind(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceCandidateKind * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_QualifierValues(
                            /* [retval, out] */__FIMapView_2_HSTRING_HSTRING * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceCandidate=_uuidof(IResourceCandidate);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceCandidateFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceCandidateFactory[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceCandidateFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("BB2B30F8-C19B-5F43-88D9-69AD728A32F4"), exclusiveto, contract] */
                    MIDL_INTERFACE("BB2B30F8-C19B-5F43-88D9-69AD728A32F4")
                    IResourceCandidateFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::Resources::ResourceCandidateKind kind,
                            /* [in] */HSTRING data,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate * * value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance2(
                            /* [in] */UINT32 __dataSize,
                            /* [size_is(__dataSize), in] */BYTE * data,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceCandidateFactory=_uuidof(IResourceCandidateFactory);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceContext
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceContext[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceContext";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("96FB48DC-F77D-55FF-AF12-34861E3D4939"), contract] */
                    MIDL_INTERFACE("96FB48DC-F77D-55FF-AF12-34861E3D4939")
                    IResourceContext : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_QualifierValues(
                            /* [retval, out] */__FIMap_2_HSTRING_HSTRING * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceContext=_uuidof(IResourceContext);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceContext2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceContext
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceContext2[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceContext2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("7A3B1158-798C-5949-969D-03510B9CE6CA"), exclusiveto, contract] */
                    MIDL_INTERFACE("7A3B1158-798C-5949-969D-03510B9CE6CA")
                    IResourceContext2 : public IInspectable
                    {
                    public:
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceContext2=_uuidof(IResourceContext2);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceLoader
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceLoader
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceLoader[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceLoader";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("BC3F76BF-DA46-54CD-8715-8B8AAF16EAAC"), exclusiveto, contract] */
                    MIDL_INTERFACE("BC3F76BF-DA46-54CD-8715-8B8AAF16EAAC")
                    IResourceLoader : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetString(
                            /* [in] */HSTRING resourceId,
                            /* [retval, out] */HSTRING * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetStringForUri(
                            /* [in] */ABI::Windows::Foundation::IUriRuntimeClass * resourceUri,
                            /* [retval, out] */HSTRING * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceLoader=_uuidof(IResourceLoader);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceLoader
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceLoaderFactory[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("871F83AA-FB34-50D6-B9B9-2C35F3FFC004"), exclusiveto, contract] */
                    MIDL_INTERFACE("871F83AA-FB34-50D6-B9B9-2C35F3FFC004")
                    IResourceLoaderFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */HSTRING fileName,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceLoader * * value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance2(
                            /* [in] */HSTRING fileName,
                            /* [in] */HSTRING resourceMap,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceLoader * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceLoaderFactory=_uuidof(IResourceLoaderFactory);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceLoader
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceLoaderStatics[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("EC9C894A-1466-5F2F-8EEE-A70CBD2B51BB"), exclusiveto, contract] */
                    MIDL_INTERFACE("EC9C894A-1466-5F2F-8EEE-A70CBD2B51BB")
                    IResourceLoaderStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetDefaultResourceFilePath(
                            /* [retval, out] */HSTRING * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceLoaderStatics=_uuidof(IResourceLoaderStatics);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceManager
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceManager[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceManager";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("AC2291EF-81BE-5C99-A0AE-BCEE0180B8A8"), contract] */
                    MIDL_INTERFACE("AC2291EF-81BE-5C99-A0AE-BCEE0180B8A8")
                    IResourceManager : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_MainResourceMap(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceMap * * value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateResourceContext(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceContext * * result
                            ) = 0;
                        /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_ResourceNotFound(
                            /* [in] */__FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs * handler,
                            /* [retval, out] */EventRegistrationToken * token
                            ) = 0;
                        /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_ResourceNotFound(
                            /* [in] */EventRegistrationToken token
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceManager=_uuidof(IResourceManager);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceManager2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceManager2[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceManager2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("7EC10160-A154-5C42-8268-30E306B1F585"), exclusiveto, contract] */
                    MIDL_INTERFACE("7EC10160-A154-5C42-8268-30E306B1F585")
                    IResourceManager2 : public IInspectable
                    {
                    public:
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceManager2=_uuidof(IResourceManager2);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceManagerFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceManagerFactory[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceManagerFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("D6ACF18F-458A-535B-A5C4-AC2DC4E49099"), exclusiveto, contract] */
                    MIDL_INTERFACE("D6ACF18F-458A-535B-A5C4-AC2DC4E49099")
                    IResourceManagerFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */HSTRING fileName,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceManager * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceManagerFactory=_uuidof(IResourceManagerFactory);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceMap
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceMap
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceMap[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceMap";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("4ABBD9BC-DF4E-5C7B-812C-7E7BB0C22377"), exclusiveto, contract] */
                    MIDL_INTERFACE("4ABBD9BC-DF4E-5C7B-812C-7E7BB0C22377")
                    IResourceMap : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ResourceCount(
                            /* [retval, out] */UINT32 * value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetSubtree(
                            /* [in] */HSTRING reference,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceMap * * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE TryGetSubtree(
                            /* [in] */HSTRING reference,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceMap * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE GetValue(
                            /* [in] */HSTRING resource,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE GetValueWithContext(
                            /* [in] */HSTRING resource,
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceContext * context,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE GetValueByIndex(
                            /* [in] */UINT32 index,
                            /* [retval, out] */__FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE GetValueByIndexWithContext(
                            /* [in] */UINT32 index,
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceContext * context,
                            /* [retval, out] */__FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE TryGetValue(
                            /* [in] */HSTRING resource,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE TryGetValueWithContext(
                            /* [in] */HSTRING resource,
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceContext * context,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceMap=_uuidof(IResourceMap);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceNotFoundEventArgs
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceNotFoundEventArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceNotFoundEventArgs[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceNotFoundEventArgs";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace Resources {
                    /* [object, uuid("64ABB08B-E77D-5B26-830F-15941E0E8200"), exclusiveto, contract] */
                    MIDL_INTERFACE("64ABB08B-E77D-5B26-830F-15941E0E8200")
                    IResourceNotFoundEventArgs : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Context(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceContext * * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Name(
                            /* [retval, out] */HSTRING * value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetResolvedCandidate(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::Resources::IResourceCandidate * candidate
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IResourceNotFoundEventArgs=_uuidof(IResourceNotFoundEventArgs);
                    
                } /* Resources */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.KnownResourceQualifierName
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.Resources.IKnownResourceQualifierNameStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_KnownResourceQualifierName_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_KnownResourceQualifierName_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_KnownResourceQualifierName[] = L"Microsoft.Windows.ApplicationModel.Resources.KnownResourceQualifierName";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.Resources.IResourceCandidateFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceCandidate ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceCandidate_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceCandidate_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceCandidate[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceContext
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceContext2
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceContext ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceContext_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceContext[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceContext";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceLoader
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceLoader ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceLoader_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceLoader_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceLoader[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceLoader";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceManager
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.Resources.IResourceManagerFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceManager2
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceManager[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceManager";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceMap
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceMap ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceMap_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceMap_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceMap[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceMap";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceNotFoundEventArgs
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceNotFoundEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceNotFoundEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceNotFoundEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceNotFoundEventArgs[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceNotFoundEventArgs";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2 __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2 __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_INTERFACE_DEFINED__)
#define ____FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_INTERFACE_DEFINED__

typedef interface __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate;

typedef struct __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidateVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * This,
            /* [out] */ __RPC__out ULONG *iidCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )(__RPC__in __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * This, /* [retval][out] */ __RPC__out HSTRING *key);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )(__RPC__in __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * This, /* [retval][out] */ __RPC__deref_out_opt __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * *value);
    END_INTERFACE
} __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidateVtbl;

interface __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate
{
    CONST_VTBL struct __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidateVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_get_Key(This,key)	\
    ( (This)->lpVtbl -> get_Key(This,key) ) 

#define __FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_get_Value(This,value)	\
    ( (This)->lpVtbl -> get_Value(This,value) ) 
#endif /* COBJMACROS */


#endif // ____FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000



#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs;

typedef struct __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs * This,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * sender,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * e);
    END_INTERFACE
} __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgsVtbl;

interface __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */



#endif // ____FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs_INTERFACE_DEFINED__

#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

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



#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__






typedef enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CResourceCandidateKind __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CResourceCandidateKind;
































/*
 *
 * Struct Microsoft.Windows.ApplicationModel.Resources.ResourceCandidateKind
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CResourceCandidateKind
{
    ResourceCandidateKind_Unknown = 0,
    ResourceCandidateKind_String = 1,
    ResourceCandidateKind_FilePath = 2,
    ResourceCandidateKind_EmbeddedData = 3,
};
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IKnownResourceQualifierNameStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.KnownResourceQualifierName
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IKnownResourceQualifierNameStatics[] = L"Microsoft.Windows.ApplicationModel.Resources.IKnownResourceQualifierNameStatics";
/* [object, uuid("DD6CDEDC-559B-50C8-AC53-82FE21F915F3"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Contrast )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Custom )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DeviceFamily )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_HomeRegion )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Language )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LayoutDirection )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Scale )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_TargetSize )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Theme )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_Contrast(This,value) \
    ( (This)->lpVtbl->get_Contrast(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_Custom(This,value) \
    ( (This)->lpVtbl->get_Custom(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_DeviceFamily(This,value) \
    ( (This)->lpVtbl->get_DeviceFamily(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_HomeRegion(This,value) \
    ( (This)->lpVtbl->get_HomeRegion(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_Language(This,value) \
    ( (This)->lpVtbl->get_Language(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_LayoutDirection(This,value) \
    ( (This)->lpVtbl->get_LayoutDirection(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_Scale(This,value) \
    ( (This)->lpVtbl->get_Scale(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_TargetSize(This,value) \
    ( (This)->lpVtbl->get_TargetSize(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_get_Theme(This,value) \
    ( (This)->lpVtbl->get_Theme(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIKnownResourceQualifierNameStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceCandidate
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceCandidate[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceCandidate";
/* [object, uuid("6C54BC0C-EF1E-57B8-B478-34FECE737356"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ValueAsString )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ValueAsBytes )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This,
        /* [out] */UINT32 * __valueSize,
        /* [size_is(, *(__valueSize)), retval, out] */BYTE * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Kind )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CResourceCandidateKind * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_QualifierValues )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * This,
        /* [retval, out] */__FIMapView_2_HSTRING_HSTRING * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_get_ValueAsString(This,value) \
    ( (This)->lpVtbl->get_ValueAsString(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_get_ValueAsBytes(This,__valueSize,value) \
    ( (This)->lpVtbl->get_ValueAsBytes(This,__valueSize,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_get_Kind(This,value) \
    ( (This)->lpVtbl->get_Kind(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_get_QualifierValues(This,value) \
    ( (This)->lpVtbl->get_QualifierValues(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceCandidateFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceCandidateFactory[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceCandidateFactory";
/* [object, uuid("BB2B30F8-C19B-5F43-88D9-69AD728A32F4"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CResourceCandidateKind kind,
        /* [in] */HSTRING data,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * * value
        );
    HRESULT ( STDMETHODCALLTYPE *CreateInstance2 )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory * This,
        /* [in] */UINT32 __dataSize,
        /* [size_is(__dataSize), in] */BYTE * data,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_CreateInstance(This,kind,data,value) \
    ( (This)->lpVtbl->CreateInstance(This,kind,data,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_CreateInstance2(This,__dataSize,data,value) \
    ( (This)->lpVtbl->CreateInstance2(This,__dataSize,data,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidateFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceContext
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceContext[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceContext";
/* [object, uuid("96FB48DC-F77D-55FF-AF12-34861E3D4939"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContextVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_QualifierValues )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * This,
        /* [retval, out] */__FIMap_2_HSTRING_HSTRING * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContextVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContextVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_get_QualifierValues(This,value) \
    ( (This)->lpVtbl->get_QualifierValues(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceContext2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceContext
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceContext2[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceContext2";
/* [object, uuid("7A3B1158-798C-5949-969D-03510B9CE6CA"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceLoader
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceLoader
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceLoader[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceLoader";
/* [object, uuid("BC3F76BF-DA46-54CD-8715-8B8AAF16EAAC"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetString )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * This,
        /* [in] */HSTRING resourceId,
        /* [retval, out] */HSTRING * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetStringForUri )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * This,
        /* [in] */__x_ABI_CWindows_CFoundation_CIUriRuntimeClass * resourceUri,
        /* [retval, out] */HSTRING * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_GetString(This,resourceId,result) \
    ( (This)->lpVtbl->GetString(This,resourceId,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_GetStringForUri(This,resourceUri,result) \
    ( (This)->lpVtbl->GetStringForUri(This,resourceUri,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceLoader
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceLoaderFactory[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderFactory";
/* [object, uuid("871F83AA-FB34-50D6-B9B9-2C35F3FFC004"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory * This,
        /* [in] */HSTRING fileName,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * * value
        );
    HRESULT ( STDMETHODCALLTYPE *CreateInstance2 )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory * This,
        /* [in] */HSTRING fileName,
        /* [in] */HSTRING resourceMap,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoader * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_CreateInstance(This,fileName,value) \
    ( (This)->lpVtbl->CreateInstance(This,fileName,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_CreateInstance2(This,fileName,resourceMap,value) \
    ( (This)->lpVtbl->CreateInstance2(This,fileName,resourceMap,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceLoader
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceLoaderStatics[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderStatics";
/* [object, uuid("EC9C894A-1466-5F2F-8EEE-A70CBD2B51BB"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetDefaultResourceFilePath )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics * This,
        /* [retval, out] */HSTRING * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_GetDefaultResourceFilePath(This,result) \
    ( (This)->lpVtbl->GetDefaultResourceFilePath(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceLoaderStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceManager
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceManager[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceManager";
/* [object, uuid("AC2291EF-81BE-5C99-A0AE-BCEE0180B8A8"), contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_MainResourceMap )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * * value
        );
    HRESULT ( STDMETHODCALLTYPE *CreateResourceContext )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * * result
        );
    /* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_ResourceNotFound )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This,
        /* [in] */__FITypedEventHandler_2_Microsoft__CWindows__CApplicationModel__CResources__CResourceManager_Microsoft__CWindows__CApplicationModel__CResources__CResourceNotFoundEventArgs * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_ResourceNotFound )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * This,
        /* [in] */EventRegistrationToken token
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_get_MainResourceMap(This,value) \
    ( (This)->lpVtbl->get_MainResourceMap(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_CreateResourceContext(This,result) \
    ( (This)->lpVtbl->CreateResourceContext(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_add_ResourceNotFound(This,handler,token) \
    ( (This)->lpVtbl->add_ResourceNotFound(This,handler,token) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_remove_ResourceNotFound(This,token) \
    ( (This)->lpVtbl->remove_ResourceNotFound(This,token) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceManager2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceManager2[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceManager2";
/* [object, uuid("7EC10160-A154-5C42-8268-30E306B1F585"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceManagerFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceManagerFactory[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceManagerFactory";
/* [object, uuid("D6ACF18F-458A-535B-A5C4-AC2DC4E49099"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory * This,
        /* [in] */HSTRING fileName,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManager * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_CreateInstance(This,fileName,value) \
    ( (This)->lpVtbl->CreateInstance(This,fileName,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceManagerFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceMap
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceMap
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceMap[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceMap";
/* [object, uuid("4ABBD9BC-DF4E-5C7B-812C-7E7BB0C22377"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMapVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ResourceCount )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [retval, out] */UINT32 * value
        );
    HRESULT ( STDMETHODCALLTYPE *GetSubtree )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [in] */HSTRING reference,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * * result
        );
    HRESULT ( STDMETHODCALLTYPE *TryGetSubtree )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [in] */HSTRING reference,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *GetValue )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [in] */HSTRING resource,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *GetValueWithContext )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [in] */HSTRING resource,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * context,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *GetValueByIndex )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [in] */UINT32 index,
        /* [retval, out] */__FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *GetValueByIndexWithContext )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [in] */UINT32 index,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * context,
        /* [retval, out] */__FIKeyValuePair_2_HSTRING_Microsoft__CWindows__CApplicationModel__CResources__CResourceCandidate * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *TryGetValue )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [in] */HSTRING resource,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *TryGetValueWithContext )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap * This,
        /* [in] */HSTRING resource,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * context,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMapVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMapVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_get_ResourceCount(This,value) \
    ( (This)->lpVtbl->get_ResourceCount(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_GetSubtree(This,reference,result) \
    ( (This)->lpVtbl->GetSubtree(This,reference,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_TryGetSubtree(This,reference,result) \
    ( (This)->lpVtbl->TryGetSubtree(This,reference,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_GetValue(This,resource,result) \
    ( (This)->lpVtbl->GetValue(This,resource,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_GetValueWithContext(This,resource,context,result) \
    ( (This)->lpVtbl->GetValueWithContext(This,resource,context,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_GetValueByIndex(This,index,result) \
    ( (This)->lpVtbl->GetValueByIndex(This,index,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_GetValueByIndexWithContext(This,index,context,result) \
    ( (This)->lpVtbl->GetValueByIndexWithContext(This,index,context,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_TryGetValue(This,resource,result) \
    ( (This)->lpVtbl->TryGetValue(This,resource,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_TryGetValueWithContext(This,resource,context,result) \
    ( (This)->lpVtbl->TryGetValueWithContext(This,resource,context,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceMap_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.Resources.IResourceNotFoundEventArgs
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.Resources.ResourceNotFoundEventArgs
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_Resources_IResourceNotFoundEventArgs[] = L"Microsoft.Windows.ApplicationModel.Resources.IResourceNotFoundEventArgs";
/* [object, uuid("64ABB08B-E77D-5B26-830F-15941E0E8200"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Context )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceContext * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Name )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This,
        /* [retval, out] */HSTRING * value
        );
    HRESULT ( STDMETHODCALLTYPE *SetResolvedCandidate )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceCandidate * candidate
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_get_Context(This,value) \
    ( (This)->lpVtbl->get_Context(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_get_Name(This,value) \
    ( (This)->lpVtbl->get_Name(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_SetResolvedCandidate(This,candidate) \
    ( (This)->lpVtbl->SetResolvedCandidate(This,candidate) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CResources_CIResourceNotFoundEventArgs_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.KnownResourceQualifierName
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.Resources.IKnownResourceQualifierNameStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_KnownResourceQualifierName_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_KnownResourceQualifierName_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_KnownResourceQualifierName[] = L"Microsoft.Windows.ApplicationModel.Resources.KnownResourceQualifierName";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.Resources.IResourceCandidateFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceCandidate ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceCandidate_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceCandidate_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceCandidate[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceCandidate";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceContext
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceContext2
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceContext ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceContext_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceContext[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceContext";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceLoader
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.Resources.IResourceLoaderStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceLoader ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceLoader_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceLoader_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceLoader[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceLoader";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceManager
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.Resources.IResourceManagerFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceManager2
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceManager[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceManager";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceMap
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceMap ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceMap_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceMap_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceMap[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceMap";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.Resources.ResourceNotFoundEventArgs
 *
 * Introduced to Microsoft.Windows.ApplicationModel.Resources.MrtCoreContract in version 1.0
 *
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.Resources.IResourceNotFoundEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceNotFoundEventArgs_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_Resources_ResourceNotFoundEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_Resources_ResourceNotFoundEventArgs[] = L"Microsoft.Windows.ApplicationModel.Resources.ResourceNotFoundEventArgs";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_RESOURCES_MRTCORECONTRACT_VERSION >= 0x10000





#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Eapplicationmodel2Eresources_p_h__

#endif // __microsoft2Ewindows2Eapplicationmodel2Eresources_h__

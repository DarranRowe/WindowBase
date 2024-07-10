
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
#ifndef __microsoft2Ewindows2Esystem_h__
#define __microsoft2Ewindows2Esystem_h__
#ifndef __microsoft2Ewindows2Esystem_p_h__
#define __microsoft2Ewindows2Esystem_p_h__


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
#if !defined(MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION)
#define MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION 0x20000
#endif // defined(MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION)

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
#ifndef ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace System {
                interface IEnvironmentManager;
            } /* System */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager ABI::Microsoft::Windows::System::IEnvironmentManager

#endif // ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace System {
                interface IEnvironmentManager2;
            } /* System */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 ABI::Microsoft::Windows::System::IEnvironmentManager2

#endif // ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace System {
                interface IEnvironmentManagerStatics;
            } /* System */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics ABI::Microsoft::Windows::System::IEnvironmentManagerStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_FWD_DEFINED__

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









namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace System {
                class EnvironmentManager;
            } /* System */
        } /* Windows */
    } /* Microsoft */
} /* ABI */







/*
 *
 * Interface Microsoft.Windows.System.IEnvironmentManager
 *
 * Introduced to Microsoft.Windows.System.EnvironmentManagerContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.System.EnvironmentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_System_IEnvironmentManager[] = L"Microsoft.Windows.System.IEnvironmentManager";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace System {
                /* [object, uuid("D1B239BB-7013-5176-B02A-63477410D986"), exclusiveto, contract] */
                MIDL_INTERFACE("D1B239BB-7013-5176-B02A-63477410D986")
                IEnvironmentManager : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetEnvironmentVariables(
                        /* [retval, out] */__FIMapView_2_HSTRING_HSTRING * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetEnvironmentVariable(
                        /* [in] */HSTRING name,
                        /* [retval, out] */HSTRING * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetEnvironmentVariable(
                        /* [in] */HSTRING name,
                        /* [in] */HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE AppendToPath(
                        /* [in] */HSTRING path
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RemoveFromPath(
                        /* [in] */HSTRING path
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE AddExecutableFileExtension(
                        /* [in] */HSTRING pathExt
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RemoveExecutableFileExtension(
                        /* [in] */HSTRING pathExt
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IEnvironmentManager=_uuidof(IEnvironmentManager);
                
            } /* System */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.System.IEnvironmentManager2
 *
 * Introduced to Microsoft.Windows.System.EnvironmentManagerContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.System.EnvironmentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_System_IEnvironmentManager2[] = L"Microsoft.Windows.System.IEnvironmentManager2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace System {
                /* [object, uuid("CFC0AD51-02B7-57FF-8CA7-E015251737CB"), exclusiveto, contract] */
                MIDL_INTERFACE("CFC0AD51-02B7-57FF-8CA7-E015251737CB")
                IEnvironmentManager2 : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_AreChangesTracked(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IEnvironmentManager2=_uuidof(IEnvironmentManager2);
                
            } /* System */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.System.IEnvironmentManagerStatics
 *
 * Introduced to Microsoft.Windows.System.EnvironmentManagerContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.System.EnvironmentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_System_IEnvironmentManagerStatics[] = L"Microsoft.Windows.System.IEnvironmentManagerStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace System {
                /* [object, uuid("407B1522-6156-5398-93FD-D6411C35E7B1"), exclusiveto, contract] */
                MIDL_INTERFACE("407B1522-6156-5398-93FD-D6411C35E7B1")
                IEnvironmentManagerStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetForProcess(
                        /* [retval, out] */ABI::Microsoft::Windows::System::IEnvironmentManager * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetForUser(
                        /* [retval, out] */ABI::Microsoft::Windows::System::IEnvironmentManager * * result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetForMachine(
                        /* [retval, out] */ABI::Microsoft::Windows::System::IEnvironmentManager * * result
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsSupported(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IEnvironmentManagerStatics=_uuidof(IEnvironmentManagerStatics);
                
            } /* System */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.System.EnvironmentManager
 *
 * Introduced to Microsoft.Windows.System.EnvironmentManagerContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.System.IEnvironmentManagerStatics interface starting with version 1.0 of the Microsoft.Windows.System.EnvironmentManagerContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.System.IEnvironmentManager ** Default Interface **
 *    Microsoft.Windows.System.IEnvironmentManager2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_System_EnvironmentManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_System_EnvironmentManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_System_EnvironmentManager[] = L"Microsoft.Windows.System.EnvironmentManager";
#endif
#endif // MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000




#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager;

#endif // ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2;

#endif // ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_FWD_DEFINED__

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













/*
 *
 * Interface Microsoft.Windows.System.IEnvironmentManager
 *
 * Introduced to Microsoft.Windows.System.EnvironmentManagerContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.System.EnvironmentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_System_IEnvironmentManager[] = L"Microsoft.Windows.System.IEnvironmentManager";
/* [object, uuid("D1B239BB-7013-5176-B02A-63477410D986"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetEnvironmentVariables )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
        /* [retval, out] */__FIMapView_2_HSTRING_HSTRING * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetEnvironmentVariable )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
        /* [in] */HSTRING name,
        /* [retval, out] */HSTRING * result
        );
    HRESULT ( STDMETHODCALLTYPE *SetEnvironmentVariable )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
        /* [in] */HSTRING name,
        /* [in] */HSTRING value
        );
    HRESULT ( STDMETHODCALLTYPE *AppendToPath )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
        /* [in] */HSTRING path
        );
    HRESULT ( STDMETHODCALLTYPE *RemoveFromPath )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
        /* [in] */HSTRING path
        );
    HRESULT ( STDMETHODCALLTYPE *AddExecutableFileExtension )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
        /* [in] */HSTRING pathExt
        );
    HRESULT ( STDMETHODCALLTYPE *RemoveExecutableFileExtension )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * This,
        /* [in] */HSTRING pathExt
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerVtbl;

interface __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_GetEnvironmentVariables(This,result) \
    ( (This)->lpVtbl->GetEnvironmentVariables(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_GetEnvironmentVariable(This,name,result) \
    ( (This)->lpVtbl->GetEnvironmentVariable(This,name,result) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_SetEnvironmentVariable(This,name,value) \
    ( (This)->lpVtbl->SetEnvironmentVariable(This,name,value) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_AppendToPath(This,path) \
    ( (This)->lpVtbl->AppendToPath(This,path) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_RemoveFromPath(This,path) \
    ( (This)->lpVtbl->RemoveFromPath(This,path) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_AddExecutableFileExtension(This,pathExt) \
    ( (This)->lpVtbl->AddExecutableFileExtension(This,pathExt) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_RemoveExecutableFileExtension(This,pathExt) \
    ( (This)->lpVtbl->RemoveExecutableFileExtension(This,pathExt) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.System.IEnvironmentManager2
 *
 * Introduced to Microsoft.Windows.System.EnvironmentManagerContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.System.EnvironmentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_System_IEnvironmentManager2[] = L"Microsoft.Windows.System.IEnvironmentManager2";
/* [object, uuid("CFC0AD51-02B7-57FF-8CA7-E015251737CB"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_AreChangesTracked )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2 * This,
        /* [retval, out] */boolean * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_get_AreChangesTracked(This,value) \
    ( (This)->lpVtbl->get_AreChangesTracked(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.System.IEnvironmentManagerStatics
 *
 * Introduced to Microsoft.Windows.System.EnvironmentManagerContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.System.EnvironmentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_System_IEnvironmentManagerStatics[] = L"Microsoft.Windows.System.IEnvironmentManagerStatics";
/* [object, uuid("407B1522-6156-5398-93FD-D6411C35E7B1"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetForProcess )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetForUser )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetForMachine )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManager * * result
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsSupported )(
        __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics * This,
        /* [retval, out] */boolean * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_GetForProcess(This,result) \
    ( (This)->lpVtbl->GetForProcess(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_GetForUser(This,result) \
    ( (This)->lpVtbl->GetForUser(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_GetForMachine(This,result) \
    ( (This)->lpVtbl->GetForMachine(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_get_IsSupported(This,value) \
    ( (This)->lpVtbl->get_IsSupported(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CSystem_CIEnvironmentManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.System.EnvironmentManager
 *
 * Introduced to Microsoft.Windows.System.EnvironmentManagerContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.System.IEnvironmentManagerStatics interface starting with version 1.0 of the Microsoft.Windows.System.EnvironmentManagerContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.System.IEnvironmentManager ** Default Interface **
 *    Microsoft.Windows.System.IEnvironmentManager2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_System_EnvironmentManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_System_EnvironmentManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_System_EnvironmentManager[] = L"Microsoft.Windows.System.EnvironmentManager";
#endif
#endif // MICROSOFT_WINDOWS_SYSTEM_ENVIRONMENTMANAGERCONTRACT_VERSION >= 0x10000




#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Esystem_p_h__

#endif // __microsoft2Ewindows2Esystem_h__

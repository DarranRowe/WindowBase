
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
#ifndef __microsoft2Eui2Esystem_h__
#define __microsoft2Eui2Esystem_h__
#ifndef __microsoft2Eui2Esystem_p_h__
#define __microsoft2Eui2Esystem_p_h__


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
#include "Microsoft.Foundation.h"
#include "Microsoft.UI.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace System {
                interface IThemeSettings;
            } /* System */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings ABI::Microsoft::UI::System::IThemeSettings

#endif // ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace System {
                interface IThemeSettingsStatics;
            } /* System */
        } /* UI */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics ABI::Microsoft::UI::System::IThemeSettingsStatics

#endif // ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace System {
                class ThemeSettings;
            } /* System */
        } /* UI */
    } /* Microsoft */
} /* ABI */



#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef DEF___FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_USE
#define DEF___FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("ad8a8846-17ae-57e3-a245-8f5a77a5ecf9"))
ITypedEventHandler<ABI::Microsoft::UI::System::ThemeSettings*,IInspectable*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Microsoft::UI::System::ThemeSettings*, ABI::Microsoft::UI::System::IThemeSettings*>,IInspectable*> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.TypedEventHandler`2<Microsoft.UI.System.ThemeSettings, Object>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Microsoft::UI::System::ThemeSettings*,IInspectable*> __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_t;
#define __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable ABI::Windows::Foundation::__FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::System::IThemeSettings*,IInspectable*>
//#define __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_t ABI::Windows::Foundation::ITypedEventHandler<ABI::Microsoft::UI::System::IThemeSettings*,IInspectable*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_USE */


#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004






namespace ABI {
    namespace Microsoft {
        namespace UI {
            
            typedef struct WindowId WindowId;
            
        } /* UI */
    } /* Microsoft */
} /* ABI */














/*
 *
 * Interface Microsoft.UI.System.IThemeSettings
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.System.ThemeSettings
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_System_IThemeSettings[] = L"Microsoft.UI.System.IThemeSettings";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace System {
                /* [object, uuid("2228EE7E-6D15-563C-8F3C-E8783BA13846"), exclusiveto, contract] */
                MIDL_INTERFACE("2228EE7E-6D15-563C-8F3C-E8783BA13846")
                IThemeSettings : public IInspectable
                {
                public:
                    /* [eventadd] */virtual HRESULT STDMETHODCALLTYPE add_Changed(
                        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable * handler,
                        /* [retval, out] */EventRegistrationToken * token
                        ) = 0;
                    /* [eventremove] */virtual HRESULT STDMETHODCALLTYPE remove_Changed(
                        /* [in] */EventRegistrationToken token
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_HighContrast(
                        /* [retval, out] */::boolean * value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_HighContrastScheme(
                        /* [retval, out] */HSTRING * value
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IThemeSettings=_uuidof(IThemeSettings);
                
            } /* System */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.System.IThemeSettingsStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.System.ThemeSettings
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_System_IThemeSettingsStatics[] = L"Microsoft.UI.System.IThemeSettingsStatics";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace System {
                /* [object, uuid("1586907D-30DB-5F97-8FA1-8940C75DCCC0"), exclusiveto, contract] */
                MIDL_INTERFACE("1586907D-30DB-5F97-8FA1-8940C75DCCC0")
                IThemeSettingsStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateForWindowId(
                        /* [in] */ABI::Microsoft::UI::WindowId windowId,
                        /* [retval, out] */ABI::Microsoft::UI::System::IThemeSettings * * result
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IThemeSettingsStatics=_uuidof(IThemeSettingsStatics);
                
            } /* System */
        } /* UI */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.System.ThemeSettings
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.System.IThemeSettingsStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.System.IThemeSettings ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_System_ThemeSettings_DEFINED
#define RUNTIMECLASS_Microsoft_UI_System_ThemeSettings_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_System_ThemeSettings[] = L"Microsoft.UI.System.ThemeSettings";
#endif
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004




#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings;

#endif // ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics;

#endif // ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions


#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable;

typedef struct __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectableVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable * This,/* [in] */ __RPC__in_opt __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * sender,/* [in] */ __RPC__in_opt IInspectable * e);
    END_INTERFACE
} __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectableVtbl;

interface __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable
{
    CONST_VTBL struct __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectableVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_Invoke(This,sender,e)	\
    ( (This)->lpVtbl -> Invoke(This,sender,e) ) 
#endif /* COBJMACROS */



#endif // ____FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable_INTERFACE_DEFINED__

#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004






typedef struct __x_ABI_CMicrosoft_CUI_CWindowId __x_ABI_CMicrosoft_CUI_CWindowId;














/*
 *
 * Interface Microsoft.UI.System.IThemeSettings
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.System.ThemeSettings
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_System_IThemeSettings[] = L"Microsoft.UI.System.IThemeSettings";
/* [object, uuid("2228EE7E-6D15-563C-8F3C-E8783BA13846"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [eventadd] */HRESULT ( STDMETHODCALLTYPE *add_Changed )(
        __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This,
        /* [in] */__FITypedEventHandler_2_Microsoft__CUI__CSystem__CThemeSettings_IInspectable * handler,
        /* [retval, out] */EventRegistrationToken * token
        );
    /* [eventremove] */HRESULT ( STDMETHODCALLTYPE *remove_Changed )(
        __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This,
        /* [in] */EventRegistrationToken token
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_HighContrast )(
        __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_HighContrastScheme )(
        __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * This,
        /* [retval, out] */HSTRING * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsVtbl;

interface __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_add_Changed(This,handler,token) \
    ( (This)->lpVtbl->add_Changed(This,handler,token) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_remove_Changed(This,token) \
    ( (This)->lpVtbl->remove_Changed(This,token) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_get_HighContrast(This,value) \
    ( (This)->lpVtbl->get_HighContrast(This,value) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_get_HighContrastScheme(This,value) \
    ( (This)->lpVtbl->get_HighContrastScheme(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Interface Microsoft.UI.System.IThemeSettingsStatics
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * Interface is a part of the implementation of type Microsoft.UI.System.ThemeSettings
 *
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004
#if !defined(____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_System_IThemeSettingsStatics[] = L"Microsoft.UI.System.IThemeSettingsStatics";
/* [object, uuid("1586907D-30DB-5F97-8FA1-8940C75DCCC0"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateForWindowId )(
        __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics * This,
        /* [in] */__x_ABI_CMicrosoft_CUI_CWindowId windowId,
        /* [retval, out] */__x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettings * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStaticsVtbl;

interface __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_CreateForWindowId(This,windowId,result) \
    ( (This)->lpVtbl->CreateForWindowId(This,windowId,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CUI_CSystem_CIThemeSettingsStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004


/*
 *
 * Class Microsoft.UI.System.ThemeSettings
 *
 * Introduced to Microsoft.Foundation.WindowsAppSDKContract in version 1.4
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.UI.System.IThemeSettingsStatics interface starting with version 1.4 of the Microsoft.Foundation.WindowsAppSDKContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.UI.System.IThemeSettings ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_FOUNDATION_WINDOWSAPPSDKCONTRACT_VERSION >= 0x10004

#ifndef RUNTIMECLASS_Microsoft_UI_System_ThemeSettings_DEFINED
#define RUNTIMECLASS_Microsoft_UI_System_ThemeSettings_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_UI_System_ThemeSettings[] = L"Microsoft.UI.System.ThemeSettings";
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
#endif // __microsoft2Eui2Esystem_p_h__

#endif // __microsoft2Eui2Esystem_h__

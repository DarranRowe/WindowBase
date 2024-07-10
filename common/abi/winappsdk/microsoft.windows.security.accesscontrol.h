
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
#ifndef __microsoft2Ewindows2Esecurity2Eaccesscontrol_h__
#define __microsoft2Ewindows2Esecurity2Eaccesscontrol_h__
#ifndef __microsoft2Ewindows2Esecurity2Eaccesscontrol_p_h__
#define __microsoft2Ewindows2Esecurity2Eaccesscontrol_p_h__


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
#if !defined(MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION)
#define MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION 0x10000
#endif // defined(MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION)

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

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Security {
                namespace AccessControl {
                    interface ISecurityDescriptorHelpersStatics;
                } /* AccessControl */
            } /* Security */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics ABI::Microsoft::Windows::Security::AccessControl::ISecurityDescriptorHelpersStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_FWD_DEFINED__



namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Security {
                namespace AccessControl {
                    
                    typedef struct AppContainerNameAndAccess AppContainerNameAndAccess;
                    
                } /* AccessControl */
            } /* Security */
        } /* Windows */
    } /* Microsoft */
} /* ABI */









/*
 *
 * Struct Microsoft.Windows.Security.AccessControl.AppContainerNameAndAccess
 *
 * Introduced to Microsoft.Windows.Security.AccessControl.AccessControlContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Security {
                namespace AccessControl {
                    /* [contract] */
                    struct AppContainerNameAndAccess
                    {
                        HSTRING appContainerName;
                        UINT32 accessMask;
                    };
                    
                } /* AccessControl */
            } /* Security */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Security.AccessControl.ISecurityDescriptorHelpersStatics
 *
 * Introduced to Microsoft.Windows.Security.AccessControl.AccessControlContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Security.AccessControl.SecurityDescriptorHelpers
 *
 *
 */
#if MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Security_AccessControl_ISecurityDescriptorHelpersStatics[] = L"Microsoft.Windows.Security.AccessControl.ISecurityDescriptorHelpersStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace Security {
                namespace AccessControl {
                    /* [object, uuid("14FA9E8D-59F0-5017-852F-3AE24FD5EBB1"), exclusiveto, contract] */
                    MIDL_INTERFACE("14FA9E8D-59F0-5017-852F-3AE24FD5EBB1")
                    ISecurityDescriptorHelpersStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetSddlForAppContainerNames(
                            /* [in] */UINT32 __accessRequestsSize,
                            /* [size_is(__accessRequestsSize), in] */ABI::Microsoft::Windows::Security::AccessControl::AppContainerNameAndAccess * accessRequests,
                            /* [in] */HSTRING principalStringSid,
                            /* [in] */UINT32 principalAccessMask,
                            /* [retval, out] */HSTRING * result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetSecurityDescriptorBytesFromAppContainerNames(
                            /* [in] */UINT32 __accessRequestsSize,
                            /* [size_is(__accessRequestsSize), in] */ABI::Microsoft::Windows::Security::AccessControl::AppContainerNameAndAccess * accessRequests,
                            /* [in] */HSTRING principalStringSid,
                            /* [in] */UINT32 principalAccessMask,
                            /* [out] */UINT32 * __resultSize,
                            /* [size_is(, *(__resultSize)), retval, out] */BYTE * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_ISecurityDescriptorHelpersStatics=_uuidof(ISecurityDescriptorHelpersStatics);
                    
                } /* AccessControl */
            } /* Security */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Security.AccessControl.SecurityDescriptorHelpers
 *
 * Introduced to Microsoft.Windows.Security.AccessControl.AccessControlContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Security.AccessControl.ISecurityDescriptorHelpersStatics interface starting with version 1.0 of the Microsoft.Windows.Security.AccessControl.AccessControlContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_Security_AccessControl_SecurityDescriptorHelpers_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Security_AccessControl_SecurityDescriptorHelpers_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Security_AccessControl_SecurityDescriptorHelpers[] = L"Microsoft.Windows.Security.AccessControl.SecurityDescriptorHelpers";
#endif
#endif // MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_FWD_DEFINED__



typedef struct __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CAppContainerNameAndAccess __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CAppContainerNameAndAccess;









/*
 *
 * Struct Microsoft.Windows.Security.AccessControl.AppContainerNameAndAccess
 *
 * Introduced to Microsoft.Windows.Security.AccessControl.AccessControlContract in version 1.0
 *
 *
 */
#if MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000

/* [contract] */
struct __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CAppContainerNameAndAccess
{
    HSTRING appContainerName;
    UINT32 accessMask;
};
#endif // MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.Security.AccessControl.ISecurityDescriptorHelpersStatics
 *
 * Introduced to Microsoft.Windows.Security.AccessControl.AccessControlContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.Security.AccessControl.SecurityDescriptorHelpers
 *
 *
 */
#if MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_Security_AccessControl_ISecurityDescriptorHelpersStatics[] = L"Microsoft.Windows.Security.AccessControl.ISecurityDescriptorHelpersStatics";
/* [object, uuid("14FA9E8D-59F0-5017-852F-3AE24FD5EBB1"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetSddlForAppContainerNames )(
        __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics * This,
        /* [in] */UINT32 __accessRequestsSize,
        /* [size_is(__accessRequestsSize), in] */__x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CAppContainerNameAndAccess * accessRequests,
        /* [in] */HSTRING principalStringSid,
        /* [in] */UINT32 principalAccessMask,
        /* [retval, out] */HSTRING * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetSecurityDescriptorBytesFromAppContainerNames )(
        __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics * This,
        /* [in] */UINT32 __accessRequestsSize,
        /* [size_is(__accessRequestsSize), in] */__x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CAppContainerNameAndAccess * accessRequests,
        /* [in] */HSTRING principalStringSid,
        /* [in] */UINT32 principalAccessMask,
        /* [out] */UINT32 * __resultSize,
        /* [size_is(, *(__resultSize)), retval, out] */BYTE * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_GetSddlForAppContainerNames(This,__accessRequestsSize,accessRequests,principalStringSid,principalAccessMask,result) \
    ( (This)->lpVtbl->GetSddlForAppContainerNames(This,__accessRequestsSize,accessRequests,principalStringSid,principalAccessMask,result) )

#define __x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_GetSecurityDescriptorBytesFromAppContainerNames(This,__accessRequestsSize,accessRequests,principalStringSid,principalAccessMask,__resultSize,result) \
    ( (This)->lpVtbl->GetSecurityDescriptorBytesFromAppContainerNames(This,__accessRequestsSize,accessRequests,principalStringSid,principalAccessMask,__resultSize,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CSecurity_CAccessControl_CISecurityDescriptorHelpersStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.Security.AccessControl.SecurityDescriptorHelpers
 *
 * Introduced to Microsoft.Windows.Security.AccessControl.AccessControlContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.Security.AccessControl.ISecurityDescriptorHelpersStatics interface starting with version 1.0 of the Microsoft.Windows.Security.AccessControl.AccessControlContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_Security_AccessControl_SecurityDescriptorHelpers_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_Security_AccessControl_SecurityDescriptorHelpers_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_Security_AccessControl_SecurityDescriptorHelpers[] = L"Microsoft.Windows.Security.AccessControl.SecurityDescriptorHelpers";
#endif
#endif // MICROSOFT_WINDOWS_SECURITY_ACCESSCONTROL_ACCESSCONTROLCONTRACT_VERSION >= 0x10000





#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Esecurity2Eaccesscontrol_p_h__

#endif // __microsoft2Ewindows2Esecurity2Eaccesscontrol_h__

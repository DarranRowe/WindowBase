
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
#ifndef __microsoft2Ewindows2Eapplicationmodel2Ewindowsappruntime_h__
#define __microsoft2Ewindows2Eapplicationmodel2Ewindowsappruntime_h__
#ifndef __microsoft2Ewindows2Eapplicationmodel2Ewindowsappruntime_p_h__
#define __microsoft2Ewindows2Eapplicationmodel2Ewindowsappruntime_p_h__


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
#if !defined(MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION)
#define MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION 0x40000
#endif // defined(MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION)

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
#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    interface IDeploymentInitializeOptions;
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentInitializeOptions

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    interface IDeploymentInitializeOptions2;
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentInitializeOptions2

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    interface IDeploymentManagerStatics;
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentManagerStatics

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    interface IDeploymentManagerStatics2;
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentManagerStatics2

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    interface IDeploymentResult;
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentResult

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    interface IDeploymentResultFactory;
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentResultFactory

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_FWD_DEFINED__



namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    
                    typedef enum DeploymentStatus : int DeploymentStatus;
                    
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */







namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    class DeploymentInitializeOptions;
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */



namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    class DeploymentResult;
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */








/*
 *
 * Struct Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentStatus
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    /* [v1_enum, contract] */
                    enum DeploymentStatus : int
                    {
                        DeploymentStatus_Unknown = 0,
                        DeploymentStatus_Ok = 1,
                        DeploymentStatus_PackageInstallRequired = 2,
                        DeploymentStatus_PackageInstallFailed = 3,
                    };
                    
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentInitializeOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentInitializeOptions[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    /* [object, uuid("578A5FD4-9D7F-5E01-97B8-D8EA61DB4027"), exclusiveto, contract] */
                    MIDL_INTERFACE("578A5FD4-9D7F-5E01-97B8-D8EA61DB4027")
                    IDeploymentInitializeOptions : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ForceDeployment(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ForceDeployment(
                            /* [in] */::boolean value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDeploymentInitializeOptions=_uuidof(IDeploymentInitializeOptions);
                    
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 3.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentInitializeOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x30000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentInitializeOptions2[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    /* [object, uuid("AD902820-149F-5E16-A566-9B2363997DE2"), exclusiveto, contract] */
                    MIDL_INTERFACE("AD902820-149F-5E16-A566-9B2363997DE2")
                    IDeploymentInitializeOptions2 : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_OnErrorShowUI(
                            /* [retval, out] */::boolean * value
                            ) = 0;
                        /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_OnErrorShowUI(
                            /* [in] */::boolean value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDeploymentInitializeOptions2=_uuidof(IDeploymentInitializeOptions2);
                    
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x30000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentManagerStatics[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    /* [object, uuid("6782A9D0-BFD0-50EA-81B0-32E9ED37CDF0"), exclusiveto, contract] */
                    MIDL_INTERFACE("6782A9D0-BFD0-50EA-81B0-32E9ED37CDF0")
                    IDeploymentManagerStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetStatus(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentResult * * result
                            ) = 0;
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE Initialize(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentResult * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDeploymentManagerStatics=_uuidof(IDeploymentManagerStatics);
                    
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentManagerStatics2[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics2";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    /* [object, uuid("F49C16EE-6EBC-5F15-BEBB-2BA49F8C0B30"), exclusiveto, contract] */
                    MIDL_INTERFACE("F49C16EE-6EBC-5F15-BEBB-2BA49F8C0B30")
                    IDeploymentManagerStatics2 : public IInspectable
                    {
                    public:
                        /* [overload] */virtual HRESULT STDMETHODCALLTYPE Initialize(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentInitializeOptions * deploymentInitializeOptions,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentResult * * result
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDeploymentManagerStatics2=_uuidof(IDeploymentManagerStatics2);
                    
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResult
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentResult
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentResult[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResult";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    /* [object, uuid("27203F62-463D-587A-8EB7-870098901078"), exclusiveto, contract] */
                    MIDL_INTERFACE("27203F62-463D-587A-8EB7-870098901078")
                    IDeploymentResult : public IInspectable
                    {
                    public:
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Status(
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::DeploymentStatus * value
                            ) = 0;
                        /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExtendedError(
                            /* [retval, out] */HRESULT * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDeploymentResult=_uuidof(IDeploymentResult);
                    
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResultFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentResult
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentResultFactory[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResultFactory";
namespace ABI {
    namespace Microsoft {
        namespace Windows {
            namespace ApplicationModel {
                namespace WindowsAppRuntime {
                    /* [object, uuid("ACD7BDAE-4AE6-5CAC-8205-1E8C305F953B"), exclusiveto, contract] */
                    MIDL_INTERFACE("ACD7BDAE-4AE6-5CAC-8205-1E8C305F953B")
                    IDeploymentResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            /* [in] */ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::DeploymentStatus status,
                            /* [in] */HRESULT extendedError,
                            /* [retval, out] */ABI::Microsoft::Windows::ApplicationModel::WindowsAppRuntime::IDeploymentResult * * value
                            ) = 0;
                        
                    };

                    MIDL_CONST_ID IID & IID_IDeploymentResultFactory=_uuidof(IDeploymentResultFactory);
                    
                } /* WindowsAppRuntime */
            } /* ApplicationModel */
        } /* Windows */
    } /* Microsoft */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentInitializeOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 2.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 2.0 of the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions ** Default Interface **
 *    Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentInitializeOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentInitializeOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentInitializeOptions[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentInitializeOptions";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentManager
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics2 interface starting with version 2.0 of the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract API contract
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentManager[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentManager";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentResult
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResultFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentResult_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentResult[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentResult";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000





#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_FWD_DEFINED__

#ifndef ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_FWD_DEFINED__
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory;

#endif // ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_FWD_DEFINED__



typedef enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CDeploymentStatus __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CDeploymentStatus;
















/*
 *
 * Struct Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentStatus
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 */

#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
/* [v1_enum, contract] */
enum __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CDeploymentStatus
{
    DeploymentStatus_Unknown = 0,
    DeploymentStatus_Ok = 1,
    DeploymentStatus_PackageInstallRequired = 2,
    DeploymentStatus_PackageInstallFailed = 3,
};
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentInitializeOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentInitializeOptions[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions";
/* [object, uuid("578A5FD4-9D7F-5E01-97B8-D8EA61DB4027"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptionsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ForceDeployment )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_ForceDeployment )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * This,
        /* [in] */boolean value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptionsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptionsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_get_ForceDeployment(This,value) \
    ( (This)->lpVtbl->get_ForceDeployment(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_put_ForceDeployment(This,value) \
    ( (This)->lpVtbl->put_ForceDeployment(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 3.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentInitializeOptions
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x30000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentInitializeOptions2[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions2";
/* [object, uuid("AD902820-149F-5E16-A566-9B2363997DE2"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_OnErrorShowUI )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 * This,
        /* [retval, out] */boolean * value
        );
    /* [propput] */HRESULT ( STDMETHODCALLTYPE *put_OnErrorShowUI )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2 * This,
        /* [in] */boolean value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_get_OnErrorShowUI(This,value) \
    ( (This)->lpVtbl->get_OnErrorShowUI(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_put_OnErrorShowUI(This,value) \
    ( (This)->lpVtbl->put_OnErrorShowUI(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x30000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentManagerStatics[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics";
/* [object, uuid("6782A9D0-BFD0-50EA-81B0-32E9ED37CDF0"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStaticsVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *GetStatus )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *Initialize )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStaticsVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStaticsVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_GetStatus(This,result) \
    ( (This)->lpVtbl->GetStatus(This,result) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_Initialize(This,result) \
    ( (This)->lpVtbl->Initialize(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics2
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 2.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentManager
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentManagerStatics2[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics2";
/* [object, uuid("F49C16EE-6EBC-5F15-BEBB-2BA49F8C0B30"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [overload] */HRESULT ( STDMETHODCALLTYPE *Initialize )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2 * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentInitializeOptions * deploymentInitializeOptions,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * * result
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2Vtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2Vtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_Initialize(This,deploymentInitializeOptions,result) \
    ( (This)->lpVtbl->Initialize(This,deploymentInitializeOptions,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentManagerStatics2_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResult
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentResult
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentResult[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResult";
/* [object, uuid("27203F62-463D-587A-8EB7-870098901078"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Status )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * This,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CDeploymentStatus * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ExtendedError )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * This,
        /* [retval, out] */HRESULT * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_get_Status(This,value) \
    ( (This)->lpVtbl->get_Status(This,value) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_get_ExtendedError(This,value) \
    ( (This)->lpVtbl->get_ExtendedError(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Interface Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResultFactory
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * Interface is a part of the implementation of type Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentResult
 *
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_IDeploymentResultFactory[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResultFactory";
/* [object, uuid("ACD7BDAE-4AE6-5CAC-8205-1E8C305F953B"), exclusiveto, contract] */
typedef struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactoryVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
        __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory * This,
        /* [in] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CDeploymentStatus status,
        /* [in] */HRESULT extendedError,
        /* [retval, out] */__x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResult * * value
        );
    END_INTERFACE
    
} __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactoryVtbl;

interface __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory
{
    CONST_VTBL struct __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactoryVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_CreateInstance(This,status,extendedError,value) \
    ( (This)->lpVtbl->CreateInstance(This,status,extendedError,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory;
#endif /* !defined(____x_ABI_CMicrosoft_CWindows_CApplicationModel_CWindowsAppRuntime_CIDeploymentResultFactory_INTERFACE_DEFINED__) */
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentInitializeOptions
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 2.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 2.0 of the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions ** Default Interface **
 *    Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentInitializeOptions2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentInitializeOptions_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentInitializeOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentInitializeOptions[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentInitializeOptions";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x20000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentManager
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics2 interface starting with version 2.0 of the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract API contract
 *   Static Methods exist on the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentManagerStatics interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentManager_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentManager[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentManager";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000


/*
 *
 * Class Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentResult
 *
 * Introduced to Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract in version 1.0
 *
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResultFactory interface starting with version 1.0 of the Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentContract API contract
 *
 * Class implements the following interfaces:
 *    Microsoft.Windows.ApplicationModel.WindowsAppRuntime.IDeploymentResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000

#ifndef RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentResult_DEFINED
#define RUNTIMECLASS_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Microsoft_Windows_ApplicationModel_WindowsAppRuntime_DeploymentResult[] = L"Microsoft.Windows.ApplicationModel.WindowsAppRuntime.DeploymentResult";
#endif
#endif // MICROSOFT_WINDOWS_APPLICATIONMODEL_WINDOWSAPPRUNTIME_DEPLOYMENTCONTRACT_VERSION >= 0x10000





#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __microsoft2Ewindows2Eapplicationmodel2Ewindowsappruntime_p_h__

#endif // __microsoft2Ewindows2Eapplicationmodel2Ewindowsappruntime_h__

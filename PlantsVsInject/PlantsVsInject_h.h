

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for PlantsVsInject.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __PlantsVsInject_h_h__
#define __PlantsVsInject_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPlantsVsInject_FWD_DEFINED__
#define __IPlantsVsInject_FWD_DEFINED__
typedef interface IPlantsVsInject IPlantsVsInject;

#endif 	/* __IPlantsVsInject_FWD_DEFINED__ */


#ifndef __PlantsVsInject_FWD_DEFINED__
#define __PlantsVsInject_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlantsVsInject PlantsVsInject;
#else
typedef struct PlantsVsInject PlantsVsInject;
#endif /* __cplusplus */

#endif 	/* __PlantsVsInject_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __PlantsVsInject_LIBRARY_DEFINED__
#define __PlantsVsInject_LIBRARY_DEFINED__

/* library PlantsVsInject */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_PlantsVsInject;

#ifndef __IPlantsVsInject_DISPINTERFACE_DEFINED__
#define __IPlantsVsInject_DISPINTERFACE_DEFINED__

/* dispinterface IPlantsVsInject */
/* [uuid] */ 


EXTERN_C const IID DIID_IPlantsVsInject;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7f9af097-9be4-40ee-b695-0981b2d6b95e")
    IPlantsVsInject : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPlantsVsInjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlantsVsInject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlantsVsInject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlantsVsInject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPlantsVsInject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPlantsVsInject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPlantsVsInject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPlantsVsInject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IPlantsVsInjectVtbl;

    interface IPlantsVsInject
    {
        CONST_VTBL struct IPlantsVsInjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlantsVsInject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPlantsVsInject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPlantsVsInject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPlantsVsInject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPlantsVsInject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPlantsVsInject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPlantsVsInject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPlantsVsInject_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PlantsVsInject;

#ifdef __cplusplus

class DECLSPEC_UUID("21022ea0-5650-4070-a52e-84fdef947115")
PlantsVsInject;
#endif
#endif /* __PlantsVsInject_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif





/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for DLLInjectBox.idl:
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


#ifndef __DLLInjectBox_h_h__
#define __DLLInjectBox_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDLLInjectBox_FWD_DEFINED__
#define __IDLLInjectBox_FWD_DEFINED__
typedef interface IDLLInjectBox IDLLInjectBox;

#endif 	/* __IDLLInjectBox_FWD_DEFINED__ */


#ifndef __DLLInjectBox_FWD_DEFINED__
#define __DLLInjectBox_FWD_DEFINED__

#ifdef __cplusplus
typedef class DLLInjectBox DLLInjectBox;
#else
typedef struct DLLInjectBox DLLInjectBox;
#endif /* __cplusplus */

#endif 	/* __DLLInjectBox_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __DLLInjectBox_LIBRARY_DEFINED__
#define __DLLInjectBox_LIBRARY_DEFINED__

/* library DLLInjectBox */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DLLInjectBox;

#ifndef __IDLLInjectBox_DISPINTERFACE_DEFINED__
#define __IDLLInjectBox_DISPINTERFACE_DEFINED__

/* dispinterface IDLLInjectBox */
/* [uuid] */ 


EXTERN_C const IID DIID_IDLLInjectBox;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("81bc1f81-dd60-4641-bb26-b09b939108ba")
    IDLLInjectBox : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IDLLInjectBoxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDLLInjectBox * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDLLInjectBox * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDLLInjectBox * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDLLInjectBox * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDLLInjectBox * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDLLInjectBox * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDLLInjectBox * This,
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
    } IDLLInjectBoxVtbl;

    interface IDLLInjectBox
    {
        CONST_VTBL struct IDLLInjectBoxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDLLInjectBox_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDLLInjectBox_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDLLInjectBox_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDLLInjectBox_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDLLInjectBox_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDLLInjectBox_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDLLInjectBox_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IDLLInjectBox_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DLLInjectBox;

#ifdef __cplusplus

class DECLSPEC_UUID("622a986a-a686-4d7e-b7c9-3caaa6642975")
DLLInjectBox;
#endif
#endif /* __DLLInjectBox_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif




// DlgProxy.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DLLInjectBox.h"
#include "DlgProxy.h"
#include "DLLInjectBoxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDLLInjectBoxDlgAutoProxy

IMPLEMENT_DYNCREATE(CDLLInjectBoxDlgAutoProxy, CCmdTarget)

CDLLInjectBoxDlgAutoProxy::CDLLInjectBoxDlgAutoProxy()
{
	EnableAutomation();

	// 为使应用程序在自动化对象处于活动状态时一直保持
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CDLLInjectBoxDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CDLLInjectBoxDlg)))
		{
			m_pDialog = reinterpret_cast<CDLLInjectBoxDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CDLLInjectBoxDlgAutoProxy::~CDLLInjectBoxDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CDLLInjectBoxDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CDLLInjectBoxDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDLLInjectBoxDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IDLLInjectBox 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {81bc1f81-dd60-4641-bb26-b09b939108ba}
static const IID IID_IDLLInjectBox =
{0x81bc1f81,0xdd60,0x4641,{0xbb,0x26,0xb0,0x9b,0x93,0x91,0x08,0xba}};

BEGIN_INTERFACE_MAP(CDLLInjectBoxDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CDLLInjectBoxDlgAutoProxy, IID_IDLLInjectBox, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in pch.h of this project
// {622a986a-a686-4d7e-b7c9-3caaa6642975}
IMPLEMENT_OLECREATE2(CDLLInjectBoxDlgAutoProxy, "DLLInjectBox.Application", 0x622a986a,0xa686,0x4d7e,0xb7,0xc9,0x3c,0xaa,0xa6,0x64,0x29,0x75)


// CDLLInjectBoxDlgAutoProxy 消息处理程序

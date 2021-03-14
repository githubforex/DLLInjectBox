
// DlgProxy.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "PlantsVsInject.h"
#include "DlgProxy.h"
#include "PlantsVsInjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlantsVsInjectDlgAutoProxy

IMPLEMENT_DYNCREATE(CPlantsVsInjectDlgAutoProxy, CCmdTarget)

CPlantsVsInjectDlgAutoProxy::CPlantsVsInjectDlgAutoProxy()
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
		ASSERT_KINDOF(CPlantsVsInjectDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CPlantsVsInjectDlg)))
		{
			m_pDialog = reinterpret_cast<CPlantsVsInjectDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CPlantsVsInjectDlgAutoProxy::~CPlantsVsInjectDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CPlantsVsInjectDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CPlantsVsInjectDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPlantsVsInjectDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IPlantsVsInject 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {7f9af097-9be4-40ee-b695-0981b2d6b95e}
static const IID IID_IPlantsVsInject =
{0x7f9af097,0x9be4,0x40ee,{0xb6,0x95,0x09,0x81,0xb2,0xd6,0xb9,0x5e}};

BEGIN_INTERFACE_MAP(CPlantsVsInjectDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CPlantsVsInjectDlgAutoProxy, IID_IPlantsVsInject, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in pch.h of this project
// {21022ea0-5650-4070-a52e-84fdef947115}
IMPLEMENT_OLECREATE2(CPlantsVsInjectDlgAutoProxy, "PlantsVsInject.Application", 0x21022ea0,0x5650,0x4070,0xa5,0x2e,0x84,0xfd,0xef,0x94,0x71,0x15)


// CPlantsVsInjectDlgAutoProxy 消息处理程序

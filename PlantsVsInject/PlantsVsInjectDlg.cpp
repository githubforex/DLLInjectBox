
// PlantsVsInjectDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "PlantsVsInject.h"
#include "PlantsVsInjectDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPlantsVsInjectDlg 对话框


IMPLEMENT_DYNAMIC(CPlantsVsInjectDlg, CDialogEx);

CPlantsVsInjectDlg::CPlantsVsInjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLANTSVSINJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = nullptr;
}

CPlantsVsInjectDlg::~CPlantsVsInjectDlg()
{
	// 如果该对话框有自动化代理，则
	//  此对话框的返回指针为 null，所以它知道
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != nullptr)
		m_pAutoProxy->m_pDialog = nullptr;
}

void CPlantsVsInjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPlantsVsInjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED (IDC_BUTTON_REBUILD, &CPlantsVsInjectDlg::OnBnClickedButtonRebuild)
END_MESSAGE_MAP()


// CPlantsVsInjectDlg 消息处理程序

BOOL CPlantsVsInjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPlantsVsInjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPlantsVsInjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPlantsVsInjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void CPlantsVsInjectDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CPlantsVsInjectDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CPlantsVsInjectDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CPlantsVsInjectDlg::CanExit()
{
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != nullptr)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



void CPlantsVsInjectDlg::OnBnClickedButtonRebuild ()
{
	DWORD _pid;

	HWND _hwnd = ::FindWindow (NULL, "植物大战僵尸中文版");
	if (_hwnd == NULL)
	{
		::MessageBox (NULL, TEXT ("对不起,找不到窗口"), "植物大战僵尸中文版", MB_OK);
		return void ();
	}

	DWORD _tid = GetWindowThreadProcessId (_hwnd, &_pid);

	HANDLE _hThread = NULL;
	HANDLE _hProcess = NULL;
	_hThread = OpenThread (THREAD_ALL_ACCESS, FALSE, _tid);
	if (_hThread == NULL)
	{
		::MessageBox (NULL, TEXT ("获取线程句柄失败"), "植物大战僵尸中文版", MB_OK);
		return void ();
	}

	_hProcess = OpenProcess (PROCESS_ALL_ACCESS, FALSE, _pid);
	if (_hThread == NULL)
	{
		::MessageBox (NULL, TEXT ("获取进程句柄失败"), "植物大战僵尸中文版", MB_OK);
		return void ();
	}

	SuspendThread (_hThread);

	///		操作寄存器
	CONTEXT _ctx = { 0 };
	_ctx.ContextFlags =  CONTEXT_ALL;
	if (!GetThreadContext (_hThread, &_ctx))
	{
		CString erro;
		erro.Format ("错误1 %4d", GetLastError ());
		AfxMessageBox (erro, MB_OK);
	}

	CString cstr;
	cstr.Format ("EIP:	%4x", _ctx.Eip);
	AfxMessageBox (cstr, MB_OK);

	_ctx.Eax = 0;
	if (!::SetThreadContext (_hThread, &_ctx))
	{
		CString erro;
		erro.Format ("错误%4d", GetLastError ());
		AfxMessageBox (erro, MB_OK);
	}

	ResumeThread(_hThread);
	ResumeThread (_hThread);
}

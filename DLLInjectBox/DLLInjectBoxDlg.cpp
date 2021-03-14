
// DLLInjectBoxDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DLLInjectBox.h"
#include "DLLInjectBoxDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDLLInjectBoxDlg 对话框


IMPLEMENT_DYNAMIC(CDLLInjectBoxDlg, CDialogEx);

CDLLInjectBoxDlg::CDLLInjectBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLLINJECTBOX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = nullptr;
}

CDLLInjectBoxDlg::~CDLLInjectBoxDlg()
{
	// 如果该对话框有自动化代理，则
	//  此对话框的返回指针为 null，所以它知道
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != nullptr)
		m_pAutoProxy->m_pDialog = nullptr;
}

void CDLLInjectBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDLLInjectBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED (IDC_BUTTON_IM_EIP, &CDLLInjectBoxDlg::OnBnClickedButtonImEip)
	ON_BN_CLICKED (IDC_BUTTON_PATH_DLL, &CDLLInjectBoxDlg::OnBnClickedButtonPathDll)
END_MESSAGE_MAP()


// CDLLInjectBoxDlg 消息处理程序

BOOL CDLLInjectBoxDlg::OnInitDialog()
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

void CDLLInjectBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDLLInjectBoxDlg::OnPaint()
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
HCURSOR CDLLInjectBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void CDLLInjectBoxDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CDLLInjectBoxDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CDLLInjectBoxDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CDLLInjectBoxDlg::CanExit()
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



void CDLLInjectBoxDlg::OnBnClickedButtonImEip ()
{
	EipHook ();
}


void CDLLInjectBoxDlg::OnBnClickedButtonPathDll ()
{
	CFileDialog get_file_path (TRUE, 0, 0, 6UL, TEXT ("DLL Files|*.dll"));

	if (get_file_path.DoModal () == IDOK)
	{
		CString file_path;
		file_path = get_file_path.GetPathName ();
		SetDlgItemText (IDC_EDIT_PATH_DLL, file_path);
	}
}


void CDLLInjectBoxDlg::EipHook ()
{
	///		从edit控件获取DLL路径	
	int path_size = GetDlgItemText (IDC_EDIT_PATH_DLL, m_Path);
	if (path_size == 0)
	{
		AfxMessageBox ("路径不能为空", MB_OK);
		return void ();
	}

	///		从edit控件获取要注入的程序窗口名称	
	path_size = GetDlgItemText (IDC_EDIT_DLG_NAME, m_Dlgname);
	if (path_size == 0)
	{
		AfxMessageBox ("程序窗口名称不能为空");
		return void ();
	}

	HWND m_Hwnd = ::FindWindow (NULL, m_Dlgname);
	if (m_Hwnd == NULL)
	{
		::MessageBox (NULL, "未获取窗口句柄！", "EIP注入方法", MB_OK);
		return void ();
	}
	
	m_Tid = GetWindowThreadProcessId (m_Hwnd, &m_Pid);

	if (m_Tid <= 0)
	{
		::MessageBox (NULL, "未获取线程ID", "EIP注入方法", MB_OK);
		return void ();
	}

	if (m_Tid <= 0)
	{
		::MessageBox (NULL, "未获取进程ID", "EIP注入方法", MB_OK);
		return void ();
	}

	hProcess = OpenProcess (PROCESS_ALL_ACCESS, FALSE, m_Pid);
	if (!hProcess)
	{
		::MessageBox (NULL, "未获取进程句柄", "EIP注入方法", MB_OK);
		return void ();
	}

	hThread = OpenThread (THREAD_ALL_ACCESS, FALSE, m_Tid);
	if (!hThread)
	{
		::MessageBox (NULL, "未获取线程ID", "EIP注入方法", MB_OK);
		return void ();
	}

	if (SuspendThread (hThread) == -1)
	{
		CString strErr;
		strErr.Format (TEXT ("线程挂起失败:[%d]"), GetLastError ());
		::MessageBox (NULL, strErr, "EIP注入方法", MB_OK);
	}

	m_Ctt.ContextFlags = CONTEXT_CONTROL;
	GetThreadContext (hThread, &m_Ctt);
	///		判断EIP是否正常
	if(m_Ctt.Eip==0)
	{
		ResumeThread (hThread);
		CString strErr;
		strErr.Format (TEXT ("EIP为0:[%d]"), GetLastError ());
		::MessageBox (NULL, strErr, "EIP注入方法", MB_OK);
		return void ();
	}

	///		申请一块内存空间，用于写入DLL路径字符串
	SIZE_T	url_size = (_tcslen (m_Path) + 1) * sizeof (TCHAR);
	BYTE*	m_Allocaddr = (BYTE*)VirtualAllocEx (hProcess, NULL, path_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	if (!m_Allocaddr)
	{
		CString strErr;
		strErr.Format (TEXT ("内存分配失败:[%d]"), GetLastError ());

		::MessageBox (NULL, strErr, "EIP注入", MB_OK);
		return void ();
	}

	///		根据路径写入指定的DLL
	BOOL	write_rslt = WriteProcessMemory (hProcess, m_Allocaddr, m_Path, path_size, NULL);

	if (!write_rslt)
	{
		CString erro1;
		erro1.Format ("DLL路径写入失败%4d", GetLastError ());
		AfxMessageBox (erro1, MB_OK);
	}
	///		获取LoadLibraryW函数地址
	PTHREAD_START_ROUTINE m_PfnAddr = (PTHREAD_START_ROUTINE)GetProcAddress (GetModuleHandle (TEXT ("Kernel32.dll")), "LoadLibraryA");
	if (!m_PfnAddr)
	{
		DWORD erro = GetLastError ();
		CString strErr;
		strErr.Format (TEXT ("获取模块地址失败:[%d]"), erro);
		::MessageBox (NULL, strErr, "EIP注入", MB_OK);
		return void ();
	}
	///		通过Shellcode注入DLL
	BYTE m_ShellCode[32] = { 0 };;;
	//DWORD* m_PdwAddr = NULL;

	//m_ShellCode[0] = 0x60;												// pushad
	//m_ShellCode[1] = 0x9C;												// pushfd
	//m_ShellCode[2] = 0x68;												// push
	//m_PdwAddr = (DWORD *)&m_ShellCode[3];								// ShellCode[3/4/5/6]
	//*m_PdwAddr = (DWORD)(m_Allocaddr + 0x100);
	//m_ShellCode[7] = 0xE8;												//call
	//m_PdwAddr = (DWORD *)&m_ShellCode[8];								// ShellCode[8/9/10/11]
	//*m_PdwAddr = (DWORD)m_PfnAddr - ((DWORD)(m_Allocaddr + 7) + 5);
	//m_ShellCode[12] = 0x9D;												// popfd
	//m_ShellCode[13] = 0x61;												// popad
	//m_ShellCode[14] = 0xE9;												// jmp
	WriteProcessMemory (hProcess, m_Allocaddr, m_ShellCode, sizeof (m_ShellCode), NULL);
	m_Ctt.Eip = (DWORD)m_Allocaddr;

	SetThreadContext (hThread, &m_Ctt);

	ResumeThread (hThread);
	CloseHandle (hProcess);
	CloseHandle (hThread);
}

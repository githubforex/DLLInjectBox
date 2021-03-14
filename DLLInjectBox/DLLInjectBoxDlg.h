
// DLLInjectBoxDlg.h: 头文件
//

#pragma once

class CDLLInjectBoxDlgAutoProxy;


// CDLLInjectBoxDlg 对话框
class CDLLInjectBoxDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDLLInjectBoxDlg);
	friend class CDLLInjectBoxDlgAutoProxy;

// 构造
public:
	CDLLInjectBoxDlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CDLLInjectBoxDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLLINJECTBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CDLLInjectBoxDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonImEip ();
	afx_msg void OnBnClickedButtonPathDll ();
///		EIP注入
public:
	void EipHook ();
private:
	CString m_Path;
	CString m_Dlgname;
	DWORD m_Pid, m_Tid;
	HANDLE hProcess, hThread;
	CONTEXT m_Ctt = { 0 };
};

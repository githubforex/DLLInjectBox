
// PlantsVsInjectDlg.h: 头文件
//

#pragma once

class CPlantsVsInjectDlgAutoProxy;


// CPlantsVsInjectDlg 对话框
class CPlantsVsInjectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlantsVsInjectDlg);
	friend class CPlantsVsInjectDlgAutoProxy;

// 构造
public:
	CPlantsVsInjectDlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CPlantsVsInjectDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLANTSVSINJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CPlantsVsInjectDlgAutoProxy* m_pAutoProxy;
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
	afx_msg void OnBnClickedButtonRebuild ();
};

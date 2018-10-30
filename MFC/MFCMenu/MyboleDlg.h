#pragma once
#include "afxwin.h"


// CMyboleDlg 对话框

class CMyboleDlg : public CDialog
{
	DECLARE_DYNAMIC(CMyboleDlg)

public:
	CMyboleDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyboleDlg();

// 对话框数据
	enum { IDD = ID_Mybole };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnAdd();
private:
    CButton m_btn;
    bool m_bIsCreated;
public:
    afx_msg void OnEnChangeEdit2();
    afx_msg void OnStnClickedNumber1();
private:
    int m_num1;
public:
    int m_num2;
    int m_num3;
    CEdit m_edit3;
    afx_msg void OnBnClickedButton2();
    afx_msg void OnEnChangeEdit1();
    afx_msg void OnBnClickedOk();
};

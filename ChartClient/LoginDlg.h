#pragma once


// CLoginDlg 对话框

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
	enum { IDD = IDD_DLGLOGIN };

protected:
    HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnlogin();
    virtual BOOL OnInitDialog();
};

class TrafficMessage
{
public:
    bool AlreadyLogin;
    char Username[20];
    char Passwd[20];
    int quantity;
    int group;
    TrafficMessage()
    {
        AlreadyLogin=FALSE;
    }
};
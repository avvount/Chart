#pragma once


// CLoginDlg �Ի���

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

// �Ի�������
	enum { IDD = IDD_DLGLOGIN };

protected:
    HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
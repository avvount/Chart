
// EscapeDlg.h : ͷ�ļ�
//

#pragma once
#include "newbutton.h"


// CEscapeDlg �Ի���
class CEscapeDlg : public CDialog
{
// ����
public:
	CEscapeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ESCAPE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonEscape();
    CNewButton m_btn1;
    CNewButton m_btn2;
    afx_msg void OnBnClickedButtonEscape2();
};

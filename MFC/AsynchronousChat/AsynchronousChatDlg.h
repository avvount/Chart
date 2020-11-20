
// AsynchronousChatDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

// CAsynchronousChatDlg �Ի���
class CAsynchronousChatDlg : public CDialog
{
	// ����
  public:
	CAsynchronousChatDlg(CWnd *pParent = NULL); // ��׼���캯��
	~CAsynchronousChatDlg();
	// �Ի�������
	enum
	{
		IDD = IDD_ASYNCHRONOUSCHAT_DIALOG
	};

  protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV ֧��

	// ʵ��
  protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnSock(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
  private:
	bool InitSocket(void);
	SOCKET m_socket;

  public:
	afx_msg void OnBnClickedBtnsend();

  private:
	int m_Radio;
};

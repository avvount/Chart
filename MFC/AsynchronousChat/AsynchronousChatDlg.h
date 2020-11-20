
// AsynchronousChatDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

// CAsynchronousChatDlg 对话框
class CAsynchronousChatDlg : public CDialog
{
	// 构造
  public:
	CAsynchronousChatDlg(CWnd *pParent = NULL); // 标准构造函数
	~CAsynchronousChatDlg();
	// 对话框数据
	enum
	{
		IDD = IDD_ASYNCHRONOUSCHAT_DIALOG
	};

  protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

	// 实现
  protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

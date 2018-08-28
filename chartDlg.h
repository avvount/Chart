
// chartDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"



// CchartDlg 对话框
class CchartDlg : public CDialog
{
// 构造
public:
	CchartDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHART_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    int m_Quantity;
    int m_Groups;
    afx_msg void OnBnClickedGenerate();
    int** m_pData;
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    CListCtrl m_List;
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

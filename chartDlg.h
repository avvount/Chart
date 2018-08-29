
// chartDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxext.h"
#include "NewListCtrl.h"


// CchartDlg �Ի���
class CchartDlg : public CDialog
{
// ����
public:
	CchartDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHART_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
    CNewListCtrl m_List;
	afx_msg void OnSize(UINT nType, int cx, int cy);
    void DrawLine(void);
private:
    CStatusBar m_wndStatusBar;
public:
    afx_msg void OnSetting();
private:
    void ResizeList(void);
public:
private:
    void GenerateList(void);
};

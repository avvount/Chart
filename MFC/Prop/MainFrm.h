
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "afxext.h"
#define UM_PROGRESS WM_USER+1
class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg LRESULT OnProgress(WPARAM,LPARAM);
	DECLARE_MESSAGE_MAP()

private:
    HICON m_Icon[3];
public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
    CToolBar m_WndToolBar;
    CProgressCtrl m_progress;
public:
    afx_msg void OnPaint();
};



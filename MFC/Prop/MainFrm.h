
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "afxext.h"
#define UM_PROGRESS WM_USER+1
class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
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




// MFCMenuView.h : CMFCMenuView 类的接口
//


#pragma once
#include "afxwin.h"

#define NUMPRE   1595
class CMFCMenuView: public CView
{
protected: // 仅从序列化创建
	CMFCMenuView();
	DECLARE_DYNCREATE(CMFCMenuView)

// 属性
public:
	CMFCMenuDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:

    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
private:
    int m_nIndex;
    CMenu m_menu;
public:
    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
    CString m_strName;
    CString m_strNum;
    bool m_bFlag;
public:
    afx_msg void OnDialog();
//    afx_msg void On32771();
};

#ifndef _DEBUG  // MFCMenuView.cpp 中的调试版本
inline CMFCMenuDoc* CMFCMenuView::GetDocument() const
   { return reinterpret_cast<CMFCMenuDoc*>(m_pDocument); }
#endif


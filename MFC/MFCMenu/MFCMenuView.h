
// MFCMenuView.h : CMFCMenuView ��Ľӿ�
//


#pragma once
#include "afxwin.h"

#define NUMPRE   1595
class CMFCMenuView: public CView
{
protected: // �������л�����
	CMFCMenuView();
	DECLARE_DYNCREATE(CMFCMenuView)

// ����
public:
	CMFCMenuDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // MFCMenuView.cpp �еĵ��԰汾
inline CMFCMenuDoc* CMFCMenuView::GetDocument() const
   { return reinterpret_cast<CMFCMenuDoc*>(m_pDocument); }
#endif


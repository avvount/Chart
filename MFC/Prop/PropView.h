
// PropView.h : CPropView ��Ľӿ�
//


#pragma once


class CPropView : public CView
{
protected: // �������л�����
	CPropView();
	DECLARE_DYNCREATE(CPropView)

// ����
public:
	CPropDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CPropView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnProperty();
private:
    int m_iOccupation;
    CString m_strWorkAddr;
    bool m_bLike[4];
    CString m_strSalary;
public:
    afx_msg void OnDot();
    afx_msg void OnLine();
    afx_msg void OnRectangle();
    afx_msg void OnEllipse();
private:
    int m_nDrawType;
    CPoint m_ptOrigin;
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // PropView.cpp �еĵ��԰汾
inline CPropDoc* CPropView::GetDocument() const
   { return reinterpret_cast<CPropDoc*>(m_pDocument); }
#endif


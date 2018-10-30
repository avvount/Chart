
// ReadWriteView.h : CReadWriteView ��Ľӿ�
//


#pragma once


class CReadWriteView : public CView
{
protected: // �������л�����
	CReadWriteView();
	DECLARE_DYNCREATE(CReadWriteView)

// ����
public:
	CReadWriteDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CReadWriteView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnMfcread();
    afx_msg void OnMfcwrite();
private:
    char *p;
    int count;
public:
    afx_msg void OnRegWrite();
    afx_msg void OnRegRead();
    afx_msg void OnArchiveload();
    afx_msg void OnArchivestore();
    afx_msg void OnCustomCppread();
    afx_msg void OnCustomCppwrite();
    afx_msg void OnCustomApiread();
//    afx_msg void OnCustomApiwrite();
};

#ifndef _DEBUG  // ReadWriteView.cpp �еĵ��԰汾
inline CReadWriteDoc* CReadWriteView::GetDocument() const
   { return reinterpret_cast<CReadWriteDoc*>(m_pDocument); }
#endif


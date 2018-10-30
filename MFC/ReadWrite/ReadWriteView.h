
// ReadWriteView.h : CReadWriteView 类的接口
//


#pragma once


class CReadWriteView : public CView
{
protected: // 仅从序列化创建
	CReadWriteView();
	DECLARE_DYNCREATE(CReadWriteView)

// 属性
public:
	CReadWriteDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CReadWriteView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // ReadWriteView.cpp 中的调试版本
inline CReadWriteDoc* CReadWriteView::GetDocument() const
   { return reinterpret_cast<CReadWriteDoc*>(m_pDocument); }
#endif


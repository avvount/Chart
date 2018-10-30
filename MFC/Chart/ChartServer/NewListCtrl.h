#if !defined(AFX_LINECOLORLISTCTRL_H__92EB1CD4_CD33_4E02_A098_367A8FEFF38E__INCLUDED_)
#define AFX_LINECOLORLISTCTRL_H__92EB1CD4_CD33_4E02_A098_367A8FEFF38E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LineColorListCtrl.h : header file
//

#include <afxtempl.h>



class CNewListCtrl : public CListCtrl
{
public:
    void SetItemColor(DWORD iItem,  COLORREF TextBkColor);    //设置某一行背景色

public:
    CMap<DWORD, DWORD &, COLORREF, COLORREF &> MapItemColor;

    // Generated message map functions
protected:
    //{{AFX_MSG(CLineColorListCtrl)
    // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_MSG
    void CNewListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);

    DECLARE_MESSAGE_MAP()
public:
//    afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINECOLORLISTCTRL_H__92EB1CD4_CD33_4E02_A098_367A8FEFF38E__INCLUDED_)

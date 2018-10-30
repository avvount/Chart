#pragma once
#include "afxext.h"

class CCustomStatusBar :
    public CStatusBar
{
public:
    CCustomStatusBar(void);
    ~CCustomStatusBar(void);
    void SetTextColor(COLORREF clrText);
    DECLARE_MESSAGE_MAP()
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
    COLORREF m_clrText;
};

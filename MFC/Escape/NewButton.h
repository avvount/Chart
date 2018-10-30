#pragma once
#include "afxwin.h"

class CNewButton :
    public CButton
{
public:
    CNewButton(void);
    ~CNewButton(void);
    DECLARE_MESSAGE_MAP()
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);

public:
    CNewButton* m_pBtn;
};

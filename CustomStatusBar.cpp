#include "StdAfx.h"
#include "CustomStatusBar.h"

CCustomStatusBar::CCustomStatusBar(void)
{
}

CCustomStatusBar::~CCustomStatusBar(void)
{
}
BEGIN_MESSAGE_MAP(CCustomStatusBar, CStatusBar)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

HBRUSH CCustomStatusBar::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CStatusBar::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO:  在此更改 DC 的任何属性
    pDC->SetTextColor(m_clrText);
    // TODO:  如果默认的不是所需画笔，则返回另一个画笔
    return hbr;
}

void CCustomStatusBar::SetTextColor(COLORREF clrText)
{
    m_clrText=clrText;
    Invalidate();
}

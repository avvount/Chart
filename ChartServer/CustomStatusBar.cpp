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

    // TODO:  �ڴ˸��� DC ���κ�����
    pDC->SetTextColor(m_clrText);
    // TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
    return hbr;
}

void CCustomStatusBar::SetTextColor(COLORREF clrText)
{
    m_clrText=clrText;
    Invalidate();
}

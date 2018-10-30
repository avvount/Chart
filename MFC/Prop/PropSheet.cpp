#include "StdAfx.h"
#include "PropSheet.h"

CPropSheet::CPropSheet(void)

{
}
//CPropSheet::CPropSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
//:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
//{
//}

CPropSheet::CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
    AddPage(&m_prop1);
    AddPage(&m_prop2);
    AddPage(&m_prop3);
}

CPropSheet::~CPropSheet(void)
{
}

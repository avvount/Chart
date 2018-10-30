#pragma once
#include "afxdlgs.h"
#include "prop1.h"
#include "prop2.h"
#include "prop3.h"

class CPropSheet :
    public CPropertySheet
{
public:
    CPropSheet(void);
    //CPropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
    CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
    ~CPropSheet(void);
    CProp1 m_prop1;
    CProp2 m_prop2;
    CProp3 m_prop3;

};

// Prop2.cpp : 实现文件
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop2.h"


// CProp2 对话框

IMPLEMENT_DYNAMIC(CProp2, CPropertyPage)

CProp2::CProp2()
	: CPropertyPage(CProp2::IDD)
    , m_bFootball(FALSE)
    , m_bBasketball(FALSE)
    , m_bVolleyball(FALSE)
    , m_bSwim(FALSE)
{

}

CProp2::~CProp2()
{
}

void CProp2::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DDX_Check(pDX, IDC_CHECK1, m_bFootball);
    DDX_Check(pDX, IDC_CHECK2, m_bBasketball);
    DDX_Check(pDX, IDC_CHECK3, m_bVolleyball);
    DDX_Check(pDX, IDC_CHECK4, m_bSwim);
}


BEGIN_MESSAGE_MAP(CProp2, CPropertyPage)
END_MESSAGE_MAP()


// CProp2 消息处理程序

BOOL CProp2::OnSetActive()
{
    // TODO: 在此添加专用代码和/或调用基类
    ((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);
    return CPropertyPage::OnSetActive();
}

LRESULT CProp2::OnWizardNext()
{
    // TODO: 在此添加专用代码和/或调用基类
    UpdateData();
    if (m_bFootball||m_bBasketball||m_bVolleyball||m_bSwim)
    {
        return CPropertyPage::OnWizardNext();
    }

    MessageBox("请至少选择一项爱好 !!!");
    return -1;
    
}

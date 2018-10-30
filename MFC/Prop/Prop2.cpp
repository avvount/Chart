// Prop2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop2.h"


// CProp2 �Ի���

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


// CProp2 ��Ϣ�������

BOOL CProp2::OnSetActive()
{
    // TODO: �ڴ����ר�ô����/����û���
    ((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);
    return CPropertyPage::OnSetActive();
}

LRESULT CProp2::OnWizardNext()
{
    // TODO: �ڴ����ר�ô����/����û���
    UpdateData();
    if (m_bFootball||m_bBasketball||m_bVolleyball||m_bSwim)
    {
        return CPropertyPage::OnWizardNext();
    }

    MessageBox("������ѡ��һ��� !!!");
    return -1;
    
}

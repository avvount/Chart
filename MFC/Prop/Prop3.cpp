// Prop3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop3.h"


// CProp3 �Ի���

IMPLEMENT_DYNAMIC(CProp3, CPropertyPage)

CProp3::CProp3()
	: CPropertyPage(CProp3::IDD)
    , m_strSalary(_T(""))
{

}

CProp3::~CProp3()
{
}

void CProp3::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DDX_CBString(pDX, IDC_COMBO1, m_strSalary);
}


BEGIN_MESSAGE_MAP(CProp3, CPropertyPage)
END_MESSAGE_MAP()


// CProp3 ��Ϣ�������

BOOL CProp3::OnSetActive()
{
    // TODO: �ڴ����ר�ô����/����û���
    ((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_FINISH|PSWIZB_BACK);
    return CPropertyPage::OnSetActive();
}

BOOL CProp3::OnInitDialog()
{
    CPropertyPage::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("1000Ԫ����");
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("1000-2000Ԫ");
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("2000-3000Ԫ");
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("3000Ԫ����");
    //((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(1);
    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CProp3::OnWizardFinish()
{
    // TODO: �ڴ����ר�ô����/����û���
    UpdateData();
    if (m_strSalary=="")
    {
        MessageBox("��ѡ��н��ˮƽ !!!");
        return 0;
    }
    return CPropertyPage::OnWizardFinish();
}

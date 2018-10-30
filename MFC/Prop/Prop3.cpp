// Prop3.cpp : 实现文件
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop3.h"


// CProp3 对话框

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


// CProp3 消息处理程序

BOOL CProp3::OnSetActive()
{
    // TODO: 在此添加专用代码和/或调用基类
    ((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_FINISH|PSWIZB_BACK);
    return CPropertyPage::OnSetActive();
}

BOOL CProp3::OnInitDialog()
{
    CPropertyPage::OnInitDialog();

    // TODO:  在此添加额外的初始化
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("1000元以下");
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("1000-2000元");
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("2000-3000元");
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("3000元以上");
    //((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(1);
    return TRUE;  // return TRUE unless you set the focus to a control
    // 异常: OCX 属性页应返回 FALSE
}

BOOL CProp3::OnWizardFinish()
{
    // TODO: 在此添加专用代码和/或调用基类
    UpdateData();
    if (m_strSalary=="")
    {
        MessageBox("请选择薪资水平 !!!");
        return 0;
    }
    return CPropertyPage::OnWizardFinish();
}

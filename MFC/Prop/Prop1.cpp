// Prop1.cpp : 实现文件
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop1.h"


// CProp1 对话框

IMPLEMENT_DYNAMIC(CProp1, CPropertyPage)

CProp1::CProp1()
	: CPropertyPage(CProp1::IDD)
    , m_occupation(-1)
    , m_strworkAddr("")
{

}

CProp1::~CProp1()
{
}

void CProp1::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DDX_Radio(pDX, IDC_RADIO1, m_occupation);
    DDX_LBString(pDX, IDC_LIST1, m_strworkAddr);
}


BEGIN_MESSAGE_MAP(CProp1, CPropertyPage)
    ON_BN_CLICKED(IDC_RADIO1, &CProp1::OnBnClickedRadio1)
END_MESSAGE_MAP()


// CProp1 消息处理程序

BOOL CProp1::OnSetActive()
{
    // TODO: 在此添加专用代码和/或调用基类
    ((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_CANCEL);

    return CPropertyPage::OnSetActive();
}

LRESULT CProp1::OnWizardNext()
{
    // TODO: 在此添加专用代码和/或调用基类
    UpdateData();
    if (-1==m_occupation)
    {
        MessageBox("请选择职业");
        return -1;
    }
    if (m_strworkAddr=="")
    {
        MessageBox("请输入工作地点");
        return -1;
    }
    return CPropertyPage::OnWizardNext();
}

void CProp1::OnBnClickedRadio1()
{
    // TODO: 在此添加控件通知处理程序代码
    UpdateData();
    if (-1!=m_occupation)
    {
        ((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);
    }
   
}

BOOL CProp1::OnInitDialog()
{
    CPropertyPage::OnInitDialog();

    // TODO:  在此添加额外的初始化
    ((CListBox*)GetDlgItem(IDC_LIST1))->AddString("北京");
    ((CListBox*)GetDlgItem(IDC_LIST1))->AddString("上海");
    ((CListBox*)GetDlgItem(IDC_LIST1))->AddString("天津");


    return TRUE;  // return TRUE unless you set the focus to a control
    // 异常: OCX 属性页应返回 FALSE
}

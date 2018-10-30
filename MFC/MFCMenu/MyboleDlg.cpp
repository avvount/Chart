// MyboleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCMenu.h"
#include "MyboleDlg.h"


// CMyboleDlg 对话框

IMPLEMENT_DYNAMIC(CMyboleDlg, CDialog)

CMyboleDlg::CMyboleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyboleDlg::IDD, pParent)
    , m_bIsCreated(false)
    , m_num1(0)
    , m_num2(0)
    , m_num3(0)
{
   
}

CMyboleDlg::~CMyboleDlg()
{
}

void CMyboleDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT2, m_num1);
    DDX_Text(pDX, IDC_EDIT1, m_num2);
    DDX_Text(pDX, IDC_EDIT3, m_num3);
    DDX_Control(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CMyboleDlg, CDialog)
    ON_BN_CLICKED(IDC_BTN_ADD, &CMyboleDlg::OnBnClickedBtnAdd)
    ON_EN_CHANGE(IDC_EDIT2, &CMyboleDlg::OnEnChangeEdit2)
    ON_STN_CLICKED(IDC_NUMBER1, &CMyboleDlg::OnStnClickedNumber1)
    ON_BN_CLICKED(IDC_BUTTON2, &CMyboleDlg::OnBnClickedButton2)
    ON_EN_CHANGE(IDC_EDIT1, &CMyboleDlg::OnEnChangeEdit1)
    ON_BN_CLICKED(IDOK, &CMyboleDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyboleDlg 消息处理程序

void CMyboleDlg::OnBnClickedBtnAdd()
{
    // TODO: 在此添加控件通知处理程序代码
    
    /*if (!m_bIsCreated)
    {
        m_btn.Create("New",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_CHILD,
            CRect(0,0,100,100),this,942);
    }
    else    
    {
        m_btn.DestroyWindow();
    }*/
  /*  if (m_btn.m_hWnd)
    {
        m_btn.DestroyWindow();
    }
    else
    {
        m_btn.Create("New",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_CHILD,
            CRect(0,0,100,100),this,942);
    }*/
    //m_bIsCreated = !m_bIsCreated;
    /*char s1[10],s2[10],s3[10];

    GetDlgItem(IDC_EDIT2)->GetWindowText(s2,10);
    GetDlgItem(IDC_EDIT1)->GetWindowText(s1,10);
    int num1=atoi(s1);
    int num2=atoi(s2);
    int num3=num2+num1;
    itoa(num3,s3,10);
    GetDlgItem(IDC_EDIT3)->SetWindowText(s3);*/
    UpdateData();
    m_num3=m_num1+m_num2;
    //m_edit3.SetFocus();
    UpdateData(false);
    
}

void CMyboleDlg::OnEnChangeEdit2()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialog::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}

void CMyboleDlg::OnStnClickedNumber1()
{
    // TODO: 在此添加控件通知处理程序代码
    CString str;
    GetDlgItem(IDC_NUMBER1)->GetWindowText(str);
    if (str=="Number1")
    {
        GetDlgItem(IDC_NUMBER1)->SetWindowText("数值");
    } 
    else
    {
        GetDlgItem(IDC_NUMBER1)->SetWindowText("Number1");
    }
}

void CMyboleDlg::OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码

    static CRect rectSmall,rectLarge;
    if (rectLarge.IsRectEmpty())
    {
        GetWindowRect(&rectLarge);
        
        CRect rectSeparator;
        GetDlgItem(IDC_SEPARATOR)->GetWindowRect(&rectSeparator);
        rectSmall=rectLarge;
        rectSmall.right=rectSeparator.right;
    }
    CString str;
    GetDlgItemText(IDC_BUTTON2,str);
    if (str=="收缩<<")
    {
        GetDlgItem(IDC_BUTTON2)->SetWindowText("扩展>>");
        SetWindowPos(NULL,rectSmall.left,rectSmall.top,rectSmall.Width()
            ,rectSmall.Height(),SWP_NOMOVE|SWP_NOZORDER);
    }
    else
    {
        GetDlgItem(IDC_BUTTON2)->SetWindowText("收缩<<");
        SetWindowPos(NULL,rectSmall.left,rectSmall.top,rectLarge.Width()
            ,rectSmall.Height(),SWP_NOMOVE|SWP_NOZORDER);
    }
}

void CMyboleDlg::OnEnChangeEdit1()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialog::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}

void CMyboleDlg::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    GetNextDlgTabItem(GetFocus())->SetFocus();
    
    
    //OnOK();
}

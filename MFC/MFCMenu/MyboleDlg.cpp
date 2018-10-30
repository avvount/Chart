// MyboleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCMenu.h"
#include "MyboleDlg.h"


// CMyboleDlg �Ի���

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


// CMyboleDlg ��Ϣ�������

void CMyboleDlg::OnBnClickedBtnAdd()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    
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
    // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
    // ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
    // ���������� CRichEditCtrl().SetEventMask()��
    // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CMyboleDlg::OnStnClickedNumber1()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CString str;
    GetDlgItem(IDC_NUMBER1)->GetWindowText(str);
    if (str=="Number1")
    {
        GetDlgItem(IDC_NUMBER1)->SetWindowText("��ֵ");
    } 
    else
    {
        GetDlgItem(IDC_NUMBER1)->SetWindowText("Number1");
    }
}

void CMyboleDlg::OnBnClickedButton2()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

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
    if (str=="����<<")
    {
        GetDlgItem(IDC_BUTTON2)->SetWindowText("��չ>>");
        SetWindowPos(NULL,rectSmall.left,rectSmall.top,rectSmall.Width()
            ,rectSmall.Height(),SWP_NOMOVE|SWP_NOZORDER);
    }
    else
    {
        GetDlgItem(IDC_BUTTON2)->SetWindowText("����<<");
        SetWindowPos(NULL,rectSmall.left,rectSmall.top,rectLarge.Width()
            ,rectSmall.Height(),SWP_NOMOVE|SWP_NOZORDER);
    }
}

void CMyboleDlg::OnEnChangeEdit1()
{
    // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
    // ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
    // ���������� CRichEditCtrl().SetEventMask()��
    // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CMyboleDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    GetNextDlgTabItem(GetFocus())->SetFocus();
    
    
    //OnOK();
}

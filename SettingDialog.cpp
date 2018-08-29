// SettingDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "chart.h"
#include "SettingDialog.h"


// CSettingDialog 对话框

IMPLEMENT_DYNAMIC(CSettingDialog, CDialog)

CSettingDialog::CSettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDialog::IDD, pParent)
{
    m_clrCoordinate=RGB(0,0,0);
    m_clrLine1=RGB(0,0,255);
    m_clrLine2=RGB(0,255,0);
    m_clrLine3=RGB(255,0,0);
    m_clrLine4=RGB(255,0,255);
    m_clrLine5=RGB(0,255,255);
}

CSettingDialog::~CSettingDialog()
{
}

void CSettingDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COORDINATE, m_Coordinate);
    DDX_Control(pDX, IDC_LINE1, m_Line1);
    DDX_Control(pDX, IDC_LINE2, m_Line2);
    DDX_Control(pDX, IDC_LINE3, m_Line3);
    DDX_Control(pDX, IDC_LINE4, m_Line4);
    DDX_Control(pDX, IDC_LINE5, m_Line5);
}


BEGIN_MESSAGE_MAP(CSettingDialog, CDialog)
    ON_BN_CLICKED(IDC_COORDINATE, &CSettingDialog::OnBnClickedCoordinate)
    ON_WM_CREATE()
    ON_BN_CLICKED(IDC_LINE1, &CSettingDialog::OnBnClickedLine1)
    ON_BN_CLICKED(IDC_LINE2, &CSettingDialog::OnBnClickedLine2)
    ON_BN_CLICKED(IDC_LINE3, &CSettingDialog::OnBnClickedLine3)
    ON_BN_CLICKED(IDC_LINE4, &CSettingDialog::OnBnClickedLine4)
    ON_BN_CLICKED(IDC_LINE5, &CSettingDialog::OnBnClickedLine5)
END_MESSAGE_MAP()


// CSettingDialog 消息处理程序

void CSettingDialog::OnBnClickedCoordinate()
{
    // TODO: 在此添加控件通知处理程序代码
 CColorDialog clrdlg;
 if (IDOK==clrdlg.DoModal())
 {
    m_clrCoordinate=clrdlg.m_cc.rgbResult;
    m_Coordinate.SetFaceColor(m_clrCoordinate);
 }


}

int CSettingDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;

  
    // TODO:  在此添加您专用的创建代码
    return 0;
}


BOOL CSettingDialog::OnInitDialog()

{

    CDialog::OnInitDialog();

    //在这里添加你的初始化函数
  
    m_Coordinate.SetFaceColor(m_clrCoordinate);
    m_Coordinate.SetTextColor(RGB(255,255,255));
    m_Line1.SetFaceColor(m_clrLine1);
    m_Line2.SetFaceColor(m_clrLine2);
    m_Line3.SetFaceColor(m_clrLine3);
    m_Line4.SetFaceColor(m_clrLine4);
    m_Line5.SetFaceColor(m_clrLine5);
    return 0;

}
void CSettingDialog::OnBnClickedLine1()
{
    // TODO: 在此添加控件通知处理程序代码
    CColorDialog clrdlg;
    if (IDOK==clrdlg.DoModal())
    {
        m_clrLine1=clrdlg.m_cc.rgbResult;
        m_Line1.SetFaceColor(m_clrLine1);
    }
}

void CSettingDialog::OnBnClickedLine2()
{
    // TODO: 在此添加控件通知处理程序代码
    CColorDialog clrdlg;
    if (IDOK==clrdlg.DoModal())
    {
        m_clrLine2=clrdlg.m_cc.rgbResult;
        m_Line2.SetFaceColor(m_clrLine2);
    }
}

void CSettingDialog::OnBnClickedLine3()
{
    // TODO: 在此添加控件通知处理程序代码
    CColorDialog clrdlg;
    if (IDOK==clrdlg.DoModal())
    {
        m_clrLine3=clrdlg.m_cc.rgbResult;
        m_Line3.SetFaceColor(m_clrLine3);
    }
}

void CSettingDialog::OnBnClickedLine4()
{
    // TODO: 在此添加控件通知处理程序代码
    CColorDialog clrdlg;
    if (IDOK==clrdlg.DoModal())
    {
        m_clrLine4=clrdlg.m_cc.rgbResult;
        m_Line4.SetFaceColor(m_clrLine4);
    }
}

void CSettingDialog::OnBnClickedLine5()
{
    // TODO: 在此添加控件通知处理程序代码
    CColorDialog clrdlg;
    if (IDOK==clrdlg.DoModal())
    {
        m_clrLine5=clrdlg.m_cc.rgbResult;
        m_Line5.SetFaceColor(m_clrLine5);
    }
}

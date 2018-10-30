// SettingDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "chart.h"
#include "SettingDialog.h"

// CSettingDialog �Ի���

IMPLEMENT_DYNAMIC(CSettingDialog, CDialog)

CSettingDialog::CSettingDialog(CWnd *pParent /*=NULL*/)
    : CDialog(CSettingDialog::IDD, pParent)
{
}

CSettingDialog::~CSettingDialog()
{
}

void CSettingDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COORDINATE, m_Coordinate);
    DDX_Control(pDX, IDC_LINE1, m_btnLine1);
    DDX_Control(pDX, IDC_LINE2, m_btnLine2);
    DDX_Control(pDX, IDC_LINE3, m_btnLine3);
    DDX_Control(pDX, IDC_LINE4, m_btnLine4);
    DDX_Control(pDX, IDC_LINE5, m_btnLine5);
    DDX_Control(pDX, IDC_ODDLINE, m_btnOddLine);
    DDX_Control(pDX, IDC_EVENLINE, m_btnEvenLine);
    DDX_Control(pDX, IDC_CHOOSENLINE, m_btnSelectedLine);
    DDX_Control(pDX, IDC_STATUSBAR, m_btnStatusBar);
}

BEGIN_MESSAGE_MAP(CSettingDialog, CDialog)
ON_BN_CLICKED(IDC_COORDINATE, &CSettingDialog::OnBnClickedCoordinate)
ON_WM_CREATE()
ON_BN_CLICKED(IDC_LINE1, &CSettingDialog::OnBnClickedLine1)
ON_BN_CLICKED(IDC_LINE2, &CSettingDialog::OnBnClickedLine2)
ON_BN_CLICKED(IDC_LINE3, &CSettingDialog::OnBnClickedLine3)
ON_BN_CLICKED(IDC_LINE4, &CSettingDialog::OnBnClickedLine4)
ON_BN_CLICKED(IDC_LINE5, &CSettingDialog::OnBnClickedLine5)
ON_BN_CLICKED(IDC_ODDLINE, &CSettingDialog::OnBnClickedOddline)
ON_BN_CLICKED(IDC_EVENLINE, &CSettingDialog::OnBnClickedEvenline)
ON_BN_CLICKED(IDC_CHOOSENLINE, &CSettingDialog::OnBnClickedChoosenline)
ON_BN_CLICKED(IDC_STATUSBAR, &CSettingDialog::OnBnClickedStatusbar)
END_MESSAGE_MAP()

// CSettingDialog ��Ϣ�������

void CSettingDialog::OnBnClickedCoordinate()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrCoordinate = clrdlg.m_cc.rgbResult;
        m_Coordinate.SetFaceColor(m_clrCoordinate);
    }
}

int CSettingDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  �ڴ������ר�õĴ�������
    return 0;
}

BOOL CSettingDialog::OnInitDialog()

{

    CDialog::OnInitDialog();

    //�����������ĳ�ʼ������

    m_Coordinate.SetFaceColor(m_clrCoordinate);
    m_Coordinate.SetTextColor(RGB(255, 255, 255));
    m_btnLine1.SetFaceColor(m_clrLine1);
    m_btnLine2.SetFaceColor(m_clrLine2);
    m_btnLine3.SetFaceColor(m_clrLine3);
    m_btnLine4.SetFaceColor(m_clrLine4);
    m_btnLine5.SetFaceColor(m_clrLine5);
    m_btnOddLine.SetFaceColor(m_clrOddLine);
    m_btnEvenLine.SetFaceColor(m_clrEvenLine);
    m_btnSelectedLine.SetFaceColor(m_clrSelected);
    m_btnStatusBar.SetFaceColor(m_clrStatusBar);
    return 0;
}
void CSettingDialog::OnBnClickedLine1()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrLine1 = clrdlg.m_cc.rgbResult;
        m_btnLine1.SetFaceColor(m_clrLine1);
    }
}

void CSettingDialog::OnBnClickedLine2()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrLine2 = clrdlg.m_cc.rgbResult;
        m_btnLine2.SetFaceColor(m_clrLine2);
    }
}

void CSettingDialog::OnBnClickedLine3()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrLine3 = clrdlg.m_cc.rgbResult;
        m_btnLine3.SetFaceColor(m_clrLine3);
    }
}

void CSettingDialog::OnBnClickedLine4()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrLine4 = clrdlg.m_cc.rgbResult;
        m_btnLine4.SetFaceColor(m_clrLine4);
    }
}

void CSettingDialog::OnBnClickedLine5()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrLine5 = clrdlg.m_cc.rgbResult;
        m_btnLine5.SetFaceColor(m_clrLine5);
    }
}

void CSettingDialog::OnBnClickedOddline()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrOddLine = clrdlg.m_cc.rgbResult;
        m_btnOddLine.SetFaceColor(m_clrOddLine);
    }
}

void CSettingDialog::OnBnClickedEvenline()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrEvenLine = clrdlg.m_cc.rgbResult;
        m_btnEvenLine.SetFaceColor(m_clrEvenLine);
    }
}

void CSettingDialog::OnBnClickedChoosenline()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrSelected = clrdlg.m_cc.rgbResult;
        m_btnSelectedLine.SetFaceColor(m_clrSelected);
    }
}

void CSettingDialog::OnBnClickedStatusbar()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

    CColorDialog clrdlg;
    if (IDOK == clrdlg.DoModal())
    {
        m_clrStatusBar = clrdlg.m_cc.rgbResult;
        m_btnStatusBar.SetFaceColor(m_clrStatusBar);
    }
}


// ChartClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ChartClient.h"
#include "ChartClientDlg.h"
#include "LoginDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

TrafficMessage tfmg;
SOCKET sockClient;
sockaddr_in addrSrv;

// CChartClientDlg 对话框

CChartClientDlg::CChartClientDlg(CWnd *pParent /*=NULL*/)
    : CDialog(CChartClientDlg::IDD, pParent), m_pdata(NULL)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
CChartClientDlg::~CChartClientDlg()
{
    closesocket(sockClient);
}
void CChartClientDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CChartClientDlg, CDialog)
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
//}}AFX_MSG_MAP
ON_BN_CLICKED(IDC_BTNSEND, &CChartClientDlg::OnBnClickedBtnsend)
ON_BN_CLICKED(IDC_BTNLOGOUT, &CChartClientDlg::OnBnClickedBtnlogout)
END_MESSAGE_MAP()

// CChartClientDlg 消息处理程序

BOOL CChartClientDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
    //  执行此操作
    SetIcon(m_hIcon, TRUE);  // 设置大图标
    SetIcon(m_hIcon, FALSE); // 设置小图标

    // TODO: 在此添加额外的初始化代码

    //CListCtrl表头
    m_List.ModifyStyle(0, LVS_REPORT); // 报表模式
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
    m_List.InsertColumn(0, "编号");
    m_List.InsertColumn(1, "第一组");
    m_List.InsertColumn(2, "第二组");
    m_List.InsertColumn(3, "第三组");
    m_List.InsertColumn(4, "第四组");
    m_List.InsertColumn(5, "第五组");
    CRect rect;
    GetClientRect(&rect);
    for (int i = 0; i < 6; i++)
    {
        m_List.SetColumnWidth(i, rect.Width() / 7); //设置列的宽度。
    }

    return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChartClientDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // 用于绘制的设备上下文

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 使图标在工作区矩形中居中
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 绘制图标
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialog::OnPaint();
    }
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChartClientDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CChartClientDlg::OnBnClickedBtnsend()
{
    // TODO: 在此添加控件通知处理程序代码
    if (m_pdata)
    {
        for (int i = 0; i < tfmg.quantity; i++)
        {
            delete[] m_pdata[i];
        }
        delete[] m_pdata;
        m_pdata = NULL;
    }
    CString strTemp;
    GetDlgItemText(IDC_EDIT_COMMAND, strTemp);
    SetDlgItemText(IDC_EDIT_COMMAND, "");
    int firstIndex = strTemp.Find(' ', 0);
    int lastIndex = strTemp.Find(' ', firstIndex + 1);
    CString strCommand = strTemp.Left(firstIndex);
    if (strCommand.Compare("test"))
    {
        MessageBox("test [column] [row]", "Usage");
        return;
    }
    CString strQuantity = strTemp.Left(lastIndex).Right(lastIndex - firstIndex - 1);
    CString strGroup = strTemp.Right(strTemp.GetLength() - lastIndex);
    tfmg.quantity = atoi(strQuantity.GetBuffer());
    tfmg.group = atoi(strGroup.GetBuffer());
    if (!tfmg.quantity || !tfmg.group)
    {
        MessageBox("请输入正确参数", "参数错误");
        return;
    }
    send(sockClient, (char *)&tfmg, sizeof(tfmg), 0);
    char **recvBuf = new char *[sizeof(int *) * tfmg.quantity];
    for (int i = 0; i < tfmg.quantity; i++)
    {
        recvBuf[i] = new char[sizeof(int) * tfmg.group];
        recv(sockClient, recvBuf[i], tfmg.group * sizeof(int), 0);
    }
    m_pdata = (int **)recvBuf;
    m_List.DeleteAllItems();
    CString str;
    for (int i = 0; i < tfmg.quantity; i++)
    {
        str.Format("%d", i + 1);
        m_List.InsertItem(i, str);

        for (int j = 0; j < tfmg.group; j++)
        {
            str.Format("%d", m_pdata[i][j]);
            m_List.SetItemText(i, j + 1, str);
        }
        for (int j = tfmg.group; j < 5; j++)
        {
            m_List.SetItemText(i, j + 1, "0");
        }
    }
}

void CChartClientDlg::OnBnClickedBtnlogout()
{
    // TODO: 在此添加控件通知处理程序代码
    WinExec(__argv[0], SW_SHOW);
    exit(0);
}

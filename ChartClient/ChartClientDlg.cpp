
// ChartClientDlg.cpp : ʵ���ļ�
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

// CChartClientDlg �Ի���

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

// CChartClientDlg ��Ϣ�������

BOOL CChartClientDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);  // ���ô�ͼ��
    SetIcon(m_hIcon, FALSE); // ����Сͼ��

    // TODO: �ڴ���Ӷ���ĳ�ʼ������

    //CListCtrl��ͷ
    m_List.ModifyStyle(0, LVS_REPORT); // ����ģʽ
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
    m_List.InsertColumn(0, "���");
    m_List.InsertColumn(1, "��һ��");
    m_List.InsertColumn(2, "�ڶ���");
    m_List.InsertColumn(3, "������");
    m_List.InsertColumn(4, "������");
    m_List.InsertColumn(5, "������");
    CRect rect;
    GetClientRect(&rect);
    for (int i = 0; i < 6; i++)
    {
        m_List.SetColumnWidth(i, rect.Width() / 7); //�����еĿ�ȡ�
    }

    return TRUE; // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChartClientDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialog::OnPaint();
    }
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChartClientDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CChartClientDlg::OnBnClickedBtnsend()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
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
        MessageBox("��������ȷ����", "��������");
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
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WinExec(__argv[0], SW_SHOW);
    exit(0);
}

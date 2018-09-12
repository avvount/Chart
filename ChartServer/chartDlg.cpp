
// chartDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "chart.h"
#include "chartDlg.h"
#include "SettingDialog.h"

#define MAXQUANTITY 100
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

ThreadInfo Info;

// CchartDlg �Ի���

CchartDlg::CchartDlg(CWnd *pParent /*=NULL*/)
    : CDialog(CchartDlg::IDD, pParent), m_Quantity(0), m_Groups(0), m_pData(NULL)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_clrD = RGB(0, 0, 0);
    m_clrL[0] = RGB(0, 0, 255);
    m_clrL[1] = RGB(0, 255, 0);
    m_clrL[2] = RGB(255, 0, 0);
    m_clrL[3] = RGB(255, 0, 255);
    m_clrL[4] = RGB(0, 255, 255);
    m_clrEvenLine = RGB(255, 255, 0);
    m_clrOddLine = RGB(0, 255, 255);
    m_clrSelected = RGB(0, 100, 100);
    m_clrStatusBar = RGB(0, 0, 255);
}

void CchartDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);

    DDX_Control(pDX, IDC_LISTCTRL, m_List);
}

BEGIN_MESSAGE_MAP(CchartDlg, CDialog)
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
//}}AFX_MSG_MAP
ON_BN_CLICKED(ID_GENERATE, &CchartDlg::OnBnClickedGenerate)
ON_WM_LBUTTONDOWN()
ON_WM_SIZE()
ON_COMMAND(IDM_SETTING, &CchartDlg::OnSetting)

ON_WM_GETMINMAXINFO()

ON_NOTIFY(NM_CLICK, IDC_LISTCTRL, &CchartDlg::OnNMClickListctrl)
ON_WM_TIMER()
ON_MESSAGE(UM_SOCK, OnSock)
END_MESSAGE_MAP()

// CchartDlg ��Ϣ�������

BOOL CchartDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);  // ���ô�ͼ��
    SetIcon(m_hIcon, FALSE); // ����Сͼ��
    // TODO: �ڴ���Ӷ���ĳ�ʼ������

    //��ʼ���׽���
    InitSocket();

    //�˵�
    CMenu menu;
    menu.LoadMenu(IDR_MAINMENU);
    SetMenu(&menu);
    menu.Detach();
    //����ѡ���
    CString strTemp;
    ((CComboBox *)GetDlgItem(IDC_COMBO_QUANTITY))->ResetContent(); //����������������
    for (int i = 1; i <= MAXQUANTITY; i++)
    {
        strTemp.Format("%d", i);
        ((CComboBox *)GetDlgItem(IDC_COMBO_QUANTITY))->AddString(strTemp);
    }
    //CListCtrl��ͷ
    m_List.ModifyStyle(0, LVS_REPORT); // ����ģʽ
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES);
    m_List.InsertColumn(0, "���");
    m_List.InsertColumn(1, "��һ��");
    m_List.InsertColumn(2, "�ڶ���");
    m_List.InsertColumn(3, "������");
    m_List.InsertColumn(4, "������");
    m_List.InsertColumn(5, "������");

    //����״̬��
    UINT indicators[] = {ID_SEPARATOR};
    if (!m_wndStatusBar.Create(this))
    {
        TRACE0("δ�ܴ���״̬��\n");
        return -1; // δ�ܴ���
    }
    m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
    CRect rect;
    m_wndStatusBar.GetItemRect(0, &rect);
    staticStatus.Create("", WS_CHILD | WS_VISIBLE, rect, &m_wndStatusBar);
    Info.m_dlgChart = this;

    return TRUE; // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CchartDlg::OnPaint()
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
    ResizeList();
    PreDrawLine();
    DrawLine();

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CchartDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CchartDlg::OnBnClickedGenerate()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

    GenerateList();
    if (!m_List.GetItemCount())
    {
        return;
    }
    SendMessage(WM_PAINT);

    GetDlgItem(ID_GENERATE)->EnableWindow(0);
    SetTimer(1, 200 * m_Quantity, NULL);
    PreDrawLine();
    for (int i = 0; i < 5; i++)
    {
        Info.m_clrL[i] = m_clrL[i];
    }

    for (int i = 0; i < m_Groups; i++)
    {
        HANDLE hThread;
        hThread = CreateThread(NULL, 0, DrawLineThread, (LPVOID)i, 0, 0);
        CloseHandle(hThread);
    }
}

void CchartDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CDialog::OnLButtonDown(nFlags, point);
}

void CchartDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialog::OnSize(nType, cx, cy);

    // TODO: �ڴ˴������Ϣ����������

    if (m_wndStatusBar.GetSafeHwnd())
    {
        CRect rect;
        GetClientRect(&rect);
        rect.top = rect.bottom - 20;
        m_wndStatusBar.MoveWindow(rect);
    }
}

void CchartDlg::OnSetting()
{
    // TODO: �ڴ���������������
    CSettingDialog dlg;
    dlg.m_clrCoordinate = m_clrD;

    dlg.m_clrLine1 = m_clrL[0];
    dlg.m_clrLine2 = m_clrL[1];
    dlg.m_clrLine3 = m_clrL[2];
    dlg.m_clrLine4 = m_clrL[3];
    dlg.m_clrLine5 = m_clrL[4];
    dlg.m_clrOddLine = m_clrOddLine;
    dlg.m_clrEvenLine = m_clrEvenLine;
    dlg.m_clrSelected = m_clrSelected;
    dlg.m_clrStatusBar = m_clrStatusBar;
    if (IDOK == dlg.DoModal())
    {
        m_clrD = dlg.m_clrCoordinate;
        m_clrL[0] = dlg.m_clrLine1;
        m_clrL[1] = dlg.m_clrLine2;
        m_clrL[2] = dlg.m_clrLine3;
        m_clrL[3] = dlg.m_clrLine4;
        m_clrL[4] = dlg.m_clrLine5;
        m_clrOddLine = dlg.m_clrOddLine;
        m_clrEvenLine = dlg.m_clrEvenLine;
        m_clrSelected = dlg.m_clrSelected;
        m_clrStatusBar = dlg.m_clrStatusBar;
        PreDrawLine();
        DrawLine();
        setLineColor();
        m_wndStatusBar.SetTextColor(m_clrStatusBar);
        m_List.RedrawItems(0, m_List.GetItemCount() - 1);
    }
}

void CchartDlg::ResizeList(void)
{
    if (m_List)
    {
        CRect rect;
        GetClientRect(&rect);
        rect.top += 25;
        rect.bottom = (rect.bottom + rect.top) / 3;
        m_List.MoveWindow(&rect, true);
        m_List.SetColumnWidth(0, rect.Width() / 8);
        for (int i = 1; i < 6; i++)
        {
            m_List.SetColumnWidth(i, rect.Width() / 6); //�����еĿ�ȡ�
        }
    }
}

void CchartDlg::GenerateList(void)
{
    if (m_pData)
    {
        for (int i = 0; i < m_Quantity; i++)
        {
            delete[] m_pData[i];
        }
        delete[] m_pData;
        m_List.DeleteAllItems();
    }
    m_Quantity = GetDlgItemInt(IDC_COMBO_QUANTITY);
    m_Groups = GetDlgItemInt(IDC_COMBO_GROUPS);

    CString str;
    if (m_Quantity < 1)
    {
        str = "����Ӧ����0\n";
    }
    if (m_Groups < 1 || m_Groups > 5)
    {
        str += "����ӦΪ1~5";
    }
    if (str.GetLength())
    {
        MessageBox(str);
        return;
    }

    setLineColor();
    int t1 = GetTickCount();
    m_pData = new int *[m_Quantity];
    for (int i = 0; i < m_Quantity; i++)
    {
        str.Format("%d", i + 1);
        m_List.InsertItem(i, str);
        m_pData[i] = new int[m_Groups];
        for (int j = 0; j < m_Groups; j++)
        {
            m_pData[i][j] = rand() % 21 - 10;
            str.Format("%d", m_pData[i][j]);
            m_List.SetItemText(i, j + 1, str);
        }
        for (int j = m_Groups; j < 5; j++)
        {
            m_List.SetItemText(i, j + 1, "0");
        }
    }
    int t2 = GetTickCount();
    Info.m_quantity = m_Quantity;
    Info.m_pdata = m_pData;
    CString strStatusInfo;
    strStatusInfo.Format("������������: %d �� %d ,��ʱ %d ms", m_Quantity,
                         m_Groups, t2 - t1);

    staticStatus.SetWindowText(strStatusInfo);
    m_wndStatusBar.SetTextColor(m_clrStatusBar);
    //m_wndStatusBar.SetPaneText(0, strStatusInfo);
}

void CchartDlg::DrawLine(void)
{
    if (!m_List.GetItemCount())
    {
        return;
    }
    CClientDC dcPaint(this);
    for (int i = 0; i < m_Groups; i++)
    {
        CPen LinePen(PS_SOLID, 1, m_clrL[i]);
        dcPaint.SelectObject(&LinePen);
        dcPaint.MoveTo(Info.rect.left + 5, Info.rect.bottom -
                                               (m_pData[0][i] + 10) / 20.0 * Info.rect.Height());
        for (int j = 1; j < m_Quantity; j++)
        {
            dcPaint.LineTo(Info.rect.left + 5 + (float)j / (m_Quantity - 1) * (Info.rect.Width() - 5), Info.rect.bottom -
                                                                                                           (m_pData[j][i] + 10) / 20.0 * Info.rect.Height());
        }
    }
}

void CchartDlg::setLineColor(void)
{
    for (int i = 0; i < m_Quantity; i++)
    {
        if (i % 2)
        {
            m_List.SetItemColor(i, m_clrEvenLine); //ż����
        }
        else
        {
            m_List.SetItemColor(i, m_clrOddLine); //������
        }
    }
}

void CchartDlg::OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    //���ƴ�����С�ߴ�
    lpMMI->ptMinTrackSize.x = 600;
    lpMMI->ptMinTrackSize.y = 400;
    CDialog::OnGetMinMaxInfo(lpMMI);
}

void CchartDlg::OnNMClickListctrl(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    setLineColor();
    m_List.SetItemColor(pNMItemActivate->iItem, m_clrSelected);
    m_List.RedrawItems(0, m_List.GetItemCount() - 1);
    *pResult = 0;
}

DWORD WINAPI CchartDlg::DrawLineThread(LPVOID lpParameter)
{
    int index = (int)lpParameter;
    CPen LinePen(PS_SOLID, 1, Info.m_clrL[index]);
    CClientDC dcPaint(Info.m_dlgChart);
    dcPaint.SelectObject(&LinePen);
    dcPaint.MoveTo(Info.rect.left + 5, Info.rect.bottom -
                                           (Info.m_pdata[0][index] + 10) / 20.0 * Info.rect.Height());
    for (int j = 1; j < Info.m_quantity; j++)
    {
        Sleep(200);
        dcPaint.LineTo(Info.rect.left + 5 + (float)j / (Info.m_quantity - 1) * (Info.rect.Width() - 5), Info.rect.bottom -
                                                                                                            (Info.m_pdata[j][index] + 10) / 20.0 * Info.rect.Height());
    }

    return 0;
}

void CchartDlg::PreDrawLine(void)
{
    CRect rectListCtrl, rectWindow;
    GetDlgItem(IDC_LISTCTRL)->GetClientRect(&rectListCtrl);
    GetClientRect(&rectWindow);
    rectDrawing.top = rectListCtrl.bottom + 40;
    rectDrawing.bottom = rectWindow.bottom - 40;
    rectDrawing.left = rectWindow.left + 30;
    rectDrawing.right = rectWindow.right - 20;
    int y_middle = (rectDrawing.bottom + rectDrawing.top) / 2;
    CRect rectClear(rectDrawing.left - 30, rectDrawing.top - 20, rectDrawing.right + 20, rectDrawing.bottom + 20);
    CClientDC dcPaint(this);
    dcPaint.FillSolidRect(rectClear, RGB(255, 255, 255));
    CPen pen(PS_SOLID, 1, m_clrD);
    dcPaint.SelectObject(&pen);
    dcPaint.MoveTo(rectDrawing.left, rectDrawing.bottom);
    dcPaint.LineTo(rectDrawing.left, rectDrawing.top);
    dcPaint.LineTo(rectDrawing.left, y_middle);
    dcPaint.LineTo(rectDrawing.right, y_middle);
    CFont font;
    font.CreatePointFont(100, "Consolas");
    dcPaint.SelectObject(&font);
    dcPaint.TextOut(rectDrawing.left - 20, rectDrawing.top - 5, "10");
    dcPaint.TextOut(rectDrawing.left - 10, y_middle - 5, "0");
    dcPaint.TextOut(rectDrawing.left - 25, rectDrawing.bottom - 5, "-10");
    Info.rect = rectDrawing;
}

void CchartDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    GetDlgItem(ID_GENERATE)->EnableWindow(1);
    KillTimer(1);
    CDialog::OnTimer(nIDEvent);
}

bool CchartDlg::InitSocket(void)
{
    m_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, 0);
    if (INVALID_SOCKET == m_socket)
    {
        MessageBox("�����׽���ʧ�� ��");
        return false;
    }
    sockaddr_in addrSock;
    addrSock.sin_addr.S_un.S_addr = htonl(ADDR_ANY);
    addrSock.sin_family = AF_INET;
    addrSock.sin_port = htons(6001);
    if (SOCKET_ERROR == bind(m_socket, (sockaddr *)&addrSock, sizeof(sockaddr)))
    {
        MessageBox("�׽��ְ�ʧ�� ��");
        return FALSE;
    }
    listen(m_socket, 5);
    if (SOCKET_ERROR == WSAAsyncSelect(m_socket, m_hWnd, UM_SOCK, FD_ACCEPT | FD_READ))
    {
        MessageBox("ע�������ȡ�¼�ʧ�� ��");
        return FALSE;
    }
    return TRUE;
}

LRESULT CchartDlg::OnSock(WPARAM wParam, LPARAM lParam)
{
    static SOCKET sockConn;
    switch (LOBYTE(lParam))
    {
    case FD_ACCEPT:
        sockaddr_in addrClient;
        int len;
        len = sizeof(sockaddr);
        sockConn = accept(m_socket, (sockaddr *)&addrClient, &len);
        break;
    case FD_READ:
        {
            char recvBuf[100];
            recv(sockConn, recvBuf, 100, 0);
            TrafficMessage *ptfmg = (TrafficMessage *)recvBuf;
            bool sendBuf = false;
            if (strcmp(ptfmg->Username, "admin") == 0 
                && strcmp(ptfmg->Passwd, "123456") == 0)
            {
                if (ptfmg->AlreadyLogin)
                {
                    CString str;
                    str.Format("%d", ptfmg->quantity);
                    SetDlgItemText(IDC_COMBO_QUANTITY, str);
                    str.Format("%d", ptfmg->group);
                    SetDlgItemText(IDC_COMBO_GROUPS, str);
                    OnBnClickedGenerate();
                    for (int i = 0; i < m_Quantity; i++)
                    {
                        send(sockConn, (char *)m_pData[i], m_Groups * sizeof(int), 0);
                    }
                }
                else
                {
                    sendBuf = true;
                    send(sockConn, (char *)&sendBuf, 1, 0);
                }
            }
            else
            {
                send(sockConn, (char *)&sendBuf, 1, 0);
            }
            break;
        }
    default:
        break;
    }
    return true;
}

CchartDlg::~CchartDlg()
{
    if (m_socket)
    {
        closesocket(m_socket);
    }
}

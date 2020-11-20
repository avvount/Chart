
// AsynchronousChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AsynchronousChat.h"
#include "AsynchronousChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAsynchronousChatDlg 对话框

CAsynchronousChatDlg::CAsynchronousChatDlg(CWnd *pParent /*=NULL*/)
    : CDialog(CAsynchronousChatDlg::IDD, pParent), m_Radio(0)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAsynchronousChatDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Radio(pDX, IDC_RADIO1, m_Radio);
}

BEGIN_MESSAGE_MAP(CAsynchronousChatDlg, CDialog)
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
//}}AFX_MSG_MAP
ON_MESSAGE(UM_SOCK, &CAsynchronousChatDlg::OnSock)
ON_BN_CLICKED(IDC_BTNSEND, &CAsynchronousChatDlg::OnBnClickedBtnsend)
END_MESSAGE_MAP()

// CAsynchronousChatDlg 消息处理程序

BOOL CAsynchronousChatDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
    //  执行此操作
    SetIcon(m_hIcon, TRUE);  // 设置大图标
    SetIcon(m_hIcon, FALSE); // 设置小图标

    // TODO: 在此添加额外的初始化代码
    InitSocket();
    UpdateData(false);
    ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS))->SetAddress(127, 0, 0, 1);
    SetDlgItemText(IDC_EDIT_DOMAIN, _T("localhost"));
    return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAsynchronousChatDlg::OnPaint()
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
HCURSOR CAsynchronousChatDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

bool CAsynchronousChatDlg::InitSocket(void)
{
    m_socket = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, 0);
    if (INVALID_SOCKET == m_socket)
    {
        MessageBox(_T("套接字创建失败 ！"));
        return false;
    }

    SOCKADDR_IN addrsock;
    addrsock.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrsock.sin_family = AF_INET;
    addrsock.sin_port = htons(6000);

    if (SOCKET_ERROR == bind(m_socket, (SOCKADDR *)&addrsock, sizeof(SOCKADDR)))
    {
        MessageBox(_T("套接字绑定失败 !"));
        return false;
    }
    if (SOCKET_ERROR == WSAAsyncSelect(m_socket, m_hWnd, UM_SOCK, FD_READ))
    {
        MessageBox(_T("注册网络读取事件失败 ！"));
        return false;
    }

    return true;
}

LRESULT CAsynchronousChatDlg::OnSock(WPARAM wParam, LPARAM lParam)
{
    switch (LOWORD(lParam))
    {
    case FD_READ:
        WSABUF wsabuf;
        wsabuf.buf = new char[200];
        wsabuf.len = 200;

        DWORD dwRead;
        DWORD dwFlag = 0;

        sockaddr_in addrFrom;
        int len = sizeof(SOCKADDR);

        if (SOCKET_ERROR == WSARecvFrom(m_socket, &wsabuf, 1, &dwRead, &dwFlag,
                                        (SOCKADDR *)&addrFrom, &len, NULL, NULL))
        {
            MessageBox(_T("数据接收失败 ！"));
            delete[] wsabuf.buf;
            return false;
        }
        CString str, strTemp;
        if (m_Radio)
        {
            hostent *pHost;
            pHost = gethostbyaddr((char *)&addrFrom.sin_addr.S_un.S_addr, 4, AF_INET);
            strTemp = pHost->h_name;
        }
        else
        {
            strTemp = inet_ntoa(addrFrom.sin_addr);
        }
        str.Format(_T("%s 说 %s \n"), strTemp, wsabuf.buf);
        /* GetDlgItemText(IDC_EDIT_RECV,strTemp);
        str+=strTemp;
        SetDlgItemText(IDC_EDIT_RECV,str);*/
        CFile file(_T("D://聊天记录.txt"), CFile::modeWrite | CFile::modeCreate |
                                               CFile::modeNoTruncate);
        file.SeekToEnd();
        file.Write(str, str.GetLength() * 2);
        file.Close();
        delete[] wsabuf.buf;
        break;
    }
    return true;
}
void CAsynchronousChatDlg::OnBnClickedBtnsend()
{
    // TODO: 在此添加控件通知处理程序代码

    UpdateData();
    DWORD dwIP;
    hostent *pHost;
    CString strHost;
    SOCKADDR_IN addrSend;

    addrSend.sin_port = htons(6000);
    addrSend.sin_family = AF_INET;
    if (m_Radio)
    {
        GetDlgItemText(IDC_EDIT_DOMAIN, strHost);
        CStringA strHostA;
        strHostA = strHost;
        pHost = gethostbyname(strHostA.GetBuffer());
        addrSend.sin_addr.S_un.S_addr = *((DWORD *)pHost->h_addr_list[0]);
    }
    else
    {
        ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS))->GetAddress(dwIP);
        addrSend.sin_addr.S_un.S_addr = htonl(dwIP);
    }

    CString strSend;
    WSABUF wsabuf;
    DWORD dwSend;
    GetDlgItemText(IDC_EDIT_SEND, strSend);
    wsabuf.len = strSend.GetLength() * 2 + 2;
    wsabuf.buf = (char *)strSend.GetBuffer();

    SetDlgItemText(IDC_EDIT_SEND, _T(""));
    if (SOCKET_ERROR == WSASendTo(m_socket, &wsabuf, 1, &dwSend, 0,
                                  (sockaddr *)&addrSend, sizeof(sockaddr), NULL, NULL))
    {
        MessageBox(_T("数据发送失败 ！"));
    }
}

CAsynchronousChatDlg::~CAsynchronousChatDlg()
{
    closesocket(m_socket);
}
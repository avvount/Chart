
// AsynchronousChatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AsynchronousChat.h"
#include "AsynchronousChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAsynchronousChatDlg �Ի���

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

// CAsynchronousChatDlg ��Ϣ�������

BOOL CAsynchronousChatDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);  // ���ô�ͼ��
    SetIcon(m_hIcon, FALSE); // ����Сͼ��

    // TODO: �ڴ���Ӷ���ĳ�ʼ������
    InitSocket();
    UpdateData(false);
    ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS))->SetAddress(127, 0, 0, 1);
    SetDlgItemText(IDC_EDIT_DOMAIN, _T("localhost"));
    return TRUE; // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAsynchronousChatDlg::OnPaint()
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
HCURSOR CAsynchronousChatDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

bool CAsynchronousChatDlg::InitSocket(void)
{
    m_socket = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, 0);
    if (INVALID_SOCKET == m_socket)
    {
        MessageBox(_T("�׽��ִ���ʧ�� ��"));
        return false;
    }

    SOCKADDR_IN addrsock;
    addrsock.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrsock.sin_family = AF_INET;
    addrsock.sin_port = htons(6000);

    if (SOCKET_ERROR == bind(m_socket, (SOCKADDR *)&addrsock, sizeof(SOCKADDR)))
    {
        MessageBox(_T("�׽��ְ�ʧ�� !"));
        return false;
    }
    if (SOCKET_ERROR == WSAAsyncSelect(m_socket, m_hWnd, UM_SOCK, FD_READ))
    {
        MessageBox(_T("ע�������ȡ�¼�ʧ�� ��"));
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
            MessageBox(_T("���ݽ���ʧ�� ��"));
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
        str.Format(_T("%s ˵ %s \n"), strTemp, wsabuf.buf);
        /* GetDlgItemText(IDC_EDIT_RECV,strTemp);
        str+=strTemp;
        SetDlgItemText(IDC_EDIT_RECV,str);*/
        CFile file(_T("D://�����¼.txt"), CFile::modeWrite | CFile::modeCreate |
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
    // TODO: �ڴ���ӿؼ�֪ͨ����������

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
        MessageBox(_T("���ݷ���ʧ�� ��"));
    }
}

CAsynchronousChatDlg::~CAsynchronousChatDlg()
{
    closesocket(m_socket);
}
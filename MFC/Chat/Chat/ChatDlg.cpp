
// ChatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatDlg �Ի���




CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_MESSAGE(WM_RECVDATA,OnRecvData)
    ON_BN_CLICKED(IDC_BTN_SEND, &CChatDlg::OnBnClickedBtnSend)
    ON_BN_CLICKED(IDC_CMD, &CChatDlg::OnBnClickedCmd)
END_MESSAGE_MAP()


// CChatDlg ��Ϣ�������

BOOL CChatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    InitSocket();
    RECVPARAM *pRecvParam=new RECVPARAM;
    pRecvParam->hwnd=m_hWnd;
    pRecvParam->sock=m_socket;
    HANDLE hThread=CreateThread(NULL,0,RecvProc,(LPVOID)pRecvParam,0,NULL);
    CloseHandle(hThread);
    ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->SetAddress(127,0,0,1);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChatDlg::OnPaint()
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
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool CChatDlg::InitSocket(void)
{
    m_socket=socket(AF_INET,SOCK_DGRAM,0);
    if (INVALID_SOCKET==m_socket)
    {
        MessageBox(_T("�����׽���ʧ�� ��"));
        return FALSE;
    }

    SOCKADDR_IN addrSock;
    addrSock.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrSock.sin_family=AF_INET;
    addrSock.sin_port=htons(6000);

    int retval=bind(m_socket,(SOCKADDR *)&addrSock,sizeof(SOCKADDR));
    if (SOCKET_ERROR==retval)
    {
        MessageBox(_T("�׽��ְ�ʧ�� !"));
        closesocket(m_socket);
        return FALSE;
    }
    return TRUE;
}

DWORD WINAPI CChatDlg::RecvProc(LPVOID lpParameter)
{
    SOCKET sock=((RECVPARAM *)lpParameter)->sock;
    HWND hwnd=((RECVPARAM *)lpParameter)->hwnd;
    delete lpParameter;

    SOCKADDR_IN addrFrom;
    int len=sizeof(SOCKADDR);
    int retval;
    TCHAR recvBuf[200],tempBuf[300];
    while (TRUE)
    {
        retval=recvfrom(sock,(char *)recvBuf,200,0,(SOCKADDR *)&addrFrom,&len);
        if (SOCKET_ERROR==retval)
        {
            break;
        }

        USES_CONVERSION;
        wsprintf(tempBuf,_T("%s ˵��%s"),A2W(inet_ntoa(addrFrom.sin_addr)),recvBuf);
        ::PostMessage(hwnd,WM_RECVDATA,0,(LPARAM)tempBuf);
    }
    return 0;
}

LRESULT CChatDlg::OnRecvData(WPARAM wParam,LPARAM lParam)
{
    CString newStr=(TCHAR *)lParam;
    CString strTemp;
    GetDlgItemText(IDC_EDIT_RECV,strTemp);
    strTemp+="\r\n";
    strTemp+=newStr;
    SetDlgItemText(IDC_EDIT_RECV,strTemp);
    SendDlgItemMessage(IDC_EDIT_RECV,WM_VSCROLL,SB_BOTTOM,0);
    GetDlgItem(IDC_EDIT_RECV)->ShowScrollBar(SB_VERT);
    return 0;
}
void CChatDlg::OnBnClickedBtnSend()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    DWORD dwIP;
    ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);

    SOCKADDR_IN addrTo;
    addrTo.sin_addr.S_un.S_addr=htonl(dwIP);
    addrTo.sin_family=AF_INET;
    addrTo.sin_port=htons(6000);

    CString strSend;
    GetDlgItemText(IDC_EDIT_SEND,strSend);
    sendto(m_socket,(char *)strSend.GetBuffer(),strSend.GetLength()*2+2,0,(SOCKADDR *)&addrTo,sizeof(SOCKADDR));
    SetDlgItemText(IDC_EDIT_SEND,_T(""));
}

void CChatDlg::OnBnClickedCmd()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    STARTUPINFO sui;
    PROCESS_INFORMATION pi;
    ZeroMemory(&sui,sizeof(STARTUPINFO));
    sui.wShowWindow=WS_VISIBLE;
    WinExec("cmd",SW_SHOW);
    //CreateProcess(_T("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"),NULL,NULL,NULL,true,0,NULL,NULL,&sui,&pi);
}

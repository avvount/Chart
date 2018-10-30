
// ChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatDlg 对话框




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


// CChatDlg 消息处理程序

BOOL CChatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    InitSocket();
    RECVPARAM *pRecvParam=new RECVPARAM;
    pRecvParam->hwnd=m_hWnd;
    pRecvParam->sock=m_socket;
    HANDLE hThread=CreateThread(NULL,0,RecvProc,(LPVOID)pRecvParam,0,NULL);
    CloseHandle(hThread);
    ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->SetAddress(127,0,0,1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChatDlg::OnPaint()
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
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool CChatDlg::InitSocket(void)
{
    m_socket=socket(AF_INET,SOCK_DGRAM,0);
    if (INVALID_SOCKET==m_socket)
    {
        MessageBox(_T("创建套接字失败 ！"));
        return FALSE;
    }

    SOCKADDR_IN addrSock;
    addrSock.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrSock.sin_family=AF_INET;
    addrSock.sin_port=htons(6000);

    int retval=bind(m_socket,(SOCKADDR *)&addrSock,sizeof(SOCKADDR));
    if (SOCKET_ERROR==retval)
    {
        MessageBox(_T("套接字绑定失败 !"));
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
        wsprintf(tempBuf,_T("%s 说：%s"),A2W(inet_ntoa(addrFrom.sin_addr)),recvBuf);
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
    // TODO: 在此添加控件通知处理程序代码
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
    // TODO: 在此添加控件通知处理程序代码
    STARTUPINFO sui;
    PROCESS_INFORMATION pi;
    ZeroMemory(&sui,sizeof(STARTUPINFO));
    sui.wShowWindow=WS_VISIBLE;
    WinExec("cmd",SW_SHOW);
    //CreateProcess(_T("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"),NULL,NULL,NULL,true,0,NULL,NULL,&sui,&pi);
}

// LOGINDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "ChartClient.h"
#include "LoginDlg.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
    ON_BN_CLICKED(IDC_BTNLOGIN, &CLoginDlg::OnBnClickedBtnlogin)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

void CLoginDlg::OnBnClickedBtnlogin()
{
    // TODO: 在此添加控件通知处理程序代码
    extern TrafficMessage tfmg;
    extern SOCKET sockClient;
    extern sockaddr_in addrSrv;
    DWORD dwIP;
    ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);
    
    CString strTemp;
    GetDlgItemText(IDC_EDIT_USERNAME,strTemp);
    strcpy(tfmg.Username,strTemp.GetBuffer());
    GetDlgItemText(IDC_EDIT_PASSWD,strTemp);
    strcpy(tfmg.Passwd,strTemp.GetBuffer());


    sockClient=socket(AF_INET,SOCK_STREAM,0);
    addrSrv.sin_addr.S_un.S_addr=htonl(dwIP);
    addrSrv.sin_port=htons(6001);
    addrSrv.sin_family=AF_INET;
    connect(sockClient,(sockaddr *)&addrSrv,sizeof(sockaddr));
    send(sockClient,(char *)&tfmg,sizeof(tfmg),0);
    bool recvBuf=false;
    recv(sockClient,(char *)&recvBuf,1,0);
    
    if (recvBuf)
    {
        tfmg.AlreadyLogin=true;
        EndDialog(IDC_BTNLOGIN);
    }
    else
    {
        MessageBox("用户名或密码错误 ");
    }
}

BOOL CLoginDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  在此添加额外的初始化
    ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->SetAddress(127,0,0,1);
    return TRUE;  // return TRUE unless you set the focus to a control
    // 异常: OCX 属性页应返回 FALSE
}

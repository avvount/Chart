// LOGINDLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChartClient.h"
#include "LoginDlg.h"


// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������

void CLoginDlg::OnBnClickedBtnlogin()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
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
        MessageBox("�û������������ ");
    }
}

BOOL CLoginDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    ((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->SetAddress(127,0,0,1);
    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

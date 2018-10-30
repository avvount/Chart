
// ChartClient.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "ChartClient.h"
#include "ChartClientDlg.h"
#include "LoginDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChartClientApp

BEGIN_MESSAGE_MAP(CChartClientApp, CWinAppEx)
ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// CChartClientApp ����

CChartClientApp::CChartClientApp()
{
    // TODO: �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

CChartClientApp::~CChartClientApp()
{
    WSACleanup();
}
// Ψһ��һ�� CChartClientApp ����

CChartClientApp theApp;

// CChartClientApp ��ʼ��

BOOL CChartClientApp::InitInstance()
{
    CWinAppEx::InitInstance();

    // ��׼��ʼ��
    // ���δʹ����Щ���ܲ�ϣ����С
    // ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
    // ����Ҫ���ض���ʼ������
    // �������ڴ洢���õ�ע�����
    // TODO: Ӧ�ʵ��޸ĸ��ַ�����
    // �����޸�Ϊ��˾����֯��
    SetRegistryKey(_T("ͼ����ϰClient"));

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err)
    {
        return FALSE;
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
        WSACleanup();
        return FALSE;
    }

    CLoginDlg loginDlg;
    if (IDC_BTNLOGIN == loginDlg.DoModal())
    {
        CChartClientDlg dlg;
        m_pMainWnd = &dlg;
        INT_PTR nResponse = dlg.DoModal();
    }

    // ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
    //  ����������Ӧ�ó������Ϣ�á�
    return FALSE;
}

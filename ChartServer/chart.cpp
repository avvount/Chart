
// chart.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "chart.h"
#include "chartDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CchartApp

BEGIN_MESSAGE_MAP(CchartApp, CWinAppEx)
ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// CchartApp ����

CchartApp::CchartApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CchartApp ����

CchartApp theApp;

// CchartApp ��ʼ��

BOOL CchartApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("ͼ����ϰServer"));


    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested=MAKEWORD(2,2);
    err=WSAStartup(wVersionRequested,&wsaData);
    if (err)
    {
        return FALSE;
    }

    if (LOBYTE(wsaData.wVersion)!=2||HIBYTE(wsaData.wVersion)!=2)
    {
        WSACleanup();
        return FALSE;
    }
	CchartDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

CchartApp::~CchartApp()
{
    WSACleanup();
}
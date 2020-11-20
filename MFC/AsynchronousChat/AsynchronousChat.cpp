
// AsynchronousChat.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "AsynchronousChat.h"
#include "AsynchronousChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAsynchronousChatApp

BEGIN_MESSAGE_MAP(CAsynchronousChatApp, CWinAppEx)
ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// CAsynchronousChatApp ����

CAsynchronousChatApp::CAsynchronousChatApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CAsynchronousChatApp ����

CAsynchronousChatApp theApp;

// CAsynchronousChatApp ��ʼ��

BOOL CAsynchronousChatApp::InitInstance()
{
	CWinAppEx::InitInstance();

	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err)
	{
		return false;
	}

	if (2 != LOBYTE(wsaData.wVersion) || 2 != HIBYTE(wsaData.wVersion))
	{
		WSACleanup();
		return false;
	}

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CAsynchronousChatDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

CAsynchronousChatApp::~CAsynchronousChatApp(void)
{
	WSACleanup();
}

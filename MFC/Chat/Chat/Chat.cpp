
// Chat.cpp : ����Ӧ�ó��������Ϊ��
//


#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"
#include <afxsock.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatApp

BEGIN_MESSAGE_MAP(CChatApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CChatApp ����

CChatApp::CChatApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CChatApp ����

CChatApp theApp;


// CChatApp ��ʼ��

BOOL CChatApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Chat"));


    if (!AfxSocketInit())
    {
        AfxMessageBox(_T("�����׽��ֿ�ʧ�� ��"));
        return FALSE;
    }

	CChatDlg dlg;
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

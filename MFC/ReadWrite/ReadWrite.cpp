
// ReadWrite.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "ReadWrite.h"
#include "MainFrm.h"

#include "ReadWriteDoc.h"
#include "ReadWriteView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CReadWriteApp

BEGIN_MESSAGE_MAP(CReadWriteApp, CWinAppEx)
ON_COMMAND(ID_APP_ABOUT, &CReadWriteApp::OnAppAbout)
// �����ļ��ı�׼�ĵ�����
ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
//ON_COMMAND(ID_CUSTOM_APIWRITE, &CReadWriteApp::OnCustomApiwrite)
END_MESSAGE_MAP()

// CReadWriteApp ����

CReadWriteApp::CReadWriteApp()
{

	m_bHiColorIcons = TRUE;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CReadWriteApp ����

CReadWriteApp theApp;

// CReadWriteApp ��ʼ��

BOOL CReadWriteApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	//WriteProfileString("default","admin","No");

	LoadStdProfileSettings(4); // ���ر�׼ INI �ļ�ѡ��(���� MRU)

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
												 RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate *pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CReadWriteDoc),
		RUNTIME_CLASS(CMainFrame), // �� SDI ��ܴ���
		RUNTIME_CLASS(CReadWriteView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����
	return TRUE;
}

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
  public:
	CAboutDlg();

	// �Ի�������
	enum
	{
		IDD = IDD_ABOUTBOX
	};

  protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV ֧��

	// ʵ��
  protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CReadWriteApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CReadWriteApp �Զ������/���淽��

void CReadWriteApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CReadWriteApp::LoadCustomState()
{
}

void CReadWriteApp::SaveCustomState()
{
}

// CReadWriteApp ��Ϣ�������

//void CReadWriteApp::OnCustomApiwrite()
//{
//    // TODO: �ڴ���������������
//    AfxMessageBox("Ӧ�ó�����");
//
//}

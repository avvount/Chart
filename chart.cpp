
// chart.cpp : 定义应用程序的类行为。
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

// CchartApp 构造

CchartApp::CchartApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CchartApp 对象

CchartApp theApp;

// CchartApp 初始化

BOOL CchartApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("图表练习Server"));


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
	

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

CchartApp::~CchartApp()
{
    WSACleanup();
}
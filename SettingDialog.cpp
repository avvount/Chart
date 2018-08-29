// SettingDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "chart.h"
#include "SettingDialog.h"


// CSettingDialog 对话框

IMPLEMENT_DYNAMIC(CSettingDialog, CDialog)

CSettingDialog::CSettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDialog::IDD, pParent)
{

}

CSettingDialog::~CSettingDialog()
{
}

void CSettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingDialog, CDialog)
END_MESSAGE_MAP()


// CSettingDialog 消息处理程序

// SettingDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "chart.h"
#include "SettingDialog.h"


// CSettingDialog �Ի���

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


// CSettingDialog ��Ϣ�������

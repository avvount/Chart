#include <windows.h>
#include <strsafe.h>
#include "SysInfo.h"
#include <Winerror.h>
#include "SystemInfoDetector.h"

INT CALLBACK DialogProc(HWND hwndDlg,  // handle to dialog box
	UINT uMsg,     // message
	WPARAM wParam, // first message parameter
	LPARAM lParam  // second message parameter
	);


int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DialogProc);
	return 0;
}

CSysInfo g_sysInfo;

enum
{
	DOT_NET_FRAMEWORK_4,
	XP_SERVICE_PACK_3,
	ZL_MAIN_PROGRAM
};

INT CALLBACK DialogProc(HWND hwndDlg,  // handle to dialog box
	UINT uMsg,     // message
	WPARAM wParam, // first message parameter
	LPARAM lParam  // second message parameter
	)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		{
			SystemInfoDef* pSI = g_sysInfo.GetAll();
			SetDlgItemTextW(hwndDlg, IDC_EDIT_OPERATING_SYSTEM, pSI->szOperatingSystem);
			SetDlgItemTextW(hwndDlg, IDC_EDIT_DOT_NET_FRAMEWORK, pSI->szDotNetFramework);
			BOOL bEnableFx4 = !pSI->bNeedXpSp3 && pSI->bNeedDotNetFx4;
			RECT rectDlg;
			int iScrWidth = GetSystemMetrics(SM_CXFULLSCREEN);
			int iScrHeight = GetSystemMetrics(SM_CYFULLSCREEN);
			GetWindowRect(hwndDlg, &rectDlg);
			int iDlgHeight = rectDlg.bottom - rectDlg.top;
			int iDlgWidth = rectDlg.right - rectDlg.left;
			MoveWindow (hwndDlg, (iScrWidth-iDlgWidth)/2, (iScrHeight-iDlgHeight)/2, iDlgWidth, iDlgHeight, FALSE);
		}
		break;
	case WM_SYSCOMMAND:
		if ((WPARAM)wParam == SC_CLOSE) 
		{
			EndDialog(hwndDlg, LOWORD(wParam));
		}
		break;
	}
	return FALSE;
}

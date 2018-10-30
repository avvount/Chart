
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MFCMenu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
    ON_UPDATE_COMMAND_UI(ID_VIEW_STATUS_BAR, &CMainFrame::OnUpdateViewStatusBar)
    ON_COMMAND(ID_POPUP_EDIT, &CMainFrame::OnPopupEdit)
    ON_COMMAND(ID_TEMP,&CMainFrame::OnTemp)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
    m_bAutoMenuEnable=FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)
        /sizeof(UINT));

    GetMenu()->GetSubMenu(0)->CheckMenuItem(0,MF_CHECKED|MF_BYPOSITION);
    /*GetMenu()->GetSubMenu(0)->EnableMenuItem(1,MF_BYPOSITION|MF_GRAYED
        |MF_DISABLED);*/
    m_bitmap.LoadBitmap(IDB_BITMAP1);
 /*   int x=GetSystemMetrics(SM_CXMENUCHECK);
    int y=GetSystemMetrics(SM_CYMENUCHECK);
    CString str;
    str.Format("%d\t%d",x,y);
    MessageBox(str);*/
    
    GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(1,MF_BYPOSITION,
        &m_bitmap,&m_bitmap);

    CMenu menu;
    //menu.LoadMenu(IDR_MENU1);
    menu.CreateMenu();
    GetMenu()->InsertMenu(1,MF_BYPOSITION|MF_POPUP,(UINT)menu.m_hMenu,"Test");
    
    menu.AppendMenu(MF_STRING,155,"1");
    menu.AppendMenu(MF_STRING,156,"2");
    menu.AppendMenu(MF_STRING,157,"3");
    //GetMenu()->AppendMenu(MF_POPUP,(UINT)menu.m_hMenu,"Test");
    
    menu.Detach();
    GetMenu()->DeleteMenu(2,MF_BYPOSITION);
    return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE | WS_SYSMENU;

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

void CMainFrame::OnUpdateViewStatusBar(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->Enable(false);

}



void CMainFrame::OnPopupEdit()
{
    // TODO: �ڴ���������������
    MessageBox("Main show");
}


void CMainFrame::OnTemp()
{
    MessageBox("Hello 1");
}
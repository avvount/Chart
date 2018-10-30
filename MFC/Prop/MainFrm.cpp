
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "Prop.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
    ON_WM_TIMER()
    ON_MESSAGE(UM_PROGRESS,OnProgress)
    ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
    ID_TIMER,
    ID_PROGRESS,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
    


    //��̬ͼ��
    extern CPropApp theApp;
    m_Icon[0]=LoadIcon(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ICON1));
    m_Icon[1]=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON2));
    m_Icon[2]=LoadIcon(theApp.m_hInstance,MAKEINTRESOURCE(IDI_ICON3));
    
    SetTimer(1,1000,0);

    //������
    if (!m_WndToolBar.Create(this,WS_CHILD|WS_VISIBLE|CBRS_TOP|CBRS_GRIPPER
        |CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_SIZE_DYNAMIC))
    {
        TRACE0("δ�ܴ���������\n");
        return -1;      // δ�ܴ���
    }
    m_WndToolBar.LoadToolBar(IDR_MAINFRAME);
    m_WndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_WndToolBar);

    //PostMessage(UM_PROGRESS);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
 

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

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    static int index;
    SetClassLong(m_hWnd,GCL_HICON,(long)m_Icon[index]);
    index=++index%3;

    CTime t=CTime::GetCurrentTime();
    CString str=t.Format("%H:%M:%S");
    CClientDC dc(this);
    m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(ID_TIMER),ID_TIMER,
        SBPS_NORMAL,dc.GetTextExtent(str).cx);
    m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_TIMER),str);

    m_progress.StepIt();
    CFrameWnd::OnTimer(nIDEvent);
}
LRESULT CMainFrame::OnProgress(WPARAM,LPARAM)
{
    
    CRect rect;
    m_wndStatusBar.GetItemRect(m_wndStatusBar.CommandToIndex(ID_PROGRESS),&rect);
    m_progress.Create(WS_CHILD |WS_VISIBLE,rect,&m_wndStatusBar,159);
    m_progress.SetPos(50);
    return true;
}
void CMainFrame::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: �ڴ˴������Ϣ����������
    // ��Ϊ��ͼ��Ϣ���� CFrameWnd::OnPaint()


    CRect rect;
    m_wndStatusBar.GetItemRect(m_wndStatusBar.CommandToIndex(ID_PROGRESS),&rect);
    if (m_progress.m_hWnd)
    {
        m_progress.MoveWindow(&rect);
    }
    else
    {
        m_progress.Create(WS_CHILD |WS_VISIBLE|PBS_SMOOTH  ,rect,&m_wndStatusBar,159);
        m_progress.SetStep(15);
    }
    
}

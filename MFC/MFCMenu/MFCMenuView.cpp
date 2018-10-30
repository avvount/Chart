
// MFCMenuView.cpp : CMFCMenuView 类的实现
//

#include "stdafx.h"
#include "MFCMenu.h"

#include "MFCMenuDoc.h"
#include "MFCMenuView.h"
#include "MyboleDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMenuView

IMPLEMENT_DYNCREATE(CMFCMenuView, CView)

BEGIN_MESSAGE_MAP(CMFCMenuView, CView)

ON_WM_RBUTTONDOWN()
ON_WM_CONTEXTMENU()
ON_WM_CHAR()
ON_COMMAND(IDM_DIALOG, &CMFCMenuView::OnDialog)
//ON_COMMAND(ID_32771, &CMFCMenuView::On32771)
END_MESSAGE_MAP()

// CMFCMenuView 构造/析构

CMFCMenuView::CMFCMenuView()
: m_nIndex(0)
, m_strName("")
, m_strNum("")
, m_bFlag(false)
{
	// TODO: 在此处添加构造代码

}

CMFCMenuView::~CMFCMenuView()
{
}

BOOL CMFCMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCMenuView 绘制

void CMFCMenuView::OnDraw(CDC* /*pDC*/)
{
	CMFCMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCMenuView 诊断

#ifdef _DEBUG
void CMFCMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMenuDoc* CMFCMenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMenuDoc)));
	return (CMFCMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMenuView 消息处理程序



void CMFCMenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值

 /*   ClientToScreen(&point);
    CMenu menu;
    menu.LoadMenu(IDR_MENU1);
    CMenu *pPopup=menu.GetSubMenu(0);
    pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y
        ,this->GetParent());
    CView::OnRButtonDown(nFlags, point);*/
}

void CMFCMenuView::OnContextMenu(CWnd* pWnd, CPoint point)
{
    // TODO: 在此处添加消息处理程序代码
    CMenu menu;
    menu.LoadMenu(IDR_MENU1);
    CMenu *pPopup=menu.GetSubMenu(0);
    pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,
        pWnd->GetParent());
}

//void CMFCMenuView::OnPopupEdit()
//{
//    // TODO: 在此添加命令处理程序代码
//    MessageBox("右键编辑");
//}
void CMFCMenuView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    CClientDC dc(this);
    if (0x0d==nChar)
    {
        Invalidate();
        if (0==m_nIndex)
        {
            m_menu.CreatePopupMenu();
            GetParent()->GetMenu()->AppendMenu(MF_POPUP,(UINT)m_menu.m_hMenu
                ,"PhoneBook");
        }
        m_nIndex++;
        m_menu.AppendMenu(MF_STRING,NUMPRE+m_nIndex,m_strName);
        m_strName.Empty();
        m_strNum.Empty();
        m_bFlag=false;
        GetParent()->DrawMenuBar();
    } 
    else if (' '==nChar)
    {
        m_bFlag=true; 
        
    }
    else
    {
        if (m_bFlag)
        {
            m_strNum += (unsigned char)nChar;
            CString strLine;
            strLine.Format("%s  %s",m_strName,m_strNum);
            dc.TextOut(0,0,strLine);
        }
        else
        {
            m_strName += (unsigned char)nChar;
            dc.TextOut(0,0,m_strName);
        }
        
    }


    CView::OnChar(nChar, nRepCnt, nFlags);
}

void CMFCMenuView::OnDialog()
{
    // TODO: 在此添加命令处理程序代码
    CMyboleDlg *dlg=new CMyboleDlg;
    dlg->Create(ID_Mybole,this);
    dlg->ShowWindow(SW_SHOW);
}



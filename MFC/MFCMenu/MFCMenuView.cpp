
// MFCMenuView.cpp : CMFCMenuView ���ʵ��
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

// CMFCMenuView ����/����

CMFCMenuView::CMFCMenuView()
: m_nIndex(0)
, m_strName("")
, m_strNum("")
, m_bFlag(false)
{
	// TODO: �ڴ˴���ӹ������

}

CMFCMenuView::~CMFCMenuView()
{
}

BOOL CMFCMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCMenuView ����

void CMFCMenuView::OnDraw(CDC* /*pDC*/)
{
	CMFCMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCMenuView ���

#ifdef _DEBUG
void CMFCMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMenuDoc* CMFCMenuView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMenuDoc)));
	return (CMFCMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMenuView ��Ϣ�������



void CMFCMenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
    // TODO: �ڴ˴������Ϣ����������
    CMenu menu;
    menu.LoadMenu(IDR_MENU1);
    CMenu *pPopup=menu.GetSubMenu(0);
    pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,
        pWnd->GetParent());
}

//void CMFCMenuView::OnPopupEdit()
//{
//    // TODO: �ڴ���������������
//    MessageBox("�Ҽ��༭");
//}
void CMFCMenuView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
    // TODO: �ڴ���������������
    CMyboleDlg *dlg=new CMyboleDlg;
    dlg->Create(ID_Mybole,this);
    dlg->ShowWindow(SW_SHOW);
}



#include "StdAfx.h"
#include "NewListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CNewListCtrl, CListCtrl)
ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnNMCustomdraw)
//ON_NOTIFY_REFLECT(NM_CLICK, &CNewListCtrl::OnNMClick)
//ON_NOTIFY_REFLECT(NM_CLICK, &CNewListCtrl::OnNMClick)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewListCtrl message handlers

void CNewListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: Add your control notification handler code here
    *pResult = CDRF_DODEFAULT;
    NMLVCUSTOMDRAW *lplvdr = (NMLVCUSTOMDRAW *)pNMHDR;
    switch (lplvdr->nmcd.dwDrawStage) //�ж�״̬
    {
    case CDDS_PREPAINT:
    {
        *pResult = CDRF_NOTIFYITEMDRAW;
        break;
    }
    case CDDS_ITEMPREPAINT: //���Ϊ��ITEM֮ǰ��Ҫ������ɫ�ĸı�
    {
        COLORREF ClrBk;
        
        if (MapItemColor.Lookup(lplvdr->nmcd.dwItemSpec, ClrBk))
        //// ������ SetItemColor(DWORD iItem, COLORREF color) ���õ�
        //// ITEM�ź�COLORREF �������в��ң�Ȼ�������ɫ��ֵ��
        {
            lplvdr->clrTextBk=ClrBk;
            *pResult = CDRF_DODEFAULT;
            
        }
        break;
    }
    }
}


void CNewListCtrl::SetItemColor(DWORD iItem, COLORREF TextBkColor)
{
    MapItemColor.SetAt(iItem, TextBkColor);
}


//void CNewListCtrl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
//{
//    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//    // TODO: �ڴ���ӿؼ�֪ͨ����������
//    
//    //SetItemColor(pNMItemActivate->iItem,RGB(0,0,0));
//    //RedrawItems(pNMItemActivate->iItem,pNMItemActivate->iItem);
//    *pResult = 0;
//}

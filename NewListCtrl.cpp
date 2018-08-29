#include "StdAfx.h"
#include "NewListCtrl.h"

#ifdef _DEBUG  
#define new DEBUG_NEW  
#undef THIS_FILE  
static char THIS_FILE[] = __FILE__;  
#endif  

/////////////////////////////////////////////////////////////////////////////  
// CNewListCtrl  

CNewListCtrl::CNewListCtrl()  
{  
}  

CNewListCtrl::~CNewListCtrl()  
{  
}  


BEGIN_MESSAGE_MAP(CNewListCtrl, CListCtrl)  
    //{{AFX_MSG_MAP(CNewListCtrl)  
    // NOTE - the ClassWizard will add and remove mapping macros here.  
    //}}AFX_MSG_MAP  
    ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnNMCustomdraw)  
END_MESSAGE_MAP()  

/////////////////////////////////////////////////////////////////////////////  
// CNewListCtrl message handlers  


void CNewListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)    
{    
    // TODO: Add your control notification handler code here     
    *pResult = CDRF_DODEFAULT;    
    NMLVCUSTOMDRAW * lplvdr=(NMLVCUSTOMDRAW*)pNMHDR;    
    NMCUSTOMDRAW &nmcd = lplvdr->nmcd;    
    switch(lplvdr->nmcd.dwDrawStage)//�ж�״̬     
    {    
    case CDDS_PREPAINT:    
        {    
            *pResult = CDRF_NOTIFYITEMDRAW;    
            break;    
        }    
    case CDDS_ITEMPREPAINT://���Ϊ��ITEM֮ǰ��Ҫ������ɫ�ĸı�     
        {    
            TEXT_BK tb;  

            if(MapItemColor.Lookup(nmcd.dwItemSpec, tb))    
                // ������ SetItemColor(DWORD iItem, COLORREF color) ���õ�     
                // ITEM�ź�COLORREF �������в��ң�Ȼ�������ɫ��ֵ��     
            {    
                lplvdr->clrText = tb.colText;     
                lplvdr->clrTextBk = tb.colTextBk;    
                *pResult = CDRF_DODEFAULT;    
            }    
        }    
        break;    
    }    
}    

void CNewListCtrl::ClearColor()  
{  
    MapItemColor.RemoveAll();  
}  

void CNewListCtrl::SetItemColor(DWORD iItem, COLORREF TextColor, COLORREF TextBkColor)  
{    
    TEXT_BK tb;  
    tb.colText = TextColor;  
    tb.colTextBk = TextBkColor;  


    MapItemColor.SetAt(iItem, tb);//����ĳ�е���ɫ��     
    this->RedrawItems(iItem, iItem);//����Ⱦɫ     

    //this->SetCheck(iItem,1);     
    this->SetFocus();    //���ý���     
    UpdateWindow();    
}    


void CNewListCtrl::SetAllItemColor(DWORD iItem, COLORREF TextColor, COLORREF TextBkColor)    
{    
    //INT_PTR ncount = this->GetItemCount();  
    TEXT_BK tb;  
    tb.colText = TextColor;  
    tb.colTextBk = TextBkColor;  

    if(iItem > 0)    
    {    
        for(DWORD numItem = 0; numItem < iItem ;numItem ++)    
        {    
            //iItem = i;     
            MapItemColor.SetAt(numItem, tb);    
            this->RedrawItems(numItem, numItem);    
        }    
    }    

    return;    

}   
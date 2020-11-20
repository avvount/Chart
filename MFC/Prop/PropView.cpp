
// PropView.cpp : CPropView ���ʵ��
//

#include "stdafx.h"
#include "Prop.h"

#include "PropDoc.h"
#include "PropView.h"
#include "PropSheet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPropView

IMPLEMENT_DYNCREATE(CPropView, CView)

BEGIN_MESSAGE_MAP(CPropView, CView)
    ON_COMMAND(ID_PROPERTY, &CPropView::OnProperty)
    ON_COMMAND(IDM_DOT, &CPropView::OnDot)
    ON_COMMAND(IDM_LINE, &CPropView::OnLine)
    ON_COMMAND(IDM_RECTANGLE, &CPropView::OnRectangle)
    ON_COMMAND(IDM_ELLIPSE, &CPropView::OnEllipse)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPropView ����/����

CPropView::CPropView()
: m_iOccupation(-1)
, m_strWorkAddr(_T(""))
, m_strSalary(_T(""))
, m_nDrawType(0)
, m_ptOrigin(0)
{
	// TODO: �ڴ˴���ӹ������
    memset(m_bLike,0,sizeof(m_bLike));

}

CPropView::~CPropView()
{
}

BOOL CPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPropView ����

void CPropView::OnDraw(CDC* pDC)
{
	CPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

    CFont font;
    font.CreatePointFont(300,"�����п�");
    pDC->SelectObject(&font);
    CString strOut;
    strOut="���ְҵ�ǣ�";
    switch (m_iOccupation)
    {
    case 0:
        strOut+="����Ա";
    	break;
    case 1:
        strOut+="ϵͳ����ʦ";
        break;
    case 2:
        strOut+="��Ŀ����";
        break;
    default:
        break;
    }
    pDC->TextOut(0,0,strOut);
    strOut="��Ĺ����ص㣺";
    strOut+=m_strWorkAddr;
    TEXTMETRIC tm;
    pDC->GetTextMetrics(&tm);
    pDC->TextOut(0,tm.tmHeight,strOut);
    strOut="�����Ȥ���ã�";
    if (m_bLike[0])
    {
        strOut+="���� ";
    }
    if (m_bLike[1])
    {
        strOut+="���� ";
    }
    if (m_bLike[2])
    {
        strOut+="���� ";
    }
    if (m_bLike[3])
    {
        strOut+="��Ӿ ";
    }
    pDC->TextOut(0,tm.tmHeight*2,strOut);
    strOut="���н��ˮƽ�� ";
    strOut+=m_strSalary;

    pDC->TextOut(0,tm.tmHeight*3,strOut);

}


// CPropView ���

#ifdef _DEBUG
void CPropView::AssertValid() const
{
	CView::AssertValid();
}

void CPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropDoc* CPropView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropDoc)));
	return (CPropDoc*)m_pDocument;
}
#endif //_DEBUG


// CPropView ��Ϣ�������

void CPropView::OnProperty()
{
    // TODO: �ڴ���������������
    CPropSheet propSheet("���Ա�");
    propSheet.SetWizardMode();
    if (ID_WIZFINISH==propSheet.DoModal())
    {
        m_iOccupation=propSheet.m_prop1.m_occupation;
        m_strWorkAddr=propSheet.m_prop1.m_strworkAddr;
        m_bLike[0]=propSheet.m_prop2.m_bFootball;
        m_bLike[1]=propSheet.m_prop2.m_bBasketball;
        m_bLike[2]=propSheet.m_prop2.m_bVolleyball;
        m_bLike[3]=propSheet.m_prop2.m_bSwim;
        m_strSalary=propSheet.m_prop3.m_strSalary;
        Invalidate();
    }
}

void CPropView::OnDot()
{
    // TODO: �ڴ���������������
    m_nDrawType=1;

}

void CPropView::OnLine()
{
    // TODO: �ڴ���������������
    m_nDrawType=2;
}

void CPropView::OnRectangle()
{
    // TODO: �ڴ���������������
    m_nDrawType=3;
}

void CPropView::OnEllipse()
{
    // TODO: �ڴ���������������
    m_nDrawType=4;
}

void func(int x)
{
	TRACE("%d\t",x);
}
void CPropView::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    m_ptOrigin=point;
	std::vector<int> v;
	for (int i = 0;i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(),v.end(),[](int x){TRACE("%d\t",x);});
    CView::OnLButtonDown(nFlags, point);
}

void CPropView::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CClientDC dc(this);
    
    switch (m_nDrawType)
    {
    case 1:
        dc.SetPixel(point,RGB(0,0,0));
    	break;
    case 2:
        dc.MoveTo(m_ptOrigin);
        dc.LineTo(point);
        break;
    case 3:
        dc.Rectangle(CRect(m_ptOrigin,point));
        break;
    case 4:
        dc.Ellipse(CRect(m_ptOrigin,point));
        break;
    default:
        break;
    }
    CView::OnLButtonUp(nFlags, point);
}

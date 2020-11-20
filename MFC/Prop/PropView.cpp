
// PropView.cpp : CPropView 类的实现
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

// CPropView 构造/析构

CPropView::CPropView()
: m_iOccupation(-1)
, m_strWorkAddr(_T(""))
, m_strSalary(_T(""))
, m_nDrawType(0)
, m_ptOrigin(0)
{
	// TODO: 在此处添加构造代码
    memset(m_bLike,0,sizeof(m_bLike));

}

CPropView::~CPropView()
{
}

BOOL CPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPropView 绘制

void CPropView::OnDraw(CDC* pDC)
{
	CPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

    CFont font;
    font.CreatePointFont(300,"华文行楷");
    pDC->SelectObject(&font);
    CString strOut;
    strOut="你的职业是：";
    switch (m_iOccupation)
    {
    case 0:
        strOut+="程序员";
    	break;
    case 1:
        strOut+="系统工程师";
        break;
    case 2:
        strOut+="项目经理";
        break;
    default:
        break;
    }
    pDC->TextOut(0,0,strOut);
    strOut="你的工作地点：";
    strOut+=m_strWorkAddr;
    TEXTMETRIC tm;
    pDC->GetTextMetrics(&tm);
    pDC->TextOut(0,tm.tmHeight,strOut);
    strOut="你的兴趣爱好：";
    if (m_bLike[0])
    {
        strOut+="足球 ";
    }
    if (m_bLike[1])
    {
        strOut+="篮球 ";
    }
    if (m_bLike[2])
    {
        strOut+="排球 ";
    }
    if (m_bLike[3])
    {
        strOut+="游泳 ";
    }
    pDC->TextOut(0,tm.tmHeight*2,strOut);
    strOut="你的薪资水平： ";
    strOut+=m_strSalary;

    pDC->TextOut(0,tm.tmHeight*3,strOut);

}


// CPropView 诊断

#ifdef _DEBUG
void CPropView::AssertValid() const
{
	CView::AssertValid();
}

void CPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropDoc* CPropView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropDoc)));
	return (CPropDoc*)m_pDocument;
}
#endif //_DEBUG


// CPropView 消息处理程序

void CPropView::OnProperty()
{
    // TODO: 在此添加命令处理程序代码
    CPropSheet propSheet("属性表单");
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
    // TODO: 在此添加命令处理程序代码
    m_nDrawType=1;

}

void CPropView::OnLine()
{
    // TODO: 在此添加命令处理程序代码
    m_nDrawType=2;
}

void CPropView::OnRectangle()
{
    // TODO: 在此添加命令处理程序代码
    m_nDrawType=3;
}

void CPropView::OnEllipse()
{
    // TODO: 在此添加命令处理程序代码
    m_nDrawType=4;
}

void func(int x)
{
	TRACE("%d\t",x);
}
void CPropView::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
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
    // TODO: 在此添加消息处理程序代码和/或调用默认值
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

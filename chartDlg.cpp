
// chartDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "chart.h"
#include "chartDlg.h"
#include "SettingDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CchartDlg 对话框




CchartDlg::CchartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CchartDlg::IDD, pParent)
    , m_Quantity(0)
    , m_Groups(0)
    , m_pData(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_clrD=RGB(0,0,0);
    m_clrL1=RGB(0,0,255);
    m_clrL2=RGB(0,255,0);
    m_clrL3=RGB(255,0,0);
    m_clrL4=RGB(255,0,255);
    m_clrL5=RGB(0,255,255);
    m_clrEvenLine=RGB(255,255,0);
    m_clrOddLine=RGB(0,255,255);

}

void CchartDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);

    DDX_Control(pDX, IDC_LISTCTRL, m_List);
}

BEGIN_MESSAGE_MAP(CchartDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(ID_GENERATE, &CchartDlg::OnBnClickedGenerate)
    ON_WM_LBUTTONDOWN()
//	ON_WM_SIZE()
ON_WM_SIZE()
ON_COMMAND(IDM_SETTING, &CchartDlg::OnSetting)
//ON_WM_MOVE()
//ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// CchartDlg 消息处理程序

BOOL CchartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    
    CMenu menu;
    menu.LoadMenu(IDR_MAINMENU);
    SetMenu(&menu);
    menu.Detach();

    CString strTemp;
    ((CComboBox*)GetDlgItem(IDC_COMBO_Quantity))->ResetContent();//消除现有所有内容
    for(int i=1;i<=50;i++)
    {
        strTemp.Format("%d",i);
        ((CComboBox*)GetDlgItem(IDC_COMBO_Quantity))->AddString(strTemp);
    }
    
    m_List.ModifyStyle( 0, LVS_REPORT );               // 报表模式  
    m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_GRIDLINES 
        | LVS_EX_FULLROWSELECT);  
    m_List.InsertColumn(0,"编号");  
    m_List.InsertColumn(1,"第一组"); 
    m_List.InsertColumn(2,"第二组"); 
    m_List.InsertColumn(3,"第三组"); 
    m_List.InsertColumn(4,"第四组"); 
    m_List.InsertColumn(5,"第五组"); 

	CRect rect;  
	m_List.GetClientRect(rect); //获得当前客户区信息  
	m_List.SetColumnWidth(0, rect.Width() / 8);

	for (int i=1;i<6;i++)
	{
		m_List.SetColumnWidth(i, rect.Width() / 6); //设置列的宽度。  
	}

    //创建状态栏
    static UINT indicators[]={ID_SEPARATOR};  
    if(!m_wndStatusBar.Create(this)|| 
        !m_wndStatusBar.SetIndicators(indicators,sizeof(indicators)/sizeof(UINT)))  
    {  
        TRACE0("Can't create status bar/n");  
        return false;  
    }  
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CchartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	ResizeList();
    DrawLine();

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CchartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CchartDlg::OnBnClickedGenerate()
{
    // TODO: 在此添加控件通知处理程序代码
    GenerateList();
    DrawLine();

}

void CchartDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    CDialog::OnLButtonDown(nFlags, point);
}



void CchartDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码

	//ResizeList();
    if (m_wndStatusBar.GetSafeHwnd())
    {
        CRect  rect; 
        GetClientRect(&rect);
        rect.top=rect.bottom-20;
        m_wndStatusBar.MoveWindow(&rect);
    }
	
}


void CchartDlg::OnSetting()
{
    // TODO: 在此添加命令处理程序代码
    CSettingDialog dlg;
    dlg.m_clrCoordinate=m_clrD;
    dlg.m_clrLine1=m_clrL1;
    dlg.m_clrLine2=m_clrL2;
    dlg.m_clrLine3=m_clrL3;
    dlg.m_clrLine4=m_clrL4;
    dlg.m_clrLine5=m_clrL5;
    dlg.m_clrOddLine=m_clrOddLine;
    dlg.m_clrEvenLine=m_clrEvenLine;
    if (IDOK==dlg.DoModal())
    {
        m_clrD=dlg.m_clrCoordinate;
        m_clrL1=dlg.m_clrLine1;
        m_clrL2=dlg.m_clrLine2;
        m_clrL3=dlg.m_clrLine3;
        m_clrL4=dlg.m_clrLine4;
        m_clrL5=dlg.m_clrLine5;
        m_clrOddLine=dlg.m_clrOddLine;
        m_clrEvenLine=dlg.m_clrEvenLine;
        DrawLine();
        setLineColor();
    }
    
}

void CchartDlg::ResizeList(void)
{
    if (m_List)
    {
        CRect  rect; 
        GetClientRect(&rect);
        rect.top+=25;
        rect.bottom=(rect.bottom+rect.top)/3;
        m_List.MoveWindow(&rect,true); 

        m_List.SetColumnWidth(0, rect.Width() / 8);

        for (int i=1;i<6;i++)
        {
            m_List.SetColumnWidth(i, rect.Width() / 6); //设置列的宽度。  
        }
        
    }
}

//void CchartDlg::OnMove(int x, int y)
//{
//    CDialog::OnMove(x, y);
//    ResizeList();
//    // TODO: 在此处添加消息处理程序代码
//}

//void CchartDlg::OnSysCommand(UINT nID, LPARAM lParam)
//{
//    // TODO: 在此添加消息处理程序代码和/或调用默认值
//    if (nID==SC_ZOOM)
//    {
//        ResizeList();
//    }
//    CDialog::OnSysCommand(nID, lParam);
//}

void CchartDlg::GenerateList(void)
{

    if (m_pData)
    {
        for (int i=0;i<m_Quantity;i++)
        {
            delete [] m_pData[i];
        }
        delete []m_pData;
        m_List.DeleteAllItems();
    }
    CString str;
    m_Quantity=GetDlgItemInt(IDC_COMBO_Quantity);
    m_Groups=GetDlgItemInt(IDC_COMBO_GROUPS);

    if ((m_Quantity<1||m_Quantity>50)||(m_Groups<1||m_Groups>5))
    {
        if (m_Quantity<1||m_Quantity>50)
        {
            str+="数量为1~50\n";
        }
        if (m_Groups<1||m_Groups>5)
        {
            str+="组数为1~5\n";
        }
        MessageBox(str);
        return ;
    } 
    else
    {
        int t1=GetTickCount();
        m_pData=new int* [m_Quantity];
        for (int i=0;i<m_Quantity;i++)
        {
            str.Format("%d",i+1);
            m_List.InsertItem(i,str);
            m_pData[i]=new int[m_Groups];
            for (int j=0;j<m_Groups;j++)
            {
                m_pData[i][j]=rand() % 21-10;
                str.Format("%d",m_pData[i][j]);
                m_List.SetItemText(i, j+1, str);
            }
            for (int j=m_Groups;j<5;j++)
            {
                m_List.SetItemText(i, j+1, "0");
            }
        }
        int t2=GetTickCount();
        setLineColor();
        CString strStatusBar;
        strStatusBar.Format("测试数据数量: %d × %d ,耗时 %d ms",m_Quantity,
            m_Groups,t2-t1);
        m_wndStatusBar.SetPaneText(0,strStatusBar);
        DrawLine();
    }
}

void CchartDlg::DrawLine(void)
{

    if (!m_List.GetItemCount())
    {
        return;
    }

    CRect rectListCtrl,rectWindow,rectDrawing;
    GetDlgItem(IDC_LISTCTRL)->GetClientRect(&rectListCtrl);
    GetClientRect(&rectWindow);
    rectDrawing.top=rectListCtrl.bottom+40;
    rectDrawing.bottom=rectWindow.bottom-40;
    rectDrawing.left=rectWindow.left+30;
    rectDrawing.right=rectWindow.right-20;
    int y_middle=(rectDrawing.bottom+rectDrawing.top)/2;
    CRect rectClear(rectDrawing.left-30,rectDrawing.top-10,rectDrawing.right+20
        ,rectDrawing.bottom+20);

    CClientDC dcPaint(this);
    dcPaint.FillSolidRect(rectClear, RGB(255,255,255));
    CPen pen(PS_SOLID,1,m_clrD);
    dcPaint.SelectObject(&pen);
    dcPaint.MoveTo(rectDrawing.left,rectDrawing.bottom);
    dcPaint.LineTo(rectDrawing.left,rectDrawing.top);
    dcPaint.LineTo(rectDrawing.left,y_middle);
    dcPaint.LineTo(rectDrawing.right,y_middle);
    dcPaint.TextOut(rectDrawing.left-20,rectDrawing.top,"10");
    dcPaint.TextOut(rectDrawing.left-10,y_middle-5,"0");
    dcPaint.TextOut(rectDrawing.left-20,rectDrawing.bottom-10,"-10");

    COLORREF clrTmp;
    for (int i=0;i<m_Groups;i++)
    {
        switch (i)
        {
        case 0:
            clrTmp=m_clrL1;
            break;
        case 1:
            clrTmp=m_clrL2;
            break;
        case 2:
            clrTmp=m_clrL3;
            break;
        case 3:
            clrTmp=m_clrL4;
            break;
        case 4:
            clrTmp=m_clrL5;
            break;
        }
        CPen LinePen(PS_SOLID,1,clrTmp);
        dcPaint.SelectObject(&LinePen);
        dcPaint.MoveTo(rectDrawing.left+5
            ,rectDrawing.bottom-(m_pData[0][i]+10)/20.0*rectDrawing.Height());
        for (int j=1;j<m_Quantity;j++)
        {
            dcPaint.LineTo(rectDrawing.left+5+(float)j/(m_Quantity-1)*(rectDrawing.Width()-5)
                ,rectDrawing.bottom-(m_pData[j][i]+10)/20.0*rectDrawing.Height());
        }
    }
}

void CchartDlg::setLineColor(void)
{
    for (int i=0;i<m_Quantity;i++)
    {
        if (i%2)
        {
            //偶数行
            m_List.SetItemColor(i,RGB(0,0,0),m_clrEvenLine);
        }
        else
        {
            //奇数行
            m_List.SetItemColor(i,RGB(0,0,0),m_clrOddLine);
        }
    }
    
}

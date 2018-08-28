
// chartDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "chart.h"
#include "chartDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CchartDlg �Ի���




CchartDlg::CchartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CchartDlg::IDD, pParent)
    , m_Quantity(0)
    , m_Groups(0)
    , m_pData(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
END_MESSAGE_MAP()


// CchartDlg ��Ϣ�������

BOOL CchartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    
    CMenu menu;
    menu.LoadMenu(IDR_MAINMENU);
    SetMenu(&menu);
    menu.Detach();

    CString strTemp;
    ((CComboBox*)GetDlgItem(IDC_COMBO_Quantity))->ResetContent();//����������������
    for(int i=1;i<=50;i++)
    {
        strTemp.Format("%d",i);
        ((CComboBox*)GetDlgItem(IDC_COMBO_Quantity))->AddString(strTemp);
    }
    
    m_List.ModifyStyle( 0, LVS_REPORT );               // ����ģʽ  
    m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_GRIDLINES 
        | LVS_EX_FULLROWSELECT);  
	
    m_List.InsertColumn(0,"���");  
    m_List.InsertColumn(1,"��һ��"); 
    m_List.InsertColumn(2,"�ڶ���"); 
    m_List.InsertColumn(3,"������"); 
    m_List.InsertColumn(4,"������"); 
    m_List.InsertColumn(5,"������"); 

	CRect rect;  
	m_List.GetClientRect(rect); //��õ�ǰ�ͻ�����Ϣ  
	m_List.SetColumnWidth(0, rect.Width() / 8);

	for (int i=1;i<6;i++)
	{
		m_List.SetColumnWidth(i, rect.Width() / 6); //�����еĿ�ȡ�  
	}

    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CchartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CchartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CchartDlg::OnBnClickedGenerate()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

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
            str+="����Ϊ1~50\n";
        }
        if (m_Groups<1||m_Groups>5)
        {
            str+="����Ϊ1~5\n";
        }
        MessageBox(str);
        return ;
    } 
    else
    {
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
    }
	CRect rectListCtrl,rectWindow,rectDrawing;

	GetDlgItem(IDC_LISTCTRL)->GetClientRect(&rectListCtrl);
	GetClientRect(&rectWindow);
	rectDrawing.top=rectListCtrl.bottom+30;
	rectDrawing.bottom=rectWindow.bottom-10;
	rectDrawing.left=rectWindow.left+10;
	rectDrawing.right=rectWindow.right-10;


	CClientDC dc(this);
	dc.MoveTo(rectDrawing.left,rectDrawing.top);
	dc.LineTo(rectDrawing.right,rectDrawing.top);
	dc.LineTo(rectDrawing.right,rectDrawing.bottom);
	dc.LineTo(rectDrawing.left,rectDrawing.bottom);
	dc.LineTo(rectDrawing.left,rectDrawing.top);
    
}

void CchartDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CDialog::OnLButtonDown(nFlags, point);
}



void CchartDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if (m_List)
	{
		CRect  rect; 
		//GetWindowRect(&rect);  //��ȡ����rect��
		//ScreenToClient(rect);  //�Ӵ��ڳߴ�ת�����û���rect
		GetClientRect(&rect);
		rect.top+=25;
		rect.bottom=(rect.bottom+rect.top)/3;
		m_List.MoveWindow(&rect,true); 

		m_List.SetColumnWidth(0, cx / 8);

		for (int i=1;i<6;i++)
		{
			m_List.SetColumnWidth(i, cx / 6); //�����еĿ�ȡ�  
		}
	}
	
}


// chartDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxext.h"
#include "NewListCtrl.h"
#include "atltypes.h"



// CchartDlg 对话框
class CchartDlg : public CDialog
{
    // 构造
  public:
    CchartDlg(CWnd *pParent = NULL); // 标准构造函数

    // 对话框数据
    enum
    {
        IDD = IDD_CHART_DIALOG
    };

  protected:
    virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

    // 实现
  protected:
    HICON m_hIcon;

    // 生成的消息映射函数
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
  public:

    afx_msg void OnBnClickedGenerate();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    void DrawLine(void);

private:
    CNewListCtrl m_List;
    int **m_pData;
    CStatusBar m_wndStatusBar;
    int m_Quantity;
    int m_Groups;
public:
    afx_msg void OnSetting();

  private:
    void ResizeList(void);//设置CListCtrl列宽

  public:
  private:
    void GenerateList(void);

  private:
    COLORREF m_clrD, m_clrL1, m_clrL2, m_clrL3, m_clrL4, m_clrL5;
    COLORREF m_clrOddLine;
    COLORREF m_clrEvenLine;

  public:

    void setLineColor(void);
    afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);

    afx_msg void OnNMClickListctrl(NMHDR *pNMHDR, LRESULT *pResult);
private:
    COLORREF m_clrSelected;
    static DWORD WINAPI DrawLineThread(LPVOID lpParameter);
    CRect rectDrawing;
    void PreDrawLine(void);
public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};

class ThreadInfo
{
public:
	//int index[5];
	int **m_pdata;
	CRect rect;
	COLORREF m_clrL[5];
	int m_quantity;
    CchartDlg *m_dlgChart;

	ThreadInfo()
	{
        
	}
};

// chartDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxext.h"
#include "NewListCtrl.h"
#include "atltypes.h"
#include "CustomStatusBar.h"

#define UM_SOCK WM_USER+1
// CchartDlg 对话框


class CchartDlg : public CDialog
{
  // 构造
public:
  CchartDlg(CWnd *pParent = NULL); // 标准构造函数
  ~CchartDlg();
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
  afx_msg LRESULT OnSock(WPARAM,LPARAM);
  DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedGenerate();
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnSize(UINT nType, int cx, int cy);
  void DrawLine(void);

private:
  CNewListCtrl m_List;
  int **m_pData;
  CCustomStatusBar m_wndStatusBar;
  CStatic staticStatus;
  int m_Quantity;
  int m_Groups;

public:
  afx_msg void OnSetting();

private:
  void ResizeList(void); //设置CListCtrl列宽

public:
private:
  void GenerateList(void);

private:
  COLORREF m_clrD, m_clrL[5];
  COLORREF m_clrOddLine;
  COLORREF m_clrEvenLine;
  COLORREF m_clrStatusBar;

public:
  void setLineColor(void);
  afx_msg void OnGetMinMaxInfo(MINMAXINFO *lpMMI);

  afx_msg void OnNMClickListctrl(NMHDR *pNMHDR, LRESULT *pResult);

private:
  COLORREF m_clrSelected;
  static DWORD WINAPI DrawLineThread(LPVOID lpParameter);
  CRect rectDrawing;
  void PreDrawLine(void);

public:
  afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
    SOCKET m_socket;
protected:
    bool InitSocket(void);
};

class ThreadInfo
{
public:
  int **m_pdata;
  CRect rect;
  COLORREF m_clrL[5];
  int m_quantity;
  CchartDlg *m_dlgChart;
};

class TrafficMessage
{
public:
    bool AlreadyLogin;
    char Username[20];
    char Passwd[20];
    int quantity;
    int group;
    TrafficMessage()
    {
        AlreadyLogin=FALSE;
    }
};
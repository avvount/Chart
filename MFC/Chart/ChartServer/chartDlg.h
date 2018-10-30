
// chartDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxext.h"
#include "NewListCtrl.h"
#include "atltypes.h"
#include "CustomStatusBar.h"

#define UM_SOCK WM_USER+1
// CchartDlg �Ի���


class CchartDlg : public CDialog
{
  // ����
public:
  CchartDlg(CWnd *pParent = NULL); // ��׼���캯��
  ~CchartDlg();
  // �Ի�������
  enum
  {
    IDD = IDD_CHART_DIALOG
  };

protected:
  virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV ֧��

  // ʵ��
protected:
  HICON m_hIcon;

  // ���ɵ���Ϣӳ�亯��
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
  void ResizeList(void); //����CListCtrl�п�

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
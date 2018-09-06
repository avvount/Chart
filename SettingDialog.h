#pragma once
#include "afxbutton.h"

// CSettingDialog 对话框

class CSettingDialog : public CDialog
{
    DECLARE_DYNAMIC(CSettingDialog)

  public:
    CSettingDialog(CWnd *pParent = NULL); // 标准构造函数
    virtual ~CSettingDialog();
    virtual BOOL OnInitDialog();
    // 对话框数据
    enum
    {
        IDD = IDD_SETTING_DIALOG
    };

  protected:
    virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

    DECLARE_MESSAGE_MAP()
  public:
    
    afx_msg void OnBnClickedCoordinate();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    COLORREF m_clrCoordinate,m_clrOddLine,m_clrEvenLine,m_clrSelected;
    COLORREF m_clrLine1, m_clrLine2, m_clrLine3, m_clrLine4, m_clrLine5;
    COLORREF m_clrStatusBar;
    afx_msg void OnBnClickedLine1();
    afx_msg void OnBnClickedLine2();
    afx_msg void OnBnClickedLine3();
    afx_msg void OnBnClickedLine4();
    afx_msg void OnBnClickedLine5();
    afx_msg void OnBnClickedOddline();
    afx_msg void OnBnClickedEvenline();
    afx_msg void OnBnClickedChoosenline();
private:
    CMFCButton m_btnSelectedLine;
    CMFCButton m_Coordinate;
    CMFCButton m_btnOddLine;
    CMFCButton m_btnEvenLine;
    CMFCButton m_btnLine1;
    CMFCButton m_btnLine2;
    CMFCButton m_btnLine3;
    CMFCButton m_btnLine4;
    CMFCButton m_btnLine5;
    CMFCButton m_btnStatusBar;
public:
    afx_msg void OnBnClickedStatusbar();
};


// ChartClientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CChartClientDlg �Ի���
class CChartClientDlg : public CDialog
{
    // ����
public:
    CChartClientDlg(CWnd* pParent = NULL);	// ��׼���캯��
    ~CChartClientDlg();
    // �Ի�������
    enum { IDD = IDD_CHARTCLIENT_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


    // ʵ��
protected:
    HICON m_hIcon;

    // ���ɵ���Ϣӳ�亯��
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnsend();

private:
    CListCtrl m_List;
    int** m_pdata;

public:
    afx_msg void OnBnClickedBtnlogout();
};

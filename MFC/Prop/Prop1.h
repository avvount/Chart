#pragma once
#include "resource.h"

// CProp1 �Ի���

class CProp1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp1)

public:
	CProp1();
	virtual ~CProp1();

// �Ի�������
	enum { IDD = IDD_PROP1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnSetActive();
    int m_occupation;
    virtual LRESULT OnWizardNext();
    afx_msg void OnBnClickedRadio1();
    virtual BOOL OnInitDialog();
    CString m_strworkAddr;
};
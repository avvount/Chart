#pragma once


// CProp2 �Ի���

class CProp2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp2)

public:
	CProp2();
	virtual ~CProp2();

// �Ի�������
	enum { IDD = IDD_PROP2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnSetActive();
    BOOL m_bFootball;
    BOOL m_bBasketball;
    BOOL m_bVolleyball;
    BOOL m_bSwim;
    virtual LRESULT OnWizardNext();
};

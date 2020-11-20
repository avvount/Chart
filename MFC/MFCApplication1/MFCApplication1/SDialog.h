#pragma once
class CSDialog:public CDialog
{
	DECLARE_DYNAMIC(CSDialog)
public:
	CSDialog();
	~CSDialog();
	void draw();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};



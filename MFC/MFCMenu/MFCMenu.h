
// MFCMenu.h : MFCMenu Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCMenuApp:
// �йش����ʵ�֣������ MFCMenu.cpp
//

class CMFCMenuApp : public CWinApp
{
public:
	CMFCMenuApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMenuApp theApp;

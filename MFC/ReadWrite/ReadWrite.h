
// ReadWrite.h : ReadWrite Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CReadWriteApp:
// �йش����ʵ�֣������ ReadWrite.cpp
//

class CReadWriteApp : public CWinAppEx
{
public:
	CReadWriteApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
//    afx_msg void OnCustomApiwrite();
};

extern CReadWriteApp theApp;

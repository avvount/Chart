
// chart.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h" // ������

// CchartApp:
// �йش����ʵ�֣������ chart.cpp
//

class CchartApp : public CWinAppEx
{
  public:
	CchartApp();
    ~CchartApp();
	// ��д
  public:
	virtual BOOL InitInstance();

	// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CchartApp theApp;

// ChartClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h" // ������

// CChartClientApp:
// �йش����ʵ�֣������ ChartClient.cpp
//

class CChartClientApp : public CWinAppEx
{
  public:
	CChartClientApp();
	~CChartClientApp();
	// ��д
  public:
	virtual BOOL InitInstance();

	// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CChartClientApp theApp;
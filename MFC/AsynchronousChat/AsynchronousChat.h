
// AsynchronousChat.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#define UM_SOCK WM_USER+1

// CAsynchronousChatApp:
// �йش����ʵ�֣������ AsynchronousChat.cpp
//

class CAsynchronousChatApp : public CWinAppEx
{
public:
	CAsynchronousChatApp();
    ~CAsynchronousChatApp(void);

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��
    
	DECLARE_MESSAGE_MAP()
    
};

extern CAsynchronousChatApp theApp;
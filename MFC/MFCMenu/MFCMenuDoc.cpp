
// MFCMenuDoc.cpp : CMFCMenuDoc 类的实现
//

#include "stdafx.h"
#include "MFCMenu.h"

#include "MFCMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMenuDoc

IMPLEMENT_DYNCREATE(CMFCMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCMenuDoc, CDocument)
END_MESSAGE_MAP()


// CMFCMenuDoc 构造/析构

CMFCMenuDoc::CMFCMenuDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFCMenuDoc::~CMFCMenuDoc()
{
}

BOOL CMFCMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCMenuDoc 序列化

void CMFCMenuDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMFCMenuDoc 诊断

#ifdef _DEBUG
void CMFCMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCMenuDoc 命令

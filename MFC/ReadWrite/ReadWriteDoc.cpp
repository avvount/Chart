
// ReadWriteDoc.cpp : CReadWriteDoc 类的实现
//

#include "stdafx.h"
#include "ReadWrite.h"

#include "ReadWriteDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CReadWriteDoc

IMPLEMENT_DYNCREATE(CReadWriteDoc, CDocument)

BEGIN_MESSAGE_MAP(CReadWriteDoc, CDocument)
//    ON_COMMAND(ID_CUSTOM_APIWRITE, &CReadWriteDoc::OnCustomApiwrite)
END_MESSAGE_MAP()

// CReadWriteDoc 构造/析构

CReadWriteDoc::CReadWriteDoc()
{
	// TODO: 在此添加一次性构造代码
}

CReadWriteDoc::~CReadWriteDoc()
{
}

BOOL CReadWriteDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	//SetTitle("CGraphic");

	return TRUE;
}

// CReadWriteDoc 序列化

void CReadWriteDoc::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码

		CString str;
		ar >> str;
		AfxMessageBox(str);
	}
}

// CReadWriteDoc 诊断

#ifdef _DEBUG
void CReadWriteDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CReadWriteDoc::Dump(CDumpContext &dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

// CReadWriteDoc 命令

//void CReadWriteDoc::OnCustomApiwrite()
//{
//    // TODO: 在此添加命令处理程序代码
//    AfxMessageBox("文档类");
//
//}

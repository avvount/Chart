
// ReadWriteDoc.cpp : CReadWriteDoc ���ʵ��
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

// CReadWriteDoc ����/����

CReadWriteDoc::CReadWriteDoc()
{
	// TODO: �ڴ����һ���Թ������
}

CReadWriteDoc::~CReadWriteDoc()
{
}

BOOL CReadWriteDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	//SetTitle("CGraphic");

	return TRUE;
}

// CReadWriteDoc ���л�

void CReadWriteDoc::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���

		CString str;
		ar >> str;
		AfxMessageBox(str);
	}
}

// CReadWriteDoc ���

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

// CReadWriteDoc ����

//void CReadWriteDoc::OnCustomApiwrite()
//{
//    // TODO: �ڴ���������������
//    AfxMessageBox("�ĵ���");
//
//}

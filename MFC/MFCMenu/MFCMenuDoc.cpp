
// MFCMenuDoc.cpp : CMFCMenuDoc ���ʵ��
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


// CMFCMenuDoc ����/����

CMFCMenuDoc::CMFCMenuDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFCMenuDoc::~CMFCMenuDoc()
{
}

BOOL CMFCMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFCMenuDoc ���л�

void CMFCMenuDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMFCMenuDoc ���

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


// CMFCMenuDoc ����

#include "stdafx.h"
#include "MFCApplication1.h"
#include "NO.h"
#include "afxdialogex.h"
#include "SDialog.h"
IMPLEMENT_DYNAMIC(CSDialog, CDialog)
BEGIN_MESSAGE_MAP(CSDialog, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()
CSDialog::CSDialog()
{
	
}


CSDialog::~CSDialog()
{
}


void CSDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	draw();
	
}

void CSDialog::draw()
{
	CRect Rect;
	GetClientRect(&Rect);
	//��Ļ���
	int width = Rect.right - Rect.left;
	//��Ļ�߶�
	int height = Rect.bottom - Rect.top;
	CDC *pDc = GetDC();
	pDc->MoveTo(0, 0);
	pDc->LineTo(50, 50);
}
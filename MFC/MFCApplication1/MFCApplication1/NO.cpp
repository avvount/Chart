// NO.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "NO.h"
#include "afxdialogex.h"


// CNO �Ի���

IMPLEMENT_DYNAMIC(CNO, CDialogEx)

CNO::CNO(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CNO::~CNO()
{
}

void CNO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNO, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CNO ��Ϣ�������


void CNO::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}

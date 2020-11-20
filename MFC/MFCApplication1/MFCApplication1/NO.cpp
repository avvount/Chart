// NO.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "NO.h"
#include "afxdialogex.h"


// CNO 对话框

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


// CNO 消息处理程序


void CNO::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
}

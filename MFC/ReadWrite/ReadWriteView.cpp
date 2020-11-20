
// ReadWriteView.cpp : CReadWriteView 类的实现
//

#include "stdafx.h"
#include "ReadWrite.h"

#include "ReadWriteDoc.h"
#include "ReadWriteView.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include "SimpleXlsx\Xlsx\Workbook.h"
#include "SimpleXlsx\Xlsx\Worksheet.h"
using namespace SimpleXlsx;
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CReadWriteView

IMPLEMENT_DYNCREATE(CReadWriteView, CView)

BEGIN_MESSAGE_MAP(CReadWriteView, CView)
ON_COMMAND(ID_READ, &CReadWriteView::OnMfcread)
ON_COMMAND(ID_MFCWRITE, &CReadWriteView::OnMfcwrite)
ON_COMMAND(ID_REG_WRITE, &CReadWriteView::OnRegWrite)
ON_COMMAND(ID_REG_READ, &CReadWriteView::OnRegRead)
ON_COMMAND(ID_ARCHIVELOAD, &CReadWriteView::OnArchiveload)
ON_COMMAND(ID_ARCHIVESTORE, &CReadWriteView::OnArchivestore)
//    ON_COMMAND(ID_CUSTOM_TEST, &CReadWriteView::OnCustomTest)
ON_COMMAND(ID_CUSTOM_CPPREAD, &CReadWriteView::OnCustomCppread)
ON_COMMAND(ID_CUSTOM_CPPWRITE, &CReadWriteView::OnCustomCppwrite)
ON_COMMAND(ID_CUSTOM_APIREAD, &CReadWriteView::OnCustomApiread)
//ON_COMMAND(ID_CUSTOM_APIWRITE, &CReadWriteView::OnCustomApiwrite)
ON_COMMAND(ID_CUSTOM_XLSX, &CReadWriteView::OnCustomXlsx)
END_MESSAGE_MAP()

// CReadWriteView 构造/析构

CReadWriteView::CReadWriteView()
    : p(NULL), count(0)
{
    // TODO: 在此处添加构造代码
}

CReadWriteView::~CReadWriteView()
{
}

BOOL CReadWriteView::PreCreateWindow(CREATESTRUCT &cs)
{
    // TODO: 在此处通过修改
    //  CREATESTRUCT cs 来修改窗口类或样式

    return CView::PreCreateWindow(cs);
}

// CReadWriteView 绘制

void CReadWriteView::OnDraw(CDC * /*pDC*/)
{
    CReadWriteDoc *pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO: 在此处为本机数据添加绘制代码
}

void CReadWriteView::OnRButtonUp(UINT nFlags, CPoint point)
{
    ClientToScreen(&point);
    OnContextMenu(this, point);
}

void CReadWriteView::OnContextMenu(CWnd *pWnd, CPoint point)
{
    theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}

// CReadWriteView 诊断

#ifdef _DEBUG
void CReadWriteView::AssertValid() const
{
    CView::AssertValid();
}

void CReadWriteView::Dump(CDumpContext &dc) const
{
    CView::Dump(dc);
}

CReadWriteDoc *CReadWriteView::GetDocument() const // 非调试版本是内联的
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CReadWriteDoc)));
    return (CReadWriteDoc *)m_pDocument;
}
#endif //_DEBUG

// CReadWriteView 消息处理程序

void CReadWriteView::OnMfcread()
{
    // TODO: 在此添加命令处理程序代码
    //FILE *pfile=fopen("D:/test.txt","r");
    CFileDialog OpenFileDialog(true);

    if (IDOK == OpenFileDialog.DoModal())
    {
        CFile openFile(OpenFileDialog.GetPathName(), CFile::modeRead);
        count = openFile.GetLength() + 1;
        p = new char[count];
        p[count] = 0;
        openFile.Read(p, count);
        MessageBox(p);
    }
}

void CReadWriteView::OnMfcwrite()
{
    // TODO: 在此添加命令处理程序代码

    CFileDialog fileDlg(false);
    fileDlg.m_ofn.lpstrFilter = "Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
    fileDlg.m_ofn.lpstrDefExt = "txt";
    if (IDOK == fileDlg.DoModal())
    {

        CFile saveFile(fileDlg.GetPathName(), CFile::modeWrite | CFile::modeCreate);
        saveFile.Write(p, count);
        saveFile.Close();
    }
}

void CReadWriteView::OnRegWrite()
{
    // TODO: 在此添加命令处理程序代码
    HKEY hKey;
    RegCreateKey(HKEY_LOCAL_MACHINE, "Software\\注册表操作\\name", &hKey);
    RegSetValue(hKey, NULL, REG_SZ, "VC++深入详解", strlen("VC++深入详解"));
    DWORD dwAge = 30;
    RegSetValueEx(hKey, "年龄", 0, REG_DWORD, (const byte *)&dwAge, sizeof(DWORD));
    RegCloseKey(hKey);
}

void CReadWriteView::OnRegRead()
{
    // TODO: 在此添加命令处理程序代码

    CString str;
    LONG lValue;
    HKEY hKey;
    RegOpenKey(HKEY_LOCAL_MACHINE, "Software\\注册表操作\\name", &hKey);
    RegQueryValue(hKey, NULL, NULL, &lValue);
    //RegQueryValue(HKEY_LOCAL_MACHINE,"Software\\注册表操作\\name",NULL,&lValue);
    if (lValue > 0)
    {
        RegQueryValue(hKey, NULL, str.GetBuffer(lValue), &lValue);
        //RegQueryValue(HKEY_LOCAL_MACHINE,"Software\\注册表操作\\name",str.GetBuffer(lValue),&lValue);
    }

    DWORD dwAge, dwValue;
    RegQueryValueEx(hKey, "年龄", NULL, NULL, (LPBYTE)&dwAge, &dwValue);
    RegCloseKey(hKey);
    CString strOut;
    strOut.Format("%s\t%d", str, dwAge);
    MessageBox(strOut);
}

void CReadWriteView::OnArchiveload()
{
    // TODO: 在此添加命令处理程序代码
    CFile file("D:/store", CFile::modeRead);
    CArchive ar(&file, CArchive::load);
    int a[10000];
    CString str;
    char *p = new char[2];
    for (int i = 0; i < 10000; i++)
    {
        ar >> a[i];
    }
    for (int i = 9900; i < 10000; i++)
    {
        str.Append(itoa(a[i], p, 10));
        //str.Append("\t");
    }

    MessageBox(str);
}

void CReadWriteView::OnArchivestore()
{
    // TODO: 在此添加命令处理程序代码
    CFile file("D:/store", CFile::modeWrite | CFile::modeCreate);
    CArchive ar(&file, CArchive::store);
    int a[10000];
    for (int i = 0; i < 10000; i++)
    {
        a[i] = i;
        ar << a[i];
    }
}

void CReadWriteView::OnCustomCppread()
{
    // TODO: 在此添加命令处理程序代码
    ifstream ifs("D:/test.txt");
    ifs.seekg(0, ios_base::end);
    int pos = ifs.tellg();
    ifs.seekg(0, ios_base::beg);
    char *p = new char[pos];
    ifs.read(p, pos);
    p[pos] = 0;
    ifs.close();
    MessageBox(p);
}

void CReadWriteView::OnCustomCppwrite()
{
    // TODO: 在此添加命令处理程序代码
    fstream fs("D:/test.txt", ios::out |ios::ate);
    int a;
    a=fs.tellg();
    int b;
    b=fs.tellp();
    /*cout<<fs.tellg()<<endl;
    cout<<fs.tellp()<<endl;*/
    //OutputDebugString();

    fs.write("C++写文件", strlen("C++写文件"));
    fs << "C++写文件";
    struct tmp
    {
        int a;
        double b;
        char s[15];
    } tmp = {5, 6185.2, "C++写文件"};
    fs.write((char *)&tmp, sizeof(tmp));
    a=fs.tellg();
    b=fs.tellp();
    fs.close();
}

void CReadWriteView::OnCustomApiread()
{
    // TODO: 在此添加命令处理程序代码
    HANDLE hFile = CreateFile("D:/test.txt", GENERIC_READ, FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    char ch[100];
    DWORD dwWords;
    ReadFile(hFile, ch, 99, &dwWords, NULL);
    MessageBox(ch);
}

//void CReadWriteView::OnCustomApiwrite()
//{
//    // TODO: 在此添加命令处理程序代码
//    MessageBox("视图类");
//}


void CReadWriteView::OnCustomXlsx()
{
	// TODO: 在此添加命令处理程序代码
	CWorkbook wb;
	
	int t1 = GetTickCount();
	for (size_t j = 0; j < 1; j++)
	{
		CWorksheet & sheet1 = wb.AddSheet(L"表一");
		for (size_t i = 0; i < 10000; i++)
		{
			sheet1.BeginRow();
			sheet1.AddCell("");
			sheet1.AddCell("1");
			sheet1.AddCell("2");
			sheet1.AddCell(L"三");
			sheet1.AddCell(L"四");
			sheet1.AddCell("");
			sheet1.AddCell("1");
			sheet1.AddCell("2");
			sheet1.AddCell(L"三");
			sheet1.AddCell(L"四");
			sheet1.EndRow();
		}
	}
	
	if (wb.Save("C:/Users/avvount/Desktop/wb.xlsx"))
	{
		int t2 = GetTickCount();
		TRACE("时间---------%d", t2 - t1);
	}
	else
	{
		ASSERT(0);
	}
	
}

#include <cstring>
#include "xlslib.h"
#include <Windows.h>
using namespace xlslib_core;
using namespace std;

int _cdecl main()
{
	workbook wb;
	worksheet* sheet1 = wb.sheet("sheet1");
	string label = "Hello, World!";
	int t1 = GetTickCount();
	for (size_t i = 0; i < 10000; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			sheet1->label(i, j, label);    // ��0��ʼ������1�У���2�У���C3

		}
	}

	wb.Dump("C:/Users/avvount/Desktop/workbook.xls");
	int t2 = GetTickCount();
	int t3 = t2 - t1;
	return 0;
}
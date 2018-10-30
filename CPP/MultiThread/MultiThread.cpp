#include<windows.h>
#include <iostream>
#include<conio.h>
#include <tchar.h>
using namespace std;
DWORD WINAPI Fun1Proc(LPVOID lpParameter);
int index=100;

typedef struct thread{
    int a;
    int *b;
    int **c;
}thread;
void main()
{
    HANDLE hThread1;
    thread ct;
    ct.a=2;
    int tmp=3;
    ct.b=&tmp;
    int **d=new int*[3];
    for (int i=0;i<3;i++)
    {
        d[i]=new int[4];
        for (int j=0;j<4;j++)
        {
            d[i][j]=i*4+j;
        }
    }
    ct.c=d;


    hThread1=CreateThread(0,0,Fun1Proc,&ct,0,0);
    CloseHandle(hThread1);

    _getche();
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
    thread *dd=(thread *)lpParameter;

    while(TRUE)
    {
        if (index>0)
        {
            
            Sleep(1);
            
            cout<<"thread 1 sell ticket "<<index--<<endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}



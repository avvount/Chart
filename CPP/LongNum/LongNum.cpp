#include <iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>

#define LIMIT 10
using namespace std;

int main()
{
    /*string str;

    cout<<str<<endl;
    system("pause");*/
    char s[5000];
    int n=0;
    while((s[n]=getchar())!=EOF)
    {
        if (isalpha(s[n]))
        {
            n++;
        }
    }
    s[n]=0;
    int num=0;
    for (int i=1;i<n-1;i++)
    {
        int count=1;
        int j=i-1;
        int k=i+1;
        while (j >= 0 && k < n && s[j] == s[k])
        {
            j--;
            k++;
            count+=2;
        }
        num=num>count?num:count;
    }
    for (int i=1;i<=n-1;i++)
    {
        int count=0;
        int j=i-1;
        int k=i;
        while (j >= 0 && k < n && s[j] == s[k])
        {
            j--;
            k++;
            count+=2;
        }
        num=num>count?num:count;
    }
    cout<<s<<endl;
    cout<<num<<endl;
}
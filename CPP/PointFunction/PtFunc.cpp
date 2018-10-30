//º¯ÊıÖ¸Õë

#include <iostream>
using namespace std;

class demo
{
public:
    int func(int a,int b)
    {
        int c=a+b;
        cout<<c<<endl;
        return c;
    }
};


void main()
{
    /* int (*p)(int,int);
    int a=0;
    int b=1;
    p=func;
    (*p)(a,b);*/
    int (demo:: *p)(int,int);
    p=&demo::func;
    int a=0;
    int b=3;
    demo t;
    (t.*p)(a,b);

}
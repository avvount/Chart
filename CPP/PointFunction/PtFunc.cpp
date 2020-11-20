//º¯ÊıÖ¸Õë

#include <iostream>
using namespace std;

class demo
{
public:
    int func(int a, int b)
    {
        int c = a + b;
        cout << c << endl;
        return c;
    }
};

using functon_pointer_type = int (demo::*)(int, int);

int main()
{
    /* int (*p)(int,int);
    int a=0;
    int b=1;
    p=func;
    (*p)(a,b);*/
    // int (demo:: *p)(int,int);
    functon_pointer_type p;
    p = &demo::func;

    decltype(&demo::func) abc;
    int a = 0;
    int b = 3;
    demo t;
    return (t.*p)(a, b);
}
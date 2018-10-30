#include<iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout<<"A constructor";
    }
    A(int a)
    {
        cout<<"A constructor"<<a<<endl;
    }

};
class B:public A
{
public:
    B(){
        cout<<"B constructor";
    }
    B(int a):A(3)
    {
        cout<<"B constructor"<<a<<endl;
    }
};

void main()
{
    B b(2);
}
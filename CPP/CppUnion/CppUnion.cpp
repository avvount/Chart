//Union¹²ÓÃÌå

#include <iostream>
using namespace std;

//union{
//    char c;
//    int a;
//}ac;
//int main()
//{
//    ac.c='1';
//    cout<<ac.a<<endl;
//}

struct node
{
    int data;
    node *next;
};
void func(int i,int j)
{
    cout<<i<<"\t"<<j<<endl;
}

void main()
{
    node n1;
    n1.data=1;
    n1.next=new node;
    n1.next->data=2;
    cout<<n1.data<<"\t"<<n1.next->data<<endl;
    delete n1.next;
}
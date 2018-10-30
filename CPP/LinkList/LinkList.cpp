#include<iostream>
#include "LinkList.h"
using namespace std;

Link::Link(const char *str/* =NULL */)
{
    strcpy(item,str);
}
Link *Link::get_next()
{
    return next;
}
void Link::print()
{
    cout<<item<<endl;
}

List::List()
{
    first=last=new Link;
}
List::~List()
{
    Clear();
    delete first;
}
List &List::Clear()
{
    Link *p=first;
    Link *tmp;
    while (p!=last)
    {
        tmp=p->next;
        delete p;
        p=tmp;
    }
    first=last;
    return *this;
}
List &List::Append(const char *str/* =NULL */)
{
    Link tmp(str);
    *last=tmp;
    last->next=new Link;
    last=last->next;
    return *this;
}
List &List::Insert(const char *str/*=NULL*/)
{
    Link *ptr=new Link(str);
    ptr->next=first;
    first=ptr;
    return *this;
}
List &List::Delete(void)
{
    if (last!=first)
    {
        Link *ptr=first->next;
        delete first;
        first=ptr;
    }
    return *this;

}
List &List::Remove(void)
{
    if (last!=first)
    {
        Link *now=first;
        Link *pre;
        while (now!=last)
        {
            pre=now;
            now=now->next;
        }
        last=pre;
        delete pre;
    }
    return *this;
}
List &List::Clear(void)
{
    while (first!=last)
    {
    }
}
void List::Print(void)
void main()
{

}
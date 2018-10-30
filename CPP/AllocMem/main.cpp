#include<iostream>
#include <cstdio>
using namespace std;

class Exam
{
    friend ostream& operator<< (ostream&,Exam&);
public:
    static void echo();
    Exam();
    Exam(const char* str);
    Exam(const Exam& other);
    ~Exam();
    Exam& operator =(const Exam &other);
    Exam operator +(const Exam &other)const;
    void printnum();
private:
    int num;
    char *p;
};


void Exam::echo()
{
    cout<<"Nothing"<<endl;
}
Exam::Exam()
{
    p=0;
    num=15;
}
Exam::Exam(const char *str)
{
    if (!str)
    {
        p=0;
    } 
    else
    {
        p=new char[strlen(str)+1];
        strcpy_s(this->p,strlen(str)+1,str);
    }
}
Exam::Exam(const Exam &other)
{
    if (!other.p)
    {
        p=0;
    } 
    else
    {
        p=new char[strlen(other.p)+1];
        strcpy_s(this->p,strlen(other.p)+1,other.p);
    }
}
Exam::~Exam()
{
    delete []p;
}
Exam Exam::operator +(const Exam &other)const
{
    Exam result;
    if (!other.p)
    {
        result=*this;
    } 
    else if (!p)
    {
        result=other;
    }
    else
    {
        result.p=new char[strlen(p)+strlen(other.p)+1];
        strcpy(result.p,p);
        strcat(result.p,other.p);
    }
    return result;
}
Exam& Exam::operator =(const Exam &other)
{
    if (this!=&other)
    {
        delete []p;
        if (!other.p)
        {
            p=0;
        }
        else
        {
            p=new char[strlen(other.p)+1];
            strcpy(p,other.p);
        }
    }
    return *this;
}
ostream& operator<<(ostream& os,Exam& str)  
{  
    os << str.p;  
    return os;  
}  

void Exam::printnum()
{
    cout<<"p is  "<<num<<endl;
}
class DExam:public Exam
{
public:
protected:
private:
};

void main()
{
    
    Exam exam1("balabalabalabala");
    Exam exam2;
    exam2="Nothing";

    cout<<exam1<<endl;
    cout<<exam2<<endl;

  Exam res;
    res=exam1+exam2;
    cout<<res<<endl;
    void (*p)(void);
    p=Exam::echo;
    (*p)();
    DExam de;
    de.printnum();
    res.printnum();
    
}
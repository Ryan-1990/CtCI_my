#include <iostream>
#include <malloc.h>

using namespace std;

char *reverse(char *str)
{
	char *p=str;
	char *start=str;
	while(*p)
	{
		p++;
	}
	p=p-1;
	while(p>start)
	{
		char temp=*start;
		*start=*p;
		*p=temp;
		start++;
		p--;
	}
	return str;
}

class person
{
public:
    int id;
    char *name;
    person(int d,char *str)
    {
        id=d;
        name=str;
    }
    virtual ~person() {cout<<"person destroyed"<<endl;}
    virtual void display()=0;
    /*{
        cout<<"person's id:  "<<id<<endl;
        cout<<"person's name:"<<name<<endl;
    }*/
};

class student: public person
{
public:
    student(int d,char*str): person(d,str){}
    ~student() {cout<<"student destroyed"<<endl;}
    void display()
    {
        cout<<"student's id:  "<<id<<endl;
        cout<<"student's name:"<<name<<endl;
    }
};

int main()
{
	/*
    char str[]="abcdefg";
	cout<<reverse(str);
    */
    /*
    person *p=new student(5,"ryan");
    p->display();
    delete p;
    */
    
    int *p=new int[100];
    cout<<p<<endl;
    delete []p;
    
    cout<<endl;
	return 0;
}

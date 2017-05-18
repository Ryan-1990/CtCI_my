#include <iostream>
#include <string>
#include "math.h"

using namespace std;

struct Node 
{
	int data;
	Node *next;
	Node(int d):data(d),next(NULL){}
};

class LinkList
{
public:
	LinkList();
	~LinkList();
	int GetLength();
	void InsertHead(int data);
	void InsertTail(int data);
	void Reverse();
	void RemoveDup();
	void Print();

	Node *head;
	Node *tail;
	int length;
};

LinkList::LinkList()
{
	head=NULL;
	tail=head;
	length=0;
}

LinkList::~LinkList()
{
	Node *temp;
	
	for(int i=0;i<length;i++)
	{
		temp=head;
		head=head->next;
		delete temp;
	}
}

int LinkList::GetLength()
{
	return length;
}

void LinkList::InsertHead(int data)
{
	Node *node=new Node(data);
	node->next=head;
	head=node;
	length++;
}

void LinkList::InsertTail(int data)
{
	Node *node=new Node(data);
	tail->next=node;
	node->next=NULL;
	tail=node;
	length++;
}

void LinkList::Reverse()
{
	if(head==NULL) return;

	Node *current=head->next;
	Node *nextnode;
	head->next=NULL;
	while(current!=NULL)
	{
		nextnode=current->next;
		current->next=head;
		head=current;
		current=nextnode;
	}
}

void LinkList::RemoveDup()
{
	Node *current=head;
	Node *runner=current;
	Node *temp;

	while(current!=NULL)
	{
		runner=current;
		while(runner->next!=NULL)
		{
			if(runner->next->data==current->data)
			{
				temp=runner->next;
				delete temp;
				runner->next=runner->next->next;
				length--;
			}
			else runner=runner->next;
		}
		current=current->next;
	}
}

void LinkList::Print()
{
	Node *current=head;

	for(int i=0;i<length;i++)
	{
		cout<<current->data<<endl;
		current=current->next;
	}
}

void Partition(LinkList ls,int x)
{	
	LinkList newlinklist;
	Node *current=ls.head;
	if(current->data<x) 
	{
		newlinklist.InsertHead(current->data);
		newlinklist.tail=newlinklist.head;
	}
	else 
	{
		newlinklist.InsertTail(current->data);
		newlinklist.head=newlinklist.tail;
	}
	current=current->next;
	while(current!=NULL)
	{
		if(current->data<x) newlinklist.InsertHead(current->data);
		else newlinklist.InsertTail(current->data);
		current=current->next;
	}
	cout<<"------------------"<<endl;
	newlinklist.Print();
}

void SumList(Node *head1,Node *head2)
{
	int num1=0;
	int num2=0;
	int result;
	LinkList Result;
	Node *current=head1;
	int temp=0;
	
	while(current!=NULL)
	{
		num1+=(current->data)*pow(10,temp);
		current=current->next;
		temp++;
	}
	current=head2;
	temp=0;
	while(current!=NULL)
	{
		num2+=(current->data)*pow(10,temp);
		current=current->next;
		temp++;
	}
	result=num1+num2;
	while(result)
	{
		int data=result%10;
		Result.InsertHead(data);
		result/=10;
	}
	Result.Print();
}

int main()
{
	LinkList linklist1;
	linklist1.InsertHead(5);
	linklist1.tail=linklist1.head;
	linklist1.InsertHead(2);
	linklist1.InsertHead(3);
	linklist1.InsertHead(2);
	linklist1.Print();
}

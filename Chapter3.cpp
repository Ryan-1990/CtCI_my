#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int d):data(d),next(NULL){}
};

class Stack
{
public:
	Stack();
	~Stack();
	void push(int data);
	void pop();
	int peek();
	int min();
	bool isEmpty();
private:
	int size;
	Node *top;
	Node *min_top;
};

Stack::Stack()
{
	top=NULL;
	min_top=NULL;
	size=0;
}

Stack::~Stack()
{
	if(top!=NULL) delete top;
}

void Stack::push(int data)
{
	if(top==NULL)
	{
		min_top=new Node(data);	
	}
	else
	{
		if(data<=min_top->data) 
		{
			Node *min_node=new Node(data);
			min_node->next=min_top;
			min_top=min_node;
		}
	}
	Node *node=new Node(data);
	node->next=top;
	top=node;
	size++;
}

void Stack::pop()
{
	if(top==NULL) return;
	if(top->data==min_top->data)
	{
		min_top=min_top->next;
	}
	Node *temp=top;
	top=top->next;
	delete temp;
}

int Stack::peek()
{
	return top->data;
}

int Stack::min()
{
	if(min_top==NULL) return false;
	return min_top->data;
}

bool Stack::isEmpty()
{
	if(top==NULL) return true;
	else return false;
}

class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	void add(int data);
	void remove();
	int peek();
	bool isEmpty();
private:
	int size;
	Stack OldStack;
	Stack NewStack;
};

MyQueue::MyQueue()
{	
	/*OldStack.push(1);
	OldStack.pop();
	NewStack.push(1);
	NewStack.pop();*/
	size=0;
}

MyQueue::~MyQueue()
{
	
}

void MyQueue::add(int data)
{
	NewStack.push(data);
	size++;
}

void MyQueue::remove()
{
	if(size==0) return;
	if(OldStack.isEmpty())
	{
		while(NewStack.isEmpty()==0)
		{
			OldStack.push(NewStack.peek());
			NewStack.pop();
		}
	}
	OldStack.pop();
	size--;
}

int MyQueue::peek()
{
	if(size==0) return 0;
	if(OldStack.isEmpty())
	{
		while(NewStack.isEmpty()==0)
		{
			OldStack.push(NewStack.peek());
			NewStack.pop();
		}
	}
	return OldStack.peek();
}

bool MyQueue::isEmpty()
{
	if(size) return false;
	else return true;
}

void SortStack(Stack stack)
{
	Stack new_stack;
	int temp;
	while(!stack.isEmpty())
	{
		temp=stack.peek();
		stack.pop();
		while(!new_stack.isEmpty()&&new_stack.peek()>temp)
		{
			stack.push(new_stack.peek());
			new_stack.pop();
		}
		new_stack.push(temp);
	}
	while(!new_stack.isEmpty())
	{
		cout<<new_stack.peek()<<" ";
		new_stack.pop();
	}
	cout<<endl;
}

int main()
{
	/*
	//Solution to 3.2
	Stack st;
	st.push(3);
	st.push(2);
	st.push(1);
	st.push(1);
	st.push(2);
	st.push(3);

	cout<<st.peek()<<endl;
	cout<<"----------------"<<endl;
	cout<<st.min()<<endl;
	st.pop();
	cout<<"----------------"<<endl;
	cout<<st.peek()<<endl;
	cout<<"----------------"<<endl;
	cout<<st.min()<<endl;
	*/

	/*
	//Solution to 3.4
	MyQueue q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
	cout<<q.peek()<<endl;
	cout<<"----------------"<<endl;
	q.remove();
	cout<<q.peek()<<endl;
	cout<<"----------------"<<endl;
	q.remove();
	q.remove();
	q.add(5);
	q.add(6);
	//q.remove();
	cout<<q.peek()<<endl;
	cout<<"----------------"<<endl;
	*/

	///*
	//Solution to 3.5
	Stack st;
	st.push(2);
	st.push(1);
	st.push(3);
	st.push(5);
	st.push(4);
	SortStack(st);
	//*/
}

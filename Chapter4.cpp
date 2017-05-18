#include <iostream>

using namespace std;

struct TreeNode
{
	int data;
	
	TreeNode *left_child;
	TreeNode *right_child;
	TreeNode(int d):data(d){}
};

struct ListNode
{
	int data;
	ListNode *next;
	ListNode(int d):data(d),next(NULL){}
};

struct NodeStack
{
	TreeNode *root[100];
	int top;
};

class BinTree
{
public:
	BinTree();
	~BinTree();
	TreeNode *createMinBST(int array[],int start,int end,int depth);
	void preOrder(TreeNode *t);

	TreeNode *root;
	int depth;
};

BinTree::BinTree()
{
	root=NULL;
	depth=0;
}

BinTree::~BinTree()
{
	
}

TreeNode * BinTree::createMinBST(int array[],int start,int end,int deep)
{
	if(start>end) return NULL;
	int mid=(start+end)/2;
	TreeNode *node=new TreeNode(array[mid]);
	depth=deep;
	if(depth==0) root=node;
	cout<<node->data<<" ";
	//cout<<"node"<<" ";
	node->left_child=createMinBST(array,start,mid-1,deep+1);
	//cout<<"left"<<" ";
	node->right_child=createMinBST(array,mid+1,end,deep+1);
	//cout<<"right"<<" ";
	return node;
}

void BinTree::preOrder(TreeNode *t)
{
	if(t==NULL) return;
	cout<<t->data<<" ";
	preOrder(t->left_child);
	preOrder(t->right_child);
}

class LinkList
{
public:
	LinkList();
	~LinkList();
	void insert(int data);
	void print();

	ListNode *head;
	int length;
};

LinkList::LinkList()
{
	head=NULL;
	length=0;
}

LinkList::~LinkList()
{
	
}

void LinkList::insert(int data)
{
	ListNode *node=new ListNode(data);
	node->next=head;
	head=node;
	length++;
}

void LinkList::print()
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

class ArrayLinkList
{
public:
	ArrayLinkList();
	~ArrayLinkList();
	int GetSize();
	LinkList GetNode(int index);
	void AddNode(LinkList list);

	int size;
	LinkList ArrayNode[10];
};

ArrayLinkList::ArrayLinkList()
{
	size=0;
}

ArrayLinkList::~ArrayLinkList()
{

}

int ArrayLinkList::GetSize()
{
	return size;
}

LinkList ArrayLinkList::GetNode(int index)
{
	return ArrayNode[index];
}

void ArrayLinkList::AddNode(LinkList list)
{
	//cout<<list.head<<" ";
	ArrayNode[size]=list;
	size++;
}

void createLevelLinkList(TreeNode *node,ArrayLinkList &array_list,int level)
{
	if(node==NULL) return;
	LinkList list;
	if(array_list.GetSize()==level) 
	{
		list.insert(node->data);
		array_list.AddNode(list);
		//cout<<list.head<<endl;
	}
	else
	{
		list.head=array_list.GetNode(level).head;
		//cout<<list.head<<endl;
		list.insert(node->data);
		array_list.ArrayNode[level]=list;
	}
	createLevelLinkList(node->left_child,array_list,level+1);
	createLevelLinkList(node->right_child,array_list,level+1);
}

void print(ArrayLinkList array_List)
{
	for(int i=0;i<array_List.GetSize();i++)
	{
		LinkList temp=array_List.GetNode(i);
		temp.print();
		cout<<endl;
	}
}

void push(NodeStack *s,TreeNode *root)
{
	s->root[s->top]=root;
	s->top++;
}

TreeNode *pop(NodeStack *s)
{
	s->top--;
	return s->root[s->top+1];
}

void preorder(TreeNode *t)
{
	if(t==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	else
	{
		NodeStack *s;
		s->top=0;
		while(t!=NULL||s->top>0)
		{
			while(t!=NULL)
			{
				cout<<t->data<<" ";
				push(s,t);
				t=t->left_child;
			}
			t=pop(s);
			t=t->right_child;
		}
	cout<<endl;
	}
}

int main()
{
	int data_size;
	cout<<"Input array size: ";
	cin>>data_size;
	int data[data_size];
	cout<<endl;
	for(int i=0;i<data_size;i++)
		data[i]=i+1;

	BinTree bt;
	bt.createMinBST(data,0,data_size-1,0);
	cout<<endl;
	//cout<<bt.root->right_child->right_child->data<<endl;
	
	bt.preOrder(bt.root);
	cout<<endl<<"depth is : "<<bt.depth+1<<endl;

	ArrayLinkList arr_list;
	createLevelLinkList(bt.root,arr_list,0);
	print(arr_list);
	
	//preorder(bt.root);
	return 0;
}

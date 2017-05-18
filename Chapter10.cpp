#include <iostream>

using namespace std;

void merge(int *A,int *B,int a,int b)
{
    int indexa=a-1;
    int indexb=b-1;
    for(int i=a+b-1;i>-1;i--)
    {
        if(A[indexa]>B[indexb])
        {
            A[i]=A[indexa];
            indexa--;
        }   
        else
        {
            A[i]=B[indexb];
            indexb--;
        }
        cout<<A[i]<<",";
    }
}

int binSearch(int *Data,int x,int left,int right)
{
	if(left>=right||x<Data[left]||x>Data[right]) return -1;
	int mid=(left+right)/2;
	if(x==Data[mid]) return mid;
	else if(x<Data[mid]) return binSearch(Data,x,left,mid-1);
	else return binSearch(Data,x,mid+1,right);
}

class TreeNode
{
public:
	int data;
	int left_size;
    TreeNode *left;
    TreeNode *right;
public:
	TreeNode()
	{
        left_size=0;
        left=NULL;
        right=NULL;
	}
	TreeNode(int d)
	{
		data=d;
        left_size=0;
        left=NULL;
        right=NULL;
	}
};

class BinTree
{
public:
	TreeNode *root;
public:	
	BinTree()
	{
		root=NULL;
	}
	BinTree(int d)
	{
		root=new TreeNode(d);
	}
	void add(int x,TreeNode *node)
	{
		if(node==NULL)
        {
            node=new TreeNode(x);
            if(root==NULL) root=node;
        }
        else if(x<=node->data)
		{
			if(node->left==NULL) node->left=new TreeNode(x);
            else add(x,node->left);
            node->left_size++;
		}
        else
		{
			if(node->right==NULL) node->right=new TreeNode(x);
            else add(x,node->right);
		}
	}
    
    void print(TreeNode *node)
    {
        if(node==NULL) return;
        else
        {
            print(node->left);
            cout<<node->data<<" ";
            print(node->right);
        }  
        cout<<endl;        
    }
};

void track(int x,BinTree &bst)
{
    bst.add(x,bst.root);
}

int getRank(int x,BinTree *root)
{
	//if(x==root->data) return root.left_size;
	//else if(x<root->data) return root.left_size;
	return 0;
}

int main()
{
    /*
	int A[10]={1,3,5,7,9};
    int B[4]={2,3,5,6};
    merge(A,B,5,4);
	
	int A[10];
	for(int i=0;i<10;i++)
		A[i]=i;
    cout<<binSearch(A,1,0,9);
	*/
	BinTree bst;
    int data[9]={5,1,4,4,5,9,7,13,3};
    for(int i=0;i<9;i++)
        track(data[i],bst);
    bst.print(bst.root);
    cout<<endl;
    return 0;
}

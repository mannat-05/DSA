#include <stdio.h>
#include <stdlib.h>
struct Bstnode 
{
	int data;
	struct Bstnode* left;
	struct Bstnode* right;
};

struct Bstnode* GetNewNode(int data)
{
	struct Bstnode* newnode = (struct Bstnode*)malloc(sizeof(struct Bstnode));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

struct Bstnode* InsertNode(struct Bstnode*root,int data)
{
	if (root==NULL)
	{
		root=GetNewNode(data); 	
	}
	else if (data<=root->data)
	{
		root->left=InsertNode(root->left,data);
	}
	else
	{
		root->right=InsertNode(root->right,data);
	}
	return root;
}

bool IsLesser(struct Bstnode*root,int value)
{
	if (root==NULL)
		return  true;
	if (root->data <=value && IsLesser(root->left,value) && IsLesser(root->right,value))
		return true;
	else
		return false;
}

bool IsGreater(struct Bstnode*root,int value)
{
	if (root==NULL)
		return  true;
	if (root->data >=value && IsGreater(root->left,value) && IsGreater(root->right,value))
		return true;
	else
		return false;
}

bool Isvalid(struct Bstnode*root)
{
	if (root==NULL)
		return true;
	if (IsLesser(root->left,root->data) && IsGreater(root->right,root->data) && Isvalid(root->left) && Isvalid(root->right))
		return true;
	else
		return true;
}

main()
{
	int element;
	struct Bstnode* root=NULL;
	root=InsertNode(root,15);	//Here we are building the link
	root=InsertNode(root,10);
	root=InsertNode(root,101);
	root=InsertNode(root,45);
	root=InsertNode(root,90);
	printf("%d",Isvalid(root));
}

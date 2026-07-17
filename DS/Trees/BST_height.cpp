#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int height (struct Bstnode*root)
{
	if (root==NULL)
		return -1;
	int lh=height(root->left);
	int rh=height(root->right);
	return fmax(lh,rh)+1;
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
	printf("The heigght of the tree is:%d",height(root));  
}

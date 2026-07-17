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

bool search(struct Bstnode*root,int data)
{
	if (root==NULL)
		return false;
	if (root->data==data)
		return true;
	else if (root->data>=data)
		return search(root->left,data);
	else
		return search(root->right,data);
}

main()
{
	int element;
	struct Bstnode* root=NULL;	//Creating an empty tree
	root=InsertNode(root,15);	//Here we are building the link
	root=InsertNode(root,10);
	root=InsertNode(root,101);
	root=InsertNode(root,45);
	root=InsertNode(root,90);
	printf("Enter the search element:");
	scanf("%d",&element);
	if(search(root,element))
		printf("Search element is found");
	else
		printf("Search element is not found");
}

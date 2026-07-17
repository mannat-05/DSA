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

int Findmin(struct Bstnode* root)
{
	if (root==NULL)
	{
		printf("The tree is empty");
		return -1;
	}
	while (root->left!=NULL)
	{
		root=root->left;
	}
	return root->data;
}

int Findmax(struct Bstnode* root)
{
	if (root==NULL)
	{
		printf("The tree is empty");
		return -1;
	}
	else if (root->right==NULL)
		return root->data;
		
	return Findmax(root->right);
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
	printf("Minimum element in the BST is:%d\n",Findmin(root));
	printf("Minimum element in the BST is:%d",Findmax(root));
}

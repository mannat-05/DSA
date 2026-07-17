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

void Preorder(struct Bstnode* root)
{
	if (root==NULL)
		return;
	printf("%d ",root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(struct Bstnode* root)
{
	if (root==NULL)
		return;
	Inorder(root->left);
	printf("%d ",root->data);
	Inorder(root->right);
}

void Postorder(struct Bstnode* root)
{
	if (root==NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ",root->data);
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
	printf("Preorder traversal:");
	Preorder(root);
	printf("\n");
	printf("Inorder traversal:");
	Inorder(root);
	printf("\n");
	printf("Postorder traversal:");
	Postorder(root);
	printf("\n");
}

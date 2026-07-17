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

struct Bstnode* Findmin(struct Bstnode* root)
{
	if (root==NULL)
	{
		printf("The tree is empty");
		return root;
	}
	while (root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

struct Bstnode* Findmax(struct Bstnode* root)
{
	if (root==NULL)
	{
		printf("The tree is empty");
		return root;
	}
	else if (root->right==NULL)
		return root;
		
	return Findmax(root->right);
}

struct Bstnode* del(struct Bstnode*root,int data)
{
	if (root==NULL)
		return root;
	else if (data<root->data)
		root->left=del(root->left,data);
	else if (data>root->data)
		root->right=del(root->right,data);
	else
	{
		//No child
		if (root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		//1 Child
		else if (root->right==NULL)
		{
			struct Bstnode* temp=root;
			root=root->left;
			delete temp;	
		}
		else if (root->left==NULL)
		{
			struct Bstnode* temp=root;
			root=root->right;
			delete temp;
		}
		//2 Child
		else
		{
			struct Bstnode* temp=Findmin(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
		}
		return root;
	}
	
}

void Inorder(struct Bstnode* root)
{
	if (root==NULL)
		return;
	Inorder(root->left);
	printf("%d ",root->data);
	Inorder(root->right);
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
	printf("Enter the element to be deleted:");
	scanf("%d",&element);
	root=del(root,element);
	Inorder(root);
}

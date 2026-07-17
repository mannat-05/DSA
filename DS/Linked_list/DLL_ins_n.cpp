#include <stdio.h>
#include <stdlib.h>

struct Node		//Node structure for doubly linked list
{
	struct Node *prev;
	int data;
	struct Node *next;
};
struct Node* head;

struct Node* getnode(int x)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
}

void Insend(int x)
{
	struct Node *newnode=getnode(x);
	struct Node *prevnode=head;
	if (head==NULL)	//if list is empty
	{
		head=newnode;
		return;
	}
	while (prevnode->next!=NULL)
	{
		prevnode=prevnode->next;	//Traversing till last node
	}
	prevnode->next=newnode;
	newnode->prev=prevnode;	
}

void ins_n(int x,int n)
{
	struct Node *newnode=getnode(x);
	struct Node *prevnode=head;
	if (n==1)
	{
		newnode->next=head;
		head=newnode;
	}
	for (int i=0;i<n-2;i++)
		prevnode=prevnode->next;
	
	newnode->next=prevnode->next;	
	prevnode->next=newnode;
	newnode->next->prev=newnode;
}

void Print()
{
	struct Node *temp=head;
	printf("List elements are:");
	while (temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

main()
{
	head=NULL;
	Insend(8);
	Insend(2);
	Insend(100);
	ins_n(5,3);
	ins_n(1,4);
	Print();
}

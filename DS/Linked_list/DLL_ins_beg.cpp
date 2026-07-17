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
void Insbeg(int x)
{
	struct Node *newnode=getnode(x);
	if (head==NULL)	//if list is empty
	{
		head=newnode;
		return;
	}
	newnode->next=head;
	newnode->next->prev=newnode;
	head=newnode;
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
void revPrint()
{
	struct Node *temp=head;
	while (temp->next!=NULL)
	{
		temp=temp->next;	
	}
	printf("List elements in reverse order are:");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
}

main()
{
	head=NULL;
	Insbeg(8);
	Insbeg(2);
	Insbeg(100);
	Print();
	revPrint();
}

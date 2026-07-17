#include <stdio.h>
#include <stdlib.h>

//Using recursion.

struct Node
{
	int data;
	struct Node*next;
};
struct Node* head;


void Insert(int element,int n)
{
	struct Node*temp1=(Node*)malloc(sizeof(struct Node));
	temp1->data=element;
	temp1->next=NULL;
	if (n==1)
	{
		temp1->next=head;
		head=temp1;
		return;
	}
	Node*temp2=head;
	for (int i=0;i<n-2;i++)	//For traversng till (n-1)th node
	{
		temp2=temp2->next;
	}
	temp1->next=temp2->next;	//Next node pointer
	temp2->next=temp1;
}

void Reverse(struct Node*p)
{
	if (p==NULL)
		return;
	Reverse(p->next);
	printf("%d ",p->data);		//Printing list using recursion
}


void Print(struct Node*p)
{
	if (p==NULL)
		return;
	printf("%d ",p->data);
	Print(p->next);		//Reversing list using recursion
}

int main()
{
	head=NULL;
	Insert(4,1);
	Insert(3,2);
	Insert(9,1);
	Insert(1,3);
	printf("List elements are:");
	Print(head);
	printf("\n");
	printf("Reversed List elements are:");
	Reverse(head);
}

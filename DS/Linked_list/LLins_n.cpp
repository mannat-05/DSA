#include <stdio.h>
#include <stdlib.h>
//Linked List
struct node	//Creating node
{
	int data;
	struct node*next;
};
struct node*head;
void Insert(int x,int n)
{
	node*temp1=(node*)malloc(sizeof(struct node));
	temp1->data=x;
	temp1->next=NULL;
	if (n==1)	//if only one node is present
	{
		temp1->next=head;
		head=temp1;
		return;	//Returns nothing and comes out of the function
	}
	node*temp2=head;
	for (int i=0;i< n-2;i++)	//For traversing till (n-1)th node
	{
		temp2=temp2->next;		//Previous node pointer
	}
		temp1->next=temp2->next;	//Used for fitting the node into the list 
		temp2->next=temp1;
}
void Print()
{
	node*temp=head;
	printf("List elements are: ");
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
	Insert(4,1);
	Insert(3,2);
	Insert(9,1);
	Insert(1,3);
	Print();
}


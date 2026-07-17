#include <stdio.h>
#include <stdlib.h>
//Linked List
struct node
{
	int data;
	struct node*next;
};
struct node*head;

void Insert (int x)
{
	node*temp=(node*)malloc(sizeof (struct node));//pointer variable used to point the most recent node.
	temp->data=x;
	temp->next=head;
	head=temp; //head always contains the address of the head  node i.e. last elemnet added in the list.
}
void sort()
{
	struct node* temp=head;
	struct node* next=temp->next;
	while (next!=NULL)
	{
		if (temp->data >= next->data)
		{
			temp->next=	
	
		else 
			temp=temp->next;
	}

}

void print ()
{
	struct node*temp=head;
	printf("List is: ");
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
	Insert(4);
	Insert(3);
	Insert(9);
	Insert(1);
	print();
	sort();
	print();
}


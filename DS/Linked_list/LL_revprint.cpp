#include <stdio.h>
#include <stdlib.h>
//Linked List
struct node
{
	int data;
	struct node*next;
};
struct node*head;

void insert (int x)
{
	node*temp=(node*)malloc(sizeof (struct node));//pointer variable used to point the most recent node.
	temp->data=x;
	temp->next=head;
	head=temp; //head always contains the address of the head  node i.e. last elemnet added in the list.
}
void print ()
{
	struct node*temp=head;
	printf("List is: ");
	while (temp->next!=NULL)
	{
		temp=temp->next;
	}
	printf("%d ",temp->data);
	printf("\n");
}

main()
{
	head=NULL;
	int i,n,x;
	printf("Enter the  number of elements:");
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("Enter the numbers:");
		scanf("%d",&x);
		insert(x);
		print();
	}
}


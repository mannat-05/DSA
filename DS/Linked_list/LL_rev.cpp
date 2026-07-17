#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node*next;
};

struct Node* head;
void reverse()
{
	struct Node *current,*prev,*next;
	current=head;
	prev=NULL;		//pointing the current node
	while (current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}

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

void Print()
{
	Node*temp=head;
	printf("List elements are:");
	while (temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	head=NULL;
	Insert(4,1);
	Insert(3,2);
	Insert(9,1);
	Insert(1,3);
	Print();
	reverse();
	Print();
}

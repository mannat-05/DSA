#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node*next;
};
struct Node* head;
void Insert(int x,int n)
{
	Node*temp1=(Node*)malloc(sizeof(struct Node));
	temp1->data=x;
	temp1->next=NULL;
	if (n==1)	
	{
		temp1->next=head;
		head=temp1;
		return;	//Returns nothing and comes out of the function
	}
	Node*temp2=head;
	for (int i=0;i< n-2;i++)	
	{
		temp2=temp2->next;		//Previous node pointer
	}
		temp1->next=temp2->next;	
		temp2->next=temp1;
}

void Delete(int n)
{
	int count=0;
    struct Node* temp1=head;
    while (temp1!=NULL)
    {
        temp1=temp1->next;
        count++;
    }
    temp1=head;
    int l=count-n+1;
//    printf("%d",count);
	if (l==1)
	{
		head=head->next;
		free(temp1);
		return;
	}
	else
	{
		for (int i=0;i<l-2;i++)
		{
			temp1=temp1->next;			//traversing till (n-1)th node
		}
		struct Node*temp2=temp1->next;	//nth node
		temp1->next=temp2->next;		//storing the address of (n+1)th node
		free(temp2);					//freeing the memory of nth node
	}

}

void Print()
{
	Node*temp=head;
	printf("List elements are: ");
	while (temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	int n;
	head=NULL;
	Insert(4,1);
	Insert(3,2);
	Insert(9,1);
	Insert(1,3);
	Print();
	printf("Enter the position at which element is to be deleted from end:");
	scanf("%d",&n);
	Delete(n);
	Print();
}


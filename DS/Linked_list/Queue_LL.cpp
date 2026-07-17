#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct node 
{   //Structure to declare stack and node
    int data;
    struct node *next;
} node;

node* head = NULL;		//Declaring the head element as global

node* getnode(int x) 
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void enqueue(int x) 
{
    node* newnode = getnode(x);
    if (head == NULL) 
	{
        head = newnode;
        return;
    } 
	else 
	{
        node* temp = head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void dequeue() 
{
    if (head == NULL) 	//No node condition
	{
        printf("Queue underflow\n");
        return;
    }
    if (head->next == NULL) //Only one node is present
	{
        head = NULL;
    } 
	else 
	{
		node*temp=head;
		head=temp->next;
		free(temp);
	}
}

void rear() 
{
    if (head == NULL) 
	{
        printf("Queue underflow\n");
        return;
    }
    node* temp = head;
    while (temp->next != NULL) 
	{
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

void display() 
{
    if (head == NULL) 
	{
        printf("Queue is empty\n");
        return;
    }
    node* temp = head;
    printf("Queue elements are: ");
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
	int c,x;
	while (true)
	{
		printf("Menu:\n1.Enqueue\n2.Dequeue\n3.Rear\n4.Display\n5.Exit\n");
		scanf("%d",&c);
		switch (c)
		{
			case 1:
				{
					printf("Enter the data to be enqueued:");
					scanf("%d",&x);
					enqueue(x);
					break;
				}
			case 2:
				{
					dequeue();
					break;
				}
			case 3:
				{
					rear();
					break;
				}
			case 4:
				{
					display();
					break;
				}
			case 5:
				{
					exit(0);
				}
		}
	}
}


#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct node 
{   //Structure to declare stack and node
    int data;
    struct node *next;
    struct node *prev;
} node;

node* head = NULL;		//Declaring the head element as global

node* getnode(int x) 
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->prev= NULL;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void ins_rear(int x) 
{
   	node *newnode=getnode(x);
	node *prevnode=head;
	if (head==NULL)				//if list is empty
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

void ins_front(int x)
{
	node* newnode=getnode(x);
	node *currnode=head;
	if (head==NULL)				//if list is empty
	{
		head=newnode;
		return;
	}
	currnode->prev=newnode;
	head=newnode;
	newnode->next=currnode;
}

void del_front() 
{
	node*temp=head;
    if (head == NULL) 	//No node condition
	{
        printf("Queue underflow\n");
        return;
    }
    else if (head->next == NULL) //Only one node is present
	{
		temp=head;
        head=NULL;
        free(temp);
    } 
	else 
	{
		temp=head;
		head=temp->next;
		temp->next->prev=NULL;
		free(temp);
	}
}

void del_rear()
{
	node* temp=head;
	if (head == NULL) 		//No node condition
	{
        printf("Queue underflow\n");
        return;
    } 
    else if (head->next == NULL) //Only one node is present
	{
        temp=head;
        head=NULL;
        free(temp);
    } 
    else 
    {
    	while (temp->next!=NULL)
    	{
    		temp=temp->next;
		}
		temp->prev->next=NULL;
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

void front()
{
	if (head == NULL) 
	{
        printf("Queue underflow\n");
        return;
    }
    node* temp = head;
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
    ins_rear(51); display();
    ins_rear(82); display();
    ins_front(100);display();
    del_front();display();
    del_rear();display();
    ins_front(100);display();
    front();
    rear();
    del_rear();display();
    del_rear();display();
}

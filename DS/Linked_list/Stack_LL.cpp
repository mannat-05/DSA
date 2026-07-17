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

void push(int x) 
{
    node* newnode = getnode(x);
    if (head == NULL) 
	{
        head = newnode;
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

void pop() 
{
    if (head == NULL) 	//No node condition
	{
        printf("Stack underflow\n");
        return;
    }
    if (head->next == NULL) //Only one node is present
	{
        head = NULL;
    } 
	else 
	{
		node*temp=head; node*prev=head;
		while (temp->next->next!=NULL) 
		{
			temp=prev->next;
			prev=prev->next; 
		} 
		temp=prev->next;
		prev->next=NULL;
		free(temp);
	}
}

void peek() 
{
    if (head == NULL) 
	{
        printf("Stack underflow\n");
        return;
    }
    node* temp = head;
    while (temp->next != NULL) 
	{
        temp = temp->next;
    }
    printf("%d\n",temp->data);

void display() {
    if (head == NULL) 
	{
        printf("Stack is empty\n");
        return;
    }
    node* temp = head;
    printf("Stack elements are: ");
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    push(5); display();
    push(1); display();
    push(82);display();
    pop(); display();
    push(100); display();
    pop();display();
    peek();
    return 0;
}


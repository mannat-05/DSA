#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct node 
{   //Structure to declare stack and node
    char data;
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

char pop() 
{
	char t1,t2;
    if (head == NULL) 
	{
        printf("Stack underflow\n");
        return '\0';
    }
    if (head->next == NULL) //removing only one node of the list
	{
		t1=head->data;
        head = NULL;
        return t1;
    } 
	else 			//Deleting the last node
	{
		node*temp=head; node*prev=head;
		while (temp->next->next!=NULL) 
		{
			temp=prev->next;
			prev=prev->next; 
		} 
		temp=prev->next;
		prev->next=NULL;
		t2=temp->data;
		free(temp);
		return t2;
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
}

void display() 
{
    if (head == NULL) 
	{
        printf("Stack is empty\n");
        return;
    }
    node* temp = head;
    printf("Stack elements are: ");
    while (temp != NULL) 
	{
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

main()
{
	node* temp = head;
	char str[MAXSIZE],rev[MAXSIZE];
	printf("Enter the string to be reversed:");
	gets(str);
	int i=0,j=0;
	while (str[i]!=0)
	{
		push (str[i]);
		i++;
	}
	
	while (head!=NULL)
	{
		rev[j]=pop();
		j++;
	}
	rev[j]='\0';	//To declare it as a string
	printf("%s",rev);	
}

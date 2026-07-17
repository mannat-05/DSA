#include <stdio.h>
#include <stdlib.h>

// Node structure for circular doubly linked list
struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL; // Global head pointer

// Function to create a new node
struct Node *getnode(int x) 
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to insert at the beginning
void Insbeg(int x) 
{
    struct Node *newnode = getnode(x);
    if (head == NULL) { // If list is empty
        head = newnode;
        newnode->next = newnode; // Point to itself to make it circular
        newnode->prev = newnode; // Point to itself to make it circular
        return;
    } 
	else 
	{
        struct Node *tail = head->prev; // Find the tail node (last node)
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode; // Update head to new node
    }
}

// Function to print the list in forward order
void Print() 
{
    if (head == NULL) 
	{
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("List elements are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we return to the head
    printf("\n");
}

// Function to print the list in reverse order
void revPrint() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head->prev; // Start from the last node (tail)
    printf("List elements in reverse order are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev); // Stop when we return to the tail
    printf("\n");
}

int main() {
    head = NULL;
    Insbeg(8);
    Insbeg(2);
    Insbeg(100);
    Print();
    revPrint();
    return 0;
}


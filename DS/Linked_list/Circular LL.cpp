#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

// Function to insert a new node at the nth position
void Insert(int x, int n) 
{
    struct node *temp1 = (struct node *)malloc(sizeof(struct node));
    temp1->data = x;
    if (n == 1) 
	{  // Insert at the head
        if (head == NULL) 
		{
            head = temp1;
            temp1->next = head; // Make it circular
        } 
		else 
		{
            struct node *temp2 = head;
            while (temp2->next != head) 
			{ 							// Traverse to the last node
                temp2 = temp2->next;
            }
            temp1->next = head;
            head = temp1;
            temp2->next = head; // Update last node to point to the new head
        }
        return;
    }
    struct node *temp2 = head;
    for (int i = 0; i < n - 2; i++) 
	{ 								// Traverse till (n-1)th node
        temp2 = temp2->next;
    }
    temp1->next = temp2->next; // Insert the new node
    temp2->next = temp1;
}

// Function to delete the nth node
void Delete(int n) 
{
    if (head == NULL) 
	{
        printf("List is empty\n");
        return;
    }
    struct node *temp1 = head;
    if (n == 1) 
	{ 							 // Delete the head
        if (head->next == head) 
		{						 // If there's only one node
            head = NULL;
            free(temp1);
            return;
        }
        struct node *temp2 = head;
        while (temp2->next != head) 
		{ 							// Traverse to the last node
            temp2 = temp2->next;
        }
        head = temp1->next;
        temp2->next = head; 		// Update last node to point to the new head
        free(temp1);
        return;
    }
    for (int i = 0; i < n - 2; i++) 
	{ 									// Traverse till (n-1)th node
        temp1 = temp1->next;
    }
    struct node *temp2 = temp1->next; // nth node
    temp1->next = temp2->next;        // Update pointers to skip nth node
    free(temp2);                      // Free the memory
}

// Function to print all elements in the list
void Print() 
{
    if (head == NULL) 
	{
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    printf("List elements are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Traverse until we reach the head again
    printf("\n");
}

// Main function
int main() {
    int n;
    Insert(4, 1);
    Insert(3, 2);
    Insert(9, 1);
    Insert(1, 3);
    Print();
    printf("Enter the position at which element is to be deleted: ");
    scanf("%d", &n);
    Delete(n);
    Print();
    return 0;
}


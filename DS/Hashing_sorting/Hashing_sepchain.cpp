#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Node structure for chaining using linked list
struct Node 
{
    int key;
    struct Node* next;
};

// Hash table with linked lists
struct Node* hashTable[TABLE_SIZE] = {NULL};	//Initialising all the linked list with null address

// Hash function
int hashFunction(int key) 
{
    return key % TABLE_SIZE;
}

// Insert function using chaining
void insert(int key) 
{
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;  // Insert at the beginning
}

// Display function
void display() 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
	{
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp) 
		{
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");	//Determines the end of a linked list at a specified hash table index
    }
}
int main() 
{
    insert(21);
    insert(34);
    insert(19);
    insert(13);
    insert(56);
    insert(45);
    insert(44);  // Causes collision with 34 (same index in hashFunction)
    display();  // Show the hash table
    return 0;
}

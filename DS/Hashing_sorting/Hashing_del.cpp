#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int occupied;
    int deleted; // Marks if a slot has been deleted
} HashTable;

int hash(int key) 
{
    return key % TABLE_SIZE;
}

void insert(HashTable table[], int key) 
{
    int index = hash(key);
    int i = 0;
    int deletedIndex = -1; // Track the first deleted slot found
    while (table[index].occupied) 
	{
        if (table[index].deleted && deletedIndex == -1) 
		{
            deletedIndex = index;  // Store the first deleted slot found
        }
        i++;
        index=(index + i)%TABLE_SIZE;
        if (i >= TABLE_SIZE) 
		{
            printf("Table is full, cannot insert key %d\n", key);
            return;
        }
    }

    if (deletedIndex != -1) 
	{
        index = deletedIndex;  // Insert in the first available deleted slot
    }
    table[index].key = key;
    table[index].occupied = 1;
    table[index].deleted = 0; // Reset deleted flag
    printf("Inserted key %d at index %d.\n", key, index);
}

void removeKey(HashTable table[], int key) 
{
    int index = hash(key);
    int i = 0;
    while (table[index].occupied) 
	{
        if (table[index].key == key && !table[index].deleted) 
		{
            table[index].deleted = 1; // Mark as deleted
            printf("Removed key %d from index %d.\n", key, index);
            return;
        }
        i++;
        index = (index + i)%TABLE_SIZE;
        if (i >= TABLE_SIZE) 
		{
            break;
        }
    }
    printf("Key %d not found in hash table.\n", key);
}

void display(HashTable table[]) 
{
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].occupied && !table[i].deleted)
            printf("Index %d: Key %d\n", i, table[i].key);
        else if (table[i].deleted)
            printf("Index %d: DELETED (Available for reuse)\n", i);
        else
            printf("Index %d: EMPTY\n", i);
    }
    printf("\n");
}

int main() 
{
    HashTable table[TABLE_SIZE] = {0};
    insert(table, 15);
    insert(table, 25);
    insert(table, 35);
    display(table);
    removeKey(table, 25);
    removeKey(table, 15);
    display(table);
    insert(table, 45); // Should reuse deleted slot
    display(table);
    return 0;
}

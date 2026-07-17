#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
//Used to specify the type pf probing
typedef enum { LINEAR, QUADRATIC, DOUBLE_HASHING } ProbingType;

//Table structure storing key value pairs
typedef struct {
    int key;
    int occupied;
} HashTable;

//Main hash function
int hash(int key) 
{
    return key % TABLE_SIZE;
}
//Also during probing all the key for probing and the table size should be relatively prime

int secondHash(int key) 
{
    return 7 - (key % 7);  // Secondary hash function for double hashing
}

int resolveCollision(ProbingType type, int hashIndex, int i, int key) 
{
    switch (type) //Selecting the type of probing
	{
        case LINEAR:
            return (hashIndex + i) % TABLE_SIZE;
        case QUADRATIC:
            return (hashIndex + i * i) % TABLE_SIZE;
        case DOUBLE_HASHING:
            return (hashIndex + i * secondHash(key)) % TABLE_SIZE;
    }
    return hashIndex;
}

void insert(HashTable table[], int key, ProbingType type) {
    int index = hash(key);
    int i = 0;
    while (table[index].occupied) 
	{
        i++;
        index = resolveCollision(type, hash(key), i, key);
        if (i >= TABLE_SIZE) 
		{
            printf("Table is full, cannot insert key %d\n", key);
            return;
        }
    }
    //Inserting the value at the probed index.
    table[index].key = key;
    table[index].occupied = 1;	//if value is mapped at the given table index then it is occupied to indicate this we use this command
    printf("Inserted key %d at index %d using %s probing.\n", key, index,
           type == LINEAR ? "Linear" : type == QUADRATIC ? "Quadratic" : "Double Hashing");
}

void display(HashTable table[]) 
{
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
	{
        if (table[i].occupied)
            printf("Index %d: Key %d\n", i, table[i].key);
        else
            printf("Index %d: EMPTY\n", i);
    }
    printf("\n");
}

int main() {
    HashTable table[TABLE_SIZE] = {0};

    insert(table, 15, LINEAR);
    insert(table, 25, QUADRATIC);
    insert(table, 35, DOUBLE_HASHING);
    insert(table, 45, LINEAR);
    insert(table, 55, QUADRATIC);
    insert(table, 65, DOUBLE_HASHING);
    display(table);
    return 0;
}

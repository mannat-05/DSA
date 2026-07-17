#include <stdio.h>
#include <stdlib.h>

// Define a structure for BST node
struct Bstnode {
    int data;
    struct Bstnode* left;
    struct Bstnode* right;
};

// Define a structure for Queue node to store BST node addresses
typedef struct node {
    struct Bstnode* data;   // Store pointer to BST node
    struct node* next;
} node;
node* head = NULL;

// Function to create a new queue node
node* getnode(struct Bstnode* x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

struct Bstnode* invertTree(struct Bstnode* root) //Function to invert a Binary Tree.
{
    if (root==NULL)
        return NULL;
    struct Bstnode* temp=root->right;
    root->right=root->left;
    root->left=temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
    
// Function to enqueue a BST node address
void enqueue(struct Bstnode* x) {
    node* newnode = getnode(x);
    if (head == NULL) {
        head = newnode;
        return;
    } 
	else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to dequeue a BST node
void dequeue() {
    if (head == NULL) {
        printf("Queue underflow\n");
        return;
    }
    
    node* temp = head;
    head = temp->next;
    free(temp);
}

// Function to get the front BST node from the queue
struct Bstnode* front() {
    if (head == NULL) {
        return NULL;
    }
    return head->data;
}

// Function to create a new BST node
struct Bstnode* GetNewNode(int data) {
    struct Bstnode* newnode = (struct Bstnode*)malloc(sizeof(struct Bstnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node into the BST
struct Bstnode* InsertNode(struct Bstnode* root, int data) {
    if (root == NULL) {
        return GetNewNode(data);
    } 
	else if (data <= root->data) {
        root->left = InsertNode(root->left, data);
    } 
	else {
        root->right = InsertNode(root->right, data);
    }
    return root;
}

// Function to perform level-order traversal of BST
void level_order(struct Bstnode* root) {
    if (root == NULL)
        return;

    enqueue(root);  // Enqueue the root node

    while (head != NULL) //Until the queue is empty
	{
        struct Bstnode* current = front();
        printf("%d ", current->data);  // Print node data
        // Enqueue children if present
        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
        dequeue();  // Remove the processed node
    }
}

int main() {
    struct Bstnode* root = NULL;
    
    // Inserting nodes into BST
    root = InsertNode(root, 15);
    root = InsertNode(root, 10);
    root = InsertNode(root, 101);
    root = InsertNode(root, 45);
    root = InsertNode(root, 90);
	invertTree(root);	
    // Level-order traversal of BST
    printf("Level order traversal: ");	//Using Breadth-first search
    level_order(root);
    printf("\n");

    return 0;
}

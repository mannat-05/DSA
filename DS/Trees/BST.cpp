#include <stdio.h>
#include <stdlib.h>

// Structure for a node in BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Function for inserting nodes in a Tree 
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL) 
	{
        return createNode(value);
    }
    
    if (value < root->data) 
	{
        root->left = insert(root->left, value);
    }
	 else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

//Function for inorder traversal in BST    
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;	//Tree is empty
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

//Function for searching an element in a BST 
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() 
{
    struct Node* root = NULL;
    root = insert(root, 6);
    insert(root, 3);
    insert(root, 9);
    insert(root, 1);
    insert(root, 5);
    insert(root, 7);
    insert(root, 11);
    insert(root,19);
    insert(root,4);
    insert(root,10);
	
    printf("In-order Traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    int searchKey = 7;
    struct Node* searchResult = search(root, searchKey);
    if (searchResult != NULL) {
        printf("Element %d found in BST\n", searchKey);
    } else {
        printf("Element %d not found in BST\n", searchKey);
    }
    
    return 0;
}

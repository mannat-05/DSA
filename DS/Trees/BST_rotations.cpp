#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* newNode(int key) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Right Rotation (for left-heavy trees)
struct Node* rightRotate(struct Node* y) 
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    return x; // New root
}

// Left Rotation (for right-heavy trees)
struct Node* leftRotate(struct Node* x) 
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    return y; // New root
}

// Insert function (Rotations included)
struct Node* insert(struct Node* root, int key) 
{
    if (root == NULL) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // No duplicates allowed
    // Example: Always rotating right after insert (not realistic for AVL!)
    if (root->left) root = rightRotate(root);
    if (root->right) root = leftRotate(root);
    return root;
}

// Inorder traversal to check tree structure
void inorder(struct Node* root) 
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main() 
{
    struct Node* root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 201);
    root = insert(root, 52);
    printf("Inorder traversal after rotations: ");
    inorder(root);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node Structure
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = val;
    node->left = node->right = NULL;
    node->height = 1; // New node has height 1
    return node;
}

// Get height of a node
int getHeight(struct TreeNode* node) {
    return (node == NULL) ? 0 : node->height;
}

// Get balance factor
int getBalance(struct TreeNode* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right Rotation (RR)
struct TreeNode* rotateRight(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* temp = x->right;
    x->right = y;
    y->left = temp;
    
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Left Rotation (LL)
struct TreeNode* rotateLeft(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* temp = y->left;
    y->left = x;
    x->right = temp;

    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Insert into AVL Tree and balance
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (!root) return createNode(val);

    if (val < root->value)
        root->left = insert(root->left, val);
    else if (val > root->value)
        root->right = insert(root->right, val);
    else
        return root; // Duplicate values not allowed

    // Update height
    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Perform rotations if tree is unbalanced
    if (balance > 1 && val < root->left->value) // RR Rotation
        return rotateRight(root);
    if (balance < -1 && val > root->right->value) // LL Rotation
        return rotateLeft(root);
    if (balance > 1 && val > root->left->value) { // LR Rotation
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && val < root->right->value) { // RL Rotation
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// In-order traversal to print the tree
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); // Unbalanced, AVL will fix it

    printf("In-order traversal of balanced AVL tree: ");
    inorder(root);

    return 0;
}

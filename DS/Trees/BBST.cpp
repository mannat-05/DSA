 #include <stdio.h>
#include <stdlib.h>

struct TreeNode 
{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) 
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* InsertNode(struct TreeNode*root,int val)
{
	if (root==NULL)
	{
		root=createNode(val); 	
	}
	else if (val<=root->value)
	{
		root->left=InsertNode(root->left,val);
	}
	else
	{
		root->right=InsertNode(root->right,val);
	}
	return root;
}

// In-order traversal to collect node values in an array
void inorder(struct TreeNode* root, int arr[], int* index) 
{
    if (!root) return;
    inorder(root->left, arr, index);
    arr[(*index)++] = root->value;	//Sorteed array.
    inorder(root->right, arr, index);
}

// Recursive function to construct balanced BST
struct TreeNode* buildBalancedTree(int arr[], int start, int end) 
{
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    struct TreeNode* root = createNode(arr[mid]);
    root->left = buildBalancedTree(arr, start, mid - 1);
    root->right = buildBalancedTree(arr, mid + 1, end);
    return root;
}

// Function to balance an unbalanced binary tree
struct TreeNode* balanceTree(struct TreeNode* root, int n) 
{
    int* arr = (int*)malloc(n * sizeof(int));
    int index = 0;
    inorder(root, arr, &index);
    struct TreeNode* balancedRoot = buildBalancedTree(arr, 0, n - 1);
    free(arr); // Clean up memory
    return balancedRoot;
}

// Function to print in-order traversal
void printTree(struct TreeNode* root) 
{
    if (!root) return;
    printf("%d ", root->value);
    printTree(root->left);
    printTree(root->right);
}

int main() 
{
    struct TreeNode* root=NULL;
	root=InsertNode(root,10);
    root=InsertNode(root,5);
    root=InsertNode(root,2);
    root=InsertNode(root,1);  // Unbalanced tree

    printf("Original tree: ");
    printTree(root);

    int n = 4; // Number of nodes in the unbalanced tree
    root = balanceTree(root, n);

    printf("\nBalanced tree: ");
    printTree(root);

    return 0;
}

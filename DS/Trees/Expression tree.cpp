#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definition of a tree node
typedef struct Node 
{
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Stack structure for storing tree nodes
typedef struct Stack 
{
    Node* nodes[100]; // Maximum stack size
    int top;
} Stack;

// Function to create a new node
Node* createNode(char data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Stack operations
void initStack(Stack* stack) 
{
    stack->top = -1;
}

void push(Stack* stack, Node* node) 
{
    stack->nodes[++stack->top] = node;
}

Node* pop(Stack* stack) {
    return stack->nodes[stack->top--];
}

// Function to check if a character is an operator
int isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to build an expression tree from a prefix expression
Node* buildTree(char* prefix) 
{
    Stack stack;
    initStack(&stack);

    int length = strlen(prefix);
    
    // Iterate through the prefix expression in reverse order
    for (int i = length - 1; i >= 0; i--) 
	{
        if (isspace(prefix[i])) continue; // Skip spaces
        
        if (isOperator(prefix[i])) {
            // Create a new node for the operator
            Node* newNode = createNode(prefix[i]);
            
            // Pop two nodes and assign them as left and right children
            newNode->left = pop(&stack);
            newNode->right = pop(&stack);
            
            // Push the new subtree back onto the stack
            push(&stack, newNode);
        } else {
            // Push operand node onto the stack
            push(&stack, createNode(prefix[i]));
        }
    }

    // The last remaining node in the stack is the root of the expression tree
    return pop(&stack);
}

// Function for postorder traversal (to get postfix notation)
void postOrder(Node* root) 
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
}

int main() 
{
    // Example prefix expression
    char prefix[] = "* a + b * c + d e";

    // Building the expression tree
    Node* root = buildTree(prefix);

    // Printing the postfix expression
    printf("Postfix expression: ");
    postOrder(root);
    printf("\n");

    return 0;
}

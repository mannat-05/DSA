#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to convert a 2D matrix into a doubly linked list
Node*** convertToDLL(int matrix[][3], int rows, int cols) {
    Node*** nodes = (Node***)malloc(rows * sizeof(Node**));

    for (int i = 0; i < rows; i++) {
        nodes[i] = (Node**)malloc(cols * sizeof(Node*));
        for (int j = 0; j < cols; j++) {
            nodes[i][j] = createNode(matrix[i][j]);
        }
    }

    // Establish left and right pointers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1]; // Same row
            if (i > 0) nodes[i][j]->right = nodes[i - 1][j]; // Same column
        }
    }

    return nodes;
}

// Function to print the doubly linked list structure as a matrix
void printDLL(Node*** nodes, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", nodes[i][j]->data);
        }
        printf("\n");
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node*** dllMatrix = convertToDLL(matrix, 3, 3);

    // Print the doubly linked list as a matrix representation
    printDLL(dllMatrix, 3, 3);

    return 0;
}

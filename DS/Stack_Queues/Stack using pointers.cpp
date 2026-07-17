#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack
struct Stack 
n{
    int top;
    int maxSize;
    int* array;
};

// Function to create a stack of given max size
struct Stack* createStack(int size) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxSize = size;
    stack->top = -1;
    stack->array = (int*)malloc(stack->maxSize * sizeof(int));
    return stack;
}

// Push operation
void push(struct Stack* stack, int value) 
{
    if (stack->top == stack->maxSize - 1) 
	{
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// Pop operation
int pop(struct Stack* stack) 
{
    if (stack->top == -1) 
	{
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Peek operation
int peek(struct Stack* stack) 
{
    if (stack->top == -1) 
	{
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

// Display stack elements
void display(struct Stack* stack) 
{
    if (stack->top == -1) 
	{
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) 
	{
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() 
{
    struct Stack* myStack = createStack(5);
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    printf("Stack elements after push operations: ");
    display(myStack);
    printf("Top element using peek: %d\n", peek(myStack));
    pop(myStack);
    printf("Stack elements after pop operation: ");
    display(myStack);
    return 0;
}

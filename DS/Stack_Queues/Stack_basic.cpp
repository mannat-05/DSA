#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct stack 
{
    int top;
    int stack[MAXSIZE];
} Stack;

Stack s = {.top = -1};

void push(int x) 
{
    if (s.top == MAXSIZE - 1)
	{
        printf("Stack overflow\n");
        return;
    }
    s.stack[++s.top] = x;
}

void pop()
{
    if (s.top == -1) 
	{
        printf("Stack underflow\n");
        return;
    }
    --s.top;
}

void peek() 
{
    if (s.top == -1) 
	{
        printf("Stack underflow\n");
        return;
    }
    printf("%d\n", s.stack[s.top]);
}

void display() 
{
    printf("Stack elements are: ");
    for (int i = 0; i <= s.top; i++) 
	{
        printf("%d ", s.stack[i]);
    }
    printf("\n");
}

int main() 
{
	int n;
	printf("Enter any number:");
	scanf("%d",&n);
	push(n);display();
    push(5); display();
    push(1); display();
    pop(); display();
    push(100); display();
    return 0;
}


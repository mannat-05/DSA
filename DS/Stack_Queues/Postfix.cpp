#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Maximum size of stack

char stack[MAX];	//Stack globally declared
int top = -1;

void push(char element) 
{
    if (top==(MAX - 1))
	{
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=element;
}

char pop() 
{
    if (top == -1) 
	{
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek() 	//used for comparing operators
{
    if (top==-1) 
	{
        return '\0';
    }
    return stack[top];
}

int isOperand(char ch)
{
    return isalnum(ch);
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix,char* postfix) 
{
    int i=0,j=0;
    while (infix[i]!='\0')
	 {
        if (isOperand(infix[i])) 
		{
            postfix[j++]=infix[i];
        } 
		else if (infix[i]=='(') 
		{
            push(infix[i]);
        } 
		else if (infix[i]==')') 
		{
            while (peek() != '(' && peek() != '\0') 
			{
                postfix[j++] = pop();
            }
            pop(); // Pop the '(' from stack(removing the parentheses)
        } 
		else 
		{
            while (precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while (peek()!='\0') 
	{
        postfix[j++]=pop();	//popping the last elements remained in the stack
    }
    postfix[j]='\0';
}

int main() 
{
    char infix[MAX],postfix[MAX];
    printf("Enter an infix expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}


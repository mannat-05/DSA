#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct stack 
{
    int top;
    char stack[MAXSIZE];
} Stack;

Stack s = {.top=-1};

void push(char x) 
{
    if (s.top==MAXSIZE-1)
	{
        printf("Stack overflow\n");
        return;
    }
    s.stack[++s.top]=x;
}

char pop()
{
    return s.stack[s.top--];
}

void display() 
{
    printf("Stack elements are:");
    for (int i=0;i<=s.top;i++) 
	{
        printf("%c",s.stack[i]);
    }
    printf("\n");
}

char peek()
{
	return s.stack[s.top];
}

main()
{
	char str[MAXSIZE],temp,rev[MAXSIZE];
	printf("Enter the string to be reversed:");
	gets(str);
	int i=0,j=0;
	while (str[i]!=0)
	{
		push (str[i]);
		i++;
	}
	//printf("%c",peek());
	while (s.top!=-1)
	{
		rev[j]=pop();
		j++;
	}
	rev[j]='\0';
	printf("%s",rev);	
}

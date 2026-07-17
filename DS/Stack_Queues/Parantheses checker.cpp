#include <stdio.h>
#define max 100
int top=-1;
char stack[max];
void push(char element);
char pop();
char peek();
bool isValid(char* s)
{
    char temp;
	int i=0;
    while (s[i]!=0)
    {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[')
            push(s[i]);
        if (s[i]==')' || s[i]=='}' || s[i]==']')
        {
            temp=pop();
            if (s[i]==')')
            {
                if (temp!='(')
                    return false;
            }
             if (s[i]=='}')
            {
            	if (temp!='{')
                	return false;
            }
             if (s[i]==']')
            {
                if (temp!='[')
                    return false;
            }  
        }
        i++;
    }
    if (top==-1 )
        return true;
    else 
        return false;
}
void push(char element)
{
    stack[++top]=element;
}
char pop()
{
	if (top==-1)
		return 0;
	else
   		return stack[top--];
}
int main ()
{
	printf("Enter the expression:");
	char s[max];
	gets(s);
	if(isValid(s))
	{
		printf("Balanced");
	}
	else
	{
		printf("Not Balanced");
	}
}

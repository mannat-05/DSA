#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct queue 
{
    int front;
    int rear;
    int queue[MAXSIZE];
} q;

q s = {.front = -1,.rear = -1 };

bool isFull()
{
	if ((s.rear+1)%MAXSIZE==s.front)
		return true;
	else 
		return false;
}
bool isEmpty()
{
	if (s.front == -1 && s.rear==-1)
		return true;
	else
		return false;
}

void enqueue(int x) 
{
    if (isFull())
	{
        printf("Queue overflow\n");
        return;
    }
    else if (isEmpty())
    {
    	s.front=s.rear=0;
	}
	else
		s.rear=(s.rear+1)%MAXSIZE;
    s.queue[s.rear] = x;
}

void dequeue()
{
    if (isEmpty()) 
	{
        printf("Queue underflow\n");
        s.front=s.rear=0;
        return;
    }
    else if (s.front==s.rear)
    {
    	s.front=s.rear=-1;
	}
	else
    	s.front=(s.front+1)%MAXSIZE;
}

void front() 
{
    if (isEmpty()) 
	{
        printf("Queue underflow\n");
        return;
    }
    printf("%d\n", s.queue[s.front]);
}

void display() 
{
    printf("Queue elements are: ");
    int i = s.front;
    while (1) 
	{
        printf("%d ",s.queue[i]);
        if (i == s.rear) 		//breaks the loop at rear pointer if rear crosses the maxsize to other side modulus of i points it there
			break;
        i=(i + 1) % MAXSIZE;  //important line
    }
    printf("\n");

}

int main() 
{
	int n;
	printf("Enter any number:");
	scanf("%d",&n);
	enqueue(n);display();
    enqueue(5); display();
    enqueue(1); display();
    front();
    enqueue(5); display();
    enqueue(1); display();
    dequeue(); display();
    dequeue();display();
    enqueue(2);display();
    enqueue(3);display();
    return 0;
}




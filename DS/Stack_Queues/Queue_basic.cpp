#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct queue 
{
    int front;
    int rear;
    int queue[MAXSIZE];
} q;

q s = {.front = -1,.rear = -1 };

bool isFull()
{
	if (s.rear==MAXSIZE-1)
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
		s.rear++;
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
    	s.front++;
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
    for (int i=s.front; i<=s.rear; i++) 
	{
        printf("%d ", s.queue[i]);
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
    dequeue(); display();
    dequeue();display();
    enqueue(2);display();
    return 0;
}




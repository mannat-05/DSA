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
q r = {.front = -1,.rear = -1 };

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

int dequeue()
{
    if (isEmpty()) 
	{
        printf("Queue underflow\n");
        s.front=s.rear=0;
        return -1;
    }
    int value=s.queue[s.front];
    if (s.front==s.rear)
    {
    	s.front=s.rear=-1;
	}
	else
    	s.front++;
    return value;
}

bool isFullr()
{
	if (r.rear==MAXSIZE-1)
		return true;
	else 
		return false;
}
bool isEmptyr()
{
	if (r.front == -1 && r.rear==-1)
		return true;
	else
		return false;
}

void enqueuer(int x) 
{
    if (isFullr())
	{
        printf("Queue overflow\n");
        return;
    }
    else if (isEmptyr())
    {
    	r.front=r.rear=0;
	}
	else
		r.rear++;
    r.queue[r.rear] = x;
}

 void reverse()
{
	if (isEmpty())
		return;
	else
	{
		int data=dequeue();
		reverse();
		enqueuer(data);
	}
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

void displayr() 
{
    printf("Reversed Queue elements are: ");
    for (int i=r.front; i<=r.rear; i++) 
	{
        printf("%d ",r.queue[i]);
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
    enqueue(2);display();
    reverse();displayr();
    return 0;
}




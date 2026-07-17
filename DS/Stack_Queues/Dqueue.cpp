#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct queue 
{
    int front;
    int rear;
    int queue[MAXSIZE];
} queue;

queue s = {.front = -1,.rear = -1 };	//Initially the queue is empty so top=rear=-1

bool isFull()
{
	if (s.rear==MAXSIZE-1)
		return true;
	else 
		return false;
}
bool isEmpty()
{
	if (s.front == -1 || s.front>s.rear)
		return true;
	else
		return false;
}

void ins_rear(int x) 
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

void ins_front(int x)
{
	if (s.front==0)
	{
		printf("Queue overflow\n");
		return;
	}
	s.queue[--s.front]=x;
}

void del_front()
{
    if (isEmpty()) 
	{
        printf("Queue underflow\n");
        s.front=s.rear=0;
        return;
    }
    s.front++;
}

void del_rear()
{
	if (s.rear<s.front)
	{
		printf("Queue underflow\n");
		s.front=s.rear=0;
		return;
	}
	s.rear--;
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

void rear()
{
	if (isEmpty())
	{
		printf("Queue underflow\n");
		return;
	}
	printf("%d\n",s.queue[s.rear]);
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
	ins_rear(n);display();
	ins_rear(1);display();
	ins_front(2);display();
	ins_rear(3);display();
	del_rear();display();
	del_front();display();
	ins_front(5);display();
	front();
	rear();
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the queue
int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty() 
{
    return front == -1;
}

int isFull() 
{
    return rear == MAX - 1;
}

void enqueue(int request) 
{
    if (isFull()) 
	{
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty()) 
	{
        front = 0;
    }
    queue[++rear]= request;
    printf("Request number %d has been added to the queue.\n",request);
}

int dequeue() 
{
    if (isEmpty()) 
	{
        printf("Queue Underflow\n");
        return -1;
    }
    int request=queue[front];
    if (front==rear) 
	{
        front=rear=-1; // Reset the queue when it becomes empty
    }
	else 
	{
        front++;
    }
    return request;
}

// Function to display the queue
void displayQueue() 
{
    if (isEmpty()) 
	{
        printf("The queue is empty.\n");
        return;
    }
    printf("Current Queue: ");
    for (int i=front;i<=rear;i++) 
	{
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, request;
    while (true) 
	{
        printf("\n1. Add Request\n2. Process Request\n3. Display Queue\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter the request number: ");
                scanf("%d", &request);
                enqueue(request);
                break;

            case 2:
                request = dequeue();
                if (request != -1) 
				{
                    printf("Processing request number %d\n", request);
                }
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


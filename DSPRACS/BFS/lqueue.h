#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int *arr;
	int front,rear,capacity;
}queue;

void init(queue *q,int x)
{
	q->capacity=x;
	q->front=-1;
	q->rear=-1;
	q->arr=malloc(sizeof(int)*x);
}

int isEmpty(queue *q)
{
	if(q->rear==q->front)
		return 1;
	else 
		return 0;
}
int isFull(queue *q)
{
	if(q->rear+1==q->capacity)
		return 1;
	else
		return 0;
}	
void enqueue(queue *q,int x)
{
	if(isFull(q))
		printf("\nQUEUE IS FULL\n");
	else
	{
		q->rear++;
		q->arr[q->rear]=x;
	}
}
int dequeue(queue *q)
{
	int x=-1;
	if(isEmpty(q))
		printf("\nQUEUE IS EMPTY\n");
	else
	{
		x=q->arr[q->front+1];
		q->front++;
	}
	return x;
}
void display(queue *q)
{
	int i;
	printf("CONTENTS OF QUEUE: \n");
	for(i=q->front+1;i<=q->rear;i++)
		printf("%d ",q->arr[i]);
	printf("\n");
}


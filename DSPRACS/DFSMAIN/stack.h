#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int elements[100];
	int size,top;
}Stack;
Stack *initialize(Stack *S);
void push(Stack *S, int x);
int pop(Stack *S);
// disp(Stack S);
//void size(Stack *S);
int isEmpty(Stack *S);
//int isFull(Stack S);
Stack *initialize(Stack *S)
{
	S=malloc(sizeof(Stack));
	S->size=100;
	S->top=-1;
	return S;
}

void push(Stack *S, int x)
{
	
	{
		S->top++;
		S->elements[S->top]=x;
	}
}

int pop(Stack *S)
{
	int x=S->elements[S->top];
	S->top--;
	return x;
}

int isEmpty(Stack *S)
{
	if(S->top==-1)
		return 1;
	else
		return 0;
}



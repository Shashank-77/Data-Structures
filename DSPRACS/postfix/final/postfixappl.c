#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Stackimpl.h"

void main()
{
	int y;
	Stack S=initialize(S);
	do
	{
		int ch,x;
		printf("Menu: \n1. Push.\n2. Pop.\n3. Display elements.\n4. Display Size.\n5. Check Empty.\n6. Check Full.\n Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				
				printf("\nEnter element: ");
				scanf("%d",&x);
				Push(&S,x);
				break;
			case 2:
				Pop(&S);
				break;
			case 3:
				display(&S);
				break; 
			case 4:
				dispSize(&S);
				break;
			case 5: 
				if(isEmpty(&S)==0)
					printf("\nThe stack is Empty !!!");
				else
					printf("\nThe stack is not Empty !!!");				
				break;		
			case 6:
				if(isFull(&S)==0)
					printf("\nThe stack is Full !!!");
				else
					printf("\nThe stack is not Full !!!");
	
		}
		printf("\nDo you wish to continue (1/0) ? ");
		scanf("%d",&y);

	}while(y==1);
}



#include "LQImpl.h"

void main(){
	Queue q;
	initialise(&q);

	int opt=0;
	char choice;
	do{
		printf("\nWassup? 1-enqueue 2-dequeue 3-display ");scanf("%d",&opt);

		if(opt==1){
			int x;
			printf("\nEnter value to enqueue ");scanf("%d",&x);
			enqueue(&q,x);
		}
		else if(opt==2){
			int x;
			x=dequeue(&q);
			printf("\n%d has been dequeued \n",x);
		}
		else if(opt==3)
			display(&q);
		else if(opt){
			printf("\nInvalid choice \n");
		}
		else;

		getchar();
		printf("\n Continue? y/n ");scanf("%c",&choice);
	}while(choice=='Y'||choice=='y');
}

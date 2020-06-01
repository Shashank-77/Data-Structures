#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Stackimpl.h"

void main()
{
	int y;
	Stack *S=initialize();
	do
	{
		int ch,x;
		char string[80];
		printf("Enter the expression: ");
		scanf(" %[^\n]",string);
		Stack *S=initialize();
		char Post[80];
		InftoPost(S,string,Post);
		printf("Post fix: %s",Post);
		int ans=evalPost(S,Post);		

		printf("\nThe answer is: %d",ans);
		printf("\nDo you wish to continue (1/0) ? ");
		scanf("%d",&y);

	}while(y==1);
}


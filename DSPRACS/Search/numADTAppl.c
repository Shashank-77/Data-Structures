#include<stdio.h>
#include<stdlib.h>
#include"search.h"

void main()
{
	numADT *N=init();
	int ch,a[10],x;
	
	do
	{
		printf("\nMenu:\n1.Insert\n2.Linear Search\n3.Binary Search\n4.Display\n5.Exit\nChoice: ");
		scanf("%d",&ch);
		int i;		
		switch(ch)
		{
			case 1:
				printf("Enter size of the array: ");
				scanf("%d",&x);
				for(i=0;i<x;i++)
					scanf("%d",&a[i]);
				insert(N,a,x);
				break;
			case 2:
				printf("Element: ");
				scanf("%d",&x);
				i=lSearch(N,x);				
				if(i!=-1)
					printf("\nElement found at position %d",i+1);
				else
					printf("\nElement not found");
				break;
			case 3:
				printf("Element: ");
				scanf("%d",&x);
				i=bSearch(N,x);				
				if(i!=-1)
					printf("\nElement found at position %d",i+1);
				else
					printf("\nElement not found");
				break;
			case 4:
				display(N);
			
		}		
	}while(ch!=5);	
	
}


/*
Output:
Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 1
Enter size of the array: 6
1 2 3 4 5 6

Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 2
Element: 3

Element found at position 3

Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 3
Element: 5

Element found at position 5

Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 1
Enter size of the array: 4
9 8 7 6

Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 3
Element: 7

Element found at position 8

Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 5

*/

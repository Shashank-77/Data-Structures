#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

void main()
{
	numADT *N=init();
	int ch,a[10],x;
	
	do
	{
		printf("\nMenu:\n1.Insert\n2.Selection sort\n3.Shell Sort\n4.Display\n5.Exit\nChoice: ");
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
				selSort(N);
				break;
			case 3:
				shellSort(N);
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
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 1
Enter size of the array: 5
12 5 8 7 9

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 4

Array elements are:
 12 5 8 7 9 

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 2

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 4

Array elements are:
 5 7 8 9 12 

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 1
Enter size of the array: 6
9 8 7 6 5 4

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 4

Array elements are:
 5 7 8 9 12 9 8 7 6 5 4 

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 3

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 4

Array elements are:
 4 5 5 6 7 7 8 8 9 9 12 

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 5

*/

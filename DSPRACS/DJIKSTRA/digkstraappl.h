#include "digkstraimpl.h"
void main()
{
	cityADT *c;
	c=malloc(sizeof(cityADT));

	
	int connects;
	char source[20],dest[20];
	char start[20];
	char path[500];
	//check if connection exists
	int ch;
	while(ch!=5)
	{
		printf("\n******MENU******\n1 - Create Graph\n2 - view graph\n3 - dikstra\n4 - Display Path\n5 - EXIT\nyour choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					create(c);
					break;
			case 2:
					disp(c);
					break;
			case 3:
					printf("Enter the source: ");
					scanf("%s",source);
					
					dikstralgo(c,findSource(c,source));
					break;

			case 4:
					printf("Enter the source: ");
					scanf("%s",start);
					printf("Enter the desitination: ");
					scanf("%s",dest);
					displayPath(c,findSource(c,start),findSource(c,dest));
					
					break;


\


		}
	}

	
	
}

/*

******MENU******
1 - Create Graph
2 - view graph
3 - dikstra
4 - Display Path
5 - EXIT
your choice: 1
Enter the number of cities: 3
Enter the number of connections: 3
Enter the source city: a
Enter the desination city: b
Enter the cost: 5
Enter the source city: a
Enter the desination city: c
Enter the cost: 10
Enter the source city: b
Enter the desination city: c
Enter the cost: 2

******MENU******
1 - Create Graph
2 - view graph
3 - dikstra
4 - Display Path
5 - EXIT
your choice: 3
Enter the source:3
Initial configuration:
v       k       d       p
1       0       0       0
2       0       5000    0
3       0       5000    0
Ater 1 is known
v       k       d       p
1       1       0       0
2       0       5000    0
3       0       5000    0
Ater 1 is known
v       k       d       p
1       1       0       0
2       0       5       1
3       0       5000    0
Ater 1 is known
v       k       d       p
1       1       0       0
2       0       5       1
3       0       10      1
Ater 2 is known
v       k       d       p
1       1       0       0
2       1       5       1
3       0       10      1
Ater 2 is known
v       k       d       p
1       1       0       0
2       1       5       1
3       0       10      1
Ater 2 is known
v       k       d       p
1       1       0       0
2       1       5       1
3       0       7       2
Ater 3 is known
v       k       d       p
1       1       0       0
2       1       5       1
3       1       7       2
Ater 3 is known
v       k       d       p
1       1       0       0
2       1       5       1
3       1       7       2
Ater 3 is known
v       k       d       p
1       1       0       0
2       1       5       1
3       1       7       2

******MENU******
1 - Create Graph
2 - view graph
3 - dikstra
4 - Display Path
5 - EXIT
your choice:4
Enter the source: a
Enter the desitination: c
 a b c
******MENU******
1 - Create Graph
2 - view graph
3 - dikstra
4 - Display Path
5 - EXIT
your choice:5
*/

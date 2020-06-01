#include "cityADTimpl.h"
void main()
{
	cityADT *c;
	c=malloc(sizeof(cityADT));

	
	int connects;
	char source[20],dest[20];
	char start[20];
	//check if connection exists
	int ch;
	while(ch!=5)
	{
		printf("\n******MENU******\n1 - Create Graph\n2 - view graph\n3 - Check if path exists\n4 - BFS\n5 - EXIT\nyour choice: ");
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
					printf("\nEnter the destination: ");
					scanf("%s",dest);
					connects=connect(c,source,dest);
					if(connects==1)
						printf("connection exists!\n");
					else
						printf("No connection!\n");
					break;
			case 4:
					printf("Enter starting point for bfs: ");
					scanf("%s",start);
					BFS(c,start);
					break;


		}
	}

	
	
}

/*OUTPUT


******MENU******
1 - Create Graph
2 - view graph
3 - Check if path exists
4 - BFS
5 - EXIT
your choice: 1
Enter the number of cities: 5
Enter the number of connections: 8
Enter the source city: chennai
Enter the desination city: madurai
Enter the source city: chennai
Enter the desination city: trichy
Enter the source city: salem
Enter the desination city: ooty
Enter the source city: salem
Enter the desination city: trichy
Enter the source city: salem
Enter the desination city: chennai
Enter the source city: trichy
Enter the desination city: salem
Enter the source city: trichy
Enter the desination city: madurai
Enter the source city: ooty
Enter the desination city: madurai

******MENU******
1 - Create Graph
2 - view graph
3 - Check if path exists
4 - BFS
5 - EXIT
your choice: 2
The adjacency matrix is:
0 1 1 0 0
0 0 0 0 0
0 1 0 1 0
1 0 1 0 1
0 1 0 0 0
***DISPLAY****
There exitsts a path between chennai and madurai
There exitsts a path between chennai and trichy
There exitsts a path between trichy and madurai
There exitsts a path between trichy and salem
There exitsts a path between salem and chennai
There exitsts a path between salem and trichy
There exitsts a path between salem and ooty
There exitsts a path between ooty and madurai

******MENU******
1 - Create Graph
2 - view graph
3 - Check if path exists
4 - BFS
5 - EXIT
your choice: 3
Enter the source: madurai

Enter the destination: ooty
No connection!

******MENU******
1 - Create Graph
2 - view graph
3 - Check if path exists
4 - BFS
5 - EXIT
your choice: 3
Enter the source: chennai

Enter the destination: ooty
connection exists!

******MENU******
1 - Create Graph
2 - view graph
3 - Check if path exists
4 - BFS
5 - EXIT
your choice: 4
Enter starting point for bfs: chennai

chennai is visited

madurai is visited

trichy is visited

salem is visited

ooty is visited

******MENU******
1 - Create Graph
2 - view graph
3 - Check if path exists
4 - BFS
5 - EXIT
your choice: 5
*/
#include "dfsimpl.h"
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
		printf("\n******MENU******\n1 - Create Graph\n2 - view graph\n3 - find path\n4 - DFS\n5 - EXIT\nyour choice: ");
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
					DFSpath(c,findSource(c,source),findSource(c,dest));
					break;
			case 4:
					printf("Enter starting point for dfs: ");
					scanf("%s",start);
					DFS(c,findSource(c,start));
					break;


		}
	}

	
	
}

/*OUTPUT


******MENU******
1 - Create Graph
2 - view graph
3 - find path
4 - DFS
5 - EXIT
your choice: 1
Enter the number of cities: 7
Enter the number of connections: 10
Enter the source city: a
Enter the desination city: e
Enter the source city: a
Enter the desination city: f
Enter the source city: b
Enter the desination city: a
Enter the source city: b
Enter the desination city: c
Enter the source city: c
Enter the desination city: d
Enter the source city: c
Enter the desination city: a
Enter the source city: d
Enter the desination city: f
Enter the source city: e
Enter the desination city: d
Enter the source city: f
Enter the desination city: d
Enter the source city: g
Enter the desination city: f

******MENU******
1 - Create Graph
2 - view graph
3 - find path
4 - DFS
5 - EXIT
your choice: 2
The adjacency matrix is:
0 1 1 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 1 0
1 0 0 0 1 0 0
1 0 0 0 0 1 0
0 0 1 0 0 0 0
0 0 1 0 0 0 0
***DISPLAY****
There exitsts a path between a and e
There exitsts a path between a and f
There exitsts a path between e and d
There exitsts a path between f and d
There exitsts a path between b and a
There exitsts a path between b and c
There exitsts a path between c and a
There exitsts a path between c and d
There exitsts a path between d and f
There exitsts a path between g and f


******MENU******
1 - Create Graph
2 - view graph
3 - find path
4 - DFS
5 - EXIT
your choice: 4
Enter starting point for dfs: a
a f d e
******MENU******
1 - Create Graph
2 - view graph
3 - find path
4 - DFS
5 - EXIT
your choice: 4
Enter starting point for dfs: e
e d f
******MENU******
1 - Create Graph
2 - view graph
3 - find path
4 - DFS
5 - EXIT
your choice: 3
Enter the source: a

Enter the destination: g
No path

******MENU******
1 - Create Graph
2 - view graph
3 - find path
4 - DFS
5 - EXIT
your choice: 3
Enter the source: e

Enter the destination: b
No path

******MENU******
1 - Create Graph
2 - view graph
3 - find path
4 - DFS
5 - EXIT
your choice: 3
Enter the source: b

Enter the destination: f
b c d f
******MENU******
1 - Create Graph
2 - view graph
3 - find path
4 - DFS
5 - EXIT
your choice: 5
*/

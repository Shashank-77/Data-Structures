#include "cityADTif.h"
#include "lqueue.h"
void create(cityADT *C)
{
	int num;
	int x=0;
	int connections;
	int flag;
	int sindex,dindex;
	char source[20],dest[20];

	int i,j;
	printf("Enter the number of cities: ");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			C->mat[i][j]=0;
		}
	}
	C->num=num;

	printf("Enter the number of connections: ");
	scanf("%d",&connections);

	for(i=0;i<connections;i++)
	{
		flag=0;
		printf("Enter the source city: ");
		scanf("%s",source);
		printf("Enter the desination city: ");
		scanf("%s",dest);
		for(j=1;j<=x;j++)
		{
			if(strcmp(C->cityarr[j],source)==0)
			{
				flag=1;
				sindex=j;
				break;
			}
		}
		if(flag==0)
		{
			x++;
			strcpy(C->cityarr[x],source);
			sindex=x;

		}
		flag=0;
		for(j=1;j<=x;j++)
		{
			if(strcmp(C->cityarr[j],dest)==0)
			{
				flag=1;
				dindex=j;
				break;
			}
		}
		if(flag==0)
		{	
			x++;
			strcpy(C->cityarr[x],dest);
			dindex=x;
		}
		C->mat[sindex][dindex]=1;
		

	}

}
void disp(cityADT *C)
{
	int i,j;
	printf("The adjacency matrix is: \n");
	for(i=1;i<=C->num;i++)
	{
		for(j=1;j<=C->num;j++)
		{
			printf("%d ",C->mat[i][j]);
		}
		printf("\n");
	}
	printf("***DISPLAY****\n");
	for(i=1;i<=C->num;i++)
	{
		for(j=1;j<=C->num;j++)
		{
			if(C->mat[i][j]==1)
			{
				printf("There exitsts a path between %s and %s\n",C->cityarr[i],C->cityarr[j]);
			}
		}
	}
	
}
int connect(cityADT *C,char source[20],char dest[20])
{
	int i,j;
	int sindex,dindex;
	for(i=1;i<=C->num;i++)	
	{
		if(strcmp(source,C->cityarr[i])==0)
			sindex=i;
		else if(strcmp(dest,C->cityarr[i])==0)
			dindex=i;
	}
	queue *q;
	q=malloc(sizeof(queue));
	init(q,100);
	int x,y,z;
	int visited[C->num];
	for(i=1;i<=C->num;i++)
	{
		visited[i]=0;
	}
			x=sindex;
		visited[x]=1;
		enqueue(q,x);
		while(!isEmpty(q))
		{
			z=dequeue(q);
			for(i=1;i<=C->num;i++)
			{
				if(C->mat[z][i])
				{
					y=i;
					if(visited[y]==0)
					{
						visited[y]=1;
						enqueue(q,y);
					}
				}
			}

		}
	
	if(visited[dindex]==1)
			return 1;
	return 0;
}

void BFS(cityADT *C,char start[])
{
	queue *q;
	q=malloc(sizeof(queue));
	init(q,100);
	int x,y,z;
	int visited[C->num];
	int i;
	x=sourceIndex(C,start);
	for(i=1;i<=C->num;i++)
	{
		visited[i]=0;
	}
	printf("\n%s is visited\n",start);
		visited[x]=1;
		enqueue(q,x);
		while(!isEmpty(q))
		{
			z=dequeue(q);
			for(i=1;i<=C->num;i++)
			{
				if(C->mat[z][i]&&visited[i]==0)
				{
					visited[i]=1;
						printf("\n%s is visited\n",C->cityarr[i]);
						enqueue(q,i);
				}
			}
	}
}

int sourceIndex(cityADT *C,char source[])
{
	int i,x=0;
	for(i=1;i<=C->num;i++)
	{
		if(strcmp(C->cityarr[i],source)==0)
		{
			return i;
		}
	}
	return -1;
}

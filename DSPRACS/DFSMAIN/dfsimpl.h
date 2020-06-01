#include "dfsif.h"
#include "stack.h"

int visited[100];
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

void DFS(cityADT *C,int x)
{
	Stack *s;
	s=initialize(s);
	int i,t;
	for(i=0;i<100;i++) visited[i]=0;
	int index=1;
	int flag;
	push(s,x);
	while(!isEmpty(s))
	{
		t=pop(s);
		printf("%s ", C->cityarr[t]);
		for(i=1;i<=C->num;i++)
		{
			if(C->mat[t][i]==1&&visited[i]==0)//if neighbor and not visited
			{
				push(s,i);
				visited[i]=1;

			}
		}
	}
}

int findSource(cityADT *C,char source[])//returns index of city
{
	int i,x=0;
	for(i=1;i<=C->num;i++)
	{
		if(strcmp(C->cityarr[i],source)==0)
		{
			x=i;
		}
	}
	return x;
}



void DFSpath(cityADT *C,int x,int d)
{
	Stack *s;
	s=initialize(s);
	int path[1000];//contains index of parent
	int i,t;
	for(i=0;i<100;i++) visited[i]=0;
	int index=1;
	int flag=0;
	push(s,x);
	while(!isEmpty(s))
	{
		t=pop(s);
		if(t==d)//checks if destination is reached
		{
			flag=1;
			break;
		}
		for(i=1;i<=C->num;i++)
		{
			if(C->mat[t][i]==1&&visited[i]==0)
			{
				path[i]=t;//stores index of parent
				push(s,i);
				visited[i]=1;
			}
		}
	}
	int finalpath[1000];
	int j=0;
	if(flag==0)
		printf("No path\n");
	else
	{
		while(t!=x)
		{
			finalpath[j]=t;
			j++;
			t=path[t];
		}
		finalpath[j]=x;
		while(j>=0){
			printf("%s ",C->cityarr[finalpath[j]]);
			j--;
		}
	}
	

}
    
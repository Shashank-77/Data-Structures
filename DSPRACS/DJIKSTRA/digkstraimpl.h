#include "digkstraif.h"

void create(cityADT *C)
{
	int num;
	int x=0;
	int connections;
	int flag;
	int sindex,dindex;
	char source[20],dest[20];

	int i,j,cost;
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
		printf("Enter the cost: ");
		scanf("%d",&cost);
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
		C->mat[sindex][dindex]=cost;
		

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



int findSource(cityADT *C,char source[])
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
int unknown(cityADT *C)
{
	int i;
	for(i=1;i<=C->num;i++)
	{
		if(C->dikstra[i][1]==0)
			return 1;

	}
	return 0;
}
 void dikstralgo(cityADT *C, int source)
 {
 	initdikstra(C);
 	int v,i,x;
 	C->dikstra[source][2]=0;
 	printf("Initial configuration: \n");
 	displaydikstra(C);
 	while(unknown(C))
 	{
 		x=1000;
 		for(i=1;i<=C->num;i++)
 		{
 			if(C->dikstra[i][2]<x && C->dikstra[i][1]==0)
 			{
 				x=C->dikstra[i][2];
 				v=i;
 			}
 		}
 		C->dikstra[v][1]=1;
 		for(i=1;i<=C->num;i++)
 		{
 			if(C->mat[v][i]>0)//neighbor of v
 			{
 				if(C->dikstra[i][1]==0)
 				{
 					if((C->dikstra[v][2]+C->mat[v][i])<C->dikstra[i][2])
 					{
 						C->dikstra[i][2]=C->dikstra[v][2]+C->mat[v][i];
 						C->dikstra[i][3]=v;
 					}
 				}
 			}
 			printf("Ater %d is known\n",v);
 			displaydikstra(C);
 		}
 	}

 }
void initdikstra(cityADT *C)
{
	int i;
	for(i=1;i<=C->num;i++)
	{
		C->dikstra[i][0]=i;
		C->dikstra[i][1]=0;
		C->dikstra[i][2]=5000;
		C->dikstra[i][3]=0;

	}
}
void displaydikstra(cityADT *C)
{
	printf("v\tk\td\tp\n");
	int i,j;
	for(i=1;i<=C->num;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",C->dikstra[i][j]);
		}
		printf("\n");
		
	}
}

void displayPath(cityADT *C,int  source,int destination) 
{
	int pathrev[20];
	char path[500];
	int x;
	int j=0;
	x=C->dikstra[destination][3];
	pathrev[j]=destination;
	j++;
	while(x!=source)
	{
		pathrev[j]=x;
		j++;
		x=C->dikstra[x][3];
	}
	pathrev[j]=source;
	j++;
	int i;
	while(j>=0)
	{
		printf("%s ",C->cityarr[pathrev[j]]);
		j--;
	}
}
#include<stdio.h>
#include<stdlib.h>

typedef struct list
{	int no;
	struct list *next;
}list;

typedef struct
{	int size;
	list *arr[20];
}hash;

void initialise(hash *h,int x)
{	h->size=x;
	int i;
	for(i=0;i<h->size;i++)
	{	h->arr[i]=malloc(sizeof(list));
		h->arr[i]->next=NULL;
	}
}

void insert(hash *h,int x)
{	int m;
	m=x%h->size;
	list *temp=malloc(sizeof(list));
	temp->no=x;
	temp->next=h->arr[m]->next;
	h->arr[m]->next=temp;
}

void search(hash *h,int x)
{	int m=x%h->size;
	int ct;
	list *temp;
	temp=h->arr[m]->next;
	while(temp!=NULL)
	{
		if(temp->no==x)
		{	printf("FOUND");
			ct=1;
			break;
		}
		temp=temp->next;
	}
	if(ct==0)
		printf("NOT FOUND");
}

void display(hash *h)
{	list *temp;
	for(int i=0;i<h->size;i++)
	{	temp=h->arr[i]->next;
		printf("%d \t",i);
		while(temp!=NULL)
		{
			printf("%d ",temp->no);
			temp=temp->next;
		}
		printf("\n");
		
	}
}
		

void main()
{	int i,j,n,x,opt;
	hash *h=malloc(sizeof(hash));
	list *temp=malloc(sizeof(list));
	printf("enter size of hash table:");
	scanf("%d",&n);
	initialise(h,n);
	do
	{
		printf("MENU:\n1.insert\n2.search\n3.display\n4.exit\n");
		printf("OPTION:");
		scanf("%d",&opt);
		if(opt==1)
		{
			printf("enter element to insert:");
			scanf("%d",&x);
			insert(h,x);
		}
		else if(opt==2)
		{
			printf("enter element to search:");
			scanf("%d",&x);
			search(h,x);
		}
		else if(opt==3)
		{
			display(h);
		}
		else
		{	printf("EXITING.....\n");
			break;
		}
	}while(opt!=4);
}

	
	

	
	

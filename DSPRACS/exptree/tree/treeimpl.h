
typedef struct node
{	char c;
	struct node *lptr,*rptr;
}node;

typedef struct Stack
{	struct node *a[20];
	int top;
}Stack;


void initialises(struct Stack *s)
{	s->top=-1;
}

struct node *create(char x)
{	struct node *temp=malloc(sizeof(struct node));
	temp->lptr=NULL;
	temp->rptr=NULL;
	temp->c=x;
	return temp;
}

void pushs(struct Stack *s,struct node *x)
{	if(s->top==9)
		printf("stack is full");
	else
	{	s->top++;
		s->a[s->top]=x;
	}
}

struct node *pops(struct Stack *s)
{	if(s->top==-1)
		printf("stack is empty");
	else
	{	s->top--;
		return s->a[s->top+1];
	}
}

struct node *treeExp(char post[])
{	struct Stack *s=malloc(sizeof(struct Stack));
	initialises(s);
	int i;
	for(i=0;i<strlen(post);i++)
	{	struct node *temp=create(post[i]);
		if(isdigit(post[i]))
			pushs(s,temp);
		else
		{	temp->rptr=pops(s);
			temp->lptr=pops(s);
			pushs(s,temp);
		}
	}
	return s->a[0];
}

int evaluate(struct node *x)
{	if(x->lptr==NULL&&x->rptr==NULL)
		return (x->c-'0');
	else
	{	
		char l=x->c;
		int a=evaluate(x->lptr);
		int b=evaluate(x->rptr);
		if(l=='+')
			return (a+b);
		else if(l=='-')
			return (a-b);
		else if(l=='*')
			return (a*b);
		else if(l=='/')
			return (a/b);
	}
}	


typedef struct
{	int top,size;
	char a[20];
}stack;	

void initialise(stack *s)
{
	s->top=-1;
}
int isEmpty(stack *s)
{	if(s->top==-1)
		return 1;
	else return 0;
}
int isFull(stack *s)
{	if(s->top==s->size)
		return 0;
	else return 1;
}
void push(stack *s,char x)
{	
	s->top+=1;
	s->a[s->top]=x;

}
char pop(stack *s)
{	if(isEmpty(s)==1)
	{	printf("stack is empty");
		return 0;
	}
	else
	{	
		s->top-=1;
		return s->a[(s->top)+1];
	}
}
void disp(stack *s)
{	if(isEmpty(s)==0)
		printf("stack is empty");
	else
	{	int i;
		for(i=s->top;i>=0;i--)
			printf("%c",s->a[i]);
	}
	
}
int precedence(char x)
{	if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
	else
		return 3;
}
void convert(char in[20],char post[20],stack *s)
{	int t=0,i;
	for(i=0;i<strlen(in);i++)
	{	if(isdigit(in[i]))
			post[t++]=in[i];
		else 
		{	if(isEmpty(s))
				push(s,in[i]);
			else  
			{	char x=s->a[s->top];
				while(precedence(x)>=precedence(in[i])&&s->top!=-1)
				{	post[t++]=pop(s);
					x=s->a[s->top];
				}
				push(s,in[i]);
				
			}
		}
		
	}
	while(!isEmpty(s))
	{	post[t++]=pop(s);
	
	}
	post[t]='\0';
	printf("the postfix expression is:");
	for(i=0;i<strlen(post);i++)
		printf("%c",post[i]);
}


		



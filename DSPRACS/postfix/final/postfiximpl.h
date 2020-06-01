

typedef struct
{
	char s[20];
	int top,size;
}Stack;




Stack *initialize()
{
	Stack *S=malloc(sizeof(Stack));
	S->size=20;
	S->top=-1;
	return S;
}


int isEmpty(Stack *S)
{
	if(S->top==-1)
		return 0;
	else
		return 1;
}


int isFull(Stack *S)
{
	if(S->top>=S->size)
		return 0;
	else
		return 1;
}


void Push(Stack *S,char x)
{
	if(isFull(S)==0)
		printf("\nStack is full!");
	else
	{
		S->top+=1;
		S->s[S->top]=x;
	}
}

char Pop(Stack *S)
{
	if(isEmpty(S)==0)
		return '\0';
	else
	{
		S->top-=1;
		return S->s[S->top+1];
	}
}


void display(Stack *S)
{
	if(isEmpty(S)==0)
		printf("\nStack is empty!");
	else
	{
		int i;
		printf("\nStack: \n");
		for(i=S->top;i>=0;i--)
			printf("%d ",S->s[i]);
	}
}


int precedence(char a)
{
	if(a=='+'||a=='-')
		return 1;
	else if(a=='*'||a=='/')
		return 2;
	else if(a=='^')
		return 3;
}


void InftoPost(Stack *S,char str[80],char post[80])
{
	int counter=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(isdigit(str[i]))
		{
			post[counter]=str[i];
			counter++;
		}
		else
		{
			char t;
			if(S->top==-1)
				Push(S,str[i]);
			else
			{
				t=S->s[S->top];
				while(precedence(t)>=precedence(str[i]))
				{
					post[counter]=Pop(S);
					counter+=1;
					t=S->s[S->top];
				}
				Push(S,str[i]);
			}
		}
	}
	while(S->top!=-1)
	{
		post[counter]=Pop(S);
		counter+=1;
	}
	post[counter]='\0';

}


int evalPost(Stack *S,char post[80])
{
	for(int i=0;i<strlen(post);i++)
	{
		if(isdigit(post[i]))
			Push(S,post[i]);
		else
		{
			int a=Pop(S)-48;
			int b=Pop(S)-48;
			switch(post[i])
			{
				case '+':Push(S,(b+a)+48);break;
				case '-':Push(S,(b-a)+48);break;
				case '*':Push(S,(b*a)+48);break;
				case '/':Push(S,(b/a)+48);break;
				case '^':Push(S,(b^a)+48);break;
			}

		}
	}
	return (Pop(S)-48);

}

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include"treeinter.h"
#include"treeimpl.h"
void main()
{	char in[20],post[20];
	printf("enter infix expression:");
	scanf("%s",in);
	stack *s=malloc(sizeof(stack));
	stack *m=malloc(sizeof(stack));
	initialise(s);
	initialise(m);
	convert(in,post,s);
	struct node *temp=treeExp(post);
	int ans=evaluate(temp);
	printf("\nevaluated answer:%d",ans);
}

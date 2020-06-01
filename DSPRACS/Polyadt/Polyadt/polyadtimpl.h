/*typedef struct 
{
	int val,exp;
}term;

typedef struct tpolyADT
{
	term t;
	struct tpolyADT *next;
}polyADT;
*/

void initialise(polyADT *p)
{
	p -> next = NULL;
}

void insertFront(polyADT *p,term x)
{
	polyADT *temp = (polyADT*)malloc(sizeof(polyADT));
	temp -> t.val = x.val;
	temp -> t.exp = x.exp;
	temp -> next = p -> next;
	p -> next = temp;

}
void insertEnd(polyADT *p, term x)

{
	polyADT *temp = (polyADT*)malloc(sizeof(polyADT));
	polyADT *tmp;
	temp -> t.val = x.val;
	temp -> t.exp = x.exp;
	
	 if(p->next==NULL)
	 {
	  p->next=temp;
	  temp->next=NULL;
	 }
	 else
	 {
	 	tmp=p->next;
	 	while(tmp->next!=NULL)
	  	 tmp=tmp->next;
	 	temp->next=tmp->next;
     	tmp->next=temp;
	 }


}
void insertAfterTerm(polyADT *p, term x, int exp)
{
	polyADT *temp = (polyADT*)malloc(sizeof(polyADT));
	polyADT *tmp;
	temp -> t.val = x.val;
	temp -> t.exp = x.exp;
	 if(p->next==NULL)
	 {
	  p->next=temp;
	  temp->next=NULL;
	 }
	 else
	 {
	 	tmp=p->next;
	 	while(tmp -> t.exp != exp)
	 	 tmp=tmp->next;
	 	temp->next=tmp->next;
     	tmp->next=temp;
	 }

}
polyADT *polyAdd(polyADT *p1, polyADT *p2)
{
	polyADT *tmp1, *tmp2;
	term j;
    tmp1=p1->next;
    tmp2=p2->next;
    polyADT *temp1 = (polyADT*)malloc(sizeof(polyADT));
    temp1 -> next = NULL;
    while(tmp1!=NULL && tmp2!=NULL)
	{
	 if(tmp1->t.exp>tmp2->t.exp)
	 {
	  insertEnd(temp1,tmp1->t);
	  tmp1=tmp1->next;
	 }
	 else if(tmp2->t.exp>tmp1->t.exp)
	 {
	  insertEnd(temp1,tmp2->t);
	  tmp2=tmp2->next;
	 }
	 else if(tmp1->t.exp==tmp2->t.exp)
	 {
	  if(tmp1->t.val+tmp2->t.val!=0)
	  {
           //temp ->t.val = tmp1 -> t.val + tmp2 ->t.val
           //temp -> t.exp = tmp1 ->t.exp
	  	j.val = tmp1->t.val + tmp2->t.val;
	  	j.exp  = tmp1 -> t.exp;
        insertEnd(temp1,j);
	  }
      tmp1=tmp1->next;
	  tmp2=tmp2->next;
     }
	}
 	if(tmp1!=NULL)
	{
	 while(tmp1!=NULL)
	 {
	  insertEnd(temp1,tmp1->t);
	  tmp1=tmp1->next;
	 }
	}
	else if(tmp2!=NULL)
	{
	 while(tmp2!=NULL)
	 {
	  insertEnd(temp1,tmp2->t);
	  tmp2=tmp2->next;
	 }
	}
	return temp1;
	/*polyADT *tmp3;
	tmp3 = temp1 -> next;
	while(tmp3!=NULL)
	{
		if(tmp3->t.val > 0)
		{
			printf("+%dx^%d",tmp3->t.val,tmp3->t.exp);
		}
		else if(tmp3->t.val < 0)
		{
			printf("-%dx^%d",tmp3->t.val,tmp3->t.exp)
		}
	}
	*/
}

polyADT *polyMul(polyADT *p1,polyADT *p2)
{
	
	polyADT *temp2 = (polyADT*)malloc(sizeof(polyADT));
    temp2 -> next = NULL;
    term j;
	polyADT *tmp1, *tmp2, *tmp4, *tmp3;
    tmp1 = p1->next;
    
    while(tmp1!=NULL)
    {
    	tmp2=p2->next;
    	while(tmp2!=NULL)
    	{
    		int flag=0;
    		tmp3=temp2->next;
    		while(tmp3!=NULL)
    		{
    			if(tmp3->t.exp==(tmp2->t.exp+tmp1->t.exp))
    			{
    				tmp3->t.val=tmp3->t.val+(tmp2->t.val*tmp1->t.val);
    				flag=1;
    				break;
				}
				tmp3=tmp3->next;	
            } 
            if(flag==0)
             	{
             	j.val = tmp1->t.val*tmp2->t.val;
	  			j.exp  = tmp1 -> t.exp + tmp2 -> t.exp;
                insertEnd(temp2,j); 
                }  
			tmp2=tmp2->next; 
    	}
    	tmp1=tmp1->next;	
    }
    /*polyADT *tmp4;
	tmp4 = temp2 -> next;
	while(tmp4!=NULL)
	{
		if(tmp4->t.val > 0)
		{
			printf("+%dx^%d",tmp4->t.val,tmp4->t.exp);
		}
		else if(tmp4->t.val < 0)
		{
			printf("-%dx^%d",tmp4->t.val,tmp4->t.exp)
		}
	}
    */
    return temp2;
}

void display(polyADT *p)
{
	polyADT *tmp;
	tmp=p ->next;
	while(tmp!=NULL)
	{
		if(tmp->t.exp==0 && tmp->next==NULL)
			printf("(%d)",tmp->t.val);
		
		else if(tmp->t.exp!=0 && tmp->next==NULL)
			printf("(%d x^%d)",tmp->t.val,tmp->t.exp);
        
        else if(tmp->t.exp==0 && tmp->next!=NULL)
			printf("(%d)+",tmp->t.val);
		
		else 
			printf("(%d x^%d)+",tmp->t.val,tmp->t.exp);
		tmp=tmp->next;
	}
}


void polyDegree(polyADT  *p)
{
	polyADT *tmp;
	tmp=p ->next;
	int max = -10000;
	while(tmp!=NULL)
	{
		if(tmp->t.exp > max)
		{
			max = tmp->t.exp;
		}
		tmp = tmp->next;
	}
	/*if(tmp->t.val > max)
		{
			max = tmp->t.val;
		}*/
	printf("The degree of the polynomial is %d",max);
}

int polyEvaluate(polyADT  *p)
{
	polyADT *tmp;
	tmp=p ->next;
	int x;
	int sum = 0;
	printf("Enter a value of x,for which you want to evaluate the polynomial");
	scanf("%d",&x);
	
	while(tmp!=NULL)
	{
		
		sum += pow(x,tmp->t.exp) * tmp->t.val;
		tmp = tmp->next;
	}
	
	return sum;

}

polyADT* polySimplify(polyADT  *p)
{
	term j;

	polyADT *tmp;
	tmp=p ->next;
	
	polyADT *temp;
	//temp = p ->next;
	
	polyADT *temp1 = (polyADT*)malloc(sizeof(polyADT));
	temp1 ->next = NULL;
	
	int degnow[100],valnow;
	
	int k;
	int i = 0;
	int flag;
	
	while(tmp!=NULL)
	{
		temp = p ->next;
		flag = 0;
		for(k = 0;k<i;k++)
		{
			if(degnow[k] == tmp->t.exp)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			tmp = tmp->next;
			continue;
		}
		degnow[i++] = tmp->t.exp;
		valnow = 0;
		while(temp!=NULL)
		{
			if(temp->t.exp == tmp->t.exp)
			{
					valnow += temp->t.val;
			}
			temp = temp ->next;

		}
		j.val = valnow;
		j.exp = tmp->t.exp;
		insertEnd(temp1,j);
		tmp = tmp->next;
	}

return temp1;
}

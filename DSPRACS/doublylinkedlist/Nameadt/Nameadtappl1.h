



typedef struct Person
{
	int pin;
	char name[100];
	int age;
	char ch[100];
	char cityadd[100];
	char streetadd[100];
	int mobilenum;
}Person;

typedef struct nameadt
{
	Person g;
	struct nameadt *lptr;
	struct nameadt *rptr;
}nameadt;

void initialise(nameadt *n)
{
	n -> lptr = NULL;
	n -> rptr = NULL;
}
	
void insertfront(nameadt *n,Person p)
{
	nameadt *tmp;
	nameadt *temp = (nameadt *)malloc(sizeof(nameadt));
	tmp = n -> rptr;
	
	nameadt *temp1;
	
	temp -> g.age  = p.age;
	
	strcpy(temp -> g.name,p.name);
	
	strcpy(temp -> g.ch,p.ch);
	
	strcpy(temp -> g.cityadd,p.cityadd);
	
	strcpy(temp -> g.streetadd,p.streetadd);
	
	temp -> g.mobilenum  = p.mobilenum;

	//creating randomnum
	srand(12345);
	
	
	
	temp -> g.pin = rand();
	
	while(tmp != NULL)
	{
		if(tmp ->g.pin == temp ->g.pin)
		{
			tmp = n -> rptr;
			temp ->g.pin = rand();
		}
		else
		{
			tmp = tmp -> rptr;
		}
	}
	
	
	//main insert	
	
	if(n -> rptr == NULL)
	{
		n ->rptr = temp;
		temp -> rptr = NULL;
		temp -> lptr = n;
	}
	else
	{
		temp -> rptr = n->rptr;
		temp1 = temp -> rptr;
		temp -> lptr = n;
		n -> rptr = temp;
		temp1 -> lptr = temp;
	}
	
}

void insertEnd(nameadt *n,Person p)
{
	nameadt *tmp;
	nameadt *temp = (nameadt *)malloc(sizeof(nameadt));
	tmp = n -> rptr;
	
	nameadt *temp1;
	
	temp -> g.age  = p.age;
	
	strcpy(temp -> g.name,p.name);
	
	strcpy(temp -> g.ch,p.ch);
	
	strcpy(temp -> g.cityadd,p.cityadd);
	
	strcpy(temp -> g.streetadd,p.streetadd);
	
	temp -> g.mobilenum  = p.mobilenum;
	
	
	
	//creating randomnum
	srand(12345);
	

	
	temp ->g.pin = rand();
	
	while(tmp != NULL)
	{
		if(tmp ->g.pin == temp ->g.pin)
		{
			tmp = n -> rptr;
			temp ->g.pin = rand();
		}
		else
		{
			tmp = tmp -> rptr;
		}
	}
	
	tmp = n->rptr;
	temp1 = n;
	//main insert	
	
	if(n -> rptr == NULL)
	{
		n ->rptr = temp;
		temp -> rptr = NULL;
		temp -> lptr = n;
	}
	else
	{
		while(tmp!=NULL)
		{
			tmp = tmp->rptr;
			temp1 = temp1 ->rptr;
		}
		temp1->rptr = temp;
		temp->rptr = NULL;
		temp->lptr = temp1;

	}
	
}

void insertPin(nameadt *n,Person p,int pin)
{
	nameadt *tmp;
	nameadt *temp = (nameadt *)malloc(sizeof(nameadt));
	tmp = n -> rptr;
	
	nameadt *temp1;
	
	temp -> g.age  = p.age;
	
	strcpy(temp -> g.name,p.name);
	
	strcpy(temp -> g.ch,p.ch);
	
	strcpy(temp -> g.cityadd,p.cityadd);
	
	strcpy(temp -> g.streetadd,p.streetadd);
	
	temp -> g.mobilenum  = p.mobilenum;
	
	
	
	//creating randomnum
	srand(12345);
	

	
	temp ->g.pin = rand();
	
	while(tmp != NULL)
	{
		if(tmp ->g.pin == temp ->g.pin)
		{
			tmp = n -> rptr;
			temp -> g.pin = rand();
		}
		else
		{
			tmp = tmp -> rptr;
		}
	}
	
	tmp = n->rptr;
	temp1 = n;
	int flag = 0;
	//main insert	
	
	if(n -> rptr == NULL)
	{
		printf("No records present");
	}
	else
	{
		while(tmp!=NULL)
		{
			if(tmp->g.pin == pin)
			{
				temp ->rptr = tmp ->rptr;
				temp1 = temp ->rptr;
				tmp -> rptr = temp;
				temp ->lptr= tmp;
				temp1 -> lptr = temp;
				flag = 1;
				break;


			}
			tmp = tmp->rptr;
		}
		

	}
	if(flag == 1 && n->rptr != NULL)
	{
		printf("Insertion sucessful");
	}
	else if(flag == 0 && n->rptr !=NULL )
	{
		printf("pin not present");
	}
	
}
void SeniorPerson(nameadt *n)
{
	nameadt *temp2;

	//normal display
	
	temp2 = n -> rptr;
	if(temp2 == NULL)
	{
		printf("No elements present");
	}
	else
	{
		while(temp2 != NULL)
		{
			if(temp2 ->g.age >=65)

			{
				printf("The name is %s\n",temp2 -> g.name);
	
				printf("The gender is %s\n",temp2 -> g.ch);
			
				printf("The cityaddress is %s\n",temp2 -> g.cityadd);
		
				printf("The streetaddress is %s\n",temp2 -> g.streetadd);
		
				printf("The mobilenumber is %d \n",temp2 -> g.mobilenum);
				
				
				printf("The age is %d \n",temp2 -> g.age);
				
				
				printf("The pin is %d \n",temp2 ->g.pin);
			
		    }
		temp2 = temp2 ->rptr;
		}
	}
}
void ratio(nameadt *n)
{
	nameadt *temp2;

	temp2 = n -> rptr;
	int countm = 0;
	int countf = 0;
	if(temp2 == NULL)
	{
		printf("No records present");
	}
	else
	{
		while(temp2 != NULL)
		{
			if(strcmp(temp2 -> g.ch,"m")==0)

			{
				countm++;
			
		    }
		    else
		    {
		    	countf++;
		    }
		temp2 = temp2 ->rptr;
		}
	}
	printf(" %d : %d ",countm,countf);
}

void locatePerson(nameadt *n,char add[])
{
	nameadt *temp2;

	//normal display
	
	int flag = 0;

	temp2 = n -> rptr;
	if(temp2 == NULL)
	{
		printf("No elements present");
	}
	else
	{
		while(temp2 != NULL)
		{
			if(strcmp(temp2 -> g.cityadd,add) == 0)

			{
				printf("The name is %s\n",temp2 -> g.name);
	
				printf("The gender is %s\n",temp2 -> g.ch);
			
				printf("The cityaddress is %s\n",temp2 -> g.cityadd);
		
				printf("The streetaddress is %s\n",temp2 -> g.streetadd);
		
				printf("The mobilenumber is %d \n",temp2 -> g.mobilenum);
				
				
				printf("The age is %d \n",temp2 -> g.age);
				
				
				printf("The pin is %d \n",temp2 -> g.pin);

				flag = 1;
			
		    }
		temp2 = temp2 ->rptr;
		}
	}
	if(flag == 1)
	{
		printf("\nsuccesful\n");
	}
	else
	{
		printf("\nnotsucessful\n");
	}
}

void display(nameadt *n)
{
	nameadt *temp2;
	
	nameadt *temp3;
	
	temp3 = n;
	//normal; display
	
	temp2 = n -> rptr;
	if(temp2 == NULL)
	{
		printf("No elements present");
	}
	else
	{
		while(temp2 != NULL)
		{
			printf("The name is %s\n\n",temp2 -> g.name);
	
			printf("The gender is %s\n\n",temp2 -> g.ch);
		
			printf("The cityaddress is %s\n\n",temp2 -> g.cityadd);
	
			printf("The streetaddress is %s\n\n",temp2 -> g.streetadd);
	
			printf("The mobilenumber is %d \n\n",temp2 -> g.mobilenum);
			
			printf("The age is %d \n\n",temp2 -> g.age);
			
			printf("The pin is %d \n\n",temp2 -> g.pin);
			
			temp2 = temp2 ->rptr;
			
			temp3 = temp3 ->rptr;
		}
	}



	//reverse display
	printf("\n\n\n");
	if(n->rptr == NULL)
	{
		printf("No elements present");
	}
	else
	{
		while(temp3 != n)
		{
			
			printf("The name is %s\n\n",temp3 -> g.name);
	
			printf("The gender is %s\n\n",temp3 -> g.ch);
		
			printf("The cityaddress is %s\n\n",temp3 -> g.cityadd);
	
			printf("The streetaddress is %s\n\n",temp3 -> g.streetadd);
	
			printf("The mobilenumber is %d \n\n",temp3 -> g.mobilenum);
			
			
			printf("The age is %d \n\n",temp3 -> g.age);
			
			
			printf("The pin is %d \n\n",temp3 -> g.pin);
			
			temp3 = temp3 -> lptr;
		}
	}
}
void sort(nameadt *n)
{
	nameadt *i;
	nameadt *j;
	nameadt *k;
	

	

	i = n->rptr;
	k = n->rptr;
	j = k -> rptr;
	nameadt *l;
	nameadt *q;
	
	for(i = n->rptr;i !=NULL;i = i -> rptr)
		{
			printf("yo");
			for(j = k->rptr;j !=NULL;j = j -> rptr)
			{
				printf("hey");
				if(i -> g.age > j-> g.age)
				{


					l = i->lptr; 

					l->rptr = j;

					//q = j->rptr;

					//q -> lptr = i; 

					i -> rptr = j ->rptr;
					
					j -> lptr = i->lptr;
					
					j -> rptr = i;
					
					i -> lptr = j; 

				}
			}
		}
}


		
	

	

	

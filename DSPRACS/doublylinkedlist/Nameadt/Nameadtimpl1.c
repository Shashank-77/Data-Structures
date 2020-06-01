#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Nameadtappl1.h"

#include "Nameadtfuncname1.h"
void main()
{
	int c;
	nameadt *n = (nameadt*)malloc(sizeof(nameadt));
	initialise(n);
	int cha;
	
	Person p;

	char add[100];


	
	
	do
	{
		printf("Enter 1 to insertfront,2 to display,3 to exit,4 to sort,5 to insertend,6 to insert after a pin");
		printf("7 to display details of senior people,8 to show male to female ratio,9 to locate a person and display their details");
	
		scanf("%d",&c);
		
		if(c == 3)
		{
			printf("thankyou");
			break;
		}
		
		switch(c)
		{
			case 1:
				printf("Enter the details\n");
				printf("Enter the name\n");
				scanf(" %s",p.name);
				
				printf("Enter the cityaddress\n");
				scanf(" %s",p.cityadd);
				
				printf("Enter the streetaddress\n");
				scanf(" %s",p.streetadd);
				
				printf("Enter the mobilenumber\n");
				scanf("%d",&p.mobilenum);
				
				printf("Enter the age\n");
				scanf("%d",&p.age);

				printf("Enter the gender\n");
				scanf(" %s",p.ch);
				
				insertfront(n,p);

				break;
			case 2:
				display(n);
				break;
			case 4:
				sort(n);
				display(n);
				break;
			case 5:
				printf("Enter the details\n");
				printf("Enter the name\n");
				scanf(" %s",p.name);
				
				printf("Enter the cityaddress\n");
				scanf(" %s",p.cityadd);
				
				printf("Enter the streetaddress\n");
				scanf(" %s",p.streetadd);
				
				printf("Enter the mobilenumber\n");
				scanf("%d",&p.mobilenum);
				
				printf("Enter the age\n");
				scanf("%d",&p.age);

				printf("Enter the gender\n");
				scanf(" %s",p.ch);

				insertEnd(n,p);
				break;
			case 6:
				printf("Enter the pin after which you want to insert");
				scanf("%d",&cha);
				
				printf("Enter the details\n");
				printf("Enter the name\n");
				scanf(" %s",p.name);
				
				printf("Enter the cityaddress\n");
				scanf(" %s",p.cityadd);
				
				printf("Enter the streetaddress\n");
				scanf(" %s",p.streetadd);
				
				printf("Enter the mobilenumber\n");
				scanf("%d",&p.mobilenum);
				
				printf("Enter the age\n");
				scanf("%d",&p.age);

				printf("Enter the gender\n");
				scanf(" %s",p.ch);


				insertPin(n,p,cha);
				break;
			case 7:
				SeniorPerson(n);
				break;
			case 8:
				ratio(n);
				break;
			case 9:
				printf("Enter the cityaddress\n");
				scanf(" %s",add);
				locatePerson(n,add);
				break;

		}
	}while(c!=3);
}	
				
	
	
	

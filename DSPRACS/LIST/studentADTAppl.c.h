#include <stdio.h>
#include <stdlib.h>
#include "studentADTif.h"
#include "studentADTimpl.h"


void main()
{
	int choice,count,i;
	char sName[20];
	student s,found;
	studArr *listADT1,*foundList,*passedList;
	int regNo;
	listADT1=malloc(sizeof(studArr));//allocates memory for the list
	choice=1;
	while(choice!=11)
	{
		printf("\n\nMENU\n1 - add record to the front\n2 - add record to the end\n3 - add record after a register number\n4 - search by register number\n5 - search by name \n6 - Delete record\n7 to calculate result\n8 - list the students that passed\n9 - List the number of students that passed with first class\n10 - display all records\n11 - Exit: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1://insert in the front
			{
				s=getinput();
				insertFront(listADT1,s);
				break;
			}
			case 2://insert at the end
			{
				s=getinput();
				insertEnd(listADT1,s);
				break;
			}
			case 3://get input and insert after 1 register number
			{
				s=getinput();
				printf("Enter the register number after which you want to insert: ");
				scanf("%d",&regNo);
				insertRegNo(listADT1,s,regNo);
				break;

			}
			case 4://search for a register number
			{
				printf("Enter the register number to search: ");
				scanf("%d",&regNo);
				found=searchRegNo(listADT1,regNo);
				printf("The name is: %s",found.name);
				break;

			}
			case 5://search for a name
			{
				printf("\nEnter the name to search for: ");
				scanf("%s",sName);
				foundList=searchName(listADT1,sName);
				display(foundList);
				break;
				
			}
			case 6://delete a record
			{
				printf("Enter the register number to delete: ");
				scanf("%d",&regNo);
				del(listADT1,regNo);
				break;
				
			}

			case 7://calculate the results
			{
				computeResult(listADT1);
				printf("REGISTER NUMBER\tNAME\tMARK 1\tMARK2\tMARK3\tTOTAL\tRESULT\n");
				for(i=0;i<listADT1->size;i++)
				{
					printf("%d\t\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t %c\n",listADT1->list[i].regNo,listADT1->list[i].name,listADT1->list[i].marks1,listADT1->list[i].marks2,listADT1->list[i].marks3,listADT1->list[i].total,listADT1->list[i].result);
				}
				break;
			
				
			}
			case 8://list the students that passed 
			{
				computeResult(listADT1);
				printf("The students that passed are:\n");
				passedList=listResult(listADT1);
				display(passedList);
				break;
							
			}
			case 9://displays the number of students that passed with first class
			{
	
				computeResult(listADT1);
				count=listClass(listADT1);
				printf("%d students passed with first class",count);
				break;
			}
			case 10://display the list
			{
				display(listADT1);	
				break;
			}
		}
	}
}

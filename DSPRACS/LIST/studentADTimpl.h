#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

student getinput()
{
	student s;
	printf("Enter the register number: ");
	scanf("%d",&s.regNo);
	printf("Enter the name: ");
	scanf("%s",s.name);
	printf("Enter the marks: ");
	scanf("%f %f %f",&s.marks1,&s.marks2,&s.marks3);
	return s;
	

}
void insertFront(studArr *listADT1,student s)//function to insert a student record to the beginning
{
	int i;
	if(listADT1->size==MAXSIZE)
		printf("Cannot insert, size has reached maximum.");
	else
	{
		for(i=listADT1->size-1;i>=0;i--)
		{
			listADT1->list[i+1]=listADT1->list[i];
		}
		listADT1->list[0]=s;
		listADT1->size++;
	}
}

void insertEnd(studArr *listADT1,student s)//function to insert a student record at the end
{
	listADT1->list[listADT1->size]=s;
	listADT1->size++;

}

void insertRegNo(studArr *listADT1,student s,int regNum)//function to insert a student record after a register number is found
{
	int compare,i;
	if(listADT1->size==MAXSIZE)
		printf("Cannot insert, size has reached maximum.");
	else
	{
		compare=listADT1->list[0].regNo;
		int pos=0;
		while(regNum!=compare)
		{
			pos++;
			compare=listADT1->list[pos].regNo;
		}
		for(i=listADT1->size-1;i>pos;i--)
		{
			listADT1->list[i+1]=listADT1->list[i];
		}
		listADT1->list[pos+1]=s;
		listADT1->size++;
	}
}

student searchRegNo(studArr *listADT1,int regNum)//returns address of record
{
	int compare;
	compare=listADT1->list[0].regNo;
	int pos=0;
	while(compare!=regNum)
	{
		pos++;
		compare=listADT1->list[pos].regNo;	
	}
	return (listADT1->list[pos]);
}

void del(studArr *listADT1, int regNum)//deletes a record
{
	int compare,i;
	compare=listADT1->list[0].regNo;
	int pos=0;
	while(regNum!=compare)
	{
		pos++;
		compare=listADT1->list[pos].regNo;
	}
	printf("REGISTER NUMBER: %d\n",listADT1->list[pos].regNo);
	printf("NAME: %s\n",listADT1->list[pos].name);
	for(i=pos;i<=listADT1->size-1;i++)
	{
		listADT1->list[i]=listADT1->list[i+1];
	}
	listADT1->size--;
}

void computeResult(studArr *listADT1)//calculates result
{
	int i;
	for(i=0;i<listADT1->size;i++)
	{
		listADT1->list[i].total=listADT1->list[i].marks1+listADT1->list[i].marks2+listADT1->list[i].marks3;
		if((listADT1->list[i].marks1>=50)&&(listADT1->list[i].marks2>=50)&&(listADT1->list[i].marks3>=50))
			listADT1->list[i].result='p';
		else
			listADT1->list[i].result='f';
	}
}

int listClass(studArr *listADT1)//number of students that passed with first class
{
	int i,count=0;
	for(i=0;i<listADT1->size;i++)
	{
		if((listADT1->list[i].total>=210)&&(listADT1->list[i].result=='p'))
			count++;
	}
	return count;
}

void display(studArr *listADT1)//displays all records
{
	int n,i;
	n=listADT1->size;
	printf("The list is:\n");
	printf("REGISTER NUMBER\tNAME\tMARK 1\tMARK2\tMARK3\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%s\t%.2f\t%.2f\t%.2f\n",listADT1->list[i].regNo,listADT1->list[i].name,listADT1->list[i].marks1,listADT1->list[i].marks2,listADT1->list[i].marks3);
	}
}

studArr *searchName(studArr *listADT1, char name[])//lists all records which match the search name
{
	int i,j=0;
	studArr *found;
	found=malloc(sizeof(studArr)*100);
	for(i=0;i<listADT1->size;i++)
	{
		if(!(strcmp(name,listADT1->list[i].name)))
		{
			found->list[j]=listADT1->list[i];
			j++;
			found->size=j;
		}

	}
	return found;
}

studArr *listResult(studArr *listADT1)//lists the records of students that passed
{
	int i,j=0;
	studArr *passed;
	passed=malloc(sizeof(studArr)*100);
	for(i=0;i<listADT1->size;i++)
	{
		if(listADT1->list[i].result=='p')
		{
			passed->list[j]=listADT1->list[i];
			j++;
			passed->size=j;
		}
	}
	return passed;
}
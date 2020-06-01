#include<stdlib.h>
#include<stdio.h>
#include <math.h>      
#include "polyadtfuncname.h"
#include "polyadtimpl.h"

void main()
{
	
	int m,n,x;
	polyADT *p1 =(polyADT*)malloc(sizeof(polyADT)); 
	polyADT *p2 = (polyADT*)malloc(sizeof(polyADT));
	polyADT *p3 = (polyADT*)malloc(sizeof(polyADT));
	initialise(p3);
    //p3 -> next = NULL;
    polyADT *p4 = (polyADT*)malloc(sizeof(polyADT));
    polyADT *p5 = (polyADT*)malloc(sizeof(polyADT));
    polyADT *p6 = (polyADT*)malloc(sizeof(polyADT));
    initialise(p4);
    //p4 -> next = NULL;
	int c;
	term t;
	initialise(p1);
	initialise(p2);
	initialise(p5);
	initialise(p6);

	int ch;
	//creating polynomial 1
	do
	{
		printf("Enter 1 to add an element at the front of the list\n2 to insert an element at the end of the list\n3 to insert an element after a specific term\n4 to exitn\n");
		scanf("%d",&ch);
		if(ch == 4)
		{
			printf("thankyou for entering polynomial 1\n");
			break;
		}

		switch(ch)
		{
			case 1:
					printf("Enter the coefficient and exponent of the term to be inserted\n");
					scanf("%d",&t.val);
					scanf("%d",&t.exp);
					insertFront(p1,t);
					break;
			case 2:
					printf("Enter the coefficient and exponent of the term to be inserted\n");
					scanf("%d",&t.val);
					scanf("%d",&t.exp);
					insertEnd(p1,t);
					break;
			case 3:
					printf("Enter the coefficient and exponent of the term to be inserted\n");
					scanf("%d",&t.val);
					scanf("%d",&t.exp);
					printf("Enter the exponent of the term after which this term is to be inserted\n");
					scanf("%d",&c);
					insertAfterTerm(p1,t,c);
					break;
		}

	}while(1);

	//creating polynomial 2
	do
	{
		printf("Enter 1 to add an element at the front of the list\n2 to insert an element at the end of the list\n3 to insert an element after a specific term\n4 to exit\n");
		scanf("%d",&ch);
		if(ch == 4)
		{
			printf("thankyou for entering polynomial 2\n");
			break;
		}

		switch(ch)
		{
			case 1:
					printf("Enter the coefficient and exponent of the term to be inserted\n");
					scanf("%d",&t.val);
					scanf("%d",&t.exp);
					insertFront(p2,t);
					break;
			case 2:
					printf("Enter the coefficient and exponent of the term to be inserted\n");
					scanf("%d",&t.val);
					scanf("%d",&t.exp);
					insertEnd(p2,t);
					break;
			case 3:
					printf("Enter the coefficient and exponent of the term to be inserted\n");
					scanf("%d",&t.val);
					scanf("%d",&t.exp);
					printf("Enter the exponent of the term after which this term is to be inserted\n");
					scanf("%d",&c);
					insertAfterTerm(p2,t,c);
					break;
		}

	}while(1);
	//performing operations
	do
	{
		printf("Enter 1 to add the two polynomials\n2 to multiply two polynomials\n3 to exit\n4 to find the degree of the polynomials\n5 to evaluate the polynomial\n6 to simplify the polynomial\n");
		scanf("%d",&ch);
		if(ch == 3)
		{
			printf("thankyou\n");
			break;
		}

		switch(ch)
		{
			case 1:
					p3 = polyAdd(p1,p2);
    				printf("The sum is\n");
    				display(p3);
    				break;

			case 2:
    				p4 = polyMul(p1,p2);
    				printf("The product is\n");
    				display(p4);
    				break;

    		case 4:
    				
    				polyDegree(p1);
    				polyDegree(p2);
    				break;
    		
    		case 5:
    				
    				
    				m = polyEvaluate(p1);
    				n = polyEvaluate(p2);
    				printf("The first polynomial when evaluated gives %d while the second polynomial gives %d\n",m,n);
    				break;
    		
    		case 6:
    				 p5 = polySimplify(p1);
    				 p6 = polySimplify(p2);
    				 printf("The polynomial1 when simplified becomes\n");
    				 display(p5);
    				 printf("The polynomial2 when simplified becomes\n");
    				 display(p6);
    				 break;




		}


	}while(1);
}


/*
Enter 1 to add an element at the front of the list
2 to insert an element at the end of the list
3 to insert an element after a specific term
4 to exitn
1
Enter the coefficient and exponent of the term to be inserted
5
2
Enter 1 to add an element at the front of the list
2 to insert an element at the end of the list
3 to insert an element after a specific term
4 to exitn
2
Enter the coefficient and exponent of the term to be inserted
6
7
Enter 1 to add an element at the front of the list
2 to insert an element at the end of the list
3 to insert an element after a specific term
4 to exitn
2
Enter the coefficient and exponent of the term to be inserted
6
3
Enter 1 to add an element at the front of the list
2 to insert an element at the end of the list
3 to insert an element after a specific term
4 to exitn
4
thankyou for entering polynomial 1
Enter 1 to add an element at the front of the list
2 to insert an element at the end of the list
3 to insert an element after a specific term
4 to exit
2
Enter the coefficient and exponent of the term to be inserted
5
2

Enter 1 to add an element at the front of the list
2 to insert an element at the end of the list
3 to insert an element after a specific term
4 to exit
2
Enter the coefficient and exponent of the term to be inserted
6
7
Enter 1 to add an element at the front of the list
2 to insert an element at the end of the list
3 to insert an element after a specific term
4 to exit
2
Enter the coefficient and exponent of the term to be inserted
6
3
Enter 1 to add an element at the front of the list
2 to insert an element at the end of the list
3 to insert an element after a specific term
4 to exit
4
thankyou for entering polynomial 2
Enter 1 to add the two polynomials
2 to multiply two polynomials
3 to exit
4 to find the degree of the polynomials
5 to evaluate the polynomial
6 to simplify the polynomial
1
The sum is
(10 x^2)+(12 x^7)+(12 x^3)Enter 1 to add the two polynomials
2 to multiply two polynomials
3 to exit
4 to find the degree of the polynomials
5 to evaluate the polynomial
6 to simplify the polynomial
2
The product is
(25 x^4)+(60 x^9)+(60 x^5)+(36 x^14)+(72 x^10)+(36 x^6)
Enter 1 to add the two polynomials
2 to multiply two polynomials
3 to exit
4 to find the degree of the polynomials
5 to evaluate the polynomial
6 to simplify the polynomial
4
The degree of the polynomial is 7
The degree of the polynomial is 7
Enter 1 to add the two polynomials
2 to multiply two polynomials
3 to exit
4 to find the degree of the polynomials
5 to evaluate the polynomial
6 to simplify the polynomial
5
Enter a value of x,for which you want to evaluate the polynomial1
Enter a value of x,for which you want to evaluate the polynomial1
The first polynomial when evaluated gives 17 while the second polynomial gives 17
Enter 1 to add the two polynomials
2 to multiply two polynomials
3 to exit
4 to find the degree of the polynomials
5 to evaluate the polynomial
6 to simplify the polynomial
6
The polynomial1 when simplified becomes
(5 x^2)+(6 x^7)+(6 x^3)The polynomial2 when simplified becomes
(5 x^2)+(6 x^7)+(6 x^3)Enter 1 to add the two polynomials
2 to multiply two polynomials
3 to exit
4 to find the degree of the polynomials
5 to evaluate the polynomial
6 to simplify the polynomial
3
thankyou

*/







































































































































































































































































































































































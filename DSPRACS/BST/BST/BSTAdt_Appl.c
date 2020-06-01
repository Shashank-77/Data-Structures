#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BSTAdt_If.h"
#include"BSTAdt_Impl.h"

void input(Player *p){
	printf("Enter Name: ");
	scanf(" %[^\n]", p->name);
}



void main(){
	node * root=NULL; int k=9;
	printf("1.------------MENU--\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. Exit\nEnter the choice: ");
	scanf("%d", &k);	
	while(k!=7){	
		if(k==1){
			Player* temp=(Player *)malloc(sizeof(Player));
			input(temp);
			root=insert(root,temp);
		
		}
		else if(k==2){
			Player temp;
			printf("Enter Name: ");
			scanf(" %[^\n]", temp.name);
			root=deleteNode(root,temp);
		}
		else if(k==3){
			Player temp;
			printf("Enter Name: ");
			scanf(" %[^\n]", temp.name);
			node * t=search(root,temp);
			output(t->key);
		
		}	
		else if(k==4){
			inorder(root);
		}
	
		else if(k==5){
			preorder(root);
		}
		else if(k==6){
			postorder(root);
		}
		else if(k==7){
			exit(0);
		}
		else{
			printf("Invalid input entered! ");
		}
		printf("\n--------------------\nEnter the choice: ");
		scanf("%d", &k);
	}	
	
}

/*
Output:
1.------------MENU--
1. Insert
2. Delete
3. Search
4. Inorder
5. Preorder
6. Postorder
7. Exit
Enter the choice: 1
Enter Name: HELLO

--------------------
Enter the choice: 1
Enter Name: VISHNU

--------------------
Enter the choice: 1
Enter Name: BAVA

--------------------
Enter the choice: 1
Enter Name: VVV

--------------------
Enter the choice: 1
Enter Name: SOMALIA

--------------------
Enter the choice: 1
Enter Name: PRIYA

--------------------
Enter the choice: 4
BAVA
HELLO
PRIYA
SOMALIA
VISHNU
VVV

--------------------
Enter the choice: 5
HELLO
BAVA
VISHNU
SOMALIA
PRIYA
VVV

--------------------
Enter the choice: 6
BAVA
PRIYA
SOMALIA
VVV
VISHNU
HELLO

--------------------
Enter the choice: 2
Enter Name: VISHNU

--------------------
Enter the choice: 4
BAVA
HELLO
PRIYA
SOMALIA
VVV
*/

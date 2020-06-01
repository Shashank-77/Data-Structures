#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	int num;
	int mat[100][100];
	char cityarr[100][20];
	int dikstra[100][4];
}cityADT;
void create(cityADT *C);
void disp(cityADT *C);
int findSource(cityADT *C,char source[]);
void dikstralgo(cityADT *C, int source);
void displayPath(cityADT *C,int  source,int destination) ;
void initdikstra(cityADT *C);
void displaydikstra(cityADT *C);

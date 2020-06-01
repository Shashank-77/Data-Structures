#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	int num;
	int mat[100][100];
	char cityarr[100][20];
}cityADT;
void create(cityADT *C);
void disp(cityADT *C);
void DFSpath(cityADT *C,int x,int d);
int findSource(cityADT *C,char source[]);
void DFS(cityADT *C,int x);
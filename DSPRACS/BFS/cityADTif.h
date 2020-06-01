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
void BFS(cityADT *C,char start[20]);
int unvisited(int v[],cityADT *C,int x);
int connect(cityADT *C,char source[20],char dest[20]);
int sourceIndex(cityADT *C,char source[]);
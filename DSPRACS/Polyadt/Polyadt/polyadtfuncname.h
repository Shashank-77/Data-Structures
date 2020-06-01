typedef struct 
{
	int val,exp;
}term;

typedef struct polyADT
{
	term t;
	struct polyADT *next;
}polyADT;


void insertFront(polyADT *p,term t);

void insertEnd(polyADT *p,term t);

void insertAfterTerm(polyADT *p, term t, int exp);

polyADT *polyAdd(polyADT *p1, polyADT *p2);
 
polyADT *polyMul(polyADT *p1, polyADT *p2);

void polyDegree(polyADT  *p);

int polyEvaluate(polyADT  *p);

polyADT* polySimplify(polyADT  *p);




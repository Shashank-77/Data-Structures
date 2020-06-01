
/*typedef struct Person
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
*/
void insertfront(nameadt *n, Person p);

void insertEnd(nameadt *n, Person p);

void insertPin(nameadt *n, Person p, int pin);

void SeniorPerson(nameadt *n);

void locatePerson(nameadt *n, char add[]);
  
void sort(nameadt *n);

void display(nameadt *n);

void ratio(nameadt *n);

//structure definitions
typedef struct
{
	int regNo;
	char name[15];
	float marks1,marks2,marks3,total;
	char result;
}student;

typedef struct
{
	student list[100];
	int size;
}studArr;

//function declarations

student getinput();//functino to get student data input
void insertFront(studArr *listADT1,student s);//function to insert a student record to the beginning
void insertEnd(studArr *listADT1,student s);//function to insert a student record at the end
void insertRegNo(studArr *listADT1,student s,int regNum);//function to insert a student record after a register number is found
student searchRegNo(studArr *listADT1,int regNum);//returns records with matching register number
void display(studArr *listADT1);//displays all records
void del(studArr *listADT1, int regNum);//deletes a record
void computeResult(studArr *listADT1);//calculates results for each student
int listClass(studArr *listADT1);//returns the number of students that passed with first class
studArr *searchName(studArr *listADT1, char name[]);//searches for a name and lists all records with the same name
studArr *listResult(studArr *listADT1);//lists all students that have passed
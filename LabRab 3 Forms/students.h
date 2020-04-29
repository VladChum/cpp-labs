//---------------------------------------------------------------------------

#ifndef studentsH
#define studentsH
//---------------------------------------------------------------------------
using namespace std;

class students
{
public:
	char name[20];
	char lastname[20];
	char fathername[20];
	int grupp;
	double maks;
	int income;       //доход

	students(){}
	students(AnsiString mname, AnsiString lname, AnsiString fname, int mgrupp, double mmaks, int mincome);

	AnsiString ShowStudents();
};
#endif

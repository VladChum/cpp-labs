//---------------------------------------------------------------------------

#pragma hdrstop
#include <time.h>
#include <vcl.h>
#include "students.h"
//---------------------------------------------------------------------------

students::students(AnsiString mname, AnsiString lname, AnsiString fname, int mgrupp, double mmaks, int mincome)
{
	strcpy(name, mname.c_str());
	strcpy(lastname, lname.c_str());
	strcpy(fathername, fname.c_str());
	grupp = mgrupp;
	maks = mmaks;
	income = mincome;
}



AnsiString students::ShowStudents()
{
	return   AnsiString(lastname) + ' ' + AnsiString(name) + ' ' + grupp;
}

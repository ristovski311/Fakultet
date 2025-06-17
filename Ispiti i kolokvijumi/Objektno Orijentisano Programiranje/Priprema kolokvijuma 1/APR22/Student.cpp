#include "Student.h"

Student::Student(int ind, double lab, double usm)
{
	indeks = ind;
	if (lab >= 0 && lab <= 20)
	{
		bodoviLab = lab;
	}
	else
		bodoviLab = 0;
	if (usm >= 0 && usm <= 40)
	{
		bodoviUsmeni = usm;
	}
	else
		bodoviUsmeni = 0;

}

Student::~Student()
{

}

ostream& Student::ispisi(ostream& o)
{
	o << "Indeks: " << indeks << endl;
	o << "Bodovi na laboratorijskim: " << bodoviLab << endl;
	o << "Bodovi na usmenom: " << bodoviUsmeni << endl;
	return o;
}
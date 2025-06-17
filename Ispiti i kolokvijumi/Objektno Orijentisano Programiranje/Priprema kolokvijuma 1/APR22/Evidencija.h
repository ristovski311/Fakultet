#pragma once
#include "Student.h"
#include <iostream>
using namespace std;

class Evidencija
{
public:
	Evidencija(int max);
	~Evidencija();
	void dodajStudenta(Student* s);
	void ukloniStudenta(int ind);
	ostream& spisak(ostream& o);
	Student* najvisePisani();
	Student* najviseCeo();
	int polozili();
	double prosecnoBodovaPolozili();
	void promeniBodoveStudentu(int ind, double dodatak);
private:
	int maxStudenata;
	int trenutnoIma;
	Student** lista;
};


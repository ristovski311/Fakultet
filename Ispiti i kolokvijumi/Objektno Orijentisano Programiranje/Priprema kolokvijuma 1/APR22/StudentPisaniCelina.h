#pragma once
#include "Student.h"
class StudentPisaniCelina : public Student
{
public:
	StudentPisaniCelina(int ind, double bodlab, double bodusm, double bodpis);
	~StudentPisaniCelina();
	ostream& ispisi(ostream& o);
	double ukupnoBodova()
	{
		return bodoviUsmeni + bodoviPisani + bodoviLab;
	}
	bool polozio();
	void promeniBodove(double dodatni);
	double ukupnoPisani()
	{
		return bodoviPisani;
	}
	friend ostream& operator<<(ostream& o, StudentPisaniCelina& s)
	{
		s.ispisi(o);
		return o;
	}
private:
	double bodoviPisani;

};


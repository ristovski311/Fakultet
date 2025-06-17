#pragma once
#include "Student.h"
class StudentPisaniKol : public Student
{
public:
	StudentPisaniKol(int ind, double bodlab, double bodusm, double prvikol, double drugikol);
	~StudentPisaniKol();
	ostream& ispisi(ostream& o);
	double ukupnoBodova()
	{
		return bodoviUsmeni + bodoviLab + bodoviDrugiKol + bodoviPrviKol;
	}
	bool polozio();
	void promeniBodove(double dodatni);
	double ukupnoPisani()
	{
		return bodoviPrviKol + bodoviDrugiKol;
	}
	friend ostream& operator<<(ostream& o, StudentPisaniKol& s)
	{
		s.ispisi(o);
		return o;
	}
private:
	double bodoviPrviKol;
	double bodoviDrugiKol;
};


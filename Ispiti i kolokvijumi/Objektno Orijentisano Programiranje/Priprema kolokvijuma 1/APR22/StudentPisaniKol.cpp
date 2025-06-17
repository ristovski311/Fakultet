#include "StudentPisaniKol.h"

StudentPisaniKol::StudentPisaniKol(int ind, double lab, double usm, double kol1, double kol2)
	:Student(ind, lab, usm)
{
	if (kol1 >= 0 && kol1 <= 20)
	{
		bodoviPrviKol = kol1;
	}
	else
		bodoviPrviKol = 0;
	if (kol2 >= 0 && kol2 <= 20)
	{
		bodoviDrugiKol = kol2;
	}
	else
		bodoviDrugiKol = 0;
}
StudentPisaniKol::~StudentPisaniKol() {}

ostream& StudentPisaniKol::ispisi(ostream& o)
{
	this->Student::ispisi(o);
	o << "Prvi kolokvijum bodovi: " << bodoviPrviKol << endl;
	o << "Drugi kolokvijum bodovi: " << bodoviDrugiKol << endl;
	return o;
}

bool StudentPisaniKol::polozio()
{
	return (bodoviUsmeni > 20 && this->ukupnoBodova() > 50 && (bodoviDrugiKol > 5) && (bodoviPrviKol > 5)
		&& (bodoviDrugiKol + bodoviPrviKol) > 20);
}

void StudentPisaniKol::promeniBodove(double dodatak)
{
	
	this->bodoviPrviKol = (this->bodoviPrviKol + dodatak) > 20 ? 20 : this->bodoviPrviKol + dodatak;
}
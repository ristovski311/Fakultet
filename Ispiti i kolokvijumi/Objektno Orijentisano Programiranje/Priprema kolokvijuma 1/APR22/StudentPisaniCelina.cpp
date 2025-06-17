#include "StudentPisaniCelina.h"

StudentPisaniCelina::StudentPisaniCelina(int ind, double lab, double usm, double pis) : Student(ind, lab, usm)
{
	if (pis >= 0 && pis <= 40)
	{
		bodoviPisani = pis;
	}
	else
		bodoviPisani = 0;
}
StudentPisaniCelina::~StudentPisaniCelina() {}

ostream& StudentPisaniCelina::ispisi(ostream& o)
{
	this->Student::ispisi(o);
	o << "Bodovi na pisanom u celini: " << bodoviPisani << endl;
	return o;
}

bool StudentPisaniCelina::polozio()
{
	return (bodoviUsmeni >= 20 && bodoviPisani >= 20 && this->ukupnoBodova() >= 50);
}

void StudentPisaniCelina::promeniBodove(double bodovi)
{
	this->bodoviPisani = (this->bodoviPisani + bodovi) > 20 ? 20 : this->bodoviPisani + bodovi;
}
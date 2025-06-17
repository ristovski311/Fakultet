#include "Artikal.h"

Artikal::Artikal() : naziv("prazan artikal"), cena(-1) {}

Artikal::Artikal(string naziv1, double cena1) :
	naziv(naziv1), cena(cena1) {}

void Artikal::showDescription()
{
	cout << "Naziv: " << this->getName() << endl;
	cout << "Cena: " << this->getPrice() << endl;
}

ostream& Artikal::print(ostream& o)
{
	o << "Naziv: " << this->getName() << endl;
	o << "Cena: " << this->getPrice() << endl;
	return o;
}

ostream& operator<<(ostream& izlaz, Artikal& a)
{
	return a.print(izlaz);
}

istream& Artikal::upis(istream& u)
{
	u >> this->naziv;
	u >> this->cena;
	return u;
}

istream& operator>>(istream& ulaz, Artikal& a)
{
	a.upis(ulaz);
	return ulaz;
}
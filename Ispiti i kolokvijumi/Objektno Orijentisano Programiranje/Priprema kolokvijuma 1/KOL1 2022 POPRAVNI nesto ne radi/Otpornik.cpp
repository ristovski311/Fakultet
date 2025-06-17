#include "Otpornik.h"

Otpornik::Otpornik(const char* kod, float otp, float mint, float maxt) : Proizvod(kod)
{
	this->otpornost = otp;
	this->minTemp = mint;
	this->maxTemp = maxt;
}

Otpornik::~Otpornik() {}

ostream& Otpornik::ispis(ostream& o)
{
	o << "Barkod kondenzatora: " << barkod << endl;
	o << "Otpornost: " << otpornost << endl;
	o << "Min operativna temp: " << minTemp << "| Max operativna temp: " << maxTemp << endl;
	o << "Defektan: ";
	if (otpornost == 0)
		o << "Da.\n";
	else
		o << "Ne.\n";

	return o;
}
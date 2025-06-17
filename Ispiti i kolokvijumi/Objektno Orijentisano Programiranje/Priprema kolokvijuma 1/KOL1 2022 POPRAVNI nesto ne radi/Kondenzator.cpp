#include "Kondenzator.h"

Kondenzator::Kondenzator(const char* kod, float kapac) : Proizvod(kod)
{
	this->kapacitivnost = kapac;
}

Kondenzator::~Kondenzator(){}

ostream& Kondenzator::ispis(ostream& o)
{
	o << "Barkod kondenzatora: " << barkod << endl;
	o << "Kapacitivnost: " << kapacitivnost << endl;
	o << "Defektan: ";
	if (kapacitivnost == 0)
		o << "Da.\n";
	else
		o << "Ne.\n";

	return o;
}
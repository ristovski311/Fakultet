#include "Kupovina.h"

Kupovina::Kupovina(const char* kod1, int sifra1, int dan, double osn, double pop)
{
	kod = new char[strlen(kod1) + 1];
	strcpy(kod, kod1);
	sifra = sifra1;
	redBrDana = dan;
	osnovnaCena = osn;
	popust = pop;
}

Kupovina::~Kupovina()
{
	if (kod != nullptr)
		delete[] kod;
	kod = nullptr;
}

ostream& Kupovina::ispisi(ostream& o)
{
	o << "Kod: " << kod << endl;
	o << "Sifra: " << sifra << endl;
	o << "Dan od 1.1.2000.:  " << redBrDana << endl;
	o << "Osnovna cena: " << osnovnaCena << endl;
	o << "Popust: " << popust << endl;
	o << "Cena: " << this->cena() << endl;
	return o;
}
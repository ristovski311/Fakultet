#include "PaketicHrana.h"


PaketicHrana::PaketicHrana(const char* boja, const char* adresa, int brcokolada, double tezina, double cena)
	: Paketic(boja, adresa)
{
	this->brojCokolada = brcokolada;
	this->tezinaCokolada = tezina;
	this->cenaPoJediniciTezine = cena;
}

PaketicHrana::~PaketicHrana(){}

ostream& PaketicHrana::Ispis(ostream& o)
{
	o << "Adresa: " << adresa << endl;
	o << "Boja: " << boja << endl;
	o << "Broj cokolada: " << brojCokolada << endl;
	o << "Tezina cokolada: " << tezinaCokolada << endl;
	o << "Cena cokolada: " << cenaPoJediniciTezine << endl;
	return o;

}

double PaketicHrana::cena()
{
	return ((double)brojCokolada * tezinaCokolada) * cenaPoJediniciTezine;
}

double PaketicHrana::tezina()
{
	return (double)brojCokolada * tezinaCokolada;
}
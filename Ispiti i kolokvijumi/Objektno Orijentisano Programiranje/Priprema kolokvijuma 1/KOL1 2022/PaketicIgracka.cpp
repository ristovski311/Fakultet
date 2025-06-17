#include "PaketicIgracka.h"

PaketicIgracka::PaketicIgracka(const char* boja, const char* adresa, int brautica, double tezina, double cena)
	: Paketic(boja, adresa)
{
	this->brojAutica = brautica;
	this->tezinaJednogAutica = tezina;
	this->cenaJednogAutica = cena;
}

PaketicIgracka::~PaketicIgracka(){}

ostream& PaketicIgracka::Ispis(ostream& o)
{
	o << "Adresa: " << adresa << endl;
	o << "Boja: " << boja << endl;
	o << "Broj autica: " << brojAutica << endl;
	o << "Tezina autica: " << tezinaJednogAutica << endl;
	o << "Cena autica: " << cenaJednogAutica << endl;
	return o;

}

double PaketicIgracka::cena()
{
	return (double)brojAutica * cenaJednogAutica;
}

double PaketicIgracka::tezina()
{
	return (double)brojAutica * tezinaJednogAutica;
}
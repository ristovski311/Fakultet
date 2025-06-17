#pragma once
#include "Paketic.h"
class PaketicIgracka : public Paketic
{
public:
	PaketicIgracka(const char* boja, const char* adresa, int brautica, double tezina, double cena);
	~PaketicIgracka();
	ostream& Ispis(ostream& o);
	double cena();
	double tezina();
private:
	int brojAutica;
	double tezinaJednogAutica;
	double cenaJednogAutica;
};



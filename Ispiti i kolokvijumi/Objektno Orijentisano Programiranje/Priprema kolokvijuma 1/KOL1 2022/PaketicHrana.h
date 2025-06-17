#pragma once
#include "Paketic.h"
class PaketicHrana : public Paketic
{
public:
	PaketicHrana(const char* boja, const char* adresa, int brcokolada, double tezina, double cena);
	~PaketicHrana();
	ostream& Ispis(ostream& o);
	double cena();
	double tezina();
private:
	int brojCokolada;
	double tezinaCokolada;
	double cenaPoJediniciTezine;
};


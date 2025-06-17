#pragma once
#include "Kupovina.h"
class Evidencija
{
public:
	Evidencija(int max);
	~Evidencija();
	void dodaj(Kupovina* k);
	void brisi(const char* kod);
	ostream& spisak(ostream& o);
	Kupovina* najskuplja();
	Kupovina* najjeftinija();
	int brojKupovina(int sifrap, int poc, int kraj);
	double ukupnaCena(int poc, int kraj);
	double dugovanje(int poc, int kraj);
private:
	Kupovina** kolekcija;
	int maxKupovina;
	int trenutnoKupovina;
};


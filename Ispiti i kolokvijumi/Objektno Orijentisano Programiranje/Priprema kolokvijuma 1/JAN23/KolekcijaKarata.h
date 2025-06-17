#pragma once
#include "DnevnaKarta.h"
class KolekcijaKarata
{
public:
	KolekcijaKarata(int n);
	void kupiKartu(DnevnaKarta* k);
	void ponistiKartu(int id);
	DnevnaKarta& vratiNajkracu();
	DnevnaKarta& vratiNajduzu();
	int brojVazecih(int redBrDana, const char* tip);
	double zarada();
	ostream& spisak(ostream& o);
private:
	int duzina;
	int popunjenost;
	DnevnaKarta** karte;
};


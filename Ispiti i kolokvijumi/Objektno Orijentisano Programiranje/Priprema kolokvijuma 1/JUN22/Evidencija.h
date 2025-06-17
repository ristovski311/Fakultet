#pragma once
#include "Ucesnik.h"
#include <iostream>
using namespace std;
class Evidencija
{
public:
	Evidencija(int n);
	~Evidencija();
	void dodaj(Ucesnik* u);
	void brisi(int redbr);
	double srednjaVrednostPlasiranih();
	Evidencija& sortiraj();
	Ucesnik* najveciBrojPoena();
	ostream& evidentiraj(ostream& o);

private:
	int maxUcesnika;
	int trenutnoUcesnika;
	Ucesnik** lista;
};


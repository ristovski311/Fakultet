#pragma once
#include "Kupovina.h"
class KupovinaOdmah : public Kupovina
{
public:
	KupovinaOdmah(const char* kod1, int sifra1, int dan, double osn, double pop)
		: Kupovina(kod1, sifra1, dan, osn, pop) {}
	~KupovinaOdmah() {}
	double cena()
	{
		return osnovnaCena - popust;
	}
	ostream& ispisi(ostream& o);
	double duguje()
	{
		return 0;
	}

};


#pragma once
#include "Kupovina.h"
class KupovinaRate : public Kupovina
{
public:
	KupovinaRate(const char* kod1, int sifra1, int dan, double osn, double pop,
		double novac, int rate, int period, int placenerate);
	~KupovinaRate();
	double cena()
	{
		return osnovnaCena;
	}
	ostream& ispisi(ostream& o);
	double duguje()
	{
		return this->cena() - novacPriKupovini - ((this->cena() - novacPriKupovini) / (double)brojRata * (double)placeneRate);
	}

private:
	double novacPriKupovini;
	int brojRata;
	int periodIzmedjuRata;
	int placeneRate;
};


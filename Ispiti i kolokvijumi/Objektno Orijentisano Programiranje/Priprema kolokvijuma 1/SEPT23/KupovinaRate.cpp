#include "KupovinaRate.h"

KupovinaRate::KupovinaRate(const char* kod1, int sifra1, int dan, double osn, double pop,
	double novac, int rate, int period, int placenerate)
	: Kupovina(kod1, sifra1, dan, osn, pop)
{
	novacPriKupovini = novac;
	brojRata = rate;
	periodIzmedjuRata = period;
	placeneRate = placenerate;
}

KupovinaRate::~KupovinaRate() {}

ostream& KupovinaRate::ispisi(ostream& o)
{
	this->Kupovina::ispisi(o);
	return o;
}

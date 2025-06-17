#include "Put.h"

Put::Put(const char* gr, int max, int brnoci, double cenaponoci)
{
	grad = gr;
	maxBrPutnika = max;
	brNocenja = brnoci;
	cenaPoNocenju = cenaponoci;
}

Put::~Put()
{
	//delete grad;
	//grad = nullptr;
}

double Put::cenaSmestaja()
{
	return (double)brNocenja * cenaPoNocenju;
}

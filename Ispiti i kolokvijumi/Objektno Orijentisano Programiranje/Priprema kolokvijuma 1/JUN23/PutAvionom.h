#pragma once
#include "Put.h"
class PutAvionom : public Put
{
public:
	PutAvionom(const char* gr, int max, int brnoci, double cenaponocenju, const char* komp, double duzinaleta, double cenampp);
	~PutAvionom();
	double cenaZaAgenciju();
	double cenaPutaPoPutniku();
	virtual ostream& IspisPuta(ostream&);
	virtual istream& UpisUPut(istream&);
private:
	const char* kompanija;
	double duzinaLeta;
	double cenaMestaPoPutniku;
};


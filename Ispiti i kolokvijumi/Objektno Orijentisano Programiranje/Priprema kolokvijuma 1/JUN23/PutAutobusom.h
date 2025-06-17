#pragma once
#include "Put.h"
class PutAutobusom : public Put
{
public:
	PutAutobusom(const char* gr, int max, int brnoci, double cenaponoci, double km, double cenapol, double potrosnja, int nociuautob);
	~PutAutobusom();
	double cenaZaAgenciju();
	double cenaPutaPoPutniku();
	virtual ostream& IspisPuta(ostream&);
	virtual istream& UpisUPut(istream&);
private:
	double km;
	double cenaGorivaPoLitru;
	double potrosnjaGorivaNa100km;
	int brNociUAutobusu;
};


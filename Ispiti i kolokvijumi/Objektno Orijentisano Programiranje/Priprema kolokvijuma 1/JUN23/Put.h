#pragma once
#include <iostream>
using namespace std;
class Put
{
public:
	Put(const char* gr, int max, int brnoci, double cenaponocenju);
	virtual ~Put();
	virtual int getPutnika() { return maxBrPutnika; }
	virtual const char* getGrad() { return grad; }
	double cenaSmestaja();
	virtual double cenaZaAgenciju() = 0;
	double virtual cenaPutaPoPutniku() = 0;
	virtual ostream& IspisPuta(ostream&) = 0;
	virtual istream& UpisUPut(istream&) = 0;
protected:
	const char* grad;
	int maxBrPutnika;
	int brNocenja;
	double cenaPoNocenju;
};


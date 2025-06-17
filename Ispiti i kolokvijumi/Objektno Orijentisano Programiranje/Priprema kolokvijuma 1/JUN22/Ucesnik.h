#pragma once
#include <iostream>
using namespace std;
class Ucesnik
{
public:
	Ucesnik(int redbr, const char* ime1, const char* prezime1, double poeni1);
	virtual ~Ucesnik();
	virtual bool prosao() = 0;
	virtual double ukupnoPoena() = 0;
	virtual int pomocnoOsoblje() = 0;
	virtual ostream& ispis(ostream& o);
	virtual int getRedBr() { return redniBr; }
protected:
	int redniBr;
	char* ime;
	char* prezime;
	double poeniPublike;
};


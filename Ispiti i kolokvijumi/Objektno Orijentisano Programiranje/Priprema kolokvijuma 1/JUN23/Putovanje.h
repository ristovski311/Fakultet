#pragma once
#include "Put.h"
#include <iostream>
using namespace std;
class Putovanje
{
public:
	Putovanje(int max, const char* datum);
	~Putovanje();
	double cenaZaAgenciju();
	double cenaPoPutniku();
	void dodajPut(Put* put);
	void obrisiPut(const char* grad);
	ostream& IspisPutovanja(ostream& o);
	istream& UpisPutovanja(istream& i);
private:
	Put** lista;
	int trenutnoPuteva;
	int planiranoPutnika;
	const char* datum;
};


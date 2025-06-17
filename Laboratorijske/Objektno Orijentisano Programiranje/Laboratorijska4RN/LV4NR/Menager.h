#pragma once
#include "Radnik.h"

class Menager : public Radnik
{
public:
	Menager();
	Menager(int jmbg, int godinaZaposljenja, double osnovicaPlate,
		int godinaStarosti, const char* ime_prezime, const string& tip);
	virtual double OdrediPlatu();
	friend istream& operator>>(istream& i, Menager& m);
	virtual void Prikazi();
	virtual istream& Upisi(istream& i);
private:
	string tip;
};


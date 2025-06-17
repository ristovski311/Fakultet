#pragma once
#include "Radnik.h"
class Developer : public Radnik
{
public:
	Developer();
	Developer(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime, const string& tip, int prekovr);
	virtual double OdrediPlatu();
	friend istream& operator>>(istream& i, Developer& d);
	virtual void Prikazi();
	virtual istream& Upisi(istream& i);
private:
	string tip;
	int prekovremeni_sati;
};


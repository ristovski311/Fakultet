#pragma once
#include "Ucesnik.h"
class Glumac : public Ucesnik
{
public:
	Glumac(int redbr, const char* ime1, const char* prezime1, double poeni1, int brrek, double ideja, double izv);
	~Glumac();
	ostream& ispis(ostream& o);
	bool prosao();
	double ukupnoPoena();
	int pomocnoOsoblje();
private:
	int brRekvizita;
	double poeniIdeja;
	double poeniIzvodjenje;
};



#pragma once
#include "Ucesnik.h"
class Pevac : public Ucesnik
{
public:
	Pevac(int redbr, const char* ime1, const char* prezime1, double poeni1, 
		const char* pesma1, int instr, int vokali, double ziri);
	~Pevac();
	ostream& ispis(ostream& o);
	bool prosao();
	double ukupnoPoena();
	int pomocnoOsoblje();
private:
	char* pesma;
	int brojInstrumenata;
	int brojVokala;
	double poeniZirija;
};


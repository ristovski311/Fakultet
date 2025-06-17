#include "Pevac.h"

Pevac::Pevac(int redbr, const char* ime1, const char* prezime1, double poeni1,
	const char* pesma1, int instr, int vokali, double ziri) : Ucesnik(redbr, ime1, prezime1, poeni1)
{
	pesma = new char[strlen(pesma1) + 1];
	strcpy(pesma, pesma1);
	brojInstrumenata = instr;
	brojVokala = vokali;
	if (ziri >= 0 && ziri <= 100)
		poeniZirija = ziri;
	else
	{
		cout << "Greska u poenima zirija!\n";
		return;
	}
}
 
Pevac::~Pevac()
{
	if (pesma != nullptr)
		delete[] pesma;
	pesma = nullptr;
}

ostream& Pevac::ispis(ostream& o)
{
	this->Ucesnik::ispis(o);
	o << "Pesma: " << pesma << endl;
	o << "Broj pratecih instrumenata: " << brojInstrumenata << endl;
	o << "Broj pratecih vokala: " << brojVokala << endl;
	o << "Poeni muzickog zirija: " << poeniZirija << endl;
	return o;
}

bool Pevac::prosao()
{
	return (poeniZirija >= 50) && (this->ukupnoPoena() > 100);
}
double Pevac::ukupnoPoena()
{
	return poeniPublike + poeniZirija;
}
int Pevac::pomocnoOsoblje()
{
	return brojInstrumenata + brojVokala;
}
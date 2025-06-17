#include "Glumac.h"

Glumac::Glumac(int redbr, const char* ime1, const char* prezime1, double poeni1,
	int brrek, double ideja, double izv) : Ucesnik(redbr, ime1, prezime1, poeni1)
{
	brRekvizita = brrek;
	if(ideja <= 100 && ideja >= 0)
	{
		poeniIdeja = ideja;
	}
	else
	{
		cout << "Greska u poenima za ideju!\n";
		return;
	}
	if (izv <= 100 && izv >= 0)
	{
		poeniIzvodjenje = izv;
	}
	else
	{
		cout << "Greska u poenima za izvodjenje!\n";
		return;
	}
}

Glumac::~Glumac() {}

ostream& Glumac::ispis(ostream& o)
{
	this->Ucesnik::ispis(o);
	o << "Broj rekvizita: " << brRekvizita << endl;
	o << "Poeni za ideju: " << poeniIdeja << endl;
	o << "Poeni za izvodjenje: " << poeniIzvodjenje << endl;
	return o;
}

bool Glumac::prosao()
{
	return (poeniIdeja >= 25) && (poeniIzvodjenje >= 25) && (this->ukupnoPoena() > 100);
}
double Glumac::ukupnoPoena()
{
	return poeniPublike + poeniIdeja + poeniIzvodjenje;
}
int Glumac::pomocnoOsoblje()
{
	return brRekvizita / 2;
}
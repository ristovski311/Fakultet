#include "Ucesnik.h"

Ucesnik::Ucesnik(int redbr, const char* ime1, const char* prezime1, double poeni1)
{
	redniBr = redbr;
	if (poeni1 >= 0 && poeni1 <= 100)
	{
		poeniPublike = poeni1;
	}
	else
	{
		cout << "Greska u poenima!\n";
		return;
	}
	ime = new char[strlen(ime1) + 1];
	strcpy(ime, ime1);
	prezime = new char[strlen(prezime1) + 1];
	strcpy(prezime, prezime1);
}
Ucesnik::~Ucesnik()
{
	if (ime != nullptr)
		delete[] ime;
	ime = nullptr;
	if (prezime != nullptr)
		delete[] prezime;
	prezime = nullptr;
}

ostream& Ucesnik::ispis(ostream& o)
{
	o << "Redni broj: " << redniBr << endl;
	o << "Ime: " << ime << endl;
	o << "Prezime: " << prezime << endl;
	o << "Poeni publike: " << poeniPublike << endl;
	return o;
}
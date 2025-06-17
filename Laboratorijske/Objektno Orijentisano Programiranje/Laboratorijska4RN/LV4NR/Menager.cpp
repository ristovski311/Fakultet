#include "Menager.h"
#include <iostream>

Menager::Menager() : Radnik()
{
	this->tip = "neodredjeni";
}

Menager::Menager(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime1, const string& tip)
	: Radnik(jmbg, godinaZaposljenja, osnovicaPlate,
		godinaStarosti, ime_prezime1), tip(tip) {}

double Menager::OdrediPlatu()
{
	return 30 * this->osnovicaPlate + 100 * this->godinaZaposljenja;
}

istream& Menager::Upisi(istream& i)
{
	this->Radnik::Upisi(i);
	i >> this->tip;
	return i;
}

istream& operator>>(istream& i, Menager& m)
{
	return m.Upisi(i);
}

void Menager::Prikazi()
{
	cout << "Ime i prezime: " << this->ime_prezime << endl;
	cout << "Jmbg: " << this->jmbg << endl;
	cout << "Godina: " << this->godinaStarosti << endl;
	cout << "Godina zaposljenja: " << this->godinaZaposljenja << endl;
	cout << "Tip: " << this->tip << endl;
	cout << "Osnovica plate: " << this->osnovicaPlate << endl;
	cout << "Plata: " << this->OdrediPlatu() << endl << endl;
}
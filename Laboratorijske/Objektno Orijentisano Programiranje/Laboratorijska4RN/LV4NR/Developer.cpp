#include "Developer.h"
#include <iostream>
Developer::Developer() : Radnik()
{
	this->tip = "neodredjeni";
	this->prekovremeni_sati = 0;
}

Developer::Developer(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime1,
	const string& tip, int prekovr) : Radnik( jmbg,  godinaZaposljenja,  osnovicaPlate,
		 godinaStarosti,ime_prezime1)
{
	this->tip = tip;
	this->prekovremeni_sati = prekovr;
}

double Developer::OdrediPlatu()
{
	return 25 * this->osnovicaPlate + 150 * this->godinaZaposljenja + 1000 * prekovremeni_sati;
}

istream& Developer::Upisi(istream& i)
{
	this->Radnik::Upisi(i);
	i >> this->tip;
	i >> this->prekovremeni_sati;
	return i;
}

istream& operator>>(istream& i, Developer& d)
{
	return d.Upisi(i);
}

void Developer::Prikazi()
{
	cout << "Ime i prezime: " << this->ime_prezime << endl;
	cout << "Jmbg: " << this->jmbg << endl;
	cout << "Godina: " << this->godinaStarosti << endl;
	cout << "Godina zaposljenja: " << this->godinaZaposljenja << endl;
	cout << "Tip: " << this->tip << endl;
	cout << "Osnovica plate: " << this->osnovicaPlate << endl;
	cout << "Plata: " << this->OdrediPlatu() << endl;
	cout << "Prekovremeni sati: " << this->prekovremeni_sati << endl << endl;
}

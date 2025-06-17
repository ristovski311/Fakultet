#include "Radnik.h"
#include <iostream>

Radnik::Radnik()
{
	this->jmbg = 0;
	this->godinaZaposljenja = 0;
	this->godinaStarosti = 0;
	this->osnovicaPlate = 0;
	this->ime_prezime = new char[100];
	this->ime_prezime[0] = 0;
}

Radnik::~Radnik()
{
	delete[] this->ime_prezime;
}

Radnik::Radnik(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime1)
{
	this->jmbg = jmbg;
	this->godinaZaposljenja = godinaZaposljenja;
	this->osnovicaPlate = osnovicaPlate;
	this->godinaStarosti = godinaStarosti;
	this->ime_prezime = new char[strlen(ime_prezime1) + 1];
	strcpy(this->ime_prezime, ime_prezime1);
}

void Radnik::operator++()
{
	this->osnovicaPlate = this->osnovicaPlate * 1.1;
}

void Radnik::operator--()
{
	this->osnovicaPlate = this->osnovicaPlate * 0.9;
}

bool Radnik::operator>(Radnik* r)
{
	return this->GetGodinaStarosti() > r->GetGodinaStarosti();
}

bool Radnik::operator<(Radnik* r)
{
	return this->GetGodinaStarosti() < r->GetGodinaStarosti();
}

bool Radnik::operator>=(Radnik* r)
{
	return this->GetGodinaStarosti() >= r->GetGodinaStarosti();
}

bool Radnik::operator<=(Radnik* r)
{
	return this->GetGodinaStarosti() <= r->GetGodinaStarosti();
}

bool Radnik::operator==(Radnik& r)
{
	return this->GetGodinaStarosti() == r.GetGodinaStarosti();
}

istream& Radnik::Upisi(istream& i)
{
	i >> this->ime_prezime;
	i >> this->jmbg;
	i >> this->godinaStarosti;
	i >> this->godinaZaposljenja;
	i >> this->osnovicaPlate;
	return i;
}

istream& operator>>(istream& i, Radnik& r)
{
	return r.Upisi(i);
}
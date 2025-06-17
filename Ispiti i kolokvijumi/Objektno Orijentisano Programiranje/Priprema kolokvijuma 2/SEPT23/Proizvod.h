#pragma once
#include <iostream>
using namespace std;
class Proizvod
{
public:
	Proizvod(const char* naziv1 = "", int meseci = 4, double cena1 = 10000, double kof = 1)
	{
		if (meseci < 3 || cena1 <= 10000)
			throw "Greska pri kreiranju proizvoda";
		this->naziv = new char[strlen(naziv1) + 1];
		strcpy(this->naziv, naziv1);
		this->meseciDoIstekaRoka = meseci;
		this->cena = cena1;
		this->koefPotraznje = kof;
	}
	Proizvod(const Proizvod& p)
	{
		delete[] this->naziv;
		this->naziv = new char[strlen(p.naziv) + 1];
		strcpy(this->naziv, p.naziv);
		this->meseciDoIstekaRoka = p.meseciDoIstekaRoka;
		this->cena = p.cena;
		this->koefPotraznje = p.koefPotraznje;
	}
	~Proizvod()
	{
		delete[] naziv;
	}
	double Vrednost()
	{
		return this->cena * koefPotraznje;
	}
	friend double operator+(double d, Proizvod& p);
	friend istream& operator>>(istream& i, Proizvod& p);
	friend ostream& operator<<(ostream& o, Proizvod& p);
private:
	char* naziv;
	int meseciDoIstekaRoka;
	double cena;
	double koefPotraznje;
};


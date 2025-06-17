#pragma once
#include <iostream>
using namespace std;
class Kupovina
{
public:
	Kupovina(const char* kod1, int sifra1, int dan, double osn, double pop);
	virtual ~Kupovina();
	virtual double cena() = 0;
	virtual const char* getKod() { return kod; }
	virtual int getSifra() { return sifra; }
	virtual ostream& ispisi(ostream& o);
	virtual double duguje() = 0;
	virtual int getDan() { return redBrDana; }
protected:
	char* kod;
	int sifra;
	int redBrDana;
	double osnovnaCena;
	double popust;
};


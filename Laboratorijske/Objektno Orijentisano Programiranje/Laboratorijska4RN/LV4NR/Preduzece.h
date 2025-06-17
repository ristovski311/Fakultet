#pragma once
#include "Radnik.h"

class Preduzece
{
public:
	Preduzece(const char* c, int max, double b);
	~Preduzece();
	Radnik** GetRadnici() { return this->radnici; }
	void SetBrEl(int a) { this->brojEl = a; }
	void Dodaj(Radnik* r, int godinaz);
	void Brisi(int jmbg);
	ostream& OPreduzecu(ostream& o);
	double ZaIsplatu();
	bool Rentabilna();
	void operator++();
	void operator--();
	Radnik** SortPoStarosti();
	friend ostream& operator<<(ostream& o, Preduzece& p);
	int GetBrEl() { return this->brojEl; }
private:
	char* naziv;
	double budzet;
	Radnik** radnici;
	int brojEl;
	int maxBrojEl;

};


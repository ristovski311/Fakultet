#pragma once
#include "Artikal.h"
class Torba : public Artikal
{
public:
	Torba();
	~Torba();
	Torba(string name, double cena, Artikal& a);
	void showDescription();
	void put(Artikal& a);
	void remove();
	friend ostream& operator<<(ostream& izlaz, Torba& torba);
	ostream& print(ostream& o);
	istream& upis(istream& u);
	friend istream& operator>>(istream& izlaz, Torba& t);
private:
	Artikal* sadrzaj;
};


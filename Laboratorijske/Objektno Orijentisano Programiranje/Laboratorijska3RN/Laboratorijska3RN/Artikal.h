#include <string>
#include <iostream>
#pragma once
using namespace std;
class Artikal
{
public:
	Artikal();
	virtual ~Artikal()
	{
		//cout << "Destruktor iz artikla\n"; 
	}
	Artikal(string naziv1, double cena1);
	virtual void showDescription();
	double getPrice()
	{
		return this->cena;
	}
	string getName()
	{
		return this->naziv;
	}
	virtual void put(Artikal& a) {};
	virtual ostream& print(ostream& o);
	friend ostream& operator<<(ostream& izlaz, Artikal& a);
	virtual istream& upis(istream& u);
	friend istream& operator>>(istream& izlaz, Artikal& a);
private:
	double cena;
	string naziv;
};


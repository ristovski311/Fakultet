#pragma once
#include "Artikal.h"
#include <string>
using namespace std;
class Laptop : public Artikal
{
public:
	Laptop();
	~Laptop();
	Laptop(string naziv1, double cena1, bool stanje1, char* opis1);
	void showDescription();
	void turnOn();
	void turnOff();
	ostream& print(ostream& o);
	friend ostream& operator<<(ostream& izlaz, Laptop& lap);
	istream& upis(istream& u);
	friend istream& operator>>(istream& izlaz, Laptop& l);
private:
	char* opis;
	bool stanje;
};


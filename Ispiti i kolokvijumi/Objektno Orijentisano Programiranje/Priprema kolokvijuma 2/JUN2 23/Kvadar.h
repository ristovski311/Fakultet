#pragma once
#include <iostream>
using namespace std;

class Kvadar
{
public:
	Kvadar(double x = 0, double z = 0, double y = 0, double r = 1);
	Kvadar(const Kvadar& k);
	Kvadar& operator=(const Kvadar& k);
	double Masa();
	bool operator>(Kvadar& k);
	friend double operator+(double d, Kvadar& k);
	friend istream& operator>>(istream& i, Kvadar& k);
	friend ostream& operator<<(ostream& o, Kvadar& k);
private:
	double duzina;
	double sirina;
	double visina;
	double gustina;
};


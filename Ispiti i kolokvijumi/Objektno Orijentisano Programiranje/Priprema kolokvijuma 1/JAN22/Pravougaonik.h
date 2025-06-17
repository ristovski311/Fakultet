#pragma once
#include "Figura.h"
class Pravougaonik : public Figura
{
public:
	Pravougaonik(double xx, double yy, double a, double b) : Figura(xx, yy), stranicaA(a), stranicaB(b) {}
	~Pravougaonik() {}
	ostream& upis(ostream& o)
	{
		o << "Koordinate centra: " << "(" << x << "," << y << ")." << endl;
		o << "Stranica a: " << stranicaA << endl;
		o << "Stranica b: " << stranicaB << endl;

		return o;
	}
	istream& ispis(istream& i)
	{
		i >> x;
		i >> y;
		i >> stranicaA;
		i >> stranicaB;
		return i;
	}
	double povrsina()
	{
		return stranicaA * stranicaB;
	}
	double obim()
	{
		return 2 * stranicaA + 2 * stranicaB;
	}
private:
	double stranicaA;
	double stranicaB;
};


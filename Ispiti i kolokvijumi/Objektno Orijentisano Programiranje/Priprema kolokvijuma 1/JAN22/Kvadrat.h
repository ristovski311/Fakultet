#pragma once
#include "Figura.h"
class Kvadrat : public Figura
{
public:
	Kvadrat(double xx, double yy, double a) : Figura(xx, yy), stranica(a) {}
	~Kvadrat(){}
	ostream& upis(ostream& o)
	{
		o << "Koordinate centra: " << "(" << x << "," << y << ")." << endl;
		o << "Stranica kvadrata: " << stranica << endl;
		return o;
	}
	istream& ispis(istream& i)
	{
		i >> x;
		i >> y;
		i >> stranica;
		return i;
	}
	double povrsina()
	{
		return stranica * stranica;
	}
	double obim()
	{
		return 4 * stranica;
	}
private:
	double stranica;
};


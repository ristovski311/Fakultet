#include "Kvadar.h"


Kvadar::Kvadar(double x, double z, double y, double r)
{
	duzina = x;
	sirina = z;
	visina = y;
	gustina = r;
}
Kvadar::Kvadar(const Kvadar& k)
{
	duzina = k.duzina;
	sirina = k.sirina;
	visina = k.visina;
	gustina = k.gustina;
}
Kvadar& Kvadar::operator=(const Kvadar& k)
{
	duzina = k.duzina;
	sirina = k.sirina;
	visina = k.visina;
	gustina = k.gustina;
	return *this;
}
double Kvadar::Masa()
{
	return (visina * sirina * duzina) * gustina;
}
bool Kvadar::operator>(Kvadar& k)
{
	return this->Masa() > k.Masa();
}
double operator+(double d, Kvadar& k)
{
	return d + k.Masa();
}
istream& operator>>(istream& i, Kvadar& k)
{
	i >> k.duzina;
	i >> k.sirina;
	i >> k.visina;
	i >> k.gustina;
	return i;
}
ostream& operator<<(ostream& o, Kvadar& k)
{
	o << k.duzina << endl;
	o << k.sirina << endl;
	o << k.visina << endl;
	o << k.gustina << endl;
	return o;
}

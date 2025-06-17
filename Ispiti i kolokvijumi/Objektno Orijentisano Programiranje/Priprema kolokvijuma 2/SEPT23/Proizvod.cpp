#include "Proizvod.h"

double operator+(double d, Proizvod& p)
{
	return d + p.Vrednost();
}

istream& operator>>(istream& i, Proizvod& p)
{
	i >> p.naziv;
	i >> p.meseciDoIstekaRoka;
	i >> p.cena;
	i >> p.koefPotraznje;
	return i;
} 
ostream& operator<<(ostream& o, Proizvod& p)
{
	o << p.naziv << endl;
	o << p.meseciDoIstekaRoka << endl;
	o << p.cena << endl;
	o << p.koefPotraznje << endl;
	return o;
}
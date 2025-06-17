#include "ProsireniPodatak.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& i, ProsireniPodatak& pp)
{
	i >> pp.T;
	i >> pp.E;
	i >> pp.V;
	return i;
}

ostream& operator<<(ostream& o, ProsireniPodatak& pp)
{
	o << pp.T;
	o << pp.E;
	o << pp.V;
	return o;
}

bool ProsireniPodatak::operator>(ProsireniPodatak& pp2)
{
	return this->SubOsecaj() > pp2.SubOsecaj();
}
float operator+(float f,ProsireniPodatak& pp2)
{
	return f + pp2.SubOsecaj();
}
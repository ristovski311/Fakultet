#include "ProsireniPodatak.h"


istream& operator>>(istream& i, ProsireniPodatak& pp)
{
	i >> pp.T;
	i >> pp.E;
	i >> pp.V;
	return i;
}
ostream& operator<<(ostream& o, ProsireniPodatak& pp)
{
	o << pp.T << endl;
	o << pp.E << endl;
	o << pp.V << endl;
	return o;
}
float operator+(float f, ProsireniPodatak& p)
{
	return f + p.SubjOsecaj();
}
bool ProsireniPodatak::operator>(ProsireniPodatak& p)
{
	return this->SubjOsecaj() > p.SubjOsecaj();
}
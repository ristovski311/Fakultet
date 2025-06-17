#include "Sport.h"

Sport::Sport(int brigr, int rez, string ob, float budz, float koef)
{
	if (brigr >= 0 && brigr <= 20)
		brojIgraca = brigr;
	else
		throw "Nije lepo unet broj igraca!";
	if (rez >= 0 && rez <= 10)
		brojRezervnih = rez;
	else
		throw "Nije lepo unet broj rezervnih!";
	obuca = ob;
	if (budz >= 0 && budz <= 50000)
		budzet = budz;
	else
		throw "Budzet nije ok";
	if (koef >= 0 && koef <= 1)
		koefPop = koef;
	else
		throw "Koeficijent pop. nije dobar!";
}

Sport::~Sport()
{

}

float Sport::vrednost()
{
	return (brojIgraca + brojRezervnih) * budzet * koefPop;
}

bool Sport::operator>(Sport& s)
{
	return this->vrednost() > s.vrednost();
}

float operator+(float f, Sport& s)
{
	return f + s.vrednost();
}

istream& operator>>(istream& i, Sport& s)
{
	i >> s.brojIgraca;
	i >> s.brojRezervnih;
	i >> s.obuca;
	i >> s.budzet;
	i >> s.koefPop;
	return i;
}

ostream& operator<<(ostream& o, Sport& s)
{
	cout << s.brojIgraca << endl;
	cout << s.brojRezervnih << endl;
	cout << s.obuca << endl;
	cout << s.budzet << endl;
	cout << s.koefPop << endl;
	return o;
}
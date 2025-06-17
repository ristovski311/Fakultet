#include "PutAvionom.h"

PutAvionom::PutAvionom(const char* gr, int max,
	int brnoci, double cenaponocenju, const char* komp, double duzinaleta, double cenampp)
	: Put(gr, max, brnoci, cenaponocenju)
{
	kompanija = komp;
	duzinaLeta = duzinaleta;
	cenaMestaPoPutniku = cenampp;
}

PutAvionom::~PutAvionom()
{
	//delete kompanija;
	//kompanija = nullptr;
}

double PutAvionom::cenaZaAgenciju()
{
	return (double)maxBrPutnika * (cenaMestaPoPutniku + this->cenaSmestaja());
}

double PutAvionom::cenaPutaPoPutniku()
{
	return 0.3 * cenaMestaPoPutniku + this->cenaSmestaja() * 0.25;
}

ostream& PutAvionom::IspisPuta(ostream& o)
{
	o << "Grad: " << grad << endl;
	o << "Max putnika: " << maxBrPutnika << endl;
	o << "Br nocenja: " << brNocenja << endl;
	o << "Cena po nocenju: " << cenaPoNocenju << endl;
	o << "Kompanija: " << kompanija << endl;
	o << "Duzina leta: " << duzinaLeta << endl;
	o << "Cena mesta po putniku: " << cenaMestaPoPutniku<< endl;
	o << "Cena smestaja: " << this->cenaSmestaja() << endl;
	o << "Cena za agenciju: " << this->cenaZaAgenciju() << endl;
	o << "Cena puta po putniku: " << this->cenaPutaPoPutniku() << endl;

	return o;
}

istream& PutAvionom::UpisUPut(istream& i)
{
	char* temp1 = new char[200];
	i >> temp1;
	grad = temp1;
	i >> maxBrPutnika;
	i >> brNocenja;
	i >> cenaPoNocenju;
	char* temp2 = new char[200];
	i >> temp2;
	kompanija = temp2;
	i >> duzinaLeta;
	i >> cenaMestaPoPutniku;

	return i;
}
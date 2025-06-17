#include "PutAutobusom.h"

PutAutobusom::PutAutobusom(const char* gr, int max,
	int brnoci, double cenaponoci, double km, double cenapol, double potrosnja, int nociuautob)
	: Put(gr, max, brnoci, cenaponoci)
{
	this->km = km;
	cenaGorivaPoLitru = cenapol;
	brNociUAutobusu = nociuautob;
	potrosnjaGorivaNa100km = potrosnja;
}

PutAutobusom::~PutAutobusom()
{
	
}

double PutAutobusom::cenaZaAgenciju()
{
	return (potrosnjaGorivaNa100km * km / 100) * 0.25 + (double)maxBrPutnika * this->cenaSmestaja();
}

double PutAutobusom::cenaPutaPoPutniku()
{
	return (this->cenaZaAgenciju() / ((double)maxBrPutnika * 0.35));
}

ostream& PutAutobusom::IspisPuta(ostream& o)
{
	o << "Grad: " << grad << endl;
	o << "Max putnika: " << maxBrPutnika << endl;
	o << "Br nocenja: " << brNocenja<< endl;
	o << "Cena po nocenju: " << cenaPoNocenju<< endl;
	o << "Kilometra: " << km << endl;
	o << "Cena goriva po litru: " << cenaGorivaPoLitru<< endl;
	o << "Potrosnja goriva na 100km: " <<potrosnjaGorivaNa100km << endl;
	o << "Broj nocenja u autobusu: " << brNociUAutobusu<< endl;
	o << "Cena smestaja: " << this->cenaSmestaja() << endl;
	o << "Cena za agenciju: " << this->cenaZaAgenciju() << endl;
	o << "Cena puta po putniku: " << this->cenaPutaPoPutniku() << endl;

	return o;
}

istream& PutAutobusom::UpisUPut(istream& i)
{
	char* temp = new char[200];
	i >> temp;
	grad = temp;
	i >> maxBrPutnika;
	i >> brNocenja;
	i >> cenaPoNocenju;
	i >> km;
	i >> cenaGorivaPoLitru;
	i >> potrosnjaGorivaNa100km;
	i >> brNociUAutobusu;

	return i;
}
#include "Putovanje.h"

Putovanje::Putovanje(int max, const char* datum1)
{
	this->planiranoPutnika = max;
	this->datum = datum1;
	this->trenutnoPuteva = 0;
	this->lista = new Put * [max];
	for (int i = 0; i < max; i++)
		lista[i] = nullptr;
}

Putovanje::~Putovanje()
{
	for (int i = 0; i < planiranoPutnika; i++)
		if (lista[i] != nullptr)
			delete lista[i];
	delete[] lista;
	lista = nullptr;
	delete datum;
	datum = nullptr;
}

double Putovanje::cenaZaAgenciju()
{
	double ukupno = 0;
	for (int i = 0; i < planiranoPutnika; i++)
		if (lista[i] != nullptr)
			ukupno += lista[i]->cenaZaAgenciju();
	return ukupno;
}

double Putovanje::cenaPoPutniku()
{
	double ukupno = 0;
	for (int i = 0; i < planiranoPutnika; i++)
		if (lista[i] != nullptr)
			ukupno += lista[i]->cenaPutaPoPutniku();
	return ukupno;
}

void Putovanje::dodajPut(Put* put)
{
	int ukupnoPutnika = 0;
	for (int i = 0; i < planiranoPutnika; i++)
		if (lista[i] != nullptr)
			ukupnoPutnika += lista[i]->getPutnika();
	if (ukupnoPutnika + put->getPutnika() < planiranoPutnika)
	{
		lista[trenutnoPuteva] = put;
		trenutnoPuteva++;
	}
	else
		cout << "GRESKA! MALO MESTA!" << endl;
}

void Putovanje::obrisiPut(const char* grad)
{
	for (int i = 0; i < trenutnoPuteva; i++)
		if (lista[i] != nullptr && lista[i]->getGrad() == grad)
		{
			delete lista[i];
			lista[i] = nullptr;
		}
}

ostream& Putovanje::IspisPutovanja(ostream& o)
{
	o << "Planirano putnika: " << planiranoPutnika << endl;
	o << "Datum: " << datum << endl;
	for (int i = 0; i < trenutnoPuteva; i++)
	{
		if (lista[i] != nullptr)
			lista[i]->IspisPuta(o);
		o << endl;
	}

	return o;
}

istream& Putovanje::UpisPutovanja(istream& i)
{
	i >> trenutnoPuteva;
	i >> planiranoPutnika;
	char* temp = new char[100];
	i >> temp;
	datum = temp;
	for (int j = 0; j < trenutnoPuteva; j++)
		lista[j]->UpisUPut(i);
	return i;
}


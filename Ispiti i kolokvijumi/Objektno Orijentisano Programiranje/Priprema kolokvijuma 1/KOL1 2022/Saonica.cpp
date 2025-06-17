#include "Saonica.h"

Saonica::Saonica(int N)
{
	this->kapacitet = N;
	this->trenutnoIma = 0;
	this->sadrzaj = new Paketic * [kapacitet];
	for (int i = 0; i < kapacitet; i++)
		sadrzaj[i] = nullptr;
}

Saonica::~Saonica()
{
	for (int i = 0; i < trenutnoIma; i++)
		if (sadrzaj[i] != nullptr)
			delete sadrzaj[i];
	delete[] sadrzaj;
	sadrzaj = nullptr;
}

void Saonica::ubaci(Paketic* p)
{
	if (trenutnoIma < kapacitet)
	{
		sadrzaj[trenutnoIma] = p;
		trenutnoIma++;
	}
	else
		cout << "Saonica je puna!\n";
}

void Saonica::izbaci(const char* adresa1)
{
	bool found = false;
	int i = 0;
	while(i < trenutnoIma && !found)
	{
		if (sadrzaj[i] != nullptr and !strcmp(sadrzaj[i]->GetAdresa(), adresa1))
		{
			sadrzaj[i] = nullptr;
			found = true;
			cout << "Paketic je izbacen\n";
		}
		i++;
	}
	if (!found)
		cout << "Nema paketica za tu adresu!\n";
}

ostream& Saonica::prikaz(ostream& o)
{
	o << "Kapacitet: " << kapacitet << endl;
	o << "Trenutno ima: " << trenutnoIma << endl;
	for (int i = 0; i < trenutnoIma; i++)
	{
		if (sadrzaj[i] != nullptr)
			sadrzaj[i]->Ispis(o);
		o << endl;
	}
	return o;

}

double Saonica::srednjaCena()
{
	int brojPaketica = 0;
	double ukupnaCena = 0;
	for (int i = 0; i < trenutnoIma; i++)
	{
		if (sadrzaj[i] != nullptr)
		{
			brojPaketica++;
			ukupnaCena += sadrzaj[i]->cena();
		}
	}
	return ukupnaCena / brojPaketica;
}

Paketic* Saonica::najteziPaketic()
{
	double najtezi = 0;
	int najteziIndeks = 0;
	for (int i = 0; i < trenutnoIma; i++)
		if (sadrzaj[i] != nullptr)
			if (sadrzaj[i]->tezina() > najtezi)
				najteziIndeks = i;
	return sadrzaj[najteziIndeks];
}
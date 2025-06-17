#include "Evidencija.h"

Evidencija::Evidencija(int max)
{
	this->maxKupovina = max;
	this->trenutnoKupovina = 0;
	this->kolekcija = new Kupovina * [max];
	for (int i = 0; i < maxKupovina; i++)
		kolekcija[i] = nullptr;
}

Evidencija::~Evidencija()
{
	for (int i = 0; i < maxKupovina; i++)
		if (kolekcija[i] != nullptr)
			delete kolekcija[i];
	delete[] kolekcija;
	kolekcija = nullptr;
}

void Evidencija::dodaj(Kupovina* k)
{
	if (trenutnoKupovina < maxKupovina)
		kolekcija[trenutnoKupovina++] = k;
	else
		cout << "Nema vise mesta u kolekciji kupovina\n";
}

void Evidencija::brisi(const char* kod)
{
	bool found = 0;
	for (int i = 0; i < trenutnoKupovina && !found; i++)
		if (kolekcija[i] != nullptr)
			if (!strcmp(kolekcija[i]->getKod(), kod))
			{
				delete kolekcija[i];
				kolekcija[i] = nullptr;
				found = 1;
			}
	if (!found)
		cout << "Nema takve kupovine u kolekciji!\n";
}

ostream& Evidencija::spisak(ostream& o)
{
	o << "Kupovina u kolekciji: " << trenutnoKupovina << "/" << maxKupovina << endl << endl;
	for (int i = 0; i < trenutnoKupovina; i++)
		if (kolekcija[i] != nullptr)
		{
			kolekcija[i]->ispisi(o);
			o << endl;
		}
	return o;
}

Kupovina* Evidencija::najjeftinija()
{
	int najj = 0;
	for (int i = 1; i < trenutnoKupovina; i++)
		if (kolekcija[i] != nullptr)
			if (kolekcija[i]->cena() < kolekcija[najj]->cena())
				najj = i;
	return kolekcija[najj];
}

Kupovina* Evidencija::najskuplja()
{
	int najs = 0;
	for (int i = 1; i < trenutnoKupovina; i++)
		if (kolekcija[i] != nullptr)
			if (kolekcija[i]->cena() > kolekcija[najs]->cena())
				najs = i;
	return kolekcija[najs];
}

int Evidencija::brojKupovina(int sifrap, int poc, int kraj)
{
	int broj = 0;
	for (int i = 0; i < trenutnoKupovina; i++)
		if (kolekcija[i] != nullptr)
			if (kolekcija[i]->getSifra() == sifrap)
				if (kolekcija[i]->getDan() >= poc && kolekcija[i]->getDan() <= kraj)
					broj++;
	return broj;
}

double Evidencija::ukupnaCena(int poc, int kraj)
{
	double ukupno = 0;
	for (int i = 0; i < trenutnoKupovina; i++)
		if (kolekcija[i] != nullptr && kolekcija[i]->getDan() <= kraj && kolekcija[i]->getDan() >= poc)
			ukupno += kolekcija[i]->cena();
	return ukupno;
}

double Evidencija::dugovanje(int poc, int kraj)
{
	double ukupno = 0;
	for (int i = 0; i < trenutnoKupovina; i++)
		if (kolekcija[i] != nullptr && kolekcija[i]->getDan() <= kraj && kolekcija[i]->getDan() >= poc)
			ukupno += kolekcija[i]->duguje();
	return ukupno;
}
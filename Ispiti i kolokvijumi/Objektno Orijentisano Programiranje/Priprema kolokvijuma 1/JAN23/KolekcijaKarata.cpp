#include "KolekcijaKarata.h"

KolekcijaKarata::KolekcijaKarata(int n)
{
	this->duzina = n;
	this->popunjenost = 0;
	this->karte = new DnevnaKarta * [n];
	for (int i = 0; i < duzina; i++)
		this->karte[i] = nullptr;
}

void KolekcijaKarata::kupiKartu(DnevnaKarta* k)
{
	if (popunjenost < duzina)
	{
		this->karte[popunjenost] = k;
		popunjenost++;
	}
	else
	{
		cout << "\nPOPUNJENA KOLEKCIJA!" << endl;
	}
}

void KolekcijaKarata::ponistiKartu(int id1)
{
	int i = 0;
	while (this->karte[i]->getId() != id1)
		i++;
	delete this->karte[i];
	this->karte[i] = nullptr;
}

DnevnaKarta& KolekcijaKarata::vratiNajkracu()
{
	DnevnaKarta* najkraca = this->karte[0];
	for (int i = 1; i < this->duzina; i++)
		if (this->karte[i] != nullptr && this->karte[i]->getBrDanaVazenja() < najkraca->getBrDanaVazenja())
			najkraca = this->karte[i];
	return *najkraca;
}

DnevnaKarta& KolekcijaKarata::vratiNajduzu()
{
	DnevnaKarta* najduza = this->karte[0];
	for (int i = 1; i < this->duzina; i++)
		if (this->karte[i] != nullptr && this->karte[i]->getBrDanaVazenja() > najduza->getBrDanaVazenja())
			najduza = this->karte[i];
	return *najduza;
}

int KolekcijaKarata::brojVazecih(int redBrDana, const char* tip)
{
	int vazece = 0;
	for (int i = 0; i < this->duzina; i++)
		if (this->karte[i] != nullptr)
			if (!strcmp(this->karte[i]->getTip(), tip) && this->karte[i]->getRedBrDana() + this->karte[i]->getBrDanaVazenja() > redBrDana)
				++vazece;
	return vazece;
}

double KolekcijaKarata::zarada()
{
	double zarada = 0;
	for (int i = 0; i < this->duzina; i++)
	if(this->karte[i] != nullptr)
	{
		zarada += this->karte[i]->getCena();
	}
	return zarada;
}

ostream& KolekcijaKarata::spisak(ostream& o)
{
	for (int i = 0; i < this->duzina; i++)
	{
		if(this->karte[i] != nullptr)
		{
			o << *this->karte[i];
			o << endl;
		}
	}
	return o;
}

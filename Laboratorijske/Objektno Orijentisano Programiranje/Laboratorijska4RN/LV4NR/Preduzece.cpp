#include "Preduzece.h"
#include <iostream>
using namespace std;

Preduzece::Preduzece(const char* naziv, int max, double budz)
{
	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);
	this->maxBrojEl = max;
	this->brojEl = 0;
	this->radnici = new Radnik*[this->maxBrojEl];
	for (int i = 0; i < maxBrojEl; i++)
		this->radnici[i] = nullptr;
	this->budzet = budz;
}

Preduzece::~Preduzece()
{
	for (int i = 0; i < this->brojEl; i++)
	{
		if (this->radnici[i] != nullptr)
		{
			delete radnici[i];
			this->radnici[i] = nullptr;
		}
	}
	if(this->radnici != nullptr)
	{
		delete[] this->radnici;
		this->radnici = nullptr;
	}
	if (this->naziv != nullptr)
	{
		delete[] this->naziv;
		this->naziv = nullptr;
	}
}

void Preduzece::Dodaj(Radnik* r, int godinaz)
{
	if (this->brojEl < this->maxBrojEl)
	{
		this->radnici[brojEl] = r;
		this->brojEl++;
		r->SetGodinaZaposljenja(godinaz);
	}
	else cout << "NIZ JE POPUNJEN!\n\n";
	return;
}

void Preduzece::Brisi(int jmbg1)
{
	for (int i = 0; i < this->brojEl; i++)
	{
		if (this->radnici[i]->GetJmbg() == jmbg1)
		{
			this->radnici[i]->SetGodinaZaposljenja(0);
			this->radnici[i] = this->radnici[brojEl - 1];
			this->radnici[brojEl - 1] = nullptr;
			this->brojEl--;
		}
	}
}

double Preduzece::ZaIsplatu()
{
	double s = 0;
	for (int i = 0; i < this->brojEl; i++)
	{
		s += this->radnici[i]->OdrediPlatu();
	}
	return s;
}

bool Preduzece::Rentabilna()
{
	return ((double)this->budzet > this->ZaIsplatu());
}


void Preduzece::operator++()
{
	for (int i = 0; i < this->brojEl; i++)
	{
		this->radnici[i]->SetOsnovicaPlate(this->radnici[i]->GetOsnovicaPlate() * 1.1);
	}
}

void Preduzece::operator--()
{
	for (int i = 0; i < this->brojEl; i++)
	{
		this->radnici[i]->SetOsnovicaPlate(this->radnici[i]->GetOsnovicaPlate() * 0.9);
	}
}

Radnik** Preduzece::SortPoStarosti()
{
	Radnik** tempniz = new Radnik * [this->brojEl];
	for (int i = 0; i < this->brojEl; i++)
	{
		tempniz[i] = this->radnici[i];
	}
	for (int i = 0; i < this->brojEl - 1; i++)
	{
		for (int j = i; j < this->brojEl; j++)
		{
			if (tempniz[j]->GetGodinaStarosti() < tempniz[i]->GetGodinaStarosti())
			{
				Radnik* temp;
				temp = tempniz[j];
				tempniz[j] = tempniz[i];
				tempniz[i] = temp;
				temp = 0;
				delete temp;
			}
		}
	}
	return tempniz;
}

ostream& Preduzece::OPreduzecu(ostream& o)
{
	o << "Preduzece: " << this->naziv << endl;
	o << "Budzet: " << this->budzet << endl;
	o << "Za isplatu: " << this->ZaIsplatu() << endl;
	string rent;
	if (this->Rentabilna()) { rent = "jeste"; }
	else { rent = "nije"; }
	o << "Rentabilna: " << rent << "\n\n";
	return o;
}

ostream& operator<<(ostream& o, Preduzece& p)
{
	Radnik** temp = p.SortPoStarosti();
	for (int i = 0; i < p.GetBrEl(); i++)
	{
		o << i << ". " << "Ime i prezime:" << temp[i]->GetIme() << "\n  Jmbg: " << temp[i]->GetJmbg()
			<< "\n  Starost: " << temp[i]->GetGodinaStarosti() << "\n  Osnovica plate: " 
			<< temp[i]->GetOsnovicaPlate() << "\n  Plata: " << temp[i]->OdrediPlatu() << "\n";
	}
	delete[] temp;
	return o;
}

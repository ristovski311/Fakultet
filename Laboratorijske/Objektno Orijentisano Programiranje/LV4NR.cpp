//MAIN ----------------------------------------------------------------------------------------------------

#include "Radnik.h"
#include "Developer.h"
#include "Menager.h"
#include "Preduzece.h"
#include <iostream>
#include <fstream>
using namespace std;

void inic(Preduzece* p,int a)
{
	for (int i = 0; i < a; i++)
	{
		if (i % 2 == 0)
		{
			p->GetRadnici()[i] = new Developer();
		}
		else
		{
			p->GetRadnici()[i] = new Menager();
		}
	}
}

int main()
{
	ifstream ulaz("radnici_ulaz.txt");
	ofstream izlaz("izlaz.txt");
	Preduzece* preduzece1 = new Preduzece("preduzece1", 2018, 1000000);
	inic(preduzece1, 2018);

	for (int i = 0; i < 10; i++)
	{ 
		ulaz >> *preduzece1->GetRadnici()[i];
		preduzece1->SetBrEl(preduzece1->GetBrEl() + 1);
	}

	preduzece1->OPreduzecu(izlaz);
	izlaz << *preduzece1;

	if (preduzece1->Rentabilna())
		++(*preduzece1);
	else
		--(*preduzece1);
	izlaz << *preduzece1;

	Radnik* novi_radnik = new Developer(10221, 0, 2, 34, "Sava_Ilic", "programer", 3);

	preduzece1->Dodaj(novi_radnik, 2023);

	cout << *preduzece1;

	preduzece1->Brisi(10221);

	cout << "\n\n-----------\n\n";

	cout << *preduzece1;

	cout << "\n\n-----------\n\n";

	preduzece1->GetRadnici()[1]->Prikazi();
	

	return 1;
}

//PREDUZECE.H ----------------------------------------------------------------------------------------------------

#pragma once
#include "Radnik.h"

class Preduzece
{
public:
	Preduzece(const char* c, int max, double b);
	~Preduzece();
	Radnik** GetRadnici() { return this->radnici; }
	void SetBrEl(int a) { this->brojEl = a; }
	void Dodaj(Radnik* r, int godinaz);
	void Brisi(int jmbg);
	ostream& OPreduzecu(ostream& o);
	double ZaIsplatu();
	bool Rentabilna();
	void operator++();
	void operator--();
	Radnik** SortPoStarosti();
	friend ostream& operator<<(ostream& o, Preduzece& p);
	int GetBrEl() { return this->brojEl; }
private:
	char* naziv;
	double budzet;
	Radnik** radnici;
	int brojEl;
	int maxBrojEl;

};



//PREDUZECE.CPP ----------------------------------------------------------------------------------------------------

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


//RADNIK.H ----------------------------------------------------------------------------------------------------

#pragma once
#include <string>
using namespace std;
class Radnik
{
public:
	Radnik();
	~Radnik();
	Radnik(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime);
	int GetJmbg() { return this->jmbg; }
	char* GetIme() { return this->ime_prezime; }
	int GetGodinaZaposljenja() { return this->godinaZaposljenja; }
	double GetOsnovicaPlate() { return this->osnovicaPlate; }
	int GetGodinaStarosti() { return this->godinaStarosti; }
	void SetGodinaZaposljenja(int a) { this->godinaZaposljenja = a; }
	void SetOsnovicaPlate(double a) { this->osnovicaPlate = a; }
	virtual double OdrediPlatu() = 0;
	void operator++();
	void operator--();
	bool virtual operator>(Radnik* r);
	bool virtual operator<(Radnik* r);
	bool virtual operator>=(Radnik* r);
	bool virtual operator<=(Radnik* r);
	bool virtual operator==(Radnik& r);
	virtual void Prikazi() = 0;
	virtual istream& Upisi(istream& i);
	friend istream& operator>>(istream& i, Radnik& r);
protected:
	int jmbg;
	int godinaZaposljenja;
	double osnovicaPlate;
	int godinaStarosti;
	char* ime_prezime;
};



//RADNIK.CPP ----------------------------------------------------------------------------------------------------

#include "Radnik.h"
#include <iostream>

Radnik::Radnik()
{
	this->jmbg = 0;
	this->godinaZaposljenja = 0;
	this->godinaStarosti = 0;
	this->osnovicaPlate = 0;
	this->ime_prezime = new char[100];
	this->ime_prezime[0] = 0;
}

Radnik::~Radnik()
{
	delete[] this->ime_prezime;
}

Radnik::Radnik(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime1)
{
	this->jmbg = jmbg;
	this->godinaZaposljenja = godinaZaposljenja;
	this->osnovicaPlate = osnovicaPlate;
	this->godinaStarosti = godinaStarosti;
	this->ime_prezime = new char[strlen(ime_prezime1) + 1];
	strcpy(this->ime_prezime, ime_prezime1);
}

void Radnik::operator++()
{
	this->osnovicaPlate = this->osnovicaPlate * 1.1;
}

void Radnik::operator--()
{
	this->osnovicaPlate = this->osnovicaPlate * 0.9;
}

bool Radnik::operator>(Radnik* r)
{
	return this->GetGodinaStarosti() > r->GetGodinaStarosti();
}

bool Radnik::operator<(Radnik* r)
{
	return this->GetGodinaStarosti() < r->GetGodinaStarosti();
}

bool Radnik::operator>=(Radnik* r)
{
	return this->GetGodinaStarosti() >= r->GetGodinaStarosti();
}

bool Radnik::operator<=(Radnik* r)
{
	return this->GetGodinaStarosti() <= r->GetGodinaStarosti();
}

bool Radnik::operator==(Radnik& r)
{
	return this->GetGodinaStarosti() == r.GetGodinaStarosti();
}

istream& Radnik::Upisi(istream& i)
{
	i >> this->ime_prezime;
	i >> this->jmbg;
	i >> this->godinaStarosti;
	i >> this->godinaZaposljenja;
	i >> this->osnovicaPlate;
	return i;
}

istream& operator>>(istream& i, Radnik& r)
{
	return r.Upisi(i);
}

//DEVELOPER.H ----------------------------------------------------------------------------------------------------

#pragma once
#include "Radnik.h"
class Developer : public Radnik
{
public:
	Developer();
	Developer(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime, const string& tip, int prekovr);
	virtual double OdrediPlatu();
	friend istream& operator>>(istream& i, Developer& d);
	virtual void Prikazi();
	virtual istream& Upisi(istream& i);
private:
	string tip;
	int prekovremeni_sati;
};



//DEVELOPER.CPP ----------------------------------------------------------------------------------------------------

#include "Developer.h"
#include <iostream>
Developer::Developer() : Radnik()
{
	this->tip = "neodredjeni";
	this->prekovremeni_sati = 0;
}

Developer::Developer(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime1,
	const string& tip, int prekovr) : Radnik( jmbg,  godinaZaposljenja,  osnovicaPlate,
		 godinaStarosti,ime_prezime1)
{
	this->tip = tip;
	this->prekovremeni_sati = prekovr;
}

double Developer::OdrediPlatu()
{
	return 25 * this->osnovicaPlate + 150 * this->godinaZaposljenja + 1000 * prekovremeni_sati;
}

istream& Developer::Upisi(istream& i)
{
	this->Radnik::Upisi(i);
	i >> this->tip;
	i >> this->prekovremeni_sati;
	return i;
}

istream& operator>>(istream& i, Developer& d)
{
	return d.Upisi(i);
}

void Developer::Prikazi()
{
	cout << "Ime i prezime: " << this->ime_prezime << endl;
	cout << "Jmbg: " << this->jmbg << endl;
	cout << "Godina: " << this->godinaStarosti << endl;
	cout << "Godina zaposljenja: " << this->godinaZaposljenja << endl;
	cout << "Tip: " << this->tip << endl;
	cout << "Osnovica plate: " << this->osnovicaPlate << endl;
	cout << "Plata: " << this->OdrediPlatu() << endl;
	cout << "Prekovremeni sati: " << this->prekovremeni_sati << endl << endl;
}


//MENAGER.H ----------------------------------------------------------------------------------------------------

#pragma once
#include "Radnik.h"

class Menager : public Radnik
{
public:
	Menager();
	Menager(int jmbg, int godinaZaposljenja, double osnovicaPlate,
		int godinaStarosti, const char* ime_prezime, const string& tip);
	virtual double OdrediPlatu();
	friend istream& operator>>(istream& i, Menager& m);
	virtual void Prikazi();
	virtual istream& Upisi(istream& i);
private:
	string tip;
};




//MENAGER.CPP ----------------------------------------------------------------------------------------------------

#include "Menager.h"
#include <iostream>

Menager::Menager() : Radnik()
{
	this->tip = "neodredjeni";
}

Menager::Menager(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime1, const string& tip)
	: Radnik(jmbg, godinaZaposljenja, osnovicaPlate,
		godinaStarosti, ime_prezime1), tip(tip) {}

double Menager::OdrediPlatu()
{
	return 30 * this->osnovicaPlate + 100 * this->godinaZaposljenja;
}

istream& Menager::Upisi(istream& i)
{
	this->Radnik::Upisi(i);
	i >> this->tip;
	return i;
}

istream& operator>>(istream& i, Menager& m)
{
	return m.Upisi(i);
}

void Menager::Prikazi()
{
	cout << "Ime i prezime: " << this->ime_prezime << endl;
	cout << "Jmbg: " << this->jmbg << endl;
	cout << "Godina: " << this->godinaStarosti << endl;
	cout << "Godina zaposljenja: " << this->godinaZaposljenja << endl;
	cout << "Tip: " << this->tip << endl;
	cout << "Osnovica plate: " << this->osnovicaPlate << endl;
	cout << "Plata: " << this->OdrediPlatu() << endl << endl;
}
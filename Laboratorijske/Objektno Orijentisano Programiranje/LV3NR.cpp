//MAIN

#include "Artikal.h"
#include "Laptop.h"
#include "Torba.h"
#include <fstream>
#include <iostream>

using namespace std;

ofstream izlaz("izlaz.txt");

void inic_array(Artikal** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = new Laptop();
		}
		else
		{
			a[i] = new Torba();
		}
	}
}

void sort(Artikal** niz, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (niz[j]->getPrice() < niz[i]->getPrice())
			{
				Artikal* temp;
				temp = niz[j];
				niz[j] = niz[i];
				niz[i] = temp;
			}
		}
	}
}

int main()
{
	Artikal** nizArtikala = new Artikal * [2018];

	inic_array(nizArtikala, 2018);

	ifstream upis("upis.txt");
	ofstream izlaz("izlaz.txt");

	//Inicijalizacija svih clanova niza nizArtikala
	for (int i = 0; i < 10; i++)
	{

		if (i % 2 == 0)
		{
			nizArtikala[i] = new Laptop();
			upis >> *nizArtikala[i];
		}
		else
		{
			nizArtikala[i] = new Torba();
			upis >> *nizArtikala[i];
			nizArtikala[i]->put(*nizArtikala[i - 1]);
		}
	}

	//Prikaz na standardni izlaz pre sortiranja
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ". \n";
		nizArtikala[i]->showDescription();
	}

	cout << "------------------------------\n";

	//Testiranje svih metoda
	Artikal* art1 = new Artikal("Artikal broj 1", 199);
	Torba* torba1 = new Torba();
	char* temp = new char[1];
	temp[0] = 0;
	Laptop* lap1 = new Laptop("Laptop broj 1", 89, true, temp);

	art1->showDescription();
	cout << art1->getPrice();

	cout << "\n----------------\n";

	lap1->showDescription();
	lap1->turnOff();
	lap1->turnOn();

	cout << "----------------\n";

	torba1->showDescription();
	torba1->put(*lap1);
	torba1->showDescription();
	torba1->remove();
	torba1->showDescription();
	torba1->remove();

	//Sortiranje
	sort(nizArtikala, 10);

	//Prikaz u izlazni fajl posle sortiranja
	for (int i = 0; i < 10; i++)
	{
		izlaz << i + 1 << ".\n";
		izlaz << *nizArtikala[i];
	}

	for (int t = 0; t < 2018; t++)
	{
		if(nizArtikala[t])
		{
			delete nizArtikala[t];
			nizArtikala[t] = 0;
		}
	}
	delete[] nizArtikala;

	return 1;
}

//----------------------------------------------------------------------------------------

//ARTIKAL H

#include <string>
#include <iostream>
#pragma once
using namespace std;
class Artikal
{
public:
	Artikal();
	virtual ~Artikal()
	{
		//cout << "Destruktor iz artikla\n"; 
	}
	Artikal(string naziv1, double cena1);
	virtual void showDescription();
	double getPrice()
	{
		return this->cena;
	}
	string getName()
	{
		return this->naziv;
	}
	virtual void put(Artikal& a) {};
	virtual ostream& print(ostream& o);
	friend ostream& operator<<(ostream& izlaz, Artikal& a);
	virtual istream& upis(istream& u);
	friend istream& operator>>(istream& izlaz, Artikal& a);
private:
	double cena;
	string naziv;
};

//----------------------------------------------------------------------------------------

//ARTIKAL CPP


#include "Artikal.h"

Artikal::Artikal() : naziv("prazan artikal"), cena(-1) {}

Artikal::Artikal(string naziv1, double cena1) :
	naziv(naziv1), cena(cena1) {}

void Artikal::showDescription()
{
	cout << "Naziv: " << this->getName() << endl;
	cout << "Cena: " << this->getPrice() << endl;
}

ostream& Artikal::print(ostream& o)
{
	o << "Naziv: " << this->getName() << endl;
	o << "Cena: " << this->getPrice() << endl;
	return o;
}

ostream& operator<<(ostream& izlaz, Artikal& a)
{
	return a.print(izlaz);
}

istream& Artikal::upis(istream& u)
{
	u >> this->naziv;
	u >> this->cena;
	return u;
}

istream& operator>>(istream& ulaz, Artikal& a)
{
	a.upis(ulaz);
	return ulaz;
}

//---------------------------------------------------------------------------

//LAPTOP H


#pragma once
#include "Artikal.h"
#include <string>
using namespace std;
class Laptop : public Artikal
{
public:
	Laptop();
	~Laptop();
	Laptop(string naziv1, double cena1, bool stanje1, char* opis1);
	void showDescription();
	void turnOn();
	void turnOff();
	ostream& print(ostream& o);
	friend ostream& operator<<(ostream& izlaz, Laptop& lap);
	istream& upis(istream& u);
	friend istream& operator>>(istream& izlaz, Laptop& l);
private:
	char* opis;
	bool stanje;
};


//-----------------------------------------------------------------------------


//LAPTOP CPP


#include "Laptop.h"

Laptop::Laptop() : Artikal(), stanje(false)
{
	this->opis = new char[100];
	this->opis[0] = '\0';
}

Laptop::~Laptop()
{
	if (this->opis != nullptr)
	{
		delete this->opis;
		this->opis = nullptr;
		//cout << "Destruktor iz laptopa\n";
	}
}

Laptop::Laptop(string naziv1, double cena1, bool stanje1, char* opis1) :
	Artikal(naziv1, cena1), stanje(stanje1)
{
	this->opis = new char[100];
	int len = 0;
	while (opis1[len] != '\0' && len < 100)
	{
		this->opis[len] = opis1[len];
		len++;
	}
	this->opis[len] = 0;

}

void Laptop::showDescription()
{
	if (this->getPrice() != -1)
	{
		this->Artikal::showDescription();
		cout << "Opis: " << this->opis << endl << endl;
	}
	else
		cout << "Trenutni laptop nije definisan!\n\n";
}

void Laptop::turnOn()
{
	this->stanje = true;
	cout << "Promenjeno stanje na ukljucen!" << endl;
}
void Laptop::turnOff()
{
	this->stanje = false;
	cout << "Promenjeno stanje na iskljucen!" << endl;
}

ostream& Laptop::print(ostream& izlaz)
{
	if (this->getPrice() != -1)
	{
		this->Artikal::print(izlaz);
		izlaz << "Opis: " << this->opis << endl << endl;
	}
	else
		izlaz << "Trenutni laptop nije definisan!\n\n";
	return izlaz;
}

ostream& operator<<(ostream& izlaz, Laptop& lap)
{
	return lap.print(izlaz);
}

istream& Laptop::upis(istream& u)
{

	this->Artikal::upis(u);
	delete this->opis;
	this->opis = new char[100];
	u >> this->opis;
	return u;
}

istream& operator>>(istream& ulaz, Laptop& l)
{
	l.upis(ulaz);
	return ulaz;
}

//-------------------------------------------------------------

//TORBA H


#pragma once
#include "Artikal.h"
class Torba : public Artikal
{
public:
	Torba();
	~Torba();
	Torba(string name, double cena, Artikal& a);
	void showDescription();
	void put(Artikal& a);
	void remove();
	friend ostream& operator<<(ostream& izlaz, Torba& torba);
	ostream& print(ostream& o);
	istream& upis(istream& u);
	friend istream& operator>>(istream& izlaz, Torba& t);
private:
	Artikal* sadrzaj;
};

//---------------------------------------------------------------------

//TORBA CPP


#include "Torba.h"

Torba::Torba() : Artikal(), sadrzaj(0) {}

Torba::Torba(string name, double cena, Artikal& a) : Artikal(name, cena), sadrzaj(&a) {}

Torba::~Torba()
{
	/*if (this->sadrzaj != nullptr)
	{
		delete sadrzaj;
		this->sadrzaj = nullptr;
		//cout << "Destruktor iz torbe\n";
	}*/
}

void Torba::showDescription()
{
	cout << "Torba za laptop racunar. Sadrzi sledeci artikal: " << "(cena torbe: " << this->getPrice() << ")" << endl;
	if (this->sadrzaj != nullptr)
	{
		this->sadrzaj->showDescription();
	}
	else
		cout << "Torba nema sadrzaj!\n";
}

void Torba::put(Artikal& a)
{
	if (this->sadrzaj == nullptr)
	{
		this->sadrzaj = &a;
		cout << "U torbu je smesten artikal!" << endl;
	}
	else
		cout << "Torba je vec puna!\n";
}

void Torba::remove()
{
	if (this->sadrzaj != nullptr)
	{
		this->sadrzaj = 0;
		cout << "Iz torbe je izbacen artikal!" << endl;
	}
	else
		cout << "Torba je vec prazna!\n";
}

ostream& Torba::print(ostream& izlaz)
{
	izlaz << "Torba za laptop racunar. Sadrzi sledeci artikal: " << "(cena torbe: " << this->getPrice() << ")" << endl;
	if (this->sadrzaj != nullptr)
	{
		this->sadrzaj->print(izlaz);
	}
	else
		izlaz << "Torba nema sadrzaj!\n";
	return izlaz;
}

ostream& operator<<(ostream& izlaz, Torba& torba)
{
	return torba.print(izlaz);
}

istream& Torba::upis(istream& u)
{

	this->Artikal::upis(u);
	return u;
}

istream& operator>>(istream& ulaz, Torba& t)
{
	t.upis(ulaz);
	return ulaz;
}

//----------------------------------------------------------------

//ULAZNI

HP_laptop
333
Sivi_laptop.
HP_torba
555
Samsung_laptop
333
Crni_samsung_laptop
Apple_torba
222
Apple_Mac
555
Sivi_macbook
Samsung_torba
999
Asus_laptop
222
Sjajan_racunar
Asus_torba
888
Dell_laptop
111
Crni_dell_racunar
Lenovo_torba
444
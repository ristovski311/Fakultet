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
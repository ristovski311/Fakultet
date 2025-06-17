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
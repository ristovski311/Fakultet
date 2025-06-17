#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Kolekcija
{
public:
	Kolekcija();
	Kolekcija(int n);
	Kolekcija(const Kolekcija<T>& k);
	Kolekcija<T>& operator=(const Kolekcija<T>& k);
	float OdrediProsek();
	void DodajPodatak(T& t);
	void Obrisi(int n);
	T& NajveciPodatak();
	template<class T> friend istream& operator>>(istream& i, Kolekcija<T>& k);
	template<class T> friend ostream& operator<<(ostream& o, Kolekcija<T>& k);
	void Sacuvaj(const char* file);
	void Ucitaj(const char* file);
private:
	T* niz;
	int max;
	int trenutno;
};

template<class T>
Kolekcija<T>::Kolekcija()
{
	this->max = 0;
	this->trenutno = 0;
	this->niz = nullptr;
}

template<class T>
Kolekcija<T>::Kolekcija(int n)
{
	this->max = n;
	this->trenutno = 0;
	this->niz = new T[max];
}

template<class T>
Kolekcija<T>::Kolekcija(const Kolekcija<T>& k)
{
	if (this->niz != nullptr)
		delete[] this->niz;
	this->max = k.max;
	this->trenutno = k.trenutno;
	this->niz = new T[this->max];
}

template<class T>
Kolekcija<T>& Kolekcija<T>::operator=(const Kolekcija<T>& k)
{
	if (this == &k)
		return *this;
	if (this->niz != nullptr)
		delete[] this->niz;
	this->max = k.max;
	this->trenutno = k.trenutno;
	this->niz = new T[this->max];
	return *this;
}

template<class T>
float Kolekcija<T>::OdrediProsek()
{
	float suma = 0;
	for (int i = 0; i < this->trenutno; i++)
		suma = suma + this->niz[i];
	return suma / this->trenutno;
}

template<class T>
void Kolekcija<T>::DodajPodatak(T& t)
{
	if (trenutno < max)
	{
		this->niz[trenutno] = t;
		trenutno++;
	}
	else
		throw "Popunjena je kolekcija!\n";
}

template<class T>
void Kolekcija<T>::Obrisi(int n)
{
	if (n >= this->trenutno)
		throw "Greska, nevalidan broj za brisanje!\n";
	else
	{
		for (int i = n; i < this->trenutno; i++)
		{
			this->niz[i] = this->niz[i + 1];
		}
		this->trenutno--;
	}
}

template<class T>
T& Kolekcija<T>::NajveciPodatak()
{
	int max = 0;
	for (int i = 1; i < this->trenutno; i++)
		if (this->niz[i] > this->niz[max])
			max = i;
	return this->niz[max];
}

template<class T>
istream& operator>>(istream& i, Kolekcija<T>& k) 
{
	T temp;
	while (i >> temp)
	{
		k.niz[k.trenutno++] = temp;
	}
	return i;
}

template<class T>
ostream& operator<<(ostream& o, Kolekcija<T>& k)
{
	for (int i = 0; i < k.trenutno; i++)
	{
		o << k.niz[i] << endl;
	}
	return o;
}

template<class T>
void Kolekcija<T>::Sacuvaj(const char* file)
{
	ofstream o(file);
	if (o.good())
	{
		o << *this;
	}
	else
		throw "Greska pri otvaranju fajla za upis!\n";
}

template<class T>
void Kolekcija<T>::Ucitaj(const char* file)
{
	ifstream i(file);
	if (i.good())
	{
		i >> *this;
	}
	else
		throw "Greska pri citanju iz fajla!\n";
}

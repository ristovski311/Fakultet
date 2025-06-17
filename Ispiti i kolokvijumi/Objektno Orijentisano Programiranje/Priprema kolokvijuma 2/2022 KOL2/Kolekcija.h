#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
template<class T>
class Kolekcija
{
public:
	Kolekcija(int n);
	~Kolekcija();
	Kolekcija(Kolekcija<T>& t);
	friend ostream& operator<<(ostream& o, Kolekcija<T>& k);
	friend istream& operator>>(istream& i, Kolekcija<T>& k);
	void Ucitaj(string file);
	ostream& Ispisi(ostream& o);
	istream& Upisi(istream& i);
	void Obrisi(int redbr);
	void DodajPodatak(T& t);
	float OdrediProsek();
	T& NajveciPodatak();
	void Sacuvaj(string file);
	int getTrenutno() { return this->trenutno; }
private:
	int max;
	int trenutno;
	T* niz;

};

template <class T>
Kolekcija<T>::Kolekcija(int n)
{
	this->max = n;
	this->trenutno = 0;
	this->niz = new T[max];
}

template<class T>
Kolekcija<T>::~Kolekcija()
{
	delete[] niz;
}

template<class T>
Kolekcija<T>::Kolekcija(Kolekcija<T>& t)
{
	delete[] this->niz;
	this->niz = new T(t.max);
	for (int i = 0; i < t.trenutno; i++)
	{
		this->niz[i] = new T(t.niz[i]);
	}
}

template <class T>
ostream& Kolekcija<T>::Ispisi(ostream& o)
{
	for (int i = 0; i < this->trenutno; i++)
	{
		o << this->niz[i] << endl;
	}
	return o;
}

template <class T>
istream& Kolekcija<T>::Upisi(istream& i)
{
	for (int p = 0; p < this->trenutno; p++)
	{
		i >> this->niz[p];
	}
	return i;
}

template<class T>
ostream& operator<<(ostream& o, Kolekcija<T>& k)
{
	for (int i = 0; i < k.getTrenutno(); i++)
	{
		k.Ispisi(o);
	}
	return o;
}

template<class T>
ostream& operator>>(istream& i, Kolekcija<T>& k)
{
	for (int i = 0; i < k.getTrenutno(); i++)
	{
		k.Upisi(i);
	}
	return i;
}

template<class T>
void Kolekcija<T>::Ucitaj(string file)
{
	ifstream upis(file);
	if (upis.good())
	{
		this->Upisi(upis);
	}
	else
		cout << "Greska pri ucitavanju iz fajla!" << endl;
}

template<class T>
void Kolekcija<T>::Obrisi(int n)
{
	if (n < this->trenutno)
	{
		for (int i = n; i < this->trenutno; i++)
			this->niz[i] = this->niz[i + 1];
		this->trenutno--;
	}
}

template<class T>
void Kolekcija<T>::DodajPodatak(T& t)
{
	if (this->trenutno < this->max)
	{
		this->niz[trenutno] = T(t);
		this->trenutno++;
	}
	else
		cout << "Puna je kolekcija\n";
}

template<class T>
T& Kolekcija<T>::NajveciPodatak()
{
	int maxind = 0;
	for (int i = 1; i < this->trenutno; i++)
	{
		if (this->niz[i] > this->niz[maxind])
			maxind = i;
	}
	return this->niz[maxind];
}

template<class T>
float Kolekcija<T>::OdrediProsek()
{
	float suma = 0;
	for (int i = 0; i < this->trenutno; i++)
	{
		suma = suma + this->niz[i];
	}
	return suma / this->trenutno;
}

template<class T>
void Kolekcija<T>::Sacuvaj(string file)
{
	ofstream ispis(file);
	if (ispis.good())
	{
		this->Ispisi(ispis);
	}
	else
		cout << "Greska pri ispisu u funkciji sacuvaj\n";

}
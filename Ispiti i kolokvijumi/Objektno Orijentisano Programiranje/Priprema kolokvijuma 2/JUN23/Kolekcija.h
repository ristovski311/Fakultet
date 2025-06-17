#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class Kolekcija
{
public:
	Kolekcija(int n);
	Kolekcija(const Kolekcija<T>& k);
	~Kolekcija();
	void Dodaj(T& t, int red);
	template<class T> friend istream& operator>>(istream& i, Kolekcija<T>& k);
	template<class T> friend ostream& operator<<(ostream& o, Kolekcija<T>& k);
	double Razlika(int x);
	double Prosek();
	T& NajvecaPotrosnja();
	T& NajmanjaPotrosnja();
	int BrojSVecomOdAktuelne();
	void Ispisi(const char* file);
	void Citaj(const char* file);
private:
	T trenutno;
	T* istorija;
	int max;
	int zauzeto;
};

template<class T>
Kolekcija<T>::Kolekcija(int n)
{
	this->max = n;
	this->zauzeto = 0;
	this->trenutno = T();
	this->istorija = new T[max];

}


template<class T>
Kolekcija<T>::Kolekcija(const Kolekcija<T>& k)
{
	delete[] this->istorija;
	this->zauzeto = k.trenutno;
	this->max = k.max;
	this->istorija = new T(k.max);
	for (int i = 0; i < k.zauzeto; i++)
	{
		this->istorija[i] = k.istorija[i];
	}
}

template<class T>
Kolekcija<T>::~Kolekcija()
{
	delete[] this->istorija;
}

template<class T>
void Kolekcija<T>::Dodaj(T& t, int red)
{
	if (red == 1 && zauzeto == 0)
	{
		this->trenutno = t;
		zauzeto++;
	}
	else if (red != this->zauzeto + 1 || red > this->max + 1)
		throw "Greska pri dodavanju!";
	else
	{
		this->istorija[zauzeto-1] = this->trenutno;
		this->trenutno = t;
		zauzeto++;
	}
}

template<class T>
istream& operator>>(istream& i, Kolekcija<T>& k)
{
	i >> k.trenutno;
	for (int p = 0; p < k.zauzeto-1; p++)
		i >> k.istorija[p];
	return i;

}

template<class T>
ostream& operator<<(ostream& o, Kolekcija<T>& k)
{
	o << k.trenutno << endl;
	for (int p = 0; p < k.zauzeto-1; p++)
		o << k.istorija[p] << endl;
	return o;

}

template<class T>
double Kolekcija<T>::Razlika(int x)
{
	if (this->zauzeto == 1)
		return 0;
	else if (x > this->zauzeto-2)
		throw "Greska pri trazenju razlike potrosnje";
	else
	{
		return this->trenutno - this->istorija[x];
	}
}

template<class T>
double Kolekcija<T>::Prosek()
{
	double suma = 0;
	if (zauzeto == 1)
		return 1;
	for (int i = 0; i < this->zauzeto-1; i++)
		suma = suma + this->istorija[i];
	return suma / (this->zauzeto - 1);

}

template<class T>
T& Kolekcija<T>::NajvecaPotrosnja()
{
	int max = 0;
	for (int i = 1; i < this->zauzeto-1; i++)
		if (this->istorija[i] > this->istorija[max])
			max = i;
	return this->istorija[max];
}


template<class T>
T& Kolekcija<T>::NajmanjaPotrosnja()
{
	int min = 0;
	for (int i = 1; i < this->zauzeto-1; i++)
		if (this->istorija[min] > this->istorija[i])
			min= i;
	return this->istorija[min];
}

template<class T>
int Kolekcija<T>::BrojSVecomOdAktuelne()
{
	int broj = 0;
	for (int i = 0; i < this->zauzeto-1; i++)
		if (this->istorija[i] > this->trenutno)
			broj++;
	return broj;
}



template<class T>
void Kolekcija<T>::Ispisi(const char* file)
{
	ofstream i(file);
	if (!i.good())
		throw "Greska pri ispisu u fajl";
	i << *this;
}



template<class T>
void Kolekcija<T>::Citaj(const char* file)
{
	ifstream o(file);
	if (!o.good())
		throw "Greska pri citanju iz fajla";
	o >> this->trenutno;
	this->zauzeto++;
	T temp;
	while (o >> temp)
	{
		this->istorija[zauzeto - 1] = temp;
		zauzeto++;
	}
}
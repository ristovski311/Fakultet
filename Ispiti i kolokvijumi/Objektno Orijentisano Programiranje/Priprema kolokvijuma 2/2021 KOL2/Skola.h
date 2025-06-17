#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Skola
{
public:
	Skola(int n);
	Skola(Skola<T>& s);
	~Skola();
	void Dodaj(T& t);
	void Ukloni(int sala);
	float Prosek();
	T& Najvrednija();
	T& NajmanjeVredna();
	istream& Upisi(istream& i);
	ostream& Ispisi(ostream& o);
	template<class T> friend ostream& operator<<(ostream& o, Skola<T>& t);
	template<class T> friend istream& operator>>(istream& i, Skola<T>& t);
	void UpisiIzFajla(string fajl);
	void IspisiUFajl(string fajl);
private:
	T* sale;
	int max;
	int zauzeto;
};

template<class T>
Skola<T>::Skola(int n)
{
	this->max = n;
	this->zauzeto = 0;
	this->sale = new T[n];
}

template<class T>
Skola<T>::~Skola()
{
	delete[] sale;
}

template<class T>
void Skola<T>::Dodaj(T& t)
{
	if (this->zauzeto < this->max)
		this->sale[zauzeto++] = T(t);
	else
		throw "Zauzete su sve sale!\n";
}

template<class T>
void Skola<T>::Ukloni(int sala)
{
	if (sala < this->zauzeto)
	{
		for (int i = sala; i < zauzeto; i++)
			this->sale[i] = this->sale[i + 1];
		zauzeto--;
	}
	else
		throw "Takva sala ne postoji!\n";
}

template<class T>
float Skola<T>::Prosek()
{
	float suma = 0;
	for (int i = 0; i < zauzeto; i++)
		suma = suma + this->sale[i];
	return suma / this->zauzeto;
}

template<class T>
T& Skola<T>::Najvrednija()
{
	int temp = 0;
	for (int i = 1; i < zauzeto; i++)
		if (this->sale[i] > this->sale[temp])
			temp = i;
	return this->sale[temp];
}

template<class T>
T& Skola<T>::NajmanjeVredna()
{
	int temp = 0;
	for (int i = 1; i < zauzeto; i++)
		if (this->sale[temp] > this->sale[i])
			temp = i;
	return this->sale[temp];
}

template<class T>
istream& Skola<T>::Upisi(istream& i)
{
	for (int p = 0; p < this->max && !i.eof(); p++)
	{
		i >> this->sale[p];
		this->zauzeto++;
	}
	return i;
}

template<class T>
ostream& Skola<T>::Ispisi(ostream& o)
{
	for (int i = 0; i < zauzeto; i++)
		o << this->sale[i] << endl;
	return o;
}

template<class T>
ostream& operator<<(ostream& o, Skola<T>& s)
{
	s.Ispisi(o);
	return o;
}

template<class T>
istream& operator>>(istream& i, Skola<T>& s)
{
	s.Upisi(i);
	return i;
}

template<class T>
void Skola<T>::UpisiIzFajla(string fajl)
{
	ifstream upis(fajl);
	if (upis.good())
	{
		this->Upisi(upis);
	}
	else
		throw "Greska pri otvaranju fajla za unos podataka!\n";
}

template<class T>
void Skola<T>::IspisiUFajl(string fajl)
{
	ofstream ispis(fajl);
	if (ispis.good())
	{
		this->Ispisi(ispis);
	}
	else
		throw "Greska pri otvaranju fajla za ispis podataka!\n";
}

template<class T>
Skola<T>::Skola(Skola<T>& s)
{
	s.max = this->max;
	s.zauzeto = this->zauzeto;
	delete[] s.sale;
	s.sale = new T[s.max];
	for (int i = 0; i < this->zauzeto; i++)
		s.sale[i] = this->sale[i];
}
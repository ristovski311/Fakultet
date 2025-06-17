#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class Kontejner
{
public:
	Kontejner(int n);
	Kontejner(const Kontejner<T>& k);
	~Kontejner();
	Kontejner<T>& operator=(const Kontejner<T>& k);
	template<class T> friend istream& operator>>(istream& i, Kontejner<T>& k);
	template<class T> friend ostream& operator<<(ostream& o, Kontejner<T>& k);
	double Prosek();
	void Uredi();
	void Dodaj(T* t);
private:
	T** niz;
	int max;
	int trenutno;
};

template<class T>
Kontejner<T>::Kontejner(int n)
{
	this->max = n;
	this->trenutno = 0;
	this->niz = new T * [max];
	for (int i = 0; i < this->max; i++)
		niz[i] = nullptr;
}

template<class T>
Kontejner<T>::Kontejner(const Kontejner<T>& k)
{
	for (int i = 0; i < this->trenutno; i++)
	{
		delete[] this->niz[i];
	}
	delete[] this->niz;
	this->max = k.max;
	this->trenutno = k.trenutno;
	this->niz = new T * [this->max];
	for (int i = 0; i < this->max; i++)
		this->niz[i] = nullptr;
	for (int i = 0; i < k.trenutno; i++)
		this->niz[i] = k.niz[i];
}

template<class T>
Kontejner<T>& Kontejner<T>::operator=(const Kontejner<T>& k)
{
	for (int i = 0; i < this->trenutno; i++)
	{
		delete[] this->niz[i];
	}
	delete[] this->niz;
	this->max = k.max;
	this->trenutno = k.trenutno;
	this->niz = new T * [this->max];
	for (int i = 0; i < this->max; i++)
		this->niz[i] = nullptr;
	for (int i = 0; i < k.trenutno; i++)
		this->niz[i] = new T();
	for (int i = 0; i < k.trenutno; i++)
		*this->niz[i] = *k.niz[i];
	return *this;
}


template<class T>
Kontejner<T>::~Kontejner()
{
	for (int i = 0; i < this->trenutno; i++)
		if(this->niz[i] != nullptr)
	{
		delete this->niz[i];
	}
	delete[] this->niz;
}


template<class T>
istream& operator>>(istream& i, Kontejner<T>& k)
{
	i >> k.max;
	i >> k.trenutno;
	for (int p = 0; p < k.trenutno; p++)
		k.niz[p] = new T();
	for (int p = 0; p < k.trenutno; p++)
	{
		i >> *k.niz[p];
	}
	return i;
}

template<class T>
ostream& operator<<(ostream& o, Kontejner<T>& k)
{
	o << k.max << endl;
	o << k.trenutno << endl;
	for (int p = 0; p < k.trenutno; p++)
	{
		o << *k.niz[p] << endl;
	}
	return o;
}


template<class T>
double Kontejner<T>::Prosek()
{
	double suma = 0;
	for (int i = 0; i < this->trenutno; i++)
	{
		suma = suma + *this->niz[i];
	}
	return suma / this->trenutno;
}

template<class T>
void Kontejner<T>::Uredi()
{
	T* temp;
	for (int i = 0; i < this->trenutno - 1; i++)
	{
		for(int j = i + 1; j < this->trenutno; j++)
			if (*this->niz[i] > *this->niz[j])
			{
				temp = this->niz[i];
				this->niz[i] = this->niz[j];
				this->niz[j] = temp;
			}
	}
	temp = nullptr;
}


template<class T>
void Kontejner<T>::Dodaj(T* t)
{
	if (this->trenutno < this->max)
	{
		this->niz[trenutno] = new T();
		*this->niz[trenutno] = *t;
		trenutno++;
	}
	else
		throw "Premalo mesta";
}
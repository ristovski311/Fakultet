#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Evidencija
{
public:
	Evidencija(int n);
	Evidencija(Evidencija<T>& e);
	~Evidencija();
	void Dodaj(T& t);
	void Obrisi(int x);
	int UkupnoPosetilaca(int x, int y);
	int* najmanjaZarada();
	ostream& Sacuvaj(ostream& o);
	istream& CitajIzFajla(istream& i);
	template<class T> friend istream& operator>>(istream& i, Evidencija<T>& e);
	template<class T> friend ostream& operator<<(istream& o, Evidencija<T>& e);
private:
	int max;
	int trenutno;
	T* niz;
};

template<class T>
Evidencija<T>::Evidencija(int n)
{
	this->max = n;
	this->trenutno = 0;
	this->niz = new T[max];
}

template<class T>
Evidencija<T>::~Evidencija()
{
	delete[] this->niz;
}

template<class T>
Evidencija<T>::Evidencija(Evidencija<T>& e)
{
	delete[] e.niz;
	e.max = this->max;
	e.trenutno = this->trenutno;
	e.niz = new T[max];
	for (int i = 0; i < this->trenutno; i++)
		e.niz[i] = this->niz[i];
}
template<class T>
void Evidencija<T>:: Dodaj(T& t)
{
	if (this->trenutno < this->max)
		this->niz[trenutno++] = t;
	else
	{
		Evidencija<T> temp(this->max + this->max / 2);
		for(int i = 0; i < this->trenutno; i++)
		{
			temp.niz[i] = this->niz[i];
			temp.trenutno++;
		}
		*this = temp; 
		this->niz[trenutno++] = t;
	}
}

template<class T>
void Evidencija<T>::Obrisi(int n)
{
	if (n <= trenutno)
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < this->trenutno; j++)
				this->niz[j] = this->niz[j + 1];
			trenutno--;
		}
	else
		throw "Greska pri brisanju dana\n";
}

template<class T>
int Evidencija<T>::UkupnoPosetilaca(int x, int y)
{
	int temp = 0;
	if (x >= 0 && x <= this->trenutno && y >= 0 && y < this->trenutno)
	{
		for (int i = x; i <= y; i++)
			temp = temp + this->niz[i];
	}
	else
		throw "Greska pri odredjivanju ukupnog broja posetilaca\n";
	return temp;
}

template<class T>
int* Evidencija<T>::najmanjaZarada()
{
	int* temp = new int[2];
	int min1 = 0;
	int min2 = 1;
	for (int i = 1; i < this->trenutno; i++)
		if (this->niz[min1] > this->niz[i])
			min1 = i;
	for (int i = 0; i < this->trenutno; i++)
		if (i != min1)
		{
			if (this->niz[min2] > this->niz[i])
				min2 = i;
		}
	temp[0] = min1;
	temp[1] = min2;
	return temp;

}

template<class T>
ostream& Evidencija<T>::Sacuvaj(ostream& o)
{
	for (int i = 0; i < this->trenutno; i++)
		o << this->niz[i] << " ";
	return o;
}


template<class T>
istream& Evidencija<T>::CitajIzFajla(istream& i)
{
	T temp;
	while (i >> temp)
	{
		this->niz[trenutno++] = temp;
	}
	return i;
}

template<class T>
istream& operator>>(istream& i, Evidencija<T>& e)
{
	e.Citaj(i);
	return i;
}

template<class T>
ostream& operator<<(ostream& o, Evidencija<T>& e)
{
	e.Sacuvaj(o);
	return o;
}
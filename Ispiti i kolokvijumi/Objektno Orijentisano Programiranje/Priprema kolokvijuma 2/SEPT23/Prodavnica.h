#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class Prodavnica
{
public:
	Prodavnica(const char* naziv_pr = "", int broj_polica = 0);
	Prodavnica(const Prodavnica<T>& p);
	~Prodavnica();
	void Dodaj(T& t);
	Prodavnica<T>& operator=(const Prodavnica<T>& p);
	void Prodaj(int red);
	//void Citaj(istream& i);
	//void Upisi(ostream& o);
	template<class T> friend istream& operator>>(istream& i, Prodavnica<T>& p);
	template<class T> friend ostream& operator<<(ostream& o, Prodavnica<T>& p);
	double SrednjaVrednost();
private:
	char* naziv;
	T* spisak;
	int brojPolica;
	int trenutno;
	const int MAX_NA_POLICI = 5;
};

template<class T>
Prodavnica<T>::Prodavnica(const char* naziv_pr, int broj_polica)
{
	this->naziv = new char[strlen(naziv_pr) + 1];
	strcpy(this->naziv, naziv_pr);
	this->brojPolica = broj_polica;
	this->trenutno = 0;
	this->spisak = new T[broj_polica * MAX_NA_POLICI];
}

template<class T>
Prodavnica<T>::Prodavnica(const Prodavnica<T>& p)
{
	delete[] this->naziv;
	delete[] this->spisak;

	this->naziv = new char[strlen(p.naziv) + 1];
	strcpy(this->naziv, p.naziv);
	this->brojPolica = p.brojPolica;
	this->trenutno = p.trenutno;
	this->spisak = new T[p.brojPolica * MAX_NA_POLICI];
	
	for (int i = 0; i < this->trenutno; i++)
	{
		this->spisak[i] = p.spisak[i];

	}
}

template<class T>
Prodavnica<T>& Prodavnica<T>::operator=(const Prodavnica<T>& p)
{
	if (this != &p)
	{
		delete[] this->naziv;
		delete[] this->spisak;

		this->naziv = new char[strlen(p.naziv) + 1];
		strcpy(this->naziv, p.naziv);
		this->brojPolica = p.brojPolica;
		this->trenutno = p.trenutno;
		this->spisak = new T[p.brojPolica * MAX_NA_POLICI];

		for (int i = 0; i < this->trenutno; i++)
		{
			this->spisak[i] = p.spisak[i];
		}
	}
	return *this;
}

template<class T>
Prodavnica<T>::~Prodavnica()
{
	if(this->naziv != nullptr)
	{
		delete[] this->naziv;
	}
	delete[] this->spisak;
 }

template<class T>
void Prodavnica<T>::Dodaj(T& t)
{
	if (this->trenutno < this->brojPolica * MAX_NA_POLICI)
		this->spisak[trenutno++] = t;
	else
		throw "Prepune su sve police";
}

template<class T>
void Prodavnica<T>::Prodaj(int n)
{
	if (n < this->trenutno)
	{
		for (int i = n; i < trenutno; i++)
			this->spisak[i] = this->spisak[i + 1];
		trenutno--;
	}
	else
		throw "Nevalidan redni broj za prodaju";
}

template<class T>
istream& operator>>(istream& i, Prodavnica<T>& p)
{
	if (p.naziv != nullptr)
		delete[] p.naziv;
	p.naziv = new char[100];
	i >> p.naziv;
	i >> p.trenutno;
	i >> p.brojPolica;
	delete[] p.spisak;
	p.spisak = new T[p.brojPolica * 5];
	for (int j = 0; j < p.trenutno; j++)
		i >> p.spisak[j];
	return i;
}

template<class T>
ostream& operator<<(ostream& o, Prodavnica<T>& p)
{
	o << p.naziv << endl;
	o << p.trenutno << endl;
	o << p.brojPolica << endl;
	for (int i = 0; i < p.trenutno; i++)
		o << p.spisak[i] << endl;
	return o;

}

template<class T>
double Prodavnica<T>::SrednjaVrednost()
{
	double suma = 0;
	for (int i = 0; i < this->trenutno; i++)
		suma = suma + this->spisak[i];
	return suma / trenutno;
}

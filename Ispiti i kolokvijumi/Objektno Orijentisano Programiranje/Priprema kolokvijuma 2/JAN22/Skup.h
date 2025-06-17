#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class Skup
{
public:
	Skup();
	Skup(int n);
	Skup(const Skup<T>& s);
	~Skup();
	Skup<T>& operator=(const Skup<T>& t);
	void Dodaj(T& t);
	void Brisi(int t);
	Skup<T> Unija(Skup<T>& s2);
	template<class T> friend istream& operator>>(istream& i, Skup<T>& s);
	template<class T> friend ostream& operator<<(ostream& o, Skup<T>& s);
private:
	T* niz;
	int max;
	int trenutno;
};

template<class T>
Skup<T>::Skup()
{
	this->max = 0;
	this->trenutno = 0;
	this->niz = nullptr;
}

template<class T>
Skup<T>::Skup(int n)
{
	this->max = n;
	this->trenutno = 0;
	this->niz = new T[max];
}

template<class T>
Skup<T>::Skup(const Skup<T>& s)
{
	delete[] this->niz;
	this->niz = new T[s.max];
	this->max = s.max;
	this->trenutno = s.trenutno;
	for (int i = 0; i < this->trenutno; i++)
		this->niz[i] = s.niz[i];
}

template<class T>
Skup<T>& Skup<T>::operator=(const Skup<T>& s)
{
	if (this == &s)
		return *this;
	else
	{
		delete[] this->niz;
		this->niz = new T[s.max];
		this->max = s.max;
		this->trenutno = s.trenutno;
		for (int i = 0; i < this->trenutno; i++)
			this->niz[i] = s.niz[i];
		return *this;
	}
}

template<class T>
Skup<T>::~Skup()
{
	delete[] this->niz;
}

template<class T>
void Skup<T>::Dodaj(T& t)
{
	if (trenutno >= this->max)
		throw "Nema mesta";
	bool found = 0;
	for (int i = 0; i < this->trenutno; i++)
	{
		if (t == this->niz[i])
			found = 1;
	}

	if (found == 1)
		throw "Isti podatak";
	this->niz[trenutno++] = t;
}

template<class T>
void Skup<T>::Brisi(int t)
{
	if (t >= this->trenutno)
		throw "Greska pri brisanju";
	for (int i = t; i < this->trenutno; i++)
		this->niz[i] = this->niz[i + 1];
	trenutno--;
}

template<class T>
Skup<T> Skup<T>::Unija(Skup<T>& s2)
{
	Skup<T> temp(this->max + s2.max);
	temp.trenutno = 0;
	for (int i = 0; i < this->trenutno; i++)
	{
		temp.niz[i] = this->niz[i];
		temp.trenutno++;
	}

	for (int i = this->trenutno; i < this->trenutno + s2.trenutno; i++)
	{
		bool found = 0;
		for (int j = 0; j < temp.trenutno && !found; j++)
			if (temp.niz[j] == s2.niz[i - this->trenutno])
				found = 1;
		if(!found)
		{
			temp.niz[temp.trenutno] = s2.niz[i - this->trenutno];
			temp.trenutno++;
		}
	}
		
	return temp;
}

template<class T>
istream& operator>>(istream& i, Skup<T>& s)
{
	//delete[] s.niz;
	//i >> s.max;
	//i >> s.trenutno;
	//s.niz = new T[s.max];
	/*for (int p = 0; p < s.trenutno; p++)
	{
		i >> s.niz[p];
	}*/

	T temp;
	while (i >> temp)
	{
		s.niz[s.trenutno++] = temp;
	}

	return i;
}

template<class T>
ostream& operator<<(ostream& o, Skup<T>& s)
{
	o << s.max << endl;
	o << s.trenutno << endl;
	for (int i = 0; i < s.trenutno; i++)
	{
		o << s.niz[i] << endl;
	}

	return o;
}
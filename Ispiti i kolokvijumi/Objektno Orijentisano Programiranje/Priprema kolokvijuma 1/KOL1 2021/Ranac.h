#pragma once
#include "Predmet.h"
#include <iostream>
using namespace std;
class Ranac
{
public:
	Ranac(int n)
	{
		max = n;
		trenutno = 0;
		sadrzaj = new Predmet * [max];
		for (int i = 0; i < max; i++)
			sadrzaj[i] = nullptr;
	}
	~Ranac()
	{
		for (int i = 0; i < max; i++)
			if (sadrzaj[i] != nullptr)
				delete sadrzaj[i];
		delete[] sadrzaj;
		sadrzaj = nullptr;
	}
	void dodaj(Predmet* p)
	{
		if (trenutno < max)
			sadrzaj[trenutno++] = p;
		else
			cout << "Ranac je pun!\n";
	}
	ostream& prikaz(ostream& o)
	{
		o << "Predmeta u rancu: " << trenutno << "/" << max << endl;
		for (int i = 0; i < trenutno; i++)
			if (sadrzaj[i] != nullptr)
				o << *sadrzaj[i];
		return o;
	}
	double srednjaVrednost()
	{
		double temp = 0;
		int ima = 0;
		for (int i = 0; i < trenutno; i++)
			if (sadrzaj[i] != nullptr)
			{
				temp += sadrzaj[i]->vrednost();
				ima++;
			}
		return temp / ima;
	}
	Predmet* najvredniji()
	{
		int temp = 0;
		for (int i = 1; i < trenutno; i++)
			if (sadrzaj[i] != nullptr)
				if (sadrzaj[i]->vrednostPoMasi() > sadrzaj[temp]->vrednostPoMasi())
					temp = i;
		return sadrzaj[temp];
	}
private:
	Predmet** sadrzaj;
	int max;
	int trenutno;
};


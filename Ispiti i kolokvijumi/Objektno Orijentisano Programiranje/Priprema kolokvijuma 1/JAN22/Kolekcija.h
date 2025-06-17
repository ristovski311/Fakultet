#pragma once
#include "Figura.h"
#include "Kvadrat.h"
class Kolekcija
{
public:
	Kolekcija(int max)
	{
		this->max = max;
		this->trenutno = 0;
		this->niz = new Figura * [max];
		for (int i = 0; i < max; i++)
			niz[i] = nullptr;
	}
	~Kolekcija()
	{
		for (int i = 0; i < trenutno; i++)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
		niz = nullptr;
	}
	void dodaj(Figura* f)
	{
		if (trenutno < max)
			niz[trenutno++] = f;
		else
		{
			this->max += this->max;
			cout << "Povecan kapacitet\n";
		}
	}
	double povrsinaSvih()
	{
		double ukupno = 0;
		for (int i = 0; i < trenutno; i++)
			if (niz[i] != nullptr)
				ukupno += niz[i]->povrsina();
		return ukupno;
	}
	double obimSvih()
	{
		double ukupno = 0;
		for (int i = 0; i < trenutno; i++)
			if (niz[i] != nullptr)
				ukupno += niz[i]->obim();
		return ukupno;
	}
	Kolekcija& sortiraj()
	{
		Figura* temp;
		for (int i = 0; i < trenutno - 1; i++)
			if(niz[i] != nullptr)
				for(int j = i + 1; j < trenutno; j++)
					if(niz[j] != nullptr)
						if (niz[j]->obim() < niz[i]->obim())
						{
							temp = niz[j];
							niz[j] = niz[i];
							niz[i] = temp;
						}
		temp = nullptr;
		return *this;
	}
	ostream& upis(ostream& o)
	{
		o << "Max elemenata kolekcije: " << max << endl;
		o << "Trenutno elemenata u kolekciji: " << trenutno << endl;
		for (int i = 0; i < trenutno; i++)
			if (niz[i] != nullptr)
			{
				niz[i]->upis(o);
				o << endl;
			}
		return o;
	}
private:
	Figura** niz;
	int max;
	int trenutno;
};



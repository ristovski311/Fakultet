#pragma once
#include "Paragraf.h"
#include <fstream>
class Tekst
{
public:
	Tekst(int max = 0)
	{
		maxDuzina = max;
		duzina = 0;
		nizPar = new Paragraf * [max];
		for (int i = 0; i < max; i++)
			nizPar[i] = nullptr;
	}
	~Tekst()
	{
		for (int i = 0; i < maxDuzina; i++)
		{
			if (nizPar != nullptr && nizPar[i] != nullptr)
				delete nizPar[i];
		}
		delete[] nizPar;
		nizPar = nullptr;
	}
	void Dodaj(Paragraf* p)
	{
		if (duzina < maxDuzina)
		{
			nizPar[duzina] = p;
			duzina++;
		}
		else
		{
			cout << "Nema dovoljno mesta!" << endl;
			maxDuzina += maxDuzina;
			cout << "Povecana duzina za: " << maxDuzina / 2 << endl;

		}
	}
	void Upisi(const char* putanja)
	{
		ofstream upis(putanja);
		if (upis.good())
		{
			upis << "Duzina teksta: " << this->duzina << " paragrafa." << endl;
			upis << "Max duzina teksta: " << this->maxDuzina << " paragrafa." << endl;
			for (int i = 0; i < duzina; i++)
				if (nizPar[i] != nullptr)
				{
					nizPar[i]->upisiPar(upis);
					upis << endl;
				}
			upis.close();
		}
	}

	void Citaj(const char* putanja)
	{
		ifstream ispis(putanja);
		if (ispis.good())
		{
			char temp;

			ispis >> this->duzina;
			ispis >> this->maxDuzina;
			ispis.get(temp);
			
			for (int i = 0; i < this->duzina; i++)
			{
				nizPar[i]->ispisiPar(ispis);
				ispis.get(temp);
			}

			ispis.close();
		}
		else
			cout << "Putanja ne radi!" << endl;
	}
private:
	Paragraf** nizPar;
	int duzina;
	int maxDuzina;
};


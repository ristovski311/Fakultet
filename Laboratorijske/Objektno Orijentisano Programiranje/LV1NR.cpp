//MAIN

#include "Matrica.h"
#include <iostream>

using namespace std;
int main()
{
	Matrica matrica1(4, 3);
	matrica1.PostaviSve();
	double sumaKolona = matrica1.SumaKolone(0) + matrica1.SumaKolone(2);
	double sumaVrsta = matrica1.SumaVrste(1) + matrica1.SumaVrste(2);
	cout << endl << "Suma 1. i 3. kolone je: " << sumaKolona << endl << "Suma 2. i 3. vrste je: " << sumaVrsta << endl << endl;
	matrica1.Prikazi();
	return 1;
}



//.H HEADER

#pragma once

class Matrica
{
public:
	//Konstruktor bez parametara
	Matrica();
	//Konstruktor za postavljanje dimenzija
	Matrica(int kolona, int vrsta);
	//Copy konstruktor
	Matrica(const Matrica& m);
	//Destruktor
	~Matrica();
	//Inline za kolone
	int VratiDimKol() const
	{
		return this->dimKolona;
	}
	//Inline za vrste
	int VratiDimVrs() const
	{
		return this->dimVrsta;
	}
	//Suma trazene vrste
	double SumaVrste(int i) const;
	//Suma trazene kolone
	double SumaKolone(int j) const;
	//Unos svih elemenata
	void PostaviSve();
	//Unos zeljenog elementa
	void PostaviEl();
	//Prikaz matrice
	void Prikazi() const;
	//Razunanje kronekerovog proizvoda
	Matrica Kroneker(const Matrica& m2) const;
	//Racunanje proizvoda
	Matrica Proizvod(const Matrica& m2) const;
	//Prikazi naziv
	void PrikaziNaziv() const;
	//Postavi naziv
	void PostaviNaziv();
private:
	int dimKolona;
	int dimVrsta;
	double** matrica;
	char* naziv;
};





//.CPP FUNCTIONS

#include "Matrica.h"
#include <iostream>

using namespace std;
//Kontruktor bez parametara
Matrica::Matrica()
{
	this->dimKolona = 20;
	this->dimVrsta = 20;
	this->naziv = new char[100];
	//cout << "Unesi naziv matrice: ";
	//cin >> this->naziv;
	this->naziv[0] = '\0';

	this->matrica = new double* [this->dimVrsta];
	for (int i = 0; i < this->dimVrsta; i++)
		this->matrica[i] = new double[this->dimKolona];
}
//Konstruktor za postavljanje dimenzija matrice
Matrica::Matrica(int vrsta, int kolona)
{
	this->dimKolona = kolona;
	this->dimVrsta = vrsta;
	this->naziv = new char[100];
	//cout << "Unesi naziv matrice: ";
	//cin >> this->naziv;
	this->naziv[0] = '\0';

	this->matrica = new double* [this->dimVrsta];
	for (int i = 0; i < this->dimVrsta; i++)
		this->matrica[i] = new double[this->dimKolona];
}
//Destruktor
Matrica::~Matrica()
{
	if (matrica != 0)
	{
		for (int i = 0; i < this->dimVrsta; i++)
			delete[] this->matrica[i];
		delete[] matrica;
	}
	if (naziv != 0)
	{
		delete[] naziv;
	}
}
//Copy konstruktor
Matrica::Matrica(const Matrica& m)
{
	this->dimKolona = m.dimKolona;
	this->dimVrsta = m.dimVrsta;
	this->matrica = new double* [this->dimVrsta];
	for (int i = 0; i < this->dimVrsta; i++)
		this->matrica[i] = new double[this->dimKolona];

	for (int i = 0; i < dimVrsta; i++)
		for (int j = 0; j < dimKolona; j++)
			this->matrica[i][j] = m.matrica[i][j];

	int naziv_len = 0;
	while (m.naziv[naziv_len++] != '\0');
	this->naziv = new char[naziv_len];
	for (int i = 0; i < naziv_len; i++)
		this->naziv[i] = m.naziv[i];
	this->naziv[naziv_len - 1] = '\0';
}
//Vraca sumu trazene vrste/reda
double Matrica::SumaVrste(int i /*Misli se na indeks vrste*/) const
{
	double sum = 0;
	for (int p = 0; p < this->dimKolona; p++)
	{
		sum += this->matrica[i][p];
	}
	return sum;
}
//Vraca sumu trazene kolone
double Matrica::SumaKolone(int j /*Misli se na indeks kolone*/) const
{
	double sum = 0;
	for (int p = 0; p < this->dimVrsta; p++)
	{
		sum += this->matrica[p][j];
	}
	return sum;
}
//Postavlja odredjeni element matrice
void Matrica::PostaviEl()
{
	int i, j;
	cout << "Unesi vrstu u koju upisujes: ";
	cin >> i;
	cout << endl << "Unesi kolonu u koju upisujes: ";
	cin >> j;
	cout << endl << "Unesi novi element matrice: ";
	cin >> this->matrica[i][j];
}
//Postavlja sve elemente matrice sa standardnog ulaza
void Matrica::PostaviSve()
{
	for (int i = 0; i < this->dimVrsta; i++)
	{
		for (int j = 0; j < this->dimKolona; j++)
		{
			cout << "Unesi element matrice" << endl;
			cin >> matrica[i][j];
		}
	}
}
//Prikazuje matricu na standardni izlaz
void Matrica::Prikazi() const
{
	cout << endl;
	for (int i = 0; i < this->dimVrsta; i++)
	{
		cout << "| ";
		for (int j = 0; j < this->dimKolona; j++)
		{
			cout << matrica[i][j] << "  ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}
//Racunanje kronekerovog proizvoda dve matrice
Matrica Matrica::Kroneker(const Matrica& m2) const
{
	Matrica rez_matrica(this->dimVrsta * m2.dimVrsta, this->dimKolona * m2.dimKolona);
	for (int a = 0; a < this->dimVrsta; a++)
	{
		for (int b = 0; b < this->dimKolona; b++)
		{
			for (int c = 0; c < m2.dimVrsta; c++)
			{
				for (int d = 0; d < m2.dimKolona; d++)
				{
					rez_matrica.matrica[a*(m2.dimVrsta) + c][b * (m2.dimKolona) + d] = m2.matrica[c][d] * this->matrica[a][b];
				}
			}
		}
	}
	return rez_matrica;
}
//Racuna proizvod dve matrice
Matrica Matrica::Proizvod(const Matrica& m2) const
{
	if (this->dimKolona != m2.dimVrsta)
	{
		cout << endl << "!! MATRICE NISU KOMPATIBILNE ZA MNOZENJE, VRACENA POCETNA MATRICA KAO REZULTAT!" << endl;
		return (*this);
	}
	Matrica rez_matrica(this->dimVrsta, m2.dimKolona);
	double s = 0;
	for (int i = 0; i < this->dimVrsta; i++)
	{
		for (int j = 0; j < m2.dimKolona; j++)
		{
			s = 0;
			for (int k = 0; k < m2.dimVrsta; k++)
			{
				s += this->matrica[i][k] * m2.matrica[k][j];
			}
			rez_matrica.matrica[i][j] = s;
		}
	}
	return rez_matrica;
}
//Prikazuje naziv matrice
void Matrica::PrikaziNaziv() const
{
	if (this->naziv[0] != '\0')
		cout << endl << this->naziv << endl;
	else
		cout << endl << "Matrica nema naziv!" << endl;
}

//Postavlja naziv matrice
void Matrica::PostaviNaziv()
{
	cout << endl << "Unesite naziv matrice: ";
	cin >> this->naziv;
}
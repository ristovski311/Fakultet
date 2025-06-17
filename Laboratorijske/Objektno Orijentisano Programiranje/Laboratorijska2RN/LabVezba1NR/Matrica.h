#pragma once
#include "Tacka.h"

class Matrica
{
public:
	//Inicijalizacija matrice
	void Inic(int vrsta, int kolona);

	//Brisanje
	void Del();

	//Kopiranje naziva matrice
	void CopyName(const Matrica& m2);

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
	Tacka SumaVrste(int i) const;

	//Suma trazene kolone
	Tacka SumaKolone(int j) const;

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

	//Operacijska f-ja =
	Matrica& operator=(const Matrica& m2);

	//Operacijska f-ja >>
	friend istream& operator>>(istream& ulaz, Matrica& m);

	//Operacijska f-ja <<
	friend ostream& operator<<(ostream& izlaz, Matrica& m);

	//Operacijska f-ja ++ (postfix)
	Matrica& operator++(int n);

	//Vraca trazenu tacku
	Tacka& VratiTacku(double x, double y, double z);

	//Normalizacija tacaka
	Matrica& Normalizuj(double x1, double x2, double y1, double y2, double z1, double z2);

private:
	int dimKolona;
	int dimVrsta;
	Tacka*** matrica;
	char* naziv;
};

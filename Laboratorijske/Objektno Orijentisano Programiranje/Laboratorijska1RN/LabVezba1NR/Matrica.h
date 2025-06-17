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


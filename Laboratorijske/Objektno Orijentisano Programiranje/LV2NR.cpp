//MAIN 

#include "Matrica.h"
#include "Tacka.h"
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	Matrica* matrica1 = new Matrica(4, 5);
	Matrica* matrica2 = new Matrica(5, 2);

	ifstream ulaz1("Matrica1.txt");
	ifstream ulaz2("Matrica2.txt");
	ofstream izlaz("Matrica3.txt");

	if (ulaz1.good())
	{
		ulaz1 >> *matrica1;
		if (izlaz.good())
		{
			izlaz << *matrica1;
			izlaz.close();
		}
		cout << "Matrica 1: \n" << *matrica1;
		ulaz1.close();
	}

	matrica1->PostaviEl();
	matrica1->Prikazi();
	cout << endl << *matrica1;

	matrica1->PostaviNaziv();
	matrica2->PostaviNaziv();
	matrica1->PrikaziNaziv();
	matrica2->PrikaziNaziv();

	if (ulaz2.good())
	{
		ulaz2 >> *matrica2;
		cout << "Matrica 2: \n" << *matrica2;
		ulaz2.close();
	}

	Tacka* rezultat_tacka = new Tacka();
	*rezultat_tacka = matrica1->SumaVrste(0) + matrica1->SumaVrste(2) + matrica1->SumaKolone(1) + matrica1->SumaKolone(4);
	cout << "Rezultat sabiranja kolona i vrsta: " << *rezultat_tacka << "\n\n";

	matrica1->Normalizuj(3, 4, 3, 4, 3, 4);
	cout << "Normalizovana matrica 1: \n" << *matrica1;

	(*matrica1)++;
	cout <<"Matrica 1 inkrementirana: \n" << *matrica1;

	Matrica* matrica3 = new Matrica();
	*matrica3 = matrica1->Proizvod(*matrica2);
	cout << "Proizvod matrica 1 i 2: \n" << *matrica3;

	Matrica* matrica4 = new Matrica();
	*matrica4 = matrica2->Kroneker(*matrica1);
	cout << "Kronekerov proizvod matrica 2 i 1: \n" << *matrica4;

	*matrica1 = *matrica2;

	cout << "Matrice 1 i 2 nakon dodele matrice 2 matrici 1: \n";
	matrica1->PrikaziNaziv();
	cout << *matrica1;
	matrica2->PrikaziNaziv();
	cout << *matrica2;

	cout << "Trazimo tacku (1,1,1) u matrici 2: " << matrica2->VratiTacku(1, 1, 1) << "\n\n";
	cout << "Trazimo tacku (10, 10, 10) u matrici 2: \n";
	cout << matrica2->VratiTacku(10, 10, 10) << endl;



}





//MATRICA HEADER-------------------------------------------------------------------------------------------------------

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




//MATRICA CPP ------------------------------------------------------------------------------------------------------------

#include "Matrica.h"
#include "Tacka.h"
#include <iostream>

using namespace std;

//Inicijalizacija matrice
void Matrica::Inic(int vrsta, int kolona)
{
	this->dimKolona = kolona;
	this->dimVrsta = vrsta;
	this->naziv = new char[100];
	this->naziv[0] = '\0';

	this->matrica = new Tacka** [this->dimVrsta];
	for (int i = 0; i < this->dimVrsta; i++)
		this->matrica[i] = new Tacka* [this->dimKolona];

	for (int i = 0; i < this->dimVrsta; i++)
	{
		for (int j = 0; j < this->dimKolona; j++)
		{
			this->matrica[i][j] = new Tacka();
		}
	}
}

//Brisanje podataka iz dinamicke zone
void Matrica::Del()
{
	if (matrica != 0)
	{
		for (int i = 0; i < this->dimVrsta; i++)
		{
			for (int j = 0; j < this->dimKolona; j++)
				delete[] this->matrica[i][j];
			delete[] matrica[i];
		}
		delete[] matrica;
	}
	if (naziv != 0)
	{
		delete[] naziv;
	}
}

//Kopiranje naziva matrice
void Matrica::CopyName(const Matrica& m2)
{
	int naziv_len = 0;
	while (m2.naziv[naziv_len++] != '\0');
	delete[] this->naziv;
	this->naziv = new char[naziv_len];
	for (int i = 0; i < naziv_len; i++)
		this->naziv[i] = m2.naziv[i];
	this->naziv[naziv_len - 1] = '\0';
}

//Default konstruktor
Matrica::Matrica()
{
	this->Inic(20, 20); 
}

//Konstruktor za postavljanje dimenzija matrice
Matrica::Matrica(int vrsta, int kolona)
{
	this->Inic(vrsta, kolona);
}

//Operacijska f-ja =
Matrica& Matrica::operator=(const Matrica& m2)
{
	if (this != &m2)
	{
		this->Del();
		this->Inic(m2.dimVrsta, m2.dimKolona);
		for (int i = 0; i < this->dimVrsta; i++)
			for (int j = 0; j < this->dimKolona; j++)
			{
				delete this->matrica[i][j];
				this->matrica[i][j] = new Tacka(*m2.matrica[i][j]);
			}
		this->CopyName(m2);
		return *this;
	}
	return *this;
}

//Destruktor
Matrica::~Matrica()
{
	this->Del();
}

//Copy konstruktor
Matrica::Matrica(const Matrica& m)
{
	this->Inic(m.dimVrsta, m.dimKolona);
	for (int i = 0; i < dimVrsta; i++)
		for (int j = 0; j < dimKolona; j++)
		{
			delete this->matrica[i][j];
			this->matrica[i][j] = new Tacka(*m.matrica[i][j]);
		}
	this->CopyName(m);
}

//Vraca sumu trazene vrste/reda
Tacka Matrica::SumaVrste(int i /*Misli se na indeks vrste*/) const
{
	Tacka sum;
	for (int p = 0; p < this->dimKolona; p++)
	{
		sum += *matrica[i][p];
	}
	return sum;
}
//Vraca sumu trazene kolone
Tacka Matrica::SumaKolone(int j /*Misli se na indeks kolone*/) const
{
	Tacka sum;
	for (int p = 0; p < this->dimVrsta; p++)
	{
		sum += *matrica[p][j];
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
	if (i > -1 && i < this->dimVrsta && j > -1 && j < this->dimKolona)
	{
		cout << endl << "Unesi novi element matrice: ";
		cin >> *matrica[i][j];
	}
	else
	{
		cout << endl << "POGRESNI INDEKSI!" << endl;
		return;
	}
}
//Postavlja sve elemente matrice sa standardnog ulaza
void Matrica::PostaviSve()
{
	for (int i = 0; i < this->dimVrsta; i++)
	{
		for (int j = 0; j < this->dimKolona; j++)
		{
			cout << "Unesi element matrice" << endl;
			cin >> *matrica[i][j];
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
			cout << *matrica[i][j] << "  ";
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
					*rez_matrica.matrica[a*(m2.dimVrsta) + c][b * (m2.dimKolona) + d] = *m2.matrica[c][d] * *this->matrica[a][b];
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
	Tacka s;

	for (int i = 0; i < this->dimVrsta; i++)
	{
		for (int j = 0; j < m2.dimKolona; j++)
		{
			s.Postavi(0, 0, 0);
			for (int k = 0; k < m2.dimVrsta; k++)
			{
				Tacka r(0,0,0);
				r = *matrica[i][k] * *m2.matrica[k][j];
				s += r;
			}
			*rez_matrica.matrica[i][j] = s;
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
	delete this->naziv;
	this->naziv = new char[100];
	cin >> this->naziv;
}

//Operacijska f-ja >>
istream& operator>>(istream& ulaz, Matrica& m)
{
	for (int i = 0; i < m.dimVrsta; i++)
	{
		for (int j = 0; j < m.dimKolona; j++)
		{
			ulaz >> *m.matrica[i][j];
		}
	}
	return ulaz;
}

//Operacijska f-ja <<
ostream& operator<<(ostream& izlaz, Matrica& m)
{
	for (int i = 0; i < m.dimVrsta; i++)
	{
		izlaz << "| ";
		for (int j = 0; j < m.dimKolona; j++)
		{
			izlaz << *m.matrica[i][j] << " ";
		}
		izlaz << " |" << "\n";
	}
	izlaz << "\n";
	return izlaz;
}

//Operatorska f-ja ++ post
Matrica& Matrica::operator++(int n)
{
	Matrica temp(this->dimVrsta, this->dimKolona);
	temp = *this;
	for (int i = 0; i < this->dimVrsta; i++)
		for (int j = 0; j < this->dimKolona; j++)
			(*this->matrica[i][j])++;
	return temp;
}

//Vracanje trazene tacke
Tacka& Matrica::VratiTacku(double x, double y, double z) 
{
	Tacka pomocna_tacka(x, y, z);
	bool found = 0;
	for (int i = 0; i < this->dimVrsta && !found; i++)
	{
		for (int j = 0; j < this->dimKolona && !found; j++)
		{
			if (pomocna_tacka == *this->matrica[i][j])
			{
				found = 1;
				return *this->matrica[i][j];
			}
		}
	}
	if (!found)
	{
		cout << "Nije pronadjena takva tacka u matrici, vracena nula-tacka." << endl;
		return *new Tacka(0, 0, 0);
	}
}

//Normalizacija tacaka
Matrica& Matrica::Normalizuj(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
{
	double xnew, ynew, znew;
	for (int i = 0; i < this->dimVrsta; i++)
	{
		for (int j = 0; j < this->dimKolona; j++)
		{
			if (this->matrica[i][j]->GetX() < xmin)
				xnew = xmin;
			else if (this->matrica[i][j]->GetX() > xmax)
				xnew = xmax;
			else
				xnew = this->matrica[i][j]->GetX();

			if (this->matrica[i][j]->GetY() < ymin)
				ynew = ymin;
			else if (this->matrica[i][j]->GetY() > ymax)
				ynew = ymax;
			else
				ynew = this->matrica[i][j]->GetY();

			if (this->matrica[i][j]->GetZ() < zmin)
				znew = zmin;
			else if (this->matrica[i][j]->GetZ() > zmax)
				znew = zmax;
			else
				znew = this->matrica[i][j]->GetZ();

			this->matrica[i][j]->Postavi(xnew, ynew, znew);
		}
	}

	return *this;
}



//TACKA HEADER ----------------------------------------------------------------------------------------------


#pragma once
#include <iostream>
using namespace std;

class Tacka
{
public:
	double GetX() { return this->x; }
	double GetY() { return this->y; }
	double GetZ() { return this->z; }
	//Default konstruktor
	Tacka()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	//Konstruktor za postavljanje zeljenih vrednosti
	Tacka(double x, double y, double z);
	//Operatorska f-ja za ulaz
	friend istream& operator>>(istream& ulaz, Tacka& t);
	//Operatorska f-ja za izlaz
	friend ostream& operator<<(ostream& izlaz, Tacka& t);
	//Operatorska f-ja za sabiranje
	Tacka& operator+(Tacka& t2);
	//Operatorska f-ja za sabiranje 2
	Tacka operator+(Tacka t2);
	//Operatorska f-ja za oduzimanje
	Tacka operator-(Tacka& t2);
	//Operatorska f-ja +=
	Tacka operator+=(Tacka& t2);
	//Operatorska f-ja *
	Tacka operator*(Tacka& t2);
	//Postavlja x,y,z
	Tacka& Postavi(double x, double y, double z);
	//Operatorska f-ja ++
	Tacka& operator++(int n);
	//Operatorska f-ja ==
	bool operator==(Tacka& t2);

private:
	double x;
	double y;
	double z;
};




//TACKA CPP------------------------------------------------------------------------------------------------------

#include "Tacka.h"


Tacka::Tacka(double x, double y, double z) : x(x), y(y), z(z) {}

istream& operator>>(istream& ulaz, Tacka& t)
{
	ulaz >> t.x;
	ulaz >> t.y;
	ulaz >> t.z;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Tacka& t)
{
	izlaz << "(" << t.x << "," << t.y << "," << t.z << ")";
	return izlaz;
}

Tacka& Tacka::operator+(Tacka& t2)
{
	Tacka t3;
	t3.x += this->x + t2.x;
	t3.y += this->y + t2.y;
	t3.z += this->z + t2.z;
	return t3;
}

Tacka Tacka::operator+(Tacka t2)
{
	Tacka t3;
	t3.x += this->x + t2.x;
	t3.y += this->y + t2.y;
	t3.z += this->z + t2.z;
	return t3;
}

Tacka Tacka::operator-(Tacka& t2)
{
	Tacka t3;
	t3.x += this->x - t2.x;
	t3.y += this->y - t2.y;
	t3.z += this->z - t2.z;
	return t3;
}

Tacka Tacka::operator+=(Tacka& t2)
{
	this->x += t2.x;
	this->y += t2.y;
	this->z += t2.z;

	return *this;
}

Tacka Tacka::operator*(Tacka& t2)
{
	Tacka t3;
	t3.x = this->x * t2.x;
	t3.y = this->y * t2.y;
	t3.z = this->z * t2.z;
	return t3;
}

Tacka& Tacka::Postavi(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return *this;
}

Tacka& Tacka::operator++(int n)
{
	this->x++;
	this->y++;
	this->z++;
	return *this;
}

bool Tacka::operator==(Tacka& t2)
{
	if (this->x == t2.x && this->y == t2.y && this->z == t2.z)
		return true;
	else
		return false;
}
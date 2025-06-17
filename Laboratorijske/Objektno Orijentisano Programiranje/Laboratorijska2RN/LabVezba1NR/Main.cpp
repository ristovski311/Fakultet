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

	matrica1->SumaKolone(10);

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
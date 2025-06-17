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
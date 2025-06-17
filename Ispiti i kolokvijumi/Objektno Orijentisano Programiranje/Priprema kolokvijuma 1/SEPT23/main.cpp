#include "Kupovina.h"
#include "KupovinaOdmah.h"
#include "KupovinaRate.h"
#include "Evidencija.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	Evidencija* e1 = new Evidencija(6);

	KupovinaOdmah* ko1 = new KupovinaOdmah("a1", 11, 10, 100, 20);
	KupovinaRate* kr2 = new KupovinaRate("b2", 13, 7, 50, 30, 10, 4, 10, 2);
	KupovinaOdmah* ko3 = new KupovinaOdmah("a3", 12, 5, 10, 0);
	KupovinaRate* kr4 = new KupovinaRate("b4", 14, 4, 100, 10, 20, 5, 4, 1);
	KupovinaOdmah* ko5 = new KupovinaOdmah("a5", 13, 15, 200, 10);
	KupovinaRate* kr6 = new KupovinaRate("b6", 13, 4, 1000, 40, 300, 10, 15, 5);

	e1->dodaj(ko1);
	e1->dodaj(kr2);
	e1->dodaj(ko3);
	e1->dodaj(kr4);
	e1->dodaj(ko5);
	e1->dodaj(kr6);

	e1->brisi("a5");

	ofstream is("ispis.txt");

	e1->spisak(is);

	cout << "\n\n";

	e1->najjeftinija()->ispisi(cout);
	cout << "\n\n";
	e1->najskuplja()->ispisi(cout);
	cout << "\n\n";
	cout << e1->brojKupovina(13, 3, 10);
	cout << "\n\n";
	cout << e1->ukupnaCena(3, 10);
	cout << "\n\n";
	cout << e1->dugovanje(5, 100);

	KupovinaOdmah* kup = new KupovinaOdmah("c1", 10, 10, 100, 10);
	e1->dodaj(kup);

}
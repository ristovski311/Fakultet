#include "Kolekcija.h"
#include "Pravougaonik.h"
#include "Figura.h"
#include "Kvadrat.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream ispis("figure_izlaz.txt");
	ofstream sort("sortirano.txt");
	Kolekcija* kol1 = new Kolekcija(10);
	Kvadrat* kvadrat1 = new Kvadrat(1, 1, 10);
	Kvadrat* kvadrat3 = new Kvadrat(3, 6, 20);
	Pravougaonik* prav2 = new Pravougaonik(4, 4, 4, 10);
	Pravougaonik* prav4 = new Pravougaonik(2, 2, 2, 5);
	kol1->dodaj(kvadrat1);
	kol1->dodaj(kvadrat3);
	kol1->dodaj(prav2);
	kol1->dodaj(prav4);
	kol1->upis(ispis);
	kol1->sortiraj();
	kol1->upis(sort);
	cout << kol1->povrsinaSvih() << " " << kol1->obimSvih();




}
#include "Saonica.h"
#include "Paketic.h"
#include "PaketicHrana.h"
#include "PaketicIgracka.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream paketici("pokloni.txt");
	Saonica* saonica1 = new Saonica(6);
	PaketicIgracka* igracka1 = new PaketicIgracka("plavi", "Jovana1", 2, 100, 100);
	PaketicIgracka* igracka3 = new PaketicIgracka("zeleni", "Marka23", 5, 50, 50);
	PaketicIgracka* igracka5 = new PaketicIgracka("crveni", "Jovana3", 4, 100, 60);
	PaketicHrana* hrana2 = new PaketicHrana("roze", "Marka1", 10, 100, 20);
	PaketicHrana* hrana4 = new PaketicHrana("ljubicasta", "Jovana2", 4, 50, 10);
	PaketicHrana* hrana6 = new PaketicHrana("zuta", "Marka10", 12, 100, 5);
	saonica1->ubaci(igracka1);
	saonica1->ubaci(hrana2);
	saonica1->ubaci(igracka1);
	saonica1->ubaci(hrana4);
	saonica1->ubaci(igracka1);
	saonica1->ubaci(hrana6);
	saonica1->prikaz(paketici);
	saonica1->najteziPaketic()->Ispis(cout);
	cout << "\n\n" << saonica1->srednjaCena() << endl;
	const char* adresa1 = "Jovana11";
	const char* adresa2 = "Marka10";
	const char* adresa3 = "Jovana1";
	saonica1->izbaci(adresa1);
	saonica1->izbaci(adresa2);
	saonica1->izbaci(adresa3);


}
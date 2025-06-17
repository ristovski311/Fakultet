#include "Evidencija.h"
#include "Student.h"
#include "StudentPisaniKol.h"
#include "StudentPisaniCelina.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream ispis("studenti.txt");

	Evidencija* evidencija1 = new Evidencija(6);
	StudentPisaniKol* kol1 = new StudentPisaniKol(101, 11, 25, 6, 15);
	StudentPisaniKol* kol3 = new StudentPisaniKol(103, 20, 40, 20, 20);
	StudentPisaniKol* kol5 = new StudentPisaniKol(105, 9, 8, 1, 19);
	StudentPisaniCelina* ceo2 = new StudentPisaniCelina(102, 15, 35, 25);
	StudentPisaniCelina* ceo4 = new StudentPisaniCelina(104, 0, 0, 0);
	StudentPisaniCelina* ceo6 = new StudentPisaniCelina(106, 14, 40, 32);

	evidencija1->dodajStudenta(kol1);
	evidencija1->dodajStudenta(ceo2);
	evidencija1->dodajStudenta(kol3);
	evidencija1->dodajStudenta(ceo4);
	evidencija1->dodajStudenta(kol5);
	evidencija1->dodajStudenta(ceo6);

	evidencija1->ukloniStudenta(104);

	evidencija1->promeniBodoveStudentu(101, 6);
	evidencija1->promeniBodoveStudentu(102, 1);
	evidencija1->promeniBodoveStudentu(104, 10);

	evidencija1->spisak(ispis);

	cout << "Najvise ceo\n\n" << *evidencija1->najviseCeo();
	cout <<"\n\nNajvise pisani\n\n" << *evidencija1->najvisePisani();
	cout << "\n\nBroj koji su polozili: " << evidencija1->polozili();
	cout << "\n\nProsek bodova onih koji su polozili: " << evidencija1->prosecnoBodovaPolozili();


}
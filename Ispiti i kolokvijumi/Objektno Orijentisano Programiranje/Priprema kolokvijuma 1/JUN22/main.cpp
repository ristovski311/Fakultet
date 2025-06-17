#include "Evidencija.h"
#include "Ucesnik.h"
#include "Glumac.h"
#include "Pevac.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream takm("takmicenje.txt");
	Evidencija* evid1 = new Evidencija(10);

	Pevac* pevac1 = new Pevac(1, "Petar", "Markovic", 30, "All i need is little love in my life", 10, 20, 60);
	Pevac* pevac3 = new Pevac(3, "Marko", "Ilic", 80, "Circles", 8, 10, 60);
	Pevac* pevac5 = new Pevac(5, "Nenad", "Savic", 75, "Faded", 4, 6, 60);

	Glumac* glumac2 = new Glumac(2, "Ilija", "Minic", 55, 30, 20, 10);
	Glumac* glumac4 = new Glumac(4, "Ilija", "Minic", 70, 10, 40, 50);
	Glumac* glumac6 = new Glumac(6, "Ilija", "Minic", 40, 20, 27, 30);

	evid1->dodaj(pevac1);
	evid1->dodaj(glumac2);
	evid1->dodaj(pevac3);
	evid1->dodaj(glumac4);
	evid1->dodaj(pevac5);
	evid1->dodaj(glumac6);

	evid1->brisi(2);

	cout << evid1->srednjaVrednostPlasiranih();

	cout << "\n\n";

	evid1->najveciBrojPoena()->ispis(cout);

	evid1->evidentiraj(takm);

	

}
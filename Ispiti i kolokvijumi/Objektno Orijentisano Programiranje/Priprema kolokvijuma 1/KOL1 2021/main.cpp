#include "Predmet.h"
#include "DragoKamenje.h"
#include "Jabuke.h"
#include "ZlatnePoluge.h"
#include "Ranac.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream predmeti("predmeti.txt");
	Ranac* ranac1 = new Ranac(5);
	DragoKamenje* ametist = new DragoKamenje();
	ZlatnePoluge* zlatna1 = new ZlatnePoluge();
	Jabuke* jabuka1 = new Jabuke();
	DragoKamenje* lapis = new DragoKamenje();
	DragoKamenje* smaragd = new DragoKamenje();

	cin >> *ametist;
	cin >> *zlatna1;
	cin >> *jabuka1;
	cin >> *lapis;
	cin >> *smaragd;

	ranac1->dodaj(ametist);
	ranac1->dodaj(zlatna1);
	ranac1->dodaj(jabuka1);
	ranac1->dodaj(lapis);
	ranac1->dodaj(smaragd);

	ranac1->prikaz(predmeti);

	cout << "\n" << *ranac1->najvredniji();
	cout << "\n" << ranac1->srednjaVrednost();



}
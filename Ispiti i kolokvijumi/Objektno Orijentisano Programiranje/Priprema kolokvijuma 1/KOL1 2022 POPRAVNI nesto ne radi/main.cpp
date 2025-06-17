#include "Proizvod.h"
#include "Traka.h"
#include "Otpornik.h"
#include "Kondenzator.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	Traka* traka1 = new Traka(6);
	Otpornik* otp1 = new Otpornik("1010", 0, 10, 20);
	Otpornik* otp3 = new Otpornik("3030", 10, 100, 150);
	Otpornik* otp5 = new Otpornik("5050", 20, 15, 90);
	Kondenzator* kond2 = new Kondenzator("2020", 10);
	Kondenzator* kond4 = new Kondenzator("4040", 0);
	Kondenzator* kond6 = new Kondenzator("6060", 30);
	traka1->stavi(otp1);
	traka1->stavi(kond2);
	traka1->stavi(otp3);
	traka1->stavi(kond4);
	traka1->stavi(otp5);
	traka1->stavi(kond6);

	Kondenzator* kond9 = new Kondenzator("9191", 99);
	Otpornik* otp9 = new Otpornik("9090", 12, 80, 90);

	traka1->zameniDefektni(kond9);
	traka1->zameniDefektni(otp9);

	Kondenzator* kond8 = new Kondenzator("8080", 70);
	Kondenzator* kond10 = new Kondenzator("A0A0", 44);

	traka1->povecajKapacitet(5);
	traka1->stavi(kond8);
	traka1->stavi(kond10);
	traka1->stavi(new Otpornik("9876", 9, 10, 100));

	for (int i = 0; i < 9; i++)
		traka1->ukloni();


}
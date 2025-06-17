#include "Put.h"
#include "PutAutobusom.h"
#include "PutAvionom.h"
#include "Putovanje.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	Putovanje* putovanje1 = new Putovanje(100, "1-1-2024");
	Putovanje* putovanje2 = new Putovanje(10, nullptr);
	PutAutobusom* autobus1 = new PutAutobusom("Nis", 10, 3, 30, 120, 2, 9, 0);
	PutAvionom* avion1 = new PutAvionom("Amsterdam", 50, 10, 20, "MojAmst", 1000, 100);
	putovanje1->dodajPut(autobus1);
	putovanje1->dodajPut(avion1);
	putovanje1->IspisPutovanja(cout);
	putovanje1->obrisiPut("Nis");
	PutAutobusom* autobus2 = new PutAutobusom("Krusevac", 20, 4, 40, 90, 3, 7, 2);
	putovanje1->dodajPut(autobus2);
	cout << "\n\n\n";
	putovanje1->IspisPutovanja(cout);
	ifstream upis("upisPuta.txt");
	PutAutobusom* bus1 = new PutAutobusom(nullptr, 0, 0, 0, 0, 0, 0, 0);
	PutAvionom* fly1 = new PutAvionom(nullptr, 0, 0, 0, nullptr, 0, 0);
	putovanje2->dodajPut(bus1);
	putovanje2->dodajPut(fly1);
	putovanje2->UpisPutovanja(upis);
	cout << "\n\n\n\n\n\n";
	putovanje2->IspisPutovanja(cout);
}
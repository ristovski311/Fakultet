#include <iostream>
#include <fstream>
#include "Evidencija.h"
#include "IzlozbeniPosetioci.h"
using namespace std;

int main()
{
	try
	{
		Evidencija<int> inter(5);
		for (int i = 0; i < 4; i++)
		{
			int temp;
			cin >> temp;
			inter.Dodaj(temp);
		}
		inter.Sacuvaj(cout);
		inter.Obrisi(2);
		int a = 555;
		inter.Dodaj(a);
		int* rez;
		rez = inter.najmanjaZarada();
		cout << rez[0] << " , " << rez[1] << endl;
		cout << inter.UkupnoPosetilaca(1,2) << endl;
		ofstream interak("interaktivni.txt");
		inter.Sacuvaj(interak);
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	try
	{
		Evidencija<IzlozbeniPosetioci> izl(5);
		ifstream izloz("unosizl.txt");
		izl.CitajIzFajla(izloz);
		izl.Sacuvaj(cout);
		izl.Obrisi(2);
		IzlozbeniPosetioci izl1(90, 10, 5);
		izl.Dodaj(izl1);
		cout << *izl.najmanjaZarada() << endl;
		cout << izl.UkupnoPosetilaca(1, 3) << endl;
		ofstream izlozbeni("izlozbeni.txt");
		izl.Sacuvaj(izlozbeni);
	}
	catch (const char* msg)
	{
		cout << msg;
	}

	return 0;
}
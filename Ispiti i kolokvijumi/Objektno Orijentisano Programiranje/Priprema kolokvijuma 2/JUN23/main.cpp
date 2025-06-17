#include <iostream>
#include <fstream>
#include "Detaljna.h"
#include "Kolekcija.h"


using namespace std;

int main()
{
	/*try
	{
		Kolekcija<int> intkol(24);
		for (int i = 1; i <= 15; i++)
		{
			int n;
			cin >> n;
			intkol.Dodaj(n, i);
			cout << intkol << endl << endl;
			cout << intkol.Razlika(i-2) << endl;
			cout << intkol.Prosek() << endl;

		}
		cout << intkol.NajmanjaPotrosnja() << endl << intkol.NajvecaPotrosnja() << endl;
		intkol.Ispisi("int.txt");
		Kolekcija<int> intkol2(24);
		intkol2.Citaj("int.txt");
		cout << "............\n" << intkol2;

	}
	catch (const char* msg)
		{
		cout << msg;
	}*/

	try
	{
		Kolekcija<Detaljna> detkol(24);
		for (int i = 1; i <= 15; i++)
		{
			Detaljna n;
			cin >> n;
			detkol.Dodaj(n, i);
			cout << detkol << endl << endl;
			cout << detkol.Razlika(i - 2);
			cout << detkol.Prosek() << endl;

		}
		cout << detkol.NajmanjaPotrosnja() << endl << detkol.NajvecaPotrosnja() << endl;
		detkol.Ispisi("int.txt");
		Kolekcija<int> detkol2(24);
		detkol2.Citaj("int.txt");
		cout << "............\n" << detkol2;

	}
	catch (const char* msg)
	{
		cout << msg;
	}


	return 0;
}
#include <iostream>
#include <fstream>
#include "Skola.h"
#include "Sport.h"
using namespace std;

int main()
{
	//umetnost:
	try 
	{
		Skola<int> skolaUmetnosti(5);
		for (int i = 0; i < 4; i++)
		{
			int temp;
			cin >> temp;
			skolaUmetnosti.Dodaj(temp);
		}

		int a = 8;

		skolaUmetnosti.Dodaj(a);
		skolaUmetnosti.Ispisi(cout);

		skolaUmetnosti.Ukloni(2);
		skolaUmetnosti.Ispisi(cout);

		cout << "\n\n" << skolaUmetnosti.NajmanjeVredna() << endl;
		cout << "\n\n" << skolaUmetnosti.Najvrednija() << endl;

		cout << "\n\n" << skolaUmetnosti.Prosek() << "\n\n\n";

		skolaUmetnosti.IspisiUFajl("ispisUm.txt");

	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	//sport:


	try
	{
		Skola<Sport> skolaSporta(4);
		skolaSporta.UpisiIzFajla("sport.txt");
		skolaSporta.Ispisi(cout);
		cout << "\n--\n";
		skolaSporta.Ukloni(1);
		cout << "\n--\n";
		Sport sp1(18, 5, "klompe", 45000, 0.2);
		skolaSporta.Dodaj(sp1);
		skolaSporta.Ispisi(cout);
		cout << "\n--\n";
		cout << skolaSporta.Najvrednija();
		cout << "\n--\n";
		cout << skolaSporta.NajmanjeVredna();
		cout << "\n--\n";
		cout << skolaSporta.Prosek();
		cout << "\n--\n";

		skolaSporta.IspisiUFajl("ispisSport.txt");
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	return 0;
}
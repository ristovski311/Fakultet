#include "Artikal.h"
#include "Laptop.h"
#include "Torba.h"
#include <fstream>
#include <iostream>

using namespace std;

void inic_array(Artikal** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = new Laptop();
		}
		else
		{
			a[i] = new Torba();
		}
	}
}

void sort(Artikal** niz, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (niz[j]->getPrice() < niz[i]->getPrice())
			{
				Artikal* temp;
				temp = niz[j];
				niz[j] = niz[i];
				niz[i] = temp;
			}
		}
	}
}

int main()
{
	Artikal** nizArtikala = new Artikal * [2018];

	inic_array(nizArtikala, 2018);

	ifstream upis("upis.txt");
	ofstream izlaz("izlaz.txt");

	//Inicijalizacija svih clanova niza nizArtikala
	for (int i = 0; i < 10; i++)
	{

		if (i % 2 == 0)
		{
			upis >> *nizArtikala[i];
		}
		else
		{
			upis >> *nizArtikala[i];
			nizArtikala[i]->put(*nizArtikala[i - 1]);
		}
	}

	//Prikaz na standardni izlaz pre sortiranja
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ". \n";
		nizArtikala[i]->showDescription();
	}

	cout << "------------------------------\n";

	//Testiranje svih metoda
	Artikal* art1 = new Artikal("Artikal broj 1", 199);
	Torba* torba1 = new Torba();
	char* temp = new char[1];
	temp[0] = 0;
	Laptop* lap1 = new Laptop("Laptop broj 1", 89, true, temp);

	art1->showDescription();
	cout << art1->getPrice();

	cout << "\n----------------\n";

	lap1->showDescription();
	lap1->turnOff();
	lap1->turnOn();

	cout << "----------------\n";

	torba1->showDescription();
	torba1->put(*lap1);
	torba1->showDescription();
	torba1->remove();
	torba1->showDescription();
	torba1->remove();

	//Sortiranje
	sort(nizArtikala, 10);

	//Prikaz u izlazni fajl posle sortiranja
	for (int i = 0; i < 10; i++)
	{
		izlaz << i + 1 << ".\n";
		izlaz << *nizArtikala[i];
	}

	for (int t = 0; t < 2018; t++)
	{
		if(nizArtikala[t])
		{
			delete nizArtikala[t];
			nizArtikala[t] = 0;
		}
	}
	delete[] nizArtikala;

	return 1;
}
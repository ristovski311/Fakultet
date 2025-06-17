#include <iostream>
#include <fstream>
#include "Livada.h"
#include "SemeRuze.h"
#include "JajascePuza.h"
#include "Ruza.h"
#include "Puz.h"
#include "TrojanskaRuza.h"
#include "TrojanskiPuz.h"
#include <math.h>
using namespace std;

int Livada::brojPronadjenih;
int Livada::brojZametaka;

int main()
{
	//Markeri za modifikacjiu stila igre
	static bool autopilot = false;
	static bool start = false;
	static bool simple = false;
	static bool endGame = false;

	try
	{

		//Pravljenje nove livade
		Livada* poljana = new Livada();

		//Igrac bira koju livadu zeli da ucita
		char* livadaIzbor = new char[8];
		strcpy(livadaIzbor, "livada");
		char izborBroj;
		cout << "=-= >> Dobrodosli u igru Livada << =-=\n\nIzaberite livadu: 1 | 2 | 3 | 4\n\n>>";
		cin >> izborBroj;
		
		switch (izborBroj)
		{
		case '1':
			strcat(livadaIzbor, "1.txt");
			break;
		case '2':
			strcat(livadaIzbor, "2.txt");
			break;
		case '3':
			strcat(livadaIzbor, "3.txt");
			break;
		case '4':
			strcat(livadaIzbor, "4.txt");
			break;
		default:
			break;
		}
		
		//Citanje odredjene livade
		poljana->UcitajIz(livadaIzbor);

		//START meni, pocetna uputstva
		system("cls");
		cout << *poljana;
		cout << "\nUnesi:\n";
		cout << "\nstart - pocetak igre  |  autopilot - automatsko ispaljivanje mlazova  | simple - bez animacija\n";

		//Unos prve reci, start za pocetak i autopilot za automatsko ispaljivanje mlazova, simple je bez animacija
		char* unos = new char[10];

		//Unos pravilne komande za pocetak igre
		do
		{
			cin >> unos;
			if (!strcmp(unos, "autopilot"))
			{
				autopilot = true;
				start = true;
			}
			else if (!strcmp(unos, "simple"))
			{
				simple = true;
				start = true;
			}
			else if (!strcmp(unos, "start"))
				start = true;
			else
				cout << "\nPogresan unos! Probajte ponovo...\n";
		} while (!start);

		system("cls");
		cout << "\nBroj nadjenih zametaka: " << Livada::brojPronadjenih << "/" << Livada::brojZametaka << "\n\n";
		cout << *poljana << "\n";

		
		while (!endGame)
		{
			if (Livada::brojPronadjenih >= Livada::brojZametaka && poljana->qEmpty())
				endGame = true;

			//Ispitivanje da li zelimo preko autopilota da igramo
			if(!autopilot)
			{
				cout << "\nPritisni bilo koje dugme da ispalis mlaz vode...\n";
				char* unos = new char[10];
				cin >> unos;
				if (!strcmp(unos, "autopilot"))
					autopilot = true;
				else if (!strcmp(unos, "end"))
					endGame = true;
			}

			//Da li je u pitanju simple mod ili mod sa tranzicijama za gadjanje
			if(!simple)
			{
				for (int i = 0; i <= 8; i++)
				{
					if (i == 20)
						cout << "\r                   \n";
					else if (i % 4 == 0)
						cout << "\r>> Gadjam... |";
					else if (i % 4 == 1)
						cout << "\r>> Gadjam... \\";
					else if (i % 4 == 2)
						cout << "\r>> Gadjam... -";
					else if (i % 4 == 3)
						cout << "\r>> Gadjam... /";
					_sleep(30);

				}
			}

			//Ciscenje konzole za prikaz sledece iteracije livade
			system("cls");

			//Proveravamo da li ima u redu za cekanje nekog semena koje je pri prosejavanju otislo na otvoreno polje
			if(poljana->qEmpty())
				poljana->mlaz();
			else
			{
				int* coords = new int[2];
				coords = poljana->deq();
				poljana->mlaz(coords[0], coords[1]);
			}

			//Prikaz broja pronadjenih zametaka, moze biti i opciono
			cout << "\nBroj nadjenih zametaka: " << Livada::brojPronadjenih << "/" << Livada::brojZametaka << "\n\n";
			cout << *poljana;

			//Mala pauza za lepsi prikaz tranzicije
			_sleep(30);
			if (autopilot)
			{
				_sleep(270);
			}
		}

		//Da li je u pitanju simple mod ili mod sa tranzicijama za kraj igre
		if(!simple)
		{
			for (int i = 0; i <= 16; i++)
			{
				if (i == 20)
					cout << "\r                   \n";
				else if (i % 4 == 0)
					cout << "\r>> Zavrsavam igru... |";
				else if (i % 4 == 1)
					cout << "\r>> Zavrsavam igru... \\";
				else if (i % 4 == 2)
					cout << "\r>> Zavrsavam igru... -";
				else if (i % 4 == 3)
					cout << "\r>> Zavrsavam igru... /";
				_sleep(30);

			}
		}

		//Prikazivanje skroz otkrivene livade kad otkrijemo sve zametke -- KRAJ IGRE
		system("cls");
		poljana->OtkrijTablu();
		cout << *poljana;
		cout << "\n =-= >> Game Over! << =-=\n";
		cout << "\n =-= >> Broj osvojenih poena: " << poljana->brojPoena() << " << =-=\n";


	}
	catch (const char* msg)
	{
		cout << msg;
	}
}
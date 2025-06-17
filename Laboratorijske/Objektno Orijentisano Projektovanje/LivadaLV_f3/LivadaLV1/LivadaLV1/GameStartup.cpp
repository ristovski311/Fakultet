#include "GameStartup.h"
#include <iostream>
using namespace std;

void GameStartup::startGame()
{
	//Indikatori podesenosti igre postavljeni na false
	this->autopilot = false;
	this->start = false;
	this->simple = false;
	this->endGame = false;

	//Pravljenje nove livade
	Livada* poljana = new Livada();

	//Igrac bira koju livadu zeli da ucita
	this->displayMsg("=-= >> Dobrodosli u igru Livada << =-=\n\nIzaberite livadu: 1 | 2 | 3 | 4\n\n>>", 7);
	
	//Izbor livade
	bool uspesnoUcitanaLivada = false;
	while (!uspesnoUcitanaLivada)
	{
		try
		{
			//Citanje odredjene livade
			poljana->UcitajIz(this->izborLivade());
			uspesnoUcitanaLivada = true;
		}
		catch (const char* msg)
		{
			system("cls");
			this->displayMsg(msg, 4);
			this->displayMsg("\n>> Molimo izaberite jedan od ponudjenih brojeva za izbor livade: 1 | 2 | 3 | 4\n\n>>", 3);
		}
	}

	//START meni, pocetna uputstva
	system("cls");
	cout << *poljana;
	displayMsg("\n>> Unesi:\n\nstart - pocetak igre  |  autopilot - automatsko ispaljivanje mlazova  | simple - bez animacija\n\n>>", 7);


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
			displayMsg("\n>> Pogresan unos! Probajte ponovo...\n", 4);
	} while (!start);

	this->displayTips();

	system("cls");
	cout << "\n>> Broj nadjenih zametaka: " << Livada::brojPronadjenih << "/" << Livada::brojZametaka << "\n\n";
	cout << *poljana << "\n";

	this->gameCycle(poljana);
	
	this->gameEnding(poljana);


}

void GameStartup::displayMsg(const char* msg, int n)
{
	for (int i = 0; i < strlen(msg); i++)
	{
		cout << msg[i];
		_sleep(n);
	}
}

const char* GameStartup::izborLivade()
{
	char izborBroj;
	cin >> izborBroj;

	char* livadaIzbor = new char[8];
	strcpy(livadaIzbor, "livada");

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
	return livadaIzbor;
}

void GameStartup::gameCycle(Livada* poljana)
{
	while (!endGame)
	{

		//Ispitivanje da li zelimo preko autopilota da igramo
		if (!autopilot)
		{
			cout << "\n>> Pritisni bilo koje dugme da ispalis mlaz vode...\n>>";
			char* unos = new char[10];
			cin >> unos;
			if (!strcmp(unos, "autopilot"))
				autopilot = true;
			else if (!strcmp(unos, "end"))
			{
				endGame = true;
				break;
			}
		}

		//Da li je u pitanju simple mod ili mod sa tranzicijama za gadjanje
		if (!simple)
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
		if (poljana->qEmpty())
			poljana->mlaz();
		else
		{
			int* coords = new int[2];
			coords = poljana->deq();
			poljana->mlaz(coords[0], coords[1]);
		}

		//Prikaz broja pronadjenih zametaka, moze biti i opciono
		cout << "\n>> Broj nadjenih zametaka: " << Livada::brojPronadjenih << "/" << Livada::brojZametaka << "\n\n";
		cout << *poljana;

		//Mala pauza za lepsi prikaz tranzicije
		_sleep(30);
		if (autopilot)
		{
			_sleep(270);
		}

		if (Livada::brojPronadjenih >= Livada::brojZametaka && poljana->qEmpty())
			endGame = true;
	}
}

void GameStartup::gameEnding(Livada* poljana)
{
	//Da li je u pitanju simple mod ili mod sa tranzicijama za kraj igre
	if (!simple)
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
	displayMsg("\n =-= >> Game Over! << =-=\n\n", 7);
	poljana->OtkrijTablu();
	cout << *poljana;
	_sleep(400);
	displayMsg("\n\n >> Broj osvojenih poena : ", 7);
	cout << poljana->brojPoena() << endl;
}

void GameStartup::displayTips()
{
	system("cls");
	this->displayMsg("\n\n\n\n\n\n\n>> Game is starting... ", 2);
	for (int i = 0; i <= 20; i++)
	{
		if (i == 20)
			cout << "\r";
		else if (i % 4 == 0)
			cout << "\r|";
		else if (i % 4 == 1)
			cout << "\r\\";
		else if (i % 4 == 2)
			cout << "\r-";
		else if (i % 4 == 3)
			cout << "\r/";
		_sleep(30);

	}
	this->displayMsg("\r>> Mozes bilo kad da uneses \"autopilot\" kako bi ga aktivirao, ili \"end\" kako bi zavrsio igru!", 2);
	_sleep(2000);
	this->displayMsg("\r                                                                                                   ", 2);
}
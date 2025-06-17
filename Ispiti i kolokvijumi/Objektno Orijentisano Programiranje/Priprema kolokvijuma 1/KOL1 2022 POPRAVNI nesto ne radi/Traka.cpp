#include "Traka.h"
#include <fstream>

Traka::Traka(int n)
{
	maxDuzina = n;
	trenutnoIma = 0;
	sadrzaj = new Proizvod * [maxDuzina];
	for (int i = 0; i < maxDuzina; i++)
		sadrzaj[i] = nullptr;
}

Traka::~Traka()
{
	for (int i = 0; i < trenutnoIma; i++)
		if (sadrzaj[i] != nullptr)
			delete sadrzaj[i];
	delete[] sadrzaj;
	sadrzaj = nullptr;
}

void Traka::stavi(Proizvod* p)
{
	if (trenutnoIma < maxDuzina)
	{
		sadrzaj[trenutnoIma] = p;
		cout << "Postavljen prozivod na poziciju: " << trenutnoIma << endl;
		trenutnoIma++;
	}
	else
	{
		cout << "Nema dovoljno mesta na traci! Povecajte kapacitet\n";
	}
}

void Traka::ukloni()
{
	bool found = 0;
	ofstream ispis;
	ispis.open("novi.txt", ios::app);
	for (int i = 0; i < trenutnoIma && !found; i++)
		if (sadrzaj[i] != nullptr)
		{
			found = 1;
			sadrzaj[i]->ispis(ispis);
			delete sadrzaj[i];
			sadrzaj[i] = nullptr;
		}
	ispis.close();
	cout << "Uklonjen proizvod sa pozicije: "<< endl;
}

void Traka::povecajKapacitet(int n)

{
	Proizvod** novSadrzaj = new Proizvod * [maxDuzina + n];
	for(int i = 0; i < maxDuzina + n; i++)
		novSadrzaj[i] = nullptr;
	for (int i = 0; i < maxDuzina; i++)
	{
		novSadrzaj[i] = this->sadrzaj[i];
	}
	delete[] this->sadrzaj;
	this->sadrzaj = nullptr;
	this->sadrzaj = novSadrzaj;
	maxDuzina += n;
	cout << "Kapacitet trake povecan za: " << n << endl;
}

int Traka::trenutnoDefektnih()
{
	int def = 0;
	for (int i = 0; i < trenutnoIma; i++)
		if (sadrzaj[i] != nullptr)
			if (sadrzaj[i]->defektan() == true)
				def++;
	return def;
}

int Traka::praznaMesta()
{
	int prazna = 0;
	for (int i = 0; i < trenutnoIma; i++)
		if (sadrzaj[i] == nullptr)
			prazna++;
	return prazna;
}

void Traka::zameniDefektni(Proizvod* p)
{
	bool nadjen = 0;
	for (int i = 0; i < trenutnoIma && !nadjen; i++)
		if (sadrzaj[i] != nullptr)
			if (sadrzaj[i]->defektan())
				if (i <= trenutnoIma / 3)
				{
					if (!strcmp(p->tip(), sadrzaj[i]->tip()))
					{
						sadrzaj[i] = p;
						nadjen = 1;
					}
					else
						cout << "\n\nTipovi proizvoda se ne poklapaju!!\n\n";
				}
				else if (i > trenutnoIma/3)
				{
					/*if (!strcmp(p->tip(), sadrzaj[i]->tip()))
					{
						sadrzaj[i] = nullptr;
						nadjen = 1;
					}
					else
					{
						sadrzaj[i] = nullptr;
						nadjen = 1;
					}*/
					sadrzaj[i] = nullptr;
					cout << "Pronadjen defektan van prve trecine trake i izbrisan!\n";
					nadjen = 1;
				}


}
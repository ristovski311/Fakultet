#include "Radnik.h"
#include "Developer.h"
#include "Menager.h"
#include "Preduzece.h"
#include <iostream>
#include <fstream>
using namespace std;

void inic(Preduzece* p,int a)
{
	for (int i = 0; i < a; i++)
	{
		if (i % 2 == 0)
		{
			p->GetRadnici()[i] = new Developer();
		}
		else
		{
			p->GetRadnici()[i] = new Menager();
		}
	}
}

int main()
{
	ifstream ulaz("radnici_ulaz.txt");
	ofstream izlaz("izlaz.txt");
	Preduzece* preduzece1 = new Preduzece("preduzece1", 2018, 1000000);
	inic(preduzece1, 2018);

	for (int i = 0; i < 10; i++)
	{ 
		ulaz >> *preduzece1->GetRadnici()[i];
		preduzece1->SetBrEl(preduzece1->GetBrEl() + 1);
	}

	preduzece1->OPreduzecu(izlaz);
	izlaz << *preduzece1;

	if (preduzece1->Rentabilna())
		++(*preduzece1);
	else
		--(*preduzece1);
	izlaz << *preduzece1;

	Radnik* novi_radnik = new Developer(10221, 0, 2, 34, "Sava_Ilic", "programer", 3);

	preduzece1->Dodaj(novi_radnik, 2023);

	cout << *preduzece1;

	preduzece1->Brisi(10221);

	cout << "\n\n-----------\n\n";

	cout << *preduzece1;

	cout << "\n\n-----------\n\n";

	preduzece1->GetRadnici()[1]->Prikazi();
	

	return 1;
}
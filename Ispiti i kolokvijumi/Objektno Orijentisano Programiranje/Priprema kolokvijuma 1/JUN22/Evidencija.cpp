#include "Evidencija.h"

Evidencija::Evidencija(int max)
{
	maxUcesnika = max;
	trenutnoUcesnika = 0;
	lista = new Ucesnik * [max];
	for (int i = 0; i < max; i++)
		lista[i] = nullptr;
}

Evidencija::~Evidencija()
{
	for (int i = 0; i < maxUcesnika; i++)
		if (lista[i] != nullptr)
			delete lista[i];
	delete[] lista;
	lista = nullptr;
}

void Evidencija::dodaj(Ucesnik* u)
{
	if (trenutnoUcesnika < maxUcesnika)
		lista[trenutnoUcesnika++] = u;
	else
		cout << "Lista je puna, prosirite je!\n";
}

void Evidencija::brisi(int redbr)
{
	bool found = 0;
	for(int i = 0; i < trenutnoUcesnika && !found; i++)
		if(lista[i] !=nullptr)
			if (lista[i]->getRedBr() == redbr)
			{
				found = 1;
				delete lista[i];
				lista[i] = nullptr;
				cout << "Obrisan je ucesnik pod rednim brojem: " << redbr << endl;
			}
	if (!found)
		cout << "Nije pronadjen ucesnik u listi s tim rednim brojem!\n";
}

double Evidencija::srednjaVrednostPlasiranih()
{
	int plasirano = 0;
	double ukupnoPoena = 0;
	for(int i = 0; i < trenutnoUcesnika; i++)
		if (lista[i] != nullptr)
			if(lista[i]->prosao())
			{
				ukupnoPoena += lista[i]->ukupnoPoena();
				plasirano++;
			}
	return ukupnoPoena / plasirano;
}

Evidencija& Evidencija::sortiraj()
{
	Ucesnik* temp;
	for(int i = 0; i < trenutnoUcesnika - 1; i++)
		if (lista[i] != nullptr)
			for(int j = i; j < trenutnoUcesnika; j++)
				if(lista[j] != nullptr)
					if (lista[j]->pomocnoOsoblje() > lista[i]->pomocnoOsoblje())
					{
						temp = lista[j];
						lista[j] = lista[i];
						lista[i] = temp;
					}
	temp = nullptr;
	return *this;
}

Ucesnik* Evidencija::najveciBrojPoena()
{
	int max = 0;
	for (int i = 0; i < trenutnoUcesnika; i++)
		if (lista[i] != nullptr)
			if (lista[max]->ukupnoPoena() < lista[i]->ukupnoPoena())
				max = i;
	return lista[max];
}

ostream& Evidencija::evidentiraj(ostream& o)
{
	o << "Ucesnika u listi: " << trenutnoUcesnika << "/" << maxUcesnika << "\n\n";
	for (int i = 0; i < trenutnoUcesnika; i++)
		if (lista[i] != nullptr)
		{
			lista[i]->ispis(o);
			o << "\n";
		}
	return o;
}
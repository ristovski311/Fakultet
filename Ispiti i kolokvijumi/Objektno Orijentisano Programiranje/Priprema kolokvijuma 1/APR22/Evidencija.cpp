#include "Evidencija.h"

Evidencija::Evidencija(int max)
{
	this->maxStudenata = max;
	this->trenutnoIma = 0;
	this->lista = new Student * [max];
	for (int i = 0; i < max; i++)
		lista[i] = nullptr;
}

Evidencija::~Evidencija()
{
	for (int i = 0; i < maxStudenata; i++)
		if (lista[i] != nullptr)
			delete lista[i];
	delete[] lista;
	lista = nullptr;
}

void Evidencija::dodajStudenta(Student* s)
{
	if (trenutnoIma < maxStudenata)
		lista[trenutnoIma++] = s;
	else
		cout << "Popunjena je evidencija!\n";
}

void Evidencija::ukloniStudenta(int ind)
{
	bool found = 0;
	for (int i = 0; i < trenutnoIma && !found; i++)
		if (lista[i]->getInd() == ind)
		{
			lista[i] = nullptr;
			found = 1;
			cout << "Izbacen student sa indeksom " << ind << endl;
		}
	if (!found)
		cout << "Nema takvog studenta u listi!";
}

ostream& Evidencija::spisak(ostream& o)
{
	o << "Maksimalno studenata u spisku: " << maxStudenata << endl;
	o << "Trenutno ih ima u spisku: " << trenutnoIma << endl << endl;
	for (int i = 0; i < trenutnoIma; i++)
		if(lista[i] != nullptr)
		{
			lista[i]->ispisi(o);
		}
	return o;
}

Student* Evidencija::najviseCeo()
{
	int max = 0;
	for (int i = 1; i < trenutnoIma; i++)
	{
		if(lista[i] != nullptr)
		{
			if (lista[i]->ukupnoBodova() > lista[max]->ukupnoBodova())
			{
				max = i;
			}
		}
	}
	return lista[max];
}

Student* Evidencija::najvisePisani()
{
	int max = 0;
	for (int i = 1; i < trenutnoIma; i++)
		if(lista[i] != nullptr)
		{
			if (lista[i]->ukupnoPisani() > lista[max]->ukupnoPisani())
				max = i;
		}
	return lista[max];
}

int Evidencija::polozili()
{
	int polozili = 0;
	for (int i = 0; i < trenutnoIma; i++)
	{
		if(lista[i] !=nullptr)
		{
			if (lista[i]->polozio())
				polozili++;
		}
	}
	return polozili;
}

double Evidencija::prosecnoBodovaPolozili()
{
	double prosek = 0;
	for (int i = 0; i < trenutnoIma; i++)
		if(lista[i] != nullptr)
		{
			if (lista[i]->polozio())
				prosek += lista[i]->ukupnoBodova();
		}
	return prosek / this->polozili();
}

void Evidencija::promeniBodoveStudentu(int ind, double dodatak)
{
	bool found = 0;
	for (int i = 0; i < trenutnoIma && !found; i++)
		if(lista[i] != nullptr)
		{
			if (lista[i]->getInd() == ind)
			{
				lista[i]->promeniBodove(dodatak);
				found = 1;
				cout << "Studentu sa indeksom" << ind << " je dodato " << dodatak << " bodova!\n";
			}
		}
	if (!found)
		cout << "Nema studenta sa takvim indeksom u listi!\n";
}
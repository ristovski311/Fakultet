#include "Livada.h"
#include <math.h>

Livada::Livada(int d)
{
	this->dim = d;
	this->livada = new Zametak**[d];
	for (int i = 0; i < this->dim; i++)
		this->livada[i] = new Zametak*[d];
	for (int i = 0; i < this->dim; i++)
		for (int j = 0; j < this->dim; j++)
			this->livada[i][j] = nullptr;
	this->otvorenaPolja = new bool* [this->dim];
	for (int i = 0; i < this->dim; i++)
		this->otvorenaPolja[i] = new bool[this->dim];
	for (int i = 0; i < this->dim; i++)
		for (int j = 0; j < this->dim; j++)
			this->otvorenaPolja[i][j] = false;
}
Livada::Livada()
{
	this->dim = 0;
	this->livada = nullptr;
	this->otvorenaPolja = nullptr;
}
Livada::~Livada()
{
	for (int i = 0; i < this->dim; i++)
	{
		for (int j = 0; j < this->dim; j++)
			delete this->livada[i][j];
		delete[] this->livada[i];
	}
	delete[] this->livada;
}
void Livada::mlaz()
{
	//Random odredjivanje jacine mlaza
	srand(time(0));
	int jacinaMlaza = rand() % 2 + 1;

	//Random generisanje koordinata livade za ispaljivanje mlaza
	int x = rand() % this->dim;
	int y = rand() % this->dim;

	//Pribavljanje tipa zametka na random odabranoj lokaciji
	const char* tmptype = "promasaj";
	if (!this->otvorenaPolja[x][y] && this->livada[x][y] != nullptr)
		tmptype = livada[x][y]->type();

	//Ako je polje bilo zatvoreno, sad ga otvaramo jer je pogodjeno mlazom
	if (!this->otvorenaPolja[x][y])
		this->otvorenaPolja[x][y] = true;

	cout << "Pogodjeno polje: (" << x << " , " << y << ")\n";
	cout << "Jacina mlaza: " << jacinaMlaza << "\n";

	//Istrazivanje tipa zametka/onoga sto je na odabranoj poziciji (x,y), u zavisnosti
	//od toga koji je tip postupa se po zadatku
	if (!strcmp(tmptype, "semeRuze"))
	{
		this->brojPronadjenih++;
		cout << "\n" << *this << endl << setw(this->dim*2) << "|" << endl << setw(this->dim * 2) << "V" << endl << endl;
		int zbir = jacinaMlaza + this->livada[x][y]->getKolicina();
		switch(zbir)
		{
		case 2:
			this->Dodaj(new Ruza(), x, y);
			break;
		case 3:
			//Proveravamo okolna polja, da li postoje i da li su prazna, ako jesu, dodajemo isto ovakvo seme
			if (x + 1 < dim)
				if (this->livada[x + 1][y] == nullptr)
				{
					this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x + 1, y);
					this->brojZametaka++;
				}
			if (y + 1 < dim)
				if (this->livada[x][y + 1] == nullptr)
				{
					this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x, y + 1);
					this->brojZametaka++;

				}
			if (x - 1 >= 0)
				if (this->livada[x - 1][y] == nullptr)
				{
					this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x - 1, y);
					this->brojZametaka++;
				}
			if (y - 1 >= dim)
				if (this->livada[x][y - 1] == nullptr)
				{
					this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x, y - 1);
					this->brojZametaka++;
				}
			//Brisemo seme s datog polja
			this->Ukloni(x, y);
			//Ako je neki od okolnih otkriven, ispaljujemo mlaz na njega prvo
			if (x + 1 < dim)
				if (this->otvorenaPolja[x + 1][y])
				{
					this->mlaz(x + 1, y);
				}
			if (y + 1 < dim)
				if (this->otvorenaPolja[x][y + 1])
				{
					this->mlaz(x, y + 1);
				}
			if (x - 1 >= 0)
				if (this->otvorenaPolja[x - 1][y])
				{
					this->mlaz(x - 1, y);
				}
			if (y - 1 >= 0)
				if (this->otvorenaPolja[x][y - 1])
				{
					this->mlaz(x, y - 1);
				}
			break;
		case 4:
			this->Dodaj(new TrojanskaRuza(), x, y);
			//
			break;
		default:
			break;
		}
		char tempc;
		cout << *this << endl << "Pritisni bilo koje dugme da nastavis...\n";
		cin >> tempc;
		system("cls");
		cout << "Pogodjeno polje: (" << x << " , " << y << ")\n\n";
		cout << "Jacina mlaza: " << jacinaMlaza << "\n";
	}
	else if (!strcmp(tmptype, "jajascePuza"))
	{
		this->brojPronadjenih++;
	}
}

void Livada::mlaz(int x, int y)
{
	//Random odredjivanje jacine mlaza
	srand(time(0));
	int jacinaMlaza = rand() % 2 + 1;

	cout << "Pogodjeno polje usled prosejavanja: (" << x << " , " << y << ")\n";
	cout << "Jacina mlaza: " << jacinaMlaza << "\n";

	//Ispaljivanje mlaza na seme, i odredjivanje akcije u zavisnosti jacine mlaza i kolicine semena
		this->brojPronadjenih++;
		cout << "\n" << *this << endl << setw(this->dim * 2) << "|" << endl << setw(this->dim * 2) << "V" << endl << endl;
		int zbir = jacinaMlaza + this->livada[x][y]->getKolicina();
		switch (zbir)
		{
		case 2:
			this->Dodaj(new Ruza(), x, y);
			break;
		case 3:
			this->Dodaj(new Ruza(), x, y);
			/*Proveravamo okolna polja, da li postoje i da li su prazna, ako jesu, dodajemo isto ovakvo seme
			if (x + 1 < dim)
				if (this->livada[x + 1][y] == nullptr)
				{
					this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x + 1, y);
					this->brojZametaka++;
				}
			if (y + 1 < dim)
				if (this->livada[x][y + 1] == nullptr)
				{
					this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x, y + 1);
					this->brojZametaka++;

				}
			if (x - 1 < dim)
				if (this->livada[x - 1][y] == nullptr)
				{
					this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x - 1, y);
					this->brojZametaka++;
				}
			if (y - 1 < dim)
				if (this->livada[x][y - 1] == nullptr)
				{
					this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x, y - 1);
					this->brojZametaka++;
				}
			//Brisemo seme s datog polja
			this->Ukloni(x, y);
			//Ako je neki od okolnih otkriven, ispaljujemo mlaz na njega prvo
			if (x + 1 < dim)
				if (this->otvorenaPolja[x + 1][y])
				{
					this->mlaz(x + 1, y);
				}
			if (y + 1 < dim)
				if (this->otvorenaPolja[x][y + 1])
				{
					this->mlaz(x, y + 1);
				}
			if (x - 1 >= 0)
				if (this->otvorenaPolja[x - 1][y])
				{
					this->mlaz(x - 1, y);
				}
			if (y - 1 >= 0)
				if (this->otvorenaPolja[x][y - 1])
				{
					this->mlaz(x, y - 1);
				}*/
			break;
		case 4:
			this->Dodaj(new TrojanskaRuza(), x, y);
			break;
		default:
			break;
		}
		cout << "Pogodjeno polje: (" << x << " , " << y << ")\n\n";
		cout << "Jacina mlaza: " << jacinaMlaza << "\n";
}

void Livada::Dodaj(Zametak * z, int x, int y)
{
	if (this->livada[x][y] != nullptr)
	{
		delete this->livada[x][y];
	}
	this->livada[x][y] = z;
}

void Livada::Ukloni(int x, int y)
{
	if (this->livada[x][y] != nullptr)
	{
		delete this->livada[x][y];
		this->livada[x][y] = nullptr;
		this->brojZametaka--;
	}
}

ostream& operator<<(ostream& o, Livada& l)
{
	for (int i = 0; i < l.dim; i++)
	{
		o << setw(3) <<"|";
		for (int j = 0; j < l.dim; j++)
		{
			if (l.otvorenaPolja[i][j])
			{
				if (l.livada[i][j] != nullptr)
					l.livada[i][j]->Ispisi(o);
				else
					o << setw(3) << " ";
			}
			else
				o << setw(3) << "#";
		}
		o << setw(3) << "|" << endl;
	}
	return o;
}

istream& operator>>(istream& i, Livada& l)
{
	if (l.livada != nullptr)
	{
		for (int p = 0; p < l.dim; p++)
		{
			for (int q = 0; q < l.dim; q++)
				delete l.livada[p][q];
			delete[] l.livada[p];
		}
		delete[] l.livada;
	}
	if (l.otvorenaPolja != nullptr)
	{
		for (int p = 0; p < l.dim; p++)
			delete[] l.otvorenaPolja[p];
		delete[] l.otvorenaPolja;
	}

	i >> l.dim;

	l.livada = new Zametak * *[l.dim];
	for (int p = 0; p < l.dim; p++)
		l.livada[p] = new Zametak * [l.dim];
	for (int p = 0; p < l.dim; p++)
		for (int q = 0; q < l.dim; q++)
			l.livada[p][q] = nullptr;

	l.otvorenaPolja = new bool* [l.dim];
	for (int p = 0; p < l.dim; p++)
		l.otvorenaPolja[p] = new bool[l.dim];

	for (int p = 0; p < l.dim; p++)
		for (int q = 0; q < l.dim; q++)
			l.otvorenaPolja[p][q] = false;

	l.brojPronadjenih = 0;
	l.brojZametaka = 0;

	char* temp = new char[3];

	for (int p = 0; p < l.dim; p++)
	{
		for (int q = 0; q < l.dim; q++)
		{
			i >> temp;
			if (!strcmp(temp, "s1"))
			{
				l.livada[p][q] = new SemeRuze(1);
				l.brojZametaka++;
			}
			else if (!strcmp(temp, "s2"))
			{
				l.livada[p][q] = new SemeRuze(2);
				l.brojZametaka++;
			}
			else if (!strcmp(temp, "j"))
			{
				l.livada[p][q] = new JajascePuza();
				l.brojZametaka++;
			}
		}
	}
	return i;
}

void Livada::UcitajIz(const char* file)
{
	ifstream ucitaj(file);
	if (!ucitaj.good())
		throw "Greska pri citanju livade!";
	ucitaj >> *this;
}

void Livada::OtkrijTablu()
{
	for (int i = 0; i < this->dim; i++)
		for (int j = 0; j < this->dim; j++)
			this->otvorenaPolja[i][j] = true;
}
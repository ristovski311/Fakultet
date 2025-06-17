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
	this->rasejavanjeQueue = new int[this->dim * this->dim];
	for (int i = 0; i < this->dim * this->dim; i++)
		this->rasejavanjeQueue[i] = -1;
	this->qsize = 0;
}

Livada::Livada()
{
	this->dim = 0;
	this->livada = nullptr;
	this->otvorenaPolja = nullptr;
	this->rasejavanjeQueue = nullptr;
	this->qsize = 0;
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
	delete[] this->rasejavanjeQueue;
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
	const char* tmptype = "trava";
	if (!this->otvorenaPolja[x][y] && this->livada[x][y] != nullptr)
		tmptype = livada[x][y]->type();

	//Ako je polje bilo zatvoreno, sad ga otvaramo jer je pogodjeno mlazom
	if (!this->otvorenaPolja[x][y])
	{
		this->otvorenaPolja[x][y] = true;
		if (!strcmp(tmptype, "ruza") || !strcmp(tmptype, "puz"))
			this->brojPronadjenih++;
	}

	cout << ">> Pogodjeno polje: (" << x << " , " << y << ") [" << tmptype << "]\n";
	cout << ">> Jacina mlaza: " << jacinaMlaza << "\n";

	//Istrazivanje tipa zametka/onoga sto je na odabranoj poziciji (x,y), u zavisnosti
	//od toga koji je tip postupa se po zadatku
	if (!strcmp(tmptype, "semeRuze"))
	{
		//Prikazujemo strelicu koja reprezentuje kako se tabla menja posle ovog mlaza
		cout << "\n" << *this << endl << setw(this->dim*2) << "|" << endl << setw(this->dim * 2) << "V" << endl << endl;

		int zbir = jacinaMlaza + this->livada[x][y]->getKolicina();

		//U odnosu na zbir kolicine semena i mlaza vode radimo:
		switch(zbir)
		{
		case 2:
			this->PosadiRuzu(x, y);
			this->brojPronadjenih++;
			break;
		case 3:
			this->brojPronadjenih++;
			this->RasejSeme(x, y);
			break;
		case 4:
			this->PosadiTrojanskuRuzu(x, y);
			this->brojPronadjenih++;
			break;
		}
		char tempc;
		cout << *this << endl << ">> Pritisni bilo koje dugme da nastavis...\n>>";
		cin >> tempc;
		system("cls");
		cout << ">> Pogodjeno polje: (" << x << " , " << y << ") [" << tmptype << "]\n";
		cout << ">> Jacina mlaza: " << jacinaMlaza << "\n";
	}
	else if (!strcmp(tmptype, "jajascePuza"))
	{
		cout << "\n" << *this << endl << setw(this->dim * 2) << "|" << endl << setw(this->dim * 2) << "V" << endl << endl;
		int zbir = jacinaMlaza + this->livada[x][y]->getKolicina();

		//U odnosu na zbir kolicine semena i mlaza vode radimo:
		switch (zbir)
		{
		case 2:
			this->PostaviPuza(x, y);
			this->brojPronadjenih++;
			break;
		case 3:
			this->PostaviTrojanskogPuza(x, y);
			this->brojPronadjenih++;
			break;
		}
		char tempc;
		cout << *this << endl << ">> Pritisni bilo koje dugme da nastavis...\n>>";
		cin >> tempc;
		system("cls");
		cout << ">> Pogodjeno polje: (" << x << " , " << y << ") [" << tmptype << "]\n";
		cout << ">> Jacina mlaza: " << jacinaMlaza << "\n";
	}


}

void Livada::mlaz(int x, int y)
{
	//Random odredjivanje jacine mlaza
	srand(time(0));
	int jacinaMlaza = rand() % 2 + 1;

	system("cls");

	cout << ">>(R) Pogodjeno polje usled prosejavanja: (" << x << " , " << y << ")\n";
	cout << ">>(R) Jacina mlaza: " << jacinaMlaza << "\n";

	//Ispaljivanje mlaza na seme, i odredjivanje akcije u zavisnosti jacine mlaza i kolicine semena
		cout << "\n" << *this << endl << setw(this->dim * 2) << "|" << endl << setw(this->dim * 2) << "V" << endl << endl;
		int zbir = jacinaMlaza + this->livada[x][y]->getKolicina();
		switch (zbir)
		{
		case 2:
			this->Dodaj(new Ruza(), x, y);
			break;
		case 3:
			this->RasejSeme(x, y); 
			break;
		case 4:
			this->Dodaj(new TrojanskaRuza(), x, y);
			break;
		default:
			break;
		}
		char tempc;
		cout << *this << endl << ">> Pritisni bilo koje dugme da nastavis...\n>>";
		cin >> tempc;
		system("cls");
		cout << ">>(R) Pogodjeno polje: (" << x << " , " << y << ")\n";
		cout << ">>(R) Jacina mlaza: " << jacinaMlaza << "\n";
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
		/*if (this->otvorenaPolja[x][y])
			this->brojPronadjenih--;*/
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

	l.rasejavanjeQueue = new int[l.dim * l.dim];
	for (int p = 0; p < l.dim * l.dim; p++)
		l.rasejavanjeQueue[p] = -1;
	l.qsize = 0;

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

void Livada::PosadiRuzu(int x, int y)
{
	this->Dodaj(new Ruza(), x, y);
}

void Livada::RasejSeme(int x, int y)
{
	//Proveravamo okolna polja, da li postoje i da li su prazna, ako jesu, dodajemo isto ovakvo seme
	if (x + 1 < dim)
		if (this->livada[x + 1][y] == nullptr)
		{
			this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x + 1, y);
			if (this->otvorenaPolja[x + 1][y])
			{
				this->enq(x + 1, y);
				this->brojPronadjenih++;
			}
			this->brojZametaka++;
		}
	if (y + 1 < dim)
		if (this->livada[x][y + 1] == nullptr)
		{
			this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x, y + 1);
			if (this->otvorenaPolja[x][y + 1])
			{
				this->enq(x, y + 1);
				this->brojPronadjenih++;
			}
			this->brojZametaka++;

		}
	if (x - 1 >= 0)
		if (this->livada[x - 1][y] == nullptr)
		{
			this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x - 1, y);
			if (this->otvorenaPolja[x - 1][y])
			{
				this->enq(x - 1, y);
				this->brojPronadjenih++;
			}
			this->brojZametaka++;
		}
	if (y - 1 < dim)
		if (this->livada[x][y - 1] == nullptr)
		{
			this->Dodaj(new SemeRuze(this->livada[x][y]->getKolicina()), x, y - 1);
			if (this->otvorenaPolja[x][y - 1])
			{
				this->enq(x, y - 1);
				this->brojPronadjenih++;
			}
			this->brojZametaka++;
		}
	//Brisemo seme s datog polja
	this->Ukloni(x, y);
	this->brojPronadjenih--;
}

void Livada::PosadiTrojanskuRuzu(int x, int y)
{
	this->Dodaj(new TrojanskaRuza(), x, y);
	//Odredjivanje 3 random pozicije gde ce trojanska ruza da postavi ruze
	int xtemp, ytemp;

	for (int j = 0; j < 3; j++)
	{
		do
		{
			xtemp = rand() % this->dim;
		} while (xtemp == x);

		do
		{
			ytemp = rand() % this->dim;
		} while (ytemp == y);

		if (this->livada[xtemp][ytemp] == nullptr)
		{
			if (this->otvorenaPolja[xtemp][ytemp])
				this->brojPronadjenih++;
			this->brojZametaka++;
		}

		this->Dodaj(new Ruza(), xtemp, ytemp);

		/*if (!this->otvorenaPolja[xtemp][ytemp])
		{
			this->otvorenaPolja[xtemp][ytemp] = true;
		}*/
	}
}

void Livada::PostaviPuza(int x, int y)
{
	this->Dodaj(new Puz(), x, y);

	//Brisanje ruza:
	if (x + 1 < dim && this->livada[x + 1][y] != nullptr)
		if (!strcmp(this->livada[x + 1][y]->type(), "ruza"))
		{
			this->Ukloni(x + 1, y);
			if(this->otvorenaPolja[x+1][y])
				this->brojPronadjenih--;
		}
	if (y + 1 < dim && this->livada[x][y + 1] != nullptr)
		if (!strcmp(this->livada[x][y + 1]->type(), "ruza"))
		{
			this->Ukloni(x, y + 1);
			if (this->otvorenaPolja[x ][y+1])
				this->brojPronadjenih--;
		}
	if (x - 1 >= 0 && this->livada[x - 1][y] != nullptr)
		if (!strcmp(this->livada[x - 1][y]->type(), "ruza"))
		{
			this->Ukloni(x - 1, y);
			if (this->otvorenaPolja[x - 1][y])
				this->brojPronadjenih--;
		}
	if (y - 1 >= dim && this->livada[x][y - 1] != nullptr)
		if (!strcmp(this->livada[x][y - 1]->type(), "ruza"))
		{
			this->Ukloni(x, y - 1);
			if (this->otvorenaPolja[x][y-1])
				this->brojPronadjenih--;
		}
}

void Livada::PostaviTrojanskogPuza(int x, int y)
{
	this->Dodaj(new TrojanskiPuz(), x, y);

	//Odredjivanje 3 random pozicije gde ce trojanski puz da postavi puzeve
	int xtemp, ytemp;

	for (int j = 0; j < 3; j++)
	{
		do
		{
			xtemp = rand() % this->dim;
		} while (xtemp == x);

		do
		{
			ytemp = rand() % this->dim;
		} while (ytemp == y);

		if (this->livada[xtemp][ytemp] == nullptr)
		{
			if(this->otvorenaPolja[xtemp][ytemp])
				this->brojPronadjenih++;
			this->brojZametaka++;
		}

		this->PostaviPuza(xtemp, ytemp);

		/*if (!this->otvorenaPolja[xtemp][ytemp])
		{
			this->otvorenaPolja[xtemp][ytemp] = true;
		}*/
	}
}

int Livada::brojPoena()
{
	int poeni = 0;
	for (int i = 0; i < this->dim; i++)
	{
		for (int j = 0; j < this->dim; j++)
		{
			if(this->livada[i][j] != nullptr)
			{
				if (!strcmp(this->livada[i][j]->type(), "ruza") || !strcmp(this->livada[i][j]->type(), "trojanskaRuza"))
					poeni++;
			}
		}
	}
	return poeni;
}

void Livada::enq(int x, int y)
{
	int n = 0;
	while (this->rasejavanjeQueue[n] != -1)
		n++;
	this->rasejavanjeQueue[n++] = x;
	this->rasejavanjeQueue[n] = y;

	this->qsize+=2;

}

int* Livada::deq()
{
	int* ret = new int[2];
	ret[0] = this->rasejavanjeQueue[0];
	ret[1] = this->rasejavanjeQueue[1];
	for (int i = 0; i < qsize; i++)
	{
		this->rasejavanjeQueue[i] = this->rasejavanjeQueue[i + 2];
	}
	this->qsize -= 2;
	return ret;
}

bool Livada::qEmpty()
{
	return this->qsize == 0;
}
#include "Fakultet.h"

Fakultet* Fakultet::instanca;

Fakultet::Fakultet()
{

}
Fakultet::~Fakultet()
{
	for (int i = 0; i < this->brUcionica; i++)
		if (this->ucionice[i] != nullptr)
			delete this->ucionice[i];
	delete[] this->ucionice;
}
void Fakultet::izvestaj()
{
	cout << "Fakultet: " << this->naziv << ", osnovan: " << this->godinaOsn << endl;
	cout << "Fakultet sadrzi: " << this->brUcionica << " racunarskih ucionica. Sledi izvestaj:\n\n";
	for (int i = 0; i < this->brUcionica; i++)
	{
		this->ucionice[i]->ispisi();
		cout << "\n";
	}
}
void Fakultet::izvestajNeispravni()
{
	cout << "Izvestaj za neispravne racunare za: " << this->naziv << endl;
	for (int i = 0; i < this->brUcionica; i++)
	{
		cout << "\tUcionica: " << this->ucionice[i]->getOznaka() << " sadrzi: " << this->ucionice[i]->vratiNeispravne() << " neispravnih racunara.\n";
	}
}
Fakultet* Fakultet::getInstanca()
{
	if (Fakultet::instanca == nullptr)
		Fakultet::instanca = new Fakultet();
	return Fakultet::instanca;
}
void Fakultet::postaviParametre(const char* naziv, int godOsn, int max)
{
	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);
	this->godinaOsn = godOsn;
	this->maxUcionica = max;
	this->ucionice = new RacunarskaUcionica*[max];
	for (int i = 0; i < this->maxUcionica; i++)
		this->ucionice[i] = nullptr;
	this->brUcionica = 0;
}

void Fakultet::registrujUcionicu(RacunarskaUcionica* u)
{
	if (this->brUcionica < this->maxUcionica)
	{
		this->ucionice[brUcionica++] = u;
	}
	else
	{
		cout << "Pun fakultet";
	}
}

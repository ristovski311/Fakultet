#include "RacunarskaUcionica.h"

RacunarskaUcionica::RacunarskaUcionica(const char* oznaka, int max, Switch* s, Projektor* proj)
{
	this->oznaka = new char[strlen(oznaka) + 1];
	strcpy(this->oznaka, oznaka);

	this->projektor = proj;

	this->maxRacunara = max;
	this->racunari = new Racunar * [max];

	for (int i = 0; i < this->maxRacunara; i++)
		this->racunari[i] = nullptr;

	this->brRacunara = 0;

	this->sw = s;
}
RacunarskaUcionica::~RacunarskaUcionica()
{
	delete[] this->racunari;
	delete this->oznaka;
}
bool RacunarskaUcionica::dodajRacunar(Racunar* r, int port)
{
	if (this->brRacunara < this->maxRacunara)
	{
		this->racunari[brRacunara++] = r;
		return true;
		this->sw->poveziRacunar(r, port);
	}
	else 
		return false;
}
bool RacunarskaUcionica::ukloniRacunar(const char* mac)
{
	for (int i = 0; i < this->brRacunara; i++)
	{
		if (!strcmp(this->racunari[i]->getMAC(), mac))
		{
			this->sw->otkaciRacunar(mac);
			for (int j = i; j < this->brRacunara; j++)
				this->racunari[j] = this->racunari[j + 1];
			this->brRacunara--;
			return true;
		}
	}
	return false;
}
int RacunarskaUcionica::vratiNeispravne()
{
	int s = 0;
	for (int i = 0; i < this->brRacunara; i++)
		if (!this->racunari[i]->getIspravan())
			s++;
	return s;
}

void RacunarskaUcionica::ispisi()
{
	cout << "\tRacunarska ucionica: " << this->oznaka << " sadrzi racunare:" << endl;
	cout << "\tNeispravnih: " << this->vratiNeispravne() << "  |  Ukupno: " << this->brRacunara << endl;
	this->projektor->ispisi();
	for (int i = 0; i < this->brRacunara; i++)
	{
		this->racunari[i]->ispisi();
		cout << "\n";
	}
}

const char* RacunarskaUcionica::getOznaka()
{
	return this->oznaka;
}
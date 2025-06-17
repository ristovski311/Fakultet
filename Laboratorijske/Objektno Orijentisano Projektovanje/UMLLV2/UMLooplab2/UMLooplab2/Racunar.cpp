#include "Racunar.h"

Racunar::Racunar(const char* mac, bool ispravan, int brProc, int brHDD, Procesor* p, 
	HDD* h, RAM* r, Tastatura* t, Monitor* m)
{
	this->MAC = new char[strlen(mac) + 1];
	strcpy(this->MAC, mac);
	this->ispravan = ispravan;
	
	this->maxHDD = brHDD;
	this->maxProcesora = brProc;

	this->hdd = new HDD*[this->maxHDD];
	this->procesori = new Procesor * [this->maxProcesora];

	this->hdd[0] = h;
	this->procesori[0] = p;

	this->brHDD = 1;
	this->brProcesora = 1;

	this->tastatura = t;
	this->monitor = m;
	this->ram = r;
}
Racunar::~Racunar()
{
	this->tastatura = nullptr;
	this->monitor = nullptr;
	this->ram = nullptr;
	delete[] this->hdd;
	delete[] this->procesori;
	delete this->MAC;
}
bool Racunar::setNeispravan()
{
	if (this->ispravan)
	{
		this->ispravan = false;
		return true;
	}
	else
		return false;
}
bool Racunar::setIspravan()
{
	if (!this->ispravan)
	{
		this->ispravan = true;
		return true;
	}
	else
		return false;
}
bool Racunar::getIspravan()
{
	return this->ispravan;
}
const char* Racunar::getMAC()
{
	return this->MAC;
}

void Racunar::ispisi()
{
	cout << "\t\tRacunar: " << this->MAC << " je izgradjen iz : " << endl;
	this->tastatura->ispisi();
	this->monitor->ispisi();
	this->ram->ispisi();
	for (int i = 0; i < this->brHDD; i++)
		this->hdd[i]->ispisi();
	for (int i = 0; i < this->brProcesora; i++)
		this->procesori[i]->ispisi();
	cout << "\t\tOvaj racunar je: ";
	if (this->ispravan)
		cout << "ispravan.\n";
	else
		cout << "neispravan.\n";
}

bool Racunar::ugradiProcesor(Procesor* p)
{
	if (this->brProcesora < this->maxProcesora)
	{
		this->procesori[brProcesora++] = p;
		return true;
	}
	else return false;
}

bool Racunar::ugradiHDD(HDD* hdd)
{
	if (this->brHDD < this->maxHDD)
	{
		this->hdd[brHDD++] = hdd;
		return true;
	}
	else return false;
}
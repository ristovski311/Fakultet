#include "Switch.h"

Switch::Switch(int brPortova)
{
	if (brPortova != 24)
		brPortova = 24;
	this->brPortova = brPortova;
	this->portovi = new Port * [brPortova];
	for (int i = 0; i < this->brPortova; i++)
	{
		this->portovi[i] = new Port();
	}
	this->macAdrese = new char* [brPortova];
	for (int i = 0; i < this->brPortova; i++)
		this->macAdrese[i] = nullptr;
	this->brAktivnihPortova = 0;
}
Switch::~Switch()
{
	for (int i = 0; i < this->brPortova; i++)
	{
		if (this->macAdrese[i] != nullptr)
			delete this->macAdrese;
	}
	delete[] this->macAdrese;

	for (int i = 0; i < this->brPortova; i++)
	{
		delete this->portovi[i];
	}
	delete[] this->portovi;
}
bool Switch::poveziRacunar(Racunar* r, int i)
{
	if (i < 0 || i > this->brPortova)
		throw "Pogresan zeljeni port!";
	if (this->macAdrese[i] != nullptr)
	{
		this->macAdrese[i] = new char[strlen(r->getMAC()) + 1];
		strcpy(this->macAdrese[i], r->getMAC());
		this->portovi[i]->aktiviraj();
		this->brAktivnihPortova++;
		return true;
	}
	return false;

}
bool Switch::otkaciRacunar(const char* mac)
{
	for (int i = 0; i < this->brPortova; i++)
	{
		if (this->portovi[i]->getAktivan())
		{
			if (!strcmp(mac, this->macAdrese[i]))
			{
				delete this->macAdrese[i];
				this->macAdrese[i] = nullptr;
				this->portovi[i]->deaktiviraj();
				this->brAktivnihPortova--;
				return true;
			}
		}
	}
	return false;
}
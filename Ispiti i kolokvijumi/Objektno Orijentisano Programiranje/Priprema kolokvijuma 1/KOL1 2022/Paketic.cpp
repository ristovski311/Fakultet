#include "Paketic.h"

Paketic::Paketic(const char* boja, const char* adresa)
{
	this->boja = new char[strlen(boja) + 1];
	this->adresa = new char[strlen(adresa) + 1];
	strcpy(this->boja, boja);
	strcpy(this->adresa, adresa);
}

Paketic::~Paketic()
{
	if (this->boja != nullptr)
		delete[] this->boja;
	this->boja = nullptr;
	if (this->adresa != nullptr)
		delete[] this->adresa;
	this->adresa = nullptr;
}

Paketic::Paketic()
{
	this->boja = new char[1];
	this->boja[0] = 0;
	this->adresa = new char[1];
	this->adresa[0] = 0;
}

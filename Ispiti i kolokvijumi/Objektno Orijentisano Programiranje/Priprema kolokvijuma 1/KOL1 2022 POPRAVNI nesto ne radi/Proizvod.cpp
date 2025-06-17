#include "Proizvod.h"

Proizvod::Proizvod(const char* kod)
{
	this->barkod = new char[strlen(kod) + 1];
	strcpy(this->barkod, kod);
}

Proizvod::~Proizvod()
{
	if (barkod != nullptr)
		delete[] barkod;
	barkod = nullptr;
}



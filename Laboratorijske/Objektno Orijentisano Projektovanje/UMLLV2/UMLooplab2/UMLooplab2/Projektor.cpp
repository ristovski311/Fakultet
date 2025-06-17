#include "Projektor.h"

Projektor::Projektor(const char* t, const char* pr)
{
	this->tip = new char [strlen(t) + 1];
	strcpy(tip, t);
	if (!strcmp(pr, "vga") && !strcmp(pr, "hdmi") && !strcmp(pr, "dvi"))
	{
		this->prikljucak = new char[strlen("vga") + 1];
		strcpy(prikljucak, "vga");
	}
	else
	{
		this->prikljucak = new char[strlen(pr) + 1];
		strcpy(prikljucak, pr);
	}

}

Projektor::~Projektor()
{
	if (prikljucak != nullptr)
		delete[] prikljucak;
	if (tip != nullptr)
		delete[] tip;
}

void Projektor::ispisi()
{
	cout << "\n\nOvo je projektor tipa: " << this->tip << " koji ima prikljucak: " << this->prikljucak << "\n\n";
}

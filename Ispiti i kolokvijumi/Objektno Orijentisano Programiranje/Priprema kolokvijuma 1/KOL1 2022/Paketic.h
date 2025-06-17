#pragma once
#include <iostream>
using namespace std;
class Paketic
{
public:
	Paketic();
	Paketic(const char* boja, const char* adresa);
	const char* GetAdresa() { return adresa; } 
	virtual ~Paketic();
	virtual ostream& Ispis(ostream& o) = 0;
	virtual double cena() = 0;
	virtual double tezina() = 0;
protected:
	char* boja;
	char* adresa;
};


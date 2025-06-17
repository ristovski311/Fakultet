#pragma once
#include <iostream>
using namespace std;
class Proizvod
{
public:
	Proizvod(const char* kod);
	virtual ~Proizvod();
	virtual const char* GetBarkod() { return barkod; };
	virtual ostream& ispis(ostream& o) = 0;
	virtual bool defektan() = 0;
	virtual const char* tip() = 0;
protected:
	char* barkod;
};


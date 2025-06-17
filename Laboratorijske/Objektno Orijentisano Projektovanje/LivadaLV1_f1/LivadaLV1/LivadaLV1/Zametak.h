#pragma once
#include <iomanip>
#include <iostream>
using namespace std;
class Zametak
{
public:
	virtual const char* type() = 0;
	virtual ostream& Ispisi(ostream& o)
	{
		o << "Greska";
		return o;
	}
	virtual int getKolicina() = 0;
};


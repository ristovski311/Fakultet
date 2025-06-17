#pragma once
#include "Zametak.h"
class Puz : public Zametak
{
	const char* type();
	ostream& Ispisi(ostream& o);
	int getKolicina()
	{
		return 0;
	}
};


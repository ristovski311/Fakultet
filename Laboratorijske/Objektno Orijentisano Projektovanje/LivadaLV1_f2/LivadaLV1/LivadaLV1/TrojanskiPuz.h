#pragma once
#include "Puz.h"
class TrojanskiPuz : public Puz
{
	const char* type();
	ostream& Ispisi(ostream& o);
	int getKolicina()
	{
		return 0;
	}
};


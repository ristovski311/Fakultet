#pragma once
#include "Livada.h"
#include "Ruza.h"
class TrojanskaRuza : public Ruza
{
	const char* type();
	ostream& Ispisi(ostream& o);
	virtual int getKolicina()
	{
		return 0;
	}
	void Reakcija(Livada& l, int x, int y);
};


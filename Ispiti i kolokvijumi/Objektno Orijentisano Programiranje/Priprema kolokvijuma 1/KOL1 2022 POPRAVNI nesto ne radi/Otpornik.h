#pragma once
#include "Proizvod.h"
class Otpornik : public Proizvod
{
public:
	Otpornik(const char* kod, float otpornost, float mint, float maxt);
	~Otpornik();
	ostream& ispis(ostream& o);
	bool defektan()
	{
		return otpornost == 0;
	}
	const char* tip() { return "otpornik"; }
private:
	float minTemp;
	float maxTemp;
	float otpornost;
};


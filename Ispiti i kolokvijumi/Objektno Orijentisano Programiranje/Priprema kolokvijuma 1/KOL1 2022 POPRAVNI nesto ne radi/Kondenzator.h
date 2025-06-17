#pragma once
#include "Proizvod.h"

class Kondenzator : public Proizvod
{
public:
	Kondenzator(const char* kod, float kapac);
	~Kondenzator();
	ostream& ispis(ostream& o);
	bool defektan()
	{
		return kapacitivnost == 0;
	}
	const char* tip() { return "kondenzator"; }
private:
	float kapacitivnost;
};


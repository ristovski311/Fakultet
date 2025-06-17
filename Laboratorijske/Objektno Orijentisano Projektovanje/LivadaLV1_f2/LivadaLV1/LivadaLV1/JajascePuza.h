#pragma once
#include "Zametak.h"
class JajascePuza : public Zametak
{
private:
	int kolicina;
public:
	JajascePuza() {
		this->kolicina = 1;
	}
	~JajascePuza(){}
	const char* type();
	ostream& Ispisi(ostream& o);
	int getKolicina()
	{
		return kolicina;
	}
};


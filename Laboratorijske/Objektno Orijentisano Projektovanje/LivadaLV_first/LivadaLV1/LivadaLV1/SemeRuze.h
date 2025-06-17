#pragma once
#include "Zametak.h"
#include "Ruza.h"
class SemeRuze : public Zametak
{
private:
	int kolicina;
public:
	SemeRuze(int k)
	{
		this->kolicina = k;
	}
	~SemeRuze(){}
	const char* type();
	friend ostream& operator<<(ostream& o, SemeRuze& sr);
	ostream& Ispisi(ostream& o)
	{
		o << *this;
		return o;
	}

	int getKolicina()
	{
		return kolicina;
	}
};


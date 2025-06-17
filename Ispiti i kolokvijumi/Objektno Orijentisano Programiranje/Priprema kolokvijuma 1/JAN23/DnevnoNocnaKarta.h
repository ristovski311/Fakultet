#pragma once
#include "DnevnaKarta.h"
class DnevnoNocnaKarta : public DnevnaKarta
{
public:
	DnevnoNocnaKarta(int id, int redBrDana, int brDanaVazenja, int brNociVazenja);
	~DnevnoNocnaKarta(){}
	void produzi(int broj);
	double getCena()
	{
		return this->DnevnaKarta::getCena() + this->cenaNocne;
	}
	friend ostream& operator<<(ostream& o, DnevnoNocnaKarta& dnk);
private:
	static double osnovnaCenaNocne;
	int brNociVazenja;
	double cenaNocne;
};


#pragma once
#include "Proizvod.h"
class Traka
{
public:
	Traka(int max);
	~Traka();
	void stavi(Proizvod* p);
	void ukloni();
	void povecajKapacitet(int n);
	void zameniDefektni(Proizvod* p);
	int trenutnoDefektnih();
	int praznaMesta();
private:
	int maxDuzina;
	int trenutnoIma;
	Proizvod** sadrzaj;
};


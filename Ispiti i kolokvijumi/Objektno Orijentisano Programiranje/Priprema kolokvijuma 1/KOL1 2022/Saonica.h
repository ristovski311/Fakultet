#pragma once
#include "Paketic.h"
#include <iostream>
using namespace std;
class Saonica
{
public:
	Saonica(int N);
	~Saonica();
	void ubaci(Paketic* p);
	void izbaci(const char* adresa);
	ostream& prikaz(ostream& o);
	double srednjaCena();
	Paketic* najteziPaketic();
private:
	Paketic** sadrzaj;
	int kapacitet;
	int trenutnoIma;
};


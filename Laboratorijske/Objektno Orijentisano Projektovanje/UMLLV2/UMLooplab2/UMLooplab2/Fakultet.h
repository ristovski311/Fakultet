#pragma once
#include "RacunarskaUcionica.h"
#include <iostream>
using namespace std;
class Fakultet
{
private:
	static Fakultet* instanca;
	char* naziv;
	int godinaOsn;
	int brUcionica;
	int maxUcionica;
	RacunarskaUcionica** ucionice;
	Fakultet();
public:
	~Fakultet();
	void izvestaj();
	void izvestajNeispravni();
	static Fakultet* getInstanca();
	void postaviParametre(const char* naziv, int godOsn, int max);
	void registrujUcionicu(RacunarskaUcionica* u);
};


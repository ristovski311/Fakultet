#pragma once
#include <iostream>
#include "Switch.h"
#include "Racunar.h"
#include "Projektor.h"
class RacunarskaUcionica
{
private:
	char* oznaka;
	int maxRacunara;
	int brRacunara;
	Racunar** racunari;
	Switch* sw;
	Projektor* projektor;
public:
	RacunarskaUcionica(const char* oznaka, int max, Switch* s, Projektor* proj);
	~RacunarskaUcionica();
	bool dodajRacunar(Racunar* r, int p);
	bool ukloniRacunar(const char* mac);
	int vratiNeispravne();
	void ispisi();
	const char* getOznaka();
};


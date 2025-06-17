#pragma once
#include "Port.h"
#include "Racunar.h"
class Switch
{
private:
	int brPortova;
	int brAktivnihPortova;
	char** macAdrese;
	Port** portovi;
public:
	Switch(int brPortova);
	~Switch();
	bool poveziRacunar(Racunar* r, int i);
	bool otkaciRacunar(const char* mac);
};


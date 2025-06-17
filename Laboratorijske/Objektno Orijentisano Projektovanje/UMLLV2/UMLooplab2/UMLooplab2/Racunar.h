#pragma once
#include "Procesor.h"
#include "RAM.h"
#include "HDD.h"
#include "SSD.h"
#include "Tastatura.h"
#include "Monitor.h"
#include <iostream>
using namespace std;
class Racunar
{
private:
	char* MAC;
	bool ispravan;
	int maxProcesora;
	int brProcesora;
	int maxHDD;
	int brHDD;
	Procesor** procesori;
	HDD** hdd;
	RAM* ram;
	Tastatura* tastatura;
	Monitor* monitor;
public:
	Racunar(const char* mac, bool ispravan, int brProc, int brHDD, Procesor* p, HDD* h, RAM* r, Tastatura* t, Monitor* m);
	~Racunar();
	bool setNeispravan();
	bool setIspravan();
	bool getIspravan();
	const char* getMAC();
	void ispisi();
	bool ugradiProcesor(Procesor* p);
	bool ugradiHDD(HDD* hdd);

};


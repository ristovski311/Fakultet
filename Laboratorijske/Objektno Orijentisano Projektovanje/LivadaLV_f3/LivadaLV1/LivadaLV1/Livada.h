#pragma once
#include <iostream>
#include <fstream>
#include "Zametak.h"
#include "SemeRuze.h"
#include "JajascePuza.h"
#include "Ruza.h"
#include "Puz.h"
#include "TrojanskaRuza.h"
#include "TrojanskiPuz.h"
using namespace std;
class Livada
{
private:
	Zametak*** livada;
	int dim;
	bool** otvorenaPolja;
	int* rasejavanjeQueue;
	int qsize;
public:
	static int brojZametaka;
	static int brojPronadjenih;
	Livada(int d);
	Livada();
	~Livada();
	void OtkrijTablu();
	void mlaz();
	void mlaz(int x, int y);
	void Dodaj(Zametak* z, int x, int y);
	void Ukloni(int x, int y);
	void UcitajIz(const char* file);
	friend ostream& operator<<(ostream& o, Livada& l);
	friend istream& operator>>(istream& i, Livada& l);
	int brojPoena();
	void enq(int x, int y);
	int* deq();
	bool qEmpty();
	//F-je za reakcije nakon mlaza vode
	void PosadiRuzu(int x, int y);
	void RasejSeme(int x, int y);
	void PosadiTrojanskuRuzu(int x, int y);
	void PostaviPuza(int x, int y);
	void PostaviTrojanskogPuza(int x, int y);
};


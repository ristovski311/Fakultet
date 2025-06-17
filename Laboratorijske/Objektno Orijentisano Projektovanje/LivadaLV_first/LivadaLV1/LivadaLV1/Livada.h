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
	friend TrojanskaRuza;
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
};


#include "TrojanskaRuza.h"

const char* TrojanskaRuza::type()
{
	return "trojanskaRuza";
}

ostream& TrojanskaRuza::Ispisi(ostream& o)
{
	o << setw(2) << "t" << "r";
	return o;
}

void TrojanskaRuza::Reakcija(Livada& l, int x, int y)
{
	//Odredjivanje 3 random pozicije gde ce trojanska ruza da postavi ruze
	int xtemp, ytemp;

	for(int j = 0; j < 3; j++)
	{
		do
		{
			xtemp = rand() % l.dim;
		} while (xtemp == x);

		do
		{
			ytemp = rand() % l.dim;
		} while (ytemp == y);
		
		l.Dodaj(new Ruza(), xtemp, ytemp);

		if (!l.otvorenaPolja[xtemp][ytemp])
		{
			l.otvorenaPolja[xtemp][ytemp] = true;
			l.brojPronadjenih++;
		}
	}


}
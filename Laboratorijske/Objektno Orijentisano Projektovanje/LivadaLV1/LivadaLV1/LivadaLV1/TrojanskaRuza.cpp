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
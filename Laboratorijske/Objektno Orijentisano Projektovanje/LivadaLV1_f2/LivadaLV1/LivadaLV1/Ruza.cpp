#include "Ruza.h"

const char* Ruza::type()
{
	return "ruza";
}

ostream& Ruza::Ispisi(ostream& o)
{
	o << setw(3) << "r";
	return o;
}

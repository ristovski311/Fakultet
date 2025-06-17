#include "Puz.h"

const char* Puz::type()
{
	return "puz";
}
ostream& Puz::Ispisi(ostream& o)
{
	o << setw(3) << "p";
	return o;
}

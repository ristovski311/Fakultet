#include "TrojanskiPuz.h"

const char* TrojanskiPuz::type()
{
	return "trojanskiPuz";
}

ostream& TrojanskiPuz::Ispisi(ostream& o)
{
	o << setw(2) << "t" << "p";
	return o;
}

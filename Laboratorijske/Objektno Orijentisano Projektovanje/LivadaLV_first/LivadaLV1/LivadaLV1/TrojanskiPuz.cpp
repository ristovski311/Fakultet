#include "TrojanskiPuz.h"

const char* TrojanskiPuz::type()
{
	return "trojanskiPuz";
}

ostream& TrojanskiPuz::Ispisi(ostream& o)
{
	o << setw(2) << "tp";
	return o;
}

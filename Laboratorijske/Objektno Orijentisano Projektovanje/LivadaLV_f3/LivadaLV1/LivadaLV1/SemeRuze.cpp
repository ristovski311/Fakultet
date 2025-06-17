#include "SemeRuze.h"

const char* SemeRuze::type()
{
	return "semeRuze";
}

ostream& operator<<(ostream& o, SemeRuze& sr)
{
	o << setw(2) << "s" << sr.kolicina;
	return o;
}
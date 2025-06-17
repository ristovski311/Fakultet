#include "JajascePuza.h"


const char* JajascePuza::type()
{
	return "jajascePuza";
}
ostream& JajascePuza::Ispisi(ostream& o)
{
	o << setw(3) << "j";
	return o;
}
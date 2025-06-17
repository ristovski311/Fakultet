#include "Takmicar.h"


istream& operator>>(istream& i, Takmicar& t)
{
	i >> t.id;
	i >> t.start;
	i >> t.rez;
	return i;
}
ostream& operator<<(ostream& o, Takmicar& t)
{
	o << t.id << endl;
	o << t.start << endl;
	o << t.rez << endl;
	return o;
}
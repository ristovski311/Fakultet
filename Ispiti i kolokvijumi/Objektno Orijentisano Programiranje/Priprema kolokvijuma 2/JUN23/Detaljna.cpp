#include "Detaljna.h"


Detaljna::Detaljna(double niza, double visa)
{
	nizaTarifa = niza;
	visaTarifa = visa;
}


Detaljna::Detaljna(Detaljna& d)
{
	this->nizaTarifa = d.nizaTarifa;
	this->visaTarifa = d.visaTarifa;
}

Detaljna::~Detaljna()
{

}


istream& operator>>(istream& i, Detaljna& d)
{
	i >> d.nizaTarifa;  
	i >> d.visaTarifa;
	return i;
}


ostream& operator<<(ostream& o, Detaljna& d)
{
	o << d.nizaTarifa << " " << d.visaTarifa << endl;
	return o;
}

double operator+(double d, Detaljna& dt)
{
	return d + dt.nizaTarifa + dt.visaTarifa;
}

double Detaljna::operator-(Detaljna& dt)
{
	return this->visaTarifa + this->nizaTarifa - dt.visaTarifa - dt.nizaTarifa;
}


bool Detaljna::operator>(Detaljna& dt)
{
	return (this->nizaTarifa + this->visaTarifa) > (dt.nizaTarifa + dt.visaTarifa);
}

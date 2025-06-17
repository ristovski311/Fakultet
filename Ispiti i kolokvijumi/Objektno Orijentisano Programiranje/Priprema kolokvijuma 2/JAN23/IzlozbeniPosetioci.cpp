#include "IzlozbeniPosetioci.h"

IzlozbeniPosetioci::IzlozbeniPosetioci(int x, int y, int z)
{
	odrasli = x;
	skola = y;
	deca = z;
}

IzlozbeniPosetioci::IzlozbeniPosetioci(IzlozbeniPosetioci& i)
{
	i.odrasli = this->odrasli;
	i.skola = this->skola;
	i.deca = this->deca;
}

IzlozbeniPosetioci::~IzlozbeniPosetioci(){}

int IzlozbeniPosetioci::ukupno()
{
	return odrasli + deca + skola;
}

float IzlozbeniPosetioci::zarada()
{
	return odrasli + skola / 2;
}

int operator+(int s, IzlozbeniPosetioci i)
{
	return s + i.ukupno();
}

istream& operator>>(istream& i, IzlozbeniPosetioci& ip)
{
	i >> ip.odrasli;
	i >> ip.skola;
	i >> ip.deca;
	return i;
}

ostream& operator<<(ostream& o, IzlozbeniPosetioci& ip)
{
	o << ip.odrasli << endl;
	o << ip.skola << endl;
	o << ip.deca << endl;
	return o;
}

bool IzlozbeniPosetioci::operator>(IzlozbeniPosetioci& ip)
{
	return this->zarada() > ip.zarada();
}
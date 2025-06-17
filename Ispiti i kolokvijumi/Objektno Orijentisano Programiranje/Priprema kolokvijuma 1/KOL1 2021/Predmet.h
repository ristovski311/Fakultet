#pragma once
#include <iostream>
using namespace std;
class Predmet
{
public:
	Predmet()
	{

	}
	Predmet(double masa1)
	{
		masa = masa1;
	}
	virtual ~Predmet(){}
	virtual ostream& ispis(ostream& o)
	{
		o << "Masa: " << masa << endl;
		return o;
	}
	friend ostream& operator<<(ostream& o, Predmet& p)
	{
		p.ispis(o);
		return o;
	}
	virtual double vrednost() = 0;
	virtual double vrednostPoMasi()
	{
		return this->vrednost() / masa;
	}
	virtual istream& upis(istream& i)
	{
		cout << "Upisi masu: " << endl;
		i >> masa;
		return i;
	}
	friend istream& operator>>(istream& i, Predmet& p)
	{
		p.upis(i);
		return i;
	}
protected:
	double masa;
};


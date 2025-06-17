#pragma once
#include <iostream>
using namespace std;
class Figura
{
public:
	Figura(double xx, double yy) : x(xx), y(yy) {}
	virtual ~Figura() {}
	virtual ostream& upis(ostream& o) = 0;
	virtual istream& ispis(istream& i) = 0;
	virtual double povrsina() = 0;
	virtual double obim() = 0;

protected:
	double x;
	double y;
};


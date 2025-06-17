#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Detaljna
{
public:
	Detaljna(double niza = 0, double visa = 0);
	Detaljna(Detaljna& d);
	~Detaljna();
	friend istream& operator>>(istream& i, Detaljna& d);
	friend ostream& operator<<(ostream& o, Detaljna& d);
	friend double operator+(double d, Detaljna& dt);
	double operator-(Detaljna& dt);
	bool operator>(Detaljna& dt);


private:
	double nizaTarifa;
	double visaTarifa;

};


#pragma once
#include <iostream>
using namespace std;
class ProsireniPodatak
{
public:
	ProsireniPodatak()
	{
		T = 0;
		E = 0;
		V = 0;
	}
	ProsireniPodatak(float x, float y, float z)
	{
		T = x;
		E = y;
		V = z;
	}
	~ProsireniPodatak()
	{}
	float SubjOsecaj()
	{
		return	T + 0.33 * E - 0.7 * V - 4.0;
	}
	friend istream& operator>>(istream& i, ProsireniPodatak& pp);
	friend ostream& operator<<(ostream& o, ProsireniPodatak& pp);
	friend float operator+(float f, ProsireniPodatak& p);
	bool operator>(ProsireniPodatak& p);
private:
	float T;
	float E;
	float V;
};


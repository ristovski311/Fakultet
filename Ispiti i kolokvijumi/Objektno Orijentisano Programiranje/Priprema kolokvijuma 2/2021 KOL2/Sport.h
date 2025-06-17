#pragma once
#include <string>
#include <iostream>
using namespace std;
class Sport
{
public:
	Sport(int brigr = 0, int rez = 0, string ob = "", float budz = 0, float koef = 0);
	~Sport();
	bool operator>(Sport& s);
	friend float operator+(float f, Sport& s);
	float vrednost();
	friend istream& operator>>(istream& i, Sport& s);
	friend ostream& operator<<(ostream& o, Sport& s);
private:
	int brojIgraca;
	int brojRezervnih;
	string obuca;
	float budzet;
	float koefPop;
};


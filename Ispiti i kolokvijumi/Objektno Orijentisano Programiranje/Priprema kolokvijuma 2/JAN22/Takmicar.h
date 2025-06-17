#pragma once
#include <iostream>
using namespace std;
class Takmicar
{
public:
	Takmicar(int x = 0, int y = 0, int z = 0)
	{
		id = x;
		start = y;
		rez = y;
	}
	Takmicar(const Takmicar& t)
	{
		this->id = t.id;
		this->start = t.start;
		this->rez = t.rez;
	}
	~Takmicar(){}
	Takmicar& operator=(const Takmicar& t)
	{
		if (this == &t)
			return *this;
		else
		{
			this->id = t.id;
			this->start = t.start;
			this->rez = t.rez;
			return *this;
		}
	}
	bool operator==(Takmicar& t)
	{
		return this->id == t.id;
	}
	bool operator!=(Takmicar& t)
	{
		return this->id != t.id;
	}
	friend istream& operator>>(istream& i, Takmicar& t);
	friend ostream& operator<<(ostream& o, Takmicar& t);
private:
	int id;
	int start;
	int rez;
};


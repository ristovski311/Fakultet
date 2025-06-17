#pragma once
#include <iostream>
using namespace std;
class DnevnaKarta
{
public:
	DnevnaKarta(int id, int redBrDana, int brDanaVazenja);
	virtual ~DnevnaKarta(){}
	virtual void produzi(int broj);
	virtual int getId() {
		return this->id;
	}
	virtual const char* getTip()
	{
		return this->tip;
	}
	virtual int getBrDanaVazenja() {
		return this->brDanaVazenja;
	}
	virtual int getRedBrDana()
	{
		return this->redBrDana;
	}
	virtual double getCena()
	{
		return this->cenaDnevne;
	}
	friend ostream& operator<<(ostream& o, DnevnaKarta& dk);
protected:
	static double osnovnaCenaDnevne;
	static double popust;
	const char* tip;
private:
	int id;
	int redBrDana;
	int brDanaVazenja;
	double cenaDnevne;
};


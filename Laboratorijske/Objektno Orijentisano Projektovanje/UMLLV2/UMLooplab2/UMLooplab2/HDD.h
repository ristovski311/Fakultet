#pragma once
#include <iostream>
using namespace std;
class HDD
{
protected:
	char* marka;
	int memorija;
public:
	HDD(const char* m, int mem)
	{
		this->marka = new char[strlen(m) + 1];
		strcpy(this->marka, m);
		this->memorija = mem;
	}
	~HDD()
	{
		delete this->marka;
	}
	virtual void ispisi()
	{
		cout << "\t\t\tHDD marke:" << this->marka << ", kapaciteta: " << this->memorija << endl;
	}
};


#pragma once
#include <iostream>
using namespace std;
class Procesor
{
private:
	int takt;
	int brojL1;
	int brojL2;
public:
	Procesor(int t, int l1, int l2)
	{
		this->takt = t;
		this->brojL1 = l1;
		this->brojL2 = l2;
	}
	~Procesor(){}
	void ispisi()
	{
		cout << "\t\t\tProcesor takta: " << this->takt << ", broja L1: " << this->brojL1 << ", broja L2: " << this->brojL2 << endl;
	}
};


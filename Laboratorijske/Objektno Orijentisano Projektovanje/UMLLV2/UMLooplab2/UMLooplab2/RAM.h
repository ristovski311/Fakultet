#pragma once
#include <iostream>
using namespace std;
class RAM
{
private:
	int takt;
	int memorija;
	char* tipMemorije;
public:
	RAM(int t, int mem, const char* tip)
	{
		this->tipMemorije = new char[strlen(tip) + 1];
		strcpy(this->tipMemorije, tip);
		this->takt = t; 
		this->memorija = mem;
	}
	~RAM()
	{
		delete this->tipMemorije;
	}
	void ispisi()
	{
		cout << "\t\t\tRAM kapaciteta:" << this->memorija << ", takta: " << this->takt << ", tipa: " << this->tipMemorije << endl;
	}
};


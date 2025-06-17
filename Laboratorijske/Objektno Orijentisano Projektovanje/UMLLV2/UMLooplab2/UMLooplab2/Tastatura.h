#pragma once
#include <iostream>
using namespace std;
class Tastatura
{
private:
	char* marka;
public:
	Tastatura(const char* marka)
	{
		this->marka = new char[strlen(marka) + 1];
		strcpy(this->marka, marka);
	}
	~Tastatura()
	{
		delete this->marka;
	}
	void ispisi()
	{
		cout << "\t\t\tTastatura marke: " << this->marka << endl;
	}
};


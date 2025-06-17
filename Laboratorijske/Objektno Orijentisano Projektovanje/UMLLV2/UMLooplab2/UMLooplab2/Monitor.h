#pragma once
#include <iostream>
using namespace std;
class Monitor
{
private:
	double dijagonala;
	char* rezolucija;
	char* marka;
public:
	Monitor(double d, const char* rez, const char* marka)
	{
		this->dijagonala = d;
		this->rezolucija = new char[strlen(rez) + 1];
		this->marka = new char[strlen(marka) + 1];
		strcpy(this->rezolucija, rez);
		strcpy(this->marka, marka);
	}
	~Monitor()
	{
		delete this->rezolucija;
		delete this->marka;

	}
	void ispisi()
	{
		cout << "\t\t\tMonitor marke: " << this->marka << ", dijagonale ekrana: " << this->dijagonala << ", rezolucije: " << this->rezolucija << endl;
	}
};


#pragma once
#include <string>
using namespace std;
class Radnik
{
public:
	Radnik();
	~Radnik();
	Radnik(int jmbg, int godinaZaposljenja, double osnovicaPlate,
	int godinaStarosti, const char* ime_prezime);
	int GetJmbg() { return this->jmbg; }
	char* GetIme() { return this->ime_prezime; }
	int GetGodinaZaposljenja() { return this->godinaZaposljenja; }
	double GetOsnovicaPlate() { return this->osnovicaPlate; }
	int GetGodinaStarosti() { return this->godinaStarosti; }
	void SetGodinaZaposljenja(int a) { this->godinaZaposljenja = a; }
	void SetOsnovicaPlate(double a) { this->osnovicaPlate = a; }
	virtual double OdrediPlatu() = 0;
	void operator++();
	void operator--();
	bool virtual operator>(Radnik* r);
	bool virtual operator<(Radnik* r);
	bool virtual operator>=(Radnik* r);
	bool virtual operator<=(Radnik* r);
	bool virtual operator==(Radnik& r);
	virtual void Prikazi() = 0;
	virtual istream& Upisi(istream& i);
	friend istream& operator>>(istream& i, Radnik& r);
protected:
	int jmbg;
	int godinaZaposljenja;
	double osnovicaPlate;
	int godinaStarosti;
	char* ime_prezime;
};


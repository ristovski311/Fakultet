#pragma once
#include <iostream>
using namespace std;

class Tacka
{
public:
	double GetX() { return this->x; }
	double GetY() { return this->y; }
	double GetZ() { return this->z; }
	//Default konstruktor
	Tacka()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	//Konstruktor za postavljanje zeljenih vrednosti
	Tacka(double x, double y, double z);
	//Operatorska f-ja za ulaz
	friend istream& operator>>(istream& ulaz, Tacka& t);
	//Operatorska f-ja za izlaz
	friend ostream& operator<<(ostream& izlaz, Tacka& t);
	//Operatorska f-ja za sabiranje
	Tacka& operator+(Tacka& t2);
	//Operatorska f-ja za sabiranje 2
	Tacka operator+(Tacka t2);
	//Operatorska f-ja za oduzimanje
	Tacka operator-(Tacka& t2);
	//Operatorska f-ja +=
	Tacka operator+=(Tacka& t2);
	//Operatorska f-ja *
	Tacka operator*(Tacka& t2);
	//Postavlja x,y,z
	Tacka& Postavi(double x, double y, double z);
	//Operatorska f-ja ++
	Tacka& operator++(int n);
	//Operatorska f-ja ==
	bool operator==(Tacka& t2);

private:
	double x;
	double y;
	double z;
};

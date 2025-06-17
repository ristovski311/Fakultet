#pragma once
#include <iostream>
using namespace std;
class Student
{
public:
	Student(int ind, double bodovilab, double bodoviusm);
	virtual ~Student();
	virtual double ukupnoBodova() = 0;
	virtual bool polozio() = 0;
	virtual void promeniBodove(double dodatni) = 0;
	virtual ostream& ispisi(ostream& o);
	virtual int getInd() { return indeks; };
	virtual double ukupnoPisani() = 0;
	friend ostream& operator<<(ostream& o, Student& s)
	{
		s.ispisi(o);
		return o;
	}
protected:
	int indeks;
	double bodoviLab;
	double bodoviUsmeni;
};


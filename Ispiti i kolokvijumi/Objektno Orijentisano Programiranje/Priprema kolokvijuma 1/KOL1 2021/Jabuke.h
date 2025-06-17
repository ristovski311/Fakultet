#pragma once
#include "Predmet.h"
class Jabuke : public Predmet
{
public:
	Jabuke()
	{
		boja = new char[20];
	}
	Jabuke(double masa, double slatkoca1, double kiselost1, const char* boja1)
		: Predmet(masa)
	{
		if (slatkoca <= 1 && slatkoca >= 0)
		{
			slatkoca = slatkoca1;
		}
		else
			slatkoca = 0;

		if (kiselost <= 1 && kiselost >= 0)
		{
			kiselost = kiselost1;
		}
		else
			kiselost = 0;

		boja = new char[strlen(boja1) + 1];
		strcpy(boja, boja1);
	}
	~Jabuke()
	{
		delete[] boja;
		boja = nullptr;
	}
	double vrednost()
	{
		double vr;
		if (slatkoca < 0.5 || kiselost < 0.5)
			vr = 0;
		else
			vr = slatkoca * kiselost * masa * 1000;
		return vr;
	}
	ostream& ispis(ostream& o)
	{
		this->Predmet::ispis(o);
		o << "Koeficijent slatkoce: " << slatkoca << endl;
		o << "Koeficijent kiselosti: " << kiselost << endl;
		o << "Boja: " << boja << endl;
		o << "Vrednost: " << this->vrednost() << endl;
		o << "Vrednost po jedinici mase: " << this->vrednostPoMasi() << endl;
		return o;
	}
	istream& upis(istream& i)
	{
		cout << "Upis jabuke:\n";
		this->Predmet::upis(i);
		cout << "Upisi slatkocu: " << endl;
		i >> slatkoca;
		cout << "Upisi kiselost: " << endl;
		i >> kiselost;
		cout << "Upisi boju: " << endl;
		i >> boja;
		return i;
	}
	friend istream& operator>>(istream& i, Jabuke& p)
	{
		p.upis(i);
		return i;
	}
private:
	double slatkoca;
	double kiselost;
	char* boja;
};


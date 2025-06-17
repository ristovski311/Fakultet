#pragma once
#include "Predmet.h"
class DragoKamenje : public Predmet
{
public:
	DragoKamenje()
	{
		boja = new char[20];
	}
	DragoKamenje(double masa, double cisto, const char* boja1, int rez1) : Predmet(masa)
	{
		if(cisto <= 1 && cisto >= 0)
		{
			cistoca = cisto;
		}
		else
			cistoca = 0;
		rez = rez1;
		boja = new char[strlen(boja1) + 1];
		strcpy(boja, boja1);
	}
	~DragoKamenje()
	{
		delete[] boja;
		boja = nullptr;
	}
	double vrednost()
	{
		return cistoca + masa;
	}
	ostream& ispis(ostream& o)
	{
		this->Predmet::ispis(o);
		o << "Koeficijent cistoce: " << cistoca << endl;
		o << "Boja: " << boja << endl;
		o << "Rez: " << rez << endl;
		o << "Vrednost: " << this->vrednost() << endl;
		o << "Vrednost po jedinici mase: " << this->vrednostPoMasi() << endl;
		return o;
	}
	istream& upis(istream& i)
	{
		cout << "Upis dragog kamena:\n";
		this->Predmet::upis(i);
		cout << "Upisi cistocu: " << endl;
		i >> cistoca;
		cout << "Upisi rez: " << endl;
		i >> rez;
		cout << "Upisi boju: " << endl;
		i >> boja;
		return i;
	}
	friend istream& operator>>(istream& i, DragoKamenje& p)
	{
		p.upis(i);
		return i;
	}
private:
	double cistoca;
	char* boja;
	int rez;
};


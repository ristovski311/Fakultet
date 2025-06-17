#pragma once
#include "Predmet.h"
class ZlatnePoluge : public Predmet
{
private:
	double stepenCistoce;
public:
	ZlatnePoluge()
	{

	}
	ZlatnePoluge(double masa, double sc) : Predmet(masa)
	{
		if (stepenCistoce >= 0 && stepenCistoce <= 24)
			stepenCistoce = sc;
		else
			stepenCistoce = 0;
	}
	~ZlatnePoluge(){}
	double vrednost()
	{
		return stepenCistoce / 24 * masa;
	}
	ostream& ispis(ostream& o)
	{
		this->Predmet::ispis(o);
		o << "Stepen cistoce: " << stepenCistoce << endl;
		o << "Vrednost: " << this->vrednost() << endl;
		o << "Vrednost po jedinici mase: " << this->vrednostPoMasi() << endl;
		return o;
	}
	istream& upis(istream& i)
	{
		cout << "Upis zlatne poluge:\n";
		this->Predmet::upis(i);
		cout << "Upisi stepen cistoce: " << endl;
		i >> stepenCistoce;
		return i;
	}
	friend istream& operator>>(istream& i, ZlatnePoluge& p)
	{
		p.upis(i);
		return i;
	}
};


#pragma once
#include "HDD.h"
class SSD : public HDD
{
private:
	int brzinaCitanja;
	int brzinaUpisa;
public:
	SSD(const char* marka, int mem, int bc, int bu) : HDD(marka,mem)
	{
		this->brzinaCitanja = bc;
		this->brzinaUpisa = bu;
	}
	~SSD(){}
	void ispisi()
	{
		cout << "\t\t\tSSD marke:" << this->marka << ", kapaciteta: " << this->memorija << ", brzine citanja: " << this->brzinaCitanja << ", brzine upisa: " << this->brzinaUpisa << endl;
	}
};


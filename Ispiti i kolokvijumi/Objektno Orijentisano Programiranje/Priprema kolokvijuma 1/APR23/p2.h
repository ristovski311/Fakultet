#pragma once
#include "Paragraf.h"
class p2 : public Paragraf
{
public:
	p2()
	{
		originalniPar = nullptr;
	}
	virtual ostream& upisiPar(ostream& o)
	{
		int i = 0;
		while (this->originalniPar[i] != '\0')
			i++;
		for (int j = i - 1; j >= 0; j--)
			o << originalniPar[j];
		o << endl;
		return o;
	}

};


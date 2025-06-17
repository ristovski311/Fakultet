#pragma once
#include "Paragraf.h"
class p1 : public Paragraf
{
public:
	p1()
	{
		originalniPar = nullptr;
	}
	virtual ostream& upisiPar(ostream& o)
	{
		int i = 0;
		char temp;
		while (this->originalniPar[i] != '\0')
			i++;
		for (int j = 0; j < i; j++)
		{
			if (originalniPar[j] >= 'a' && originalniPar[j] <= 'z')
			{
				temp = originalniPar[j] - 'a' + 'A';
				o << temp;
			}
			else if (originalniPar[j] >= 'A' && originalniPar[j] <= 'Z')
			{
				temp = originalniPar[j] + 'a' - 'A';
				o << temp;
			}
			else
				o << originalniPar[j];
		}	
		o << endl;
		return o;
	}
};


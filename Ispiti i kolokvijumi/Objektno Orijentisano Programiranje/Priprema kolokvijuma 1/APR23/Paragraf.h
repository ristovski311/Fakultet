#pragma once
#include <iostream>
using namespace std;
class Paragraf
{
public:
	Paragraf()
	{
		originalniPar = nullptr;
	}
	virtual ostream& upisiPar(ostream& o) = 0;
	virtual istream& ispisiPar(istream& i)
	{
		char* temp = new char[255];
		char curr;
		int p = 0;
		i.get(curr);
		while (curr != '\n')
		{
			temp[p] = curr;
			p++;
			i.get(curr);
		}
		temp[p] = '\0';
		originalniPar = temp;
		return i;
		
	}
protected:
	const char* originalniPar;
};


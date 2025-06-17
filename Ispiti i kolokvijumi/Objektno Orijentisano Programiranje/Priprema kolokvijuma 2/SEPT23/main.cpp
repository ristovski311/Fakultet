#include <iostream>
#include <fstream>
#include "Proizvod.h"
#include "Prodavnica.h"
using namespace std;

int main()
{
	try
	{
		Prodavnica<double> psi("prodavnica_psi", 2);
		for (int i = 0; i < 4; i++)
		{
			double temp;
			cin >> temp;
			psi.Dodaj(temp);
		}
		psi.Prodaj(1);
		ofstream o("psi.txt");
		o << psi;
		o.close();
		Prodavnica<double> psi2;
		ifstream i("psi.txt");
		i >> psi2;
		cout << "\n\n[][][][][][][]\n\n" << psi2;
		i.close();
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	return 0;
}
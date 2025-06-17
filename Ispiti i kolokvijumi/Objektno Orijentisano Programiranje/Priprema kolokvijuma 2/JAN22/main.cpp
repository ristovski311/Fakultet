#include <iostream>
#include <fstream>
#include "Skup.h"
#include "Takmicar.h"

using namespace std;

int main()
{
	/*try
	{
		Skup<int> intskup(5);
		ifstream i("int.txt");
		i >> intskup;
		cout << intskup << endl << "---" << endl;
		int a = 1;
		intskup.Dodaj(a);
		cout << intskup << endl << "---" << endl;
		intskup.Brisi(1);
		cout << intskup << endl << "---" << endl;
		Skup<int> intskup2(7);
		for (int i = 0; i < 7; i++)
			intskup2.Dodaj(i);
		cout << intskup2 << endl << "---" << endl;
		Skup<int> rez;
		rez = intskup.Unija(intskup2);
		cout << rez;
	}
	catch (const char* msg)
	{
		cout << msg;
	}*/


	try
	{
		Skup<Takmicar> takmskup(5);
		ifstream i("takmicar.txt");
		i >> takmskup;
		cout << takmskup << endl << "---" << endl;
		Takmicar a(5,5,5);
		takmskup.Dodaj(a);
		cout << takmskup << endl << "---" << endl;
		takmskup.Brisi(1);
		cout << takmskup << endl << "---" << endl;
		Skup<Takmicar> takmskup2(7);
		for (int i = 0; i < 7; i++)
		{
			Takmicar temp(i, i, i);
			takmskup2.Dodaj(temp);
		}
		cout << takmskup2 << endl << "---" << endl;
		Skup<Takmicar> rez;
		rez = takmskup.Unija(takmskup2);
		cout << rez;
	}
	catch (const char* msg)
	{
		cout << msg;
	}


	return 0;
}
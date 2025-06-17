#include <iostream>
#include <fstream>
#include "Kontejner.h"
#include "Kvadar.h"
using namespace std;

int main()
{
	/*try
	{
		int a = 2;
		int* pa = &a;
		Kontejner<int> kint(10);
		ifstream i("int.txt");
		i >> kint;
		cout << kint << endl;
		kint.Uredi();
		cout << kint << endl;
		cout << kint.Prosek() << endl;
		kint.Dodaj(pa);
		cout << kint << endl;
		kint.Uredi();
		cout << kint << endl;
		cout << kint.Prosek() << endl;
		i.close();
		ofstream o("int.txt");
		o << kint;
	}
	catch (const char* msg)
	{
		cout << msg;
	}*/

	try
	{
		Kvadar a(1,1,1,1);
		Kvadar* pa = &a;
		Kontejner<Kvadar> kkv(6);
		ifstream i("kvadar.txt");
		i >> kkv;
		cout << kkv << endl;
		kkv.Uredi();
		cout << kkv << endl;
		cout << kkv.Prosek() << endl;
		kkv.Dodaj(pa);
		cout << kkv << endl;
		kkv.Uredi();
		cout << kkv << endl;
		cout << kkv.Prosek() << endl;
		i.close();
		ofstream o("kvadar.txt");
		o << kkv;
	}
	catch (const char* msg)
	{
		cout << msg;
	}



	return 0;
}
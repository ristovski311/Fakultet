#include <iostream>
#include <fstream>
#include "KvadratnaMatrica.h"
#include "Complex.h"
using namespace std;

int main()
{
	try
	{
		KvadratnaMatrica<int> intmat(3);
		cin >> intmat;
		KvadratnaMatrica<int> intmat2(3);
		intmat2.Citaj("ucitajint.txt");
		cout << intmat;
		cout << intmat2;
		KvadratnaMatrica<int> sumaint(3);
		sumaint = intmat + intmat2;
		sumaint.Ispisi("intsuma.txt");
		KvadratnaMatrica<int> proizint(3);
		proizint = intmat * intmat2;
		proizint.Ispisi("intproiz.txt");
	}
	catch (const char* msg)
	{
		cout << msg;
	}


	return 0;
}
#include "p1.h"
#include "p2.h"
#include "Paragraf.h"
#include "Tekst.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const char* isp = "tekst.txt";
	const char* ups = "izlazni_tekst.txt";
	Tekst* tekst1 = new Tekst(10);
	p1* p1_1 = new p1();
	p2* p2_1 = new p2();
	p1* p1_2 = new p1();
	p2* p2_2 = new p2();
	tekst1->Dodaj(p1_1);
	tekst1->Dodaj(p2_1);
	tekst1->Dodaj(p1_2);
	tekst1->Dodaj(p2_2);
	tekst1->Citaj(isp);
	tekst1->Upisi(ups);
}
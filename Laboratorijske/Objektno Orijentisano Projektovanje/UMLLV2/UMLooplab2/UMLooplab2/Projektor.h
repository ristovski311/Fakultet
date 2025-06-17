#pragma once
#include <iostream>
using namespace std;
class Projektor
{
private:
	char* tip;
	char* prikljucak;
public:
	Projektor(const char* t, const char* pr);
	~Projektor();
	void ispisi();
};


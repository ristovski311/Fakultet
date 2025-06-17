#pragma once
#include <iostream>
using namespace std;
class IzlozbeniPosetioci
{
public:
	IzlozbeniPosetioci(int x = 0, int y = 0, int z = 0);
	IzlozbeniPosetioci(IzlozbeniPosetioci& i);
	~IzlozbeniPosetioci();
	int ukupno();
	float zarada();
	friend int operator+(int s, IzlozbeniPosetioci i);
	friend ostream& operator<<(ostream& o, IzlozbeniPosetioci& i);
	friend istream& operator>>(istream& i, IzlozbeniPosetioci& ip);
	bool operator>(IzlozbeniPosetioci& ip);
private:
	int odrasli;
	int deca;
	int skola;
};


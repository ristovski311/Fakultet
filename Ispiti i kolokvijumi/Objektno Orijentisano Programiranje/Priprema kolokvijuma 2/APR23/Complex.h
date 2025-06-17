#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Complex
{
public:
	Complex(double x = 0, double y = 0);
	Complex(Complex& c);
	~Complex();
	friend istream& operator>>(istream& i, Complex& c);
	friend ostream& operator<<(ostream& o, Complex& c);
	Complex operator+(Complex c);
	Complex operator*(Complex c);
private:
	double real;
	double imag;
};


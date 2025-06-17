#include "Complex.h"


Complex::Complex(double x, double y)
{
	real = x;
	imag = y;
}
Complex::Complex(Complex& c)
{
	c.real = this->real;
	c.imag = this->imag;
}
Complex::~Complex(){}
istream& operator>>(istream& i, Complex& c)
{
	i >> c.real;
	i >> c.imag;
	return i;
}
ostream& operator<<(ostream& o, Complex& c)
{
	o << c.real << c.imag << endl;
	return o;
}
Complex Complex::operator+(Complex c)
{
	Complex temp(this->real + c.real, this->imag + c.imag);
	return temp;
}
Complex Complex::operator*(Complex c)
{
	Complex temp(this->real * c.real, this->imag * c.imag);
	return temp;
}
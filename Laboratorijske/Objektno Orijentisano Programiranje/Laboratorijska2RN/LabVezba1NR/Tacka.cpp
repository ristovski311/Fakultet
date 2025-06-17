#include "Tacka.h"


Tacka::Tacka(double x, double y, double z) : x(x), y(y), z(z) {}

istream& operator>>(istream& ulaz, Tacka& t)
{
	ulaz >> t.x;
	ulaz >> t.y;
	ulaz >> t.z;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Tacka& t)
{
	izlaz << "(" << t.x << "," << t.y << "," << t.z << ")";
	return izlaz;
}

Tacka& Tacka::operator+(Tacka& t2)
{
	Tacka t3;
	t3.x += this->x + t2.x;
	t3.y += this->y + t2.y;
	t3.z += this->z + t2.z;
	return t3;
}

Tacka Tacka::operator+(Tacka t2)
{
	Tacka t3;
	t3.x += this->x + t2.x;
	t3.y += this->y + t2.y;
	t3.z += this->z + t2.z;
	return t3;
}

Tacka Tacka::operator-(Tacka& t2)
{
	Tacka t3;
	t3.x += this->x - t2.x;
	t3.y += this->y - t2.y;
	t3.z += this->z - t2.z;
	return t3;
}

Tacka Tacka::operator+=(Tacka& t2)
{
	this->x += t2.x;
	this->y += t2.y;
	this->z += t2.z;

	return *this;
}

Tacka Tacka::operator*(Tacka& t2)
{
	Tacka t3;
	t3.x = this->x * t2.x;
	t3.y = this->y * t2.y;
	t3.z = this->z * t2.z;
	return t3;
}

Tacka& Tacka::Postavi(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return *this;
}

Tacka& Tacka::operator++(int n)
{
	this->x++;
	this->y++;
	this->z++;
	return *this;
}

bool Tacka::operator==(Tacka& t2)
{
	if (this->x == t2.x && this->y == t2.y && this->z == t2.z)
		return true;
	else
		return false;
}
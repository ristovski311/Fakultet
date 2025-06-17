#include "DnevnoNocnaKarta.h"

DnevnoNocnaKarta::DnevnoNocnaKarta(int id, int redBrDana, int brDanaVazenja, int brNociVazenja)
	: DnevnaKarta(id, redBrDana, brDanaVazenja)
{
	if (brNociVazenja == brDanaVazenja - 1 || brNociVazenja == brDanaVazenja)
	{
		this->brNociVazenja = brNociVazenja;
	}
	else
	{
		cout << "Greska! Broj noci vazenja sme biti samo jednak ili za 1 manji od broja dana vazenja!";
		this->brNociVazenja = this->getBrDanaVazenja();
	}
	this->tip = "nocna";
	this->cenaNocne = this->osnovnaCenaNocne - 0.02 * (this->popust + (double)this->brNociVazenja);
	this->brNociVazenja = brNociVazenja;
}

void DnevnoNocnaKarta::produzi(int broj)
{
	this->DnevnaKarta::produzi(broj);
	this->brNociVazenja += broj;
	this->cenaNocne = this->osnovnaCenaNocne - 0.02 * (this->popust + (double)this->brNociVazenja);
	cout << "Produzena nocna karta: " << this->getId() << endl;
}

ostream& operator<<(ostream& o, DnevnoNocnaKarta& dnk)
{
	o << "ID: " << dnk.getId() << endl;
	o << "Cena: " << dnk.getCena() << endl;
	o << "Vazi od dana: " << dnk.getRedBrDana() << endl;
	o << "Vazi dana: " << dnk.getBrDanaVazenja() << endl;
	o << "Vazi noci: " << dnk.brNociVazenja << endl;
	return o;
}
#include "DnevnaKarta.h"

DnevnaKarta::DnevnaKarta(int id, int redBrDana, int brDanaVazenja)
{
	this->tip = "dnevna";
	this->id = id;
	this->redBrDana = redBrDana;
	this->brDanaVazenja = brDanaVazenja;
	this->cenaDnevne = this->osnovnaCenaDnevne - 0.02 * (this->popust + (double)this->brDanaVazenja);
}

void DnevnaKarta::produzi(int broj)
{
	this->brDanaVazenja += broj;
	this->cenaDnevne = this->osnovnaCenaDnevne - 0.02 * (this->popust + (double)this->brDanaVazenja);
	cout << "Produzena dnevna karta: " << this->getId() << endl;
}

ostream& operator<<(ostream& o, DnevnaKarta& dk)
{
	o << "ID: " << dk.getId() << endl;
	o << "Cena: " << dk.getCena() << endl;
	o << "Vazi od dana: " << dk.getRedBrDana() << endl;
	o << "Vazi dana: " << dk.getBrDanaVazenja() << endl;
	return o;
}

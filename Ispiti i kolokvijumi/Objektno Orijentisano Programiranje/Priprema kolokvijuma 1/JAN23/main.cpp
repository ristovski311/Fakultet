#include "DnevnaKarta.h"
#include "DnevnoNocnaKarta.h"
#include "KolekcijaKarata.h"
#include <fstream>
using namespace std;

double DnevnaKarta::osnovnaCenaDnevne = 10;
double DnevnaKarta::popust = 2;
double DnevnoNocnaKarta::osnovnaCenaNocne = 12;


int main()
{
	KolekcijaKarata kol1(6);
	DnevnaKarta* dk1 = new DnevnaKarta(1, 1, 10);
	DnevnoNocnaKarta* dnk1 = new DnevnoNocnaKarta(2, 2, 10, 10);
	DnevnaKarta* dk2 = new DnevnaKarta(3, 4, 5);
	DnevnoNocnaKarta* dnk2 = new DnevnoNocnaKarta(4, 5, 20, 19);
	
	kol1.kupiKartu(dk1);
	kol1.kupiKartu(dnk1);
	kol1.kupiKartu(dk2);
	kol1.kupiKartu(dnk2);

	kol1.spisak(cout);

	DnevnoNocnaKarta* dnk3 = new DnevnoNocnaKarta(5, 1, 10, 20);
	kol1.kupiKartu(dnk3);

	cout << "\n\n\n";

	kol1.spisak(cout);
	cout << endl << kol1.zarada() << endl;
	cout << kol1.brojVazecih(14, "nocna") << endl;
	cout << kol1.vratiNajduzu();
	cout << kol1.vratiNajkracu();

	kol1.ponistiKartu(1);
	dk2->produzi(100);
	cout << "\n---\n";

	kol1.spisak(cout);

	return 0;
}

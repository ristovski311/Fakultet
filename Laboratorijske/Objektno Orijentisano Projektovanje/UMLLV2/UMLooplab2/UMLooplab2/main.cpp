#include <iostream>
#include "Fakultet.h"

using namespace std;

void main()
{
	//tip projektora tip prikljucka (vga hdmi dvi)
	Fakultet* Elektronski;
	Elektronski = Fakultet::getInstanca();
	Elektronski->postaviParametre("Elektronski Fakultet u Nisu", 1960, 10);

	Switch* sw1 = new Switch(24);
	Switch* sw2 = new Switch(24);
	Switch* sw3 = new Switch(24);

	Projektor* proj1 = new Projektor("VEGA", "hdmi");
	Projektor* proj2 = new Projektor("PROJECT", "vga");
	Projektor* proj3 = new Projektor("STAR", "dvi");
	Projektor* proj4 = new Projektor("PROJECT", "nesto");

	RacunarskaUcionica* r1 = new RacunarskaUcionica("R01", 24, sw1, proj1);
	RacunarskaUcionica* r2 = new RacunarskaUcionica("R02", 20, sw2, proj2);
	RacunarskaUcionica* r3 = new RacunarskaUcionica("R03", 40, sw2, proj3);

	Elektronski->registrujUcionicu(r1);
	Elektronski->registrujUcionicu(r2);
	Elektronski->registrujUcionicu(r3);

	Procesor* pr1 = new Procesor(10, 2, 1);
	Procesor* pr2 = new Procesor(5, 2, 1);
	Procesor* pr3 = new Procesor(15, 2, 2);
	Procesor* pr4 = new Procesor(20, 3, 3);
	Procesor* pr5 = new Procesor(25, 2, 1);
	Procesor* pr6 = new Procesor(30, 5, 6);
	Procesor* pr7 = new Procesor(35, 2, 1);
	Procesor* pr8 = new Procesor(40, 6, 5);
	Procesor* pr9 = new Procesor(45, 1, 1);
	Procesor* pr10 = new Procesor(50, 7, 3);

	RAM* ram1 = new RAM(1, 100, "tip1");
	RAM* ram2 = new RAM(2, 100, "tip2");
	RAM* ram3 = new RAM(3, 100, "tip3");
	RAM* ram4 = new RAM(4, 100, "tip4");
	RAM* ram5 = new RAM(5, 100, "tip5");
	RAM* ram6 = new RAM(6, 100, "tip6");

	HDD* hdd1 = new HDD("marka1", 1000);
	HDD* hdd2 = new HDD("marka2", 2000);
	HDD* hdd3 = new HDD("marka3", 1000);
	HDD* hdd4 = new HDD("marka4", 3000);
	HDD* hdd5 = new HDD("marka5", 8000);
	HDD* hdd6 = new HDD("marka6", 5000);

	HDD* ssd1 = new SSD("markass1", 9000, 10, 15);
	HDD* ssd2 = new SSD("markassd2", 4500, 15, 12);

	Tastatura* ta1 = new Tastatura("marka1");
	Tastatura* ta2 = new Tastatura("marka1");
	Tastatura* ta3 = new Tastatura("marka2");
	Tastatura* ta4 = new Tastatura("marka2");
	Tastatura* ta5 = new Tastatura("marka3");
	Tastatura* ta6 = new Tastatura("marka3");

	Monitor* mon1 = new Monitor(10.5, "1080x720", "marka1");
	Monitor* mon2 = new Monitor(20.5, "1080x720", "marka2");
	Monitor* mon3 = new Monitor(14.7, "1080x720", "marka3");
	Monitor* mon4 = new Monitor(10.5, "4k", "marka3");
	Monitor* mon5 = new Monitor(10.5, "1080x720", "marka4");
	Monitor* mon6 = new Monitor(15.5, "fHD", "marka1");

	Racunar* racunar1 = new Racunar("RAC01", true, 1, 1, pr1, hdd1, ram1, ta1, mon1);
	Racunar* racunar2 = new Racunar("RAC02", true, 5, 3, pr2, hdd2, ram2, ta2, mon2);
	racunar2->ugradiHDD(ssd1);
	racunar2->ugradiProcesor(pr10);
	Racunar* racunar3 = new Racunar("RAC03", true, 3, 1, pr3, hdd3, ram3, ta3, mon3);
	racunar3->ugradiProcesor(pr7);
	racunar3->ugradiProcesor(pr8);
	racunar3->ugradiProcesor(pr9);
	Racunar* racunar4 = new Racunar("RAC04", true, 1, 1, pr4, hdd4, ram4, ta4, mon4);
	Racunar* racunar5 = new Racunar("RAC05", true, 2, 4, pr5, hdd5, ram5, ta5, mon5);
	racunar5->ugradiHDD(ssd2);
	Racunar* racunar6 = new Racunar("RAC06", false, 3, 1, pr6, hdd6, ram6, ta6, mon6);

	r1->dodajRacunar(racunar1,1);
	r1->dodajRacunar(racunar2,2);

	r3->dodajRacunar(racunar3,1);
	r3->dodajRacunar(racunar4,3);
	r3->dodajRacunar(racunar5,5);
	r3->dodajRacunar(racunar6,7);

	Elektronski->izvestaj();
	Elektronski->izvestajNeispravni();

	cout << "\n\n------------------------------2222--------------------------------\n\n";

	r3->ukloniRacunar("RAC05");
	Elektronski->izvestaj();
	Elektronski->izvestajNeispravni();

	cout << "\n\n-----------------------------3333---------------------------------\n\n";

	racunar1->setNeispravan();
	Elektronski->izvestaj();
	Elektronski->izvestajNeispravni();

	cout << "\n\n-------------------------------4444-------------------------------\n\n";

	racunar1->setIspravan();
	Elektronski->izvestaj();
	Elektronski->izvestajNeispravni();

	delete sw1;
	delete sw2;
	delete sw3;

	delete pr1;
	delete pr2;
	delete pr3;
	delete pr4;
	delete pr5;
	delete pr6;
	delete pr7;
	delete pr8;
	delete pr9;
	delete pr10;
	
	delete ram1;
	delete ram2;
	delete ram3;
	delete ram4;
	delete ram5;
	delete ram6;

	delete hdd1;
	delete hdd2;
	delete hdd3;
	delete hdd4;
	delete hdd5;
	delete hdd6;

	delete ssd1;
	delete ssd2;

	
	delete ta1;
	delete ta2;
	delete ta3;
	delete ta4;
	delete ta5;
	delete ta6;

	delete mon1;
	delete mon2;
	delete mon3;
	delete mon4;
	delete mon5;
	delete mon6;

	delete racunar1;
	delete racunar2;
	delete racunar3;
	delete racunar4;
	delete racunar5;
	delete racunar6;

	delete proj1;
	delete proj2;
	delete proj3;
	delete proj4;

	delete Elektronski;
}

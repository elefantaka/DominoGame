#ifndef STOLDODOBORU_H
#define STOLDODOBORU_H

#include "Pionek.h"
#include <iostream>
#include <string>

using namespace std;

class StolDoDoboru {
	Pionek *tab; //tablica pionkow
	int poczatek;
	int koniec;
public:
	StolDoDoboru();
	void dodajPozostalePionki(Pionek tabPionkow[], int ileDoStoluDoDoboru);
	void drukuj();
	Pionek dajPionek();
	bool czyPustyStol();
};

#endif
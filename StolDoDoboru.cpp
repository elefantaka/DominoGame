#include "Pionek.h"
#include "StolDoDoboru.h"

#include <iostream>
#include <string>

using namespace std;

StolDoDoboru::StolDoDoboru() {
	tab = new Pionek[PudelkoPionkow::N];
	poczatek = -1;
	koniec = -1;
}

void StolDoDoboru::dodajPozostalePionki(Pionek tabPionkow[], int ileDoStoluDoDoboru) {
	if (ileDoStoluDoDoboru > 0) {
		poczatek = 0;
		for (int i = PudelkoPionkow::N - ileDoStoluDoDoboru; i < PudelkoPionkow::N; i++) {
			koniec++;
			tab[koniec] = tabPionkow[i];
		}
	}
}

void StolDoDoboru::drukuj() {
	cout << "Stol do doboru: ";
	if (poczatek == -1) {
		cout << "Stol do doboru jest pusty";
	}
	else {
		for (int i = poczatek; i <= koniec; i++) {
			tab[i].drukuj();
		}
	}
	cout << endl << endl;
}

bool StolDoDoboru::czyPustyStol() {
	if (poczatek == -1) {
		return true;  //stol jest pusty
	}
	else if (poczatek > koniec) {
		return true;
	}
	else {
		return false;  //stol nie jest pusty
	}
}

Pionek StolDoDoboru::dajPionek() {
	if (czyPustyStol() == true) {
		Pionek p(-1, -1);
		return p;
	}
	else {
		Pionek p = tab[poczatek];
		poczatek++;
		return p;
	}
}
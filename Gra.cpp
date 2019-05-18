#include "Gra.h"
#include "Gracz.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Gra::Gra() {
	//cout << "Konstruktor domyslny gracz." << endl;
	tworzGraczy();
}

void Gra::rozdajPionki() {
	int ilePionkowNaPoczatku;
	if (ileGraczy <= 4) {
		ilePionkowNaPoczatku = 7;
	}
	else {
		ilePionkowNaPoczatku = PudelkoPionkow::N / ileGraczy;
	}
	int ileStolDoDoboru = PudelkoPionkow::N - ileGraczy * ilePionkowNaPoczatku;
	pp.mieszaj();
	int indeksPionka = 0;
	for (int i = 0; i < ilePionkowNaPoczatku; i++) {
		for (int j = 0; j < ileGraczy; j++) {
			Pionek p = pp.dajPionek(indeksPionka);
			tabGraczy[j]->wezPionek(p);
			indeksPionka++;
		}
	}
	stoldd.dodajPozostalePionki(pp.pokazTablice(), ileStolDoDoboru);
}

void Gra::rozgrywka() {
	rozdajPionki();
	drukuj();
	wykladaniePionkow();
}

void Gra::tworzGraczy() {
	int ileOsob;
	cout << "Podaj liczbe graczy." << endl;
	cin >> ileGraczy;
	cout << "Podaj ilosc osob" << endl;
	cin >> ileOsob;
	if (ileOsob > ileGraczy) {
		ileOsob = ileGraczy;
	}
	for (int i = 0; i < ileOsob; i++) {
		tabGraczy[i] = new GraczOsoba;
		cout << "Podaj imie gracza:" << i << endl;
		tabGraczy[i]->wczytajImie(i);
	}

	for (int i = ileOsob; i < ileGraczy; i++) {
		tabGraczy[i] = new GraczKomputer;
		tabGraczy[i]->wczytajImie(i);
	}
}

void Gra::wykladaniePionkow() {
	int ktoZaczyna = rand() % ileGraczy;
	cout << "Gre rozpoczyna gracz nr: " << ktoZaczyna << endl;
	int aktualnyGracz = ktoZaczyna;
	while (true) {
		linia.drukuj();
		tabGraczy[aktualnyGracz]->ruch();
		if (aktualnyGracz < (ileGraczy - 1)) {
			aktualnyGracz++;
		}
		else {
			aktualnyGracz = 0;
		}
	}
}

void Gra::drukuj() {
	for (int i = 0; i < ileGraczy; i++) {
		tabGraczy[i]->drukuj();
	}
	stoldd.drukuj();
}
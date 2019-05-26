#include "Gra.h"
#include "Gracz.h"
#include "Wynik.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Gra::Gra() {
	//cout << "Konstruktor domyslny gracz." << endl;
	linia = new LiniaNaStole;
	tworzGraczy();
	for (int i = 0; i < ileGraczy; i++) {
		tabGraczy[i]->ustawLinieNaStole(linia);
	}
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
	if (ileGraczy == 0) {
		return;
	}
	rozdajPionki();
	drukuj();
	wykladaniePionkow();
	Wynik w(tabGraczy, ileGraczy);
	w.wypisz();
}

void Gra::tworzGraczy() {
	int ileOsob;
	cout << "Podaj liczbe graczy." << endl;
	cin >> ileGraczy;
	if (ileGraczy < 0 || ileGraczy > 28) {
		cout << "Niepoprawna ilosc graczy" << endl;
		ileGraczy = 0;
		return;
	}
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
	linia->drukuj();
	bool koniecGry = false;
	int numerMiejsca = 1;
	int licznikNieaktywanychGraczy = 0;
	while (koniecGry == false) {
		tabGraczy[aktualnyGracz]->drukuj();
		if (tabGraczy[aktualnyGracz]->getJuzSkonczyl() == false) {
			bool koniecRuchu = false;
			while (koniecRuchu == false) {
				bool czyDodaldoLinii = tabGraczy[aktualnyGracz]->ruch();
				if ((czyDodaldoLinii == false) && (stoldd.czyPustyStol() == false)) {
					Pionek p = stoldd.dajPionek();  //daj pionek
					tabGraczy[aktualnyGracz]->dobierzPionek(p);  //brakuje ddobierz pionek
					licznikNieaktywanychGraczy = 0;
				}
				else { //nie dobral pionka
					if (czyDodaldoLinii == false) {
						licznikNieaktywanychGraczy++;
					}
					else {
						licznikNieaktywanychGraczy = 0;
					}
					koniecRuchu = true;
				}
				tabGraczy[aktualnyGracz]->drukuj();
			}
			if (tabGraczy[aktualnyGracz]->getIleWlasnych() == 0) {
				tabGraczy[aktualnyGracz]->zakoncz();
				tabGraczy[aktualnyGracz]->setMiejsce(numerMiejsca);
				cout << "Gracz zakonczy gre na miejscu:" << numerMiejsca << endl;
				numerMiejsca++;
			}
		}
		else {
			cout << "Omijamy wygraczegi gracza";
			tabGraczy[aktualnyGracz]->drukuj();
			licznikNieaktywanychGraczy++;
		}
		linia->drukuj();
		if (licznikNieaktywanychGraczy == ileGraczy) {
			koniecGry = true;
		}
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
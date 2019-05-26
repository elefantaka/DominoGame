#include "Gracz.h"
#include "Wynik.h"

#include <iostream>
#include <string>

using namespace std;

Wynik::Wynik(Gracz **tabKolejnosc, int ileGraczy) {
	this->tabKolejnosc = tabKolejnosc;
	this->ileGraczy = ileGraczy;
	ustalMiejsca();
}

void Wynik::ustalMiejsca() {
	for (int i = 0; i < ileGraczy; i++) {
		for (int j = 0; j < (ileGraczy - 1); j++) {
			bool zamiana = false;
			if ((tabKolejnosc[j]->getMiejsce() == -1) && (tabKolejnosc[j + 1]->getMiejsce() > -1)) {
				zamiana = true;
			}
			if ((tabKolejnosc[j]->getMiejsce() == -1) && (tabKolejnosc[j + 1]->getMiejsce() == -1) && (tabKolejnosc[j]->getIleWlasnych() > tabKolejnosc[j + 1]->getIleWlasnych())) {
				zamiana = true;
			}
			if ((tabKolejnosc[j + 1]->getMiejsce() > -1) && (tabKolejnosc[j]->getMiejsce() > -1) && (tabKolejnosc[j]->getMiejsce() > tabKolejnosc[j + 1]->getMiejsce())) {
				zamiana = true;
			}
			if (zamiana == true) {
				Gracz *temp = tabKolejnosc[j];
				tabKolejnosc[j] = tabKolejnosc[j + 1];
				tabKolejnosc[j + 1] = temp;
			}
		}
	}
}

void Wynik::ustalPodium() {

}

void Wynik::wypisz() {
	cout << "Gra zakoczona. Wyniki: " << endl;
	for (int i = 0; i < ileGraczy; i++) {
		tabKolejnosc[i]->drukujMiejsce();
	}
}

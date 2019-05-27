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

void Wynik::wypisz() {
	cout << endl << "Gra zakoczona. Wyniki: " << endl;
	for (int i = 0; i < ileGraczy; i++) {
		tabKolejnosc[i]->drukujMiejsce();
	}
}

ostream& operator<<(ostream& os, const Wynik &W) {
	os << endl << "Gra zakoczona. Wyniki: " << endl;
	for (int i = 0; i < W.ileGraczy; i++) {
		Gracz *g = W.tabKolejnosc[i];
		os << "Gracz " << g->getImie() << "miejsce " << g->getMiejsce() << ": "; 
		if (g->getIleWlasnych() == 0) {
			os << "Gracz nie posiada pionkow";
		}
		else {
			for (int i = 0; i < g->getIleWlasnych(); i++) {
				os << "{" << g->getPionek(i).getA() << "," << g->getPionek(i).getB() << "}"; 
			}
		}
		cout << endl;
	}
	return os;
}

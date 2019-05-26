#include "LiniaNaStole.h"
#include "Pionek.h"

#include <iostream>
#include <string>

using namespace std;

LiniaNaStole::LiniaNaStole() {
	glowa = NULL;
}

bool LiniaNaStole::dodajPoLewej(Pionek p) {
	if (wolnoDodacPoLewej(p) == false) {
		cout << "Niepoprawny ruch" << endl;
		return false;
	}
	Element *nowy = new Element;
	nowy->pion = p;
	nowy->nast = glowa;
	glowa = nowy;
	return true;
}

bool LiniaNaStole::dodajPoPrawej(Pionek p) {
	if (wolnoDodacPoPrawej(p) == false) {
		cout << "Niepoprawny ruch" << endl;
		return false;
	}
	Element *nowy = new Element;
	nowy->pion = p;
	nowy->nast = NULL;
	if (glowa == NULL) {
		glowa = nowy;
	}
	else {
		Element *temp;
		temp = glowa;
		while (temp->nast != NULL) {
			temp = temp->nast;
		}
		temp->nast = nowy;
	}
	return true;
}

bool LiniaNaStole::wolnoDodacPoLewej(Pionek p) {
	if (glowa == NULL) {
		return true;
	}
	int lewyKoniecLinii = glowa->pion.getA();
	if (p.getB() == lewyKoniecLinii) {
		return true;
	}
	else {
		return false;
	}
}

bool LiniaNaStole::wolnoDodacPoPrawej(Pionek p) {
	if (glowa == NULL) {
		return true;
	}
	int prawyKoniecLinii;
	Element *aktualny;
	aktualny = glowa;
	while (aktualny->nast != NULL) {
		aktualny = aktualny->nast;
	}
	prawyKoniecLinii = aktualny->pion.getB();
	if (p.getA() == prawyKoniecLinii) {
		return true;
	}
	else {
		return false;
	}
}

int LiniaNaStole::pokazLewyKoniec() {
	if (glowa == NULL) {
		return -1;
	}
	else {
		return glowa->pion.getA();
	}
}

int LiniaNaStole::pokazPrawyKoniec() {
	if (glowa == NULL) {
		return -1;
	}
	else {
		Element *aktualny;
		aktualny = glowa;
		while (aktualny->nast != NULL) {
			aktualny = aktualny->nast;
		}
		return aktualny->pion.getB();
	}
}

bool LiniaNaStole::czyLiniaPusta() {
	if (glowa == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void LiniaNaStole::drukuj() {
	if (glowa == NULL) {
		cout << "Linia na stole jest pusta.";
	}
	else {
		cout << "Linia na stole:";
		Element *temp;
		temp = glowa;
		while (temp != NULL) {
			temp->pion.drukuj();
			temp = temp->nast;
		}
	}
	cout << endl;
}
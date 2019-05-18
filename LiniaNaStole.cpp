#include "LiniaNaStole.h"

#include <iostream>
#include <string>

using namespace std;

LiniaNaStole::LiniaNaStole() {
	glowa = NULL;
}

void LiniaNaStole::dodajPoLewej(Pionek p) {
	Element *nowy = new Element;
	nowy->pion = p;
	nowy->nast = glowa;
	glowa = nowy;
}

void LiniaNaStole::dodajPoPrawej(Pionek p) {
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
}

void LiniaNaStole::drukuj() {
	if (glowa == NULL) {
		cout << "Linia na stole jest pusta." << endl;
	}
	else {
		Element *temp;
		temp = glowa;
		while (temp != NULL) {
			temp->pion.drukuj();
			temp = temp->nast;
		}
	}
}
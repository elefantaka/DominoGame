#ifndef WYNIK_H
#define WYNIK_H

#include "Gracz.h"

#include <iostream>
#include <string>


using namespace std;

class Wynik {
	Gracz **tabKolejnosc;
	int ileGraczy;
public:
	Wynik(Gracz **tabKolejnosc, int ileGraczy);
	void ustalMiejsca();
	void wypisz();
	friend ostream& operator<< (ostream& os, const Wynik &W);
};

#endif

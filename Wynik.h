#ifndef WYNIK_H
#define WYNIK_H

#include "Gracz.h"

#include <iostream>
#include <string>

using namespace std;

class Wynik {
	Gracz *tabKolejnosc;
public:
	Wynik();
	void ustalMiejsca();
	void ustalPodium();
	void wypisz();
};

#endif

//POTRZEBNA ILOSC PUNKTOW 
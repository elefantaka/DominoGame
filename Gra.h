#ifndef GRA_H
#define GRA_H

#include "LiniaNaStole.h"
#include "StolDoDoboru.h"
#include "Gracz.h"
#include <iostream>
#include <string>

using namespace std;

class Gra {
	PudelkoPionkow pp;
	StolDoDoboru stoldd; //stol do doboru
	Gracz *tabGraczy[28]; //tablica graczy
	LiniaNaStole *linia; //wskaznik do linii na stole, ktora powinna byc tylko jedna
	int ileGraczy; //ilosc graczy
public:
	Gra();
	void rozdajPionki(); //rozdawanie pionkow
	void rozgrywka();  
	void tworzGraczy();
	void wykladaniePionkow();
	void drukuj();
};

#endif

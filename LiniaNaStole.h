#ifndef LiniaNaStole_H
#define LiniaNaStole_H

#include "Pionek.h"

#include <iostream>
#include <string>

using namespace std;

class Element {
	Pionek pion;
	Element *nast; //lista
	friend class LiniaNaStole;
};

class LiniaNaStole {
	Element *glowa;
public:
	LiniaNaStole();
	bool dodajPoLewej(Pionek p);
	bool dodajPoPrawej(Pionek p);
	bool wolnoDodacPoPrawej(Pionek p);
	bool wolnoDodacPoLewej(Pionek p);
	int pokazLewyKoniec();
	int pokazPrawyKoniec();
	bool czyLiniaPusta();
	void drukuj();
};

#endif

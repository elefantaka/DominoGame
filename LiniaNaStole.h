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
	void dodajPoLewej(Pionek p);
	void dodajPoPrawej(Pionek p);
	void drukuj();
};
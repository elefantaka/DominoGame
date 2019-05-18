#ifndef GRACZ_H
#define GRACZ_H

#include "Pionek.h"

#include <iostream>
#include <string>

using namespace std;

class Gracz {
protected:
	Pionek *wlasne;
	int ileWlasnych;
	string imie;
public:
	Gracz();
	~Gracz();
	virtual void wczytajImie(int numerGracza) = 0;
	void drukuj();
	void wezPionek(Pionek p1);
	virtual Pionek ruch() = 0; //virtual - metoda sie zmienia w podklasach
};

class GraczKomputer : public Gracz {  //dziedziczenie
public:
	Pionek ruch();
	void wczytajImie(int numerGracza);
};

class GraczOsoba : public Gracz {
public:
	Pionek ruch();
	void wczytajImie(int numerGracza);
};

#endif
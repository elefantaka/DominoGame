#ifndef GRACZ_H
#define GRACZ_H

#include "Pionek.h"
#include "LiniaNaStole.h"

#include <iostream>
#include <string>

using namespace std;

class Gracz {
protected:
	Pionek *wlasne;
	int ileWlasnych;
	string imie;
	LiniaNaStole *linia; //wskaznik na linie na stole
	bool juzSkonczyl;
	int miejsce;
	void usunPionek(int numer);
public:
	Gracz();
	~Gracz();
	virtual void wczytajImie(int numerGracza) = 0;
	void ustawLinieNaStole(LiniaNaStole *linia);
	void drukuj();
	void drukujMiejsce();
	void wezPionek(Pionek p1);
	void dobierzPionek(Pionek p);
	int getIleWlasnych();
	void setMiejsce(int noweMiejsce);
	int getMiejsce();
	void zakoncz(); //ustawienie juz skonczyl na true
	bool getJuzSkonczyl();
	virtual bool ruch() = 0; //virtual - metoda sie zmienia w podklasach
};

class GraczKomputer : public Gracz {  //dziedziczenie
public:
	bool ruch();
	void wczytajImie(int numerGracza);
};

class GraczOsoba : public Gracz {
public:
	bool ruch();
	void wczytajImie(int numerGracza);
};

#endif
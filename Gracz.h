#ifndef GRACZ_H
#define GRACZ_H

#include "Pionek.h"
#include "LiniaNaStole.h"
#include "Zbior.h"

#include <iostream>
#include <string>

using namespace std;

class Gracz {
protected:
	Pionek *wlasne; //wlasne pionki
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
	string getImie();
	Pionek getPionek(int pionek);
	void zakoncz(); //ustawienie juz skonczyl na true
	bool getJuzSkonczyl();
	virtual bool ruch(Zbior<int> pionkiPrzeciwnika) = 0; //virtual - metoda sie zmienia w podklasach
	Zbior<int>dajMojeNumery();
};

class GraczKomputer : public Gracz {  //dziedziczenie
public:
	bool ruch(Zbior<int> pionkiPrzeciwnika);
	void wczytajImie(int numerGracza);
};

class GraczOsoba : public Gracz {
public:
	bool ruch(Zbior<int> pionkiPrzeciwnika);
	void wczytajImie(int numerGracza);
};

#endif
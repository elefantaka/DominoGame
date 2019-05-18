#include "Gracz.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;  //do cout 

Gracz::Gracz() {
	//cout << "Konstruktor domyslny Gracz: tworzy pusta tablice wlasnych pionkow." << endl;
	wlasne = new Pionek[PudelkoPionkow::N];
	ileWlasnych = 0;
	imie = "NienazwanyGracz";
}

Gracz::~Gracz() {
	//cout << "Destruktor Gracz " << imie << " usuwa tablice wlasnych pionkow" << endl;
	delete[] wlasne;
	wlasne = NULL;
}

void Gracz::drukuj() {
	cout << "Gracz: " << imie << " ";
		if (ileWlasnych == 0) {
			cout << "Gracz nie posiada pionkow";
		}
		else {
			for (int i = 0; i < ileWlasnych; i++) {
				wlasne[i].drukuj();
			}
		}
		cout << endl;
}

void Gracz::wezPionek(Pionek p1) {
	wlasne[ileWlasnych] = p1;
	ileWlasnych++;
}

void GraczOsoba::wczytajImie(int numerGracza) {
	cout << "Podaj imie gracza nr" << numerGracza << endl;
	cin >> imie;
}

RuchGracza GraczOsoba::ruch() {
	int numer;
	cout << "Ruch gracza " << imie << endl;
	cout << "Podaj nr pionka" << endl;
	cin >> numer;
	return wlasne[numer];
}

void GraczKomputer::wczytajImie(int numerGracza) {
	stringstream napis;
	napis << "Komputer" << numerGracza;
	imie = napis.str();
}

Pionek GraczKomputer::ruch() {
	Pionek p(0, 0);
	cout << "Ruch gracza " << imie << endl;
	return p;
}
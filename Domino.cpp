#include <iostream>
#include "Gra.h"
#include <ctime>
#include <cstdlib>

int main() {
	srand(time(NULL));
	cout << "Gra domino." << endl;
	cout << "Autor: Renata Wietrzynska" << endl;
	cout << "Zapraszam do zabawy :)" << endl << endl;

	Pionek p1(7, 3); ///wywolanie konstruktora
	Pionek p2(2, 4);

	PudelkoPionkow pp;
	pp.drukuj();

	GraczKomputer g1;
	g1.drukuj();
	g1.wezPionek(p1);
	g1.wezPionek(p2);
	g1.drukuj();
	g1.ruch();

	Gra  gra1;

	gra1.rozgrywka();

	cout << endl <<"Koniec programu." << endl;
	return 0;
}
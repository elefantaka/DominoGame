#include <iostream>
#include "Gra.h"
#include <ctime>
#include <cstdlib>

int main() {

	srand(time(NULL));

	cout << "Gra domino." << endl;
	cout << "Autor: Renata Wietrzynska" << endl;
	cout << "Zapraszam do zabawy :)" << endl << endl;

	Gra  gra;

	gra.rozgrywka();

	cout << endl <<"Koniec programu." << endl;
	return 0;
}
#include <iostream>
#include "Gra.h"
#include <ctime>
#include <cstdlib>

int main() {

	srand(time(NULL));

	cout << "Gra domino." << endl;
	cout << "Autor: Renata Wietrzynska" << endl;
	cout << "Zapraszam do zabawy :)" << endl << endl;
	
	int koniec = 0;

	while (koniec == 0) {
		Gra  gra;
		gra.rozgrywka();
		cout << "Czy zakonczyc gre 0 - nie, 1 - tak" << endl;
		cin >> koniec;
	}

	cout << endl <<"Koniec programu." << endl;
	return 0;
}



#include "Pionek.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;  //do cout 

Pionek::Pionek(int ap, int bp) {
	//cout << "Konstruktor 2 - arg Pionek: " << "{" << ap << "," << bp << "}" << endl;
	a = ap;
	b = bp;
}

Pionek::Pionek() {
	//cout << "Konstruktor domyslny Pionek." << endl;
	a = -1;
	b = -1;
}

void Pionek::drukuj() {
	cout << "{" << a << "," << b << "}";
}

Pionek::~Pionek() {
	//cout << "Destruktor Pionek: usuwa: " << "{" << a << "," << b << "}" << endl;
}

const int PudelkoPionkow::N = 28;

PudelkoPionkow::PudelkoPionkow() {
	//cout << "Konstruktor domyslny PudelkoPionkow: tworzy tablice pionkow." << endl;
	tab = new Pionek[N];
	int numerPionka = 0;
	for (int b = 0; b <= 6; b++) {
		for (int a = 0; a <= b; a++) {
			Pionek p(a, b);
			tab[numerPionka] = p;
			numerPionka++;
		}
	}
}

void PudelkoPionkow::drukuj() {
	cout << "Pudelko pionkow: ";
		for (int i = 0; i < N; i++) {
			tab[i].drukuj();
		}
		cout << endl;
}

PudelkoPionkow::~PudelkoPionkow() {
	//cout << "Destruktor PudelkoPionkow: usuwa tablice pionkow" << endl;
	delete[] tab; //usun tablice
	tab = NULL;
}

void PudelkoPionkow::mieszaj() {
	for (int i = 0; i < 100; i++) {
		int indeks1, indeks2;
		indeks1 = rand() % N;
		indeks2 = rand() % N;
		Pionek temp = tab[indeks1];
		tab[indeks1] = tab[indeks2];
		tab[indeks2] = temp;
	}
}

Pionek PudelkoPionkow::dajPionek(int indeks) {
	Pionek p;
	p = tab[indeks];
	return p;
}

Pionek *PudelkoPionkow::pokazTablice() {
	return tab;
}

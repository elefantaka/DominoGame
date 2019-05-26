#ifndef PIONEK_H
#define PIONEK_H

class Pionek {
	int a;
	int b;
public:
	Pionek(int ap, int bp); //konstruktor
	void drukuj();
	void odwrocPionka();
	int getA();
	int getB();
	~Pionek(); //destruktor pionka
	Pionek();
};

class PudelkoPionkow {
	Pionek *tab;
public:
	static const int N;
	PudelkoPionkow(); //konstruktor
	~PudelkoPionkow(); //destruktor
	void drukuj();
	void mieszaj(); //jeszcze nie skonczone
	Pionek dajPionek(int indeks);
	Pionek *pokazTablice();
};

#endif


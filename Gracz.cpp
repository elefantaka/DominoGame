#include "Gracz.h"
#include "LiniaNaStole.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;  //do cout 

Gracz::Gracz() {
	//cout << "Konstruktor domyslny Gracz: tworzy pusta tablice wlasnych pionkow." << endl;
	wlasne = new Pionek[PudelkoPionkow::N];
	ileWlasnych = 0;
	imie = "NienazwanyGracz";
	juzSkonczyl = false;
	miejsce = -1;
}

Gracz::~Gracz() {
	//cout << "Destruktor Gracz " << imie << " usuwa tablice wlasnych pionkow" << endl;
	delete[] wlasne;
	wlasne = NULL;
}

void Gracz::drukuj() {
	cout << "Gracz " << imie;
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

void Gracz::drukujMiejsce() {
	cout << "Gracz " << imie << "miejsce " << miejsce << ": ";
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

int Gracz::getIleWlasnych() {
	return ileWlasnych;
}

void Gracz::setMiejsce(int noweMiejsce) {
	miejsce = noweMiejsce;
}

string Gracz::getImie() {
	return imie;
}

Pionek Gracz::getPionek(int pionek) {
	return *wlasne;
}

void Gracz::zakoncz() {
	juzSkonczyl = true;
}

void Gracz::wezPionek(Pionek p1) {
	wlasne[ileWlasnych] = p1;
	ileWlasnych++;
}

bool Gracz::getJuzSkonczyl() {
	return juzSkonczyl;
}

int Gracz::getMiejsce() {
	return miejsce;
}

void GraczOsoba::wczytajImie(int numerGracza) {
	cout << "Podaj imie gracza nr " << numerGracza << endl;
	cin >> imie;
}

void Gracz::usunPionek(int numer) {
	for (int i = numer + 1; i < ileWlasnych; i++) {
		wlasne[i - 1] = wlasne[i];
	}
	ileWlasnych--;
}

void Gracz::ustawLinieNaStole(LiniaNaStole *linia2) {
	this->linia = linia2; //ustawiamy linie, zapamietujemy wskaznik do tej linii
}

bool GraczOsoba::ruch(Zbior<int> pionkiPrzeciwnika) {
	int numer;
	cout << "Ruch gracza " << imie << endl;
	cout << "Podaj nr pionka" << endl;
	cin >> numer;
	if (numer < 0 || numer >= ileWlasnych) {
		cout << "Tracisz kolejke (nie ma takiego pionka)" << endl;
		return false;
	}
	int czyOdwrocic;
	cout << "Czy odwrocic pionka? 0 - nie, 1 - tak" << endl;
	cin >> czyOdwrocic;
	if (czyOdwrocic == 1) {
		wlasne[numer].odwrocPionka();
	}
	int lewoPrawo;
	cout << "Czy dodac po lewej - 0, czy po prawej - 1" << endl;
	cin >> lewoPrawo;
	if (lewoPrawo == 0) {
		bool czyDodal = linia->dodajPoLewej(wlasne[numer]);
		if (czyDodal == false) {
			cout << "Tracisz kolejke" << endl;
			return false;
		}
	}
	else if (lewoPrawo == 1) {
		bool czyDodal = linia->dodajPoPrawej(wlasne[numer]);
		if (czyDodal == false) {
			cout << "Tracisz kolejke" << endl;
			return false;
		}
	}
	else {
		cout << "Tracisz kolejke" << endl;
		return false;
	}
	usunPionek(numer);
	return true;
}

void GraczKomputer::wczytajImie(int numerGracza) {
	stringstream napis;
	napis << "Komputer" << numerGracza;
	imie = napis.str();
}

bool GraczKomputer::ruch(Zbior<int> pionkiPrzeciwnika) {
	cout << "Ruch gracza " << imie << endl;
	if (ileWlasnych == 0) {
		cout << "Gracz juz wygral" << endl;
		return true;
	}
	if (linia->czyLiniaPusta()) {
		linia->dodajPoLewej(wlasne[0]);
		usunPionek(0);
		return true;
	}
	int lewyKoniec = linia->pokazLewyKoniec();
	int prawyKoniec = linia->pokazPrawyKoniec();
	//szuka lepszego pionka przy uzyciu zbioru czyli szablonu
	for (int i = 0; i < ileWlasnych; i++) {
		Pionek p = wlasne[i];
		if (lewyKoniec == p.getA()) {
			if (pionkiPrzeciwnika.czyNalezy(p.getB()) == false) {
				p.odwrocPionka();
				linia->dodajPoLewej(p);
				usunPionek(i);
				return true;
			}
		}
		if (lewyKoniec == p.getB()) {
			if (pionkiPrzeciwnika.czyNalezy(p.getA()) == false) {
				linia->dodajPoLewej(p);
				usunPionek(i);
				return true;
			}
		}
		if (prawyKoniec == p.getA()) {
			if (pionkiPrzeciwnika.czyNalezy(p.getB()) == false) {
				linia->dodajPoPrawej(p);
				usunPionek(i);
				return true;
			}
		}
		if (prawyKoniec == p.getB()) {
			if (pionkiPrzeciwnika.czyNalezy(p.getA()) == false) {
				p.odwrocPionka();
				linia->dodajPoPrawej(p);
				usunPionek(i);
				return true;
			}
		}
	}
	for (int i = 0; i < ileWlasnych; i++) {
		Pionek p = wlasne[i];
		if (lewyKoniec == p.getA()) {
			p.odwrocPionka();
			linia->dodajPoLewej(p);
			usunPionek(i);
			return true;
		}
		if (lewyKoniec == p.getB()) {
			linia->dodajPoLewej(p);
			usunPionek(i);
			return true;
		}
		if (prawyKoniec == p.getA()) {
			linia->dodajPoPrawej(p);
			usunPionek(i);
			return true;
		}
		if (prawyKoniec == p.getB()) {
			p.odwrocPionka();
			linia->dodajPoPrawej(p);
			usunPionek(i);
			return true;
		}
	}
	cout << "Tracisz kolejke" << endl;
	return false;
}

void Gracz::dobierzPionek(Pionek p) {
	wlasne[ileWlasnych] = p;
	ileWlasnych++;
}

Zbior<int> Gracz::dajMojeNumery() {
	Zbior<int> wynikZbioru(7);
	for (int i = 0; i < ileWlasnych; i++) {
		wynikZbioru.dodaj(wlasne[i].getA());
		wynikZbioru.dodaj(wlasne[i].getB());
	}
	return wynikZbioru;
}
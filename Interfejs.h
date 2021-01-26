#pragma once
#include <iostream>
#include "Baza.h"

using namespace std;
class Interfejs {
public:
	Interfejs() : b (Baza()) , stan(true) {}
	bool get_stan() { return stan; }
	void polecenie()
	{
		string p;
		cin >> p;
		if (p == "drukuj")
		{
			b.drukuj();
		}
		else if (p == "dodaj")
		{
			dodaj_pojazd();
		}
		else if (p == "usun")
		{
			usun_pojazd();
		}
		else if (p == "wyczysc")
		{
			wyczysc();
		}
		else if (p == "zapisz")
		{
			zapisz();
		}
		else if (p == "wczytaj")
		{
			odczytaj();
		}
		else if (p == "zamknij")
		{
			stan=false;
		}
		else
			cout << "Nieznana komenda"<<'\n';
	}
	void dodaj_pojazd() {	
		string t1;
		string  re1, ma1, mo1;
		double p1;
		cout << "Jaki pojazd chcialbys dodac do bazy:" << '\n' << "Osobowy, Motocykl, Ciezarowka ?"<<'\n';
		cin >> t1;
		cout << "Podaj numer rejestracyjny pojazdu:" << '\n';
		cin >> re1;
		cout << "Podaj marke pojazdu:" << '\n';
		cin >> ma1;
		cout << "Podaj model pojazdu:" << '\n';
		cin >> mo1;
		cout << "Podaj pojemnosc silnika pojazdu:" << '\n';
		cin >> p1;
		b.dodaj(t1, re1, ma1, mo1, p1);
}
	void usun_pojazd() {
		string pd;
		cout << "Jaki typ pojazdu  chcesz usunac:" << '\n' << "Osobowy, Motocykl, Ciezarowka ?" << '\n';
		cin >> pd;
		string rej2;
		cout << "Podaj numer rejestracyjny pojazdu ktory chcesz usunac:" << '\n';
		cin >> rej2;
		b.usun(rej2,pd);
	}
	void zapisz() {
		string nazwa;
		cout << "Podaj nazwe pliku binarnego do ktorego chcesz zapisac baze (pamietaj o rozszerzeniu):" << '\n';
		cin >> nazwa;
		b.zapis(nazwa);
	}
	void odczytaj() {
		string nazwa;
		cout << "Podaj nazwe pliku binarnego z ktorego chcesz odczytaæ baze (pamietaj o rozszerzeniu):" << '\n';
		cin >> nazwa;
		b.odczyt(nazwa);
	}
	void wyczysc() {
		char d;
		cout << "Czy na pewno chcesz usunac baze? t/n" << '\n';
		cin >> d;
		if (d == 't') {
			b.czysc();
		}			
	}
private:
	Baza  b;
	bool stan;
};
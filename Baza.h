#pragma once
#include "Pojazdy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
class Baza
{
public:
Baza() {
	l_o = 0; l_m = 0; l_c = 0;
}
void dodaj(string t , string r , string mar ,string mod,double V) {
	bool s = false;
	for_each(lista_p.begin(), lista_p.end(), [&](auto& it) { if (it->get_rej() != r) s = true; });
	if (s) {
		if (t == "Osobowy") {
			unique_ptr< Pojazd > p = make_unique< Osobowy >(r, mar, mod, V);
			lista_p.emplace_back(move(p));
			l_o++;
		}
		else if (t == "Motocykl") {
			unique_ptr< Pojazd > p = make_unique< Motocykl >(r, mar, mod, V);
			lista_p.emplace_back(move(p));
			l_m++;
		}
		else if (t == "Ciezarowka") {
			unique_ptr< Pojazd > p = make_unique< Ciezarowka >(r, mar, mod, V);
			lista_p.emplace_back(move(p));
			l_c++;
		}
		else {
			cout << "BLAD" << '\n';
		}
	}else cout << "Podany numer rejestracyjny jest juz w bazie" << '\n';
}
void usun(string r ,string pd) {
	bool s=false;
	for_each(lista_p.begin(), lista_p.end(), [&](auto& it) { if (it->get_rej() == r) s = true; });
	if (s) {
		auto u = find_if(lista_p.begin(), lista_p.end(), [&](auto& it) {
			return (it->get_rej() == r); });
		if (pd == "Osobowy")
		{
			l_o--;
		}
		else if (pd == "Motocykl") {
			l_m--;
		}
		else if (pd == "Ciezarowka") {
			l_c--;
		}
		lista_p.erase(u);
	}
	else
			cout << "Nie ma pojazdu o takim numerze rejestracyjnym w bazie" << '\n';
}
const void drukuj() {
	if (l_c == 0 && l_m == 0 && l_o == 0) {
		cout<<"Baza pojazdow jest pusta " << '\n';
	}
	else {

		cout << "Baza pojazdow: " << '\n';
		for_each(lista_p.begin(), lista_p.end(), [](auto& it) { it->print(); });
		cout << "W bazie jest:" << '\n';
		cout << l_o << " samochodow osobowych" << '\n';
		cout << l_m << " motocykli" << '\n';
		cout << l_c << " samochodow ciezarowych" << '\n';
	}
};
void czysc() {
	lista_p.clear();
	l_o = 0; l_m = 0; l_c = 0;
}
void zapis(string nazwa) {
	fstream plik;
	plik.open(nazwa, ios::out | ios::binary);	
	if (plik.is_open()) {		
		for_each(lista_p.begin(), lista_p.end(), [&](auto& it) {
			string t= it->get_typ(), re= it->get_rej(), ma= it->get_marka(), mo= it->get_model();
			double V = it->get_poj();
			plik.write(t.c_str(), t.size()+1);
			plik.write(re.c_str(), re.size()+1);
			plik.write(ma.c_str(), ma.size()+1);
			plik.write(mo.c_str(), mo.size()+1);
			plik.write((const char*) &V, sizeof V);			
			});
		plik.close();		
	}
	else {
		cout << "Nie uda³o siê otworzyæ pliku" << '\n';
	}
};
void odczyt(string nazwa) {
	fstream plik;
	plik.open(nazwa, ios::in | ios::binary);
	if (plik.is_open()) {
		do {
			string t, re, ma, mo;
			double po;
			getline(plik,t,'\0');
			getline(plik, re, '\0');
			getline(plik, ma, '\0');
			getline(plik, mo, '\0');
			plik.read((char*)&po, sizeof po);
			if (t == "Osobowy") {
				unique_ptr< Pojazd > p = make_unique< Osobowy >(re, ma, mo, po);
				lista_p.emplace_back(move(p));
				l_o++;
			}
			else if (t == "Motocykl") {
				unique_ptr< Pojazd > p = make_unique< Motocykl >(re, ma, mo, po);
				lista_p.emplace_back(move(p));
				l_m++;
			}
			else if (t == "Ciezarowy") {
				unique_ptr< Pojazd > p = make_unique< Ciezarowka >(re, ma, mo, po);
				lista_p.emplace_back(move(p));
				l_c++;
			}			
			
		} while (!plik.eof());
		plik.close();
		cout << "Wczytano baze pojazdow" << '\n';
		drukuj();
	}
	else {
		cout << "Nie uda³o siê otworzyæ pliku" << '\n';
	}
};
private:
list< unique_ptr<Pojazd>> lista_p;
int l_o, l_m, l_c;
};
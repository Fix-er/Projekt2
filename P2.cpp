// P2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "Interfejs.h"

int main()
{ 
    cout << "Baza Pojazdow" << '\n'<<"Polecenia:"<<'\n'
        << "dodaj" << '\n'
        << "usun" << '\n'
        << "drukuj" << '\n'
        << "wyczysc" << '\n'
        << "zapisz" << '\n'
        << "wczytaj" << '\n'
        << "zamknij" << '\n';
    Interfejs i;
    while (i.get_stan())
    {
        cout << "Polecenie:" << '\n';
        i.polecenie();
    }
        
    return 0;
}


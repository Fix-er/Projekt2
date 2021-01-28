// P2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "Interfejs.h"

int main()
{ 
    const char* wstep = "Baza Pojazdow\nPolecenia:\ndodaj\nusun\ndrukuj\nwyczysc\nzapisz\nwczytaj\nzamknij\n";
    cout << wstep;
    Interfejs i;
    while (i.get_stan())
    {
        cout << "Polecenie:" << '\n';
        i.polecenie();
    }
        
    return 0;
}


#include <iostream>
#include <locale.h>

#include "test.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    for(;;)
    {
        cout<<"KONSOLOWNIK v01 (12.06.19) by Micha� Szubi�ski\n";
        cout<<"Wersja v01 posiada:\n\n- Kompatybilno�� z podstawowym formatem bazy pyta� testownika z PWr,\n- Przyjmowanie pyta� z maksymalnie 10 odpowiedziami abcd(efghij),\n";
        cout<<"- Mo�liwo�� wielu odpowiedzi w pytaniu lub �adnej,\n- Statystyki dotyczace aktualnego testu,\n- Uruchamianiu wielu baz pyta�,\n- Mieszanie odpowiedzi,\n- Polskie znaki.\n";
        cout<<"\n�eby uruchomi� baz� pyta� wystarczy wklei� folder bazy pyta� do folderu z konsolownikiem, a nastepni� wpisa� jego nazw�!\n\n\n";
        Test t;
    }


    return 0;
}

#include <iostream>
#include <locale.h>

#include "test.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    for(;;)
    {
        cout<<"KONSOLOWNIK v01 (12.06.19) by Michał Szubiński\n";
        cout<<"Wersja v01 posiada:\n\n- Kompatybilność z podstawowym formatem bazy pytań testownika z PWr,\n- Przyjmowanie pytań z maksymalnie 10 odpowiedziami abcd(efghij),\n";
        cout<<"- Możliwość wielu odpowiedzi w pytaniu lub żadnej,\n- Statystyki dotyczace aktualnego testu,\n- Uruchamianiu wielu baz pytań,\n- Mieszanie odpowiedzi,\n- Polskie znaki.\n";
        cout<<"\nŻeby uruchomić bazę pytań wystarczy wkleić folder bazy pytań do folderu z konsolownikiem, a nastepnię wpisać jego nazwę!\n\n\n";

        Test t;
    }


    return 0;
}

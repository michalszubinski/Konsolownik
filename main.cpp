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
        cout<<"Wersja v01 posiada:\n\n";
        cout<<"- Kompatybilność z podstawowym formatem bazy pytań testownika z PWr,\n";
        cout<<"- Przyjmowanie pytań z maksymalnie 10 odpowiedziami abcd(efghij),\n";
        cout<<"- Możliwość wielu odpowiedzi w pytaniu lub żadnej,\n";
        cout<<"- Statystyki dotyczące aktualnego testu,\n";
        cout<<"- Uruchamianiu wielu baz pytań,\n";
        cout<<"- Mieszanie odpowiedzi,\n";
        cout<<"- Polskie znaki.\n\n";

        Test t;
    }


    return 0;
}

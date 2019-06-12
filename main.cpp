#include <iostream>
#include <locale.h>

#include "test.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    for(;;)
    {
        cout<<"KONSOLOWNIK v01 (12.06.19) by Micha³ Szubiñski\n";
        cout<<"Wersja v01 posiada:\n\n- Kompatybilnoœæ z podstawowym formatem bazy pytañ testownika z PWr,\n- Przyjmowanie pytañ z maksymalnie 10 odpowiedziami abcd(efghij),\n";
        cout<<"- Mo¿liwoœæ wielu odpowiedzi w pytaniu lub ¿adnej,\n- Statystyki dotyczace aktualnego testu,\n- Uruchamianiu wielu baz pytañ,\n- Mieszanie odpowiedzi,\n- Polskie znaki.\n";
        cout<<"\n¯eby uruchomiæ bazê pytañ wystarczy wkleiæ folder bazy pytañ do folderu z konsolownikiem, a nastepniê wpisaæ jego nazwê!\n\n\n";
        Test t;
    }


    return 0;
}

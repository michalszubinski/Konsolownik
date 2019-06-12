#include <iostream>

#include "answer.h"
#include <string>

using namespace std;

Answer::Answer()
{
    this -> text = "";
    this -> value = 0;
}

void Answer::settext(string txt) // ustawia tekst pytania
{
    this -> text = txt;
}

string Answer::gettext()
{
    return text;
}

void Answer::print() // wyswietla pytanie
{
    cout<<text<<endl;
}

void Answer::correct()// ustawia wartosc value na true
{
    this -> value = 1;
}

bool Answer::check() // sprawdza odpowiedz dla pytania
{
    return value;
}

bool Answer::getvalue()
{
    return value;
}

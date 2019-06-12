#ifndef ANSWER_H_INCLUDED
#define ANSWER_H_INCLUDED

#include <string>

using namespace std;

class Answer
{
private:
    string text;
    bool value;

public:

    Answer();
    void settext(string txt); // ustawia tekst pytania
    string gettext();
    void print(); // wyswietla pytanie
    void correct(); // ustawia wartosc value na true
    bool check(); // sprawdza odpowiedz dla pytania
    bool getvalue();
};


#endif // ANSWER_H_INCLUDED

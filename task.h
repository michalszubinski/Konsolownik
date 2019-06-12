#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include <vector>
#include "answer.h"

using namespace std;

class Task
{
private:
    char value; // 0 najgorsze // 6 najlepsze
    char view; // ile razy zostalo wyswietlone
    string header; // naglowek
    string question; // pytanie
    string file; // lokalizacja pliku z pytaniami
    vector<Answer> answers; // odpowiedzi
    int ans_num; // ile jest odpowiedzi
    bool done; // czy wyswietlac pytanie
    bool good; // czy pytanie nadaje sie do uzycia
    bool lastresponse; // czy ostatnia odpowiedz byla prawidlowa
    bool randomize; // czy zmieniac miejsca
    vector<int> org; // oryginalne miejsca w wektorze answers
    vector<char> userin; // user input
    bool dopreprint;

public:
    Task();
    //~Task();
    void loadquestion(string filename);
    void setvalue(char i);
    void addvalue(char i);
    char getvalue();
    string getheader();
    string getquestion();
    string getanswer(int i);
    void setdone();
    bool getgood();
    void print();
    void setlastresponse(bool i);
    bool getlastresponse();
    void setrandomize(bool i);
    bool check(bool updatepreprint=1);
    void setuserin(vector<char> newuserin);
    int getans_num();
    bool getanswervalue(int i);
    void preprint();
};

#endif // TASK_H_INCLUDED

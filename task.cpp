#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "answer.h"
#include "task.h"

using namespace std;

Task::Task()
{
    value = 3;
    view = 0;
    done = 0;
    good = 1;
    randomize = 1;
    ans_num=0;
    dopreprint=1;
}

//~Task()
void Task::loadquestion(string filename)
{
    fstream plik1;

    plik1.open(filename.c_str(), ios::in);

    if(!plik1.good())
    {
        cout<<"Nie udalo sie otworzyc pliku "<<filename<<" !\n";
    }
    else
    {
        this -> file = filename;
        int i=0;
        string linia;

        while (getline(plik1, linia))
        {
            if(!good) break;

            if(!i)
            {
                header = linia;
                ans_num = header.length() - 1;
                if(!(ans_num>0))
                {
                    cout<<"Blad przy wczytywaniu "<<filename<<" !\n";
                    good = 0;
                }
            }
            else if(i==1) question = linia;
            else
            {
                Answer ans;

                if(header[i-1]=='1') ans.correct();
                ans.settext(linia);

                answers.push_back(ans);
            }

            i++;
        }
    }

    plik1.close();
}

void Task::setvalue(char i)
{
    value = i;
}
void Task::addvalue(char i)
{
    value += i;

    if(value<0) value = 0;

    if(value>6) value = 6;

}
char Task::getvalue()
{
    return value;
}

string Task::getheader()
{
    return header;
}
string Task::getquestion()
{
    return question;
}
string Task::getanswer(int i)
{
    if(i<0||i>ans_num)
    {
        string x="error";
        cout<<"Bledny numer pytania dla "<<file<<" !\n";
        return x;
    }
    else
    {
        return answers[i].gettext();
    }
}

void Task::setdone()
{
    done = 1;
}

bool Task::getgood()
{
    return good;
}

void Task::print()
{
    printf("Filename: %s\n\n%s\n",file.c_str(),question.c_str());

    if(good)
    {
        char x='a';
        /*for(int i=0; i<ans_num;i++)
        {
            printf("%c. %s\n",x, answers[i].gettext().c_str());
        }*/

        if(dopreprint) preprint();

        int ileuserinbylo=0;

        for(int i=0; i<ans_num;i++)
        {

            /*if(ileuserinbylo<userin.size())
            {
                if(userin[org[i]]==x) {cout<<"* "; ileuserinbylo++;}
            }*/

            printf("%c. %s\n",x, answers[org[i]].gettext().c_str());
            x++;
        }
    }
}

void Task::setlastresponse(bool i)
{
    lastresponse = i;
}

bool Task::getlastresponse()
{
    return lastresponse;
}

void Task::setrandomize(bool i)
{
    randomize = i;
}

bool Task::check(bool updatepreprint)
{
    vector<bool> G00;
    int actt;
    bool act;

    for(unsigned int i = 0; i < userin.size(); i++)
    {
        actt = userin[0] - 'a';

        act = answers[org[actt]].check();
        G00.push_back(act);
    }

    bool checker=1;

    for(unsigned int i = 0; i < G00.size(); i++)
    {
        if(G00[i]==0) {checker = 0; break;}
    }

    if(userin.size()==0)
    {
        for(int i=1; i<header.length(); i++)
        {
            if(header[i]=='1') return 0;
        }
    }

    unsigned int ilepop=0;

    for(unsigned int i = 0; i < answers.size(); i++)
    {
        if(answers[i].check()) ilepop++;
    }

    if(updatepreprint) dopreprint = 1;

    if(ilepop!=userin.size()) return 0;

    return checker;
}

void Task::setuserin(vector<char> newuserin)
{
    userin = newuserin;
}

int Task::getans_num()
{
    return ans_num;
}

bool Task::getanswervalue(int i)
{
    if(i<0||i>ans_num)
    {
        bool x = 0;
        cout<<"Bledna wartosc odpowiedzi dla "<<file<<" !\n";
        return x;
    }
    else
    {
        return answers[i].getvalue();
    }
}

void Task::preprint()
{
    for(unsigned int i = 0; i<org.size(); i++)
        org.pop_back();

    if(!randomize)
    {
        for(int i=0; i<ans_num;i++)
        {
            org.push_back(i);
        }
    }
    else
    {
        bool catc=1;
        for(int i=0; i<ans_num;i++)
        {
            org.push_back(rand() % ans_num);

            catc = 1;

            while(catc)
            {
                catc = 0;

                for(int j=0; j<i;j++)
                {
                    if(org[i]==org[j]&&i!=j) catc = 1;
                }

                if(catc) org[i] = rand() % ans_num;
            }

            catc = 0;
        }
    }

    this -> dopreprint = 0;
}


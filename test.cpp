#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <io.h>
#include <dirent.h>

#include "test.h"


using namespace std;

Test::Test()
{
    srand( time( NULL ) );

    string x;
    bool End=0;

    for(;;)
    {
        cout<<"Podaj nazwę folderu z którego wczytać bazę pytań:\n";
        cin>>x;

        string loc = "\\"+x;
        cout<<loc<<endl;

        if(load(loc)) { Sleep(50);main(); End=1;}
        else
        {
            cout<<"\nBLAD! Sprobuj ponownie! Brak bazy pytan "<<x<<" !\n"<<endl;
        }

        if(End) break;
    }
}
bool Test::load(string loc)
{
    //POBIERANIE SCIEZKI
    char cCurrentPath[FILENAME_MAX];

    if (!_getcwd(cCurrentPath, sizeof(cCurrentPath)))
         {
         return errno;
         }

    cCurrentPath[sizeof(cCurrentPath) - 1] = '/0'; /* not really required */

    printf ("Adres programu: %s\n\n", cCurrentPath);
    //KONIEC POBIERANIA SCIEZKI

    //USTAWIANIE LOKALIZACJI BAZY
    string currentdir = cCurrentPath + loc;

    cout<<endl<<endl<<currentdir<<endl<<endl;


    //ZLICZANIE LICZBY PLIKOW W BAZIE
    DIR *dir;
    struct dirent *ent;

    int ileplikow=-1;
    //vector<string> listaplikow;

    if ((dir = opendir (currentdir.c_str())) != NULL)
    {
          /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            if(ileplikow<=0) ileplikow++;
            else
            {
                string name = ent->d_name;
                string actloc = loc+"\\"+name;
                actloc.erase(actloc.begin());

                if(name.length()>=4)
                {
                    if(name[name.length()-4]=='.'&&name[name.length()-3]=='t'&&name[name.length()-2]=='x'&&name[name.length()-1]=='t') // jesli koncowka to .txt
                    {
                        fstream plik;
                        string napis;

                        plik.open(actloc.c_str(), ios::in);
                        if( plik.good() == true )
                        {

                            getline(plik, napis);
                            if(napis[0]='X')
                            {
                                Task task;

                                task.loadquestion(actloc);
                                //task.print();

                                tasks.push_back(task);
                                ileplikow++;
                            }
                            plik.close();
                        }
                    }
                }
            }
            printf ("%s - plik nr. %d\n", ent->d_name,ileplikow);
        }

        closedir (dir);
    }
    else
    {
        /* could not open directory */
        perror ("");
        return 0;
    }
    //KONIEC ZLICZANIA

    ileplikow--;

    MAX_TASKS = ileplikow;

    if(ileplikow>0) {this -> location = loc; return 1;}

    return 0;
}

void Test::save()
{

}
void Test::main()
{

    bool send=0;
    bool changed=1;

    for(;;)
    {
        if(!tasks.size()) break;

        choose();
        send = 0;

        while(!send)
        {
            if(changed)
            {
                changed = 0;
                system("cls");
                tasks[actask].setuserin(userin);
                print();

                cout<<endl<<"Zaznaczone odpowiedzi:\n";
                for(int i=0; i<userin.size(); i++)
                {
                    cout<<userin[i]<<endl;
                }
                cout<<endl;
            }

            keys(&send,&changed);
        }

        system("cls");
        tasks[actask].setuserin(userin);
        print();
        if(tasks[actask].check())
        {
            if(tasks[actask].getlastresponse()) tasks[actask].addvalue(1);
            tasks[actask].setlastresponse(1);
            tasks[actask].addvalue(1);
            cout<<"DOBRA ODPOWIEDZ!\n";
            if(tasks[actask].getvalue()==6) /*MAX VALUE*/
            {
                tasks.erase(tasks.begin()+actask);
                cout<<"Pytanie ZALICZONE!\n";
            }

        }
        else
        {
            bool czyjakaspoprawna=0;

            tasks[actask].setlastresponse(0);
            tasks[actask].addvalue(-1);
            cout<<"!!! ZLA ODPOWIEDZ!\n\n";
            cout<<"Poprawna odpowiedz to: \n\n";
            for(int i=0; i<tasks[actask].getans_num();i++)
            {
                if(tasks[actask].getanswervalue(i))
                {
                    cout<<"- "<<tasks[actask].getanswer(i)<<endl<<endl;
                    czyjakaspoprawna=1;
                }

            }
            if(!czyjakaspoprawna) cout<<"- Brak poprawnej odpowiedzi!\n\n";
            cout<<"\n\n\n\n";
            system("pause");
        }

        Sleep(500);

        while(userin.size()>0)
        {
            userin.pop_back();
        }

        changed = 1;

        if(tasks.size()<=0) break;
    }

    cout<<"KONIEC TESTU!\n\n\n";
    Sleep(3000);
    system("pause");
    system("cls");
}

void Test::choose()
{
    int prevtask = actask;

    actask = rand() % tasks.size();

    while(actask==prevtask&&tasks.size()>1) actask = rand() % tasks.size();
}

void Test::print()
{
    tasks[actask].print();
    int zaliczonych = MAX_TASKS - tasks.size();
    float procent = (float)zaliczonych * 100.0f / (float)MAX_TASKS;
    printf("\nZaliczonych pytan: %d/%d (%f%c)\n",zaliczonych,MAX_TASKS,procent,37);
}

void Test::key(char c, bool *changed)
{
    if((unsigned int)(c - 'a')<tasks[actask].getans_num())
    {
        /*cout<<"KEY HAS BEEN PRESSED\n";
        system("pause");*/
        Sleep(70);
        *changed = true;
        bool czyjuztenbyl=0;
        int ktorybyl=0;

        for(unsigned int i = 0; i<userin.size(); i++)
        {
            if(c==userin[i]) {czyjuztenbyl=1; ktorybyl=i; }
        }

        if(czyjuztenbyl)
        {
            userin.erase(userin.begin()+ktorybyl);
        }
        else
        {
            userin.push_back(c);
        }
    }
}

void Test::keys(bool *send, bool *changed)
{
        if(GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            *send = 1;
        }
        if(GetAsyncKeyState(0x41) & 0x8000)
        {
            key('a',changed);
        }
        if(GetAsyncKeyState(0x42) & 0x8000)
        {
            key('b',changed);
        }
        if(GetAsyncKeyState(0x43) & 0x8000)
        {
            key('c',changed);
        }
        if(GetAsyncKeyState(0x44) & 0x8000)
        {
            key('d',changed);
        }
        if(GetAsyncKeyState(0x45) & 0x8000)
        {
            key('e',changed);
        }
        if(GetAsyncKeyState(0x46) & 0x8000)
        {
            key('f',changed);
        }
        if(GetAsyncKeyState(0x47) & 0x8000)
        {
            key('g',changed);
        }
        if(GetAsyncKeyState(0x48) & 0x8000)
        {
            key('h',changed);
        }
        if(GetAsyncKeyState(0x49) & 0x8000)
        {
            key('i',changed);
        }
        if(GetAsyncKeyState(0x4A) & 0x8000)
        {
            key('j',changed);
        }
}

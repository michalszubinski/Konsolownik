#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "task.h"

class Test
{
private:
    vector<Task> tasks;
    vector<char> userin;
    int MAX_TASKS;
    string location;
    int actask;


public:

    Test();
    bool load(string loc);
    void save();
    void main();
    void choose();
    void print();
    void key(char c, bool *changed);
    void keys(bool *send, bool *changed);
};


#endif // TEST_H_INCLUDED

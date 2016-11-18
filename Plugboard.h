

#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>






using namespace std;


class Plugboard{

public:
    //constructors
Plugboard();


char plugboard_convert(char input);
int Plugboard_load(const char* filename);

private:


int pbarray[26];
int counter=0;

};

#endif

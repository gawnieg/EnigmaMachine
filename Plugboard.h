

#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>






using namespace std;


class Plugboard{

public:
    //constructors
Plugboard(const char* filename);




private:

char plugboard_convert(char input);
int pbarray[26];
int counter=0;

};

#endif

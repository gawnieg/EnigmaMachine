

#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>






using namespace std;


class Plugboard{

public:

    Plugboard();
    char plugboard_convert(char input);// to carry out mapping
    int Plugboard_load(const char* filename);//to load and error check

private:


    int pbarray[26];// to store mapping array
    int counter=0;// for indexing mapping array

};

#endif

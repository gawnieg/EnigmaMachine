
#ifndef REFLECTOR_H
#define REFLECTOR_H


#include <iostream>



using namespace std;


class Reflector{

public:

    Reflector();
    char reflect(char input_char); // to carry out mapping
    int Reflector_load(const char* filename); //to load and error check


private:

    int rfarray[26]; // to store mapping array
    int counter=0;// for indexing mapping array

};

#endif

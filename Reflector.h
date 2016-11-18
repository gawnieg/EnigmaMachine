
#ifndef REFLECTOR_H
#define REFLECTOR_H


#include <iostream>



using namespace std;


class Reflector{

public:
    //constructors
    Reflector();
char reflect(char input_char);
int Reflector_load(const char* filename);


private:

int rfarray[26];//putting here and not in public


};

#endif

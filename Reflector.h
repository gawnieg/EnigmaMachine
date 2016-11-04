
#ifndef REFLECTOR_H
#define REFLECTOR_H


#include <iostream>
#include "Plugboard.h"
#include "Enigma.h"
#include "Rotor.h"


using namespace std;


class Reflector{

public:
    //constructors
    Reflector(const char* filename);
	char reflect(char input_char);
	


private:

int rfarray[26];//putting here and not in public

};

#endif

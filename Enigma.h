#ifndef ENIGMA_H
#define ENIGMA_H


#include <iostream>


#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"


using namespace std;


class Enigma{

public:
    //constructors
    Enigma(Plugboard* plugboard, Reflector* reflector, Rotor* rotorarray[5], int numberofrotors);


	Plugboard* plugboard;
	Reflector* reflector;
	Rotor* rotorarray[5];


    char encode(char input_char_to_be_encrypted);



private:
signed int rotor_index_enigma =0;



};

#endif

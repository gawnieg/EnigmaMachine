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
    Enigma(Plugboard* plugboard, Reflector* reflector, Rotor* rotorarray[2], int numberofrotors);
	char one_way(char input_char);

	Plugboard* plugboard;
	Reflector* reflector;
	Rotor* rotorarray[5];

    void one_turn();
    char encode(char input_char_to_be_encrypted);



private:
int rotorindex =0;



};

#endif

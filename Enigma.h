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
	Rotor* rotorarray[2];
	int rotorindex;


private:




};

#endif

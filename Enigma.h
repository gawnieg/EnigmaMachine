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
    int rotor_index_enigma =0;
	int number_of_rotors_enigma;

	Plugboard* plugboard;
	Reflector* reflector;
	Rotor* rotorarray[5]; // was 5

    int number_rot_comp[5]={0,0,0,0,0};



private:




};

#endif

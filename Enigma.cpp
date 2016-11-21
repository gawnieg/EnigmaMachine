#include"Enigma.h"
#include<iostream>
#include<fstream>
#include <cstring>
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"


Enigma::Enigma(Plugboard* _plugboard, Reflector* _reflector, Rotor* _rotorarray[],\
     int _numberofrotors ){
//constructor for enigma

    plugboard = _plugboard;
    reflector = _reflector;
    number_of_rotors_enigma= _numberofrotors;

    for(int i=0;i<=number_of_rotors_enigma; i++){
		rotorarray[i]=_rotorarray[i];
	}
}

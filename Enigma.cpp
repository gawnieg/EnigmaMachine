#include"Enigma.h"
#include<iostream>
#include<fstream>
#include <cstring>
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

// #define COMMENTS_ON
#define STEP_COMMENTS_ON


Enigma::Enigma(Plugboard* _plugboard, Reflector* _reflector, Rotor* _rotorarray[], int _numberofrotors ){
//constructor for enigma

    plugboard = _plugboard;
    reflector = _reflector;
    rotor_index_enigma = _numberofrotors -1; //minus one so can be used directly as an index
    #ifdef COMMENTS_ON
    cout << " _numberofrotors is " << _numberofrotors << endl; //debugging
    cout << "Rotor index" << rotor_index_enigma <<endl;
    cout << " rotorindex is " << rotor_index_enigma << endl;
    #endif



	/*
        for(int i=0; i <5; i++){ // up to 5 rotor members
            rotorarray[i] = _rotorarray[i]; //THIS LINE IS PROBLEMATIC, what am i trying to do here?
        }
	*/
	

    number_of_rotors_enigma= _numberofrotors;
	
		for(int i=0;i<=number_of_rotors_enigma; i++){
			rotorarray[i]=_rotorarray[i];
	}




}



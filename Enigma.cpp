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
    cout << " _numberofrotors is " << _numberofrotors << endl; //debugging
    cout << "Rotor index" << rotor_index_enigma <<endl;

    rotor_index_enigma = _numberofrotors -1; //minus one so can be used directly as an index
    cout << " rotorindex is " << rotor_index_enigma << endl;

        for(int i=0; i <5; i++){ // up to 5 rotor members
            rotorarray[i] = _rotorarray[i]; //THIS LINE IS PROBLEMATIC, what am i trying to do here?
        }


    number_of_rotors_enigma= _numberofrotors;








}

char Enigma::encode(char input_char_to_be_encrypted){
    /* this function should take in the input character and pass it through the
    plugboard, rotor and then reflector back through the rotor and plugboard
    and then give back out the character it arrives at. It should then rotate the
    rotors as they should be rotated.
    */

    ///temporary section until get rotorindex functioning correctly in the constructor


    char transfer_char;




    return transfer_char;
} // end bracket for encode function

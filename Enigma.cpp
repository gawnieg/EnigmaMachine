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










}

char Enigma::encode(char input_char_to_be_encrypted){
    /* this function should take in the input character and pass it through the
    plugboard, rotor and then reflector back through the rotor and plugboard
    and then give back out the character it arrives at. It should then rotate the
    rotors as they should be rotated.
    */

    ///temporary section until get rotorindex functioning correctly in the constructor
    #ifdef COMMENTS_ON
    cout << "counting number of rotors " << endl;
    #endif

    int count_temp=0;
    while (rotorarray[count_temp]!=NULL){
        count_temp++;
    }
    #ifdef COMMENTS_ON
    cout << "number of rotors is " << count_temp<<  endl;
    #endif

    bool rotate_next_rotor_1 = rotorarray[0]->rotate();
    bool rotate_next_rotor_2 = false; // for moving rotor 3
    bool rotate_next_rotor_3 = false; // for moving rotor 4

    if(rotate_next_rotor_1 == true && count_temp > 1){
        cout << "rotate rotor 2 is required !!!" << endl;
        rotate_next_rotor_2 = rotorarray[1]->rotate();
    }
    if(rotate_next_rotor_2 == true && count_temp>2){
        cout << "rotate rotor 3 is required !!!" << endl;
        rotate_next_rotor_3 = rotorarray[2]->rotate();
    }


    //character to store result between steps.
    char transfer_char;

    //could have if statements in here depending on the amount of rotors the machine is setup with

    if(count_temp ==1){ // for one rotor
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending to plugboard " << endl;
        #endif

        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor1" << endl;
        #endif

        transfer_char = rotorarray[0]->in_out(transfer_char,false);
        transfer_char = reflector->reflect(transfer_char);

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: passed back from rotor 1 was "<< transfer_char << endl;
        #endif

        transfer_char = rotorarray[0]->in_out(transfer_char,true); //sending to rotor 1

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        #endif

        transfer_char = plugboard->plugboard_convert(transfer_char);
    }

    if(count_temp ==2){ // for 2 rotors
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending to plugboard " << endl;
        #endif
        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);

        #ifdef STEP_COMMENTS_ON

        cout << "Encode: sending char to in_out rotor1" << endl;
        #endif
        transfer_char = rotorarray[0]->in_out(transfer_char,false);
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor2" << endl;
        #endif
        transfer_char = rotorarray[1]->in_out(transfer_char,false);

        transfer_char = reflector->reflect(transfer_char);

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: passed back from reflector was "<< transfer_char << endl;
        #endif
        transfer_char = rotorarray[1]->in_out(transfer_char,true); //sending to rotor 1

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor1" << endl;
        #endif
        transfer_char = rotorarray[0]->in_out(transfer_char,true);

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        #endif

        transfer_char = plugboard->plugboard_convert(transfer_char);
    }

    if(count_temp ==3){ // for 3 rotors
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending to plugboard " << endl;
        #endif

        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor1 as"<< transfer_char  << endl;
        #endif

        transfer_char = rotorarray[0]->in_out(transfer_char,false);
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor2 as" << transfer_char << endl;
        #endif
        transfer_char = rotorarray[1]->in_out(transfer_char,false);
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor3 as "<< transfer_char << endl;
        #endif
        transfer_char = rotorarray[2]->in_out(transfer_char,false);

        transfer_char = reflector->reflect(transfer_char);
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: passed back from reflector was "<< transfer_char << endl;
        cout << "Encode: sending char to in_out rotor3 as "<<  transfer_char << endl;
        #endif

        transfer_char = rotorarray[2]->in_out(transfer_char,true);
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: passed back from rotor3 was "<< transfer_char << endl;
        #endif
        transfer_char = rotorarray[1]->in_out(transfer_char,true); //sending to rotor 1
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: passed back from rotor1 was " << transfer_char<< endl;
        #endif
        transfer_char = rotorarray[0]->in_out(transfer_char,true);
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        #endif
        transfer_char = plugboard->plugboard_convert(transfer_char);
        cout << "Encode: after plugboard "<< transfer_char << endl;
    }




    return transfer_char;
} // end bracket for encode function
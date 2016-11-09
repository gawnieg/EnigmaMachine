#include"Enigma.h"
#include<iostream>
#include<fstream>
#include <cstring>
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

Enigma::Enigma(Plugboard* _plugboard, Reflector* _reflector, Rotor* _rotorarray[], int _numberofrotors ){
//constructor for enigma

    plugboard = _plugboard;
    reflector = _reflector;
    cout << " _numberofrotors is " << _numberofrotors << endl; //debugging
    rotorindex = _numberofrotors -1; //minus one so can be used directly as an index

    for(int i=0; i <6; i++){ // up to 5 rotor members
        rotorarray[i] = _rotorarray[i]; //THIS LINE IS PROBLEMATIC, what am i trying to do here?
    }
    cout << " rotorindex is " << rotorindex << endl;









}
void Enigma::one_turn(){
    rotorarray[0]->rotate();
}

char Enigma::encode(char input_char_to_be_encrypted){
    /* this function should take in the input character and pass it through the
    plugboard, rotor and then reflector back through the rotor and plugboard
    and then give back out the character it arrives at. It should then rotate the
    rotors as they should be rotated.
    */

    ///temporary section until get rotorindex functioning correctly in the constructor
    cout << "counting number of rotors " << endl;
    int count_temp=0;
    while (rotorarray[count_temp]!=NULL){
        count_temp++;
    }
    cout << "number of rotors is " << count_temp<<  endl;

    bool rotate_next_rotor_1 = rotorarray[0]->rotate();
    bool rotate_next_rotor_2 = false; // for moving rotor 3
    bool rotate_next_rotor_3 = false; // for moving rotor 4

    if(rotate_next_rotor_1 == true && count_temp > 1){
        cout << "rotate rotor 2 is required !!!" << endl;
        rotate_next_rotor_2 = rotorarray[1]->rotate();
    }
    if(rotate_next_rotor_2 == true && count_temp>2){
        cout << "rotate rotor 3 is required !!!" << endl;
        rotate_next_rotor_3 = rotorarray[1]->rotate();
    }


    //character to store result between steps.
    char transfer_char;

    //could have if statements in here depending on the amount of rotors the machine is setup with

    if(count_temp ==1){ // for one rotor
        cout << "Encode: sending to plugboard " << endl;
        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);

        cout << "Encode: sending char to in_out rotor1" << endl;
        transfer_char = rotorarray[0]->in_out(transfer_char,false);

        transfer_char = reflector->reflect(transfer_char);

        cout << "Encode: passed back from rotor 1 was "<< transfer_char << endl;
        transfer_char = rotorarray[0]->in_out(transfer_char,true); //sending to rotor 1

        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        transfer_char = plugboard->plugboard_convert(transfer_char);
    }

    if(count_temp ==2){ // for 2 rotors
        cout << "Encode: sending to plugboard " << endl;
        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);

        cout << "Encode: sending char to in_out rotor1" << endl;
        transfer_char = rotorarray[0]->in_out(transfer_char,false);

        cout << "Encode: sending char to in_out rotor2" << endl;
        transfer_char = rotorarray[1]->in_out(transfer_char,false);

        transfer_char = reflector->reflect(transfer_char);

        cout << "Encode: passed back from reflector was "<< transfer_char << endl;
        transfer_char = rotorarray[1]->in_out(transfer_char,true); //sending to rotor 1

        cout << "Encode: sending char to in_out rotor1" << endl;
        transfer_char = rotorarray[0]->in_out(transfer_char,true);

        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        transfer_char = plugboard->plugboard_convert(transfer_char);
    }

    if(count_temp ==3){ // for 3 rotors
        cout << "Encode: sending to plugboard " << endl;
        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);

        cout << "Encode: sending char to in_out rotor1" << endl;
        transfer_char = rotorarray[0]->in_out(transfer_char,false);

        cout << "Encode: sending char to in_out rotor2" << endl;
        transfer_char = rotorarray[1]->in_out(transfer_char,false);

        cout << "Encode: sending char to in_out rotor3" << endl;
        transfer_char = rotorarray[2]->in_out(transfer_char,false);

        transfer_char = reflector->reflect(transfer_char);
        cout << "Encode: passed back from reflector was "<< transfer_char << endl;

        cout << "Encode: sending char to in_out rotor3" << endl;
        transfer_char = rotorarray[2]->in_out(transfer_char,true);

        cout << "Encode: passed back from reflector was "<< transfer_char << endl;
        transfer_char = rotorarray[1]->in_out(transfer_char,true); //sending to rotor 1

        cout << "Encode: sending char to in_out rotor1" << endl;
        transfer_char = rotorarray[0]->in_out(transfer_char,true);

        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        transfer_char = plugboard->plugboard_convert(transfer_char);
    }




    return transfer_char;
} // end bracket for encode function




char Enigma::one_way(char input_char){ // replaced by encode function?




/*
   cout << "before plugboard-------------------------------------------------------" << endl;
   char char_after_plugboard;
   char_after_plugboard=plugboard->plugboard_convert(input_char);


   cout<< "back in main before rotor1 is----------------------------------"  << endl;
   char char_after_rotor1;
	char_after_rotor1=rotorarray[0]->in_out(char_after_plugboard);//if array of rotors will not be rotor1 anymore!


   //cout<< "back in main after rotor1 is " << rotor2->in_out(char_after_rotor1) << endl;
   cout << "before rotor2----------------------------------" <<endl;
   char char_after_rotor2;
   char_after_rotor2 = rotorarray[1]->in_out(char_after_rotor1);
   //cout<< "back in main char after rotor is " << char_after_rotor2 <<endl;


   cout << "before reflector------------------------------------------" << endl;
   char char_after_reflector;
   char_after_reflector = reflector->reflect(char_after_rotor2);

   cout << "Character after plugboard, rotor1 and rotor2 and reflector is " << char_after_reflector <<endl;
*/

}

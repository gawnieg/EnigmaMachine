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
Rotor* rotorarray[] = _rotorarray[];
rotorindex = _numberofrotors -1; //minus one so can be used directly as an index



	
	
}



char Enigma::one_way(char input_char){

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
}



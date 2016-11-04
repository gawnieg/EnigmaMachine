#include <iostream>
#include <fstream>
#include <cstring>
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Enigma.h"


using namespace std;




class InputSwitches{
};

class Outboard{
    };





int main(int argc, char** argv){


//cout << "What was passed was " << argv[1] << endl;
Plugboard *plugb = new Plugboard(argv[1]);//will need to error check to see if this is the right array member being passed
Reflector *reflec = new Reflector(argv[2]);
Rotor *rotor1 = new Rotor(argv[3]);
cout << "adding rotor2" <<endl;
Rotor *rotor2 = new Rotor(argv[4]);
 cout << "rotor2 should be added" <<endl;

Rotor* rotor_r[2] = {rotor1,rotor2};

int sizeofrotorarray = 2;

Enigma enigma(plugb,reflec,rotor_r, sizeofrotorarray); // the 2 is the number of rotors

 
 
 //add to Engima object. Plugboard rotor and reflector

//beginning input and testing
char input_char;
while(input_char != '.'){
    cout << "please input an input character, type . to exit" << endl;
    cin >> input_char;
	
	enigma.one_way(input_char);
	
	
	
	
	
	
	
	

	//cout<< "returned from enigma one way is " << Enigma::one_way(input_char)<<endl;
	/*
		cout << "before plugboard-------------------------------------------------------" << endl;
	char char_after_plugboard;
	char_after_plugboard=plugb->plugboard_convert(input_char);


	cout<< "back in main before rotor1 is----------------------------------"  << endl;
	char char_after_rotor1;
	char_after_rotor1=rotor1->in_out(char_after_plugboard);


	//cout<< "back in main after rotor1 is " << rotor2->in_out(char_after_rotor1) << endl;
	cout << "before rotor2----------------------------------" <<endl;
	char char_after_rotor2;
	char_after_rotor2 = rotor2->in_out(char_after_rotor1);
	//cout<< "back in main char after rotor is " << char_after_rotor2 <<endl;


	cout << "before reflector------------------------------------------" << endl;
	char char_after_reflector;
	char_after_reflector = reflec->reflect(char_after_rotor2);

	cout << "Character after plugboard, rotor1 and rotor2 and reflector is " << char_after_reflector <<endl;

*/











}



//send this to the plugboard object, some function that converts it to whatever wired output should give


}

#include <iostream>
#include <fstream>
#include <cstring>
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"



using namespace std;



class Enigma{

// public:
//
// Rotor* enigma_rotor_array[];
};


class InputSwitches{
};

class Outboard{
    };





int main(int argc, char** argv){


//cout << "What was passed was " << argv[1] << endl;
//Plugboard *plugb = new Plugboard(argv[1]);//will need to error check to see if this is the right array member being passed
// Reflector *reflec = new Reflector(argv[2]);
Rotor *rotor1 = new Rotor(argv[3],argv[4]);
// cout << "adding rotor2" <<endl;
// Rotor *rotor2 = new Rotor(argv[5]);
// cout << "rotor2 should be added" <<endl;

//beginning input and testing
char input_char;
while(input_char != '.'){
    cout << "please input an input character, type . to exit" << endl;
    cin >> input_char;
    
    //cout << "plugboard converted is:" << plugb->plugboard_convert(input_char) << endl;
	//cout<< "back in main the reflected is " << reflec->reflect(input_char) << endl;
	cout<< "back in main the rotor is " << rotor1->in_out(input_char) << endl;
	
}



//send this to the plugboard object, some function that converts it to whatever wired output should give


}

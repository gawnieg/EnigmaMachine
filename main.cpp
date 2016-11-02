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
Plugboard *plugb = new Plugboard(argv[1]);//will need to error check to see if this is the right array member being passed
Reflector *reflect = new Reflector(argv[2]);
Rotor *rotor1 = new Rotor(argv[3],argv[4]);
cout << "adding rotor2" <<endl;
Rotor *rotor2 = new Rotor(argv[5]);
cout << "rotor2 should be added" <<endl;



}

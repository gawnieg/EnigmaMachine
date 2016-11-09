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


int sizeofargumentlistpassed=argc-1;// minus one as executable counted!
cout << sizeofargumentlistpassed << " arguments have been passed!!!" <<endl;
cout << "number of rotors = " << sizeofargumentlistpassed - 3 << endl; /* as
plugboard, reflector and rotor position file must be uploaded)*/

int rotornumber = 1;

Plugboard *plugb = new Plugboard(argv[1]);//will need to error check to see if this is the right array member being passed
Reflector *reflec = new Reflector(argv[2]);
Rotor* rotor_r[5] = {NULL, NULL, NULL, NULL,NULL};

if((sizeofargumentlistpassed - 3) ==1){
    Rotor *rotor1 = new Rotor(argv[3],argv[4], rotornumber);
    rotor_r[0]= rotor1;

}
if((sizeofargumentlistpassed - 3) ==2){
    Rotor *rotor1 = new Rotor(argv[4],argv[5], rotornumber);
    Rotor *rotor2 = new Rotor(argv[3],argv[5],rotornumber);
    rotor_r[0]= rotor1;
    rotor_r[1]= rotor2;
}
if((sizeofargumentlistpassed - 3) ==3){
    Rotor *rotor1 = new Rotor(argv[5],argv[6], rotornumber); // was argv[3]
    Rotor *rotor2 = new Rotor(argv[4],argv[6],rotornumber); //was argv[4]
    Rotor *rotor3 = new Rotor(argv[3],argv[6],rotornumber);
    rotor_r[0]= rotor1;
    rotor_r[1]= rotor2;
    rotor_r[2]= rotor3;


}
if ((sizeofargumentlistpassed - 3) ==4){
    Rotor *rotor1 = new Rotor(argv[6],argv[7], rotornumber);
    Rotor *rotor2 = new Rotor(argv[5],argv[7],rotornumber);
    Rotor *rotor3 = new Rotor(argv[4],argv[7],rotornumber);
    Rotor *rotor4 = new Rotor(argv[3],argv[7],rotornumber);
    rotor_r[0]= rotor1;
    rotor_r[1]= rotor2;
    rotor_r[2]= rotor3;
    rotor_r[3]=rotor4;
}


cout << "sizeofargumentlistpassed is " << sizeofargumentlistpassed << endl;
sizeofargumentlistpassed = sizeofargumentlistpassed-3;

cout << "creating enigma object " << endl;
Enigma enigma(plugb,reflec,rotor_r, sizeofargumentlistpassed); // the 2 is the number of rotors


//enigma.one_turn();
//testing out new array structures
char input_char;
string input_sentance;
cout << "please input an input character, type . to exit" << endl;



while(input_char != '.'){
    cout << "please input an input character, type . to exit" << endl;
    cin >> input_char;
    cout << "encoded character is : " << enigma.encode(input_char) << endl;


}



} //END OF MAIN

/*
To Do:
1. be able to pass in strings from the commmand LINE
2. construct enigma so that it can have unlimited rotors.
3.  update error code. isdigit is also not functioning correctly.


*/

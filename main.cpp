#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Enigma.h"
#include <algorithm>



using namespace std;

string delSpaces(string &str);



class InputSwitches{
};

class Outboard{
};





int main(int argc, char** argv){


int sizeofargumentlistpassed=argc-1;// minus one as executable counted!
cout << sizeofargumentlistpassed << "Main: arguments have been passed!!!" <<endl;
cout << "Main: number of rotors = " << sizeofargumentlistpassed - 3 << endl; /* as
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


cout << "Main: sizeofargumentlistpassed - 3 is " << sizeofargumentlistpassed << endl;
sizeofargumentlistpassed = sizeofargumentlistpassed-3;
cout << "Main: sizeofargumentlistpassed - 3 is " << sizeofargumentlistpassed << endl;

cout << "Main:creating enigma object " << endl;
Enigma enigma(plugb,reflec,rotor_r, sizeofargumentlistpassed); // the 2 is the number of rotors


char input_char;
string input_sentance;
cout << "please input an sentence to be encrypted, terminated by a full stop" << endl;
cin  >>ws>>  input_sentance;


int a=0;
char encrypted_sentence [100];


while(input_char != '.'){

    input_char = input_sentance[a];
    if(input_char == '.'){
        break;
    }
    cout << "the int versionof the character is " << (int)input_char <<endl;
    if( ((int)input_char < 65) || ((int)input_char >122) || (((int)input_char >90) && ((int)input_char <97)) ){
        break;
    }

    cout << "The "<< a <<" charcter from sentence is " << input_char << endl;
    //encrypted_sentence[a] = enigma.encode(input_char);
    cout << "number of rotors is " << enigma.number_of_rotors_enigma <<  endl;

    char transfer_char = input_char;
    //section to look after rotation of rotors.
    bool rotate_next_rotor_1 = enigma.rotorarray[0]->rotate();
    bool rotate_next_rotor_2 = false; // for moving rotor 3
    bool rotate_next_rotor_3 = false; // for moving rotor 4

    if(rotate_next_rotor_1 == true && number_of_rotors_enigma > 1){
        cout << "rotate rotor 2 is required !!!" << endl;
        rotate_next_rotor_2 = enigma.rotorarray[1]->rotate();
    }
    if(rotate_next_rotor_2 == true && number_of_rotors_enigma>2){
        cout << "rotate rotor 3 is required !!!" << endl;
        rotate_next_rotor_3 = enigma.rotorarray[2]->rotate();
    }

    //send to plugboard
    transfer_char = plugb->plugboard_convert(transfer_char);
    cout << "Output from plugboard is " << transfer_char << endl;

    ///section for way out
    for(int i =0; i < number_of_rotors_enigma -1; i++){

    transfer_char = rotorarray[i].in_out(transfer_char, 0, enigma); // as

    }

    //send to reflector
    transfer_char = reflec->reflect(transfer_char);
    cout << "Output from plugboard is " << transfer_char << endl;

    //section for way back

    for(int i = enigma.number_of_rotors_enigma-1; i < 0; i--){

    transfer_char = rotorarray[i].in_out(transfer_char, 0, enigma); // as

    }




    cout << "The encrypted character is " << transfer_char <<endl;

    //cout << "encoded character is : " << enigma.encode(input_char) << endl;
    a++;
    cout << "---------------------------------------------------------------" <<endl;

}

cout << "The encrypted_sentence is " <<endl;
for(unsigned int i=0; i<input_sentance.length()-1; i++){
    cout << encrypted_sentence[i];
}
cout << endl; //print blank line at end for readability

cout << "The number of rotations for rotor1 is " << rotor_r[0]->num_rotations_comp << endl;
cout << "The number of rotations for rotor2 is " << rotor_r[1]->num_rotations_comp << endl;
cout << "The number of rotations for rotor3 is " << rotor_r[2]->num_rotations_comp << endl;

cout << endl; //print blank line at end for readability



} //END OF MAIN

string delSpaces(string &str)
{
   // str.erase(remove(str.begin(), str.end(), ' '), str.end());
cout << str << endl;
   for(unsigned int i=0; i<str.length(); i++){
      if(str[i] == ' ') str.erase(i,1);
      cout << "i is " << i << endl;
   }

     cout << str << endl;
    return str;
}



/*
To Do:
1. be able to pass in strings from the commmand LINE
2. construct enigma so that it can have unlimited rotors.
3.  update error code. isdigit is also not functioning correctly.


*/

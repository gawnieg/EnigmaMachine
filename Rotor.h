#ifndef ROTOR_H
#define ROTOR_H


#include <iostream>
#include "Enigma.h"




using namespace std;


class Rotor{

public:
    //constructors
    Rotor(const char* filename, int rotornumber);
    Rotor(const char* filename, const char* pos_file, int rotornumber);


    bool rotate( Enigma enigma);

    char in_out(char input_char, bool way_back, Enigma enigma); /*maps the inputted character, way_back is to indicate what direction the character is travelling. true for on the way back
    and returns the output according to how
    the rotor array is established*/
    // rotor_index_enigma is the index number, rightmost is zero
    int num_rotations_comp=0; // will hold the number of rotations the rotor has done.
    int rotorarray[30];
    int rotate_marker=0; //marker for where the rotor rotates from




private:

int pos_array[5]; //enigma class should really hold the position array

bool sets_position = false;




void printrotorarray(int rotorarray[30]);



};

#endif

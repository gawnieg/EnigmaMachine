#ifndef ROTOR_H
#define ROTOR_H


#include <iostream>
#include "errors.h"




using namespace std;


class Rotor{

public:
    //constructors

    Rotor();
    int Rotor_load(const char* filename, const char* pos_file, int rotornumber, int (&numberofrotationsarray)[5]);


    bool rotate(int whatrotor, int (&numberofrotationsarray)[5]);

    char in_out(char input_char, bool way_back,int numberofrotationsarray[5],int rotornumber); /*maps the inputted character, way_back is to indicate what direction the character is travelling. true for on the way back
    and returns the output according to how
    the rotor array is established*/
    // rotor_index_enigma is the index number, rightmost is zero
    int num_rotations_comp=0; // will hold the number of rotations the rotor has done.




private:
int rotorarray[30];
int pos_array[5]; //enigma class should really hold the position array

bool sets_position = false;
int rotate_marker=0; //marker for where the rotor rotates from
int starting_rotate_marker=0; ///marker to account for offset starting position



void printrotorarray(int const  (&rotorarray)[30]);



};

#endif

#ifndef ROTOR_H
#define ROTOR_H


#include <iostream>




using namespace std;


class Rotor{

public:
    //constructors
    Rotor(const char* filename, int rotornumber);
    Rotor(const char* filename, const char* pos_file, int rotornumber);







private:
int rotorarray[30];
int pos_array[5]; //enigma class should really hold the position array

bool sets_position = false;
int rotate_marker=0; //marker for where the rotor rotates from

bool rotate();

char in_out(char input_char, bool way_back); /*maps the inputted character, way_back is to indicate what direction the character is travelling. true for on the way back
and returns the output according to how
the rotor array is established*/

};

#endif

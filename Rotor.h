#ifndef ROTOR_H
#define ROTOR_H


#include <iostream>
#include "errors.h"




using namespace std;


class Rotor{

public:

    Rotor(); //blank constructor
    int Rotor_load(const char* filename, const char* pos_file,\
         int rotornumber, int (&numberofrotationsarray)[5]);
         /*Loads up and tests the parameters.      */
    bool rotate(int whatrotor, int (&numberofrotationsarray)[5]);
    /*this function rotates the rotor, the number of which is passed by whatrotor
    with zero being the rightmost rotor. It returns true if the rotor to its LHS
    needs a rotation (i.e. a notch has been hit)
    */
    char in_out(char input_char, bool way_back,int numberofrotationsarray[5],\
        int rotornumber); /*maps the inputted character, way_back is to indicate\
         what direction the character is travelling. true for on the way back
    and returns the output according to how the rotor array is established*/





private:
    int rotorarray[27];
    int pos_array[5];
    int rotate_marker=0; //marker for where the rotor rotates from
    int starting_rotate_marker=0; ///marker to account for offset starting position
    void printrotorarray(int const  (&rotorarray)[27]); // function to print out array



};

#endif

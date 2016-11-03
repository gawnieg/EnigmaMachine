#include <iostream>

#ifndef ROTOR_H
#define ROTOR_H

using namespace std;


class Rotor{

public:
    //constructors
    Rotor(const char* filename);
    Rotor(const char* filename, const char* pos_file);
	char in_out(char input_char); /*maps the inputted character
	and returns the output according to how 
	the rotor array is established*/
	
	


private:

int rotorarray[30];
int pos_array[5];
bool sets_position = false;

};

#endif

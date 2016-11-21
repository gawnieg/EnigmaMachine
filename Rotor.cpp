#include<iostream>
#include<fstream>
#include <cstring>
#include "Rotor.h"
#include "errors.h"


using namespace std;



Rotor::Rotor(){

        //intentionally blank
}//end ofrotor constructor with position array


char Rotor::in_out(char input_char, bool way_back,  int numberofrotationsarray [5],\
     int rotornumber){


	int input_int;

    if(way_back==false){


        // standard ie if way_back is false
        //if way_back ==true then different mapping is required
        char  transfer_char = input_char;
        char transfer_char_before;
        transfer_char_before = transfer_char;

        //then mapping internally
        input_int= (int)transfer_char - 65 ;

        transfer_char = (char)(rotorarray[input_int]+65); // this does the internal mapping.
        transfer_char_before = transfer_char;
        transfer_char = (char)((int)transfer_char - (numberofrotationsarray[rotornumber]%26));
        if(transfer_char > 'Z' ){
            transfer_char='A' + ((numberofrotationsarray[rotornumber])%26)-('Z'-transfer_char_before) -1;
        }
        if(transfer_char < 'A' ){
            transfer_char = 'Z' - ((numberofrotationsarray[rotornumber])%26)+(transfer_char_before-'A') +1 ;
        }

        return transfer_char;

    } //end of forwards section



    if(way_back == true){

        char  transfer_char = input_char;
        char transfer_char_before;
        transfer_char_before = transfer_char;

        transfer_char = (char)((int)transfer_char + ((numberofrotationsarray[rotornumber])%26));

        if(transfer_char > 'Z' ){
              transfer_char = 'A' + ((numberofrotationsarray[rotornumber])%26)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
             transfer_char = 'Z' - ((numberofrotationsarray[rotornumber])%26)+(transfer_char_before-'A') +1 ;
         }

         /* MAPPING SECTION */

        input_int= (int)transfer_char - 65 ;
        bool rotorarraymatch=false;
        int index_match_back=0;

        while(rotorarraymatch == false){
            if(rotorarray[index_match_back] == input_int){
                rotorarraymatch=true;
                break;
            }
            index_match_back++;
        }
        transfer_char = (char)(index_match_back + 65); // this does the mapping
        return transfer_char;


    } //end of backward section

return 0; //this will not execute as way_back will be either true or false.

}//end bracket for in_out


bool Rotor::rotate(int whatrotor , int (&numberofrotationsarray)[5]){


    //increment the number of rotations index for this rotor.
    numberofrotationsarray[whatrotor]++;

	//rotate array function - 1 standard step.
    int temp=0;
    //moving array around
	for(int i =25; i > -1 ; i--){
		temp=rotorarray[25];
		rotorarray[25]=rotorarray[i];
		rotorarray[i]=temp;
	}
    if(starting_rotate_marker== numberofrotationsarray[whatrotor]||\
        numberofrotationsarray[whatrotor]%rotate_marker == 0){
        return true;
    }
    else {
        return false;
    }


}

void Rotor::printrotorarray(int const (&rotorarray)[27]){

    cout << "Printing rotor array" << endl;
        for(int i=0; i<26; i++){
    		cout << rotorarray[i] << " at element " << i << "  "<< \
            (char)(rotorarray[i]+65) << " at " << (char)(i+65) <<endl;
        }

}


int Rotor::Rotor_load(const char* filename, const char* pos_file, int rotornumber,\
     int (&number_rot_comp)[5]){


    ifstream in_pos;
    in_pos.open(pos_file);
    if(in_pos.fail()){
        return (ERROR_OPENING_CONFIGURATION_FILE);
    }

    if(in_pos.peek()==std::ifstream::traits_type::eof()){
        cerr << "No starting position for rotor 0 in rotor position file: rotor.pos" <<endl;
        return (NO_ROTOR_STARTING_POSITION);
    }

    char test_char;

    if (in_pos.is_open()) {
      while (in_pos >> test_char) {
        if (!isdigit(test_char)) {
            cerr << "Non-numeric character in rotor positions file rotor.pos"<<endl;
            return NON_NUMERIC_CHARACTER;
        }
      }
    }
    in_pos.close();

    int pos_counter=0;
    in_pos.open(pos_file);
    while(!in_pos.eof()){
        in_pos  >>  pos_array[pos_counter];

        if(in_pos.rdstate()>0){
            break;
        }
        if(pos_array[pos_counter]> 25 ||pos_array[pos_counter]<0 ){
            return(INVALID_INDEX);
        }
        pos_counter++;
    }

    in_pos.close();


//////////////////END OF SECTION TO LOAD POSITION //////////////////////////

    ifstream in;
    in.open(filename);

    if(in.fail()){
        return (ERROR_OPENING_CONFIGURATION_FILE);
    }
    char testing_char;
    // in.open(filename);
    if (in.is_open()) {
      while (in >> testing_char) {
        if (!isdigit(testing_char)) {
            cerr << "Non-numeric character for mapping in rotor file rotor.rot" <<endl;
            return NON_NUMERIC_CHARACTER;
        }
      }
    }
    in.close();

    int counter=0;
    in.open(filename);
    while(!in.eof()){

        in >>ws >>  rotorarray[counter];
        //this is exiting out of the loop for the last character
        if(in.rdstate()>0){
            break;
        }

        //check for outside of range
        if(rotorarray[counter]> 25 ||rotorarray[counter]<0 ){
            return(INVALID_INDEX);
        }
        //check for duplicates
        for(int i =0; i<(counter-1); i++ ){ //counter -1 to account for the fact that the rotate marker is included
            for(int j=0; j < i; j++){
                if(rotorarray[i]==rotorarray[j]){
                    cerr << "Invalid mapping of input " << j << " to output "\
                    << rotorarray[j] << " (output " << rotorarray[j] \
                    << " is already mapped to from input " << i \
                    << ") in rotor file: " << filename <<endl;

                    return(INVALID_ROTOR_MAPPING);
                }
            }
        }
        counter++;
    }
    in.close();

    //setting the last character as the rotate marker
    rotate_marker=rotorarray[26];


    if(counter != 27){
        cerr << "Not all inputs mapped in rotor file: rotor.rot" <<endl;
        return(INVALID_ROTOR_MAPPING);
    }

    //initialising rotor to starting position
    int initialrotationsindex = pos_counter-rotornumber;

    //adjusting for intial position
    number_rot_comp[rotornumber-1]=number_rot_comp[rotornumber-1]+\
    pos_array[initialrotationsindex];

    starting_rotate_marker= number_rot_comp[rotornumber-1];


    //adjusting number of rotations complete
    for (int i =0; i < pos_array[initialrotationsindex]; i++) {
        int temp=0;
            for(int i =25; i > -1  ; i--){
                temp=rotorarray[25];
                rotorarray[25]=rotorarray[i];
                rotorarray[i]=temp;
            }
    }

    return NO_ERROR;
}

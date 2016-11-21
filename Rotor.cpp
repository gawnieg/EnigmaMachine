#include<iostream>
#include<fstream>
#include <cstring>
#include "Rotor.h"
#include "errors.h"
//
#define COMMENTS_ON
#define ARRAYPRINTING


using namespace std;



Rotor::Rotor(){

        //intentionally blank


    }//end ofrotor constructor with position array


char Rotor::in_out(char input_char, bool way_back,  int numberofrotationsarray [5], int rotornumber){


    	int input_int;
        #ifdef COMMENTS_ON
        cout << "character is " << input_char<< endl;
        cout << "which as an integer is " << (int)input_char - 65 << endl;
        cout << "way back? " << way_back <<endl;

        #endif


if(way_back==false){


    // standard ie if way_back is false
    //if way_back ==true then different mapping is required
    char  transfer_char = input_char;
    char transfer_char_before;
    transfer_char_before = transfer_char;

    //then mapping internally
    input_int= (int)transfer_char - 65 ;
    #ifdef COMMENTS_ON
        printrotorarray(rotorarray);
        if(way_back == false){
                cout << "IN_OUT has found the matching number to be "\
                << rotorarray[input_int] << " which as an char is " <<\
                 (char)(rotorarray[input_int]+65) <<endl;
        }
    #endif



    transfer_char = (char)(rotorarray[input_int]+65); // this does the internal mapping.


    #ifdef COMMENTS_ON
    cout << "   Now changing to account for output rotor" <<rotornumber <<\
    " rotation relativity " \
    << (char)((int)transfer_char - (numberofrotationsarray[rotornumber]%26)) <<endl;
    #endif

    transfer_char_before = transfer_char;

    transfer_char = (char)((int)transfer_char - (numberofrotationsarray[rotornumber]%26));


    if(transfer_char > 'Z' ){
        #ifdef COMMENTS_ON
        cout << "greater than Z so have to reset" << endl;
        #endif
        transfer_char='A' + ((numberofrotationsarray[rotornumber])%26)-('Z'-transfer_char_before) -1;

    }
    if(transfer_char < 'A' ){
        #ifdef COMMENTS_ON
        cout << "less than A  so have to reset!!!!!!!!!!!!!!!!!" << endl;
        #endif
        transfer_char = 'Z' - ((numberofrotationsarray[rotornumber])%26)+(transfer_char_before-'A') +1 ;

    }

return transfer_char;

} //end of forwards section



    if(way_back == true){

        char  transfer_char = input_char;
        char transfer_char_before;
        transfer_char_before = transfer_char;

        #ifdef COMMENTS_ON
        cout << "passed in as " << transfer_char << endl;


        cout << "Rotor Class moving backwards - accounting for rotation is now " << \
        (char)((int)transfer_char + (numberofrotationsarray[rotornumber])%26) <<\
        "which is adding" << (numberofrotationsarray[rotornumber])%26 << endl;
        #endif



        transfer_char = (char)((int)transfer_char + ((numberofrotationsarray[rotornumber])%26));


          if(transfer_char > 'Z' ){
              #ifdef COMMENTS_ON
              cout << "greater than Z so have to reset" << endl;
              #endif
              transfer_char = 'A' + ((numberofrotationsarray[rotornumber])%26)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
              #ifdef COMMENTS_ON
              cout << "less than A so have to reset!!!!!!!!!!!!!!!!!!!!!!!" << endl;
              #endif
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
        #ifdef COMMENTS_ON
        cout << "found mapped character on way back to be  " << (char)(index_match_back + 65) <<endl;


            printrotorarray(rotorarray);
            if(way_back == false){
                    cout << "IN_OUT has found the matching number to be "\
                    << rotorarray[input_int] << " which as an char is " <<\
                     (char)(rotorarray[input_int]+65) <<endl;
            }
        #endif

        transfer_char = (char)(index_match_back + 65); // this does the mapping


return transfer_char;


 }    /////////////////end of backward section

return 0; //this will not execute as way_back will be either true or false.

}//end bracket for in_out


bool Rotor::rotate(int whatrotor , int (&numberofrotationsarray)[5]){


    //increment the number of rotations index for this rotor.
    numberofrotationsarray[whatrotor]++;



    #ifdef COMMENTS_ON
	cout <<"Rotor.Rotate STARTING 1 ROTATE FOR ROTOR!" <<endl;
    cout << "printing array before rotation" <<endl;
    printrotorarray(rotorarray);
    #endif
	//rotate array function - 1 standard step.

	int temp=0;
    //moving array around
	for(int i =25; i > -1 ; i--){
		temp=rotorarray[25];
		rotorarray[25]=rotorarray[i];
		rotorarray[i]=temp;
	}

    #ifdef COMMENTS_ON
	cout <<"printing array after rotation" <<endl;
    printrotorarray(rotorarray);
    #endif

    /*could set flag that indicates when notch has been reached
    and then send flag to enigma class indicating that it should rotate the next
    rotor . true if notch reached, false if not */
#ifdef COMMENTS_ON
    cout << "rotate_marker for this rotor is " << rotate_marker <<endl;

#endif

    //was rotorarray[0]== rotatemarker
    if(starting_rotate_marker== numberofrotationsarray[whatrotor]||\
        numberofrotationsarray[whatrotor]%rotate_marker == 0){
        cout << "requesting rotation of second rotor " << endl;
        cout << "numberofrotationsarray" << numberofrotationsarray[whatrotor] <<endl;
        return true;

    }
    else {
        return false;
    }


}

void Rotor::printrotorarray(int const (&rotorarray)[30]){
#ifdef ARRAYPRINTING
cout << "Printing rotor array" << endl;
    for(int i=0; i<26; i++){
		cout << rotorarray[i] << " at element " << i << "  "<< \
        (char)(rotorarray[i]+65) << " at " << (char)(i+65) <<endl;
    }
#endif


}


int Rotor::Rotor_load(const char* filename, const char* pos_file, int rotornumber, int (&number_rot_comp)[5]){


    ifstream in_pos;
    in_pos.open(pos_file);
    if(in_pos.fail()){
        return (ERROR_OPENING_CONFIGURATION_FILE);
    }

    if(in_pos.peek()==std::ifstream::traits_type::eof()){
        cerr << "FILE EMPTY" <<endl;
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


    int counter=0;

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

                    return(INVALID_ROTOR_MAPPING);
                }
            }

        }
        counter++;

    }

    char testing_char;
    in.open(filename);
    if (in.is_open()) {
      while (in >> testing_char) {
        if (!isdigit(testing_char)) {
            cerr << "Non-numeric character for mapping in rotor file rotor.rot" <<endl;
            return NON_NUMERIC_CHARACTER;
        }
      }
    }
    in.close();

    //setting the last character as the rotate marker
    rotate_marker=rotorarray[26];


    if(counter != 27){
        cerr << "Not all inputs mapped in rotor file: rotor.rot" <<endl;
        return(INVALID_ROTOR_MAPPING);
    }

    in.close();


    #ifdef COMMENTS_ON
    cout << "printing upon construction " << endl;
    //printing array - debugging
    printrotorarray(rotorarray);
    #endif

//initialising rotor to starting position


    int initialrotationsindex = pos_counter-rotornumber;

    // plus one as position file is read from left to right
    #ifdef COMMENTS_ON
    cout << "the offset required is : " << pos_array[initialrotationsindex] << endl;
    cout << "rotor number " << rotornumber <<endl;
    cout << "pos counter " << pos_counter <<endl;
    for(int i =0; i < 3; i++){
        cout << "the poss array is " << pos_array[i]<<endl;
    }
    cout << "number of rotations array before" <<number_rot_comp[rotornumber-1]<< endl;

    cout<< "rotate_marker" << rotate_marker<<endl;



    #endif
    //adjusting for intial position
    number_rot_comp[rotornumber-1]=number_rot_comp[rotornumber-1]+\
    pos_array[initialrotationsindex];

    starting_rotate_marker= number_rot_comp[rotornumber-1];


    //adjusting number of rotations complete
    #ifdef COMMENTS_ON
    cout << "number of rotations array after" <<number_rot_comp[rotornumber-1]<< endl;
    #endif







    for (int i =0; i < pos_array[initialrotationsindex]; i++) {
            int temp=0;

            for(int i =25; i > -1  ; i--){
                temp=rotorarray[25];
                rotorarray[25]=rotorarray[i];
                rotorarray[i]=temp;
            }
    }



    #ifdef COMMENTS_ON
    cout << "printing after position initialisation " << endl;
    printrotorarray(rotorarray);
    cout << "rotor is now initialised" <<endl;
    #endif

    return NO_ERROR;
}

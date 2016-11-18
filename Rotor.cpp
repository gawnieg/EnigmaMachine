#include<iostream>
#include<fstream>
#include <cstring>
#include "Rotor.h"
#include "errors.h"
//
// #define COMMENTS_ON
// #define ARRAYPRINTING


using namespace std;




    Rotor::Rotor(){




    }//end ofrotor constructor with position array


char Rotor::in_out(char input_char, bool way_back,  int numberofrotationsarray [5], int rotornumber){


    	int input_int;
        #ifdef COMMENTS_ON
        cout << "character is " << input_char<< endl;
        cout << "which as an integer is " << (int)input_char - 65 << endl;
        cout << "way back? " << way_back <<endl;

        #endif
        int nextrotornumber = rotornumber +1; // is the next one over

if(way_back==false){


    // standard ie if way_back is false
    //if way_back ==true then different mapping is required
    char  transfer_char = input_char;
    char transfer_char_before;
    transfer_char_before = transfer_char;

    if(rotornumber != 0){ // does not need to for first rotor
        #ifdef COMMENTS_ON
        cout << "Rotor: accounting for rotation for this rotor would be equivilent to  " << \
        (char)((int)transfer_char - (numberofrotationsarray[rotornumber]%25))<< endl;
        #endif
        transfer_char = (char)((int)transfer_char - (numberofrotationsarray[rotornumber]%25));

        if(transfer_char > 'Z' ){
            #ifdef COMMENTS_ON
            cout << "greater than Z so have to reset" << endl;
            #endif
            transfer_char='A' + (numberofrotationsarray[rotornumber]%25)-('Z'-transfer_char_before) -1;
        }
        if(transfer_char < 'A' ){
            #ifdef COMMENTS_ON
            cout << "less than A  so have to reset!" << endl;
            #endif

            transfer_char = 'Z' - (numberofrotationsarray[rotornumber]%25)+(transfer_char_before-'A') +1 ;
        }
        #ifdef COMMENTS_ON
        cout << "Rotor: accounted for rotation would be equivilent to  " <<transfer_char<<endl;
        #endif
    }

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
    << (char)((int)transfer_char - (numberofrotationsarray[rotornumber]%25)) <<endl;
    #endif

    transfer_char_before = transfer_char;

    transfer_char = (char)((int)transfer_char - (numberofrotationsarray[rotornumber]%25));


    if(transfer_char > 'Z' ){
        #ifdef COMMENTS_ON
        cout << "greater than Z so have to reset" << endl;
        #endif
        transfer_char='A' + ((numberofrotationsarray[rotornumber])%25)-('Z'-transfer_char_before) -1;

    }
    if(transfer_char < 'A' ){
        #ifdef COMMENTS_ON
        cout << "less than A  so have to reset!!!!!!!!!!!!!!!!!" << endl;
        #endif
        transfer_char = 'Z' - ((numberofrotationsarray[rotornumber])%25)+(transfer_char_before-'A') +1 ;

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
        (char)((int)transfer_char + (numberofrotationsarray[rotornumber])%25) <<\
        "which is adding" << (numberofrotationsarray[rotornumber])%25 << endl;
        #endif



        transfer_char = (char)((int)transfer_char + ((numberofrotationsarray[rotornumber])%25));


          if(transfer_char > 'Z' ){
              #ifdef COMMENTS_ON
              cout << "greater than Z so have to reset" << endl;
              #endif
              transfer_char = 'A' + ((numberofrotationsarray[rotornumber])%25)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
              #ifdef COMMENTS_ON
              cout << "less than A so have to reset!!!!!!!!!!!!!!!!!!!!!!!" << endl;
              #endif
             transfer_char = 'Z' - ((numberofrotationsarray[rotornumber])%25)+(transfer_char_before-'A') +1 ;
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



        transfer_char_before = transfer_char;

        if(rotornumber !=0){ // does not need to be done before the plugboard.
            #ifdef COMMENTS_ON
        cout << " Rotor Class moving backwards (part2)- accounting for rotation  " << \
        (char)((int)transfer_char + (numberofrotationsarray[rotornumber])%25)<< \
        " which is adding " << (numberofrotationsarray[rotornumber])%25 << endl;
        #endif
        transfer_char = (char)((int)transfer_char + ((numberofrotationsarray[rotornumber])%25));


          if(transfer_char > 'Z' ){
              #ifdef COMMENTS_ON
              cout << "greater than Z so have to reset" << endl;
              #endif
              transfer_char = 'A' + ((numberofrotationsarray[rotornumber])%25)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
              #ifdef COMMENTS_ON
              cout << "less than A so have to reset!" << endl;
              #endif
             transfer_char = 'Z' - ((numberofrotationsarray[rotornumber])%25)+(transfer_char_before-'A') +1 ;
         }
        #ifdef COMMENTS_ON
         cout << "the character is now " << transfer_char << "going back to main" <<endl;
         #endif
        }

return transfer_char;


 }    /////////////////end of backward section




return 'F'; //if goosed



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
    if(rotate_marker== numberofrotationsarray[whatrotor]){ // IF THE TOP POSITION IS EQUAL TO THE NOTCH T
        return true;

    }
    else {
        return false;
    }


}

void Rotor::printrotorarray(int rotorarray[30]){
#ifdef ARRAYPRINTING
cout << "Printing rotor array" << endl;
    for(int i=0; i<26; i++){
		cout << rotorarray[i] << " at element " << i << "  "<< \
        (char)(rotorarray[i]+65) << " at " << (char)(i+65) <<endl;
    }
#endif


}


int Rotor::Rotor_load(const char* filename, const char* pos_file, int rotornumber){

    sets_position =true;
    ifstream in_pos;
    in_pos.open(pos_file);
    if(!in_pos){
        return (ERROR_OPENING_CONFIGURATION_FILE);
    }
    int pos_counter=0;
    while(!in_pos.eof()){
        in_pos  >>  pos_array[pos_counter];
        //cout << "reading pos array" << endl;
        //cout << "counter is " << pos_counter << endl;

        if(in_pos.rdstate()>0){
            break;
        }
        if(isdigit(pos_array[pos_counter])==true){
            return(NON_NUMERIC_CHARACTER);
        }
        if(pos_array[pos_counter]> 25 ||pos_array[pos_counter]<0 ){
            return(INVALID_INDEX);
        }
        pos_counter++;
    }

    in_pos.close();


    ifstream in;
    in.open(filename);
        if(!in){
            return (ERROR_OPENING_CONFIGURATION_FILE);
        }
        //put in array
        //int pbarray[26];

        //printing for testing

        int counter=0;

        while(!in.eof()){

            in >>ws >>  rotorarray[counter];
            //this is exiting out of the loop for the last character
            if(in.rdstate()>0){
                break;
            }
            //check if everything is a digit
            if(isdigit(rotorarray[counter])==true){
                return(NON_NUMERIC_CHARACTER);
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
    //setting the last character as the rotate marker
    rotate_marker=rotorarray[26];


    if(counter != 27){
        return(INVALID_ROTOR_MAPPING);
    }

    in.close();


    #ifdef COMMENTS_ON
    cout << "printing upon construction " << endl;
    //printing array - debugging
    printrotorarray(rotorarray);
    #endif

//moving


    int initialrotationsindex = 0;
    //change this to sizeofarray - x. This is currently the
    if(rotornumber == 1){
        initialrotationsindex = 2;
    }
    if(rotornumber == 2){
        initialrotationsindex = 1;
    }
    if(rotornumber == 3){
        initialrotationsindex = 0;
    }

    // plus one as position file is read from left to right
    #ifdef COMMENTS_ON
    cout << "the offset required is : " << pos_array[initialrotationsindex] << endl;
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
}

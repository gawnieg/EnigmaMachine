#include<iostream>
#include<fstream>
#include <cstring>
#include "Rotor.h"

#define COMMENTS_ON
#define ARRAYPRINTING


using namespace std;




    Rotor::Rotor(const char* filename, const char* pos_file, int rotornumber){

		sets_position =true;
        ifstream in_pos;
        in_pos.open(pos_file);
        if(!in_pos){
            cout <<"input stream failed for in_pos" <<endl;
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
                cerr<< "NON_NUMERIC_CHARACTER" <<endl;
            }
            if(pos_array[pos_counter]> 25 ||pos_array[pos_counter]<0 ){
                cerr << "INVALID_INDEX" << pos_array[pos_counter]  << endl;
            }
            pos_counter++;
        }

        for(int i =0; i < pos_counter; i++){

                    cout << "the pos_array member  is " << pos_array[i] <<endl;
        }
        in_pos.close();

        cout << "up in the rotor constructor " << filename <<endl;
        ifstream in;
        in.open(filename);
            if(!in){
                cout <<"input stream failed" <<endl;
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
                    cerr<< "NON_NUMERIC_CHARACTER" <<endl;
                }
                //check for outside of range
                if(rotorarray[counter]> 25 ||rotorarray[counter]<0 ){
                    cerr << "INVALID_INDEX" << rotorarray[counter]  << endl;
                }
                //check for duplicates
                for(int i =0; i<(counter-1); i++ ){ //counter -1 to account for the fact that the rotate marker is included
                    for(int j=0; j < i; j++){
                        if(rotorarray[i]==rotorarray[j]){
                            cerr << "INVALID_ROTOR_MAPPING" /*<< " at " << j << "and "<< i */ << endl;
                        }
                    }

                }
                counter++;

            }
		//setting the last character as the rotate marker
		rotate_marker=rotorarray[26];
		cout << "rotate marker is" <<rotate_marker << endl;

        if(counter != 27){
            cerr<<  "INVALID_ROTOR_MAPPING" << endl;
        }

        in.close();


        #ifdef COMMENTS_ON
        cout << "printing upon construction " << endl;
        //printing array - debugging
        printrotorarray(rotorarray);
        #endif

    //moving

        cout << "the rotor number is  " <<rotornumber <<endl;
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
        cout << "the offset required is : " << pos_array[initialrotationsindex] << endl;

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


    }//end ofrotor constructor with position array

//consider deleting as need to send position array to all rotors!!!
    Rotor::Rotor(const char* filename, int rotornumber){ //overloading Rotor constructor, this one has no position
        #ifdef COMMENTS_ON
        cout << "up in the rotor constructor " << filename <<endl;
        #endif
        ifstream in;
        in.open(filename);
            if(!in){
                cout <<"input stream failed" <<endl;
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
                    cerr<< "NON_NUMERIC_CHARACTER" <<endl;
                }
                //check for outside of range
                if(rotorarray[counter]> 25 ||rotorarray[counter]<0 ){
                    cerr << "INVALID_INDEX" << rotorarray[counter]  << endl;
                }
                //check for duplicates
                for(int i =0; i<counter; i++ ){
                    for(int j=0; j < i; j++){
                        if(rotorarray[i]==rotorarray[j]){
                            cerr << "INVALID_ROTOR_MAPPING" /*<< " at " << j << "and "<< i */ << endl;
                        }
                    }

                }
                counter++;

            }

		//setting the last character as the rotate marker
		rotate_marker=rotorarray[26];
        #ifdef COMMENTS_ON
		cout << "rotate marker is" <<rotate_marker << endl;
        #endif


        if(counter != 27){
            cerr<<  "INVALID_ROTOR_MAPPING" << endl;
        }

        in.close();


        #ifdef COMMENTS_ON
        //printing array - debugging
        for(int i =0; i < (counter-1); i++){

                    cout << "the rotorarray member  is " << rotorarray[i] << " at index " << i << endl;

		}


        //section added to initialise the position of the rotor
        cout << "the rotor number is  " <<rotornumber <<endl;

        #endif

        int initialrotationsindex = 0; // this is the index to extract a number from the pos_array
        //change this to sizeofarray - x
        if(rotornumber == 1){
            initialrotationsindex = 2;
        }
        if(rotornumber == 2){
            initialrotationsindex = 1;
        }
        if(rotornumber == 3){
            initialrotationsindex = 0;
        }
        #ifdef COMMENTS_ON
        cout << "the rotor number is  " <<rotornumber <<endl;
        cout << "pos_array 0 is" << pos_array[0] << endl;
        cout << "pos_array 1 is" << pos_array[1] << endl;
        cout << "pos_array 2 is" << pos_array[2] << endl;


        // plus one as position file is read from left to right
        cout << "the offset required is : " << pos_array[initialrotationsindex] << endl;
        #endif
        //this loop is rotating the rotor array the required number of times for initialisation
        for (int i =0; i < pos_array[initialrotationsindex]; i++) {
    			int temp=0;

        		for(int i =25; i > -1 ; i--){
        			temp=rotorarray[25];
        			rotorarray[25]=rotorarray[i];
        			rotorarray[i]=temp;
                }
        }
        #ifdef COMMENTS_ON
        cout << "printing after position initialisation " << endl;
                //printing array - debugging
                for(int i =0; i < (counter-1); i++){

                cout << "the rotorarray member  is " << rotorarray[i] <<endl;

            }

        cout << "rotor is now initialised" <<endl;
        #endif


    }//end ofrotor constructor

char Rotor::in_out(char input_char, bool way_back,  Enigma &enigma){


    	int input_int;
        #ifdef COMMENTS_ON
        cout << "which as an integer is " << (int)input_char - 65 << endl;
        cout << "way back? " << way_back <<endl;

        #endif
        int next_rotor_index_enigma = rotor_index_enigma +1; // is the next one over

if(way_back==false){


    // standard ie if way_back is false
    //if way_back ==true then different mapping is required
    char  transfer_char = input_char;
    char transfer_char_before;
    transfer_char_before = transfer_char;

<<<<<<< HEAD
    if(rotor_index_enigma != 0){ // does not need to for first rotor

        cout << "Rotor: accounting for rotation for this rotor would be equivilent to  " << \
        (char)((int)transfer_char - enigma.number_rot_comp[rotor_index_enigma])<< endl;
        transfer_char = (char)((int)transfer_char - (enigma.number_rot_comp[rotor_index_enigma]%25));
=======
	int input_int;
    #ifdef COMMENTS_ON
    cout << "Rotor: passed character to rotor is " << input_char << endl;
    cout << "which as an integer is " << (int)input_char - 65 << endl;
    #endif
>>>>>>> parent of 2addb38... 3 rotors working!!!

        if(transfer_char > 'Z' ){
            cout << "greater than Z so have to reset" << endl;
            transfer_char='A' + (enigma.number_rot_comp[rotor_index_enigma]%25)-('Z'-transfer_char_before) -1;
        }
        if(transfer_char < 'A' ){
            cout << "less than A  so have to reset!" << endl;
            transfer_char = 'Z' - (enigma.number_rot_comp[rotor_index_enigma]%25)+(transfer_char_before-'A') +1 ;
        }

        cout << "Rotor: accounting for rotation would be equivilent to  " <<transfer_char<<endl;
    }

    //then mapping internally
    input_int= (int)input_char - 65 ;
    #ifdef COMMENTS_ON
        printrotorarray(rotorarray);
        if(way_back == false){
                cout << "IN_OUT has found the matching number to be "\
                << rotorarray[input_int] << " which as an char is " <<\
                 (char)(rotorarray[input_int]+65) <<endl;
        }
    #endif



    transfer_char = (char)(rotorarray[input_int]+65); // this does the internal mapping.

    cout << "   Now changing to account for output rotor rotation relativity " \
    << (char)((int)transfer_char - enigma.number_rot_comp[rotor_index_enigma]) <<endl;
    transfer_char_before = transfer_char;

    transfer_char = (char)((int)transfer_char - enigma.number_rot_comp[rotor_index_enigma]);


    if(transfer_char > 'Z' ){
        cout << "greater than Z so have to reset" << endl;
        transfer_char='A' + ((enigma.number_rot_comp[rotor_index_enigma])%25)-('Z'-transfer_char_before) -1;

    }
    if(transfer_char < 'A' ){
        cout << "less than A  so have to reset!!!!!!!!!!!!!!!!!" << endl;
        transfer_char = 'Z' - ((enigma.number_rot_comp[rotor_index_enigma])%25)+(transfer_char_before-'A') +1 ;

    }


} //end of forwards section



    if(way_back == true){


        transfer_char_before = transfer_char;

        cout << "           Rotor Class moving backwards - accounting for rotation " << \
        (char)((int)transfer_char + (enigma.number_rot_comp[rotor_index_enigma])%25)<< endl;

        transfer_char = (char)((int)transfer_char + ((enigma.number_rot_comp[rotor_index_enigma])%25));


          if(transfer_char > 'Z' ){
              cout << "greater than Z so have to reset" << endl;
              transfer_char = 'A' + ((enigma.number_rot_comp[rotor_index_enigma])%25)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
              cout << "less than A so have to reset!!!!!!!!!!!!!!!!!!!!!!!" << endl;
             transfer_char = 'Z' - ((enigma.number_rot_comp[rotor_index_enigma])%25)+(transfer_char_before-'A') +1 ;
         }



        /* MAPPING SECTION */

        input_int= (int)input_char - 65 ;
        bool rotorarraymatch=false;
        int index_match_back=0;

        while(rotorarraymatch == false){
            if(rotorarray[index_match_back] == input_int){
                rotorarraymatch=true;
                break;
            }
            index_match_back++;
        }
<<<<<<< HEAD
    cout << "found mapped character to be  " << (char)(index_match_back + 65) <<endl;
=======

    return (char)(index_match_back + 65);
    }
    /////////////////end of backward section
>>>>>>> parent of 2addb38... 3 rotors working!!!

    #ifdef COMMENTS_ON
        printrotorarray(rotorarray);
        if(way_back == false){
                cout << "IN_OUT has found the matching number to be "\
                << rotorarray[input_int] << " which as an char is " <<\
                 (char)(rotorarray[input_int]+65) <<endl;
        }
    #endif

    transfer_char = (char)(index_match_back + 65); // this does the mapping

<<<<<<< HEAD
=======
    //this is what should be returned if is on the way out to the reflector -forwards
	return (char)(rotorarray[input_int]+65);
>>>>>>> parent of 2addb38... 3 rotors working!!!


    transfer_char_before = transfer_char;

    if(rotor_index_enigma !=0){ // does not need to be done before the plugboard.

    cout << "           Rotor Class moving backwards - accounting for rotation  " << \
    (char)((int)transfer_char + (enigma.number_rot_comp[rotor_index_enigma])%25)<< endl;

    transfer_char = (char)((int)transfer_char + ((enigma.number_rot_comp[rotor_index_enigma])%25));


      if(transfer_char > 'Z' ){
          cout << "greater than Z so have to reset" << endl;
          transfer_char = 'A' + ((enigma.number_rot_comp[rotor_index_enigma])%25)-('Z'-transfer_char_before) -1;
      }

      if(transfer_char < 'A' ){
          cout << "less than A so have to reset!" << endl;
         transfer_char = 'Z' - ((enigma.number_rot_comp[rotor_index_enigma])+(transfer_char_before-'A') +1 ;
     }
    }




 }    /////////////////end of backward section




return transfer_char;



}//end bracket for in_out


bool Rotor::rotate(Enigma enigma){


    //increment the number of rotations index for this rotor.
    enigma.number_rot_comp[rotor_index_enigma]++;



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

    if(rotorarray[0] == rotate_marker){
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

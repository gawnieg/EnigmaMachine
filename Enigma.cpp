#include"Enigma.h"
#include<iostream>
#include<fstream>
#include <cstring>
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

// #define COMMENTS_ON
#define STEP_COMMENTS_ON


Enigma::Enigma(Plugboard* _plugboard, Reflector* _reflector, Rotor* _rotorarray[], int _numberofrotors ){
//constructor for enigma

    plugboard = _plugboard;
    reflector = _reflector;
    cout << " _numberofrotors is " << _numberofrotors << endl; //debugging
    cout << "Rotor index" << rotor_index_enigma <<endl;

    rotor_index_enigma = _numberofrotors -1; //minus one so can be used directly as an index
    cout << " rotorindex is " << rotor_index_enigma << endl;

        for(int i=0; i <5; i++){ // up to 5 rotor members
            rotorarray[i] = _rotorarray[i]; //THIS LINE IS PROBLEMATIC, what am i trying to do here?
        }


    number_of_rotors_enigma= _numberofrotors;








}

char Enigma::encode(char input_char_to_be_encrypted){
    /* this function should take in the input character and pass it through the
    plugboard, rotor and then reflector back through the rotor and plugboard
    and then give back out the character it arrives at. It should then rotate the
    rotors as they should be rotated.
    */

    ///temporary section until get rotorindex functioning correctly in the constructor


<<<<<<< HEAD
    char transfer_char;

=======
    bool rotate_next_rotor_1 = rotorarray[0]->rotate();
    bool rotate_next_rotor_2 = false; // for moving rotor 3
    bool rotate_next_rotor_3 = false; // for moving rotor 4

    if(rotate_next_rotor_1 == true && count_temp > 1){
        cout << "rotate rotor 2 is required !!!" << endl;
        rotate_next_rotor_2 = rotorarray[1]->rotate();
    }
    if(rotate_next_rotor_2 == true && count_temp>2){
        cout << "rotate rotor 3 is required !!!" << endl;
        rotate_next_rotor_3 = rotorarray[2]->rotate();
    }
    if(rotate_next_rotor_3 == true && count_temp){
        cout << "rotate rotor 4 is required !!!" << endl;
        rotorarray[2]->rotate();
    }


    //character to store result between steps.
    char transfer_char;

    //could have if statements in here depending on the amount of rotors the machine is setup with

    if(count_temp ==1){ // for one rotor
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending to plugboard " << endl;
        #endif

        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor1" << endl;
        #endif

        transfer_char = rotorarray[0]->in_out(transfer_char,false);
        transfer_char = reflector->reflect(transfer_char);

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: passed back from rotor 1 was "<< transfer_char << endl;
        #endif

        transfer_char = rotorarray[0]->in_out(transfer_char,true); //sending to rotor 1

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        #endif

        transfer_char = plugboard->plugboard_convert(transfer_char);
    }

    if(count_temp ==2){ // for 2 rotors
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending to plugboard " << endl;
        #endif
        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);

        #ifdef STEP_COMMENTS_ON

        cout << "Encode: sending char to in_out rotor1" << endl;
        #endif
        transfer_char = rotorarray[0]->in_out(transfer_char,false);
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor2" << endl;
        #endif
        transfer_char = rotorarray[1]->in_out(transfer_char,false);

        transfer_char = reflector->reflect(transfer_char);

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: passed back from reflector was "<< transfer_char << endl;
        #endif
        transfer_char = rotorarray[1]->in_out(transfer_char,true); //sending to rotor 1

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor1" << endl;
        #endif
        transfer_char = rotorarray[0]->in_out(transfer_char,true);

        #ifdef STEP_COMMENTS_ON
        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        #endif

        transfer_char = plugboard->plugboard_convert(transfer_char);
    }




























    if(count_temp ==3){ // for 3 rotors
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending to plugboard " << endl;
        #endif

/* sending to plugboard */
        transfer_char = plugboard->plugboard_convert(input_char_to_be_encrypted);



/* mapping through to rotor1 */
        #ifdef STEP_COMMENTS_ON
        cout << "Encode: sending char to in_out rotor1 as"<< transfer_char  << endl;
        cout << "-----------------" << endl;
        #endif

        transfer_char = rotorarray[0]->in_out(transfer_char,false);

/* accounting for movement of rotor1 */
        char transfer_char_before;
        transfer_char_before = transfer_char;
        //additional sector to account for movement between two moving rotors.
        cout << "ENCODE: accounting for rotation for rotor1  would be equivilent to  " << \
        (char)((int)transfer_char - rotorarray[0]->num_rotations_comp)<< endl;
        transfer_char = (char)((int)transfer_char - rotorarray[0]->num_rotations_comp); //should this be num_rotations_comp%25?



        if(transfer_char > 'Z' ){
            cout << "greater than Z so have to reset" << endl;
            transfer_char='A' + ((rotorarray[0]->num_rotations_comp)%25)-('Z'-transfer_char_before) -1;

        }
        if(transfer_char < 'A' ){
            cout << "less than A  so have to reset!!!!!!!!!!!!!!!!!" << endl;
            transfer_char = 'Z' - ((rotorarray[0]->num_rotations_comp)%25)+(transfer_char_before-'A') +1 ;

        }
        cout << "ENCODE: accounting for rotation for rotor1  would be equivilent to  " <<transfer_char<<endl;


/* accouting more rotor2 movement before sending */


        cout << "   Now mapping to account for rotor2 turning ,after rotor1 " \
        << (char)((int)transfer_char - rotorarray[1]->num_rotations_comp) <<endl;
        transfer_char_before = transfer_char;

        transfer_char = (char)((int)transfer_char - rotorarray[1]->num_rotations_comp);


        if(transfer_char > 'Z' ){
            cout << "greater than Z so have to reset" << endl;
            transfer_char='A' + ((rotorarray[1]->num_rotations_comp)%25)-('Z'-transfer_char_before) -1;

        }
        if(transfer_char < 'A' ){
            cout << "less than A  so have to reset!!!!!!!!!!!!!!!!!" << endl;
            transfer_char = 'Z' - ((rotorarray[1]->num_rotations_comp)%25)+(transfer_char_before-'A') +1 ;

        }



/* sending to rotor2 */

        #ifdef STEP_COMMENTS_ON
        cout << "       Encode: sending char to in_out (MAPPING) rotor2 as" << transfer_char << endl;
        cout << "       -------------" << endl;
        #endif

        transfer_char = rotorarray[1]->in_out(transfer_char,false); // sending character to rotor2


/* accounting for rotor2's own movement relative to rotor3 */


        transfer_char_before = transfer_char;

        cout << "       Encode: accounting for rotation coming out of rotor2, by rotor2 would be equivilent to  " << \
        (char)((int)transfer_char - (rotorarray[1]->num_rotations_comp)%25)<< endl;

        transfer_char = (char)((int)transfer_char - ((rotorarray[1]->num_rotations_comp)%25));


          if(transfer_char > 'Z' ){
              cout << "greater than Z so have to reset" << endl;
              transfer_char = 'A' + ((rotorarray[1]->num_rotations_comp)%25)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
              cout << "less than A so have to reset!!!!!!!!!!!!!!!!!!!!!!!" << endl;
             transfer_char = 'Z' - ((rotorarray[1]->num_rotations_comp)%25)+(transfer_char_before-'A') +1 ;

          }




/* sending to rotor3 MAPPING */


        #ifdef STEP_COMMENTS_ON
        cout << "           Encode: sending char to in_out (MAPPING) rotor3 as "<< transfer_char << endl;
        cout << "           -------------" << endl;

        #endif
        transfer_char = rotorarray[2]->in_out(transfer_char,false);





/* accounting for rotor3's movement to reflector - this section should do nothing as of yet*/


        transfer_char_before = transfer_char;

        cout << "           ENCODE: accounting for rotation of rotor3  would be equivilent to  " << \
        (char)((int)transfer_char - (rotorarray[2]->num_rotations_comp)%25)<< endl;
        transfer_char = (char)((int)transfer_char - ((rotorarray[2]->num_rotations_comp)%25));


          if(transfer_char > 'Z' ){
              cout << "greater than Z so have to reset" << endl;
              transfer_char = 'A' + ((rotorarray[2]->num_rotations_comp)%25)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
              cout << "less than A so have to reset!!" << endl;
             transfer_char = 'Z' - ((rotorarray[2]->num_rotations_comp)%25)+(transfer_char_before-'A') +1 ;

          }




/* sending to reflector */

        cout << "               Passing " << transfer_char << " to reflector" <<endl;
        transfer_char = reflector->reflect(transfer_char);
        cout << "               Encode: passed back from reflector was "<< transfer_char << endl;
        cout << "               -------------" << endl;
        // unsure what is needed here, should do this on way back?
/////////////////////////////////////////////////////////////////////////////////


                        /* WAY BACK */


//////////////////////////////////////////////////////////////////////////////////

/* accounting for rotation of rotor3 relative to reflector */
        transfer_char_before = transfer_char;

        cout << "           Encode: accounting for rotation of rotor3 would be equivilent to  " << \
        (char)((int)transfer_char + (rotorarray[2]->num_rotations_comp)%25)<< endl;

        transfer_char = (char)((int)transfer_char + ((rotorarray[2]->num_rotations_comp)%25));


          if(transfer_char > 'Z' ){
              cout << "greater than Z so have to reset" << endl;
              transfer_char = 'A' + ((rotorarray[2]->num_rotations_comp)%25)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
              cout << "less than A so have to reset!!!!!!!!!!!!!!!!!!!!!!!" << endl;
             transfer_char = 'Z' - ((rotorarray[2]->num_rotations_comp)%25)+(transfer_char_before-'A') +1 ;
         }


/* sending to rotor 3 mapping */

        #ifdef STEP_COMMENTS_ON
        cout << "           Encode: sending char to in_out rotor3 on way back as "<<  transfer_char << endl;
        #endif

        transfer_char = rotorarray[2]->in_out(transfer_char,true);




        #ifdef STEP_COMMENTS_ON
        cout << "           Encode: passed back from rotor3  after mapping was "<< transfer_char << endl;
        #endif



/* accounting for rotor2's movement relative to rotor3 */



        /*
        NOW ADDING SECTION THAT ACCOUNTS FOR MOVEMENT OF
        SECOND rotor before going to the second rotor*/
        transfer_char_before = transfer_char;

        cout << "           Now mapping rotor 3 output to account for rotor2 turning" \
        << (char)((int)transfer_char + rotorarray[1]->num_rotations_comp);


        transfer_char = (char)((int)transfer_char + rotorarray[1]->num_rotations_comp);


        if(transfer_char > 'Z' ){
            cout << "greater than Z so have to reset" << endl;
            transfer_char='A' + ((rotorarray[1]->num_rotations_comp)%25)-('Z'-transfer_char_before) -1;

        }
        if(transfer_char < 'A' ){
            cout << "less than A  so have to reset!!!!!!!!!!!!!!!!!" << endl;
            transfer_char = 'Z' - ((rotorarray[1]->num_rotations_comp)%25)+(transfer_char_before-'A') +1 ;

        }



/* mapping with rotor2  */

        transfer_char = rotorarray[1]->in_out(transfer_char,true); //sending to rotor 1

        /* end of added sections*/




//new seciton// mapping rotor2's movement with rotor1

        transfer_char = (char)((int)transfer_char + rotorarray[1]->num_rotations_comp);
        transfer_char_before = transfer_char;


        if(transfer_char > 'Z' ){
            cout << "greater than Z so have to reset" << endl;
            transfer_char='A' + ((rotorarray[1]->num_rotations_comp)%25)-('Z'-transfer_char_before) -1;

        }
        if(transfer_char < 'A' ){
            cout << "less than A  so have to reset!!!!!!!!!!!!!!!!!" << endl;
            transfer_char = 'Z' - ((rotorarray[1]->num_rotations_comp)%25)+(transfer_char_before-'A') +1 ;

        }











/* accocunting for rotation of rotor1 relativeto rotor2 */


        #ifdef STEP_COMMENTS_ON
        cout << "Encode: going into rotor1 is " << transfer_char<< endl;
        #endif

        transfer_char_before = transfer_char;

        cout << "ENCODE: accounting for rotation  would be equivilent to  " << \
        (char)((int)transfer_char + (rotorarray[0]->num_rotations_comp)%25)<< endl;

        transfer_char = (char)((int)transfer_char + ((rotorarray[0]->num_rotations_comp)%25));


          if(transfer_char > 'Z' ){
              cout << "greater than Z so have to reset" << endl;
              transfer_char = 'A' + ((rotorarray[0]->num_rotations_comp)%25)-('Z'-transfer_char_before) -1;
          }

          if(transfer_char < 'A' ){
              cout << "less than A so have to reset!!!!!!!!!!!!!!!!!!!!!!!" << endl;
             transfer_char = 'Z' - ((rotorarray[0]->num_rotations_comp)%25)+(transfer_char_before-'A') +1 ;

          }




        transfer_char = rotorarray[0]->in_out(transfer_char,true);


        #ifdef STEP_COMMENTS_ON
        cout << "Encode: about to enter plugboard "<< transfer_char << endl;
        #endif
        transfer_char = plugboard->plugboard_convert(transfer_char);
        cout << "Encode: after plugboard "<< transfer_char << endl;
    }

>>>>>>> parent of 2addb38... 3 rotors working!!!



    return transfer_char;
} // end bracket for encode function

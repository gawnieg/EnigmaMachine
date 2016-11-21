#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Enigma.h"
#include <algorithm>
#include "errors.h"

// #define COMMENTS_ON

using namespace std;




int main(int argc, char** argv){


    int rotornumber = 1;
    int mainnumrotors = argc-4;
    int errorcode=0;

    if(argc < 3){
        cerr << "usage: enigma plugboard-file reflector-file (<rotor-file>* rotor-positions)?"<<endl;
        return (INSUFFICIENT_NUMBER_OF_PARAMETERS);
    }
    if(argc==4){
        cerr << "usage: enigma plugboard-file reflector-file (<rotor-file>* rotor-positions)?"<<endl;
        return (INSUFFICIENT_NUMBER_OF_PARAMETERS);
    }

    bool norotors=false;
    if(mainnumrotors <= 0){
        norotors = true;
    }



    Plugboard *plugb = new Plugboard();
    errorcode = plugb->Plugboard_load(argv[1]);

    if(errorcode!=0){
        return errorcode;
    }
    Reflector *reflec = new Reflector();
    errorcode = reflec->Reflector_load(argv[2]);

    if(errorcode!=0){
        return errorcode;
    }

    Rotor* rotor_r[mainnumrotors];
    for(int i =0; i < mainnumrotors; i++ ){

        rotor_r[i] = new Rotor();
        // rotor_r[i]->Rotor_load(argv[(argc-2-i)],argv[argc-1],rotornumber,enigma.number_rot_comp);
        // rotornumber++;

    }
Enigma enigma(plugb,reflec,rotor_r, mainnumrotors); // the 2 is the number of rotors

for(int i =0; i < mainnumrotors; i++ ){

    errorcode=rotor_r[i]->Rotor_load(argv[(argc-2-i)],argv[argc-1],rotornumber,enigma.number_rot_comp);
    if(errorcode!=0){
        return errorcode;
    }
    rotornumber++;

}



    char input_char;

    //cout << "please input an sentence to be encrypted, terminated by a full stop" << endl;

    #ifdef COMMENTS_ON
    char encrypted_sentence [500];
    int a=0;
    #endif


    while(cin  >>ws>>  input_char){
        #ifdef COMMENTS_ON
        if(input_char=='.'){
            break;
        }



        #endif
        if( ((int)input_char < 65) || ((int)input_char >122) || (((int)input_char >90) && ((int)input_char <97)) ){
            break;
        }


        #ifdef COMMENTS_ON
        cout << "number of rotors is " << enigma.number_of_rotors_enigma <<  endl;
        #endif
        char transfer_char = input_char;

        if(norotors==false){
            if(enigma.rotorarray[0]->rotate(0, enigma.number_rot_comp)==true){
                #ifdef COMMENTS_ON
                cout << "rotation of second required" << endl;
                #endif
                for(int i =0; i < mainnumrotors; i++ ){//rotation
                    if(enigma.rotorarray[i+1]->rotate(i+1, enigma.number_rot_comp)!=true){
                        break;
                    }

            }
        }
    }



        #ifdef COMMENTS_ON
        cout << "-----------------BEGINNING ENCRYPTION-------------------" <<endl;
        #endif
        //send to plugboard
        transfer_char = plugb->plugboard_convert(transfer_char);
        #ifdef COMMENTS_ON
        cout << "Output from plugboard is " << transfer_char << endl;
        #endif
        ///section for way out
        if(norotors==false){
            for(int i =0; i < enigma.number_of_rotors_enigma; i++){
                #ifdef COMMENTS_ON
                cout <<"sending character to in_out on way out" << endl;
                #endif
                transfer_char = (enigma.rotorarray[i])->in_out(transfer_char, 0, enigma.number_rot_comp , i); // as
            }
        }
        #ifdef COMMENTS_ON
        cout << "########################Now sending to reflector#####################" << endl;
        #endif
        //send to reflector
        transfer_char = reflec->reflect(transfer_char);
        #ifdef COMMENTS_ON
        cout << "Output from reflector is " << transfer_char << endl;
        cout << "enigma number of rotors is " << enigma.number_of_rotors_enigma << endl;
        #endif

        if(norotors==false){
            for(int i = enigma.number_of_rotors_enigma-1; i > -1; i--){
                #ifdef COMMENTS_ON
                cout <<"sending character to in_out on way back for rotor index "<<i  << endl;
                #endif
                transfer_char = (enigma.rotorarray[i])->in_out(transfer_char, 1, enigma.number_rot_comp, i);
            }
        }

        //NOW SEND TO PLUGBOARD
        transfer_char = plugb->plugboard_convert(transfer_char);
        cout << transfer_char;




        #ifdef COMMENTS_ON
        cout << "The encrypted character is " << transfer_char <<endl;
        encrypted_sentence[a]=transfer_char;
        a++;
        #endif



        #ifdef COMMENTS_ON
        cout << "---------------------------------------------------------------" <<endl;
        #endif
    }


    cout << endl; //print blank line at end for readability
    #ifdef COMMENTS_ON
    cout << "The number of rotations for rotor1 is " << enigma.number_rot_comp[0] << endl;
    cout << "The number of rotations for rotor2 is " << enigma.number_rot_comp[1]<< endl;
    cout << "The number of rotations for rotor3 is " << enigma.number_rot_comp[2] << endl;

    cout << endl; //print blank line at end for readability



    for(int i =0; i < a; i++){
        cout<< encrypted_sentence[i];

    }
    cout << endl; //print blank line at end for readability
    #endif



if(errorcode==0){
    delete plugb;
    delete reflec;
    // delete [] rotor_r;
}


return (NO_ERROR);

} //END OF MAIN


/*
To Do:
1. be able to pass in strings from the commmand LINE
2. construct enigma so that it can have unlimited rotors.
4. make rotor3 rotate in a three rotor setup
6. see what you can make private without too much hassle. .


*/

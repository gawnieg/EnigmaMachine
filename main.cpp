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

string delSpaces(string &str);






int main(int argc, char** argv){


    int rotornumber = 1;
    int mainnumrotors = argc-4;

    bool norotors=false;
    if(mainnumrotors == 0){
        norotors = true;
    }

    int errorcode=0;

    Plugboard *plugb = new Plugboard();//will need to error check to see if this is the right array member being passed
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
        rotor_r[i]->Rotor_load(argv[(argc-2-i)],argv[argc-1],rotornumber);
        rotornumber++;

    }


    Enigma enigma(plugb,reflec,rotor_r, mainnumrotors); // the 2 is the number of rotors


    char input_char;
    string input_sentance;
    // cout << "please input an sentence to be encrypted, terminated by a full stop" << endl;
    cin  >>ws>>  input_sentance;


    int a=0;
    char encrypted_sentence [500];



    while(input_char != '.'){

        input_char = input_sentance[a];
        if(input_char == '.'){
            break;
        }
        #ifdef COMMENTS_ON
        cout << "debugging - the int version of the character is " << (int)input_char <<endl;
        #endif
        if( ((int)input_char < 65) || ((int)input_char >122) || (((int)input_char >90) && ((int)input_char <97)) ){
            break;
        }


        #ifdef COMMENTS_ON
        cout << "number of rotors is " << enigma.number_of_rotors_enigma <<  endl;
        #endif
        char transfer_char = input_char;
        // //section to look after rotation of rotors. Turn into a loop!
        // bool rotate_next_rotor_1;
        // bool rotate_next_rotor_2 = false;
        // bool rotate_next_rotor_3 = false;


        //bool rotorrotate [mainnumrotors];

    // if(norotors==false){
    //     for(int i =0; i < mainnumrotors; i++ ){//rotation
    //         if(enigma.rotorarray[i]->rotate(i, enigma.number_rot_comp) == true){
    //             cout << "Next rotor needs a rotation" <<endl;
    //                 if(i+1 >= mainnumrotors){
    //                     break;
    //                 }
    //
    //             if(enigma.rotorarray[i+1]->rotate(i+1, enigma.number_rot_comp)!=true){
    //                 break;
    //             }
    //         }
    //
    //     }
    // }

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







        // rotate_next_rotor_1 = enigma.rotorarray[0]->rotate(0, enigma.number_rot_comp); //THESE 0,1,2 ETC NEED TO BE CHANGED TO TAKE ON INFINITE ROTORS!
        // cout << "*******************************************************"<< endl;
        // cout << "rotate_next_rotor_1 " << rotate_next_rotor_1 <<endl;
        // cout << "rotate_next_rotor_2 " << rotate_next_rotor_2 <<endl;
        //
        // if(rotate_next_rotor_1 == true && enigma.number_of_rotors_enigma > 1){
        //     cout << "rotate rotor 2 is required !!!" << endl;
        //     rotate_next_rotor_2 = enigma.rotorarray[1]->rotate(1,enigma.number_rot_comp);//enigma.number_rot_comp passed by reference - is an array
        // }
        // if(rotate_next_rotor_2 == true && enigma.number_of_rotors_enigma>2){
        //     cout << "rotate rotor 3 is required !!!" << endl;
        //     rotate_next_rotor_3 = enigma.rotorarray[2]->rotate(2,enigma.number_rot_comp);
        // }

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
        encrypted_sentence[a] = transfer_char;
        #ifdef COMMENTS_ON
        cout << "The encrypted character is " << transfer_char <<endl;
        #endif

        //cout << "encoded character is : " << enigma.encode(input_char) << endl;
        a++;
        #ifdef COMMENTS_ON
        cout << "---------------------------------------------------------------" <<endl;
        #endif
    }
    #ifdef COMMENTS_ON
    cout << "The encrypted_sentence is " <<endl;
    #endif
    for( int i=0; i<a; i++){
        cout << encrypted_sentence[i];
    }
    cout << endl; //print blank line at end for readability
    #ifdef COMMENTS_ON
    cout << "The number of rotations for rotor1 is " << enigma.number_rot_comp[0] << endl;
    cout << "The number of rotations for rotor2 is " << enigma.number_rot_comp[1]<< endl;
    cout << "The number of rotations for rotor3 is " << enigma.number_rot_comp[2] << endl;

    cout << endl; //print blank line at end for readability
    #endif


if(errorcode==0){
    delete plugb;
    delete reflec;
    // delete [] rotor_r;
}


return (NO_ERROR);

} //END OF MAIN

string delSpaces(string &str)
{
   // str.erase(remove(str.begin(), str.end(), ' '), str.end());
cout << str << endl;
   for(unsigned int i=0; i<str.length(); i++){
      if(str[i] == ' ') str.erase(i,1);
      cout << "i is " << i << endl;
   }

     cout << str << endl;
    return str;
}



/*
To Do:
1. be able to pass in strings from the commmand LINE
2. construct enigma so that it can have unlimited rotors.
4. make rotor3 rotate in a three rotor setup
6. see what you can make private without too much hassle. .


*/

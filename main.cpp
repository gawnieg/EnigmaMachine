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
    cout << "The error code is " <<errorcode <<endl;
    if(errorcode!=0){
        return errorcode;
    }

    Rotor* rotor_r[mainnumrotors];
    for(int i =0; i < mainnumrotors; i++ ){

        rotor_r[i] = new Rotor(argv[(argc-2-i)],argv[argc-1],rotornumber);
        rotornumber++;

    }

    cout << "Main:creating enigma object " << endl;
    Enigma enigma(plugb,reflec,rotor_r, mainnumrotors); // the 2 is the number of rotors


    char input_char;
    string input_sentance;
    cout << "please input an sentence to be encrypted, terminated by a full stop" << endl;
    cin  >>ws>>  input_sentance;


    int a=0;
    char encrypted_sentence [500];



    while(input_char != '.'){

        input_char = input_sentance[a];
        if(input_char == '.'){
            break;
        }
        cout << "debugging - the int version of the character is " << (int)input_char <<endl;
        if( ((int)input_char < 65) || ((int)input_char >122) || (((int)input_char >90) && ((int)input_char <97)) ){
            break;
        }



        cout << "number of rotors is " << enigma.number_of_rotors_enigma <<  endl;

        char transfer_char = input_char;
        // //section to look after rotation of rotors. Turn into a loop!
        bool rotate_next_rotor_1;
        bool rotate_next_rotor_2 = false;
        bool rotate_next_rotor_3 = false;


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

//     if(norotors==false){
//         if(enigma.rotorarray[0]->rotate(0, enigma.number_rot_comp)==true){
//             cout << "rotation of second required" << endl;
//             for(int i =0; i < mainnumrotors; i++ ){//rotation
//                 if(enigma.rotorarray[i+1]->rotate(i+1, enigma.number_rot_comp)!=true){
//                     break;
//                 }
//
//         }
//     }
// }







        rotate_next_rotor_1 = enigma.rotorarray[0]->rotate(0, enigma.number_rot_comp); //THESE 0,1,2 ETC NEED TO BE CHANGED TO TAKE ON INFINITE ROTORS!
        cout << "*******************************************************"<< endl;
        cout << "rotate_next_rotor_1 " << rotate_next_rotor_1 <<endl;
        cout << "rotate_next_rotor_2 " << rotate_next_rotor_2 <<endl;

        if(rotate_next_rotor_1 == true && enigma.number_of_rotors_enigma > 1){
            cout << "rotate rotor 2 is required !!!" << endl;
            rotate_next_rotor_2 = enigma.rotorarray[1]->rotate(1,enigma.number_rot_comp);//enigma.number_rot_comp passed by reference - is an array
        }
        if(rotate_next_rotor_2 == true && enigma.number_of_rotors_enigma>2){
            cout << "rotate rotor 3 is required !!!" << endl;
            rotate_next_rotor_3 = enigma.rotorarray[2]->rotate(2,enigma.number_rot_comp);
        }


        cout << "-----------------BEGINNING ENCRYPTION-------------------" <<endl;
        //send to plugboard
        transfer_char = plugb->plugboard_convert(transfer_char);
        cout << "Output from plugboard is " << transfer_char << endl;
        ///section for way out
        if(norotors==false){
            for(int i =0; i < enigma.number_of_rotors_enigma; i++){
                cout <<"sending character to in_out on way out" << endl;
                transfer_char = (enigma.rotorarray[i])->in_out(transfer_char, 0, enigma.number_rot_comp , i); // as
            }
        }

        cout << "########################Now sending to reflector#####################" << endl;
        //send to reflector
        transfer_char = reflec->reflect(transfer_char);
        cout << "Output from reflector is " << transfer_char << endl;
        cout << "enigma number of rotors is " << enigma.number_of_rotors_enigma << endl;
        //section for way back

        if(norotors==false){
            for(int i = enigma.number_of_rotors_enigma-1; i > -1; i--){
                cout <<"sending character to in_out on way back for rotor index "<<i  << endl;
                transfer_char = (enigma.rotorarray[i])->in_out(transfer_char, 1, enigma.number_rot_comp, i);
            }
        }

        //NOW SEND TO PLUGBOARD
        transfer_char = plugb->plugboard_convert(transfer_char);
        encrypted_sentence[a] = transfer_char;
        cout << "The encrypted character is " << transfer_char <<endl;

        //cout << "encoded character is : " << enigma.encode(input_char) << endl;
        a++;
        cout << "---------------------------------------------------------------" <<endl;

    }

    cout << "The encrypted_sentence is " <<endl;
    for( int i=0; i<a; i++){
        cout << encrypted_sentence[i];
    }
    cout << endl; //print blank line at end for readability

    cout << "The number of rotations for rotor1 is " << enigma.number_rot_comp[0] << endl;
    cout << "The number of rotations for rotor2 is " << enigma.number_rot_comp[1]<< endl;
    cout << "The number of rotations for rotor3 is " << enigma.number_rot_comp[2] << endl;

    cout << endl; //print blank line at end for readability



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
3.  update error code. isdigit is also not functioning correctly
4. make rotor3 rotate in a three rotor setup
5. Make deconstructors for each of the classes.
6. see what you can make private without too much hassle. .


*/

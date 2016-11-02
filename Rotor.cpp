#include<iostream>
#include<fstream>
#include <cstring>
#include "Rotor.h"


using namespace std;



    Rotor::Rotor(const char* filename, const char* pos_file){
        sets_position =true;
        ifstream in_pos;
        in_pos.open(pos_file);
        if(!in_pos){
            cout <<"input stream failed" <<endl;
        }
        int pos_counter=0;
        while(!in_pos.eof()){
            in_pos >>ws >>  pos_array[pos_counter];

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

                    cout << "the pos_array member  is " << pos_array[pos_counter] <<endl;
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
                for(int i =0; i<counter; i++ ){
                    for(int j=0; j < i; j++){
                        if(rotorarray[i]==rotorarray[j]){
                            cerr << "INVALID_ROTOR_MAPPING" /*<< " at " << j << "and "<< i */ << endl;
                        }
                    }

                }
                counter++;

            }

        if(counter != 27){
            cerr<<  "INVALID_ROTOR_MAPPING" << endl;
        }

        in.close();


        //printing array - debugging
        for(int i =0; i < counter; i++){

                    cout << "the rotorarray member  is " << rotorarray[i] <<endl;
        }

        //cout << "rotor is now initialised" <<endl;


    }//end ofrotor constructor with position array

    Rotor::Rotor(const char* filename){ //overloading Rotor constructor, this one has no position

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
                for(int i =0; i<counter; i++ ){
                    for(int j=0; j < i; j++){
                        if(rotorarray[i]==rotorarray[j]){
                            cerr << "INVALID_ROTOR_MAPPING" /*<< " at " << j << "and "<< i */ << endl;
                        }
                    }

                }
                counter++;

            }

        if(counter != 27){
            cerr<<  "INVALID_ROTOR_MAPPING" << endl;
        }

        in.close();


        //printing array - debugging
        for(int i =0; i < counter; i++){

                    cout << "the rotorarray member  is " << rotorarray[i] <<endl;
        }

        //cout << "rotor is now initialised" <<endl;


    }//end ofrotor constructor

#include<iostream>
#include<fstream>
#include <cstring>
#include "Plugboard.h"

using namespace std;



Plugboard::Plugboard(const char* filename){
    cout << "up in the plugboard constructor " << filename <<endl;
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

            in >>ws >>  pbarray[counter];
            //this is exiting out of the loop for the last character
            if(in.rdstate()>0){
                break;
            }
            //check if everything is a digit
            if(isdigit(pbarray[counter])==true){
                cerr<< "NON_NUMERIC_CHARACTER" <<endl;
            }
            //check for outside of range
            if(pbarray[counter]> 25 ||pbarray[counter]<0 ){
                cerr << "INVALID_INDEX" << pbarray[counter]  << endl;
            }
            //check for duplicates
            for(int i =0; i<counter; i++ ){
                for(int j=0; j < i; j++){
                    if(pbarray[i]==pbarray[j]){
                        cerr << "IMPOSSIBLE_PLUBOARD_CONFIGURATION" /*<< " at " << j << "and "<< i */ << endl;
                    }
                }

            }
            counter++;

        }

        //cout << "counter is " << counter <<endl;
        //check if there is an even number of array memebers
        if(counter%2 !=0){
            //cerr << "counter%2 is " << counter%2 <<endl;
            cerr<< "INCORRECT_PLUGBOARD_CONFIGURATION" <<endl;
        }





    in.close();


    //printing array - debugging
    for(int i =0; i < counter; i++){

                cout << "the pbarray member  is " << pbarray[i] <<endl;
    }



}//end of constructor

#include<iostream>
#include<fstream>
#include <cstring>
#include "Reflector.h"


Reflector::Reflector(const char* filename){
    cout << "up in the reflector constructor " << filename <<endl;
    ifstream in;
    in.open(filename);
        if(!in){
            cout <<"input stream failed" <<endl;
        }
        //put in array
        //int rfarray[26];


        int counter=0;

        while(!in.eof()){

            in >>ws >>  rfarray[counter];
            //this is exiting out of the loop for the last character
            if(in.rdstate()>0){
                break;
            }
            //check if everything is a digit
            if(isdigit(rfarray[counter])==true){
                cerr<< "NON_NUMERIC_CHARACTER" <<endl;
            }
            //check for outside of range
            if(rfarray[counter]> 25 ||rfarray[counter]<0 ){
                cerr << "INVALID_INDEX" << rfarray[counter]  << endl;
            }
            //check for duplicates
            for(int i =0; i<counter; i++ ){
                for(int j=0; j < i; j++){
                    if(rfarray[i]==rfarray[j]){
                        cerr << "INVALID_REFLECTOR_MAPPING" /*<< " at " << j << "and "<< i */ << endl;
                    }
                }

            }
            counter++;

        }//end of while loop for reading file

        //check if correct number of pairs
        if(counter != 26){
            cerr<<  "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS" << endl;
        }
        for(int i =0; i < counter; i++){

                    cout << "the rfarray member  is " << rfarray[i] <<endl;
        }
        in.close();


}//end of constructor

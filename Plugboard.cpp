#include<iostream>
#include<fstream>
#include <cstring>
#include "Plugboard.h"
#include "errors.h"

using namespace std;

//#define COMMENTS_ON


Plugboard::Plugboard(){


}//end of constructor


char Plugboard::plugboard_convert(char input_char){

int input_int;
    #ifdef COMMENTS_ON
        cout << "passed character to plugboard is " << input_char << endl;
        cout << "which as an integer is " << (int)input_char - 65 << endl;
    #endif

    input_int= (int)input_char - 65 ;

    //find what index number input is on the pbarray
    int index_match=0;
    bool index_m = false;

    #ifdef COMMENTS_ON
        cout <<"array size is " << counter << endl;
    #endif


    while(index_m==false && index_match < counter){ //check these conditions
        if(pbarray[index_match]== input_int ){
            index_m=true;
            break;
        }

        index_match++;

    }
    #ifdef COMMENTS_ON
        cout << "index match is " << index_match <<endl;
    #endif

    if(index_m ==false){
        //map to themself!
        return input_char;
    }



    if(index_match%2 != 0){// if the match is uneven you will want to look at the element before it
        //the converted character will be pbarray +1
        #ifdef COMMENTS_ON
        cout <<"odd therefore return the previous one" <<endl;
        cout << "pbarray return is " << pbarray[(index_match - 1)] << endl; // 2 as is zero indexed!
        cout << "which is the character " << (char)(pbarray[(index_match - 1)] +65) << endl;
        #endif

        return (char)(pbarray[index_match - 1] +65);

    }
    if(index_match%2 == 0){
        #ifdef COMMENTS_ON
        cout <<"even therefore return the next one, which is" <<endl;
        cout << "pbarray return is " << pbarray[(index_match + 1)] << endl;
        #endif

        return (char)(pbarray[index_match + 1] + 65);
    }

return index_match;

}


int Plugboard::Plugboard_load(const char* filename){


    ifstream in;
    in.open(filename);
        if(!in){
            return (ERROR_OPENING_CONFIGURATION_FILE);
        }
        //put in array
        //int pbarray[26];

        //printing for testing



        while(!in.eof()){

            in >>ws >>  pbarray[counter];
            //this is exiting out of the loop for the last character
            if(in.rdstate()>0){
                break;
            }
            //check if everything is a digit
            if(isdigit(pbarray[counter])==true){
                return (NON_NUMERIC_CHARACTER);

            }
            //check for outside of range
            if(pbarray[counter]> 25 ||pbarray[counter]<0 ){
                return (INVALID_INDEX);
            }
            //check for duplicates
            for(int i =0; i<counter; i++ ){
                for(int j=0; j < i; j++){
                    if(pbarray[i]==pbarray[j]){
                        return (IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
                    }
                }

            }
            counter++;

        }


        //check if there is an even number of array memebers
        if(counter%2 !=0){

            return(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);

        }





    in.close();

    #ifdef COMMENTS_ON
    //printing array - debugging
    for(int i =0; i < counter; i++){

                cout << "the pbarray member  is " << pbarray[i] <<"   which is " << i<< endl;
                if(i%2!=0 ){
                    cout<<"----------"<<endl;
                }

    }
    #endif

return 0 ;

}

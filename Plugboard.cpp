#include<iostream>
#include<fstream>
#include <cstring>
#include "Plugboard.h"

using namespace std;

//#define COMMENTS_ON


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

    #ifdef COMMENTS_ON
    //printing array - debugging
    for(int i =0; i < counter; i++){

                cout << "the pbarray member  is " << pbarray[i] <<"   which is " << i<< endl;
                if(i%2!=0 ){
                    cout<<"----------"<<endl;
                }

    }
    #endif

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

    return index_match;// is this right?


}

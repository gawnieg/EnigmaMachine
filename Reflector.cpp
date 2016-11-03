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
					if(i%2!=0 ){
						cout<<"----------"<<endl;
					}
        }
        in.close();


}//end of constructor

char Reflector::reflect(char input_char){
	
	int input_int;
    cout << "passed character to reflector is " << input_char << endl;
    cout << "which as an integer is " << (int)input_char - 65 << endl;
    input_int= (int)input_char - 65 ;
	
	    //find what index number input is on the pbarray
    int index_match=0;
    bool index_m = false;



    while(index_m==false){ //check these conditions
        if(rfarray[index_match]== input_int ){
            index_m=true;
            break;
        }

        index_match++;

    }
cout << "index match is " << index_match <<endl;
	
	if(index_match%2 != 0){// if the match is uneven you will want to look at the element before it
		//the converted character will be pbarray +1
		cout <<"odd therefore return the previous one" <<endl;
		cout << "pbarray return is " << rfarray[(index_match - 1)] << endl; // 2 as is zero indexed!
		cout << "which is the character " << (char)(rfarray[(index_match - 1)] +65) << endl;
		return (char)(rfarray[index_match - 1] +65);
	}
	
	if(index_match%2 == 0){

		cout <<"even therefore return the next one, which is" <<endl;
		cout << "pbarray return is " << rfarray[(index_match + 1)] << endl;
		return (char)(rfarray[index_match + 1] + 65);
	}

	return index_match;
	
}


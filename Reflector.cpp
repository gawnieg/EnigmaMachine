#include<iostream>
#include<fstream>
#include <cstring>
#include "Reflector.h"
#include "errors.h"



Reflector::Reflector(){


}//end of constructor

char Reflector::reflect(char input_char){

	int input_int;
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
	if(index_match%2 != 0){// if the match is uneven you will want to look at the element before it
		//the converted character will be pbarray +1
        return (char)(rfarray[index_match - 1] +65);
	}

	if(index_match%2 == 0){
		return (char)(rfarray[index_match + 1] + 65);
	}
	return index_match;

}

int Reflector::Reflector_load(const char* filename){


    ifstream in;
    in.open(filename);

		if(in.fail()){
            return (ERROR_OPENING_CONFIGURATION_FILE);
        }


        int counter=0;

        while(!in.eof()){

            in >>ws >>  rfarray[counter];
            //this is exiting out of the loop for the last character
            if(in.rdstate()>0){
                break;
            }

            //check for outside of range
            if(rfarray[counter]> 25 ||rfarray[counter]<0 ){
            return(INVALID_INDEX);
            }
            //check for duplicates
            for(int i =0; i<counter; i++ ){
                for(int j=0; j < i; j++){
                    if(rfarray[i]==rfarray[j]){
                        return(INVALID_REFLECTOR_MAPPING);
                    }
                }

            }
            counter++;

        }//end of while loop for reading file
		in.close();

		char test_char;
  	  	in.open(filename);
  	  	if (in.is_open()) {
  	  	while (in >> test_char) {
  	      	if (!isdigit(test_char)) {
  				cerr<< "Non-numeric character in reflector file reflector.rf" <<endl;
  				return (NON_NUMERIC_CHARACTER);
  	      }
  	    }
  	  }
  	  in.close();

	  if(counter % 2 !=0){
	  	cerr<<"Incorrect (odd) number of parameters in reflector file reflector.rf"<<endl;
	  	return(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
	  }

        //check if correct number of pairs
        if(counter != 26){
			cerr<<"Insufficient number of mappings in reflector file: reflector.rf"<<endl;
            return(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);

        }
        return (NO_ERROR);

}

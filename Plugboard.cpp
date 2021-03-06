#include<iostream>
#include<fstream>
#include <cstring>
#include "Plugboard.h"
#include "errors.h"

using namespace std;




Plugboard::Plugboard(){


}//end of constructor


char Plugboard::plugboard_convert(char input_char){

    int input_int;
    input_int= (int)input_char - 65 ;

    //find what index number input is on the pbarray
    int index_match=0;
    bool index_m = false;

    while(index_m==false && index_match < counter){ //check these conditions
        if(pbarray[index_match]== input_int ){
            index_m=true;
            break;
        }

        index_match++;

    }
    if(index_m ==false){
        //map to themself!
        return input_char;
    }
    if(index_match%2 != 0){// if the match is uneven you will want to look at the element before it
        //the converted character will be pbarray +1
        return (char)(pbarray[index_match - 1] +65);
    }
    if(index_match%2 == 0){
        return (char)(pbarray[index_match + 1] + 65);
    }

return index_match;

}


int Plugboard::Plugboard_load(const char* filename){

    ifstream in;

    in.open(filename);
    if (in.is_open()) {
        while (in >> pbarray[counter]) {
            if (pbarray[counter] < 0 || pbarray[counter] > 25) {

                    return (INVALID_INDEX);
                }
        counter++;
        }
      in.close();
    }

    else if (in.fail()) {
        cerr << "cannot open" << filename << endl;
        return (ERROR_OPENING_CONFIGURATION_FILE);
    }
    for (int i = 0; i < counter; i++) {
      for (int j = 0; j < counter; j++) {
        if ((pbarray[i] == pbarray[j]) && (i != j)) {

      return (IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
        }
      }
    }
    char test_char;
    in.open(filename);
    if (in.is_open()) {
      while (in >> test_char) {
        if (!isdigit(test_char)) {
            cerr << "Non-numeric character in plugboard file plugboard.pb" << endl;
            return NON_NUMERIC_CHARACTER;
        }
      }
    }
    in.close();

    if(counter >26){
        cerr << "Incorrect number of parameters in plugboard file plugboard.pb" <<endl;
        return (INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
    }
    if (counter % 2 == 1) {
        cerr << "Incorrect number of parameters in plugboard file plugboard.pb" <<endl;
        return (INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
    }

    return (NO_ERROR) ;

}

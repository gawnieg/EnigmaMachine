#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;



class Enigma{

// public:
//
// Rotor* enigma_rotor_array[];


};

class Rotor{
private:

int rotorarray[30];
int pos_array[5];
bool sets_position = false;

public:
 //constructor
    Rotor(const char* filename, const char* pos_file){
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

    Rotor(const char* filename){ //overloading Rotor constructor, this one has no position

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




}; //end of rotor class def

class Reflector{

private:
int rfarray[26];//putting here and not in public

public:

    Reflector(const char* filename){
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



};//end of reflector class


class Plugboard{
/*when initialised should pull info from argv, check it,
 then put it in an array */
private:

int pbarray[26];

public:
 //constructor
    Plugboard(const char* filename){
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





};

class InputSwitches{
};

class Outboard{
    };





int main(int argc, char** argv){


//cout << "What was passed was " << argv[1] << endl;
Plugboard *plugb = new Plugboard(argv[1]);//will need to error check to see if this is the right array member being passed
Reflector *reflect = new Reflector(argv[2]);
Rotor *rotor1 = new Rotor(argv[3],argv[4]);
cout << "adding rotor2" <<endl;
Rotor *rotor2 = new Rotor(argv[5]);
cout << "rotor2 should be added" <<endl;


/*
char character[2];
ifstream infile;
infile.open(argv[1]);
while(!infile.eof()){

infile >> character;
cout << character << endl;
}
*/



}

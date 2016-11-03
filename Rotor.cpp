#include<iostream>
#include<fstream>
#include <cstring>
#include "Rotor.h"


using namespace std;



    Rotor::Rotor(const char* filename, const char* pos_file){
        
		cout << "using overloaded rotor constructor" <<endl;
		
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
                        if(i%2!=0 ){
							cout<<"----------"<<endl;
						}
		
		
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
                        if(i%2!=0 ){
							cout<<"----------"<<endl;
						}
		}

        //cout << "rotor is now initialised" <<endl;


    }//end ofrotor constructor
	
char Rotor::in_out(char input_char){
		int input_int;
    cout << "passed character to rotor is " << input_char << endl;
    cout << "which as an integer is " << (int)input_char - 65 << endl;
    input_int= (int)input_char - 65 ;
	
	    //find what index number input is on the pbarray
    int index_match=0;
    bool index_m = false;



    while(index_m==false){ //check these conditions
        if(rotorarray[index_match]== input_int ){
            index_m=true;
            break;
        }

        index_match++;

    }
	cout << "index match is " << index_match <<endl;
	
	if(index_match%2 != 0){// if the match is uneven you will want to look at the element before it
		//the converted character will be pbarray +1
		cout <<"odd therefore return the previous one" <<endl;
		cout << "rotorarray return is " << rotorarray[(index_match - 1)] << endl; // 2 as is zero indexed!
		cout << "which is the character " << (char)(rotorarray[(index_match - 1)] +65) << endl;
		return (char)(rotorarray[index_match - 1] +65);
	}
	
	if(index_match%2 == 0){

		cout <<"even therefore return the next one, which is" <<endl;
		cout << "rotorarray return is " << rotorarray[(index_match + 1)] << endl;
		return (char)(rotorarray[index_match + 1] + 65);
	}

	return index_match;
}

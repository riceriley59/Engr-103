/*******************************************************************
** Program: Helper_funcs.cpp
** Author: Riley Rice
** Date: 06/04/2022
** Description: This has a bunch of helper functions for my resume program to make error handling and information
** getting easier.
*******************************************************************/

//all the required libraries that I need for my functions
#include <iostream>
#include <fstream>
#include <cstring>

//makes string usage and 
using namespace std; 

/*******************************************************************
** Function: has_spaces()
** Description: Looks at a cstring and returns true if it has spaces and false if otherwise
** Parameters: char str[]
** Pre-conditions: it needs an initialized cstring
** Post-conditions: return a boolean based if there is a space or not
*******************************************************************/
bool has_spaces(char str[]){
    bool has_spaces = false;

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            has_spaces = true;
        }
    }

    return has_spaces;
}

/*******************************************************************
** Function: txt()
** Description: Looks at a cstring and returns true if it has .txt at the end and false if otherwise
** Parameters: char str[]
** Pre-conditions: it needs an initialized cstring
** Post-conditions: return a boolean value based on whether there is a .txt extension at the end
*******************************************************************/
bool txt(char str[]){
    bool txt = false;

   for(int i = 0; i < strlen(str); i++){
       if(str[i] == '.'){
           if(str[i + 1] == 't' && str[i + 2] == 'x' && str[i + 3] == 't') {
               txt = true;
           }
       }
   }

    return txt;
}

/*******************************************************************
** Function: add_txt()
** Description: Adds .txt extension to the end of a cstring
** Parameters: char name[]
** Pre-conditions: it needs an initialized cstring
** Post-conditions: returns the cstring with .txt concatenated at the end of it
*******************************************************************/
void add_txt(char name[]){
    char txt[5] = ".txt";
    strncat(name, txt, 4);
}

/*******************************************************************
** Function: get_file_names()
** Description: gets a file name from the user with error handling
** Parameters: char name[]
** Pre-conditions: it needs an intialized cstring
** Post-conditions: returns the cstring with the value given by the user now initialized in it
*******************************************************************/
void get_file_names(char name[]){
    bool input = false;

    cout << "Input file name?: ";

    do{
        cin.getline(name, 64, '\n');
        cout << endl;

        if(!has_spaces(name) && !txt(name)){
            add_txt(name);
            input = true;
        }
        else{
            cout << "That input is invalid try again: ";
            input = false;
        }
        
    } while(!input);
}

/*******************************************************************
** Function: open_input_file()
** Description: Opens an input file stream binded to a file specified by the user 
** Parameters: ifstream& strm
** Pre-conditions: it needs a declared ifstream
** Post-conditions: it opens the ifstream and binds it to the file specified by the user
*******************************************************************/
void open_input_file(ifstream& strm){
    bool file_exists;

    do{
	    file_exists = true;
        char file_name[64];
        get_file_names(file_name);
        strm.open(file_name);
        if(!strm.is_open()){
            cout << "\nThe file couldn't be opened, try again.\n\n";
            file_exists = false;
        }
    }while(!file_exists);
}

/*******************************************************************
** Function: close_file()
** Description: closes an input file stream, and returns a boolean on whether it closes succesfully or not
** Parameters: ifstream& strm
** Pre-conditions: takes an ifstream parameter
** Post-conditions: closes the file and returns a boolean value based on the succes of the closing of the stream
*******************************************************************/
bool close_file(ifstream& strm){
    strm.close();
    if (strm.is_open()){
        cout << "Stream could not close!" << endl;
        return false;
    }

    return true;
}

/*******************************************************************
** Function: q_again()
** Description: Asks the user if they want to run the program again, error handling is also implemented
** Parameters: Null
** Pre-conditions: NULL
** Post-conditions: returns a boolean value based on whether the user wants to play again or not
*******************************************************************/
bool q_again(){
    bool input = true;
    char c[64];

    cout << "\nDo you want to build another resume again (y-yes, n-no)?: ";

    do{
        input = true;
        cin.getline(c, 64, '\n');

        if(c[0] == 'y' && strlen(c) == 1){
            cout << endl;
            return true;
        }
        else if(c[0] == 'n' && strlen(c) == 1){
            return false;
        }
        else{
            cout << "\nYou're input is invalid try again: ";
            input = false;
        }
    } while(!input);

    return false;
}

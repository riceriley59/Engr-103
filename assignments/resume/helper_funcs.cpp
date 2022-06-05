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
** Function: is_int()
** Description: Indicate if a given string is an integer
** Parameters: string num
** Pre-conditions: take a string parameter
** Post-conditions: return a value to tell if the string is an int
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
** Function: is_int()
** Description: Indicate if a given string is an integer
** Parameters: string num
** Pre-conditions: take a string parameter
** Post-conditions: return a value to tell if the string is an int
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
** Function: is_int()
** Description: Indicate if a given string is an integer
** Parameters: string num
** Pre-conditions: take a string parameter
** Post-conditions: return a value to tell if the string is an int
*******************************************************************/
void add_txt(char name[]){
    char txt[5] = ".txt";
    strncat(name, txt, 4);
}

/*******************************************************************
** Function: is_int()
** Description: Indicate if a given string is an integer
** Parameters: string num
** Pre-conditions: take a string parameter
** Post-conditions: return a value to tell if the string is an int
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
** Function: is_int()
** Description: Indicate if a given string is an integer
** Parameters: string num
** Pre-conditions: take a string parameter
** Post-conditions: return a value to tell if the string is an int
*******************************************************************/
void open_input_file(ifstream& strm){
    bool file_exists = true;

    do{
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
** Function: is_int()
** Description: Indicate if a given string is an integer
** Parameters: string num
** Pre-conditions: take a string parameter
** Post-conditions: return a value to tell if the string is an int
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
** Function: is_int()
** Description: Indicate if a given string is an integer
** Parameters: string num
** Pre-conditions: take a string parameter
** Post-conditions: return a value to tell if the string is an int
*******************************************************************/
bool q_again(){
    bool input = true;
    char c;

    cout << "\nDo you want to build another resume again (y-yes, n-no)?: ";

    do{
        cin >> c;

        if(c == 'y'){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl;
            return true;
        }
        else if(c == 'n'){
            return false;
        }
        else if(c != 'y' && c != 'n'){
            cout << "\nYou're input is invalid try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            input = false;
        }
    } while(!input);

    return false;
}
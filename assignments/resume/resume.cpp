/*******************************************************************
** Program: resume.cpp
** Author: Riley Rice
** Date: 06/04/2022
** Description: This program takes in a text file from the user and then builds a resume from that text file.
** Input: An input.txt file which will give all the information to the program (format in readme.txt).
** Output: A text file that is named (last name on resume).txt with the organized resume.
*******************************************************************/
 
//all the libraries I need for this program
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "helper_funcs.h"

//makes working with types and outputting easier
using namespace std;

//the struct to store Education Background
struct Edu {
    char univ[128]; //a c-string to store the university name
    char major[64]; //a c-string to store the major
    int graduate_year; //graduation year
    float GPA; //GPA
};

//the struct to store the basic information
struct Basics {
    char fname[64]; //a c-string to store the first name
    char lname[64]; //a c-string to store the last name
    char email[64]; //a c-string to store the email address
    Edu edu; //an Edu object to store the ed. background
};

//the struct to store one work experience
struct Exp {   
    char company[64]; //a c-string to store the company name
    char start_date[64]; //a c-string to store the start date
    char end_date[64]; //a c-string to store the end date
    char des[1024]; //the description of the work experience
};

/*******************************************************************
** Function: get_skills()
** Description: get each skill, as a string, from a file, and store them into
** the array of string, sk. The size of the array is sk_size.
** Parameters: string sk[], int sk_size, ifstream& strm
** Pre-conditions: needs a string array with a size of at least sk_size and a ifstream open that can
** be referenced.
** Post-conditions: string array with all the skills from the filestream in it
*******************************************************************/
void get_skills (string sk[], int sk_size, ifstream& strm){
    for(int i = 0; i < sk_size; i++){ //go through the amount of skills
        strm >> sk[i]; //put each skill in the sk array from the file stream
    }
}

/*******************************************************************
** Function: get_exp()
** Description: get each work experience, as an Exp struct object, from a file,
** and store them into the array of Exp, ex. The size of the array is ex_size.
** Parameters: Exp ex[], int ex_size, ifstream& strm
** Pre-conditions: needs an open file stream that can be referenced and an Exp array intialized with at least
** the size of ex_size
** Post-conditions: array of experience objects with members being initialized from info in the file stream
*******************************************************************/
void get_exp (Exp ex[], int ex_size, ifstream& strm){
    for(int i = 0; i < ex_size; i++){ //for the amount of work experiences
        //fill each ex objects members with information from the file stream as cstrings
        strm.getline(ex[i].company, 64, '~');
        strm.getline(ex[i].start_date, 64, '~');
        strm.getline(ex[i].end_date, 64, '~');
        strm.getline(ex[i].des, 1024, '~');
    }
}

/*******************************************************************
** Function: get_basics()
** Description: get all the basic info, as a Basics struct object from a file
** Parameters: Basics& basic, ifstream& strm
** Pre-conditions: needs a declared Basics object and an open file stream 
** Post-conditions: fills up all the member info from the Basics object with information from the file stream
*******************************************************************/
void get_basics(Basics& basic, ifstream& strm){
    //fill all the basic members and Edu members information from the file stream
    strm.getline(basic.fname, 64, ' ');
    strm.getline(basic.lname, 64, '~');
    strm.getline(basic.email, 64, '~');
    strm.getline(basic.edu.univ, 128, '~');
    strm.getline(basic.edu.major, 64, '~');
    strm >> basic.edu.graduate_year;
    strm >> basic.edu.GPA;
}

/*******************************************************************
** Function: build_resume()
** Description: the function to build the resume with all the user information in the structs that we got from 
** the file stream.
** Parameters: ofstream& f, Basics b, Exp ex[], int ex_size, string sk[], int sk_size
** Pre-conditions: Needs an open file stream that can be referenced along with an initialized Basics object
** and ex array and sk array.
** Post-conditions: returns a file with all the information from the user file formatted into a professional resume
*******************************************************************/
void build_resume (ofstream& f, Basics b, Exp ex[], int ex_size, string sk[], int sk_size){
    //put all the basic information at the top
    f << b.fname << " " << b.lname;
    f << b.email << "\n\n";
    f << "Resume: \n\n";
    f << "Education:" << b.edu.univ << "\n" << "Graduation Year: " << b.edu.graduate_year;
    f << b.edu.major << "\t" << "GPA: " << b.edu.GPA << "\n\n";

    //then go through all the skills and put them on a new line right next to each other
    f << "Skills:" << "\n";
    for(int i = 0; i < sk_size; i++){
        f << sk[i] << "\n";
    }

    //then go through each experience object and put all its member information next to each other for each one
    f << "\nExperience:";
    for(int i = 0; i < ex_size; i++){
        if(i > 0){
            f << "\n";
        }
        f << ex[i].company;
        f << ex[i].start_date;
        f << ex[i].end_date;
        f << ex[i].des;
    }
 
    f << endl;
}

/*******************************************************************
** Function: welcome()
** Description: Welcome the user to the program so that they know what the program is and where the instructions are
** Parameters: Null
** Pre-conditions: Null
** Post-conditions: outputs user welcome to console
*******************************************************************/
void welcome(){
    cout << "Welcome to the resume builder! Refer to the readme.txt to know the file layout required for the program \n";
    cout << "and then you can input that into the program when you run it. It will take that file and output a resume \n";
    cout << "in lastname.txt where lastname is the last name specified in your inputs resume file! \n\n";
}

/*******************************************************************
** Function: main()
** Description: This main function welcomes the user and then opens an input and output filestream and then 
** opens the input file stream and gets the size of the skills and experience array from the input file stream
** and then fills those structs with information from the input file stream. Then finally it opens the output
** file stream and puts all the information from the structs into the final resume file. It then closes the streams
** and outputs an error if it doesn't close properly. This is all repreated as long as the user decides to do so 
** through a do-while loop.
** Parameters: NULL
** Pre-conditions: NULL
** Post-conditions: outputs a text file formatted as a resume with all the users information
*******************************************************************/
int main(){
    bool again = false;

    //welcome the user
    welcome();

    //run once and loop again if the user wants to
    do{
        //declare input and output file streams
        ifstream strm;
        ofstream ostrm;
        
        //open the strm file stream binded to a file specified by the user
        open_input_file(strm);

        //declare amount of skills and amount of experience variables
        int amount_of_skills = 0;
        int amount_of_exp = 0;

        //intialize them with values from the file stream
        strm >> amount_of_exp;
        strm >> amount_of_skills;

        //open a string skills array and Exp object array with the size of the two previous variables
        string skills[amount_of_skills];
        Exp exp[amount_of_exp];
        Basics basic; // declare a Basics object also

        //call all the functions which fill up the arrays and Basics object with data from the input file stream
        get_basics(basic, strm);
        get_exp(exp, amount_of_exp, strm);
        get_skills(skills, amount_of_skills, strm);

        //declare a char array the size of the lname from the basics object and initialize it with the basic lname variable
        char output_file[strlen(basic.lname)];
        strcpy(output_file, basic.lname);

        //add the .txt extension to the lname cstring
        add_txt(output_file);

        //open the output file stream with the b.lname value
        ostrm.open(output_file, ofstream::trunc);

        //then build the resume with all the information in the arrays and objects and store them in the output file stream
        build_resume(ostrm, basic, exp, amount_of_exp, skills, amount_of_skills);

        //then close the file and return 1 if it doesn't close succesfully
        if(!close_file(strm)){
            return 1;
        }

        //then prompt the user if they want to run the program again before exiting
        again = q_again();
    } while(again); //run again if the user decides to run the program again

    //end main with no errors
    return 0;
}


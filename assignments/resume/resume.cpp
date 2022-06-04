#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "helper_funcs.h"

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

//get each skill, as a string, from the user, and store them into
//the array of string, sk. The size of the array is sk_size.
void get_skills (string sk[], int sk_size, ifstream& strm){
    for(int i = 0; i < sk_size; i++){
        strm >> sk[i];
    }
}

//get each work experience, as an Exp struct object, from the user,
//and store them into the array of Exp, ex. The size of the array is
//ex_size.
void get_exp (Exp ex[], int ex_size, ifstream& strm){
    for(int i = 0; i < ex_size; i++){
        strm.getline(ex[i].company, 64, '~');
        strm.getline(ex[i].start_date, 64, '~');
        strm.getline(ex[i].end_date, 64, '~');
        strm.getline(ex[i].des, 1024, '~');
    }
}

void get_basics(Basics& basic, ifstream& strm){
    strm.getline(basic.fname, 64, ' ');
    strm.getline(basic.lname, 64, '~');
    strm.getline(basic.email, 64, '~');
    strm.getline(basic.edu.univ, 128, '~');
    strm.getline(basic.edu.major, 64, '~');
    strm >> basic.edu.graduate_year;
    strm >> basic.edu.GPA;
}

//the function to build the resume with all user inputs. Create your
//own design of resume template here. Be creative! :)
void build_resume (ofstream& f, Basics b, Exp ex[], int ex_size, string sk[], int sk_size){
    f << b.fname << " " << b.lname;
    f << b.email << "\n\n";
    f << "Resume: \n\n";
    f << "Education:" << b.edu.univ << "\n" << "Graduation Year: " << b.edu.graduate_year;
    f << b.edu.major << "\t" << "GPA: " << b.edu.GPA << "\n\n";

    f << "Skills:" << "\n";
    for(int i = 0; i < sk_size; i++){
        f << sk[i] << "\n";
    }

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
}

void welcome(){
    cout << "Welcome to the resume builder! Refer to the readme.txt to know the file layout required for the program \n";
    cout << "and then you can input that into the program when you run it. It will take that file and output a resume \n";
    cout << "in another .txt file! \n\n";
}

int main(){
    bool again = false;

    welcome();

    do{
        string skills[10];
        Exp exp[5];
        Basics basic;
        ifstream strm;
        ofstream ostrm;

        open_input_file(strm);

        int amount_of_skills = 0;
        int amount_of_exp = 0;
        strm >> amount_of_exp;
        strm >> amount_of_skills;

        get_basics(basic, strm);
        get_exp(exp, amount_of_exp, strm);
        get_skills(skills, amount_of_skills, strm);

        string output_file = get_file_names(true);
        ostrm.open(output_file, ofstream::trunc);
        build_resume(ostrm, basic, exp, amount_of_exp, skills, amount_of_skills);

        if(!close_file(strm)){
            return 1;
        }

        again = q_again();
    } while(again);

    return 0;
}


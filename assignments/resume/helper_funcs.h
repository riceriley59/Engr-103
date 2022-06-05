/*******************************************************************
** Program: assignment4.h
** Author: Riley Rice
** Date: 06/04/2022
** Description: This is the header file so that I can use my helper functions in other programs.
*******************************************************************/

//header guard so things aren't include multiple times
#pragma once

//makes typing out things easier
using namespace std;

//all the function prototypes from the helper_funcs.cpp file
void add_txt(char[]);
void get_file_names(bool);
void open_input_file(ifstream&);
bool close_file(ifstream&);
bool has_spaces(char[]);
bool txt(char[]);
bool q_again();
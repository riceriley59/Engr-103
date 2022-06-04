/****************
 * Program: helper_funcs.h 
 * Author: Riley Rice
 * Date: 5-20-2022
 * Description: This is the interface file or header file for my helperfunction library which contains useful functions for error handling
 * Input: There are no inputs but a header guard and the different libraries should be included
 * Output: The output of this is the reference to the different functions through the function prototypes.
****************/

//header guard which makes it so that headers aren't included more than once which would cause errors
#pragma once

//includes all the necessary libraries for the functions
#include <string>
#include <iostream>
#include <cstdlib>
#include <math.h>

//makes it easier to declare parameters like strings
using namespace std;

/***************
 * These are all the function prototypes that are then defined in the implementation file, and they are what allow
 * this interface or header file to call these functions and reference them when this is included in other files.
***************/ 
bool check_range(int, int, int);

int  equality_test(int , int);

bool is_int(string);

bool is_float(string);

void string_to_int(string, int&);

void swap(int&, int&);

int word_count(string);

void pause();

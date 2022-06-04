/****************
 * Program: fraction.cpp 
 * Author: Riley Rice
 * Date: 5-20-2022
 * Description: This program takes a fraction and returns the fraction in it's lowest terms. It also deals with error handling and makes 
 * sure all the inputs are valid.
 * Input: You input two rational whole numbers as strings, and the denominator can't equal zero as that's undefined.
 * Output: It outputs the fraction that you inputted in lowest terms
****************/

//include iostream to make outputting to console easier and then include my helper functions library to make error handling easier
#include <iostream>
#include "../error_funcs/helper_funcs.h"

//make it so using standard functions easier such as cout and strings etc.
using namespace std;

/****************
 * Function: g_c_d() 
 * Description: Finds the greatest common divisor of two numbers by recursively calling itself and finding the remainder of the two numbers
 * until you can reduce it until 0 and then you use the number that made num1%num2 == 0 as that's the GCD that you were looking for.
 * Parameters: int num1, int num2
 * Pre-conditions: It needs two integer parameters
 * Post-conditions: Returns the greatest common divisor of the two integer parameters
****************/
int g_c_d(int num1, int num2){
	if(num2 == 0){ //if num2 equals 0 return num1 because that number made the modulo return 0 which means it's the gcd
		return num1;
	}
	//call it recursively and swap the num2 to num1 and make num2 equal to num1 % num2
	return g_c_d(num2, num1 % num2);
}

/****************
 * Function: to_lowest_terms()
 * Description: takes two integers and returns them in lowest terms, and then returns true if the denominator doesn't equal 0, and false if
 * otherwise.
 * Parameters: int& numerator, int& denominator
 * Pre-conditions: It needs two external integer variables to be declared since the parameters are passed by reference.
 * Post-conditions: returns both the integers in lowest terms and then returns true if the denominator doesn't equal 0, and false if otherwise.
****************/
bool to_lowest_terms(int& numerator, int& denominator){	
   	int gcd = g_c_d(numerator, denominator); //call the g_c_d function with the numerator and denominator and store it into gcd
	numerator /= gcd;
	denominator /= gcd; // divide both the numerator and denominator by the gcd
	
	//if the denominator is zero then return false and break out since this is undefined
	if(denominator == 0){
		return false;
	}	
	else if(denominator < 0){ //denominator is negative then multiply the numerator and denominator by -1 so that the numerator is always the negative one
		denominator *= -1;
		numerator *= -1;
	}

	//if the denominator isn't zero then return true
	return true;
}

/****************
 * Function: get_numerator() 
 * Description: This function gets the numerator from the user and does error handling to make sure the input is valid
 * Parameters: no parameters
 * Pre-conditions: It doesn't need anything except for some variables to be declared
 * Post-conditions: Returns a valid numerator
****************/
int get_numerator() {
	string snum;
	int num;
	bool numgood;

	do { //loops until numerator input is valid
		cout << endl << "Enter your numerator: ";
		getline(cin, snum); //get input from cin and stores into snum variable
		
		//if snum is an integer and the word count is 1 then convert the snum to int and store in num then return num
		if (is_int(snum) && word_count(snum) == 1) {
			string_to_int(snum, num);
			return num;
		}
		else { // else tell them their input is invalid and loop again
			cout << "\nYou must enter only whole numbers! Try again. \n";
			numgood = false;
		}

	} while (!numgood);
}

/****************
 * Function: get_denominator() 
 * Description: This function gets the denominator from the user and does error handling to make sure the input is valid
 * Parameters: int& num
 * Pre-conditions: It needs to have a numerator variable that's initialized, and in this case that should be through the get_numerator() function
 * Post-conditions: Returns a valid denominator
****************/
int get_denominator(int& num) {
	string sden;
	int den = 0;
	bool dengood;

	do { //loops until denominator input is valid
		cout << endl << "Enter your denominator: ";
		getline(cin, sden); //get input from cin and stores into sden variable
		
		//if sden is an integer and the word_count is 1 then convert the sden to int
		if (is_int(sden) && word_count(sden) == 1) { 
			string_to_int(sden, den);
			if (!(to_lowest_terms(num, den))) { //if to_lowest_terms returns false or denominator equals 0 then tell them their input is invalid and loop again
				cout << "\nYou can't enter 0 for a denominator, that's undefined. Try again.\n";
				dengood = false;
			}
			else { //if the denominator isn't 0 then return the denominator
				return den;
			}
		}
		else { //if input isn't a int then loop again
			cout << "\nYou must enter only whole numbers! Try again.\n";
			dengood = false;
		}
	} while (!dengood);
}

/****************
 * Function: another() 
 * Description: Gets a valid input from the user on whether they want to do another conversion and returns a bool on whether they want to or not.
 * Parameters: no parameters are needed
 * Pre-conditions: It doesn't need anything
 * Post-conditions: Returns true if the user wants to do another conversion and false if otherwise
****************/
bool another() {
	string sanother;
	int another;
	bool anothergood;

	do { //loop until another input is valid
		cout << "\n\nDo you want to do another conversion (0-no, 1-yes)? ";
		getline(cin, sanother); //get input from cin and store in sanother string
		
		//if sanother is an integer then convert the string to an int
		if (is_int(sanother)) {
			string_to_int(sanother, another);
			if (another == 1){ //if another equal 1 then return true
				return true;
			}
			else if (another == 0) { //if another equals 0 then return false
				return false;
			}
			else { //if input isn't a valid integer then loop again
				anothergood = false;
			}
		}
		
		//if input isn't integer then output that their input is invalid and loop again
		cout << "\nYou're input is invalid, try again.";
		

	} while (!anothergood);
}

/****************
 * Function: main() 
 * Description: It gets a numerator and then a denominator and then puts them in lowest terms and asks if you want to do another conversion
 * Parameters: no parameters needed
 * Pre-conditions: needs helper functions library included
 * Post-conditions: Returns your fraction in lowest terms
****************/
int main(){	
	
   	//welcome the user
   	cout << "\nWelcome! Enter a fraction and it will be returned in it's lowest term: use only whole numbers for your numerator and denominator, \n";
	cout << "and don't put your numerator as 0 as that's undefined.\n";

	//do-while loop that loops if the user wants to do another conversion, based off of another() return value
   	do{
	   	//get valid numerator
		int num = get_numerator();

		//get valid denominator
		int den = get_denominator(num);
		
		//change numerator and denominator to lowest terms
		to_lowest_terms(num, den);

		//output fraction in lowest terms, and right here only the numerator
		cout << "\n\nThe lowest terms of your fraction: " << num; 
		
		//if the denominator is equal to 1 then you don't need to output it otherwise you should.
		if(den != 1){
			cout << "/" << den;
		}
		
	}while(another());
	
	cout << endl;

	return 0;
}

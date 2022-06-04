/****************
 * Program: helper_funcs.cpp 
 * Author: Riley Rice
 * Date: 5-20-2022
 * Description: This is the implementation file for my helper function library, and it contains a lot of useful functions for error handling.
 * Input: The only thing that is needed is the include for the header file, and the required parameters for each function call so that the 
 * functions can be used.
 * Output: The output of this is the different functions and their different uses and values.
****************/

//refers to my header file with all the function prototypes
#include "helper_funcs.h"

//makes outputting to the console a lot easier
using namespace std;


/****************
 * Function: check_range() 
 * Description: Checks if a given value is within the given range
 * Parameters: int lower_bound, int upper_bound, int test_value
 * Pre-conditions: It needs a lower bound, upper bound, and a test_value and they all need to be intitialized
 * Post-conditions: Returns true if the test value is within the bounds and false if otherwise
****************/
bool check_range(int lower_bound, int upper_bound, int test_value) {
	if (test_value <= upper_bound && test_value >= lower_bound) { //if test_value is between upper_bound and lower_bound then return true
		return true;
	}

	return false; //otherwise return false 
}

/****************
 * Function: equality_test() 
 * Description: Checks if two given integers are equal to each other
 * Parameters: int num1, int num2
 * Pre-conditions: It takes in two integers
 * Post-conditions: It returns -1 or 1 if they aren't equal depending on which number is larger and 0 if they are equal.
****************/
int equality_test(int num1, int num2) {
	if (num1 < num2) { //if num1 is less than num2 then return -1
		return -1;
	}
	else if (num1 > num2) { //if num1 is greater than num2 then return 1
		return 1;
	}
	else { //if num1 equals num2 then return 0
		return 0;
	}
}

/****************
 * Function: is_int() 
 * Description: Checks if a given string is an integer or not
 * Parameters: string num
 * Pre-conditions: takes a string parameter
 * Post-conditions: returns false if the string isn't an integer and true otherwise.
****************/
bool is_int(string num) {
	for (int i = 0; i < num.length(); i++) { //iterate through each character of the string
		//if the first character is - and the length of the string is greater than 1 and this is the first iteration then continue because it is a valid negative sign
	   	if(num[0] == '-' && num.length() > 1 && i == 0){
			continue;
		}
		//if the character of the string isn't an ASCII integer value or the character is . then return false because it isn't numbers or it's a float with a dot
		else if(!((int(num[i]) - 48) <= 9 && (int(num[i] - 48)) >= 0) || num[i] == '.'){
			return false;
		}
		//if the whole string was iterated and it didn't return false then return true because it's an integer
		else if(i == num.length() - 1) {
			return true;
		}
	}
}

/****************
 * Function: is_float() 
 * Description: Checks if a given string is a float or not
 * Parameters: string num
 * Pre-conditions: takes a string parameter
 * Post-conditions: returns false if the string isn't a float and true otherwise.
****************/
bool is_float(string num) {
   	bool dot = false; //bool to keep track of whether or not their is a dot

	//iterate through each character of the given string
	for (int i = 0; i < num.length(); i++){
	   	//if the first character is - and the length of the string is greater than 1 or the character is .
		if((num[0] == '-' && num.length() > 1 && i == 0) || num[i] == '.'){
			//if the character is . and the character before the dot isn't - then continue and make dot true because it's a valid dot
		   	if (num[i] == '.' && num[i - 1] != '-')
				dot = true;
			//otherwise continue because it's a negative sign character
		}
		//if the character isn't an ASCII integer value then return false
		else if(!((int(num[i]) - 48) <= 9 && (int(num[i] - 48)) >= 0)){
			return false;
		}
		//if the whole string was iterated and none of the string were invalid and there was a valid dot then return true becuase it's a float
		if(i == num.length() - 1 && dot){
			return true;		
		}
	}
}

/****************
 * Function: string_to_int() 
 * Description: It takes a string and then turns it into an integer
 * Parameters: string num, int& value
 * Pre-conditions: It needs an external variable that can be reference, and takes a string parameter than can only be between 0-9
 * Post-conditions: It returns the string in an integer value
****************/
void string_to_int(string num, int& value) {
	value = 0; // set the value equal to 0 to get rid of any garbage value stored in their

	//iterate through each character of the given string
   	for(int i = 0; i < num.length(); i++){
	   	//if the character is a valid ASCII integer value
		if((int(num[i]) - 48) >= 0 && (int(num[i]) - 48) <= 9){
	   		//as the string is iterated multiply the integer value by a power of 10 that is decremented as the for loop increments then add that to value variable	   
	   		value += pow(10, (num.length() - 1) - i) * (int(num[i]) - 48);
			//if the first character is a - value and the whole string has already been converted then multiply the value by -1 to make the integer a negative
			if(num[0] == '-' && i == num.length() - 1){
				value *= -1;
			}
		}
	}
}

/****************
 * Function: swap() 
 * Description: swaps two integer's values
 * Parameters: int& num1, int& num2
 * Pre-conditions: it takes two int references which means there needs two external variables that can be referenced
 * Post-conditions: the two integers will now have switched their values 
****************/
void swap(int& num1, int& num2) {

	int temp = num1; //make a temporary integer variable to store num1 in

	num1 = num2; // store num2 in num1 
	num2 = temp; // store temp or num1 in num2

	return;
}

/****************
 * Function: word_count() 
 * Description: It returns the word count of a string
 * Parameters: string sentence
 * Pre-conditions: takes a string parameter
 * Post-conditions: returns the word count of the string in an integer
****************/
int  word_count(string sentence) {
	int count = 0; //make a count variable
	
	//iterate through each character of the string
	for (int i = 0; i < sentence.length(); i++) {
	   	//if the string has been completely iterated through and the last character isn't a space or it is a dot then add one to the count because that means
		//the word ended at the end and it wasn't a blank space.
		if(i == sentence.length() - 1 && (sentence[i] == '.' || sentence[i] != ' ')){
			count++;
		}
		//if the character is a space and the next character isn't a space then add to the count because that means their is a next word and the last word has ended
		else if(sentence[i] == ' ' && sentence[i + 1] != ' ') {
			count++;
		}
	}

	return count; //return the count
}

/****************
 * Function: pause()
 * Description: it pauses the flow of the function its called in until a key is pressed
 * Parameters: none
 * Pre-conditions: needs to be called in a function
 * Post-conditions: it causes the flow of function to be stopped until keypress
****************/
void pause() {
	cout << "\n\npress anything to continue...";
	cin.clear();
	cin.ignore(256, '\n');
}

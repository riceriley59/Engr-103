/****************
 * Program: error_funcs.cpp 
 * Author: Riley Rice
 * Date: 5-20-2022
 * Description: This is the driver file for my helper functions library which uses my functions to test them and make sure they work.
 * Input: The only thing that is needed is the include for the header file, and the required parameters for each function call so that the 
 * functions can be used.
 * Output: The output of this is the different functions and their different uses and values, and whether the function works properly when presented
 * with different test cases.
****************/

//includes my helper functions library and iostream to make outputting easier
#include "helper_funcs.h"
#include <iostream>

//makes outputting to console and using strings easier
using namespace std;


/****************
 * Function: main() 
 * Description: the main function that calls all my functions with different cases to make sure the functions work properly. This 
 * is considered the driver file for my library.
 * Parameters: none
 * Pre-conditions: It needs the helper function library included
 * Post-conditions: Returns true if the test is good and false if otherwise
****************/
 int main() {
	cout << "\n1. Testing check_range() ....\n";
	cout << "Testing check_range(5,8,6)...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << check_range(5, 8, 6);
	(check_range(5, 8, 6) == true) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting check_range(5,8,8)...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << check_range(5, 8, 8);
	(check_range(5, 8, 8) == true) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting check_range(5,8,5)...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << check_range(5, 8, 5);
	(check_range(5, 8, 5) == true) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting check_range(5,8,9)...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << check_range(5, 8, 9);
	(check_range(5, 8, 9) == false) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n2. Testing equality_test() ....\n";
	cout << "Testing equality_test(7,7)...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << equality_test(7, 7);
	(equality_test(7, 7) == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting equality_test(10,8)...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << equality_test(10, 8);
	(equality_test(10, 8) == 1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting equality_test(9,10)...\n";
	cout << "Expected: -1";
	cout << "\tActual: " << equality_test(9, 10);
	(equality_test(9, 10) == -1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n3. Testing is_int() ....\n";
	cout << "Testing is_int(\"34\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_int("34");
	(is_int("34") == 1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"-34\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_int("-34");
	(is_int("-34") == 1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"50.6\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_int("50.6");
	(is_int("50.6") == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"abc\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_int("abc");
	(is_int("abc") == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"-\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_int("-");
	(is_int("-") == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"50abc\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_int("50abc");
	(is_int("50abc") == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n4. Testing is_float() ....\n";
	cout << "Testing is_float(\"34.2\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_float("34.2");
	(is_float("34.2") == 1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"-34.2\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_float("-34.2");
	(is_float("-34.2") == 1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\".6\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_float(".6");
	(is_float(".6") == 1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"4.\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_float("4.");
	(is_float("4.") == 1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"abc\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_float("abc");
	(is_float("abc") == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"-\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_float("-");
	(is_float("-") == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"-.\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_float("-.");
	(is_float("-.") == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"50.2abc\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_float("50.2abc");
	(is_float("50.2abc") == 0) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n5. Testing string_to_int() ....\n";
	int value;
	cout << "Testing string_to_int...(\"1234\", value)\n";
	cout << "Expected: 1234";
	string_to_int("1234", value);
	cout << "\tActual: " << value;
	(value == 1234) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting string_to_int...(\"18\", value)\n";
	cout << "Expected: 18";
	string_to_int("18", value);
	cout << "\tActual: " << value;
	(value == 18) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting string_to_int...(\"-18\", value)\n";
	cout << "Expected: -18";
	string_to_int("-18", value);
	cout << "\tActual: " << value;
	(value == -18) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n6. Testing swap() ....\n";
	cout << "Testing swap(7, 9)...\n";
	cout << "Expected num1 = 9, num2 = 7";
	int num1 = 7, num2 = 9;
	swap(num1, num2);
	cout << "\tActual: num1 = " << num1 << ", num2 = " << num2;
	(num1 == 9 && num2 == 7) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting swap(100, -60)... \n";
	cout << "Expected num3 = -60, num4 = 100";
	num1 = 100; num2 = -60;
	swap(num1, num2);
	cout << "\tActual: num1 = " << num1 << ", num2 = " << num2;
	(num1 == -60 && num2 == 100) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n7. Testing word_count() ....\n";
	cout << "Testing word_count(\"Hello, my name is Roger.\")...\n";
	cout << "Expected: 5";
	string sentence = "Hello, my name is Roger.";
	cout << "\tActual: " << word_count(sentence);
	(word_count(sentence) == 5) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting word_count(\"hello\")...\n";
	cout << "Expected: 1";
	sentence = "hello";
	cout << "\tActual: " << word_count(sentence);
	(word_count(sentence) == 1) ? cout << "\tPASSED\n" : cout << "\tFAILED\n";


	return 0;
}

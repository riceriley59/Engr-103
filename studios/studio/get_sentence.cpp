#include <iostream>
#include <string>

using namespace std;

/**************
 * Pre-conditions: There needs to be a variable that can store this output 
 * Post-Conditions: There will be a variable that has the return value copied into it
**************/
string get_sentence();

/**************
 * Pre-conditions: There needs to be a variable that can be called into the function
 * Post-conditions: There isn't anything that gets returned
**************/
void get_sentence2(string&);

void get_sentence2(string& s){
	cout << "input a string: ";
	getline(cin, s);
	cout << s << endl;
}

string get_sentence(){

   	string sentence;

	cout << "input a string: ";
	getline(cin, sentence);

	return sentence;
}

int main(){
 	string sentence;

//	sentence = get_sentence();

//	cout << sentence << endl;

	get_sentence2(sentence);

	return 0;
}

/********************
 *With the & the parameter is given an alias with the same memory address and a different name which means that it won't be copied and you don't need to return anything 
 *without the & parameter a copy of the parameter is made with a different memory address that then needs to be returned into another variable outside the function
********************/

#include <iostream>

using namespace std;

int main(){
	
	char input;

	cout << endl << endl;
	cout << "Enter a letter and I will tell you if it's uppercase or lowercase: ";
	cin >> input;
	cout << endl << endl;

	if(input >= 65 && input <= 90){
		cout << "The letter you entered is uppercase";
		cout << endl << endl;
	}
	else if(input >= 97 && input <= 122){
		cout << "The letter you entered is a lowercase";
		cout << endl << endl;
	}
	else{
		cout << "You entered in an invalid input, please enter a uppercase or /n";
		cout << "lowercase letter.";
		cout << endl << endl;	
	}	
}

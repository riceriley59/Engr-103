#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

int atoi(char character){
	return int(character);
}

char itoa(int integer){
	return char(integer);
}

int string_to_int(string Mystring){
   	
	int integer;

	for(int i = 0; i < Mystring.length(); i++){
		integer += pow(10, (Mystring.length() - 1) - i) * (int(Mystring[i]) - 48);
	}

	return integer;
}

int  main(){

	int option;
	bool optiongood;

   	cout << endl << endl;
	cout << "Do you want to convert a character to an integer(1) or the other way around(2)? Or convert a string into an integer(3)? ";
		
	do{
		cin >> option;
		cout << endl << endl;
	
		if(option == 1){
		   	char character;	

			cout << "Enter in a character: ";
			cin >> character;
			cout << endl;
		   	optiongood = true;
			cout << "Heres the integer representation: " << atoi(character);
			cout << endl << endl;
		}
		else if(option == 2){
			int integer;
		   
			cout << "Enter in an integer: ";
			cin >> integer;
			cout << endl;
		   	optiongood = true;
			cout << "heres the character representaton: " << itoa(integer);
			cout << endl << endl;
		}
		else if(option == 3){
			string str;

			cout << "Enter in a string: ";
			cin >> str;
			cout << endl;
			optiongood = true;
			cout << "Heres the string converted into an integer: " << string_to_int(str);
			cout << endl << endl;
		}
		else{
			optiongood = false;
			cout << "your input is invalid try again: ";
			cout << endl;
		}
	}while(!optiongood);

	return 0;
}

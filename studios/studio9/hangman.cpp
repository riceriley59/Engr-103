#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void get_string(string& str_to_store){
	cout << "\nWelcome to hangman! \n\n" << "Enter a string to set for the other people to guess: ";
	getline(cin, str_to_store);
}

void set_replace_string(string copy_str, string& dash_str){
	for(int i = 0; i < copy_str.length(); i++){
		if(copy_str[i] != ' '){
			dash_str[i] = '-';
		}
	}
}

int get_search_replace(char c , string copy_str, string& dash_str){
	int count = 0;

	for(int i = 0; i < copy_str.length(); i++){
		if(copy_str[i] == c){
			dash_str[i] = c;
			count++; 
		}
	}

	return count;
}

int main(){
	string hidden_string;
	get_string(hidden_string);

	string dash_str = hidden_string;
	set_replace_string(hidden_string, dash_str);

	bool run = true;
	
	while(run){
	   	char c;
		cout << "\nEnter in a character to guess: ";
		cin >> c;

		int amount = get_search_replace(c, hidden_string, dash_str);
		 
		cout << "\nHeres the string:" << dash_str;	

		if(amount == 0){
			cout << "\nYour character isn't in the string try again!\n";
		}
		else if(hidden_string == dash_str){
			cout << "\nYou got the string good job!\n\n";
			run = false;
		}
		else{
			cout << "\n" << amount << " character(s) was in the string!\n";
		}
	}

   	return 0;
}

#define MAXINPUT 256

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void get_string(char str_to_store[]){
	cout << "\nWelcome to hangman! \n\n" << "Enter a string to set for the other people to guess: ";
	cin.getline(str_to_store, MAXINPUT - 1);
}

void set_replace_string(char copy_str[], char dash_str[]){
	for(int i = 0; i < strlen(copy_str); i++){
		if(copy_str[i] != ' '){
			dash_str[i] = '-';
		}
	}
}

int get_search_replace(char c , char copy_str[], char dash_str[]){
	int count = 0;

	for(int i = 0; i < strlen(copy_str); i++){
		if(copy_str[i] == c){
			dash_str[i] = c;
			count++; 
		}
	}

	return count;
}

int main(){
	char hidden_string[MAXINPUT];
	get_string(hidden_string);

	char dash_str[MAXINPUT];
	strcpy(dash_str, hidden_string);
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
		else if(strcmp(hidden_string, dash_str) == 0){
			cout << "\nYou got the string good job!\n\n";
			run = false;
		}
		else{
			cout << "\n" << amount << " character(s) was in the string!\n";
		}
	}

   	return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void randletters(int upperamt, int loweramt){
	for(int j = 0; j <= upperamt - 1; j++){
		char upletter = (rand() % (90 - 65 + 1)) + 65;
		cout << upletter;
	}
	for(int k = 0; k <= loweramt - 1; k++){
		char lowerletter = (rand() % (122 - 97 + 1)) + 97;
		cout << lowerletter;	
	}
}

void randnumbers(int amount){
	for(int i = 0; i <= amount - 1; i++){
		int number = rand() % 10;
		cout << number;
	}
}

int main(){

   	bool playagain;
	srand(time(NULL));

	
	cout << endl << endl;
	cout << "Welcome to Password Creator!";
   	cout << endl << endl << endl;

	do {
   		bool letters;

   		bool uppercase;
   		int upperamount;

		bool lowercase;
		int loweramount;

		bool numbers;
		int numberamount;

   		cout << "In your password..." << endl;

   		cout << "Do you want letters (0-No, 1-Yes)?: ";
   		cin >> letters;
   		cout << endl;
	
		if(letters == true){
   			cout << "Do you want uppercase letters (0-No, 1-Yes)?: ";
   			cin >> uppercase;
   			cout << endl;
   			cout << "How many characters of the password should be uppercase?: ";
   			cin >> upperamount;
   			cout << endl;

   			cout << "Do you want lowercase letters (0-No, 1-Yes)?: ";
   			cin >> lowercase;
   			cout << endl;
   			cout << "How many character of the password should be lowercase?: ";
   			cin >> loweramount;
   			cout << endl;
		}

   		cout << "Do you want numbers (0-No, 1-Yes)?: ";
   		cin >> numbers;
   		cout << endl;
   		cout << "How many characters of the password should be numbers?: ";
   		cin >> numberamount;
   		cout << endl << endl << endl;

		cout << "Generating the password with a length of " << loweramount + upperamount + numberamount << ": ";
		cout << endl;
		cout << "Your random password is: ";

		if(letters && numbers){
			randletters(upperamount, loweramount);
			randnumbers(numberamount);
		}
		else if(!letters && numbers){
			randnumbers(numberamount);		
		}
		else if(letters && !numbers){
			randletters(upperamount, loweramount);
		}
		else{
	   		cout << endl;
			cout << "A password cant be made with those selections do you want to try again (0-No, 1-Yes)?: ";
			cin >> playagain;
			cout << endl << endl;
		}

		cout << endl << endl << endl;
		cout << "Would you like to make another password (0-No, 1-Yes)?: ";
		cin >> playagain;
		cout << endl << endl;

	}while(playagain);	

   	return 0;
}

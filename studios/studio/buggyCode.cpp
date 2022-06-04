/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream>

using namespace std;

int main(){

	int x = 3, y = 3;

	cout << "y is set to: " << y << endl;

	//while again is true, prompt user for y value,
	//and output if it's >, < or = to x
	bool again = true;
	while(again){

	   	cout << "Please enter a number for y: ";
		cin >> y;

		if(x > y){
			cout << "X is greater than Y\n";
			cout << "would you like to input another number?" << endl;
			cin >> again;
		}
		else if(x == y){
			cout << "X is equal to Y\n";
			cout << "would you like to input another number?" << endl;
			cin >> again;
		}
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?" << endl;
			cin >> again;
		}
		//what if x == y?
	}

	//for loop, print out the value of x for 10 times
	for(x = 0; x < 10; x++){
		cout << x << endl;
	}
	
	//compute and output factorial for num
	int num = 0;
	int sum = 1;
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;
	for(int x = num; x > 0; x--){
		sum *= x;
	}
	cout << sum << endl;

	//conditionals
	char myAnswer;
	cout << "Are you enjoying engr103? (y or n) " << endl;
	cin >> myAnswer;
	if(myAnswer == 'y'){
		cout << "YAY" << endl;
	}
	else if(myAnswer == 'n'){
		cout << "YOU WILL SOON!" << endl;
	}

	return 0;
}

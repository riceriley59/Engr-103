#include <iostream>

using namespace std;

int main(){
	int x;

	cout << endl << endl;
	cout << "Please enter an integer: ";
	cin >> x;
	cout << endl << endl;
	
	switch(x % 2 == 0){
		case 1:
		   cout << "the integer is even";
		   cout << endl << endl;
		   break;
		default:
		   cout << "the integer is odd";
		   cout << endl << endl;
		   break;
	}
}

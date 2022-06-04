#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int bytes;

	cout << endl << endl;
	cout << "Enter an amount of bytes below 8 (0-8): ";
	cin >> bytes;
	cout << endl << endl;

	bytes *= 8;

	unsigned long unsignmax = (unsigned long) pow(2, bytes) - 1;
	unsigned long unsignmin = 0;

	signed long signmax = (signed long) pow(2, bytes - 1) - 1;
	signed long signmin = (signed long) pow(2, bytes - 1) * -1;

	cout << "The maximum unsigned int with bytes " << bytes << " is " << unsignmax << endl;
	cout << "The minimum unsigned int with bytes " << bytes << " is " << unsignmin << endl << endl;

	cout << "The maximum signed int with bytes " << bytes << " is " << signmax << endl;
	cout << "The minimum signed int with bytes " << bytes << " is " << signmin << endl << endl;
	
	cout << "Add one to signed max, and you get: " << (signmax + 1) << endl;
	cout << "Add one to unsigned max, and you get: " << (unsignmax + 1) << endl << endl;

	cout << "Subtract one from signed min, and you get: " << (signmin - 1) << endl;
	cout << "Subtract one from unsigned min, and you get: " << (unsignmin - 1) << endl << endl;

	return 0;

}

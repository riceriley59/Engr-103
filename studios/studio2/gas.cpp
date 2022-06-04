#include <iostream>

using namespace std;

int main(){
	float mpg, thousandmiles;

	cout << endl << "Enter your car's miles per gallon(MPG): ";
	cin >> mpg;
	cout << endl << endl;
	
	thousandmiles = 100000.0f / mpg;

	cout << "Gas used over a 100,000-miles: " << thousandmiles << endl;
	cout << "If the gas is $2.50/gallon, you will spend: $" << (thousandmiles * 2.50f) << endl;
	cout << "If the gas is $4.50/gallon, you will spend: $" << (thousandmiles * 4.50f) << endl << endl; 	

	return 0;

}

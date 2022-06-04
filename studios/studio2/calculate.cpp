#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int one = 20 / (2 + 4 + 5.5) + 2 / 4;
	int two = 20 / 2 + 4 + 5.5 + 2 / 4;
	int three = 25 % 5 * (6 + 12) % 36;
	int four = 2 * 45.0 + 10 / 12;
	int five = 2 * 45.0 + 10.0 / 12;
	int six = pow(2,8) / (6 + 12) * 2;

	cout << one << endl;
	cout << two << endl; 
	cout << three << endl; 
	cout << four << endl; 
	cout << five << endl; 
	cout << six << endl;

	return 0; 
}

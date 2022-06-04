#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	
	int x;
	srand(time(NULL));

	x = rand();
	cout << "x = " << x << endl;
	

	x  = x % 5;
	cout << "x between 0 and 5: " << x << endl;

	if(x == 0){ 
		cout << "I am 0" << endl;
	}
	else if(x % 2 == 0) {
		cout << "I am an even number" << endl;
	}
	else{
		cout << "I am an odd Number" << endl;
	}

	return 0;
}

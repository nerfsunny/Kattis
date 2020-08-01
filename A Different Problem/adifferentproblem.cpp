#include <iostream>

using namespace std;
using ull = unsigned long long int;

int main(int argc, char** argv) {
	//Initializing variables
	ull num1, num2;

	//While-loop that itereates through each input and stores the two numbers in their respective variables
	while(cin >> num1 >> num2) 
		//Checks which number is bigger, then executes the correct expression so that the result is always positive. This is due to abs() in cmath not having an overloaded function for unsigned numbers
		cout << ((num1 > num2) ? (num1 - num2) : (num2 - num1)) << endl;

	return 0;
}
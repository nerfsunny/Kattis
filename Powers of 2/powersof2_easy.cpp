#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

//Checks if value is a substring in number. If it is, it returns true. Otherwise, it returns false
bool containsNumberString(const string& number, const string& value) {
	if(number.find(value) != string::npos)
		return true;
	else
		return false;
}

int main(int argc, char** argv) {
	/* Initializing variables,
	 *
	 * inputSize, stores the largest number that is going to be generated for the test case
	 * counter, stores how many numbers contain powerOf2 as a substring
	 * exponent, stores the power that 2 is going to be raised by
	 * powerOf2, stores the result of 2^exponent
	 */
	ull inputSize, counter = 0, exponent, powerOf2;

	//Storing values into their respective variables
	cin >> inputSize >> exponent;

	//Calculating 2^exponent
	powerOf2 = pow(2, exponent);

	/* Generates numbers from [powerOf2, inputSize]. 
	 * This range was selected since any number strictly below powerOf2 would be guaranteed to not contain powerOf2 
	 * as a subsstring
	 */
	for(ull number = powerOf2; number <= inputSize; number++) 
		//Converts the two numbers to string and checks if number contains powerOf2. If it does, then it increments counter
		if(containsNumberString(to_string(number), to_string(powerOf2)))
			counter++;
	
	//Outputting the total amount of numbers that contain powerOf2 as a substring
	cout << counter << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

ull convertHexToBase10(const ull number) {
	//Initiallizng variables
	ull result = 0, num = number, power = 0;

	//While-loop that continues until there are no more digits
	while(num > 0) {
		//Takes the right-mpst digit
		int digit = num % 10;

		//Takes the extracted digit and multiplies by 16^power, then sums it to the result
		result = result + digit * pow(16, power);

		//Divides the number by 10 and truncates the resulting decimal number
		num = num/10;

		//Increments power by 1
		power++;
	}

	//Returns final calculation
	return result;
}

//Converts a given an ambigious octal/decimal number, it converts it to its decimal counterpart
ull convertOctalToBase10(const int number) {
	//Initiallizng variables
	ull result = 0, num = number, power = 0;

	//While-loop that continues until there are no more digits
	while(num > 0) {
		//Takes the right-mpst digit
		int digit = num % 10;

		//Takes the extracted digit and multiplies by 8^power, then sums it to the result
		result = result + digit * pow(8, power);

		//Divides the number by 10 and truncates the resulting decimal number
		num = num/10;

		//Increments power by 1
		power++;
	}

	//Returns final calculation
	return result;
}

//Checks if the given number contains digit
bool checkForDigit(const ull number, const int digit) {
	//Saving number in this temp variable
	ull num = number;

	//While-loop that continues until there are no more digits
	while(num > 0) {
		//Takes the right-mpst digit
		int numDigit = num % 10;

		//If-statement that checks if the extracted digit is the same as the specified digit; if it is, then it returns true and exits the function
		if(numDigit == digit)
			return true;

		//Divides the number by 10 and truncates the resulting decimal number
		num = num/10;
	}

	//If the number does not contain the specified digit, it returns false
	return false;
}

int main(int argc, char** argv) {
	//Initiallizing variable
	ull number, numberOfInputs, lineNumber;;

	//Storing number of inputs for test case
	cin >> numberOfInputs;

	//For-loop that iterates through the inputs
	for(int i = 1; i <= numberOfInputs; i++) {
		//Stores the line number and number
		cin >> lineNumber >> number;

		//If-statemenet: if the decimal number contains either a 8 or 9, it outputs a 0 for the octal number and only converts the number as if it was hex to a decimal number
		//Otherwise, it converts the number as if it was an octal to a decimal number and hex to a decimal number
		if(checkForDigit(number, 9) || checkForDigit(number, 8)) 
			cout << lineNumber << " 0 " << number << " " << convertHexToBase10(number) << endl;
		else 
			cout << lineNumber << " " << convertOctalToBase10(number) << " " << number << " " << convertHexToBase10(number) << endl;
	}

	return 0;
}
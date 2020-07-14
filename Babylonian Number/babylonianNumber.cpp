#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

//Converts the babylonianNumber (stored as digits in a vector) into their decimal counterpart
ull convertToDecimalNumber(vector<int>& babylonianDigits) {
	//Initializing variables. decimalNumber is used to store the total sum when converting from one base to another, power is used to store the exponential power used in the conversion
	ull decimalNumber = 0, power = 0;

	//For-loop that iteraties through the vector, from indexes 0 to size - 1
	for(int index = 0; index < babylonianDigits.size(); index++) {
		//Converts the babylonianDigit to its decimal counterpart and adds it to decimalNumber
		decimalNumber += (babylonianDigits.at(index) * pow(60, power));

		//Increments power by 1
		power++;
	}

	//Returns converted number
	return decimalNumber;
}

int main(int argc, char** argv) {
	/*Initializing variables: 
		numberOfInputs stores the number of babylonian numbers in the test case
		babylonianNumber is used to store the specific babylonianNumber used for the conversion
		babylonianDigits is used to store the digits of babylonianNumber
	*/
	int numberOfInputs;
	string babylonianNumber;
	vector<int> babylonianDigits;

	//Storing number of inputs
	cin >> numberOfInputs;

	//For-loop that iterates through all of the inputs
	for(int i = 0; i < numberOfInputs; i++) {
		//Storing babylonianNumber
		cin >> babylonianNumber;

		//While-loop that continues until there are no more digits in the string
		while(babylonianNumber.length() > 0) {
			//Stores the last index where a comma appears in the string
			int commaIndex = babylonianNumber.rfind(",");

			/*If-else statement block that executes on one of the three following conditions:
				1. If the string does not contain anymore commas, it converts the string to an int and pushes it to the vector
				2. If the last comma is found at an index that is also the end of the string, then it pushes a zero to the vector and substrings it from 0 to the second to last index
				3. In all other cases, it extracts the number from index + 1 from the string, converts to an int and pushes to the vector; it also substrings it from 0 to index - 1
			*/
			if(commaIndex == string::npos) {
				babylonianDigits.push_back(stoi(babylonianNumber));
				babylonianNumber = "";
			}else if(commaIndex == babylonianNumber.length() - 1) {
				babylonianDigits.push_back(0);
				babylonianNumber = babylonianNumber.substr(0, commaIndex);
			}else {
				babylonianDigits.push_back(stoi(babylonianNumber.substr(commaIndex + 1)));
				babylonianNumber = babylonianNumber.substr(0, commaIndex);
			}
		}

		//Passes vector to function to calculate its decimal counterpart and outputs it to terminal
		cout << convertToDecimalNumber(babylonianDigits) << endl;

		//Clears the vector for the next input
		babylonianDigits.clear();
	}

	return 0;
}
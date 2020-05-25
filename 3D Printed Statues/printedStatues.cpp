#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	//Initializing variables.
	//numberOfStatues is the input from the command line; numberOfDays stores how many days it takes to printers and/or statues to complete the job; numberOfPrinters counts how many total printers can be used
	int numberOfStatues, numberOfDays = 0, numberOfPrinters = 1;

	//Stores input 
	cin >> numberOfStatues;

	/*
	While-loop that determines how many total printers are needed for the job. It increases the number of printers by a power of 2 (so it follows 2^n) and continues finds the closest value of 2^n that is less than the number of statues.
	Everytime it increments the number of statues, it also incremenets the number of days by 1. 
	*/
	while(numberOfPrinters * 2 < numberOfStatues) {
		numberOfPrinters = numberOfPrinters * 2;
		numberOfDays++;
	}

	//While-loop that that counts how many days it then takes to print the requested number of statues given the number of printers on hand. Once the number of statues reaches 0 or lower, it exits the loop
	while(numberOfStatues > 0) {
		numberOfStatues = numberOfStatues - numberOfPrinters;
		numberOfDays++;
	}

	//Outputs result
	cout << numberOfDays << endl;

	return 0;
}
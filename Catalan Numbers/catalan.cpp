#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
using ld = long double;

ld calculateFactorial(int number) {
	if(number <= 1)
		return 1;

	return number * calculateFactorial(number - 1);
}

ld calculateCatalanNumber(int number) {
	int denominator = number + 1;
	ld n = calculateFactorial(2 * number);
	ld k = calculateFactorial(number);

	return n/(k * k * denominator);
}

int main(int argc, char** argv) {
	int numberOfInputs;
	int input;

	cin >> numberOfInputs;

	for(int i = 0; i < numberOfInputs; i++) {
		cin >> input;

		cout << calculateBinomial(input * 2, input) << endl;
	}

	return 0;
}
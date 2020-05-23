#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long convertFromBase8ToBase10(const long input) {
	long number = input;
	long result = 0;
	long value = 0;
	int power = 0;

	while(number > 0) {
		value = (number % 10) * pow(8, power);
		result = result + value;
		number = number/10;
		power++;
	}

	return result;
}

string convertFromBase10ToBase16(const long input, vector<string>& vec) {
	string result = "";
	long number = input;
	long value = 0;

	while(number > 0) {
		value = number % 16;
		number = number/16;
		result = vec.at(value) + result;

		//cout << "Remainder: " << value << " Value: " << number << " Hexadecimal: " << result << endl; 
	}

	return result;
}

int main(int argc, char** argv) {
	long number = 0;
	vector<string> hex = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

	cin >> number;

	//cout << convertFromBase8ToBase10(number) << endl;
	cout << convertFromBase10ToBase16(convertFromBase8ToBase10(number), hex) << endl;

	return 0;
}

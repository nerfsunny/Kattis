#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
//using llong = unsigned long long int;

using llong = long double;

/*llong convertFromBase8ToBase10(const llong input) {
	llong number = input;
	llong result = 0;
	llong value = 0;
	int power = 0;

	while(number > 0) {
		value = (number % 10) * pow(8, power);
		result = result + value;
		number = number/10;
		power++;

		cout << "Value: " << value << " Result: " << result << " Number: " << number << " Power: " << power - 1 << endl;
	}

	return result;
}*/

llong convertFromBase8ToBase10(const string input) {
	string number = input;
	llong value;
	llong result = 0;
	llong power = 0;

	while(number.length() > 0) {
		value = stoi(number.substr(number.length() - 1, 1)) * pow(8, power);
		result = result + value;
		number = number.substr(0, number.length() - 1);
		power++;

		cout << "Value: " << value << " Result: " << result << " Number: " << number << " Power: " << power - 1 << endl;
	}

	return result;
}

/*string convertFromBase10ToBase16(const llong input, vector<string>& vec) {
	string result = "";
	llong number = input;
	llong value = 0;

	while(number > 0) {
		value = number % 16;
		number = number/16;
		result = vec.at(value) + result;

		cout << "Remainder: " << value << " Value: " << number << " Hexadecimal: " << vec.at(value) << " Result: " << result << endl; 
	}

	return result;
}*/

string convertFromBase10ToBase16(const llong input, vector<string>& vec) {
	string result = "";
	llong number = input;
	llong value = 0;

	while(number > 0) {
		value = fmod(number, 16);
		number = floor(number/16);
		result = vec.at(value) + result;

		cout << "Remainder: " << value << " Value: " << number << " Hexadecimal: " << vec.at(value) << " Result: " << result << endl; 
	}

	return result;
}

int main(int argc, char** argv) {
	//llong number = 0;
	string number;
	vector<string> hex = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

	cin >> number;

	cout << number << endl;
	//cout << convertFromBase8ToBase10(number) << endl;
	llong temp = convertFromBase8ToBase10(number);
	cout << temp << endl;
	string hexNumber = convertFromBase10ToBase16(temp, hex);

	while(true) {
		if(hexNumber[0] != '0')
			break;

		if(hexNumber[0] == '0')
			hexNumber = hexNumber.substr(1);
	}

	//Outputs converted number to console
	cout << hexNumber << endl;

	return 0;
}
